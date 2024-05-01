/*
    Co n thanh pho 1,2,...,n. Giua 2 thanh pho i va j co the co 1 con duong (2 chieu) ket noi giua chung.
    Moi thanh pho i co tuyen buyt i voi c[i] la gia ve moi khi len xe va d[i] la so thanh pho toi da ma
    buyt i co the di den tren 1 hanh trinh di qua cac con duong ket noi
    Ban hay tim hanh trinh di tu thanh pho 1 den thanh pho n sao cho tong gia ve la nho nhat
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 5005
#define ll long long
#define MOD 1000000009

int n, m;
vector<pair<int, int, int>> adj[MAX]; // adj[u] la danh sach ke cua dinh u, moi phan tu la 1 cap (v, c[u], d[u]) voi v la dinh ke cua u, c[u] la gia ve khi len xe tai dinh u, d[u] la so thanh pho toi da ma buyt co the di den tren 1 hanh trinh di qua u
int c[MAX], d[MAX];

void dijkstra(int s, int t)
{
    //Mang cost luu gia ve nho nhat de di den moi dinh
    vector<ll> cost(n + 1, INF);
    vector<bool> visited(n + 1, false);
    cost[s] = 0;
    //Tao hang doi uu tien pq luu cap (cost[v], v) voi cost[v] la gia ve nho nhat de di den v
    priority_queue<pair<int, int, int>, vector<pair<int, int, int>>, greater<pair<int, int, int>>> pq;
    pq.push({0, s, d[s]});
    while (!pq.empty())
    {
        //Lay dinh u co cost[u] nho nhat ra khoi hang doi
        pair<int, int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int cost_u = top.first;
        int d_u = top.third; //So thanh pho toi da ma buyt co the di den tren 1 hanh trinh di qua u
        //Danh dau u da duoc tham
        if(d_u > 0) {
            
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> d[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, c[u], d[u]});
        adj[v].push_back({u, c[v], d[v]});
    }

    dijkstra(1, n);

    return 0;
}