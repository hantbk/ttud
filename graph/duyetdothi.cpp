#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 1009
#define ll long long
#define MOD 1000000007

int n, e[MAX][MAX]; // Adjacency matrix
int b[MAX]; // Visited array
queue<int> q;

void NhapDoThi()
{
    int m, u, v;
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            e[i][j] = 0;
        }
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        e[u][v] = e[v][u] = 1;
    }
}

// Depth-First Search (DFS)
void dfs(int k) {
    cout << k << " ";
    b[k] = 1;
    for (int i = 1; i <= n; i++)
    {
        if(b[i] == 0 && e[k][i] == 1) {
            dfs(i);
        }
    }
}

// Breadth-First Search (BFS)
void bfs(int k) {
    queue<int> q;
    b[k] = 1;
    q.push(k);

    while (!q.empty())
    {
        int c = q.front(); q.pop();
        cout << c << " ";
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 0 && e[c][i] == 1)
            {
                b[i] = 1;
                q.push(i);
            }
        }
    }
}

void bfs_full() {
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            bfs(i);
        }
    }
    cout << endl;
}

void dfs_full() {
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            dfs(i);
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    NhapDoThi();
    // cout << "BFS Traversal: ";
    // Initialize all nodes as unvisited
    // for (int i = 1; i <= n; i++) {
    //     b[i] = 0;
    // }
    // bfs_full();

    // cout << "DFS Traversal: ";
    // // Initialize all nodes as unvisited
    for (int i = 1; i <= n; i++) {
        b[i] = 0;
    }
    dfs_full();

    return 0;
}
