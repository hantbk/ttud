#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N;
vector<int> adj[1001]; // Danh sách kề
vector<int> c[1001];   // weight of edge
int d[1001];           // distance from the source node to v 
int parent[1001];      // parent of v

void input(){
    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }
}

void bfs(int u){
    queue<int> q;
    d[u] = 0;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0; i < adj[v].size(); i++){
            int x = adj[v][i];
            if(d[x] > -1){
                if(parent[v] != x){
                    cout << "Cycle detected\n";
                    continue;
                }
                int w = c[v][i];
                q.push(x);
                d[x] = d[v] + w;
                parent[x] = v;
            }
        }
    }
}

int findMax(){
    int res = -1;
    int u = -1;
    for(int v = 1; v <= N; v++){
        if(res < d[v]){
            res = d[v];
            u = v;
        }
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    memset(d, -1, sizeof(d));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    int u = findMax();
    memset(d, -1, sizeof(d));
    memset(parent, -1, sizeof(parent));
    bfs(u);
    u = findMax();
    cout << d[u] << endl;

    return 0;
}