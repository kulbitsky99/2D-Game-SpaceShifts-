SOURCES_C = $(wildcard *.cpp)
OBJS_O = $(SOURCES_C:.cpp=.o)
CC = g++
IDIR =../
CFLAGS = -Wall -Wextra -pedantic -I$(IDIR)
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
RM = /bin/rm -rf

_DEPS = $(wildcard *.h)
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: main objects

main: $(OBJS_O)
	$(CC) -c $(SOURCES_C)

objects: $(OBJS_O)
	$(CC) $(OBJS_O) -o go $(SFMLFLAGS)
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $(@) $<

clean:  
	$(RM) *.o go
