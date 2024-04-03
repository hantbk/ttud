#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e9 + 18
#define endl "\n"

int T, N, C;
int x[1000000];

bool isFeasible(int mid, int x[], int N, int C)
{

    // Place the first element at the first position
    int pos = 0;

    // Initialize the number of elements placed
    int elements = 1;

    for (int i = 1; i < N; i++)
    {
        if (x[i] - x[pos] >= mid)
        {
            pos = i;
            elements++;
        }
        if (elements == C)
        {
            return true;
        }
    }
    return false;
}

int largestMinDistance(int x[], int N, int C)
{

    // Sort the array
    sort(x, x + N);

    // Initialize result
    int res = -1;

    // Initialize start and end
    int left = 1, right = x[N - 1];

    // Binary search to find the largest minimum distance
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (isFeasible(mid, x, N, C))
        {
            res = max(res, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N >> C;
        for (int i = 0; i < N; i++)
            cin >> x[i];
        cout << largestMinDistance(x, N, C) << endl;
    }

    return 0;
}
