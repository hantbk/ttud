#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
vector<int> adj[100009], r_adj[100009]; // Danh sách kề và danh sách kề nghịch đảo
bool visited[100009];
stack<int> st;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        r_adj[v].push_back(u);
    }
}

void DFS1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS1(v);
        }
    }
    st.push(u);
}

void DFS2(int u)
{
    visited[u] = true;
    // cout << u << " ";
    for (int v : r_adj[u])
    {
        if (!visited[v])
        {
            DFS2(v);
        }
    }
}

void SCC()
{
    memset(visited, false, sizeof(visited));
    // Gọi DFS trên đồ thị ban đầu
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            DFS2(u);
            // cout << endl;
            ++cnt;
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    SCC();

    return 0;
}