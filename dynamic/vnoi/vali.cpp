/*
Có n đồ vật, mỗi đồ vật có khối lượng và giá trị tương ứng Ai, Bi
Có một cái túi có thể chứa tối đa W kg
Hãy chọn một số đồ vật sao cho tổng khối lượng không vượt quá W và tổng giá trị là lớn nhất
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, W;
int a[MAX], b[MAX];
int F[MAX][MAX]; // F[i][j] là tổng giá trị lớn nhất của vali khi xét từ vật 1 đến vật i với khối lượng tối đa là j

void dp(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            F[i][j] = F[i - 1][j]; // Không chọn vật i
            if(j >= a[i]){
                F[i][j] = max(F[i][j], F[i - 1][j - a[i]] + b[i]); // Chọn vật i
            }
        }
    }
    cout<<F[n][W]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>W;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>b[i];
    }
    dp();

    return 0;
}