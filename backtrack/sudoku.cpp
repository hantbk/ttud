#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int x[9][9];
bool markR[9][10];    // markR[r][v] = True => v đã xuất hiện trên hàng r
bool markC[9][10];    // markC[c][v] = True => v đã xuất hiện trên cột c
bool markS[3][3][10]; // markS[I][J][v] = True => v đã xuất hiện trong
                      // bảng con kích thước 3x3 ở toạ độ (I, J)

int sol;

void solution()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << x[i][j];
        }
        cout << endl;
    }
    cout << "-------------------------\n";
}

bool check(int v, int r, int c)
{
    if (markR[r][v])
        return false;
    if (markC[c][v])
        return false;
    if (markS[r / 3][c / 3][v])
        return false;
    return true;
}

void Try(int r, int c)
{
    for (int v = 1; v <= 9; v++)
    {
        if (check(v, r, c))
        {
            x[r][c] = v;
            markR[r][v] = true;
            markC[c][v] = true;
            markS[r / 3][c / 3][v] = true;
            if (r == 8 && c == 8)
            {
                // solution();
                sol++;
            }
            else
            {
                if (c == 8)
                    Try(r + 1, 0);
                else
                    Try(r, c + 1);
            }
            x[r][c] = 0;
            markR[r][v] = false;
            markC[c][v] = false;
            markS[r / 3][c / 3][v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int v = 1; v <= 9; v++)
    {
        for (int r = 0; r <= 8; r++)
            markR[r][v] = false;
        for (int c = 0; c <= 8; c++)
            markC[c][v] = false;
        for (int I = 0; I <= 2; I++)
            for (int J = 0; J <= 2; J++)
                markS[I][J][v] = false;
    }
    Try(0, 0);
    cout << sol;

    return 0;
}