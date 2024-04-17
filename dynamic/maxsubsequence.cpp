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

int n, a[MAX], s[MAX], result = INT_MIN, endPoint, startPoint;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    s[1] = a[1];
    for (int k = 2; k <= n; k++) {
        s[k] = max(a[k], s[k - 1] + a[k]);
    }

    for (int i = 1; i <= n; i++) {
        if (result <= s[i]) {
            result = s[i];
            endPoint = i;
        }
    }
    cout << result << endl;
    // for (int i = endPoint, sum = result; i >= 1; i--) {
    //     cout << a[i] << " ";
    //     sum -= a[i];
    //     if (sum == 0) break;
    // }

    // Find the start point
    startPoint = endPoint;
    while (result != 0) {
        result -= a[startPoint];
        startPoint--;
    }

    // Print the subsequence
    for (int i = startPoint + 1; i <= endPoint; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
