#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e9 + 18
#define endl "\n"

ll a[1000000];

// Tron 2 day con: day 1 [L, m], day 2 [m + 1, R]
ll merge(ll a[], ll l, ll m, ll r)
{
    vector<ll> x(a + l, a + m + 1);     // Day con 1
    vector<ll> y(a + m + 1, a + r + 1); // Day con 2
    ll i = 0, j = 0;
    ll count = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            l++;
            i++;
        }
        else
        {
            count += x.size() - i;
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size())
    {
        a[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        l++;
        j++;
    }
    return count;
}

ll mergeSort(ll a[], ll l, ll r)
{
    ll dem = 0;
    if (l < r)
    {
        ll m = (l + r) / 2;
        dem += mergeSort(a, l, m);
        dem += mergeSort(a, m + 1, r);
        dem += merge(a, l, m, r);
    }
    return dem;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll ans =  mergeSort(a, 0, n - 1);
    ans = ans % 1000000007;
    cout<<ans;

    return 0;
}
