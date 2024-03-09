#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000][1000], result;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; i++)
        {
            cin >> a[i][j];
        }
    }
    
    for (int k = 1; k <= m; k++)
    {
        a[0][k] = 0;
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                a[i][j] +=a[i-1][j];
            }
        }
        int max_area = 0;
        for (int k = 1; k <= m; k++)
        {
            int l,r;
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