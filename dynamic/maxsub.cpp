/*
    Find the maximum subsequence sum of an array
    Input:  8
            -2 1 -3 4 -1 2 1 -5
    Output: 6
            4 -1 2 1
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, a[MAX], s[MAX], result, minSi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    minSi = 0;
    result = s[1];
    s[1] = a[1] ;
    for (int j = 2; j <= n; j++)
    {
        s[j] = s[j-1] + a[j];
        
        result = max(result, s[j] - minSi);
        minSi = min(minSi, s[j]);
    }

    cout<<result;

    return 0;
}
