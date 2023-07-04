CC=g++ -std=c++11
EXE_FILE=driver

all: $(EXE_FILE)

$(EXE_FILE): Game.o Maze.o MazeLocation.o Wall.o OpenSpace.o MazePerson.o IntrepidStudent.o TA.o Instructor.o driver.cpp
	$(CC) Game.o Maze.o MazeLocation.o Wall.o OpenSpace.o MazePerson.o IntrepidStudent.o TA.o Instructor.o driver.cpp -o $(EXE_FILE)

Game.o: Game.cpp
	$(CC) -c Game.cpp

Maze.o: Maze.cpp
	$(CC) -c Maze.cpp

MazeLocation.o: MazeLocation.cpp
	$(CC) -c MazeLocation.cpp

Wall.o: Wall.cpp
	$(CC) -c Wall.cpp

OpenSpace.o: OpenSpace.cpp
	$(CC) -c OpenSpace.cpp

MazePerson.o: MazePerson.cpp
	$(CC) -c MazePerson.cpp
	
IntrepidStudent.o: IntrepidStudent.cpp
	$(CC) -c IntrepidStudent.cpp

TA.o: TA.cpp
	$(CC) -c TA.cpp

Instructor.o: Instructor.cpp
	$(CC) -c Instructor.cpp

clean:
	rm -f *.o $(EXE_FILE)