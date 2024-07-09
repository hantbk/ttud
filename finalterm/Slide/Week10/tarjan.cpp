#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n,m, cnt, res;
vector<int> adj[100009];
int num[100009], low[100009];
stack<int> st;

void tarjan(int u){
    low[u] = num[u] = ++cnt;
    st.push(u);

    for(int v : adj[u]){
        if(num[v]){
            low[u] = min(low[u], num[v]);
        } else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == num[u]){
        res ++;
        int tmp;
        do {
            tmp = st.top();
            st.pop();
            num[tmp] = low[tmp] = INF;
        } while(tmp != u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}