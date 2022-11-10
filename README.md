# GameOfLife

Project created by Maciej Matusiak. The game was designed and created as a part of academic programming classes. The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a game in which users decide one of two form of game if he wants to go to the next animation transform or if the computer does it for him. The rules of the game and the mechanism that supports the user's movements are based on the OPP paradigm and implemented in game files divided according to the structure of object-oriented programs. The configured CMake file was used for the compilation and project management process.

# Rules:

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead. Every cell interacts with it is eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

- Any live cell with fewer than two live neighbours dies, as if by underpopulation. 
- Any live cell with two or three live neighbours lives on to the next generation. 
- Any live cell with more than three live neighbours dies, as if by overpopulation. 
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. 
