#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char,pair<int,char>> left,pair<char,pair<int,char>> right) {
    return right.second.first < left.second.first;
}



vector<pair<char,pair<int,char>>> aStar(unordered_map<char,vector<pair<char,int>>> &graph, map<char,int> heuristic, char start) {
    vector<pair<char,pair<int,char>>> q;
    vector<pair<char,pair<int,char>>> ans;
    for(auto &i: graph) {
        q.push_back({i.first, {i.first == start?0:INT_MAX,'0'}});
    }
    
    int n = q.size();
    int cur = 0;
    while (q.size() > 0) {
        auto &node = q[0];
        ans.push_back(node);
        q.erase(q.begin());
        for(auto & edge : graph[node.first]) {
            for(auto &a: q) {
                if(a.first == edge.first) {
                    if(a.second.first > (heuristic[a.first]+edge.second+node.second.first)) {
                        a.second.first = heuristic[a.first]+edge.second+node.second.first;
                        a.second.second = node.first;
                    }
                }
            }
            make_heap(q.begin(),q.end(), cmp);
        }
        cur++;
    }
    return ans;
}


int main() {
    map<char,int> heuristic = {
        {'A', 15},
        {'B',13},
        {'C',13},
        {'D',12},
        {'E',11},
        {'F',8},
        {'G',7},
        {'H',6},
        {'I',5},
        {'J',3},
        {'K',2},
        {'Z',0}
    };

    unordered_map<char,vector<pair<char,int>>> graph = {
        {'A',{{'B',1},{'C',2},{'D',2}}},
        {'B',{{'E',3},{'F',4}}},
        {'C',{{'F',4},{'G',3}}},
        {'D',{{'G',3},{'H',3}}},
        {'E',{{'I',3},{'J',6}}},
        {'F',{{'I',6},{'J',6}}},
        {'G',{{'J',7},{'K',8}}},
        {'H',{{'K',8},{'Z',7}}},
        {'I',{{'J',6}}},
        {'J',{{'K',6}}},
        {'K',{{'Z',7}}},
        {'Z',{}},
    };
    for(auto &g: graph) {
        char p = g.first;
        for(auto &i: g.second) {
            pair<char, int> edge = {p, i.second};
            graph[i.first].push_back({edge});
        }
    }
    char start = 'A';
    vector<pair<char,pair<int,char>>> q = aStar(graph, heuristic, start);
    cout<<"Char"<<" "<<"Distance"<<" "<< "Parent"<<endl;
    for(auto &a: q) {
        cout<<setw(4)<<a.first;
        a.second.first == INT_MAX?cout<<setw(8)<<"INF":cout<<setw(8)<<a.second.first;
        cout<<setw(6)<<a.second.second<<endl;
        
    }
    return 0;
}