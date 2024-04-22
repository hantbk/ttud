/*
    The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days (1 ≤ N ≤ 1000). 
    Due to the hospital's policy, the nurse must work at least K1 and at most K2 consecutive days (1 ≤ K1, K2 ≤ 1000).
    A working period of the nurse is defined to be a consecutive sequence of working days. 
    The director wants to know the number of possible working plans for the nurse.

    Input
        The first line contains three integers N, K1, K2 (1 ≤ N ≤ 1000, 1 ≤ K1, K2 ≤ 1000).
    Output
        Print the number of possible working plans for the nurse modulo 10^9 + 7.

    Idea: 
        - F[i][j] la so cach xep den ngay thu i va da lam duoc j ngay lien tiep
        - F[i][j] = F[i - 1][j - 1] voi j > 0 // lam duoc j ngay lien tiep thi phai lam duoc j - 1 ngay lien tiep
        - F[i][0] = tong(F[i - 1][j]) voi k1 <= j <= k2 // neu khong lam duoc j ngay lien tiep thi phai lam duoc 0 ngay lien tiep
        - Ket qua la F[n + 1][0] + F[n][0] // vi co the lam duoc n ngay lien tiep hoac n + 1 ngay lien tiep
    Test:
        input:
            6 2 3
        output:
            4
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, k1, k2, res;
int F[1002][1002]; // F[i][j] la so cach xep den ngay thu i va da lam duoc j ngay lien tiep

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k1 >> k2;

    F[1][0] = 1;
    F[1][1] = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        for (int j = 1; j <= k2; j++)
        {
            F[i][j] = F[i - 1][j - 1];
        }

        for (int j = k1; j <= k2; j++)
        {
            F[i][0] = (F[i][0] + F[i - 1][j]) % MOD;
        }
    }

    res = F[n + 1][0] + F[n][0];
    cout << res % MOD;

    return 0;
}