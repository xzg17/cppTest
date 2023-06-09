#include <string>
#include "Piece.h"

class DIDBoard{
public:
    TestBoard(int bo[14], int hands[6]);
    void rotate();
    void push(int move);
    int get_tesu();
    int next_player();
    int pop();
    int is_end();
    std::string to_string();
    int board[14];
    int hands[6];
    int lost_history[8];//2~7
    int tesu;
    int history[200];
    int end;//0,1
private:
};
TestBoard::TestBoard(int bo[14], int hands[6]){
    this->tesu=0;
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
    this->lost_history[0] = 0;
    this->lost_history[1] = 0;
    this->lost_history[2] = 0;
    this->lost_history[3] = 0;
    this->lost_history[4] = 0;
    this->lost_history[5] = 0;
    this->lost_history[6] = 0;
    this->lost_history[7] = 0;
    this->end=0;
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
    this->history[this->tesu]=move;
    f=move / 14;
    t=move % 14;
    if(this->board[t]<0){
        int p=this->board[t];
        if(p+1){
            this->hands[-p-2]+=1;
            if(this->lost_history[-p]){
                this->lost_history[-p+3]=tesu;
            }else{
                this->lost_history[-p]=tesu;
            }
        }else{
            this->end=1;
        }
        
    }
    this->board[t]=this->board[f];
    this->board[f]=0;
    this->rotate();
};
int TestBoard::pop(){
    this->rotate();
    int f,t;
    int move=this->history[this->tesu];
    f=move / 14;
    t=move % 14;
    this->board[f]=this->board[t];
    this->board[t]=0;
    if(this->end){
        this->end=0;
        this->board[t]=-1;
    }else{
        if(this->lost_history[2]==tesu){
            this->board[t]=-2;
            this->lost_history[2]=0;
        }
        if(this->lost_history[3]==tesu){
            this->board[t]=-3;
            this->lost_history[3]=0;
        }
        if(this->lost_history[4]==tesu){
            this->board[t]=-4;
            this->lost_history[4]=0;
        }
        if(this->lost_history[5]==tesu){
            this->board[t]=-2;
            this->lost_history[5]=0;
        }
        if(this->lost_history[6]==tesu){
            this->board[t]=-3;
            this->lost_history[6]=0;
        }
        if(this->lost_history[7]==tesu){
            this->board[t]=-4;
            this->lost_history[7]=0;
        }
    };
    this->tesu-=1;
    return move;
}

int TestBoard::is_end(){
    return this->end;
};

int TestBoard::get_tesu(){
    return this->tesu;
};

int TestBoard::next_player(){
    return this->tesu % 2;
};

std::string TestBoard::to_string(){
    return 
        " "+std::to_string(this->board[1])+" "+std::to_string(this->board[2])+" "+std::to_string(this->board[3])+"\n"+
        " "+std::to_string(this->board[4])+" "+std::to_string(this->board[5])+" "+std::to_string(this->board[6])+"\n"+
        " "+std::to_string(this->board[7])+" "+std::to_string(this->board[8])+" "+std::to_string(this->board[9])+"\n"+
        " "+std::to_string(this->board[10])+" "+std::to_string(this->board[11])+" "+std::to_string(this->board[12])+"\n";
}
