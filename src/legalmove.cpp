#include <cstdlib> //for abs()
#include <iostream>

#include "legalmove.h"

bool pawnLegalMove(Move move, Game game)
{ 
   int step = move.from_row - move.to_row; 
    //returns false if different column not capturing 
    //or in same row moves backwards
    if(
            move.from_col != move.to_col || //moves column and not capturing
            step < 1 || //if step is not forward
            step > 2 || //if step is greater than 2
            (move.from_row != 6) || // not in 2nd rank and moves two steps
            game.whitePiecesPosition[move.to_row*8+move.to_col]==1 ||//if dest is occupied by a white piece
            game.blackPiecesPosition[move.to_row*8+move.to_col]==1
            )

        return false;

    return true;
}

bool rookLegalMove(Move move, Game game)
{
    int xstep = abs(move.to_col - move.from_col);
    int ystep = abs(move.to_row - move.from_row);
    if(
            //both x and y change
            (xstep != 0 && ystep != 0) ||
            //neither x nor y change
            (xstep == 0 && ystep == 0)
      )
        return false;
    
    /**check if there is a piece blocking
     * first check if rook is moving vert or horiz
     */
    //moving horz
//    if(move.from_row==move.to_row)
//    {
//
//    }
//
//    //moving vert
//    if(move.from_col==move.to_col)
    
        
       
    return true;
}

bool knightLegalMove(Move move, Game game)
{
    int xstep = abs(move.to_row - move.from_row);
    int ystep = abs(move.to_col - move.from_col);

    //if steps are greater than 2 return false
    if(xstep > 2 || ystep > 2)
    {
        //std::cout<<"greater than 2"<<std::endl;
        return false;
    }


    //if steps are equal return false
    if(xstep == ystep)
    {
        //std::cout<<"steps equal"<<std::endl;
        return false;
    }
    //std::cout<<"knight legal move method reached"<<std::endl;
    return true;
}

bool bishopLegalMove(Move move, Game game)
{
    int xstep = abs(move.from_col - move.to_col);
    int ystep = abs(move.from_row - move.to_row);
    //x = y steps and !=0

    if(xstep == ystep && xstep !=0)
        return true;

    return false;
}

bool kingLegalMove(Move move, Game game)
{
    //can only move 1 square  
    //xstep and ystep can have values of 0,1 and cannot both be 0
    int xstep = abs(move.from_col - move.to_col);
    int ystep = abs(move.to_row - move.from_row);

    if(xstep==0 && ystep == 0)
        return false;

    if(xstep > 1 || ystep > 1)
        return false;

    //invalid move if the dest is occupied by white piece
    if(game.whitePiecesPosition[move.to_row*8 + move.to_col]==true)   
        return false;

    return true;
}
