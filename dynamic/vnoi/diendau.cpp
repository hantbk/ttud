/*
Cho n số tự nhiên a1, a2, ..., an.Ban đầu các số được đặt liên tiếp theo đúng thứ tự
cách nhau bởi dấu "?" (ví dụ: a1?a2?a3?...?an). Cho trước số S, có cách nào
thay các dấu "?" bằng dấu "+" hoặc "-" sao cho kết quả bằng S không?
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, S;
int a[MAX];
int L[MAX][MAX]; // L[i][t] = 1 nếu có thể điền dấu vào i số đầu tiên và cho kết quả bằng t

void dp()
{
    L[1][a[1]] = 1;
    L[1][-a[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int t = 0; t <= S; t++)
        {
            if(L[i-1][t + a[i]] || L[i-1][t - a[i]]){ // Nếu có thể điền dấu vào i-1 số đầu tiên và cho kết quả bằng t + a[i] hoặc t - a[i]
                L[i][t] = 1;
            }
        }
    }
    if(L[n][S]){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp();

    return 0;
}