#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

string T, P;
int last[256];

void computeLast(string P)
{
    int m = P.length();
    for (int i = 0; i < 256; i++)
    {
        last[i] = 0;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        if (last[P[i]] == 0)
        {
            last[P[i]] = i;
        }
    }
}

int boyerMoore(string P, string T)
{
    int n = T.length();
    int m = P.length();
    computeLast(P);
    int s = 0;
    int cnt = 0;

    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && P[j] == T[s + j])
        {
            j--;
        }
        if (j < 0)
        {
            cnt++;
            s++;
        }
        else
        {
            int k = last[T[s + j]];
            if (j - k > 1)
            {
                s += j - k;
            }
            else
            {
                s++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> P;
    cout << boyerMoore(P, T);

    return 0;
}