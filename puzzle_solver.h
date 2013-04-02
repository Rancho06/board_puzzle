#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "mylist.h"

/**
	This class combines other classes together to solve the problem
	
	@author Shu Zhou
*/
class PuzzleSolver
{
 public:
  /** Typedef for the closed-list set.  Declare your closed list variable as
   *   BoardSet closedlist; 
   * when you write your code for the run() funciton
  */
  typedef std::set<Board *, BoardLessThan> BoardSet;

  /** Constructor (makes a copy of the Board and stores it in _b
  @param b The current state board to solve
  */
  PuzzleSolver(const Board &b);

  /// Destructor
  ~PuzzleSolver();

  /** Run the A* search returning -1 if no solution exists or
   *  the number of moves in the solution
   @param ph A pointer to a PuzzleHeuristic object that can be used to compute h_ value
   @return The number of steps it takes to solve the puzzle
  */
  int run(PuzzleHeuristic *ph);

  /** Return the solution List 
  @return A MyList of the solution sequence for cheat
  */
  MyList<int>* getlist();
  

  /** Return how many expansions were performed in the search 
  @return The number of expansions
  */
   int getNumExpansions();
  

 private:
  Board b_;
  int expansions_;
  //**** Declare a List to store your solutions sequence of tiles to move
  MyList<int> solutionlist;
  
};

#endif
