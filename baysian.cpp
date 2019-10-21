#include<bits/stdc++.h>
using namespace std;

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
    
    return 0;
}