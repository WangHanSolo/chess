#include <iostream>
#include <string>

char startup[8][8] = 
{
'r','n','b','q','k','b','n','r',
'p','p','p','p','p','p','p','p',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'-','-','-','-','-','-','-','-',
'P','P','P','P','P','P','P','P',
'R','N','B','Q','K','B','N','R'};


void printb(char board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
int main()
{

    std::cout<<"Han's foolish attempt at making my own chess engine"<<std::endl<<std::endl;
    printb(startup);
    while(1)
    {
    }
}
