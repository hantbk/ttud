#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define N 20
#define XMAX 10005

int D[N] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000,
            2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 2000000};
int mem[N + 1][XMAX];

// MinCoin(i, x) is the minimum number of coins needed to make change for amount x using the first i denominations
// MinCoin(i, 0) = 0; MinCoin(i, x) = INF for x < 0; MinCoin(0, x) = INF
int MinCoin(int i, int x)
{
    if (x < 0)
        return INF; // No solution if x is negative
    if (x == 0)
        return 0; // Zero coins needed to make change for 0
    if (i == 0)
        return INF; // No coins to use, so no solution

    if (mem[i][x] != -1)
        return mem[i][x]; // Return already computed result

    int res = INF;
    // Option 1: Include the ith coin and solve for the remaining amount
    if (x >= D[i - 1])
    {
        res = min(res, 1 + MinCoin(i, x - D[i - 1]));
    }
    // Option 2: Exclude the ith coin and solve with remaining coins
    res = min(res, MinCoin(i - 1, x));

    mem[i][x] = res; // Store result in memoization table
    return res;
}

void Trace(int i, int x)
{
    if (x <= 0 || i == 0)
        return;

    if (x >= D[i - 1] && mem[i][x] == 1 + mem[i][x - D[i - 1]])
    {
        cout << D[i - 1] << " ";
        Trace(i, x - D[i - 1]);
    }
    else
    {
        Trace(i - 1, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    memset(mem, -1, sizeof(mem));

    int result = MinCoin(N, x); // Calculate minimum coins needed for amount x using all denominations
    if (result == INF)
    {
        cout << "No solution" << endl; // If result is INF, no solution exists
    }
    else
    {
        cout << result << endl; // Print the minimum number of coins
        Trace(N, x);            // Trace and print the coins used
        cout << endl;
    }

    return 0;
}
