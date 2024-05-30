#include<bits/stdc++.h>
using namespace std;
#define MAX 1000009
 
int n, L1, L2;
int res;
int a[MAX];
int F[MAX]; // F[i] là tổng số vàng nếu nhà kho i là nhà kho cuối cùng được chọn

void mining() {
    for (int i = 1; i <= n; i++)
    {
        F[i] = a[i]; // Chỉ chọn được 1 kho do kho tiếp theo phải cách ít nhất L1 kho
    }
    for (int i = L1 + 1; i <= n; i++)
    {
        for (int j = i - L2; j <= i - L1; j++)
        {
            F[i] = max(F[i], F[j] + a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, F[i]);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >>n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    mining();
	
	return 0;
}