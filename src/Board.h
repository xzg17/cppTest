#include <string>

class Board{
public:
    Board(int bo[14]);
    void rotate();
    void push(int move);
    int next_player();
    int is_end();
    std::string to_string();
    int board[14];
    int next;
    int end;//0,1
private:
};
Board::Board(int bo[14]){
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
    this->next=0;
    this->end=0;
};
void Board::rotate(){
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
};
void Board::push(int move){
    int f,t;
    f=move / 14;
    t=move % 14;
    if(this->board[t]==-1){
        this->end=1;
    }
    this->board[t]=this->board[f];
    this->board[f]=0;
    this->next=1-next;
    this->rotate();
};
int Board::is_end(){
    return this->end;
};

int Board::next_player(){
    return this->next;
};

std::string Board::to_string(){
    return 
        " "+std::to_string(this->board[1])+" "+std::to_string(this->board[2])+" "+std::to_string(this->board[3])+"\n"+
        " "+std::to_string(this->board[4])+" "+std::to_string(this->board[5])+" "+std::to_string(this->board[6])+"\n"+
        " "+std::to_string(this->board[7])+" "+std::to_string(this->board[8])+" "+std::to_string(this->board[9])+"\n"+
        " "+std::to_string(this->board[10])+" "+std::to_string(this->board[11])+" "+std::to_string(this->board[12])+"\n";
}
