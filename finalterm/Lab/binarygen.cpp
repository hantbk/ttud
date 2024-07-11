#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s[i] = '1';

            for (int j = i + 1; j < n; j++)
            {
                s[j] = '0';
            }
            flag = true;
            break;
        }
    }
    if (flag)
        cout << s << endl;
    else
        cout << -1 << endl;

    return 0;
}