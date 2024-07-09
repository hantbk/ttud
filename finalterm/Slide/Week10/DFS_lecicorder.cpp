#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[1001]; // Danh sách kề
bool visited[1001];    // Đánh dấu đỉnh đã thăm

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    memset(visited, false, sizeof(visited));
}

void DFS(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]) DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }

    return 0;
}