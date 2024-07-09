#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int a[100005];
int M[22][100005]; // M[i][j] là chỉ số của phần tử nhỏ nhất của dãy con bắt đầu từ a[j] và có 2^i phần tử
int n;
int sum;

void preprocessing()
{
    for (int j = 0; j < n; j++)
        M[0][j] = j;

    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
        {
            if (a[M[i - 1][j]] < a[M[i - 1][j + (1 << (i - 1))]])
                M[i][j] = M[i - 1][j];
            else
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
        }
    }
}

void rmq(int L, int R)
{
    int k = log2(R - L + 1);
    if (a[M[k][L]] < a[M[k][R - (1 << k) + 1]])
        sum += a[M[k][L]];
    else
        sum += a[M[k][R - (1 << k) + 1]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    preprocessing();
    int q;
    cin >> q;
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        rmq(L, R);
    }
    cout << sum << endl;

    return 0;
}