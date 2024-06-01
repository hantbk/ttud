#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int x[100];
bool visited[100];
int load;
int n, Q;
int dmin = MAX;
int d[100][100];
int f;
int f_best = MAX;

bool check(int v, int k)
{
    if (visited[v])
        return false;
    if (v <= n)
    { // v la diem don
        if (load >= Q)
            return false;
    }
    else
    { // v la diem tra
        if (!visited[v - n])
            return false;
    }
    return true;
}

void updateBest()
{
    if (f + d[x[2 * n]][x[0]] < f_best)
    {
        f_best = f + d[x[2 * n]][x[0]];
        // cout << "update best " << f_best << endl;
    }
}

// Thu tat ca gia tri cho x[k] khi da biet x[0], x[1], ...,x[k-1]
void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = true;
            f = f + d[x[k - 1]][x[k]];
            if (v <= n)
                load += 1;
            else
                load -= 1;
            if (k == 2 * n)
                updateBest();
            else
            {
                if (f + dmin * (2 * n + 1 - k) < f_best)
                    Try(k + 1);
            }
            if (v <= n)
                load -= 1;
            else
                load += 1;
            visited[v] = false;
            f = f - d[x[k - 1]][x[k]];
        }
    }
}

void input()
{
    cin >> n >> Q;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if (i != j && d[i][j] < dmin)
                dmin = d[i][j];
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    for (int v = 0; v <= 2 * n; v++)
        visited[v] = false;
    x[0] = 0;
    Try(1);

    cout << f_best << endl;

    return 0;
}