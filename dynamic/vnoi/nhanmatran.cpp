#include <iostream>
using namespace std;

const int N = 310;
int d[N], L[N][N], n;

int calc(int i, int j)
{
    if (L[i][j] == -1)
    {
        if (i == j)
            L[i][j] = 0;
        else
        {
            L[i][j] = calc(i + 1, j) + d[i - 1] * d[i] * d[j];
            for (int k = i; k < j; k++)
                L[i][j] = min(L[i][j], calc(i, k) + calc(k + 1, j) + d[i - 1] * d[k] * d[j]);
        }
    }
    return L[i][j];
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        L[i][j] = -1;
    cout << calc(1, n);
}