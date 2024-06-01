#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    list<int> L;
    for(int v = 1; v<= 5; v++) L.push_back(v);
    list<int> ::iterator p;
    p = L.begin();
    advance(p,2); // jump 2 position 
    L.insert(p,2,6); // insert 2 occurrences of 6 after position p
    for(p = L.begin(); p != L.end(); p++) cout<<*p<<" ";

    // vector<int> V;
    // V.push_back(1);
    // V.push_back(2);
    // for(int i = 3; i<=10;i++) V.push_back(i);
    // for(int i = 0; i < V.size(); i++) cout<<V[i]<<" ";
    // cout<<endl;
    // V.erase(V.begin(), V.begin() + 3);
    // for(int i = 0; i < V.size(); i++) cout<<V[i]<<" ";
    // cout<<endl;

    return 0;
}