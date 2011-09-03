include ./Makefile.defs

TARGET      = libTython.a
TEST_TARGET = libTythonTest

OBJS_GCOV = $(OBJS:.o=.gcno) $(TEST_OBJS:.o=.gcno) lcov.info

DOXYGEN  = doxygen
DOXYCONF = Tython.doxygen
DOXYOUT  = docs

.SUFFIXES: .cc .o 

.PHONY: test clean tags force all

%.o : %.cc
$(TEST_SRCS_DIR)/%.o : $(TEST_SRCS_DIR)/%.cc
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@ 
%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS) 
	$(RANLIB) $@

$(TEST_TARGET): $(TARGET) $(TEST_OBJS)
	$(CXX) $(TEST_LIBS) $(TARGET) $(TEST_OBJS) -o $@

test: $(TEST_TARGET) force
	./$(TEST_TARGET) --gtest_output=xml

clean:
	$(RM) $(RM_GC)
	$(RM) $(TARGET) $(TEST_TARGET)
	$(RM) $(OBJS) $(TEST_OBJS)
	$(RM) $(TAGSFILE)
	$(RM) $(OBJS_GCOV)
	$(RM) test_detail.xml
	$(RM) -r $(DOXYOUT)
	cd $(SRCS_DIR)      && $(RM) $(RM_GC)
	cd $(TEST_SRCS_DIR) && $(RM) $(RM_GC)


tags:
	@$(TAGS) $(TAGSOPTION)

doxygen:
	$(DOXYGEN) $(DOXYCONF)

force:

all: $(TARGET)
