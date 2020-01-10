## Chess Engine

My foolish attempt to create my own chess engine. Its still a work in progress. If you want to try it out clone the repository and compile by entering "make" (without parantheses). It will create the executable "game". GLHF!

## File Structure

src: all the code :)
test: unit tests :(
## Progress 

#1/11/2020
Finished QueenLegalMove, load board from txt, and update game methods. Right now program throws error when compiling need to debug. Next step is think about whether AllyCollision method is needed.

#1/7/2020
worked on legal moves for all pieces except for queen, still wip. Need to finish rook checking collision in legalmoves.cpp
TODO:
1. check colision for rook,bishop
2. work on queen legal move
3. attack board?

# 1/6/2020
reorganized data structure that stores game state, added methods to check pawn and rook legal moves\
TODO:
1. method to check collison
2. legal moves for other pieces
3. add data structures within Game struct to keep track of white/black pieces
    
# 1/2/2020
print board and ask user for move TODO: need to figure out how to pass board to move method


