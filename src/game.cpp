#include <string>
#include <fstream>

#include "game.h"
#include "move.h"
/**
 * Updates the game data structure to reflect the state of the game
 * The method is called after a legal move is made
 * The char array has been changed in the move(move.h) method and will be
 * used to update the game  
 * used in move_piece method
 *
 * TODO: (1/8)not sure if needed, complexity problems might rend this moot
 */
Game update_game(Move move, Game game)
{
    game.turnSide = !game.turnSide;
    game.total_moves++;
    game.turnNum = game.total_moves/2+1;

    //White's turn updates array tracking white position
    if(game.turnSide == 1)
    {
        game.whitePiecesPosition[move.to_row * 8 + move.to_col]=1;
        game.whitePiecesPosition[move.from_row * 8 + move.from_col]=0;
    }

    //Black's turn updates array tracking blacks position
    if(game.turnSide==0)
    {
        game.blackPiecesPosition[move.to_row * 8 + move.to_col]=1;
        game.blackPiecesPosition[move.from_row * 8 + move.from_col]=0;
    }

    game.piecesPosition[move.to_row * 8 + move.to_col] = 1;
    game.piecesPosition[move.from_row * 8 + move.from_col] = 0;

    return game;
}
/**
 * Assigns values to Game struct to set the board
 */
Game initialize_board()
{
    Game game;
    
    game.turnNum = 0;
    game.total_moves = 0;
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

    bool pieces[64] = 
    {
        1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,
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
        game.piecesPosition[i] = pieces[i];
    }

    return game;
}

/**
 * loads a txt file that contains a chess board
 */
Game load_board(std::string filename)
{
    Game game;
    char fileContent[71];


    std::ifstream file(filename);

    for(int i = 0; i < 70; i++)
    {
        file >> fileContent[i];
    }

    game.turnNum = fileContent[0] - '0';
    game.turnSide = fileContent[1] - '0';
    game.whiteCastleKingSide = fileContent[2] - '0';
    game.whiteCastleQueenSide = fileContent[3] - '0';
    game.blackCastleKingSide = fileContent[4] - '0';
    game.blackCastleQueenSide = fileContent[5] - '0';

    for(int i = 6; i < 70; i++)
        game.board[i-6] = fileContent[i];

    return game;
}




