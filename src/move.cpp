#include <iostream>

#include "move.h"
#include "legalmove.h"

Game move_piece(std::string input, Game game)
{
    if(game.board[(56-input[1]) * 8 + alphabet2int(input[0])] == '-')
    {
        std::cout<<"Invalid move"<<std::endl;
        return game;
    }

    Move move; 
    move.from_row = 56 - input[1]; 
    move.from_col = alphabet2int(input[0]);
    move.to_row = 56 - input[3]; 
    move.to_col = alphabet2int(input[2]);
    move.piece = game.board[(56-input[1]) * 8 + alphabet2int(input[0])];

    if(legal_move(move,game))
    {
        //replace destination square with piece
        game.board[move.to_row * 8 + move.to_col] = move.piece;
        
        //replaces the origin square with -
        game.board[move.from_row * 8 + move.from_col] = '-';
    }
    else
    {
        std::cout<<std::endl<<"INVALID MOVE"<<std::endl;
    }

return game;
}

bool legal_move(Move move, Game game)
{
    if(move.piece == 'P')
        return pawnLegalMove(move,game);

    if(move.piece == 'R')
        return rookLegalMove(move,game);

    if(move.piece == 'B')
        return bishopLegalMove(move,game);

    if(move.piece == 'K')
        return kingLegalMove(move,game);
    
    //TODO THIS NEEDS A LOT OF THOUGHT HOW TO IMPLEMENT
    if(move.piece == 'Q')
        return false;


//   if(move.char == 'N')
//       return knightLegalMove(move,game);

    return false;
}

int alphabet2int(char letter)
{
    int num;
    char alph[8] = {'a','b','c','d','e','f','g','h'};

    for(int i = 0; i < 8; i++)
    {
        if(letter ==alph[i])
        {
            num=i;
            break;
        }
    }
    return num;
}