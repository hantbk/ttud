#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[1001]; // Danh sách kề
bool visited[1001];    // Đánh dấu đỉnh đã thăm
stack<int> s;

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

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            DFS(v);
    }
}

void DFS_stack(int u)
{
    stack<int> s;
    s.push(u);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            cout << top << " ";
            visited[top] = true;
            for (auto it = adj[top].rbegin(); it != adj[top].rend(); ++it)
            {
                if (!visited[*it])
                {
                    s.push(*it);
                }
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
            DFS(i);
    }
    cout << endl;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS_stack(i);
    }
    cout << endl;

    return 0;
}