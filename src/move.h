#pragma once

#include "game.h"

struct Move
{
    char piece;
    int from_row;
    int from_col;
    int to_row;
    int to_col;
};
/*
moves the chess piece

Parameters: 
    move: user input, should be in the format a1a2
    game: current game

returns the updated game
 */
Game move_piece(std::string input, Game game);

bool legal_move(Move move, Game game);

/**
 * convert board alphabet coordinates to numbers for array indexing
 *
 * Paramter
 *  letter: the char to be converted, should be a~h
 *
 * Returns an int with value between 0~7 
 */
int alphabet2int(char letter);
