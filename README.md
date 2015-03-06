# Puzzle - Programming Assignments Private Repository
### Student Information
  + Name: Shu Zhou
  + USC Email: shuzhou@usc.edu
  + USC ID: 8960637637

### Compile & Run Instructions
The grader should use the following procedure to compile and run the code:
```shell
make
./puzzle size initMoves seed
```

To complie files:
Run this:
qmake -project
then delete unneeded files from.pro file (puzzle.cpp)
qmake
make clean
make


To generate Doxygen:
Run this:
sudo apt-get install doxygen
make clean
doxygen -g config.txt
doxygen config.txt
