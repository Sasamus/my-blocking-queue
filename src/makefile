CC 			= g++
CCFLAGS		= -std=c++0x
PROGS		= my-blocking-queue
LIBS		= -pthread
FILES		= BlockingQueue.cpp
OBJS		= BlockingQueue.o
GCH			= BLockingQueue.h.gch

all: compile my-blocking-queue

my-blocking-queue: $(OBJS)
	$(CC) $(CCFLAGS) -o $@  $(OBJS) $(LIBS)

compile: $(FILES)
	$(CC) $(CCFLAGS) -c $(FILES)

clean:
	rm -f $(PROGS) $(OBJS) $(GCH)
