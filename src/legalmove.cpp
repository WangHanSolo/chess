#include "legalmove.h"

bool pawnLegalMove(Move move, Game game)
{ 
   int step = move.from_row - move.to_row; 
    //returns false if different column not capturing 
    //or in same row moves backwards
    if(move.from_col != move.to_col || step < 1)
        return false;

    //returns false if it isnt in 2 rank and takes 2 steps
    if(move.from_row != 6 && step > 1)
        return false;
    
    return true;
}

bool rookLegalMove(Move move, Game game)
{
    if((move.from_row==move.to_row)^(move.from_col==move.to_col))
        return true;
    return false;
}

bool knightLegalMove(Move move, Game game)
{
    
    return true;
}

bool bishopLegalMove(Move move, Game game)
{
    return true;
}

bool kingLegalMove(Move move, Game game)
{
    return true;
}
