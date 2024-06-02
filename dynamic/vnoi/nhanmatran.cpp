#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N;
int d[MAX];
int F[MAX][MAX]; // F[i][j] là số phép nhân để tính tích của các ma trận từ i đến j

void dp(){
    for(int i = 1; i <= N; i++) F[i][i] = 0;

    for(int i = 1; i < N; i++)
        F[i][i + 1] = d[i-1] * d[i] * d[i+1];

    for(int len = 2; len < N; len++){
        for(int i = 1; i <= N - len; i++){
            int j = i + len;
            F[i][j] = INF;
            for(int k = i + 1; k < j; k++)
                F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + d[i-1] * d[k] * d[j]);
        }
    }

    cout << F[1][N];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> d[i];

    dp();

    return 0;
}
