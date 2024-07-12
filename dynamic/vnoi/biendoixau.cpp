#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m, n;
string a, b;
vector<vector<int>> L;

int main()
{
    cin >> a >> b;
    m = a.length();
    n = b.length();
    L.resize(m + 1);
    for (auto& i : L)
        i.resize(n + 1);
    /* Vì a và b bắt đầu từ chỉ số 1 nên
     * chèn thêm 1 kí tự vào đầu 2 xâu */
    a = "_" + a;
    b = "_" + b;

    for (int i = 0; i <= m; i++)
        L[i][0] = i;
    for (int j = 0; j <= n; j++)
        L[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                L[i][j] = L[i - 1][j - 1];
            else
                L[i][j] = 1 + min(L[i - 1][j - 1],
                              min(L[i - 1][j], L[i][j - 1]));
        }
    cout << L[m][n];
}