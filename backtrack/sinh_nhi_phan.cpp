#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int x[MAX], n; // Chua cau hinh hien tai

bool check(int v, int k)
{
    if (k == 1)
        return true;
    return x[k - 1] + v <= 1;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
}