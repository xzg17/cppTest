/*
空:0
歩:1[25]
銀:2[26]
角:3[27]
飛:4[28]
金:5[29]
玉:6
成:+6
偶:11
direction
012
3-4
567(012)
drop:8
合法手生成はひらがなすいしょうとかを参考にした
*/
//viewerでプレイする場合打歩詰反則に対応できないがどう実装するか
//↑周囲に飛車設置で対応できるので打歩詰も実装する。
//lishogiで再生することを前提としよう
//よく考えたらrotateするから純粋な再生は無理かも

#include "CHIKARAWAZA.hpp"

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
    
    int pseudo_moves1(int *moves1);
    int pseudo_moves2(int *moves2);
    int pseudo_moves3(int *moves3);
    int pseudo_moves4(int *moves4);
    //以下使うか怪しいもの
    int moves1[200];//成でない「指す」手。移動先*方向=25*8=200
    int moves2[25];//可成域への成る手。移動先*方向=5*5=25(+200)
    int moves3[60];//非可成域への成る手。移動先*方向=20*3=(+225)
    int moves4[125];//打つ手。移動先*駒種=25*5=125(+285)
private:
};

void TsuiBoard5::direction_N1(int *moves1, int pos){
    if(5 <= pos && this->board[pos - 5] <= 0){
        moves1[8 * pos - 39] = pos;//moves1[8 * (pos - 5) + 1] = pos;
    };
};
void TsuiBoard5::direction_S1(int *moves1, int pos){
    if(pos < 20 && this->board[pos + 5] <= 0){
        moves1[8 * pos + 46] = pos;//moves1[8 * (pos + 5) + 6] = pos;
    };
};
void TsuiBoard5::direction_EW1(int *moves1, int pos){
    if(pos % 5 != 0 && this->board[pos - 1] <= 0){
        moves1[8 * pos - 5] = pos;//moves1[8 * (pos - 1) + 3] = pos;
    };
    if(pos % 5 != 4 && this->board[pos + 1] <= 0){
        moves1[8 * pos + 12] = pos;//moves1[8 * (pos + 1) + 4] = pos;
    };
};
void TsuiBoard5::direction_NEW1(int *moves1, int pos){
    if(5 <= pos && pos % 5 != 0 && this->board[pos - 6] <= 0){
        moves1[8 * pos - 48] = pos;//moves1[8 * (pos - 6) + 0] = pos;
    };
    if(5 <= pos && pos % 5 != 4 && this->board[pos - 4] <= 0){
        moves1[8 * pos - 30] = pos;//moves1[8 * (pos - 4) + 2] = pos;
    };
};
void TsuiBoard5::direction_SEW1(int *moves1, int pos){
    if(pos < 20 && pos % 5 != 0 && this->board[pos + 4] <= 0){
        moves1[8 * pos + 37] = pos;//moves1[8 * (pos + 4) + 5] = pos;
    };
    if(pos < 20 && pos % 5 != 4 && this->board[pos + 6] <= 0){
        moves1[8 * pos + 55] = pos;//moves1[8 * (pos + 6) + 7] = pos;
    };
};
void TsuiBoard5::direction_PR1(int *moves1, int pos){
    int p = pos;
    int illegal = 1;
    while(5 <= p){
        p -= 5;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 1] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    ;}
    p = pos;
    illegal = 1;
    while(p < 20){
        p += 5;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 6] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(p % 5 != 0){
        p -= 1;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 3] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(p % 5 != 0){
        p += 1;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 4] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
};
void TsuiBoard5::direction_PB1(int *moves1, int pos){
    int p = pos;
    int illegal = 1;
    while(5 <= p && p % 5 != 0){
        p -= 6;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(5 <= p && p % 5 != 4){
        p -= 4;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 2] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(p < 20 && p % 5 != 0){
        p += 4;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 5] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(p < 20 && p % 5 != 4){
        p += 6;
        if(this->board[p] > 0){
            break;
        };
        moves1[8 * p + 7] = pos * illegal;
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
};

void TsuiBoard5::direction_N2(int *moves2, int pos){
    if(5 <= pos && pos < 10){//渡すときにこの条件を満たすように実装した方がいいかも
        moves2[5 * pos - 24] = pos;//moves1[5 * (pos - 5) + 1] = pos;
    };
};
void TsuiBoard5::direction_NEW2(int *moves2, int pos){
    if(5 <= pos && pos < 10){
        if(pos != 5){
            moves2[5 * pos - 30] = pos;//moves1[5 * (pos - 6) + 0] = pos;
        };
        if(pos != 9){
            moves2[5 * pos - 18] = pos;//moves1[5 * (pos - 4) + 2] = pos;
        };
    };
};
void TsuiBoard5::direction_EW2(int *moves2, int pos){
    if(pos < 5){
        if(pos != 0){
            moves2[5 * pos - 2] = pos;//moves1[5 * (pos - 1) + 3] = pos;
        };
        if(pos != 4){
            moves2[5 * pos + 9] = pos;//moves1[5 * (pos + 1) + 4] = pos;
        };
    };
};
void TsuiBoard5::direction_PR2(int *moves2, int pos){
    int p = pos;
    int illegal = 1;
    while(5 <= p){
        p -= 5;
        if(this->board[p] > 0){
            break;
        };
        if(p < 5){
            moves2[5 * p + 1] = pos * illegal;
        };
        if(this->board[p] != 0){
            illegal = -1;
        };
    ;}
    p = pos;
    illegal = 1;
    while(p % 5 != 0){
        p -= 1;
        if(this->board[p] > 0){
            break;
        };
        if(p < 5){
            moves2[5 * p + 3] = pos * illegal;
        };
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(p % 5 != 0){
        p += 1;
        if(this->board[p] > 0){
            break;
        };
        if(p < 5){
            moves2[5 * p + 4] = pos * illegal;
        };
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
};
void TsuiBoard5::direction_PB2(int *moves2, int pos){
    int p = pos;
    int illegal = 1;
    while(5 <= p && p % 5 != 0){
        p -= 6;
        if(this->board[p] > 0){
            break;
        };
        if(p < 5){
            moves2[5 * p] = pos * illegal;
        };
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
    p = pos;
    illegal = 1;
    while(5 <= p && p % 5 != 4){
        p -= 4;
        if(this->board[p] > 0){
            break;
        };
        if(p < 5){
            moves2[5 * p + 2] = pos * illegal;
        };
        if(this->board[p] != 0){
            illegal = -1;
        };
    };
};

void TsuiBoard5::direction_S3(int *moves3, int pos){
    if(pos < 5){
        moves3[3 * pos + 16] = pos;//moves1[3 * (pos + 5) + 1] = pos;
    }
};
void TsuiBoard5::direction_SEW3(int *moves3, int pos){
    if(pos < 5){
        if(pos % 5 != 0){
            moves3[3 * pos + 12] = pos;//moves1[3 * (pos + 4) + 0] = pos;
        };
        if(pos % 5 != 4){
            moves3[3 * pos + 20] = pos;//moves1[3 * (pos + 6) + 2] = pos;
        };
    };
};
void TsuiBoard5::direction_PR3(int *moves3, int pos){
    if(pos < 5){
        int p = pos;
        int illegal = 1;
        while(p < 20){
            p += 5;
            if(this->board[p] > 0){
                break;
            };
            moves3[3 * p + 1] = pos * illegal;
            if(this->board[p] != 0){
                illegal = -1;
            };
        };
    };
};
void TsuiBoard5::direction_PB3(int *moves3, int pos){
    if(pos < 5){
        int p = pos;
        int illegal = 1;
        while(p < 20 && p % 5 != 0){
            p += 4;
            if(this->board[p] > 0){
                break;
            };
            moves1[3 * p] = pos * illegal;
            if(this->board[p] != 0){
                illegal = -1;
            };
        };
        p = pos;
        illegal = 1;
        while(p < 20 && p % 5 != 4){
            p += 6;
            if(this->board[p] > 0){
                break;
            };
            moves1[3 * p + 2] = pos * illegal;
            if(this->board[p] != 0){
                illegal = -1;
            };
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
    return CHIKARAWAZA1(this->board, k);
};
int TsuiBoard5::is_close_check(){
    int k = this->kpos[0];
    if(k < 5){
        if(this->board[k - 5] < 0 && this->board[k - 5] != -3){
            return 1;
        };
        if(k % 5 != 0){
            if(this->board[k - 6] <= -5 || this->board[k - 6] == -2 || this->board[k - 6] == -3){
                return 1;
            };
        };
        if(k % 5 != 4){
            if(this->board[k - 4] <= -5 || this->board[k - 4] == -2 || this->board[k - 4] == -3){
                return 1;
            };
        };
    }else if(20 <= k){
        if(this->board[k + 5] <= -4){
            return 1;
        };
        if(k % 5 != 0){
            if(this->board[k + 4] == -10 || this->board[k + 4] == -2 || this->board[k + 4] == -3){
                return 1;
            };
        };
        if(k % 5 != 4){
            if(this->board[k + 6] == -10 || this->board[k + 6] == -2 || this->board[k + 6] == -3){
                return 1;
            };
        };
    }else{
        if(k % 5 != 0){
            if(this->board[k - 1] <= -4){
                return 1;
            };
        };
        if(k % 5 != 4){
            if(this->board[k + 1] <= -4){
                return 1;
            };
        };
    };
    return 0;
};

int TsuiBoard5::pseudo_moves1(int *moves1){
    for(int i = 0;i < 25;i++){
        if(0 < this->board[i]){
            if(this->board[i] != 3){
                this->direction_N1(moves1, i);
            };
            if(this->board[i] == 2 || this->board[i] == 6 || this->board[i] == 10){
                this->direction_NEW1(moves1, i);
                this->direction_SEW1(moves1, i);
            };
            if(5 <= this->board[i]){
                this->direction_NEW1(moves1, i);
                this->direction_EW1(moves1, i);
                this->direction_S1(moves1, i);
            };
            if(this->board[i] == 3 || this->board[i] == 9){
                this->direction_PB1(moves1, i);
            };
            if(this->board[i] == 4 || this->board[i] == 10){
                this->direction_PR1(moves1, i);
            };
        };
    };
    return 1;
};

int TsuiBoard5::pseudo_moves2(int *moves2){
    for(int i = 0;i < 25;i++){
        if(0 < this->board[i] && this->board[i] <= 4){
            if(this->board[i] == 1){
                this->direction_N2(moves2, i);
            };
            if(this->board[i] == 2){
                this->direction_N2(moves2, i);
                this->direction_NEW2(moves2, i);
            };
            if(this->board[i] == 3){
                this->direction_PB2(moves2, i);
            };
            if(this->board[i] == 4){
                this->direction_PR2(moves2, i);
            };
        };
    };
    return 2;
};
int TsuiBoard5::pseudo_moves3(int *moves3){
    for(int i = 0;i < 5;i++){
        if(0 < this->board[i] && this->board[i] <= 4){
            if(this->board[i] == 2){
                this->direction_SEW3(moves3, i);
            };
            if(this->board[i] == 3){
                this->direction_PB3(moves3, i);
            };
            if(this->board[i] == 4){
                this->direction_PR3(moves3, i);
            };
        };
    };
    return 3;
};
int TsuiBoard5::pseudo_moves4(int *moves4){//1~3は移動元を格納したけどどうしよう
    int pcol = -1;
    for(int i = 0;i < 25;i++){
        if(this->board[i] == 1){
            pcol = i % 5;
            break;
        };
    };
    for(int i = 0;i < 25;i++){
        if(this->board[i] <= 0){
            if(this->board[25] > 0){
                if(i % 5 != pcol){
                    moves4[5 * i] = 1;
                };
            };
            if(this->board[26] > 0){
                moves4[5 * i + 1] = 1;
            };
            if(this->board[27] > 0){
                moves4[5 * i + 2] = 1;
            };
            if(this->board[28] > 0){
                moves4[5 * i + 3] = 1;
            };
            if(this->board[29] > 0){
                moves4[5 * i + 4] = 1;
            };
        };
    };
    return 4;
};

int TsuiBoard5::push(int move, int move_from){
    if(move_form < 0){
        this->board[35] -= 1;
        return 0;
    };
    int move_to, p, result, get;
    if(move < 285){
        if(move < 200){
            move_to = move >> 3;
            p = this->board[move_from];
        }else if(move < 225){
            move_to = move / 5;
            p = this->board[move_from];
        }else{
            move_to = move / 3;
            p = this->board[move_from];
        };
        this->board[move_from] = 0;
        get = this->board[move_to];
        this->board[move_to] = p;
        if(this->is_dist_check() || this->is_close_check()){
            this->board[35] -= 1;
            result = 0;
            this->board[move_from] = p;
            this->board[move_to] = get;
        }else{
            //貫通判定未実装
            if(200 <= move){
                this->board[move_to] += 6;
            };
            if(get){
                this->board[get + 24] += 1;
            };
            this->board[37] += 1;
        };
    }else{
        move_to = move / 5;
        p = move % 5 + 1;
        if(this->board[move_to] != 0){
            this->board[35] -= 1;
            result = 0;
        };
    };
    
    return result;
};


TsuiBoard5 TsuiBoard5::pushed(int move, int move_from){
    TsuiBoard5 board;
    board.push(move, move_from);
    return board;
};

int TsuiBoard5::is_end(){
    return this->end;
};
