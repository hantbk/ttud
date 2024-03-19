#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

#define pii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    priority_queue<pii, vector<pii>,greater<pii>> PQ;
    PQ.push(make_pair(4,-10));
    PQ.push(make_pair(1,-10));
    PQ.push(make_pair(9,-900));

    while (!PQ.empty())
    {
        pii e = PQ.top();
        PQ.pop();
        cout<<" pq pop "<< e.first<<","<<e.second<<endl;
    }
    
    return 0;
}
