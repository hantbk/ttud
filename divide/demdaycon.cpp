/*
    Cho day so a1, a2, ..., an va so S. Dem so day con co tong bang S.
    Giai thuat:
        - F(tong, n) = F(tong, n - 1) + F(tong - a[n], n - 1)
        - F(tong, n) = 1, n = 0, tong = 0
        - F(tong, n) = 0, n = 0, tong != 0
    Input:  5
            1 2 3 4 5
            5
    Output: 3
            1 4
            2 3
            5
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, a[MAX], S;

int F(int tong, int n)
{
    // Tinh so day con co tong bang S
    if (n == 0)
        if (tong == 0)
            return 1;
        else
            return 0;
    else 
        return F(tong, n - 1) + F(tong - a[n], n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Nhap S: ";
    cin >> S;
    cout << "Cac day con co tong bang S la: " << F(S, n) << endl;

    return 0;
}