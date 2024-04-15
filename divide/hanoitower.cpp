#include <bits/stdc++.h>
using namespace std;

int n, buoc = 0;

// Chuyen n dia tu A => B qua trung gian C
void move(int n, int A, int B, int C)
{
    if (n == 1)
    {
        buoc++;
        cout << "Buoc " << buoc << ": chuyen dia tu " << A << " sang " << C << endl;
    }
    else
    {
        move(n - 1, A, C, B);
        move(1, A, B, C);
        move(n - 1, B, A, C);
    }
}

int main()
{
    cout << "N = ";
    cin >> n;
    move(n, 1, 2, 3);
    return 0;
}