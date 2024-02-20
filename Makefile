CC := gcc
EXE_FILE := exam_2
CFLAGS := -g -ansi -pedantic-errors -Wall
SRCDIR := data_structures
OBJDIR := obj
TESTDIR := tests
SOLDIR := solutions

# Don't strictly need, but allows command `make all`
.PHONY: all, test, clean
.PHONY: solutions
.PHONY: bst hash_table d_linked_list stack bag deque queue


all: $(EXE_FILE)

$(EXE_FILE): \
 $(OBJDIR)/main.o $(OBJDIR)/type.o \
 $(OBJDIR)/bst.o $(OBJDIR)/hash_table.o $(OBJDIR)/d_linked_list.o $(OBJDIR)/stack.o $(OBJDIR)/bag.o $(OBJDIR)/deque.o $(OBJDIR)/queue.o \
 $(SRCDIR)/bst.h $(SRCDIR)/hash_table.h $(SRCDIR)/d_linked_list.h $(SRCDIR)/stack.h $(SRCDIR)/bag.h $(SRCDIR)/deque.h $(SRCDIR)/queue.h \
 $(OBJDIR)/test_bst.o $(OBJDIR)/test_hash_table.o $(OBJDIR)/test_d_linked_list.o $(OBJDIR)/test_stack.o $(OBJDIR)/test_bag.o $(OBJDIR)/test_deque.o $(OBJDIR)/test_queue.o \
 $(TESTDIR)/bst.h $(TESTDIR)/hash_table.h $(TESTDIR)/d_linked_list.h $(TESTDIR)/stack.h $(TESTDIR)/bag.h $(TESTDIR)/deque.h $(TESTDIR)/queue.h \
 $(OBJDIR)/_helpers.o $(TESTDIR)/_helpers.c | $(OBJDIR)
	$(CC) $(CFLAGS) -lm $(OBJDIR)/main.o $(OBJDIR)/type.o $(OBJDIR)/bst.o $(OBJDIR)/hash_table.o $(OBJDIR)/d_linked_list.o $(OBJDIR)/stack.o $(OBJDIR)/bag.o $(OBJDIR)/deque.o $(OBJDIR)/queue.o $(OBJDIR)/test_bst.o $(OBJDIR)/test_hash_table.o $(OBJDIR)/test_d_linked_list.o $(OBJDIR)/test_stack.o $(OBJDIR)/test_bag.o $(OBJDIR)/test_deque.o $(OBJDIR)/test_queue.o $(OBJDIR)/_helpers.o -o $(EXE_FILE)



$(OBJDIR)/main.o: main.c $(SRCDIR)/bst.h $(SRCDIR)/stack.h $(SRCDIR)/bag.h $(SRCDIR)/deque.h $(SRCDIR)/queue.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/type.o: type.c type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<



$(OBJDIR)/bst.o: $(SRCDIR)/bst.c $(SRCDIR)/bst.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/hash_table.o: $(SRCDIR)/hash_table.c $(SRCDIR)/hash_table.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/d_linked_list.o: $(SRCDIR)/d_linked_list.c $(SRCDIR)/d_linked_list.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/stack.o: $(SRCDIR)/stack.c $(SRCDIR)/stack.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/bag.o: $(SRCDIR)/bag.c $(SRCDIR)/bag.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/deque.o: $(SRCDIR)/deque.c $(SRCDIR)/deque.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/queue.o: $(SRCDIR)/queue.c $(SRCDIR)/queue.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<



$(OBJDIR)/test_bst.o: $(TESTDIR)/bst.c $(TESTDIR)/bst.h $(SRCDIR)/bst.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_hash_table.o: $(TESTDIR)/hash_table.c $(TESTDIR)/hash_table.h $(SRCDIR)/hash_table.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_d_linked_list.o: $(TESTDIR)/d_linked_list.c $(TESTDIR)/d_linked_list.h $(SRCDIR)/d_linked_list.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_stack.o: $(TESTDIR)/stack.c $(TESTDIR)/stack.h $(SRCDIR)/stack.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_bag.o: $(TESTDIR)/bag.c $(TESTDIR)/bag.h $(SRCDIR)/bag.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_deque.o: $(TESTDIR)/deque.c $(TESTDIR)/deque.h $(SRCDIR)/deque.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/test_queue.o: $(TESTDIR)/queue.c $(TESTDIR)/queue.h $(SRCDIR)/queue.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/_helpers.o: $(TESTDIR)/_helpers.c $(TESTDIR)/_helpers.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<



.PHONY: solutions

