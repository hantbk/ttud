#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Treasure
{
    ll x, y;
    ll value;
};

int n;
vector<Treasure> a; // a[i] là kho báu thứ i
vector<ll> f; // f[i] là giá trị lớn nhất có thể nhận được khi chọn kho báu thứ i

bool cmp(Treasure a, Treasure b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

void timkhobau()
{
    sort(a.begin(), a.end(), cmp);
    for(auto it : a)
        cout<<it.x<<" "<<it.y<<" "<<it.value<<endl;

    for (int i = 0; i < n; i++)
    {
        f[i] = a[i].value;
        for (int j = 0; j < i; j++)
        {
            if (a[j].x <= a[i].x && a[j].y <= a[i].y)
            {
                f[i] = max(f[i], f[j] + a[i].value);
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, f[i]);
    }

    // cout << res;
}

int main()
{
    cin >> n;
    a.resize(n);
    f.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].value;

    timkhobau();

    return 0;
}
