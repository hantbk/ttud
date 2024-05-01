/*
    There are n passengers 1,2,...,n. The passenger i want to travel from point i to point i+n
    There is a taxi located at point 0 for transporting passengers. Given the distance matrix of the points,
    Compute the shortest route for the taxi, serving n passengers and returning to point 0.
    At any moment, there is no more than one passenger in the taxi, and no point is visited more than once.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n;
int c[24][24];    // c[i][j] is the distance from point i to point j
int x[24];        // x[i] is the point i in the route
bool visited[24]; // visited[i] is true if point i is visited
int load = 0;     // load is the number of passengers in the taxi
int f;            // f is the current distance of the route
int best = INF;   // best is the shortest distance of the route
int cmin = INF;   // cmin is the minimum distance from point i to any other point

bool check(int v)
{
    if (visited[v])
    {
        return false;
    }
    // Neu v la diem cuoi cung va chua di het cac diem
    if (v > n)
    {
        if (!visited[v - n]) // Neu diem doi dien chua di qua
        {
            return false;
        }
    }
    else if (load + 1 > 1)
    {
        return false;
    }
    return true;
}

void updateBest()
{
    if (f + c[x[2 * n]][0] < best)
    {
        best = f + c[x[2 * n]][0];
    }
}

void Try(int k)
{
    if (f >= best)
    {
        return;
    }

    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            visited[v] = true;
            x[k] = v;
            f = f + c[x[k - 1]][x[k]];

            if (v <= n)
                load++;
            else
                load--;

            if (k == 2 * n)
                updateBest();
            else
            {
                if (f + (2 * n + 1) * cmin < best)
                    Try(k + 1);
            }

            // Tra lai gia tri ban dau
            visited[v] = false;
            if (v <= n)
                load--;
            else
                load++;
            f = f - c[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    Try(1);
    cout << best;

    return 0;
}