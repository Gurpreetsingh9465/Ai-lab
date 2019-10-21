#include<bits/stdc++.h>
using namespace std;

// rules.txt file
// 0,0,4,0,
// 0,0,0,3,
// 3,0,0,4,
// 0,3,3,1,
// 3,3,0,1,
// 2,4,1,0,
// 2,0,1,4,

int * getData(char *a, int n) {
    int no = 0;
    int *ans = new int[4];
    int index = 0;
    for(int i=0;i<n;i++) {
        if('0'<=a[i] && a[i]<='9' || a[i] == ',') {
            if(a[i] == ',') {
                ans[index++] = no;
                no = 0;
                continue;
            }
            no = no*10 + (a[i] - '0');
        }
    }
    return ans;
}


int main() {
    ifstream stream("rules.txt");
    map<pair<int,int>, int> sets;
    map<int,list<int>> graph;
    int index = 0;
    while(!stream.eof()) {
        char *a = new char[10];
        stream.getline(a,10);
        int *ans = getData(a,10);
        pair<int,int> p1,p2;
        p1.first = ans[0];
        p1.first = ans[1];
        p2.first = ans[2];
        p2.second = ans[3];
        if(sets.find(p1) == sets.end()) {
            sets.insert({p1,index++});
        }
        if(sets.find(p2) == sets.end()) {
            sets.insert({p2,index++});
        }
        graph[sets[p1]].push_back(sets[p2]);
    }
    for(auto &i: graph) {
        cout<<i.first<<" -> ";
        for(auto &j: i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    stream.close();
    return 0;
}