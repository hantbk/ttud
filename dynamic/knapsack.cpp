/*
    Bai toan cai tui
    Cho n vat va mot cai tui co the chua dung w kg
    Moi vat co trong luong ai va gia tri bi
    Hay chon cac vat de cho vao cai tui sao cho gia tri cua cac vat do la lon nhat
    va trong luong cua chung khong vuot qua w
    Nhap vao n, w, mang a[] va b[] la trong luong va gia tri cua vat thu i
    Xuat ra gia tri lon nhat co the dat duoc
    1 <= n <= 100
    1 <= w <= 1000
    1 <= ai, bi <= 100
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int c[MAX][MAX]; // c[k][h] = F(k, h) la gia tri lon nhat co the dat duoc khi su dung k vat va gioi han trong luong la h
int a[MAX], b[MAX]; // Mang a[] la trong luong cua vat thu i, mang b[] la gia tri cua vat thu i
int n, w;           // Trong luong cua cai tui

// Sử dụng k đồ vật đầu tiên và giới hạn tổng trọng lượng là h
int F(int k, int h)
{
    if (h == 0 || k == 0)
        return 0;
    if (h >= a[k])
        return max(F(k - 1, h), F(k - 1, h - a[k]) + b[k]);
    return F(k - 1, h);
}

void dp() {
    c[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<"N = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
        cout << "b[" << i << "]: ";
        cin >> b[i];
    }
    cout << "W = ";
    cin >> w;

    cout << "So tien toi da lay duoc (top-down): "<< F(n, w)<<endl;
    cout << "So tien toi da lay duoc (bottom-up): "<< F(n, w)<<endl;

    return 0;
}