#include <bits/stdc++.h>

using namespace std;
#define INF 1e9

int N, K;
int c[3001], a[3001];
int g[3001][102]; 
int d = 0;
int res = -1;

int dp(int location, int rest)
{
    if (g[location][rest] == -1)
    {
        if (rest > 1)
        {
            for (int i = 1; i <= d; ++i)
            {
                if (location - i >= 1 && a[location - i] >= i)
                    g[location][rest] = max(g[location][rest], dp(location - i, rest - 1) + c[location]);
            }
            if (g[location][rest] == -1)
                g[location][rest] = -INF;
        }
        else
        {
            if (location != 1 && rest == 1)
                g[location][rest] = -INF;
            if (location == 1 && rest == 1)
                g[location][rest] = c[location];
        }
    }
    return g[location][rest];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> c[i];
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        d = max(d, a[i]);
    }
    memset(g, -1, sizeof(g));
    std::cout << max(res, dp(N, K + 1));
    return 0;
}