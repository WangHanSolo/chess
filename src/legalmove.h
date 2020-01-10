#include "move.h"
#include "game.h"

/**
 * Checks if the move is legal
 *
 * Paramters:
 *    move: the move to be checked
 *    game: the current state of game
 * Returns true if move is legal false otherwise
 *
 * NOTE: There isnt a method for the queen bc it is the combination of rook and bishop
 */
bool pawnLegalMove(Move move, Game game);
bool rookLegalMove(Move move, Game game);
bool knightLegalMove(Move move, Game game);
bool bishopLegalMove(Move move, Game game);
bool kingLegalMove(Move move, Game game);
bool queenLegalMove(Move move, Game game);
bool checkAllyCollision(Move move, Game game);
