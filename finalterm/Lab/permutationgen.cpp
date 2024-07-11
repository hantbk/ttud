#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[10009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = false;

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            int j = n - 1;
            while (a[i] > a[j])
                j--;
            swap(a[i], a[j]);
            sort(a + i + 1, a + n);
            flag = true;
            break;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}