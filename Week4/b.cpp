#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, k1, k2;
int s0[1001]; // s0[i] la so cach xep den ngay thu i va ngay thu i la ngay nghi
int s1[1001]; // s1[i] la so cach xep den ngay thu i va ngay thu i la ngay lam viec

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++)
    {
        s0[i] = s1[i] = 0;
    }

    s0[0] = 1;
    s1[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        s0[i] = s1[i - 1]; 
        for (int j = k1; j <= k2; j++)
        {
            if (i - j >= 0)
            {
                s1[i] = s1[i] + s0[i - j];
            }
        }
    }
    cout<<s0[n]+s1[n];
    
    return 0;
}