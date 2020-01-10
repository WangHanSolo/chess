#pragma once

#include "move.h"
struct Game
{
    int turnNum;
    int total_moves;
    bool turnSide; //true for white, false for black
    
    bool whiteCastleKingSide;
    bool whiteCastleQueenSide;

    bool blackCastleKingSide;
    bool blackCastleQueenSide;

    char board[64];
    bool whitePiecesPosition[64];
    bool blackPiecesPosition[64];

};

/**
 *Returns new chess game
 */
Game initialize_board();
Game load_board(std::string filename);
Game update_game(Move move,Game game);
