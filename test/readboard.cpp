#include <iostream>
#include <fstream>
#include <string>

int main()
{
    char board1D[64];
    char current_char;
    int num_characters = 64;
    int i = 0;


    std::ifstream txtfile ("board.txt");

    if(txtfile.is_open())
    {
        while(i<64)
        {
            txtfile >> board1D[i];
            i++;
        }
        
        for(int i =0; i <num_characters;i++)
        {
            std::cout<<board1D[i];
         
        }
        std::cout<<std::endl;
    }
}
