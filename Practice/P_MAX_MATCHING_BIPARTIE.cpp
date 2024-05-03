/*
    Given a bipartite graph, find the maximum matching.
    The Hopcroft-Karp algorithm is used to solve this problem.
    Time complexity: O(sqrt(V) * E)
    Space complexity: O(V + E)
    where V is the number of vertices and E is the number of edges.
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 1000009;

int n, m;
vector<int> match; // match[u] = v, match[v] = u
vector<int> dist;  // dist[u] = distance from u to 0
vector<int> Q;

bool dfs(int u, vector<vector<int>> &adj)
{
    if (u == 0)
        return true;
    for (int v : adj[u])
    {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v], adj))
        {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

void hopcroft_karp(vector<vector<int>> &adj)
{
    int res = 0;
    while (1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (match[i] == 0)
            {
                dist[i] = 0;
                Q.push_back(i);
            }
            else
            {
                dist[i] = INF;
            }
        }
        dist[0] = INF;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.erase(Q.begin());
            if (u != 0)
            {
                for (int v : adj[u])
                {
                    if (dist[match[v]] == INF)
                    {
                        dist[match[v]] = dist[u] + 1;
                        Q.push_back(match[v]);
                    }
                }
            }
        }
        if (dist[0] == INF)
            break;
        for (int i = 1; i <= n; i++)
        {
            if (match[i] == 0 && dfs(i, adj))
            {
                res++;
            }
        }
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    match.assign(n + m + 1, 0);
    dist.assign(n + m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(n + x);
        }
    }

    hopcroft_karp(adj);

    return 0;
}
