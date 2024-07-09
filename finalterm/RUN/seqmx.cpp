#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, k;
int a[MAX];
int pre_sum[MAX];
double max_avg = -INF;

double Try(int j){ // Tìm max avg của dãy con có j <= k phần tử 
    double max_avg_local = -INF;

    for(int m = 1; m <= n - j + 1; m++){
        double sum = pre_sum[m + j - 1] - pre_sum[m - 1];
        double avg_val = sum / j;
        max_avg_local = max(max_avg_local, avg_val);
    }
    return max_avg_local;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    
    for(int i = k; i <= n; i++){
        max_avg = max(max_avg, Try(i));
    }

    cout << fixed << setprecision(5) << max_avg << endl;

    return 0;
}