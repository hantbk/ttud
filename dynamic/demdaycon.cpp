/*
    Bài toán: Cho số nguyên S và mảng A gồm N số nguyên.
    Hãy tìm số lượng dãy con không giảm của mảng A có tổng bằng S.
    Dữ liệu vào:
        - Dòng đầu tiên chứa 2 số nguyên N và S (1 ≤ N ≤ 100, 1 ≤ S ≤ 10^6)
        - Dòng thứ 2 chứa N số nguyên A1, A2, ..., AN (1 ≤ Ai ≤ 10^6)
    Kết quả:
        - In ra số lượng dãy con không giảm của mảng A có tổng bằng S.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, a[MAX], s;
int c[MAX][MAX]; // c[k][s] = F[s][k], mang c duoc tinh tu c[0] => c[1] => c[2] => ... => c[n]

int F(int s, int k)
{
    if (k == 0)
        return (s == 0) ? 1 : 0;
    return (s < a[k]) ? F(s, k - 1) : F(s, k - 1) + F(s - a[k], k - 1);
}

void dp()
{
    c[0][0] = 1;

    for (int j = 1; j <= s; j++)
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            c[i][j] = c[i - 1][j];
            if (j >= a[i])
            {
                c[i][j] += c[i - 1][j - a[i]];
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Nhap S: ";
    cin >> s;
    dp();

    cout << "Cac day con co tong bang S (top-down method) la: " << F(s, n) << endl;
    cout << "Cac day con co tong bang S (bottom-up method) la: " << c[n][s] << endl;

    return 0;
}