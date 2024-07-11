#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
int a[MAX];
int maxH = 0;

long long count_wood(int height)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > height)
        {
            sum += a[i] - height;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }

    int left = 0;
    int right = maxH;

    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (count_wood(mid) >= m)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout << left;

    return 0;
}