#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int m, n;

int way(int m, int n)
{
    if (m == 0 || n == 0)
        return 1;

    return way(m - 1, n) + way(m, n - 1);
}

int main()
{
    cin >> m >> n;

    cout << way(m, n);

    return 0;
}