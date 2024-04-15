#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, a[MAX], dem;
bool b[MAX]; // cot i chua co hau
bool c[MAX]; // duong cheo chinh chua co hau
bool d[MAX]; // duong cheo phu chua co hau

void solution()
{
    dem++;
    cout << "Cach dat hau thu " << dem << endl;
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            if (j == a[i])
                cout << " x";
            else
                cout << " .";
}

// // Kiem tra quan hau o dong k cot i co an toan khong
// bool isSafe(int k, int i)
// {
//     for (int j = 1; j < k; j++)
//         if (a[j] == i || a[j] + j == k + i || (a[j] - j == i - k))
//             return false;
//     return true;
// }

// Dat quan hau o dong thu k cot i
void Try(int k)
{
    if (k > n)
    {
        solution();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] && c[n + k - i] && d[k + i])
        {
            b[i] = c[n + k - i] = d[k + i] = false;
            a[k] = i;
            Try(k + 1);
            b[i] = c[n + k - i] = d[k + i] = true;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < MAX; i++)
    {
        b[i] = c[i] = d[i] = true;
    }
    
    Try(1);
    return 0;
}