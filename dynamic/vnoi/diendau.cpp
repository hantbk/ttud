#include <bits/stdc++.h>
using namespace std;
#define MAXN 100 // Adjust this based on problem constraints
#define OFFSET 10000 // Adjust this based on the maximum possible absolute value of S

int n, S;
int a[MAXN];
bool L[MAXN][2 * OFFSET + 1]; // L[i][t + OFFSET] = true if we can obtain sum t using the first i elements

void dp()
{
    memset(L, 0, sizeof(L)); // Initialize all values to false
    L[0][OFFSET] = true; // Initial condition: sum of 0 using 0 elements
    
    for (int i = 1; i <= n; i++)
    {
        for (int t = -OFFSET; t <= OFFSET; t++)
        {
            if (t - a[i] + OFFSET >= 0 && t - a[i] + OFFSET <= 2 * OFFSET)
                L[i][t + OFFSET] = L[i][t + OFFSET] || L[i-1][t - a[i] + OFFSET];
            if (t + a[i] + OFFSET >= 0 && t + a[i] + OFFSET <= 2 * OFFSET)
                L[i][t + OFFSET] = L[i][t + OFFSET] || L[i-1][t + a[i] + OFFSET];
        }
    }
    
    if (S + OFFSET >= 0 && S + OFFSET <= 2 * OFFSET && L[n][S + OFFSET])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp();

    return 0;
}
