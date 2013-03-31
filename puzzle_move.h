#ifndef PUZZLEMOVE_H
#define PUZZLEMOVE_H
#include <functional>
#include "board.h"
#include "puzzle_heur.h"

/** Class PuzzleMove represents a single potential move
 * storing the tile that would be moved and the 
 * resulting board
*/
class PuzzleMove
{
 public:
  /** Constructor for starting Board of an A* search*/
  PuzzleMove(Board &b);

  /** Constructor for subsequent search boards 
   * (i.e. those returned by Board::potentialMoves() )
  */
  PuzzleMove(int tile, Board *b, PuzzleMove *parent);

  /** Destructor*/
  ~PuzzleMove();

  /** Compare to PuzzleMoves based on f distance */
  bool operator<(const PuzzleMove& p) const;
  /** Compare to PuzzleMoves based on f distance */
  bool operator>(const PuzzleMove& p) const;
  /** Compare to PuzzleMoves based on f distance */
  bool operator==(const PuzzleMove& p) const;

 
 public:
  /// tile moved to reach the Board b
  int tileMove_; 
  /// Pointer to a board representing the updated state
  Board *b_;   
  /// distance from the start board 
  int g_;  
  /// heuristic distance to the goal       
  int h_;         
  /// Pointer to parent PuzzleMove
  PuzzleMove *prev_;  
};


// Leave this alone and don't touch it!
/** This class is used to sort a list*/
struct PuzzleMoveGreater : 
  public std::binary_function<const PuzzleMove*, const PuzzleMove*,bool>
{
/// create an operator to compare two PuzzleMove
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    return *m1 > *m2;
  }
};

#endif
