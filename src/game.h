#pragma once
struct Game
{
    int turnNum;
    bool turnSide; //true for white, false for black
    
    bool whiteCastleQueenSide;
    bool whiteCastleKingSide;
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

