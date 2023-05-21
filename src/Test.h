#include <math.h>
typedef struct{
    int f;//from
    int t;//to
    int p;//piece
    int pro;//progress
    int d;//dir
} move;

class TestBoard{
public:
    TestBoard(int bo[25], int il[2]);
    int push(move mo,);
private:
    int board[25];
    int ills[2];
};
TestBoard::TestBoard(int bo[25], int il[2]){
    this->ills[0] = il[0];
    this->ills[1] = il[1];
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
    this->board[13] = bo[13];
    this->board[14] = bo[14];
    this->board[15] = bo[15];
    this->board[16] = bo[16];
    this->board[17] = bo[17];
    this->board[18] = bo[18];
    this->board[19] = bo[19];
    this->board[20] = bo[20];
    this->board[21] = bo[21];
    this->board[22] = bo[22];
    this->board[23] = bo[23];
    this->board[24] = bo[24];
};
