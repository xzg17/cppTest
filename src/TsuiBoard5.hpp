/*
空:0
歩:1
銀:2
角:3
飛:4
金:5
玉:6
成:+6
偶:11
合法手生成はひらがなすいしょうとかを参考にした
*/
//マジックナンバー？#define？なにそれおいしいの？
//可読性？酸っぱそうな名前だね
//viewerでプレイする場合打歩詰反則に対応できないが同実装するか
//lishogiで再生することを前提としよう
//よく考えたらrotateするから純粋な再生は無理かも
class TsuiBoard5{
public:
    Board();
    void rotate();
    int push(int move);//合法1反則0
    Board pushed(int move);
    int is_dist_check();//一マス以上開けての王手判定
    int is_close_check();//隣からの王手判定
    int is_end();
    std::string to_string();
    int board[62];//0~48盤49~58持駒59,60反則61手数
    int kpos[2];
    int end;
    //以下使うか怪しいもの
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[25];//打つ手。移動先*方向=25*1=25(+285)
private:
};
Board::Board(){
    this->board[0] = 11;
    this->board[1] = 11;
    this->board[2] = 11;
    this->board[3] = 11;
    this->board[4] = 11;
    this->board[5] = 11;
    this->board[6] = 11;
    this->board[7] = 11;
    this->board[8] = -4;
    this->board[9] = -3;
    this->board[10] = -2;
    this->board[11] = -5;
    this->board[12] = -6;
    this->board[13] = 11;
    this->board[14] = 11;
    this->board[15] = 0;
    this->board[16] = 0;
    this->board[17] = 0;
    this->board[18] = 0;
    this->board[19] = -1;
    this->board[20] = 11;
    this->board[21] = 11;
    this->board[22] = 0;
    this->board[23] = 0;
    this->board[24] = 0;
    this->board[25] = 0;
    this->board[26] = 0;
    this->board[27] = 11;
    this->board[28] = 11;
    this->board[29] = 1;
    this->board[30] = 0;
    this->board[31] = 0;
    this->board[32] = 0;
    this->board[33] = 0;
    this->board[34] = 11;
    this->board[35] = 11;
    this->board[36] = 6;
    this->board[37] = 5;
    this->board[38] = 2;
    this->board[39] = 3;
    this->board[40] = 4;
    this->board[41] = 11;
    this->board[42] = 11;
    this->board[43] = 11;
    this->board[44] = 11;
    this->board[45] = 11;
    this->board[46] = 11;
    this->board[47] = 11;
    this->board[48] = 11;
    this->board[49] = 0;
    this->board[50] = 0;
    this->board[51] = 0;
    this->board[52] = 0;
    this->board[53] = 0;
    this->board[54] = 0;
    this->board[55] = 0;
    this->board[56] = 0;
    this->board[57] = 0;
    this->board[58] = 0;
    this->board[59] = 9;
    this->board[60] = 9;
    this->board[61] = 0;

    this->kpos[0] = 36;
    this->kpos[1] = 12;
};
void Board::rotate(){
    int _;
    _ = this->board[0];
    this->board[0] = -this->board[48];
    this->board[48] = -_;
    _ = this->board[1];
    this->board[1] = -this->board[47];
    this->board[47] = -_;
    _ = this->board[2];
    this->board[2] = -this->board[46];
    this->board[46] = -_;
    _ = this->board[3];
    this->board[3] = -this->board[45];
    this->board[45] = -_;
    _ = this->board[4];
    this->board[4] = -this->board[44];
    this->board[44] = -_;
    _ = this->board[5];
    this->board[5] = -this->board[43];
    this->board[43] = -_;
    _ = this->board[6];
    this->board[6] = -this->board[42];
    this->board[42] = -_;
    _ = this->board[7];
    this->board[7] = -this->board[41];
    this->board[41] = -_;
    _ = this->board[8];
    this->board[8] = -this->board[40];
    this->board[40] = -_;
    _ = this->board[9];
    this->board[9] = -this->board[39];
    this->board[39] = -_;
    _ = this->board[10];
    this->board[10] = -this->board[38];
    this->board[38] = -_;
    _ = this->board[11];
    this->board[11] = -this->board[37];
    this->board[37] = -_;
    _ = this->board[12];
    this->board[12] = -this->board[36];
    this->board[36] = -_;
    _ = this->board[13];
    this->board[13] = -this->board[35];
    this->board[35] = -_;
    _ = this->board[14];
    this->board[14] = -this->board[34];
    this->board[34] = -_;
    _ = this->board[15];
    this->board[15] = -this->board[33];
    this->board[33] = -_;
    _ = this->board[16];
    this->board[16] = -this->board[32];
    this->board[32] = -_;
    _ = this->board[17];
    this->board[17] = -this->board[31];
    this->board[31] = -_;
    _ = this->board[18];
    this->board[18] = -this->board[30];
    this->board[30] = -_;
    _ = this->board[19];
    this->board[19] = -this->board[29];
    this->board[29] = -_;
    _ = this->board[20];
    this->board[20] = -this->board[28];
    this->board[28] = -_;
    _ = this->board[21];
    this->board[21] = -this->board[27];
    this->board[27] = -_;
    _ = this->board[22];
    this->board[22] = -this->board[26];
    this->board[26] = -_;
    _ = this->board[23];
    this->board[23] = -this->board[25];
    this->board[25] = -_;
    this->board[24] = -this->board[24];
    
    _ = this->board[49];
    this->board[49] = this->board[54];
    this->board[54] = _;
    _ = this->board[50];
    this->board[50] = this->board[55];
    this->board[55] = _;
    _ = this->board[51];
    this->board[51] = this->board[56];
    this->board[56] = _;
    _ = this->board[52];
    this->board[52] = this->board[57];
    this->board[57] = _;
    _ = this->board[53];
    this->board[53] = this->board[58];
    this->board[58] = _;
    
    _ = this->board[59];
    this->board[59] = this->board[60];
    this->board[60] = _;
    
    _ = this->kpos[0];
    this->kpos[0] = this->kpos[1];
    this->kpos[1] = _;
};

int Board::is_dist_check(){
    kpos;
};
int is_close_check(){
    if(this->kpos[0] < 5){
        return -1
    }else{
        if(this->board[this->kpos[0]] < 0 && this->board[this->kpos[0]] != -3){
            return 1;
        };
        if()
    };
    
};//隣からの王手判定
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
