/*
Cho bảng 𝐴 gồm 𝑀∗𝑁 ô. Từ ô (𝑖,𝑗) có thể di chuyển sang 3 ô (𝑖+1,𝑗)
,(𝑖+1,𝑗−1) và (𝑖+1,𝑗+1). Hãy xác định một lộ trình đi từ hàng 1 đến hàng 𝑀
sao cho tổng các ô đi qua là lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 10009
#define ll long long
#define MOD 1000000009

int M, N;
int A[MAX][MAX];
int F[MAX][MAX]; // F[i][j] là tổng lớn nhất khi đi đến ô (i, j)

void dp()
{
    for (int j = 1; j <= N; j++)
        F[1][j] = A[1][j];

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            F[i][j] = max(max(F[i - 1][j], F[i - 1][j - 1]), F[i - 1][j + 1]) + A[i][j];

    int res = -INF;
    for (int j = 1; j <= N; j++)
        res = max(res, F[M][j]); // Tìm tổng lớn nhất ở hàng M

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    dp();

    return 0;
}