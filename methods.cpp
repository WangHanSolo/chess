/**
 * This file is for miscellaneous methods
 */

#define ROWS 8
#define COLS 8
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
