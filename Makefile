include ./Makefile.defs

TARGET      = Tython
TEST_TARGET = TestTython
DEPEND      = Makefile.dep

RM    = rm -f
RM_GC = *~ \#*

TAGS       = gtags
TAGSOPTION = 
TAGSFILE   = GPATH GRTAGS GSYMS GTAGS 

.SUFFIXES: .cc .o 

.cc.o:
	$(CC) $(CFLAGS) $(ARCH) $(INCLUDE) -c $< -o $@ 

$(TARGET): $(OBJS_ALL)
	$(CC) $(LIBS) $(OBJS_ALL) -o $@

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(LIBS) $(TEST_LIBS) $(OBJS) $(TEST_OBJS) -o $@

test: $(TEST_TARGET) force
	./$(TEST_TARGET)

clean:
	$(RM) $(RM_GC)
	$(RM) $(TARGET) $(TEST_TARGET)
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

