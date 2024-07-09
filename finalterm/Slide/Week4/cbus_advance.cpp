#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, K, D;
int X[100];        // Mảng lưu trữ đường đi từ thành phố 1 đến thành phố n
int c[100][100];   // c[i][j] là ma trận chi phí từ thành phố i đến thành phố j
int load = 0;      // Biến lưu trữ số lượng hành khách trên xe
int cmin = INF;    // Biến lưu trữ chi phí nhỏ nhất
bool visited[100]; // Mảng lưu trữ các thành phố đã đi qua
int f[100];       // Mảng lưu trữ chi phí hiện tại 
int fbest = INF;   // Biến lưu trữ chi phí nhỏ nhất

void input()
{
    cin >> N >> K >> D;
    for (int i = 0; i <= 2 * N; i++)
    {
        for (int j = 0; j <= 2 * N; j++)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] > 0)
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}

// Kiểm tra có thể đặt thành phố v tại vị trí k không
bool check(int v, int k)
{
    if (visited[v])
        return false;
    if (v > N && !visited[v - N])
        return false;
    if (v <= N && load + 1 > K)
        return false;
    if(v > N && f[X[k-1]] - f[v-N] + c[X[k-1]][v] > D)
        return false;
    return true;
}

void updateBest(int v)
{
    if (f[v] + c[X[2 * N]][0] < fbest)
    {
        fbest = f[v] + c[X[2 * N]][0];
    }
}

void Try(int k)
{
    for (int v = 1; v <= 2 * N; v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            visited[v] = true;
            f[v] = f[X[k-1]] + c[X[k - 1]][v];

            if (v <= N)
                load++;
            else
                load--;

            if (k == 2 * N)
                updateBest(v);
            else if (f[v] + (2 * N - k + 1) * cmin < fbest)
                Try(k + 1);

            if (v <= N)
                load--;
            else
                load++;
            visited[v] = false;
            f[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    X[0] = 0;
    f[0] = 0;
    visited[0] = true;
    Try(1);
    cout << fbest << endl;

    return 0;
}