

SRCS = test2.c

HDRS = 

OBJS = test2.o

CC = gcc

CFLAGS = -g -Wall

PROGRAM = exe

all = $(PROGRAM)

$(PROGRAM) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)
         
#bit_manupulation.o : bit_manupulation.c
#adport.o : adport.c adport.h

.PHONY = clean

clean :
	rm -f *.o *.c~ *.swp $(PROGRAM)

