#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e9 + 18
#define endl "\n"

int n, K;
int load = 0;      // load la so hanh khach tren xe
int d[100][100];   // d la ma tran khoang cach giua cac diem
int x[100];        // x la mang luu tru duong di
int cmin = MOD;    // cmin la do dai duong di ngan nhat giua cac diem
bool visited[100]; // visited la mang danh dau cac diem da di qua
int f;             // f la do dai duong di hien tai
int best = MOD;    // best la do dai duong di ngan nhat

bool check(int v)
{
    if (visited[v])
    {
        return false;
    }
    // Neu v la diem cuoi cung va chua di het cac diem
    if (v > n)
    {
        if (!visited[v - n]) // Neu diem doi dien chua di qua
        {
            return false;
        }
    }
    else if (load + 1 > K)
    {
        return false;
    }
    return true;
}

void updateBest()
{
    if ((f + d[x[2 * n]][0]) < best)
    {
        best = f + d[x[2 * n]][0];
    }
}

void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            x[k] = v;                  // Luu tru duong di
            f = f + d[x[k - 1]][x[k]]; // Cap nhat do dai duong di
            visited[v] = true;         // Danh dau diem da di qua

            if (v <= n) // Neu diem v la diem don
            {
                load++;
            }
            else
            {
                load--;
            }

            if (k == 2 * n)
                updateBest(); // Cap nhat do dai duong di ngan nhat
            else
            {
                if ((f + cmin * (2 * n + 2 - k)) < best)
                {
                    Try(k + 1);
                }
            }

            // Tra lai trang thai ban dau
            if (v <= n)
            {
                load--;
            }
            else
            {
                load++;
            }
            f = f - d[x[k - 1]][x[k]];
            visited[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if (d[i][j] > 0)
            {
                cmin = min(cmin, d[i][j]);
            }
        }
    }

    Try(1);
    cout << best;

    return 0;
}
