#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, K;
vector<int> a;
int cnt = 0; // Declaration and initialization of 'cnt'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    a.resize(N); // Resizing 'a' to size 'N'
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<tuple<int, int, int>> result;

    for (int i = 0; i < N - 2; i++)
    {
        int target = K - a[i];
        int j = i + 1;
        int k = N - 1;

        while (j < k)
        {
            int sum = a[j] + a[k];
            if (sum == target)
            {
                result.push_back({a[i], a[j], a[k]});
                cnt++;
                j++;
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    cout << cnt << endl;
    // Print the result
    for (auto triplet : result)
    {
        cout << "(" << get<0>(triplet) << ", " << get<1>(triplet) << ", " << get<2>(triplet) << ")\n";
    }

    return 0;
}
