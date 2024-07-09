#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1009
#define ll long long
#define MOD 1000000009

int n, k;
int a[MAX];
double F[MAX][MAX]; // F[k][n] là max avg của dãy con có k phần tử và kết thúc tại n
double max_avg = -INF; // Khởi tạo với giá trị nhỏ hơn để tìm max

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void dp(){
    // Khởi tạo F[1][i]
    for(int i = 0; i < n; i++){
        F[1][i] = a[i];
    }

    // Tính các giá trị F[i][j] với i > 1
    for(int i = 2; i <= k; i++){
        for(int j = i - 1; j < n; j++){
            double max_avg_local = -INF;
            for(int t = j; t >= i - 1; t--){
                double sum = 0;
                for(int m = t; m <= j; m++) {
                    sum += a[m];
                }
                double avg_val = sum / (j - t + 1);
                max_avg_local = max(max_avg_local, (F[i - 1][t - 1] * (i - 1) + sum) / i);
            }
            F[i][j] = max(F[i][j - 1], max_avg_local);
        }
    }

    // Tìm giá trị max_avg trong F[k][n]
    for(int i = k - 1; i < n; i++){
        max_avg = max(max_avg, F[k][i]);
    }

    cout << fixed << setprecision(5) << max_avg << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    dp();

    return 0;
}
