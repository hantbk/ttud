#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, K1, K2;
int S0[MAX]; // S0[i] là số cách xếp thoả mãn cho i ngày đầu trong đó ngày i là ngày nghỉ
int S1[MAX]; // S1[i] là số cách xếp thoả mãn cho i ngày đầu trong đó ngày i là ngày làm việc

void dp()
{
    for(int i = 1; i <= N; i++){
        S0[i] = S1[i] = 0;
    }

    S0[0] = 1;
    S0[1] = 1;
    S1[K1] = 1;

    for(int i = K1 + 1; i <= N; i++){
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int j = i - K2; j <= i - K1; j++){
            if(j >= 0){
                S1[i] = S1[i] + S0[j];
            }
        }
    }
    cout<<S0[N]+S1[N]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K1 >> K2;
    dp();

    return 0;
}