#include<bits/stdc++.h>
using namespace std;

void dfsInternal(map<int, list<int>> graph, map<int,bool> &isVisited,int node,vector<int> &result) {
    result.push_back(node);
    isVisited[node] = true;
    list<int> neigbours = graph[node];
    for(int i: neigbours) {
        if(!isVisited[i]) {
            dfsInternal(graph,isVisited,i,result);
        }
    }
}

vector<int> dfs(map<int, list<int>> graph, int startNode) {
    map<int,bool> isVisited;
    for(auto i: graph) {
        pair<int,bool> val;
        val.first = i.first;
        val.second = false;
        isVisited.insert(val);
    }
    vector<int> close;
    dfsInternal(graph, isVisited, startNode, close);
    return close;
}

vector<int> bfs(map<int, list<int>> graph, int startNode) {
    map<int,bool> isVisited;
    for(auto i: graph) {
        pair<int,bool> val;
        val.first = i.first;
        val.second = false;
        isVisited.insert(val);
    }
    queue<int> open;
    vector<int> close;
    open.push(startNode);
    isVisited[startNode] = true;
    while (!open.empty()) {
        int node = open.front();
        open.pop();
        close.push_back(node);
        list<int> neighbours = graph[node];
        for(int i: neighbours) {
            if(!isVisited[i]) {
                open.push(i);
                isVisited[i] = true;
            }
        }
    }
    return close;
}


int main() {
    map<int, list<int>> graph = {
        {1, {2, 3} },
        {2, {1, 4, 5} },
        {3, {1, 6} },
        {4, {2, 5} },
        {5, {2, 4, 6} },
        {6, {5, 7, 8}},
        {7, {4, 6} },
        {8, {6} }
    };
    cout<<"graph is"<<endl;
    for( pair<int, list<int>> i :  graph) {
        cout<<i.first<<" => ";
        for(int j: i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int> result = bfs(graph, 3);
    cout<<"BFS = ";
    for(int i: result) {
        cout<<i<<" ";
    }
    cout<<endl;
    result = dfs(graph, 3);
    cout<<"DFS = ";
    for(int i: result) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}