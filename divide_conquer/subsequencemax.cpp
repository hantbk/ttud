/*
    Bài toán dãy con dài nhất: cho dãy số nguyên a = a1,
    a2, …, an. Tìm dãy con gồm một số liên tiếp các phần
    tử có tổng lớn nhất
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000];

int MaxLeftMid(int i, int m)
{
    int ans = a[m], sum = 0;
    for (int k = m; k >= i; k--)
    {
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRightMid(int m, int j)
{
    int ans = a[m], sum = 0;
    for (int k = m; k <= j; k++)
    {
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int SubSeqMax(int i, int j)
{
    if (i == j)
        return a[i];
    int m = (i + j) / 2;
    int wLeft = SubSeqMax(i, m);
    int wRight = SubSeqMax(m + 1, j);

    int wLeftMax = MaxLeftMid(i, m);
    int wRightMax = MaxRightMid(m + 1, j);
    int wMax = wLeftMax + wRightMax;

    return max(max(wLeft,wRight),wMax);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout<<SubSeqMax(0,n-1);

    return 0;
}