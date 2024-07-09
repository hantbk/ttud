#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int H, W;
int n;
int h[100], w[100];
bool mark[100][100];

int x[100], y[100];
int o[100];
int res = 0;

void input()
{
    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> w[i];
    }
}

bool check(int vo, int vx, int vy, int k)
{
    int wk = w[k];
    int hk = h[k];
    if (vo == 1)
    {
        wk = h[k];
        hk = w[k];
    }
    if (vx + wk > W || vy + hk > H)
        return false;
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            if (mark[i][j])
                return false;
        }
    }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool state)
{
    int wk = w[k];
    int hk = h[k];
    if (vo == 1)
    {
        wk = h[k];
        hk = w[k];
    }
    for (int i = vx; i < vx + wk; i++)
        for (int j = vy; j < vy + hk; j++)
            mark[i][j] = state;
}

void Try(int k)
{
    for (int vo = 0; vo <= 1; vo++)
    {
        int wk = w[k];
        int hk = h[k];
        if (vo == 1)
        {
            wk = h[k];
            hk = w[k];
        }
        for (int vx = 0; vx <= W - wk; vx++)
        {
            for (int vy = 0; vy <= H - hk; vy++)
            {
                if (check(vo, vx, vy, k))
                {
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(vo, vx, vy, k, true);
                    if (k == n)
                    {
                        res = 1;
                        return;
                    }
                    else
                        Try(k + 1);
                    doMark(vo, vx, vy, k, false);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    Try(1);
    cout << res << endl;

    return 0;
}