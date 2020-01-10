#include <iostream>
#include <string>

#include "src/game.h"
#include "src/move.h"

/**
 * Prints board to console
 */
void printb(Game game)
{

    std::cout<<std::endl<<std::endl;
    for(int i = 0; i < 64; i++)
    {
        std::cout<<game.board[i]<<" ";

        if(i%8==7)
            std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}


int main()
{
    int side;
    Game game;
    
    game = initialize_board();

    std::cout<<game.whiteCastleKingSide<<std::endl;
    std::string move;
    std::cout<<"Han's foolish attempt at making his own chess engine"<<std::endl<<std::endl;
   
    
    std::cout<<"what side do you want to play?"<<std::endl;
    std::cout<<"    enter 1 for white"<<std::endl;
    std::cout<<"    enter 2 for black"<<std::endl;
    std::cin>>side;

//    if(side==2)
//        flipboard();

    printb(game);
    
    while(1)
    {
        std::cout<<"Please enter your move or enter q to quit"<<std::endl;
        std::cin>>move;

        if(move == "q")
           break; 
        std::cout<<std::endl<<std::endl;

        game = move_piece(move, game);
        printb(game);
    }

    std::cout<<"Thanks for playing"<<std::endl;
}
