/*
Cho hàm P: {0, 1, ..., n-1} -> {TRUE, FALSE} thoả mãn nếu P(i) = TRUE thì P(j) = TRUE
với mọi j > i
Yêu cầu tìm chỉ số j nhỏ nhất sao cho P(j) = TRUE
*/

#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[1000];

bool P(int i)
{
    return a[i] >= x;
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int low = 0, hight = n - 1;
    while (low < hight)
    {
        int mid = (low + hight) / 2;
        if (P(mid))
        {
            hight = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (low == hight && P(low))
    {
        cout << "The minimum index where " << x << " can be found is " << low << endl;
    }
    else
    {
        cout << "Cannot find " << x << endl;
    }

    return 0;
}
