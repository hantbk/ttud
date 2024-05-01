/*
    A project has n tasks. Task i has duration d[i] to be completed. 
    There are precedence constraints between tasks represented by a set Q of pairs (i, j):
    (i, j) ∈ Q means task i cannot be started until task j is completed.
    Compute the earliest completion time of the project.
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

int n,m;
int d[1001]; 
vector<int> adj[MAX];
bool visited[MAX];
vector<int> topoSort;

void dfsTopoSort(int u){
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            dfsTopoSort(v);
        }
    }
    topoSort.push_back(u);
}

void makeSpan(){
    int f[1001]; // f[u] is the earliest completion time of task u
    for(int u: topoSort){
        f[u] = d[u];
    }
    for(int u: topoSort){
        for(int v: adj[u]){
            f[v] = max(f[v], f[u] + d[v]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f[i]);
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>d[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));
    
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            dfsTopoSort(i);
        }
    }
    reverse(topoSort.begin(), topoSort.end());
    // for(int u: topoSort){
    //     cout<<u<<" ";
    // }
    
    makeSpan();


    return 0;
}