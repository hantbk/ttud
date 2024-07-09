/*
    Given a directed graph G = (V, E) in which V = {1, 2, ..., n}. Each arc (i, j) in E has a non-negative weight w[i][j]
    Given two node s and t of G. Find the shortest path from s to t. 
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m, s, t;
vector<pair<int, int>> adj[MAX];
int pre[MAX]; // pre[v] la dinh truoc v tren duong di ngan nhat tu s den v

void dijkstra(int s, int t) {
    // Mang d luu khoang cach ngan nhat tu s den moi dinh
    vector<ll> d(n+1, INF);
    vector<bool> visited(n+1, false);
    d[s] = 0;
    pre[s] = s;
    // Tao hang doi uu tien pq luu cap (d[v], v) voi d[v] la khoang cach ngan nhat tu s den v
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        // Lay dinh u co d[u] nho nhat ra khoi hang doi
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int kc = top.first;
        // if (kc > d[u]) continue;
        // Danh dau u da duoc tham
        if(visited[u]) continue;
        visited[u] = true;
        // Relaxation: Neu co the cap nhat d[v] = d[u] + w[u][v]
        for(auto it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    cout << d[t] << endl;
    // Truy vet de in ra duong di
    vector<int> path;
    while (1)
    {
        path.push_back(t);
        if (t == s) break;
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for(int x: path) cout << x << " ";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s >> t;
    dijkstra(s, t);

    return 0;
}