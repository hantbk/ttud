/*
    Cho so nguyen duong k
    Tim so cach chia k thanh tong it nhat 2 so nguyen duong doi mot khac nhau
    f(k,n) la so cach phan tich k thanh tong cac so khong vuot qua n
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int k;

// int f(int k, int n)
// {
//     if (n == 1)
//     {
//         if (k == 1)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     if (k == 0)
//     {
//         return 1;
//     }
//     if (k < n)
//     {
//         return f(k, k);
//     }
//     return f(k, n - 1) + f(k - n, n - 1);
// }

int f(int k, int n)
{
    if (n == 1)
    {
        if (k == 1)
        {
            return 1;
        }
        return 0;
    }
    int h = k - n;
    if (h == 0)
        return f(k, n - 1) + 1;
    else if (h < n)
        return f(k, n - 1) + f(h, h);
    return f(k, n - 1) + f(h, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cout << "So cach chia " << k << " thanh tong it nhat 2 so nguyen duong doi mot khac nhau la: " << f(k, k) - 1 << "\n";

    return 0;
}