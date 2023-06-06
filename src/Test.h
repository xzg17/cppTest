#include <math.h>
typedef struct{
    int f;//from
    int t;//to
    int p;//piece
    int g;//get
} move;

class TestBoard{
public:
    TestBoard(int bo[13], int hands[6]);
    int push(move mo,);
    int board[12];
    int hands[6];
private:
};
TestBoard(int bo[13], int hands[6]){
    this->board[0] = bo[0];
    this->board[1] = bo[1];
    this->board[2] = bo[2];
    this->board[3] = bo[3];
    this->board[4] = bo[4];
    this->board[5] = bo[5];
    this->board[6] = bo[6];
    this->board[7] = bo[7];
    this->board[8] = bo[8];
    this->board[9] = bo[9];
    this->board[10] = bo[10];
    this->board[11] = bo[11];
    this->board[12] = bo[12];
};
