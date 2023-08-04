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
direction
012
3-4
567
drop:8
合法手生成はひらがなすいしょうとかを参考にした
*/
//マジックナンバー？#define？なにそれおいしいの？
//可読性？酸っぱそうな名前だね
//viewerでプレイする場合打歩詰反則に対応できないが同実装するか
//lishogiで再生することを前提としよう
//よく考えたらrotateするから純粋な再生は無理かも
class TsuiBoard5{
public:
    TsuiBoard5();
    void rotate();
    int push(int move, int move_from);//合法1反則0
    TsuiBoard5 pushed(int move, int move_from);
    int is_dist_check();//一マス以上開けての王手判定
    int is_close_check();//隣からの王手判定
    int is_end();
    int board[62];//0~24盤25~34持駒35,36反則37手数
    int kpos[2];
    int end;
    int set(int *in_board);
    void direction_N1(int *moves1, int pos);
    void direction_S1(int *moves1, int pos);
    void direction_EW1(int *moves1, int pos);
    void direction_NEW1(int *moves1, int pos);
    void direction_SEW1(int *moves1, int pos);
    void direction_PR1(int *moves1, int pos);
    void direction_PB1(int *moves1, int pos);

    void direction_N2(int *moves2, int pos);
    void direction_EW2(int *moves2, int pos);
    void direction_NEW2(int *moves2, int pos);
    void direction_PR2(int *moves2, int pos);
    void direction_PB2(int *moves2, int pos);

    void direction_S3(int *moves3, int pos);
    void direction_SEW3(int *moves3, int pos);
    void direction_PR3(int *moves3, int pos);
    void direction_PB3(int *moves3, int pos);
    
    int pseudo_move1(int *move1);
    int pseudo_move2(int *move2);
    int pseudo_move3(int *move3);
    int pseudo_move4(int *move4);
    //以下使うか怪しいもの
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[25];//打つ手。移動先*駒種=25*5=25(+285)
private:
};

void TsuiBoard5::direction_N1(int *moves1, int pos){
    if(5 <= pos){
        moves1[8 * pos - 39] = pos;//moves1[8 * (pos - 5) + 1] = pos;
    };
};
void TsuiBoard5::direction_S1(int *moves1, int pos){
    if(pos < 20){
        moves1[8 * pos + 46] = pos;//moves1[8 * (pos + 5) + 6] = pos;
    };
};
void TsuiBoard5::direction_EW1(int *moves1, int pos){
    if(pos % 5 != 0){
        moves1[8 * pos - 5] = pos;//moves1[8 * (pos - 1) + 3] = pos;
    };
    if(pos % 5 != 4){
        moves1[8 * pos + 12] = pos;//moves1[8 * (pos + 1) + 4] = pos;
    };
};
void TsuiBoard5::direction_NEW1(int *moves1, int pos){
    if(5 <= pos && pos % 5 != 0){
        moves1[8 * pos - 48] = pos;//moves1[8 * (pos - 6) + 0] = pos;
    };
    if(5 <= pos && pos % 5 != 4){
        moves1[8 * pos - 30] = pos;//moves1[8 * (pos - 4) + 2] = pos;
    };
};
void TsuiBoard5::direction_SEW1(int *moves1, int pos){
    if(pos < 20 && pos % 5 != 0){
        moves1[8 * pos + 37] = pos;//moves1[8 * (pos + 4) + 5] = pos;
    };
    if(pos < 20 && pos % 5 != 4){
        moves1[8 * pos + 55] = pos;//moves1[8 * (pos + 6) + 7] = pos;
    };
};
void TsuiBoard5::direction_PR1(int *moves1, int pos){
    int p = pos;
    while(5 <= p){
        p -= 5;
        moves1[p + 1] = pos;
        if(this->board[p] > 0){
            break;
        };
    ;}
    p = pos;
    while(p < 20){
        p += 5;
        moves1[p + 6] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
    p = pos;
    while(p % 5 != 0){
        p -= 1;
        moves1[p + 3] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
    p = pos;
    while(p % 5 != 0){
        p += 1;
        moves1[p + 4] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
};
void TsuiBoard5::direction_PB1(int *moves1, int pos){
    int p = pos;
    while(5 <= p && p % 5 != 0){
        p -= 6;
        moves1[p] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
    p = pos;
    while(5 <= p && p % 5 != 4){
        p -= 4;
        moves1[p + 2] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
    p = pos;
    while(p < 20 && p % 5 != 0){
        p += 4;
        moves1[p + 5] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
    p = pos;
    while(p < 20 && p % 5 != 4){
        p += 6;
        moves1[p + 7] = pos;
        if(this->board[p] > 0){
            break;
        };
    };
};
TsuiBoard5::TsuiBoard5(){
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

    this->kpos[0] = 20;
    this->kpos[1] = 4;
};
void TsuiBoard5::rotate(){
    int _;
    for(int i = 0;i < 12;i++){
        _ = this->board[i];
        this->board[i] = -this->board[24 - i];
        this->board[24 - i] = -_;
    }
    this->board[12] = -this->board[12];
    
    for(int i = 49;i < 54;i++){
        _ = this->board[i];
        this->board[i] = this->board[i + 5];
        this->board[i + 5] = _;
    }
    
    _ = this->board[59];
    this->board[59] = this->board[60];
    this->board[60] = _;
    
    _ = this->kpos[0];
    this->kpos[0] = this->kpos[1];
    this->kpos[1] = _;
};

int TsuiBoard5::is_dist_check(){
    int k = this->kpos[0];
    return 0;
};
int TsuiBoard5::is_close_check(){
    if(this->kpos[0] < 5){
        return 0;
    }else{
        if(this->board[this->kpos[0]] < 0 && this->board[this->kpos[0]] != -3){
            return 1;
        };
        if(1){
            return 0;
        };
    };
};

int TsuiBoard5::pseudo_move1(int *moves1){
    return 1;
};
int TsuiBoard5::push(int move, int move_from){
    int to;
    int dir;
    if(move < 225){
        if(move < 200){
            to = move >> 3;
            dir = move - (to << 3);
        };
    };
    return 1;
};

TsuiBoard5 TsuiBoard5::pushed(int move, int move_from){
    TsuiBoard5 board;
    board.push(move, move_from);
    return board;
};

int TsuiBoard5::is_end(){
    return this->end;
};
