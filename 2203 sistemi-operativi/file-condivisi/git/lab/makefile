CC = gcc
LD = gcc
DEPS_GEN = $(CC) -MM $(CFLAGS)

CFLAGS = -std=c99 #-Wall
LDFLAGS = -lm -lpthread

SRCS = $(wildcard *.c)
LIBS_SRCS = $(wildcard lib-*.c)
LIBS_OBJS = $(LIBS_SRCS:.c=.o)
PROGS_SRCS = $(filter-out $(LIBS_SRCS), $(SRCS))
PROGS = $(patsubst %.c,%,$(PROGS_SRCS))
PROGS_OBJS = $(addsuffix .o, $(PROGS))
DEPS_FILE = makefile.deps

GIT_FOLDER = ../../../git-repository/lab/examples/
GIT_RELEASES = makefile makefile.sample hello.c at-exit.c lib-misc.h lib-misc.c creation-mask.c test-seek-on-stdin.c count.c hole.c copy.c redirect.c copy-stream.c streams-and-buffering.c my-cat.c stat.c list-dir.c move.c mmap-read.c mmap-copy.c mmap-reverse.c fork.c fork-buffer-glitch.c multi-fork.c # multi-fork-with-wait.c exec.c nano-shell.c thread-ids.c multi-thread-join.c thread-memory-glitch.c thread-conc-problem.c thread-conc-problem-fixed-with-mutex.c thread-prod-cons-with-sem.c thread-number-set-with-rwlock.c thread-safe-number-set-with-rwlock.c thread-safe-number-queue-as-monitor.c thread-barrier.c thread-sort-with-barrier.c

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS += -lbsd
endif

all: $(PROGS)

%: $(LIBS_OBJS) %.o makefile
	$(LD) $(LIBS_OBJS) $(basename $@).o -o $@ $(LDFLAGS)

lib-%.o: lib-%.c lib-%.h makefile
	$(CC) $(CFLAGS) -c $<

$(DEPS_FILE): *.[Cch]
	for i in *.[Cc]; do $(DEPS_GEN) "$${i}"; done > $@

-include $(DEPS_FILE)

depend:
	$(DEPS_GEN) $(CFLAGS) $(LIBS_SRCS) > $(DEPS_FILE)

clean:
	rm -f $(PROGS) $(LIBS_OBJS) $(PROGS_OBJS) $(DEPS_FILE)

print-%:
	@echo $* = $($*)

git-add: $(GIT_RELEASES)
	cp $(GIT_RELEASES) $(GIT_FOLDER) && git -C $(GIT_FOLDER) add $(GIT_RELEASES) -v
