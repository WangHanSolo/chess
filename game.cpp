#include <iostream>
#include <string>
//#include "methods.cpp"
#define ROWS 8
#define COLS 8

char board[ROWS][COLS] = 
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

/**
 * flips board if player wants to play black
 */
void flipboard()
{
    char temp[ROWS][COLS] = 
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
 *convert board alphabet coordinates to numbers for array indexing
 */
int alphabet2int(char letter)
{
    int num;
    char alph[8] = {'a','b','c','d','e','f','g','h'};

    for(int i = 0; i < 8; i++)
    {
        if(letter==alph[i])
        {
            num = i;
            break;
        }
    }
    return num; 
}

/**
 * Takes the move string and moves the pieces on the board
 * '1' ascii is 49, 8 ascii is 56
 */
void move_piece(std::string move,char board[ROWS][COLS])
{
    std::cout<<move[1]<<std::endl<<move[3]<<std::endl<<std::endl;
    int origin_row = 56-(int)move[1]; int origin_col = alphabet2int(move[0]);
    int dest_row = 56-(int)move[3]; int dest_col = alphabet2int(move[2]);


    board[dest_row][dest_col] = board[origin_row][origin_col];
    board[origin_row][origin_col] = '-';
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
        std::cout<<std::endl<<std::endl;

        move_piece(move, board);

        printb();
    }

    std::cout<<"Thanks for playing"<<std::endl;
}
