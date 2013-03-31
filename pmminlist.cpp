#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param pm Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
	if(slist_.empty()){
		slist_.insert(slist_.begin(),pm);
	}
	else{
  		std::list<PuzzleMove*>::iterator it; 
  		for(it= slist_.begin();it!=slist_.end();++it){
  			if(*pm<*(*it))
  				slist_.insert(it,pm);
  			return;
  		}
 	}
 }
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
 //---- See http://www.cplusplus.com/reference/list/list/insert/
//std::list<PuzzleMove*>::iterator PMMinList::begin(){
//	return slist_.begin();
//}

//std::list<PuzzleMove*>::iterator PMMinList::end(){
//	return slist_.end();
//}

//std::list<PuzzleMove*>::iterator PMMinList::erase(std::list<PuzzleMove*>::iterator it){
//	return slist_.erase(it);
//}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

