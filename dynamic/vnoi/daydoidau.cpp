/*
Cho dãy số A[] gồm n phần tử. Hãy tìm dãy con đổi dấu dài nhất của dãy A[].
thoả mãn: ai1 < ai2 > ... < ain hoặc ai1 > ai2 < ... < ain
các chỉ số phải cách nhau ít nhất l: i2 - i1 >= l, i3 - i2 >= l, ...
các phần tử cách nhau không quá u: |ai - aj| <= u

L[i] = max(1, P[j] + 1) với mọi j <= i - l và A[j] < A[i] và A[i] - A[j] <= u
P[i] = max(1, L[j] + 1) với mọi j <= i - l và A[j] > A[i] và A[j] - A[i] <= u
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, l, u;
int a[MAX];
int L[MAX]; // L[i] là số phần tử của dãy con đổi dấu có phần tử cuối cùng là a[i] và phần tử cuối lớn hơn phần tử trước nó
int P[MAX]; // P[i] là số phần tử của dãy con đổi dấu dài nhất kết thúc tại a[i] và có phần tử cuối nhỏ hơn phần tử trước nó

void dp()
{
    for (int i = 1; i <= n; i++)
    {
        L[i] = 1;
        P[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i - j >= l)
            {
                if (a[j] < a[i] && a[i] - a[j] <= u)
                {
                    L[i] = max(1, P[j] + 1);
                }
                if (a[j] > a[i] && a[j] - a[i] <= u)
                {
                    P[i] = max(1, L[j] + 1);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, max(L[i], P[i]));
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> u;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp();

    return 0;
}