#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> allPath(unordered_map<char,vector<pair<float,char>>> &m, char source, char dest) {
  queue<vector<char>> q;
  vector<char> initPath = {source};
  q.push(initPath);
  vector<vector<char>> ans;
  while(!q.empty()) {
    vector<char> path = q.front();
    q.pop();
    int last = path.size()-1;
    vector<pair<float,char>> neigh = m[path[last]];
    if(dest == path[last]) {
      ans.push_back(path);
    }
    for(auto &i: neigh) {
      vector<char> newPath(path);
      newPath.push_back(i.second);
      q.push(newPath);
    }
  }
  return ans;

}

float getProb(unordered_map<char,vector<pair<float,char>>> &m, char source, char dest) {
  vector<pair<float,char>> neigh = m[source];
  for(auto &i: neigh) {
    if(i.second == dest) {
      return i.first;
    }
  }
  return -1;
}

int main() {
    unordered_map<char,vector<pair<float,char>>> m({
      {'A',{{0.3,'B'},{0.4,'C'},{0.5,'D'}}},
      {'B',{{0.6,'E'},{0.7,'F'}}},
      {'C',{{0.6,'F'},{0.4,'G'}}},
      {'D',{{0.6,'G'},{0.9,'H'}}},
      {'E',{{0.7,'F'}}},
      {'F',{{0.5,'G'}}},
      {'G',{{0.3,'H'}}},
      {'H',{}}
    });
    vector<vector<char>> ans = allPath(m,'A','H');
    vector<float> prob;
    for(auto &i: ans) {
      char prev;
      if(i.size() > 0)
        prev = i[0];
      float mul = 1;
      for(int j=1;j<i.size();j++) {
        mul= mul * (getProb(m, prev, i[j]));
        prev = i[j];
      }
      if(mul != 1) {
        prob.push_back(mul);
      }
    }
    float sum = 0;
    for(auto &i: prob) {
      sum+=i;
    }
    for(int i = 0;i<ans.size();i++) {
      for(auto &j: ans[i]) {
        cout<<j<<" ";
      }
      cout<<prob[i]<<endl;
    }
    cout<<"sum is = "<<sum<<endl;
    return 0;
}