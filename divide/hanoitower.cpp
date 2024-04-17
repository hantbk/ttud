/*
    Hanoi Tower
    Cho n dia tren cot A, chuyen tat ca n dia sang cot C sao cho:
        - Chi duoc phep chuyen 1 dia trong 1 buoc
        - Khong duoc dat dia nang len dia nho

    Giai thuat:
        - Chuyen n-1 dia tu A => B qua trung gian C
        - Chuyen dia cuoi cung tu A => C
        - Chuyen n-1 dia tu B => C qua trung gian A
    Input:  3
    Output: Buoc 1: chuyen dia tu 1 sang 3
            Buoc 2: chuyen dia tu 1 sang 2
            Buoc 3: chuyen dia tu 3 sang 2
            Buoc 4: chuyen dia tu 1 sang 3
            Buoc 5: chuyen dia tu 2 sang 1
            Buoc 6: chuyen dia tu 2 sang 3
            Buoc 7: chuyen dia tu 1 sang 3
*/

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