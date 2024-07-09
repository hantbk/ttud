#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[1001]; // Danh sách kề
bool visited[1001];    // Đánh dấu đỉnh đã thăm
queue<int> q;

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
    memset(visited, false, sizeof(visited));
}

void BFS(int u)
{

    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            BFS(i);
    }

    return 0;
}