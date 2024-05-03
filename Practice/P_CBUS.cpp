/*
    There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n).
    There is a bus located at point 0 and has k places for transporting the passengers (it means at any time,
    there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling
    distance from point i to point j (i, j = 0,1,…, 2n).
    Compute the shortest route for the bus, serving n passengers and coming back to point 0.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, k;
int load = 0; // load la so hanh khach tren xe
int cmin = 1000000;
int c[100][100];   // distance matrix
int x[100];        // Mang luu tru duong di
bool visited[100]; // Mang kiem tra da check vi tri
int best = MOD;    // shortest route
int f;             // route hien tai dang di

// Kiem tra xem dinh v co thoa man khong
bool kiemtra(int v)
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
    else if (load + 1 > k)
    {
        return false;
    }
    return true;
}

void updateBest()
{
    if ((f + c[x[2 * n]][0]) < best)
    {
        best = f + c[x[2 * n]][0];
    }
}

void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (kiemtra(v))
        {
            x[k] = v;
            f = f + c[x[k - 1]][x[k]];
            visited[v] = true;

            if (v <= n)
            {
                load++;
            }
            else
            {
                load--;
            }

            if (k == 2 * n)
            {
                updateBest();
            }
            else
            {
                if ((f + (2 * n + 2 - k) * cmin) < best)
                {
                    Try(k + 1);
                }
            }

            if (v <= n)
            {
                load--;
            }
            else
            {
                load++;
            }

            f = f - c[x[k - 1]][x[k]];
            visited[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cmin = min(c[i][j], cmin);
        }
    }
    Try(1);
    cout << best << endl;

    return 0;
}