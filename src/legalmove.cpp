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
    int xstep = move.to_col - move.from_col;
    int ystep = move.to_row - move.from_row;

    if(
            //both x and y change
            (xstep != 0 && ystep != 0) ||
            //neither x nor y change
            (xstep == 0 && ystep == 0)
      )
    {
        return false;
    }
    //if going straight then check if path is blocked
    else
    {
        std::cout<<"checking if path is blocked"<<std::endl;
        //going horizontal
        if(xstep != 0)
        {
            //going right
            if(xstep > 0)
            for(int i = move.from_col + 1; i < move.to_col; i++)
            {
                if(game.piecesPosition[move.from_row * 8 + i] == 1)
                    return false;
            }
            else //going left
            {
                for(int i = move.from_col - 1; i > move.to_col; i--)
                {
                    if(game.piecesPosition[move.from_row * 8 + i] == 1)
                        return false;
                }
            }
        }
        //going vertical
        else  
        {
            std::cout<<"going vertical"<<std::endl;
           //going up
           if(ystep < 0)
           {
               std::cout<<"going up"<<std::endl;
               for(int i = move.from_row - 1; i > move.to_row; i--)
               {
                   if(game.piecesPosition[i * 8 + move.to_col] == 1)
                   {
                       return false;
                   }
               }
           }
           else //going down
           {
               for(int i = move.from_row + 1; i < move.to_row; i++) 
               {
                   if(game.piecesPosition[i * 8 + move.to_col] == 1)
                       return false;
               }
           }
        }
        
    } 
    //checks if destination has a same color piece
    if((game.turnSide == 1 && game.whitePiecesPosition[move.to_row * 8 + move.to_col] == 1) ||
       (game.turnSide == 0 && game.blackPiecesPosition[move.to_row * 8 + move.to_col] == 1))
        return false;

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
    
    //if there is already a same color piece there
    if((game.turnSide == 1 && game.whitePiecesPosition[move.to_row * 8 + move.to_col == true]) || 
       (game.turnSide == 0 && game.blackPiecesPosition[move.to_row * 8 + move.to_col == true]))
        return false;
    //std::cout<<"knight legal move method reached"<<std::endl;
    return true;
}

bool bishopLegalMove(Move move, Game game)
{
    int origin_index = move.from_row * 8 + move.from_col;
    int dest_index = move.to_row * 8 + move.to_col;
    int xstep = abs(move.from_col - move.to_col);
    int ystep = abs(move.from_row - move.to_row);
    //x = y steps and !=0
    //No pieces along path
//    std::cout<<"bishoplegalmovereached"<<std::endl;
    if(xstep == ystep && xstep !=0)
    {
//        std::cout<<"1st if statment passed"<<std::endl;
        //check diaganol direction
        //heading left
        if(move.from_col > move.to_col)
        {
            //heading down
            if(move.from_row < move.to_row)
            {
//                std::cout<<"heading left down"<<std::endl;
                for(int i = origin_index + 7; i < dest_index; i = i + 7)
                {
                    //if piece is along way return false
                    if(game.piecesPosition[i] == 1)
                        return false;
                }

            }
            //heading up
            else
            {
//                std::cout<<"heading left up"<<std::endl;
                for(int i = origin_index - 9; i > dest_index; i = i- 9)
                {
                    if(game.piecesPosition[i] == 1)
                    {
//                        std::cout<<"working"<<std::endl;
                        return false;
                    }
                }
            }
        }
        //heading right
        else
        {
            //heading down
            if(move.from_row < move.to_row)
            {
//                std::cout<<"heading right down"<<std::endl;
                for(int i = origin_index + 9; i < dest_index; i = i + 9)
                {
                    if(game.piecesPosition[i] == 1)
                        return false;
                }
            }
            //heading up
            else
            {
//                std::cout<<"heading right up"<<std::endl;
                std::cout<<origin_index<<std::endl;
                for(int i = origin_index - 7; i > dest_index; i = i - 7)
                {
//                    std::cout<<"for loop reached"<<std::endl;
                    if (game.piecesPosition[i] == 1)
                        return false;
                }
            }

        }
    }
    else
        return false;

    //destination contain same color piece return false
    if(game.turnSide == 1 && game.whitePiecesPosition[move.to_row * 8 + move.to_col] == true)
        return false;
    if(game.turnSide == 0 && game.blackPiecesPosition[move.to_row * 8 + move.to_col] == true)
        return false;

//    std::cout<<"bishoplegalmove returning true"<<std::endl;

    return true;
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

bool queenLegalMove(Move move, Game game)
{
    bool bishop = bishopLegalMove(move,game);
    bool rook = rookLegalMove(move,game);
    if(rook)
        std::cout<<"bishop"<<std::endl;
    if(bishop)
        std::cout<<"rook"<<std::endl;
    //
    //queen can move like bishop or rook but not both at the same time (XOR)
    if(!bishopLegalMove(move, game) != !rookLegalMove(move,game))
        return true;
  
    return false;
}
