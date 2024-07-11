#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009
#define pii pair<int, int>

// Level is number of steps to (X, Y) state
map<pii, int> level;
// queue to maintain the states
queue<pii> q;

// Changing state of jugs from (u1, u2) to (a, b)
void Pour(int a, int b, pii u)
{
    // If this state is not visited yet
    if (level[{a, b}] == 0)
    {
        q.push({a, b});
        level[{a, b}] = level[{u.first, u.second}] + 1;
    }
}

void BFS(int a, int b, int target)
{
    // Map is used to check if the state is visited or not
    bool isSolvable = false;
    level.clear();
    q = queue<pii>();

    q.push({0, 0});
    level[{0, 0}] = 1;

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        if (u.first == target || u.second == target)
        {
            isSolvable = true;
            cout << level[{u.first, u.second}] - 1 << endl;
            break;
        }

        Pour(u.first, b, u);  // Fill Jug 1
        Pour(a, u.second, u); // Fill Jug 2
        Pour(u.first, 0, u);  // Empty Jug 1
        Pour(0, u.second, u); // Empty Jug 2

        for (int ap = 0; ap <= max(a, b); ap++)
        {
            // Pour from Jug 2 to Jug 1
            int c = u.first + ap;
            int d = u.second - ap;
            // Check if this state is possible or not
            if ((c == a && d >= 0) || (d == 0 && c <= a))
                Pour(c, d, u);
            // Pour amount ap from Jug 1 to Jug 2
            c = u.first - ap;
            d = u.second + ap;
            // Check if this state is possible or not
            if ((d == b && c >= 0) || (c == 0 && d <= b))
                Pour(c, d, u);
        }
    }
    if (!isSolvable)
        cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        int jug1, jug2, target;
        cin >> jug1 >> jug2 >> target;
        BFS(jug1, jug2, target);
    }

    return 0;
}