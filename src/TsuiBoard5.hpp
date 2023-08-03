/*
空:0
歩:1
銀:2
角:3
飛:4
金:5
玉:6
合法手生成はひらがなすいしょうとかを参考にした
*/
//マジックナンバー？#define？なにそれおいしいの？
//可読性？酸っぱそうな名前だね
class TsuiBoard5{
public:
    Board();
    void rotate();
    int push(int move);//合法1反則0
    Board pushed(int move);
    int next_player();
    int is_end();
    std::string to_string();
    int board[38];//0~24盤25~34持駒35,36反則37手数
    //以下使うか怪しいもの
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[25];//打つ手。移動先*方向=25*1=25(+285)
private:
};
Board::Board(){
    this->board[0] = -4;
    this->board[1] = -3;
    this->board[2] = -2;
    this->board[3] = -5;
    this->board[4] = -6;
    this->board[5] = 0;
    this->board[6] = 0;
    this->board[7] = 0;
    this->board[8] = 0;
    this->board[9] = -1;
    this->board[10] = 0;
    this->board[11] = 0;
    this->board[12] = 0;
    this->board[13] = 0;
    this->board[14] = 0;
    this->board[15] = 1;
    this->board[16] = 0;
    this->board[17] = 0;
    this->board[18] = 0;
    this->board[19] = 0;
    this->board[20] = 6;
    this->board[21] = 5;
    this->board[22] = 2;
    this->board[23] = 3;
    this->board[24] = 4;
    this->board[25] = 0;
    this->board[26] = 0;
    this->board[27] = 0;
    this->board[28] = 0;
    this->board[29] = 0;
    this->board[30] = 0;
    this->board[31] = 0;
    this->board[32] = 0;
    this->board[33] = 0;
    this->board[34] = 0;
    this->board[35] = 9;
    this->board[36] = 9;
    this->board[37] = 0;
};
void Board::rotate(){
    int _;
    _ = this->board[0];
    this->board[0] = -this->board[24];
    this->board[24] = -_;
    _ = this->board[1];
    this->board[1] = -this->board[23];
    this->board[23] = -_;
    _ = this->board[2];
    this->board[2] = -this->board[22];
    this->board[22] = -_;
    _ = this->board[3];
    this->board[3] = -this->board[21];
    this->board[21] = -_;
    _ = this->board[4];
    this->board[4] = -this->board[20];
    this->board[20] = -_;
    _ = this->board[5];
    this->board[5] = -this->board[19];
    this->board[19] = -_;
    _ = this->board[6];
    this->board[6] = -this->board[18];
    this->board[18] = -_;
    _ = this->board[7];
    this->board[7] = -this->board[17];
    this->board[17] = -_;
    _ = this->board[8];
    this->board[8] = -this->board[16];
    this->board[16] = -_;
    _ = this->board[9];
    this->board[9] = -this->board[15];
    this->board[15] = -_;
    _ = this->board[10];
    this->board[10] = -this->board[14];
    this->board[14] = -_;
    _ = this->board[11];
    this->board[11] = -this->board[13];
    this->board[13] = -_;
    this->board[12] = -this->board[12];
    
    _ = this->board[25];
    this->board[25] = this->board[30];
    this->board[30] = _;
    _ = this->board[26];
    this->board[26] = this->board[31];
    this->board[31] = _;
    _ = this->board[27];
    this->board[27] = this->board[32];
    this->board[32] = _;
    _ = this->board[28];
    this->board[28] = this->board[33];
    this->board[33] = _;
    _ = this->board[29];
    this->board[29] = this->board[34];
    this->board[34] = _;
    _ = this->board[35];
    this->board[35] = this->board[36];
    this->board[36] = _;
};
int Board::push(int move){//入力がpseudo_legalを前提とする。
    int to;
    int dir;
    if(move < 225){
        if(move < 200){
            to = move >> 3;
            dir = move - (to << 3);
        };
    };
};

Board Board::pushed(int move){
    Board board(this->board, this->next);
    board.push(move);
    return board;
};

int Board::is_end(){
    return this->end;
};

int Board::next_player(){
    return this->next;
};
