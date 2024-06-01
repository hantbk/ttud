#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[MAX];
int L1[MAX]; // L1[i] là số phần tử của dãy con tăng dần kể từ phần tử 1 đến a[i]
int L2[MAX]; // L2[i] là số phần tử của dãy con giảm dần kể từ phần tử 1 đến a[i]

void dp()
{
    for (int i = 0; i < n; i++) // LIS tang dan
        for (int j = 0; j < n; j++)
            if (a[i] > a[j])
                L1[i] = max(L1[i], L1[j] + 1);

    for (int i = 0; i < n; i++) // LDS giam dan
        for (int j = 0; j < i; j++)
            if (a[i] < a[j])
                L2[i] = max(L2[i], L2[j] + 1);

    // for (auto x : L1){
    //     if(x != 0)
    //         cout << x << " ";
    // }
    // cout << endl;
    // for (auto x : L2){
    //     if(x != 0)
    //         cout << x << " ";
    // }
    // cout << endl;

    int res = *max_element(L1, L1 + n) + *max_element(L2, L2 + n) - 1;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        L1[i] = 1;
        L2[i] = 1;
    }
    dp();

    return 0;
}
