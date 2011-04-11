include ./Makefile.defs

TARGET      = Tython
TARGET_LIBS = libTython.a
TEST_TARGET = main_test
DEPEND      = Makefile.dep

RM    = rm -f
RM_GC = *~ \#*

TAGS       = gtags
TAGSOPTION = 
TAGSFILE   = GPATH GRTAGS GSYMS GTAGS 

.SUFFIXES: .cc .o 

.cc.o:
	$(CC) $(CFLAGS) $(ARCH) $(INCLUDE) -c $< -o $@ 

$(TARGET): $(TARGET_LIBS) $(OBJS_MAIN)
	$(CC) $(LIBS) $(TARGET_LIBS) $(OBJS_MAIN) -o $@

$(TARGET_LIBS): $(OBJS)
	ar crus $@ $(OBJS)

$(TEST_TARGET): $(TARGET_LIBS) $(TEST_OBJS)
	$(CC) $(LIBS) $(TEST_LIBS) $(TARGET_LIBS) $(TEST_OBJS) -o $@

test: $(TEST_TARGET) force
	./$(TEST_TARGET)

clean:
	$(RM) $(RM_GC)
	$(RM) $(TARGET) $(TARGET_LIBS) $(TEST_TARGET)
	$(RM) $(OBJS_ALL) $(TEST_OBJS)
	$(RM) $(DEPEND)
	$(RM) $(TAGSFILE)
	cd $(SRCS_DIR)      && $(RM) $(RM_GC)
	cd $(TEST_SRCS_DIR) && $(RM) $(RM_GC)

depend:
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -E -MM > $(DEPEND)

tags:
	@$(TAGS) $(TAGSOPTION)

force:

all: $(TARGET)

-include $(DEPEND)

