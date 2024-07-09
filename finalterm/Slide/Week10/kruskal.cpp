#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct edge
{
    int u, v;
    int w;
};

int n, m;
int parent[MAX], _size[MAX];
vector<edge> edges;

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        _size[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (_size[a] < _size[b])
        swap(a, b);
    parent[b] = a;
    _size[a] += _size[b];
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void kruskal()
{
    // Tao cay khung nho nhat
    vector<edge> mst;
    int d = 0;
    sort(edges.begin(), edges.end(), cmp); // Sap xep cac canh theo thu tu tang dan cua trong so
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break;
        edge e = edges[i]; // Lay canh co trong so nho nhat
        if (Union(e.u, e.v))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge e;
        e.u = u;
        e.v = v;
        e.w = w;
        edges.push_back(e);
    }
    make_set();
    kruskal();

    return 0;
}