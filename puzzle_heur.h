#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H

/** A virtual class*/
class PuzzleHeuristic
{
 public:
 /** ceate a virtual member function compute() so that
  * its derived class must have this function included.
 */
  virtual int compute(int *tiles, int size) = 0;
};


/** An actual ManhattanHeuristic Classes declared here that have only one method
 * called compute() to compute the value of h_
*/
class ManhattanHeuristic: public PuzzleHeuristic{
	public:
	int compute(int *tiles, int size);

};

/** An actual OutOfPlaceHeuristic Classes declared here that have only one method
 * called compute() to compute the value of h_
*/
class OutOfPlaceHeuristic: public PuzzleHeuristic{
	public:
	int compute(int *tiles, int size);

};


#endif
