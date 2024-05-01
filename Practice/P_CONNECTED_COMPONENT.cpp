/*
    Given a undirected graph G = (V, E), find the number of connected components in the graph.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

int N, M;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int x : adj[u])
    {
        if (!visited[x])
            dfs(x);
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
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

void connectedComponent()
{
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ++ans;
            cout << "Cac dinh thuoc thanh phan lien thong thu " << ans << " :\n";
            // dfs(i);
            bfs(i);
            cout << endl;
        }
    }
    cout << "So thanh phan lien thong cua do thi: " << ans << endl;
    if (ans == 1)
    {
        cout << "Do thi lien thong !" << endl;
    }
    else
    {
        cout << "Do thi khong lien thong !" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connectedComponent();
    return 0;
}