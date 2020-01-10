#include "game.h"

/**
 * Updates the game data structure to reflect the state of the game
 * The method is called after a legal move is made
 * The char array has been changed in the move(move.h) method and will be
 * used to update the game  
 * used in move_piece method
 *
 * TODO: (1/8)not sure if needed, complexity problems might rend this moot
 */
Game update_game(Game game)
{
    return game;
}

/**
 * Assigns values to Game struct to set the board
 */
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
    
    bool black[64]=
    {
        1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0
    };

    bool white[64]=
    {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1
    };

    for(int i = 0; i < 64; i++)
    {
        game.board[i] = board[i];
        game.whitePiecesPosition[i] = white[i];
        game.blackPiecesPosition[i] = black[i];
    }

    return game;
}

