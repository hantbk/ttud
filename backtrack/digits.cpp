#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int X[7]; // X[0] = I, X[1] = C, X[2] = T, X[3] = K, X[4] = H, X[5] = U, X[6] = S
int ans, n;
bool appear[10];

void solution()
{
    int T = X[0] * 100 + X[1] * 10 + X[2] - X[3] * 100 - 62 + X[4] * 1000 + X[5] * 100 + X[6] * 10 + X[2]; // T = ICT - K62 + HUST
    if (T == n)
    {
        ans++;
        // cout << X[0] << X[1] << X[2] << " - " << X[3] << "62 + " << X[4] << X[5] << X[6] << X[2] << " = " << n << endl;
    }
}

void Try(int k){
    for (int v = 1; v <= 9; v++)
    {
        if (!appear[v])
        {
            X[k] = v;
            appear[v] = true;
            if(k == 6) solution();
            else Try(k+1);
            appear[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    Try(0);
    cout << ans;

    return 0;
}