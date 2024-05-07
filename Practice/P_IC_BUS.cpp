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
queue<pair<int, pair<int, int> > > q; // q lưu trữ tổng số tiền cần phải trả, số thành phố đã đi qua, số trạm còn lại
vector<int> adj[MAX];               // adj[u] lưu trữ các thành phố kề với thành phố u và cách đi giữa chúng
int c[MAX], d[MAX];
int f[MAX][MAX]; // f[u][rem] = cost
int res = MAX;

void minCost()
{
    q.push({ c[1], {1, d[1]}});
    while (!q.empty())
    {
        int cost = q.front().first;
        int u = q.front().second.first;
        int rem = q.front().second.second;
        q.pop();
        if (f[u][rem] > cost || f[u][rem] == -1)
        {
            q.push({ cost + c[u], {u, d[u]}});
            f[u][rem] = cost + c[u];
        }
        if (rem > 0)
        {
            for (int i=0; i< adj[u].size(); ++i)
            {
                int v = adj[u][i];
                if (f[v][rem] > cost || f[v][rem] == -1)
                {
                    q.push({ cost, {v, rem - 1}});
                    f[v][rem] = cost;
                }
            }
        }
        if(u == n) {
            res = min(res, cost);
        }
    }
    cout<<res;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(f, -1, sizeof(f));
    minCost();

    return 0;
}