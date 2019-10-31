#include<bits/stdc++.h>
using namespace std;


class Kknight {
    private:
        int m,n;
        long long int count;
        int **board;
    public:
        Kknight(int n,int m) {
            count = 0;
            this->n = n;
            this->m = m;
            this->board = new int*[n];
            for(int i=0;i<n;i++) {
                board[i] = new int[m];
                for(int j=0;j<m;j++) {
                    board[i][j] = 0;
                }
            }
        }
        bool canPlace(int i, int j) {
            if(board[i][j] == 1) {
                return false;
            }
            vector<pair<int,int>> attack = {
                {i+1,j+2},
                {i+2,j+1},
                {i+1,j-2},
                {i+2,j-1},
                {i-1,j+2},
                {i-2,j-1},
                {i-1,j-2},
                {i-2,j+1}
            };
            for(auto &point: attack) {
                if(point.first>=0 && point.first<n && point.second>=0 && point.second < m) {
                    if(board[point.first][point.second] == 1) {
                        return false;
                    }
                }
            }
            return true;
        }

        void run(int k, int i = 0, int j=0) {
            if(k<0) {
                return;
            }
            if(k == 0) {
                count+=1;
                cout<<count<<endl;
                this->printBoard();
            } else {
                for(int sti=i;sti<n;sti++) {
                    for(int stj=j;stj<m;stj++) {
                        if(canPlace(sti,stj)) {
                            board[sti][stj] = 1;
                            run(k-1,sti,stj);
                            board[sti][stj] = 0;
                        }
                    }
                    j = 0;
                }
            }
        }

        void printBoard() {
            for(int i = 0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        int ** getBoard() {
            return board;
        }
};

int main() {
    int n,m,k;
    cout<<"Enter n,m and k"<<endl;
    cin>>n>>m>>k;
    Kknight prog(n,m);
    prog.run(k);
    return 0;
}