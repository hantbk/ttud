/*
Ở đất nước Omega người ta chỉ tiêu tiền xu. Có 𝑁 loại tiền xu, loại thứ 𝑖
có mệnh giá là 𝐴𝑖 đồng. Một người khách du lịch đến Omega du lịch với số 
tiền 𝑀 đồng. Ông ta muốn đổi số tiền đó ra tiền xu Omega để tiện tiêu dùng. 
Ông ta cũng muốn số đồng tiền đổi được là ít nhất (cho túi tiền đỡ nặng khi đi đây đi đó). 
Bạn hãy giúp ông ta tìm cách đổi tiền.
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, M;
int a[MAX];
int F[MAX][MAX]; // F[i][j] là số đồng xu ít nhất có thể đổi được từ i loại tiền đầu tiên sao cho tổng số tiền đổi được là j

void dp(){
    for(int i = 0; i <= N; i++)
        F[i][0] = 0;
    for(int j = 0; j <= M; j++)
        F[0][j] = INF; // Không thể đổi được tổng số tiền j nếu không có loại tiền nào

    for(int i = 1; i <= N; i++){
        for(int t = 1; t <= M; t++){
            if(t < a[i])
                F[i][t] = F[i - 1][t];
            else
                F[i][t] = min(F[i - 1][t], F[i][t - a[i]] + 1);
        }
    }

    cout << F[N][M];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> a[i];

    dp();

    return 0;
}