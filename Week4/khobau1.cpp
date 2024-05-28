#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
pair<pair<ll, ll>, ll> a[100001]; // a[i] là kho báu thứ i
vector<ll> f; // f[i] là giá trị lớn nhất có thể nhận được khi chọn kho báu thứ i

void timkhobau()
{
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        f[i] = a[i].second;

        for(int j = 0; j < i; j++)
        {
            if(a[j].first.first <= a[i].first.first && a[j].first.second <= a[i].first.second)
                f[i] = max(f[i], f[j] + a[i].second);
        }
    }
    

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, f[i]);
    }

    cout << res;
}

int main()
{
    cin >> n;
    f.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;

    timkhobau();

    return 0;
}
