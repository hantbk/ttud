#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

ll n;
ll a[MAX];
ll ta[MAX];

ll merge(ll left, ll mid, ll right)
{
    ll i = left;
    ll j = mid + 1;
    ll count = 0;
    for (ll k = left; k <= right; k++)
    {
        if (i > mid)
        {
            ta[k] = a[j];
            j++;
        }
        else if (j > right)
        {
            ta[k] = a[i];
            i++;
        }
        else
        {
            if (a[i] > a[j])
            {
                count += mid - i + 1;
                ta[k] = a[j];
                j++;
            }
            else
            {
                ta[k] = a[i];
                i++;
            }
        }
    }
    for (ll k = left; k <= right; k++)
        a[k] = ta[k];

    return count;
}

ll mergeSort(int left, int right)
{
    ll dem = 0;
    if (left < right)
    {
        ll mid = (left + right) / 2;
        dem += mergeSort(left, mid);
        dem += mergeSort(mid + 1, right);
        dem += merge(left, mid, right);
    }

    return dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = mergeSort(0, n - 1);
    cout << ans % MOD;

    return 0;
}