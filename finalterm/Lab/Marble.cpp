#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int W, H;
int table[1009][1009]; // table[i][j] là lượng chất thải nhỏ nhất khi cắt tấm gạch i x j

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            table[i][j] = i * j; // Khởi tạo bảng chất thải

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        table[y][x] = 0; // Đánh dấu các ô không có chất thải
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int minWaste = table[i][j];
            // Horizontal cut
            for (int k = 1; k <= i; k++)
            {
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);
            }
            // Vertical cut
            for (int k = 1; k <= j; k++)
            {
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);
            }
            table[i][j] = minWaste;
        }
    }
    cout << table[H][W] << endl;

    return 0;
}