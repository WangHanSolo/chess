#include <iostream>
#include <string>
#include "move.cpp"

char board[8][8] = 
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

/**
 * flips board if player wants to play black
 */
void flipboard()
{
    char temp[8][8] = 
    {
    'R','N','B','Q','K','B','N','R',
    'P','P','P','P','P','P','P','P',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    '-','-','-','-','-','-','-','-',
    'p','p','p','p','p','p','p','p',
    'r','n','b','q','k','b','n','r',
    };
    
    for(int i=0; i<8;i++)
    {
        for(int j=0; j<8; j++)
        {
            board[i][j]=temp[i][j];
        }       
    }
}

/**
 * Prints board to console
 */
void printb()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

int main()
{
    int side;
    std::string move;
    std::cout<<"Han's foolish attempt at making his own chess engine"<<std::endl<<std::endl;
   
    
    std::cout<<"what side do you want to play?"<<std::endl;
    std::cout<<"    enter 1 for white"<<std::endl;
    std::cout<<"    enter 2 for black"<<std::endl;
    std::cin>>side;

    if(side==2)
        flipboard();

    printb();
    
    while(1)
    {
        std::cout<<"Please enter your move or enter q to quit"<<std::endl;
        std::cin>>move;

        if(move == "q")
           break; 
        std::cout<<std::endl<<std::endl<<std::endl;

        move(board);

        printb();
    }

    std::cout<<"Thanks for playing"<<std::endl;
}
