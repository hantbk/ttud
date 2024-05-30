/*
    Cho N và M. Liệt kê tất cả các nghiệm nguyên dương của pt
    X1 + X2 + ... + Xn = M
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, M;
int X[1000];
int T;

int check(int v, int k)
{
    if (k < N)
        return 1;
    return T + v == M;
}

void solution()
{
    for (int i = 1; i <= N; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; v <= M - T - (N - k); v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            T = T + X[k];
            if (k == N)
                solution();
            else Try(k+1);
            T = T - X[k];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    Try(1);

    return 0;
}