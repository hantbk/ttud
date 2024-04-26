#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, e[MAX][MAX]; // Ma tran ke
int b[MAX]; // Mang danh dau
queue<int> q;

void NhapDoThi()
{
    int m, u, v;
    cout << " So dinh = "; cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            e[i][j] = 0;
        }
    }
    
    cout<<" So canh = "; cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cout<<"Canh thu "<<i<<": "; cin>>u>>v;
        e[u][v] = e[v][u] = 1;
    }
    
}

// Duyet theo chieu sau (deep-first search)
void dfs(int k) {
    cout<<"DFS tham dinh "<<k<<endl;
    b[k] = 1;
    for (int i = 1; i <= n; i++)
    {
        if(b[i] == 0 && e[k][i] == 1) {
            dfs(i);
        }
    }
}

// Duyet theo chieu rong (Breadth-first search)
void bfs(int k) {
    for (int i = 1; i <= n; i++)
    {
        b[i] = 0;
    }
    b[k] = 1;
    q.push(k);
    while (!q.empty())
    {
        int c = q.front(); q.pop();
        cout<<"BFS tham dinh "<<c<<endl;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 0 && e[c][i])
            {
                b[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    NhapDoThi();
    dfs(1);
    bfs(1);

    return 0;
}