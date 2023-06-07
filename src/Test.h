#include <math.h>
#include "Piece.h"
/*
int chick[14][1]={
    {-1},
    {-1},{-1},{-1},
    {1}, {2}, {3},
    {4}, {5}, {6},
    {7}, {8}, {9},
    {-1}
};
int jiraffe[14][4]={
    {-1,-1,-1,-1},
    {2, 4,-1,-1},{1, 3, 5,-1},{2, 6,-1,-1},
    {1, 5, 7,-1},{2, 4, 6, 8},{3, 5, 9,-1},
    {4, 8, 10,-1},{5, 7, 9,11},{6, 8,12,-1},
    {7,11,-1,-1},{8, 10,12,-1},{9,11,-1,-1},
    {-1,-1,-1,-1}
};
int elephant[14][4]={
    {-1,-1,-1,-1},
    {5,-1,-1,-1},{4, 6,-1,-1},{5,-1,-1,-1},
    {2, 8,-1,-1},{1, 3, 7, 9},{2, 8,-1,-1},
    {5,11,-1,-1},{4, 6, 10,12},{5,11,-1,-1},
    {8,-1,-1,-1},{7, 9,-1,-1},{8,-1,-1,-1},
    {-1,-1,-1,-1}
};
int lion[14][12]={
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12},
    {0, 2, 4, 5,-1,-1,-1,-1,-1,-1,-1,-1},
    {0, 1, 3, 4, 5, 6,-1,-1,-1,-1,-1,-1},
    {0, 2, 5, 6,-1,-1,-1,-1,-1,-1,-1,-1},
    {1, 2, 5, 7, 8,-1,-1,-1,-1,-1,-1,-1},
    {1, 2, 3, 4, 6, 7, 8, 9,-1,-1,-1,-1},
    {2, 3, 5, 8, 9,-1,-1,-1,-1,-1,-1,-1},
    {4, 5, 8, 10,11,-1,-1,-1,-1,-1,-1,-1},
    {4, 5, 6, 7, 9, 10,11,12,-1,-1,-1,-1},
    {5, 6, 8,11,12,-1,-1,-1,-1,-1,-1,-1},
    {7, 8,11,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {7, 8, 9, 10,12,-1,-1,-1,-1,-1,-1,-1},
    {8, 9,11,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};
int hen[14][6]={
    {-1,-1,-1,-1,-1,-1},
    {2, 4,-1,-1,-1,-1},
    {1, 3, 5,-1,-1,-1},
    {2, 6,-1,-1,-1,-1},
    
    {1, 2, 5, 7,-1,-1},
    {1, 2, 3, 4, 6, 8},
    {2, 3, 5, 9,-1,-1},
    
    {4, 5, 8, 10,-1,-1},
    {4, 5, 6, 7, 9,11},
    {5, 6, 8,12,-1,-1},
    
    {7, 8,11,-1,-1,-1},
    {7, 8, 9, 10,12,-1},
    {8, 9,11,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1}
};
//*/
class TestBoard{
public:
    TestBoard(int bo[14], int hands[6]);
    void rotate();
    void push(int move);
    int board[14];
    int hands[6];
    int lost_history[8];//2~7
    int tesu;
private:
};
TestBoard::TestBoard(int bo[14], int hands[6]){
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
    this->hands[0] = hands[0];
    this->hands[1] = hands[1];
    this->hands[2] = hands[2];
    this->hands[3] = hands[3];
    this->hands[4] = hands[4];
    this->hands[5] = hands[5];
};
void TestBoard::rotate(){
    int _;
    _ = this->board[0];
    this->board[0] = -this->board[13];
    this->board[13] = -_;
    _ = this->board[1];
    this->board[1] = -this->board[12];
    this->board[12] = -_;
    _ = this->board[2];
    this->board[2] = -this->board[11];
    this->board[11] = -_;
    _ = this->board[3];
    this->board[3] = -this->board[10];
    this->board[10] = -_;
    _ = this->board[4];
    this->board[4] = -this->board[9];
    this->board[9] = -_;
    _ = this->board[5];
    this->board[5] = -this->board[8];
    this->board[8] = -_;
    _ = this->board[6];
    this->board[6] = -this->board[7];
    this->board[7] = -_;
    _ = this->hands[0];
    this->hands[0] = this->hands[5];
    this->hands[5] = _;
    _ = this->hands[1];
    this->hands[1] = this->hands[4];
    this->hands[4] = _;
    _ = this->hands[2];
    this->hands[2] = this->hands[3];
    this->hands[3] = _;
};
void TestBoard::push(int move){
    int f,t;
    this->tesu+=1;
    f=move / 14;
    t=move % 14;
    if(this->board[t]<0){
        int p=this->board[t];
        this->hands[-p-2]+=1;
        if(this->lost_history[-p]){
            this->lost_history[-p+3]=tesu;
        }else{
            this->lost_history[-p+3]=tesu;
        }
    }
};
