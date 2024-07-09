#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[100009]; // Danh sách kề
bool visited[100009];    // Đánh dấu đỉnh đã thăm
stack<int> s;
vector<pair<int, int>> dscanh;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dscanh.push_back({u, v});
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void articulation()
{
    int ans = 0;
    int tplt = 0; // So thanh phan lien thong cua do thi ban dau
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            tplt++;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // Loai bo dinh i khoi do thi
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int dem = 0; // Dem so thanh phan lien thong sau khi loai bo dinh i
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                dem++;
                dfs(j);
            }
        }
        if (dem > tplt)
            ans++;
    }

    cout << ans << " ";
}

void dfs2(int u, int s, int t)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if ((v == t && u == s) || (v == s && u == t))
            continue;
        if (!visited[v])
        {
            dfs2(v, s, t);
        }
    }
}

void bridge()
{
    int ans = 0;
    int tplt = 0; // So thanh phan lien thong cua do thi ban dau
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            tplt++;
            dfs(i);
        }
    }

    for (auto it : dscanh)
    {
        int x = it.first, y = it.second;
        // Loai bo canh (x,y) khoi do thi
        memset(visited, false, sizeof(visited));
        int dem = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dem++;
                dfs2(i, x, y);
            }
        }
        if (dem > tplt)
            ans++;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    articulation();
    bridge();

    return 0;
}