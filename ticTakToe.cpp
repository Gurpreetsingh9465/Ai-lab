#include<bits/stdc++.h>
using namespace std;

class Board {
    private:
        char *board;
        char AI;
        char oponent;
    public:
        char getOponent() {
            return oponent;
        }
        char getAi() {
            return AI;
        }
        Board() {}

        Board(char AI) {
            this->AI = AI;
            if(AI == 'X') {
                oponent = 'O';
            } else {
                 oponent = 'X';
            }
            
            this->board = new char[9];
            memset(this->board,'_',sizeof(this->board)+1);
        }

        void displayBoard() {
            system("cls");
            for(int i=0;i<9;i++) {
                if(i%3==0) {
                    cout<<endl;
                }
                cout<<"_"<<board[i]<<a"_";
                if( i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7) {
                    cout<<"|";
                }
            }
        }

        bool isWinning(char val) {
            if(board[0] == val && board[1] == val && board[2] == val) {
                return true;
            } else if(board[3] == val && board[4] == val && board[5] == val) {
                return true;
            } else if(board[6] == val && board[7] == val && board[8] == val) {
                return true;
            } else if(board[0] == val && board[3] == val && board[6] == val) {
                return true;
            } else if(board[1] == val && board[4] == val && board[7] == val) {
                return true;
            } else if(board[2] == val && board[5] == val && board[8] == val) {
                return true;
            } else if(board[0] == val && board[4] == val && board[8] == val) {
                return true;
            } else if(board[2] == val && board[4] == val && board[6] == val) {
                return true;
            }
            return false;
        }
        bool isDraw() {
            for (int i = 0; i < 9; i++) {
                if(board[i] == '_') {
                    return false;
                }
            }
            return true;
        } 

        bool makeMove(int pos, char val) {
            pos = pos - 1;
            if(!(pos>=0 && pos<=8)) {
                return false;
            }
            if(board[pos] == '_') {
                board[pos] = val;
                return true;
            }
            return false;
        }

        bool isValidMove(int i) {
            if(board[i-1] == '_') 
                return true;
            return false;
        }

        void backtrack(int i) {
            board[i-1] = '_';
        }

        // int minimax(bool isAiTurn) {
        //     int move = -1
        //     if (isAiTurn) {
                
        //     } else if (!isAiTurn) {

        //     }
        //     return move;
        // }

        int randomAlgo() {
            if (board[4] == this->oponent) {
                if (board[0] == '_') {
                    return 1;
                }
                if (board[2] == '_') {
                    return 3;
                }
                if (board[6] == '_') {
                    return 7;
                }
                if (board[8] == '_') {
                    return 9;
                }
                
            }
            
            
            if (board[0] ==this->oponent) {
                if (board[1] == '_')
                    return 2;
            }
            if (board[2] ==this->oponent) {
                if (board[0] == '_')
                    return 1;
            }
            if (board[6] ==this->oponent) {
                if (board[8] == '_')
                    return 9;
            }
            if (board[8] ==this->oponent) {
                if (board[5] == '_')
                    return 6;
            }
            if (board[4] == '_') {
                return 5;
            }
            int i = rand()%9+1;
            while (!isValidMove(i)) {
                i = rand()%9+1;
            }
            return i;
        }

        int predictMove() {
            for(int i=1;i<=9;i++) {
                if(makeMove(i,AI)) {
                    if(isWinning(AI) || isDraw()) {
                        backtrack(i);
                        return i;
                    }
                    
                    backtrack(i);
                }
            }
            for(int i=1;i<=9;i++) {
                if(makeMove(i,oponent)) {
                    if(isWinning(oponent)) {
                        backtrack(i);
                        return i;
                    }
                    backtrack(i);
                }
            }
            return randomAlgo();
        }
};

void askMove(Board *b) {
    ask:
        cout<<endl<<"Enter Your Move"<<endl;
        int move;
        cin>>move;
        if (b->isValidMove(move)) {
            b->makeMove(move,b->getOponent());
        } else {
            cout<<"Invalid Move"<<endl;
            goto ask;
        }
}

int main() {
    start:
        cout<<"DO You Want To Play First?Y/N"<<endl;
        char yn;
        cin>>yn;
        Board *b;
        bool isAiTurn;
        if (yn == 'Y' || yn == 'y') {
            b = new Board('O');
            isAiTurn = false;
        } else if (yn == 'N' || yn == 'n') {
            b = new Board('X');
            isAiTurn = true;
        } else {
            cout<<"Wrong Input"<<endl;
            goto start;
        }
        system("cls");
        while (true) {
            if (b->isDraw()) {
                system("cls");
                cout<<"Draw"<<endl;
                break;
            }
            b->displayBoard();
            if (isAiTurn) {
                int move = b->predictMove();
                b->makeMove(move,b->getAi());
                b->displayBoard();
                isAiTurn = false;
            }
            if (b->isWinning(b->getAi())) {
                system("cls");
                cout<<"Ai wins"<<endl;
                break;
            }
            if (b->isDraw()) {
                system("cls");
                cout<<"Draw"<<endl;
                break;
            }
            if (!isAiTurn) {
                askMove(b);
                b->displayBoard();
                isAiTurn = true;
            }
            if (b->isWinning(b->getOponent())) {
                system("cls");
                cout<<"You Win"<<endl;
                break;
            }
            if (b->isDraw()) {
                system("cls");
                cout<<"Draw"<<endl;
                break;
            }
        }
    goto start;
    return 0;
}