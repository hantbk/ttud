#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000009

string T, P;

long long power(int a, int b) {
    // Compute a^b % MOD using modular exponentiation
    long long res = 1;
    for (int i = 0; i < b; i++) {
        res = (res * a) % MOD;
    }
    return res;
}

int hashCode(string P) {
    // Compute the hash code of string P
    int m = P.length();
    long long c = 0;
    for (int i = 0; i < m; i++) {
        c = (c * 256 + P[i]) % MOD;
    }
    return c;
}

int hashCode(string T, int start, int end) {
    // Compute the hash code of substring T[start:end]
    long long c = 0;
    for (int i = start; i <= end; i++) {
        c = (c * 256 + T[i]) % MOD;
    }
    return c;
}

int rabinKarp(string P, string T) {
    // Rabin-Karp algorithm to count occurrences of P in T
    int cnt = 0;
    int n = T.length();
    int m = P.length();
    int hP = hashCode(P);
    int hT = hashCode(T, 0, m - 1);
    long long e = power(256, m - 1);

    for (int s = 0; s <= n - m; s++) {
        if (hP == hT) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (P[j] != T[s + j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
            }
        }
        if (s < n - m) {
            int t = (T[s] * e) % MOD;
            hT = ((hT - t + MOD) % MOD * 256 + T[s + m]) % MOD;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> P;
    cout << rabinKarp(P, T);

    return 0;
}
