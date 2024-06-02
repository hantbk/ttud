/*
Cho 2 xâu X,F. Xâu gốc có n kí tự và xâu F có m kí tự.
Có 3 phép biến đổi xâu như sau:
- Chèn 1 kí tự vào sau kí tự thứ i: I i c (1 ≤ i ≤ n+1, 1 ≤ c ≤ 26)
- Thay thế kí tự thứ i bằng kí tự c: R i c (1 ≤ i ≤ n, 1 ≤ c ≤ 26)
- Xóa kí tự thứ i: D i (1 ≤ i ≤ n)
Hãy tìm số lần biến đổi ít nhất để xâu X trở thành xâu F.
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
string X, F;
int L[MAX][MAX]; // L[i][j] la so lan bien doi it nhat de bien xau X[1..i] gồm i kí tự phần đầu của X thanh xau F[1..j] gồm j kí tự phần đầu của F

void dp()
{
    for (int i = 0; i <= n; i++)
        L[i][0] = i;
    for (int j = 0; j <= m; j++)
        L[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Nếu X[i] = F[j] thì không cần phải thay đổi
            if(X[i-1] == F[j-1]) L[i][j] = L[i-1][j-1];
            else L[i][j] = min(min(L[i-1][j] + 1,L[i][j-1] + 1),L[i-1][j-1] + 1);
        }
    }
    cout << L[n][m];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> X >> F;
    dp();

    return 0;
}