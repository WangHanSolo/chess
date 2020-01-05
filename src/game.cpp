#include "game.h"

Game initialize_board()
{
    Game game;

    game.turnNum = 0;
    game.turnSide = true;
    game.whiteCastleQueenSide = true;
    game.whiteCastleKingSide = true;
    game.blackCastleKingSide = true;
    game.blackCastleQueenSide = true;

    char board[64] = 
    {
    'r','n','b','q','k','b','n','r',
    'p','p','p','p','p','p','p','p',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    'P','P','P','P','P','P','P','P',
    'R','N','B','Q','K','B','N','R'
    };

    for(int i = 0; i < 64; i++)
    {
        game.board[i] = board[i];
    }

    return game;
}
