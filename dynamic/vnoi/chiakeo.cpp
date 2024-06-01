/*
Cho n gói kẹo, gói thứ i có ai viên kẹo
Hãy chia n gói kẹo thành 2 phần sao cho hiệu số viên kẹo giữa 2 phần là nhỏ nhất
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[MAX];
int T; // Tổng số viên kẹo
int F[MAX][MAX]; // F[i][S] là tổng số viên kẹo lớn nhất có thể chia được từ 1 đến i mà không vượt quá S

void dp(){
    for(int i = 1; i <= n; i++){
        for(int S = 1; S <= T / 2; S++){
            F[i][S] = F[i - 1][S]; // Không chọn gói i
            if(S >= a[i]){
                F[i][S] = max(F[i][S], F[i - 1][S - a[i]] + a[i]); // Chọn gói i
            }
        }
    }
    cout<<T - 2 * F[n][T / 2]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        T += a[i];
    }

    dp();

    return 0;
}