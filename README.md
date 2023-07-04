# Maze Escape Game

## Description

Maze Escape Game is a turn-based maze game where the player, represented by the Intrepid Student, must navigate through a randomly generated maze to escape while avoiding the TAs and appeasing them with programming skills. The goal is to reach the Instructor with a sufficient number of programming skills to pass the course.

## Game Setup

- The size of the square maze is determined by the user's input.
- Mazes smaller than 5 spaces on a side are not allowed, and the user is reprompted until a valid input is given.
- The maze is randomly configured with walls, open spaces, programming skills, TAs, the Instructor, and the Intrepid Student.
- The Instructor cannot share its space with programming skills, TAs, or the Intrepid Student.
- An open space can have at most 1 programming skill.
- Multiple TAs and/or the Intrepid Student may share the same square.

## Class Structure

- The game utilizes the following classes:
  - Wall and OpenSpace, which derive from the abstract class MazeLocation.
  - IntrepidStudent, TA, and Instructor, which derive from the abstract class MazePerson.
  - MazeLocation and MazePerson are abstract classes.
  - MazeLocation is used polymorphically, and the Maze contains a member of MazeLocation instead of Wall or OpenSpace.
  - A std::vector is used to implement a grid of MazeLocation objects.
  - The Game class represents the entire turn-based maze game and is responsible for managing the game's functionalities.

## Game Functionalities

- The Intrepid Student can move to adjacent open spaces within the maze using the WASD controls (or equivalent).
- TAs move around the maze each turn to adjacent open spaces.
- The Intrepid Student picks up a programming skill when moving into a space containing one, while TAs do not affect programming skills.
- If a TA enters a space adjacent to the Intrepid Student and the TA is not appeased, the player loses the game.
- Demonstrating a programming skill appeases the TAs for 10 turns.
- If the Intrepid Student reaches the Instructor and holds at least 3 programming skills, they are allowed to escape from the maze with a passing grade; otherwise, they lose the game.
- The maze is displayed correctly with different character symbols, and clear instructions are provided after each move/turn.
- The game keeps track of the number of programming skills the Intrepid Student has.
- The user can choose to play again until they choose to quit.

## Installation

1. Clone the repository or download the source code files.
2. Ensure that you have a C++ compiler installed on your system.
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the program using the provided makefile.
5. Run the compiled executable.

## Dependencies

- C++ compiler (e.g., g++)
- make (build tool)

## File Structure

- `Makefile`: Build automation file.
- `main.cpp`: Main driver file.
- `maze.h`: Header file containing the MazeLocation, Wall, OpenSpace, MazePerson, IntrepidStudent, TA, Instructor, and Game class declarations.
- `maze.cpp`: Implementation file for the MazeLocation, Wall, OpenSpace, MazePerson, IntrepidStudent, TA, Instructor, and Game classes.
