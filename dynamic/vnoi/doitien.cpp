#include <iostream>
#include <vector>
using namespace std;

// Struct để truy vết
struct Trace
{
    int coin; // Chỉ số đồng tiền được thêm vào
    int i; // i và j dùng để truy vết trong bảng QHĐ
    int j;

    Trace(int c = 0, int row = 0, int col = 0)
        : coin(c), i(row), j(col) {};
};

const int N = 1e6 + 10;
int n, m, A[N];
vector<int> L, P;
vector<vector<Trace>> d;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    // Quy ước inf = -1
    P = vector<int>(m + 1, -1);
    L.resize(m + 1);
    d = vector<vector<Trace>>(n + 1, vector<Trace>(m + 1));

    // Bước QHĐ
    for (int i = 1; i <= n; i++)
    {
        L[0] = 0;
        for (int j = 1; j <= m; j++)
            if (A[i] > j)
            {
                L[j] = P[j];
                d[i][j] = Trace(0, i - 1, j);
            }
            else
            {
                // L[j] = min(P[j], L[j - A[i]]);
                // Nếu P[j] và L[j - A[i]] khác inf
                if (P[j] != -1 && L[j - A[i]] != -1)
                {
                    if (P[j] < L[j - A[i]] + 1)
                    {
                        L[j] = P[j];
                        d[i][j] = Trace(0, i - 1, j);
                    }
                    else
                    {
                        L[j] = L[j - A[i]] + 1;
                        d[i][j] = Trace(i, i, j - A[i]);
                    }
                }
                // Chỉ L[j - A[i]] là inf
                else if (P[j] != -1)
                {
                    L[j] = P[j];
                    d[i][j] = Trace(0, i - 1, j);
                }
                // Chỉ P[j] là inf
                else if (L[j - A[i]] != -1)
                {
                    L[j] = L[j - A[i]] + 1;
                    d[i][j] = Trace(i, i, j - A[i]);
                }
                // Cả hai số là inf
                else
                    L[j] = -1;
            }
        P = L;
    }
    cout << L[m] << '\n';

    // Truy vết
    if (L[m] != -1)
    {
        vector<int> cnt(n + 1);
        Trace t = d[n][m];
        while (t.coin != 0 && t.j != 0)
        {
            cnt[t.coin]++;
            t = d[t.i][t.j];
        }
        for (int i = 1; i <= n; i++)
            cout << cnt[i] << ' ';
    }
}