solutions: \
 $(OBJDIR)/main.o $(OBJDIR)/type.o \
 $(OBJDIR)/solution_bst.o $(OBJDIR)/solution_hash_table.o $(OBJDIR)/solution_d_linked_list.o $(OBJDIR)/solution_stack.o $(OBJDIR)/solution_bag.o $(OBJDIR)/solution_deque.o $(OBJDIR)/solution_queue.o \
 $(SOLDIR)/bst.h $(SOLDIR)/hash_table.h $(SOLDIR)/d_linked_list.h $(SOLDIR)/stack.h $(SOLDIR)/bag.h $(SOLDIR)/deque.h $(SOLDIR)/queue.h \
 $(OBJDIR)/test_bst.o $(OBJDIR)/test_hash_table.o $(OBJDIR)/test_d_linked_list.o $(OBJDIR)/test_stack.o $(OBJDIR)/test_bag.o $(OBJDIR)/test_deque.o $(OBJDIR)/test_queue.o \
 $(TESTDIR)/bst.h $(TESTDIR)/hash_table.h $(TESTDIR)/d_linked_list.h $(TESTDIR)/stack.h $(TESTDIR)/bag.h $(TESTDIR)/deque.h $(TESTDIR)/queue.h \
 $(OBJDIR)/_helpers.o $(TESTDIR)/_helpers.c | $(OBJDIR)
	$(CC) $(CFLAGS) -lm $(OBJDIR)/main.o $(OBJDIR)/type.o $(OBJDIR)/solution_bst.o $(OBJDIR)/solution_hash_table.o $(OBJDIR)/solution_d_linked_list.o $(OBJDIR)/solution_stack.o $(OBJDIR)/solution_bag.o $(OBJDIR)/solution_deque.o $(OBJDIR)/solution_queue.o $(OBJDIR)/test_bst.o $(OBJDIR)/test_hash_table.o $(OBJDIR)/test_d_linked_list.o $(OBJDIR)/test_stack.o $(OBJDIR)/test_bag.o $(OBJDIR)/test_deque.o $(OBJDIR)/test_queue.o $(OBJDIR)/_helpers.o -o $(EXE_FILE)



$(OBJDIR)/solution_bst.o: $(SOLDIR)/bst.c $(SOLDIR)/bst.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_hash_table.o: $(SOLDIR)/hash_table.c $(SOLDIR)/hash_table.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_d_linked_list.o: $(SOLDIR)/d_linked_list.c $(SOLDIR)/d_linked_list.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_stack.o: $(SOLDIR)/stack.c $(SOLDIR)/stack.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_bag.o: $(SOLDIR)/bag.c $(SOLDIR)/bag.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_deque.o: $(SOLDIR)/deque.c $(SOLDIR)/deque.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/solution_queue.o: $(SOLDIR)/queue.c $(SOLDIR)/queue.h type.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<



.PHONY: bst hash_table d_linked_list stack bag deque queue

bst: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_bst.o $(TESTDIR)/bst.h $(OBJDIR)/bst.o $(SRCDIR)/bst.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_bst -include $(TESTDIR)/bst.h -o $(EXE_FILE) $< $(OBJDIR)/test_bst.o $(OBJDIR)/bst.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

hash_table: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_hash_table.o $(TESTDIR)/hash_table.h $(OBJDIR)/hash_table.o $(SRCDIR)/hash_table.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_hash_table -include $(TESTDIR)/hash_table.h -o $(EXE_FILE) $< $(OBJDIR)/test_hash_table.o $(OBJDIR)/hash_table.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

d_linked_list: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_d_linked_list.o $(TESTDIR)/d_linked_list.h $(OBJDIR)/d_linked_list.o $(SRCDIR)/d_linked_list.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_d_linked_list -include $(TESTDIR)/d_linked_list.h -o $(EXE_FILE) $< $(OBJDIR)/test_d_linked_list.o $(OBJDIR)/d_linked_list.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

stack: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_stack.o $(TESTDIR)/stack.h $(OBJDIR)/stack.o $(SRCDIR)/stack.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_stack -include $(TESTDIR)/stack.h -o $(EXE_FILE) $< $(OBJDIR)/test_stack.o $(OBJDIR)/stack.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

bag: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_bag.o $(TESTDIR)/bag.h $(OBJDIR)/bag.o $(SRCDIR)/bag.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_bag -include $(TESTDIR)/bag.h -o $(EXE_FILE) $< $(OBJDIR)/test_bag.o $(OBJDIR)/bag.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

deque: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_deque.o $(TESTDIR)/deque.h $(OBJDIR)/deque.o $(SRCDIR)/deque.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_deque -include $(TESTDIR)/deque.h -o $(EXE_FILE) $< $(OBJDIR)/test_deque.o $(OBJDIR)/deque.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o

queue: $(TESTDIR)/_main.c $(OBJDIR)/type.o $(OBJDIR)/test_queue.o $(TESTDIR)/queue.h $(OBJDIR)/queue.o $(SRCDIR)/queue.h $(OBJDIR)/_helpers.o | $(OBJDIR)
	$(CC) $(CFLAGS) -lm -DTEST_FUNCTION=test_queue -include $(TESTDIR)/queue.h -o $(EXE_FILE) $< $(OBJDIR)/test_queue.o $(OBJDIR)/queue.o $(OBJDIR)/_helpers.o $(OBJDIR)/type.o



$(OBJDIR):
	mkdir $(OBJDIR)



.PHONY: clean
clean:
	rm -rf $(OBJDIR)/
	rm -f  $(EXE_FILE)
