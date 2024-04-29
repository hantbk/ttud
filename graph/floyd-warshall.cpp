#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, a[MAX][MAX]; // Ma tran trong so cac cung
int b[MAX][MAX];    // Mang luu do dai duong di
bool c[MAX][MAX];   // Mang luu dinh trung gian

void NhapDoThi()
{
    int m, u, v, w;
    cout << " So dinh = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = INF;
        }
    }

    cout << " So canh = ";
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cout << "Canh thu " << i << ": ";
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }
}

// Tim duong di ngan nhat
void xuly()
{
    // gan mang A cho mang B
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
            c[i][j] = j;
        }
    }

    // giam nho cac gia tri cua mang B xuong
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (b[i][j] > b[i][k] + b[k][j])
                {
                    b[i][j] = b[i][k] + b[k][j];
                    c[i][j] = k;
                }
}

void trace(int p, int q)
{
    if (c[p][q] == q)
    {
        cout << " ==> " << q;
    }
    else
    {
        trace(p, c[p][q]);
        trace(c[p][q], p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    NhapDoThi();
    xuly();
    cout << "Duong di min = ";
    trace(0, 5);

    return 0;
}