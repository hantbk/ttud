#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

ll n;
ll a[MAX];

ll merge(ll left, ll mid, ll right)
{
    vector<ll> x(a + left, a + mid + 1);      // copy nội dung từ a[left, mid] -> vector x
    vector<ll> y(a + mid + 1, a + right + 1); // copy nội dung từ a[mid+1, right] -> vector y
    ll i = 0, j = 0;
    ll cnt = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[left] = x[i];
            left++;
            i++;
        }
        else
        {
            cnt += x.size() - i;
            a[left] = y[j];
            left++;
            j++;
        }
    }
    while (i < x.size())
    {
        a[left] = x[i];
        left++;
        i++;
    }
    while (j < y.size())
    {
        a[left] = y[j];
        left++;
        j++;
    }
    return cnt;
}

ll mergeSort(ll left, ll right)
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