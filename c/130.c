#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char** board, int boardRowSize, int boardColSize) {
    int i, j;
    int qi, qj;
    int* queue_i = (int*)malloc(sizeof(int)*2000);
    int* queue_j = (int*)malloc(sizeof(int)*2000);
    
    int head = 0;
    int tail = 0;

    for(i = 0; i <= boardRowSize-1; i ++) {
        for(j = 0; j <= boardColSize-1; j++) {
            if(i == 0 || i == boardRowSize-1 || j == 0 || j == boardColSize-1) {
                if(board[i][j] == 'O') {

                    head = 0;
                    tail = 0;

                    queue_i[head] = i;
                    queue_j[head] = j;

                    board[i][j] = '-';

                    printf("start\n");
    
                    while(tail <= head) {

                        qi = queue_i[tail];
                        qj = queue_j[tail];

                        printf("%d-%d %d-%d\n", tail, head, qi, qj);
                        
                        if(qi+1 <= boardRowSize-1 && board[qi+1][qj] == 'O') {
                            head++;
                            queue_i[head] = qi+1;
                            queue_j[head] = qj;
                            board[qi+1][qj] = '-';
                        }
                        if(qj+1 <= boardColSize-1 && board[qi][qj+1] == 'O') {
                            head++;
                            queue_i[head] = qi;
                            queue_j[head] = qj+1;
                            board[qi][qj+1] = '-';
                        }
                        if(qi-1 >= 0 && board[qi-1][qj] == 'O') {
                            head++;
                            queue_i[head] = qi-1;
                            queue_j[head] = qj;
                            board[qi-1][qj] = '-';
                        }
                        if(qj-1 >= 0 && board[qi][qj-1] == 'O') {
                            head++;
                            queue_i[head] = qi;
                            queue_j[head] = qj-1;
                            board[qi][qj-1] = '-';
                        }
                        
                        tail++;
                    }
                }
            }
        }
    }
    
    for(i = 0; i <= boardRowSize-1; i ++) {
        for(j = 0; j <= boardColSize-1; j++) {
            if(board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }

    for(i = 0; i <= boardRowSize-1; i ++) {
        for(j = 0; j <= boardColSize-1; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int i, j;

    char s1[] = "OOOXXXOO";
    char s2[] = "OOOXXXXO";
    char s3[] = "XXXXOOOO";
    char s4[] = "XOXOOXXX";
    char s5[] = "OXOXXXOO";
    char s6[] = "OXXOOXXO";
    char s7[] = "OXOXXXOO";
    char s8[] = "OXXXXOXX";

    char ** board = (char**)malloc(sizeof(char*)*8);
    board[0] = (char*)s1;
    board[1] = (char*)s2;
    board[2] = (char*)s3;
    board[3] = (char*)s4;
    board[4] = (char*)s5;
    board[5] = (char*)s6;
    board[6] = (char*)s7;
    board[7] = (char*)s8;

    printf("------------------\n");
    for(i = 0; i <= 7; i ++) {
        printf("%s\n", board[i]);
    }

    solve(board, 8, 8);

    printf("------------------\n");
    for(i = 0; i <= 7; i ++) {
        printf("%s\n", board[i]);
    }

    return 0;
}