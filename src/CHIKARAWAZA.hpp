int CHIKARAWAZA1(int *board, int k);

int CHIKARAWAZA1(int *board, int k){
    if(k == 0){
        if(board[1] == 0){
            if(board[2] == -4 || board[2] == -10){
                return 1;
            };
            if(board[2] == 0){
                if(board[3] == -4 || board[3] == -10){
                    return 1;
                };
                if(board[3] == 0){
                    if(board[4] ==  -4 || board[4] == -9){
                        return 1;
                    };
                };
            };
        };
        if(board[6] == 0){
            if(board[12] == -3 || board[12] == -9){
                return 1;
            };
            if(board[12] == 0){
                if(board[18] == -3 || board[18] == -9){
                    return 1;
                }
                if(board[18] == 0){
                    if(board[24] == -3 || board[24] == -9){
                        return 1;
                    };
                };
            };
        };
        if(board[5] == 0){
            if(board[10] == -4 || board[10] == -10){
                return 1;
            };
            if(board[10] == 0){
                if(board[15] == -4 || board[15] == -10){
                    return 1;
                }
                if(board[15] == 0){
                    if(board[20] == -4 || board[20] == -10){
                        return 1;
                    };
                };
            };
        };
    };
    if(k == 1){
        if(board[2] == 0){
            if(board[3] == -4 || board[3] == -10){
                return 1;
            };
            if(board[3] == 0){
                if(board[4] == -4 || board[4] == -10){
                    return 1;
                };
            };
        };
        if(board[7] == 0){
            if(board[13] == -3 || board[13] == -9){
                return 1;
            };
            if(board[13] == 0){
                if(board[19] == -3 || board[19] == -9){
                    return 1;
                };
            };
        };
        if(board[6] == 0){
            if(board[11] == -4 || board[11] == -10){
                return 1;
            };
            if(board[11] == 0){
                if(board[16] == -4 || board[16] == -10){
                    return 1;
                }
                if(board[16] == 0){
                    if(board[21] == -4 || board[21] == -10){
                        return 1;
                    };
                };
            };
        };
    };
    if(k == 2){
        if(board[1] == 0){
            if(board[0] == -4 || board[0] == -10){
                return 1;
            };
        };
        if(board[3] == 0){
            if(board[4] == -4 || board[4] == -10){
                return 1;
            };
        };
        if(board[7] == 0){
            if(board[12] == -4 || board[12] == -10){
                return 1;
            };
            if(board[12] == 0){
                if(board[17] == -4 || board[17] == -10){
                    return 1;
                };
                if(board[17] == 0){
                    if(board[22] == -4 || board[22] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[6] == 0){
            if(board[10] == -3 || board[10] == -9){
                return 1;
            };
        };
        if(board[8] == 0){
            if(board[14] == -3 || board[14] == -9){
                return 1;
            };
        };
    };
    if(k == 3){
        if(board[2] == 0){
            if(board[1] == -4 || board[1] == -10){
                return 1;
            };
            if(board[1] == 0){
                if(board[0] == -4 || board[0] == -10){
                    return 1;
                };
            };
        };
        if(board[8] == 0){
            if(board[13] == -4 || board[13] == -10){
                return 1;
            };
            if(board[13] == 0){
                if(board[18] == -4 || board[18] == -10){
                    return 1;
                };
                if(board[18] == 0){
                    if(board[23] == -4 || board[23] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[7] == 0){
            if(board[11] == -3 || board[11] == -9){
                return 1;
            };
            if(board[11] == 0){
                if(board[15] == -3 || board[15] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 4){
        if(board[3] == 0){
            if(board[2] == -4 || board[2] == -10){
                return 1;
            };
            if(board[2] == 0){
                if(board[1] == -4 || board[1] == -10){
                    return 1;
                };
                if(board[1] == 0){
                    if(board[0] == -4 || board[0] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[8] == 0){
            if(board[12] == -3 || board[12] == -9){
                return 1;
            };
            if(board[12] == 0){
                if(board[16] == -3 || board[16] == -9){
                    return 1;
                };
                if(board[16] == 0){
                    if(board[20] == -3 || board[20] == -9){
                        return 1;
                    };
                };
            };
        };
        if(board[9] == 0){
            if(board[14] == -4 || board[14] == -10){
                return 1;
            };
            if(board[14] == 0){
                if(board[19] == -4 || board[19] == -10){
                    return 1;
                };
                if(board[19] == 0){
                    if(board[24] == -4 || board[24] == -10){
                        return 1;
                    };
                };
            };
        };
    };
    if(k == 5){
        if(board[6] == 0){
            if(board[7] == -4 || board[7] == -10){
                return 1;
            };
            if(board[7] == 0){
                if(board[8] == -4 || board[8] == -10){
                    return 1;
                };
                if(board[8] == 0){
                    if(board[9] == -4 || board[9] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[11] == 0){
            if(board[17] == -3 || board[17] == -9){
                return 1;
            };
            if(board[17] == 0){
                if(board[23] == -3 || board[23] == -9){
                    return 1;
                };
            };
        };
        if(board[10] == 0){
            if(board[15] == -4 || board[15] == -10){
                return 1;
            };
            if(board[15] == 0){
                if(board[20] == -4 || board[20] == -10){
                    return 1;
                };
            };
        };
    };
    if(k == 6){
        if(board[7] == 0){
            if(board[8] == -4 || board[8] == -10){
                return 1;
            };
            if(board[8] == 0){
                if(board[9] == -4 || board[9] == -10){
                    return 1;
                };
            };
        };
        if(board[11] == 0){
            if(board[16] == -4 || board[16] == -10){
                return 1;
            };
            if(board[16] == 0){
                if(board[21] == -4 || board[21] == -10){
                    return 1;
                };
            };
        };
        if(board[12] == 0){
            if(board[18] == -3 || board[18] == -9){
                return 1;
            };
            if(board[18] == 0){
                if(board[24] == -3 || board[24] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 7){
        if(board[6] == 0){
            if(board[5] == -4 || board[5] == -10){
                return 1;
            };
        };
        if(board[8] == 0){
            if(board[9] == -4 || board[9] == -10){
                return 1;
            };
        };
        if(board[12] == 0){
            if(board[17] == -4 || board[17] == -10){
                return 1;
            };
            if(board[17] == 0){
                if(board[24] == -4 || board[24] == -10){
                    return 1;
                };
            };
        };
        if(board[11] == 0){
            if(board[15] == -3 || board[15] == -9){
                return 1;
            };
        };
        if(board[13] == 0){
            if(board[19] == -3 || board[19] == -9){
                return 1;
            };
        };
    };
    if(k == 8){
        if(board[7] == 0){
            if(board[6] == -4 || board[6] == -10){
                return 1;
            };
            if(board[6] == 0){
                if(board[5] == -4 || board[5] == -10){
                    return 1;
                };
            };
        };
        if(board[13] == 0){
            if(board[18] == -4 || board[18] == -10){
                return 1;
            };
            if(board[18] == 0){
                if(board[23] == -4 || board[23] == -10){
                    return 1;
                };
            };
        };
        if(board[12] == 0){
            if(board[16] == -3 || board[16] == -9){
                return 1;
            };
            if(board[16] == 0){
                if(board[20] == -3 || board[20] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 9){
        if(board[8] == 0){
            if(board[7] == -4 || board[7] == -10){
                return 1;
            };
            if(board[7] == 0){
                if(board[6] == -4 || board[6] == -10){
                    return 1;
                };
                if(board[6] == 0){
                    if(board[5] == -4 || board[5] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[14] == 0){
            if(board[19] == -4 || board[19] == -10){
                return 1;
            };
            if(board[19] == 0){
                if(board[24] == -4 || board[24] == -10){
                    return 1;
                };
            };
        };
        if(board[13] == 0){
            if(board[17] == -3 || board[17] == -9){
                return 1;
            };
            if(board[17] == 0){
                if(board[21] == -3 || board[21] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 10){
        if(board[5] == 0){
            if(board[0] == -4 || board[0] == -10){
                return 1;
            };
        };
        if(board[15] == 0){
            if(board[20] == -4 || board[20] == -10){
                return 1;
            };
        };
        if(board[11] == 0){
            if(board[12] == -4 || board[12] == -10){
                return 1;
            };
            if(board[12] == 0){
                if(board[13] == -4 || board[13] == -10){
                    return 1;
                };
                if(board[13] == 0){
                    if(board[14] == -4 || board[14] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[6] == 0){
            if(board[2] == -3 || board[2] == -9){
                return 1;
            };
        };
        if(board[16] == 0){
            if(board[22] == -3 || board[22] == -9){
                return 1;
            };
        };
    };
    if(k == 11){
        if(board[6] == 0){
            if(board[1] == -4 || board[1] == -10){
                return 1;
            };
        };
        if(board[16] == 0){
            if(board[21] == -4 || board[21] == -10){
                return 1;
            };
        };
        if(board[12] == 0){
            if(board[13] == -4 || board[13] == -10){
                return 1;
            };
            if(board[13] == 0){
                if(board[14] == -4 || board[14] == -10){
                    return 1;
                };
            };
        };
        if(board[7] == 0){
            if(board[3] == -3 || board[3] == -9){
                return 1;
            };
        };
        if(board[17] == 0){
            if(board[23] == -3 || board[23] == -9){
                return 1;
            };
        };
    };
    if(k == 12){
        if(board[7] == 0){
            if(board[2] == -4 || board[2] == -10){
                return 1;
            };
        };
        if(board[11] == 0){
            if(board[10] == -4 || board[10] == -10){
                return 1;
            };
        };
        if(board[13] == 0){
            if(board[14] == -4 || board[14] == -10){
                return 1;
            };
        };
        if(board[17] == 0){
            if(board[22] == -4 || board[22] == -10){
                return 1;
            };
        };
        if(board[6] == 0){
            if(board[0] == -3 || board[0] == -9){
                return 1;
            };
        };
        if(board[8] == 0){
            if(board[4] == -3 || board[4] == -9){
                return 1;
            };
        };
        if(board[16] == 0){
            if(board[20] == -3 || board[20] == -9){
                return 1;
            };
        };
        if(board[18] == 0){
            if(board[24] == -3 || board[24] == -9){
                return 1;
            };
        };
    };
    if(k == 13){
        if(board[8] == 0){
            if(board[3] == -4 || board[3] == -10){
                return 1;
            };
        };
        if(board[18] == 0){
            if(board[23] == -4 || board[23] == -10){
                return 1;
            };
        };
        if(board[12] == 0){
            if(board[11] == -4 || board[11] == -10){
                return 1;
            };
            if(board[11] == 0){
                if(board[10] == -4 || board[10] == -10){
                    return 1;
                };
            };
        };
        if(board[7] == 0){
            if(board[1] == -3 || board[1] == -9){
                return 1;
            };
        };
        if(board[17] == 0){
            if(board[21] == -3 || board[21] == -9){
                return 1;
            };
        };
    };
    if(k == 14){
        if(board[9] == 0){
            if(board[4] == -4 || board[4] == -10){
                return 1;
            };
        };
        if(board[19] == 0){
            if(board[24] == -4 || board[24] == -10){
                return 1;
            };
        };
        if(board[13] == 0){
            if(board[12] == -4 || board[12] == -10){
                return 1;
            };
            if(board[12] == 0){
                if(board[11] == -4 || board[11] == -10){
                    return 1;
                };
                if(board[11] == 0){
                    if(board[10] == -4 || board[10] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[8] == 0){
            if(board[2] == -3 || board[2] == -9){
                return 1;
            };
        };
        if(board[18] == 0){
            if(board[22] == -3 || board[22] == -9){
                return 1;
            };
        };
    };
    if(k == 15){
        if(board[16] == 0){
            if(board[17] == -4 || board[17] == -10){
                return 1;
            };
            if(board[17] == 0){
                if(board[18] == -4 || board[18] == -10){
                    return 1;
                };
                if(board[18] == 0){
                    if(board[19] == -4 || board[19] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[10] == 0){
            if(board[5] == -4 || board[5] == -10){
                return 1;
            };
            if(board[5] == 0){
                if(board[0] == -4 || board[0] == -10){
                    return 1;
                };
            };
        };
        if(board[11] == 0){
            if(board[7] == -3 || board[7] == -9){
                return 1;
            };
            if(board[7] == 0){
                if(board[3] == -3 || board[3] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 16){
        if(board[17] == 0){
            if(board[18] == -4 || board[18] == -10){
                return 1;
            };
            if(board[18] == 0){
                if(board[19] == -4 || board[19] == -10){
                    return 1;
                };
            };
        };
        if(board[11] == 0){
            if(board[6] == -4 || board[6] == -10){
                return 1;
            };
            if(board[6] == 0){
                if(board[1] == -4 || board[1] == -10){
                    return 1;
                };
            };
        };
        if(board[12] == 0){
            if(board[8] == -3 || board[8] == -9){
                return 1;
            };
            if(board[8] == 0){
                if(board[4] == -3 || board[4] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 17){
        if(board[16] == 0){
            if(board[15] == -4 || board[15] == -10){
                return 1;
            };
        };
        if(board[18] == 0){
            if(board[19] == -4 || board[19] == -10){
                return 1;
            };
        };
        if(board[12] == 0){
            if(board[7] == -4 || board[7] == -10){
                return 1;
            };
            if(board[7] == 0){
                if(board[2] == -4 || board[2] == -10){
                    return 1;
                };
            };
        };
        if(board[11] == 0){
            if(board[5] == -3 || board[5] == -9){
                return 1;
            };
        };
        if(board[13] == 0){
            if(board[9] == -3 || board[9] == -9){
                return 1;
            };
        };
    };
    if(k == 18){
        if(board[13] == 0){
            if(board[8] == -4 || board[8] == -10){
                return 1;
            };
            if(board[8] == 0){
                if(board[3] == -4 || board[3] == -10){
                    return 1;
                };
            };
        };
        if(board[17] == 0){
            if(board[16] == -4 || board[16] == -10){
                return 1;
            };
            if(board[16] == 0){
                if(board[15] == -4 || board[15] == -10){
                    return 1;
                };
            };
        };
        if(board[12] == 0){
            if(board[6] == -3 || board[6] == -9){
                return 1;
            };
            if(board[6] == 0){
                if(board[0] == -3 || board[0] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 19){
        if(board[18] == 0){
            if(board[17] == -4 || board[17] == -10){
                return 1;
            };
            if(board[17] == 0){
                if(board[16] == -4 || board[16] == -10){
                    return 1;
                };
                if(board[16] == 0){
                    if(board[15] == -4 || board[15] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[14] == 0){
            if(board[9] == -4 || board[9] == -10){
                return 1;
            };
            if(board[9] == 0){
                if(board[4] == -4 || board[4] == -10){
                    return 1;
                };
            };
        };
        if(board[13] == 0){
            if(board[7] == -3 || board[7] == -9){
                return 1;
            };
            if(board[7] == 0){
                if(board[1] == -3 || board[1] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 20){
        if(board[19] == 0){
            if(board[18] == -4 || board[18] == -10){
                return 1;
            };
            if(board[18] == 0){
                if(board[17] == -4 || board[17] == -10){
                    return 1;
                };
                if(board[17] == 0){
                    if(board[16] == -4 || board[16] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[15] == 0){
            if(board[10] == -4 || board[10] == -10){
                return 1;
            };
            if(board[10] == 0){
                if(board[5] == -4 || board[5] == -10){
                    return 1;
                };
                if(board[5] == 0){
                    if(board[0] == -4 || board[0] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[16] == 0){
            if(board[12] == -3 || board[12] == -9){
                return 1;
            };
            if(board[12] == 0){
                if(board[8] == -3 || board[8] == -9){
                    return 1;
                };
                if(board[8] == 0){
                    if(board[4] == -3 || board[4] == -9){
                        return 1;
                    };
                };
            };
        };
    };
    if(k == 21){
        if(board[16] == 0){
            if(board[11] == -4 || board[11] == -10){
                return 1;
            };
            if(board[11] == 0){
                if(board[6] == -4 || board[6] == -10){
                    return 1;
                };
                if(board[6] == 0){
                    if(board[1] == -4 || board[1] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[22] == 0){
            if(board[23] == -4 || board[23] == -10){
                return 1;
            };
            if(board[23] == 0){
                if(board[24] == -4 || board[24] == -10){
                    return 1;
                };
            };
        };
        if(board[17] == 0){
            if(board[13] == -3 || board[13] == -9){
                return 1;
            };
            if(board[13] == 0){
                if(board[9] == -3 || board[9] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 22){
        if(board[21] == 0){
            if(board[20] == -4 || board[20] == -10){
                return 1;
            };
        };
        if(board[23] == 0){
            if(board[24] == -4 || board[24] == -10){
                return 1;
            };
        };
        if(board[17] == 0){
            if(board[12] == -4 || board[12] == -10){
                return 1;
            };
            if(board[12] == 0){
                if(board[7] == -4 || board[7] == -10){
                    return 1;
                };
                if(board[7] == 0){
                    if(board[2] == -4 || board[2] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[18] == 0){
            if(board[14] == -3 || board[14] == -9){
                return 1;
            };
        };
        if(board[16] == 0){
            if(board[10] == -3 || board[10] == -9){
                return 1;
            };
        };
    };
    if(k == 23){
        if(board[18] == 0){
            if(board[13] == -4 || board[13] == -10){
                return 1;
            };
            if(board[13] == 0){
                if(board[8] == -4 || board[8] == -10){
                    return 1;
                };
                if(board[8] == 0){
                    if(board[3] == -4 || board[3] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[22] == 0){
            if(board[21] == -4 || board[21] == -10){
                return 1;
            };
            if(board[21] == 0){
                if(board[20] == -4 || board[20] == -10){
                    return 1;
                };
            };
        };
        if(board[17] == 0){
            if(board[11] == -3 || board[11] == -9){
                return 1;
            };
            if(board[11] == 0){
                if(board[5] == -3 || board[5] == -9){
                    return 1;
                };
            };
        };
    };
    if(k == 24){
        if(board[23] == 0){
            if(board[22] == -4 || board[22] == -10){
                return 1;
            };
            if(board[22] == 0){
                if(board[21] == -4 || board[21] == -10){
                    return 1;
                };
                if(board[21] == 0){
                    if(board[20] == -4 || board[20] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[19] == 0){
            if(board[14] == -4 || board[14] == -10){
                return 1;
            };
            if(board[14] == 0){
                if(board[9] == -4 || board[9] == -10){
                    return 1;
                };
                if(board[9] == 0){
                    if(board[4] == -4 || board[4] == -10){
                        return 1;
                    };
                };
            };
        };
        if(board[18] == 0){
            if(board[12] == -3 || board[21] == -9){
                return 1;
            };
            if(board[21] == 0){
                if(board[6] == -3 || board[6] == -9){
                    return 1;
                };
                if(board[6] == 0){
                    if(board[0] == -3 || board[0] == -9){
                        return 1;
                    };
                };
            };
        };
    };
    return 0;
};
