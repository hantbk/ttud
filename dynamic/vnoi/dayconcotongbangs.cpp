/*
Cho dãy A1, A2, ..., An
Tìm 1 dãy con có tổng bằng S.
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, S;
int a[MAX];
int L[MAX][MAX]; // L[i][t] = 1 nếu tồn tại dãy con từ 1 đến i có tổng bằng t

void dp(){
    L[0][0] = 1; // Không chọn phần tử nào
    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= S; t++){
            L[i][t] = L[i - 1][t]; // Không chọn phần tử i
            if(t >= a[i]){
                L[i][t] = L[i][t] || L[i - 1][t - a[i]]; // Chọn phần tử i
            }
        }
    }
    if(L[n][S]){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>S;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    dp();

    return 0;
}