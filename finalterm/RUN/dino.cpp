#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
stack<int> s;
queue<int> q;
int a[100009];
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        s.push(a[i]);

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'C')
        {
            if (!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
        }
        else if (str[i] == 'H')
        {
            if (!q.empty())
            {
                s.push(q.front());
                q.pop();
            }
        }
    }

    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}