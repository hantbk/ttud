/*
    TSP - Travelling Salesman Problem
    Cho n diem tren mat phang, tim duong di ngan nhat di qua tat ca cac diem
    Moi diem chi duoc di qua 1 lan
    Dung thuat toan nhanh canh
    1. Khoi tao gia tri a[0] = 0, b[0] = false
    2. Tim gia tri a[k], tong do dai duong di hien tai la "tong"
    3. Neu tong > dodai thi return
    4. Neu k == n thi kiem tra xem tong + c[a[n-1]][a[0]] co nho hon dodai khong
    5. Neu co thi cap nhat dodai
    6. Neu khong thi return
    7. Duyet i tu 0 den n
    8. Neu b[i] = true thi
    9. b[i] = false
    10. a[k] = i
    11. Goi lai ham Try(k+1, tong + c[a[k-1]][a[k]])
    12. b[i] = true
    13. Ket thuc
    Input:  4
            0 3 7 4
            3 0 1 2
            7 1 0 5
            4 2 5 0
    Output: Duong di ngan nhat 10
*/

#include <bits/stdc++.h>
using namespace std;

const int n = 4;
int c[n][n] = {
    {0, 3, 7, 4},
    {3, 0, 1, 2},
    {7, 1, 0, 5},
    {4, 2, 5, 0},
};

int a[n], dodai = 10000000;
bool b[n];

// Tim gia tri a[k], tong do dai duong di hien tai la "tong"
void Try(int k, int tong)
{
    if(dodai < tong) return;

    if (k == n)
    {
        if (dodai > tong + c[a[n - 1]][a[0]])
        {
            dodai = tong + c[a[n - 1]][a[0]];
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            b[i] = false;
            a[k] = i;
            Try(k+1, tong + c[a[k-1]][a[k]]);
            b[i] = true;
        }
    }
    
}

int main()
{
    for (int i = 0; i < n; i++) b[i] = true;
    a[0] = 0;
    b[0] = false;
    Try(1, 0);
    cout<<"Duong di ngan nhat "<<dodai;
    return 0;
}