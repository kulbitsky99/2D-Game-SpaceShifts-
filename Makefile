SOURCE_S = functions.cpp physics_engine.cpp earth.cpp trash_obj.cpp main.cpp game_obj.cpp satellite_obj.cpp bullet_obj.cpp
CC = g++
CFLAGS = -Wall -Wextra -pedantic
RM = /bin/rm -rf

all: main objects clean

main: 
	g++ -c $(SOURCE_S)

objects: 
	g++ functions.o earth.o physics_engine.o trash_obj.o satellite_obj.o bullet_obj.o game_obj.o main.o -o go -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:  
	$(RM) *.o pro
