#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int val;
        vector<Node *> neigh;
        Node() {}
        Node(int val) {
            this->val = val;
        }
};

void beamSearch(vector<Node *> v, int k) {
    queue<Node *> Q;
    Q.push(v[0]);
    Node *temp;
    while(!Q.empty()) {
        temp = Q.front();
        cout<<temp->val<<" ";
        Q.pop();
        for(int i = 0;i<k;i++) {
            if(temp->neigh.size() > i) {
                Q.push(temp->neigh[i]);
            }
        }
    }
    cout<<endl;
}


int main() {
    vector<Node *> V(9);
    for(int i=1;i<=9;i++) {
        V[i-1] = new Node(i);
    }
    for(int i = 1;i<=4;i++) {
        V[0]->neigh.push_back(V[i]); 
    }
    for(int i = 5;i<=8;i++) {
        V[1]->neigh.push_back(V[i]); 
    }
    beamSearch(V,2);
    return 0;
}

