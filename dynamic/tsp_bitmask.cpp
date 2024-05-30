#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define N 20
int n;
int c[N][N];
int mem[N][1 << N];
int F[N][1 << N]; // F[i][S] is the minimum cost to visit all cities in set S ending at city i

void dp()
{
    // Initialize all values to INF
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            F[i][j] = INF;
        }
    }

    // Starting point: only visit the starting city 0
    F[0][1] = 0;

    // Iterate over all subsets of cities
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            { // If city i is in the current subset
                for (int j = 0; j < n; j++)
                {
                    if ((mask & (1 << j)) == 0)
                    { // If city j is not in the current subset
                        F[j][mask | (1 << j)] = min(F[j][mask | (1 << j)], F[i][mask] + c[i][j]);
                    }
                }
            }
        }
    }

    // Calculate the minimum cost to return to the starting city
    int res = INF;
    for (int i = 1; i < n; i++)
    {
        res = min(res, F[i][(1 << n) - 1] + c[i][0]);
    }

    cout << res << endl;
}

int TSP(int i, int S)
{
    if (S == (1 << n) - 1)
        return c[i][0];
    if (mem[i][S] != -1)
        return mem[i][S];
    int res = INF;
    for (int j = 1; j <= n; j++)
    {
        if (S & (1 << j))
            continue;
        res = min(res, c[i][j] + TSP(j, S | (1 << j)));
    }
    mem[i][S] = res;
    return res;
}

void Trace(int i, int S)
{
    cout << i << " -> ";
    if (S == (1 << n) - 1)
    {
        cout << 0 << endl;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (S & (1 << j))
            continue;
        if (mem[i][S] == c[i][j] + mem[j][S | (1 << j)])
        {
            Trace(j, S | (1 << j));
            return;
        }
    }
}

void IterTrace()
{
    int i = 0, S = 1;
    cout << 0 << " -> ";
    for (int k = 1; k < n; k++)
    {
        for (int j = 1; j < n; j++)
        {
            if (S & (1 << j))
                continue;
            if (mem[i][S] == c[i][j] + mem[j][S | (1 << j)])
            {
                i = j;
                S = S | (1 << j);
                cout << i << " -> ";
                break;
            }
        }
    }
    cout << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    // dp();
    memset(mem, -1, sizeof(mem));
    cout << TSP(0, 1) << endl;
    // Trace(0, 1);
    // IterTrace();

    return 0;
}
