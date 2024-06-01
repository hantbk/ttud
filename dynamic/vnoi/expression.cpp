/*
Cho n số nguyên. Chia chúng thành 2 nhóm sao cho tích của tổng 2 nhóm là lớn nhất.
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[MAX];
int T;
int L[MAX][MAX]; // L[i][t] = 1 nếu tồn tại dãy con từ 1 đến i có tổng bằng t

void dp(){
    L[0][0] = 1; // Không chọn phần tử nào
    for (int i = 1; i <= n; i++)
    {
        for (int t = 0; t <= T; t++)
        {
            L[i][t] = L[i - 1][t]; // Không chọn phần tử i
            if (t >= a[i])
            {
                L[i][t] = L[i][t] || L[i - 1][t - a[i]]; // Chọn phần tử i
            }
        }
    }
    
    int res = 0;
    for (int t = 1; t <= T; t++)
    {
        if (L[n][t])
        {
            res = max(res, t * (T - t));
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        T += a[i];
    }
    dp();

    return 0;
}