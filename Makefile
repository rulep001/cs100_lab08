#Iterator makefile

#Variables
COMPILE = g++
FLAGS = -W -Wall -Werror -g
OBJS = iterator.o composite.o

#Targets

all: test.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out test.cpp $(OBJS)

iterator.o: iterator.cpp iterator.h
	$(COMPILE) $(FLAGS) -c iterator.cpp
	
composite.o: composite.cpp composite.h
	$(COMPILE) $(FLAGS) -c composite.cpp

clean:
	rm -rf *~ *.o a.out