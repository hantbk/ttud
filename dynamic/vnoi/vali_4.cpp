/*
Cho n đồ vật, mỗi đồ vật có khối lượng và giá trị tương ứng. 
Hãy chọn ra một số đồ vật sao cho tổng khối lượng không vượt quá W và tổng giá trị là lớn nhất.
Mỗi vật được chọn nhiều lần 
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, W;
int a[MAX], b[MAX];
int F[MAX][MAX]; // F[i][j] là giá trị lớn nhất có thể đạt được khi chọn từ các vật 1, 2, ..., i sao cho tổng khối lượng không vượt quá j

void dp(){
    for(int i = 0; i <= n; i++)
        F[i][0] = 0;
    for(int j = 0; j <= W; j++)
        F[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= W; t++){
            if(t < a[i])
                F[i][t] = F[i - 1][t];
            else
                F[i][t] = max(F[i - 1][t], F[i][t - a[i]] + b[i]);
        }
    }

    cout << F[n][W];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    dp();

    return 0;
}