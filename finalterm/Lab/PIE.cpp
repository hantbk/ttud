#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 10009
#define ll long long
#define MOD 1000000009
#define PI 4 * atan(1)

int N, F;
int cnt = INF;
int r[MAX];
double S[MAX]; // S[i] là diện tích của chiếc bánh thứ i
double MAXS;  // Diện tích lớn nhất của chiếc bánh

void input()
{
    MAXS = 0;
    cin >> N >> F;
    for(int i = 0; i < N; i++)
    {
        cin >> r[i];
        S[i] = PI * r[i] * r[i];
        MAXS = max(MAXS, S[i]);
    }
}

// Kiểm tra xem có thể chia chiếc bánh ra thành ít nhất F phần không
bool check(double s){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += floor(S[i] / s);
    }
    return sum > F;
}

double PIE(double left, double right){
    double mid = (left + right) / 2;
    cnt--;

    if(right - left < 1e-7 || cnt < 0) return mid;
    else{
        if(check(mid)) return PIE(mid, right);
        else return PIE(left, mid);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        input();
        cout << fixed << setprecision(6) << PIE(0, MAXS) << endl;
    }

    return 0;
}