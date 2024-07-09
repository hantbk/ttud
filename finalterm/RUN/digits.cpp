#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int x[8]; // X[0] = H, X[1] = U, X[2] = S, X[3] = T, X[4] = O, X[5] = I, X[6] = C
bool visited[10];
int cnt = 0;
int n;

void solution()
{
    int hust = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
    int soict = x[2] * 10000 + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3];

    if (hust + soict == n)
        cnt++;
}

bool check(int k, int v)
{
    if (k == 0 && v == 0)
        return false;
    if (k == 2 && v == 0)
        return false;
    if (visited[v])
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 0; v <= 9; v++)
    {
        if (check(k, v))
        {
            x[k] = v;
            visited[v] = true;
            if (k == 6) solution();
            else Try(k + 1);
            visited[v] = false;
        }
    }
}

void solve()
{
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    cnt = 0;
    Try(0);
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
    }

    return 0;
}