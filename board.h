#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <map>
#include <functional>

/** 
  Board Class is to create the board and do the basic operations to the board
  such as move a tile or check whether the board is solved or compare the two boards 
  using ==,<, or >.
  
  @author Shu Zhou 
*/
class Board
{
 public:
  /**  default constructor */
  Board(); 

  /** Init a board of given size and scramble it with numInitMoves 
   * by moving the space tile with a randomly chosen direction N, W, S, E
   * some of which may be invalid, in which case we skip that move */
  Board(int size, int numInitMoves, int seed);

  /** Copy constructor */
  Board(const Board &b);

  /** Another kind of "copy" constructor */
  Board(int *tiles, int size); 

  /** Destructor */
  ~Board();

  /** Swaps the blank with the specified tile */
  void move(int tile);

  /** Generate potential moves and returns new boards
   * Key=tile, Value=Ptr to corresponding Board */
  std::map<int, Board*> potentialMoves(); 
  
  /** used in potentialmove function. to create a new board based on our potential move.*/
  Board* NewBoard(int);

  /** Returns true if the board is solved, false otherwise */
  bool solved();

  /** Operators<< can output a Board object on the screen directly using friend connection*/
  friend std::ostream& operator<<(std::ostream &os, const Board &b);
  
  /** the operator== to compare the two boards.*/	
  bool operator==(const Board& rhs) const;
  
  /** the operator< to compare the two boards.*/
  bool operator<(const Board& rhs) const;
  
  /** the operator!= to compare the two boards.*/
  bool operator!=(const Board& rhs) const;
  
  // Accessors
  int* getTiles() const;
  int getSize() const;
  int getblankloc() const;
  // Add any accessors


 private:
  int *tiles_;
  int size_;
  // Add Data members

};

/** This is used to order the BoardSet class*/
struct BoardLessThan : 
  public std::binary_function<const Board*, const Board*,bool>
{
/** create a new operator to compare the two boards 
 *given the "<" operator we already defined
*/
  bool operator()(const Board *b1, const Board *b2) const
  {
    return *b1 < *b2;
  }
};



#endif
