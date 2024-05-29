#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[1000];

int binary_search(int a[], int left, int right, int x)
{
    if (left > right)
        return 0;
    int mid = (left + right) / 2;
    if (a[mid] == x)
        return mid;
    if (x < a[mid])
        return binary_search(a, left, mid - 1, x);
    else
        return binary_search(a, mid + 1, right, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout<<binary_search(a,0,n-1,x);

    return 0;
}