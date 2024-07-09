#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[1001]; // Danh sách kề
int color[1001];       // Mảng lưu màu của đỉnh

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
    memset(color, -1, sizeof(color));
}

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0; // 0: Red, 1: Blue

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x: adj[v]){
            if(color[x] == -1){
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if(color[x] == color[v]){
                return false;
            }
        }
    }
    return true;
}

bool dfs(int u, int par){
    color[u] = 1 - color[par];
    for(int v: adj[u]){
        if(color[v] == -1){
            if(!dfs(v, u)){
                return false;
            }
        }
        else if(color[v] == color[u]){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    bool check = true;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!bfs(i)){
                check = false;
                break;
            }
        }
    }
    if(check){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}