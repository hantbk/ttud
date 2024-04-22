/*
    Given a sequence of n integers a1, a2, ..., an (1 ≤ n ≤ 105, |ai| ≤ 109).
    A subsequence of a sequence is a sequence that can be derived from the original sequence by deleting some elements without changing the order of the remaining elements.
    A subsequence is called even if the sum of its elements is even
    Find the maximum sum of an even subsequence 
    If there is no even subsequence or odd subsequence, print "NOT_FOUND".
    Input
        The first line contains an integer n (1 ≤ n ≤ 105).
        The second line contains n integers a1, a2, ..., an (|ai| ≤ 109).

    Output
        Print the maximum sum of an even subsequence 
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MAX 1000009
#define ll long long
#define MOD 1000000009

ll n, a[MAX], s[MAX], result, minSi_even, minSi_odd;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    minSi_even = 0;
    minSi_odd = INF;
    result = -INF;
    s[1] = a[1];
    for (int j = 2; j <= n; j++)
    {
        s[j] = s[j - 1] + a[j];
        if (s[j] % 2 == 0)
        {
            result = max(result, s[j] - minSi_even);
            minSi_even = min(minSi_even, s[j]);
        }
        else
        {
            if (minSi_odd == INF)
            {
                minSi_odd = s[j];
            }
            else
            {
                result = max(result, s[j] - minSi_odd);
                minSi_odd = min(minSi_odd, s[j]);
            }
        }
    }
    if (result == -INF)
    {
        cout << "NOT_FOUND";
    }
    else
    {
        cout << result;
    }

    return 0;
}
