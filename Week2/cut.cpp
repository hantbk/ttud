#include <bits/stdc++.h>
using namespace std;

int H, W; // The shape rectangle with height H and width W
int n;    // n smaller rectangle submaterials
int h[10], w[10];
int x[10], y[10], o[10];
bool mark[10][10];
int result = 0;

bool check(int v0, int vx, int vy, int k)
{
    int wk, hk;
    if (v0 == 0)
    {
        wk = w[k];
        hk = h[k];
    }
    else
    {
        wk = h[k];
        hk = w[k];
    }
    if (vx + wk > W)
        return false;
    if (vy + hk > H)
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

void doMark(int v0, int vx, int vy, int k, bool mark_value)
{
    int wk, hk;
    if (v0 == 0)
    {
        wk = w[k];
        hk = h[k];
    }
    else
    {
        wk = h[k];
        hk = w[k];
    }
    for (int i = vx; i < vx + wk; i++)
    {
        for (int j = vy; j < vy + hk; j++)
        {
            mark[i][j] = mark_value;
        }
    }
}

void Try(int k)
{
    if (k == n)
    {
        result++;
        return;
    }

    for (int v0 = 0; v0 <= 1; v0++)
    {
        int wk, hk;
        if (v0 == 0)
        {
            wk = w[k];
            hk = h[k];
        }
        else
        {
            wk = h[k];
            hk = w[k];
        }

        for (int vx = 0; vx <= W - wk; vx++)
        {
            for (int vy = 0; vy <= H - hk; vy++)
            {
                if (check(v0, vx, vy, k))
                {
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = v0;
                    doMark(v0, vx, vy, k, true);
                    Try(k + 1);
                    doMark(v0, vx, vy, k, false);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }

    Try(0);

    if (result > 0)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}