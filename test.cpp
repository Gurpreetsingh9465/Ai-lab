#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {55};
    vector<int> b(a);
    b.push_back(457);
    for(auto i: b) {
        cout<<i<<endl;
    }
    return 0;
}