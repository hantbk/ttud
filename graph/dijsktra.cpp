#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, a[MAX][MAX]; // Ma tran trong so cac cung
int b[MAX];         // Mang luu do dai duong di
bool c[MAX];        // Mang danh dau co dinh hay chua

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

// Tim duong di ngan nhat tu dinh p den dinh q
void xuly(int p, int q)
{
    // Khoi tao
    for (int i = 0; i < n; i++)
    {
        b[i] = INF;
        c[i] = true;
    }
    b[p] = 0; c[p] = false;
    int k = p;

    // Chung nao chua co dinh duoc dinh q thi con tiep tuc
    while (c[q])
    {
        // Giam nho duong di
        for (int i = 0; i < n; i++)
        {
            if (c[i] && (b[i] > b[k] + a[k][i]))
            {
                b[i] = b[k] + a[k][i];
            }
        }

        // Chon dinh co dinh moi
        k = q;
        for (int i = 0; i < n; i++)
        {
            if (c[i] && b[i] < b[k])
            {
                k = i;
            }
        }

        // Co dinh dinh k
        c[k] = false;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    NhapDoThi();
    xuly(0, n - 1);
    cout<<b[n-1];

    return 0;
}