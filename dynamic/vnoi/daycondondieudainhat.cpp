/*
Cho dãy số A[] gồm n phần tử. Hãy tìm dãy con tăng dài nhất của dãy A[].
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[MAX];
int F[MAX]; // F[i] là độ dài dãy con tăng dài nhất, các phần tử lấy trong miền A[1] -> A[i] và kết thúc tại A[i]

void dp()
{
    for (int i = 1; i <= n; i++)
    {
        F[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            if (a[j] <= a[i])
                F[i] = max(1, F[j] + 1);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, F[i]);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp();

    return 0;
}