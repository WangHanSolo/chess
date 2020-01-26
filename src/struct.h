#pragma once


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
    bool piecesPosition[64];
};

struct Move
{
    char piece;
    int from_row;
    int from_col;
    int to_row;
    int to_col;
};

