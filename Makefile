include ./Makefile.defs

TARGET_LIB  = Tython
TARGET      = lib$(TARGET_LIB).so
TEST_TARGET = libTythonTest
TEST_XML     = unittest.xml


DOXYGEN  = doxygen
DOXYCONF = Tython.doxygen
DOXYOUT  = docs
COVERAGE = $(TEST_XML)
CPPCHECK_XML = cppcheck.xml

.SUFFIXES: .cc .o 

.PHONY: test test-all clean distclean tags force all

%.o : %.cc
$(TEST_SRCS_DIR)/%.o : $(TEST_SRCS_DIR)/%.cc
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@ 
%.o : %.cc
	$(CXX) -fPIC $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) -shared -o $@ $(OBJS) $(LIBS)

$(TEST_TARGET): $(TARGET) $(TEST_OBJS)
	$(CXX) $(TEST_LIBS) -L. -l$(TARGET_LIB) $(TEST_OBJS) -o $@

test: $(TEST_TARGET) force
	GTEST_FILTER="-UserContextTest.*:UserFactoryTest.TestSetAndDeleteContext" \
	./$(TEST_TARGET) --gtest_output="xml:$(TEST_XML)" 

test-all: $(TEST_TARGET) force
	./$(TEST_TARGET) --gtest_output="xml:$(TEST_XML)"

cppcheck:
	cppcheck --enable=all --enable=style src -I include --xml 2> $(CPPCHECK_XML)

clean:
	$(RM) $(RM_GC)
	$(RM) $(TARGET) $(TEST_TARGET)
	$(RM) $(OBJS) $(TEST_OBJS)
	$(RM) $(OBJS_GCOV)
	$(RM) $(CPPCHECK_XML)
	cd $(SRCS_DIR)      && $(RM) $(RM_GC)
	cd $(TEST_SRCS_DIR) && $(RM) $(RM_GC)

distclean: clean
	$(RM) $(TAGSFILE)
	$(RM) -r $(DOXYOUT) $(COVERAGE)

tags:
	@$(TAGS) $(TAGSOPTION)

doxygen:
	$(DOXYGEN) $(DOXYCONF)

force:

all: $(TARGET)
