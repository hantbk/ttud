#include <bits/stdc++.h>
using namespace std;

int n, m, a[1010][1010], result;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int k = 1; k <= m; k++)
    {
        a[0][k] = 0;
    }

    // Complexity: O(n^3)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                a[i][j] += a[i - 1][j];
            }
        }
        int max_area = 0;
        for (int k = 1; k <= m; k++)
        if(a[i][k] > 0)
        {
            int l, r;
            l = r = k;
            while (a[i][l] >= a[i][k])
            {
                l--;
            }
            while (a[i][r] >= a[i][k])
            {
                r++;
            }
            int area = (r - l - 1) * a[i][k];
            max_area = max(area, max_area);
        }
        result = max(max_area, result);
    }
    cout << result;
    return 0;
}