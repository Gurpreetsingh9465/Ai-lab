#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *left, *right, *mid;
    node(int data) {
        this->data = data;
        this->mid = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> iterativeDfs(node *root, int depth) {
    vector<int> res;
    stack<node *> s;
    s.push(root);
    int curDepth = 0;
    while(!s.empty()) {
        int size = s.size();
        while(size--) {
            node * n = s.top();
            s.pop();
            res.push_back(n->data);
            if(n->data > 66) {
                break;
            }
            
            if(n->right != NULL) {
                s.push(n->right);
            }
            if(n->mid != NULL) {
                s.push(n->mid);
            }
            if(n->left != NULL) {
                s.push(n->left);
            }
        }
        if(curDepth>=depth) {
            break;
        }
        curDepth+=1;
    }
    return res;
}



void printVector(vector<int> v) {
    for(auto &i: v) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void generateTree(node *root) {
    if(root->data >= 24) {
        return;
    }
    root->left = new node(3*root->data);
    root->mid = new node(3*root->data+1);
    root->right = new node(3*root->data+2);
    generateTree(root->left);
    generateTree(root->mid);
    generateTree(root->right);
}

int main() {
    node *root = new node(1);
    generateTree(root);
    for(int i = 1;i<=11;i++) {
        cout<<"depth "<<i<<" =: ";
        vector<int> res = iterativeDfs(root,i);
        printVector(res);
    }
    return 0;
}