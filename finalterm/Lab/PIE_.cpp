#include <bits/stdc++.h>
using namespace std;

#define MAX 1000009
#define PI 3.14159265358979323846

int N, F;
int r[MAX];

int count_pie(double m){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += (int)(PI * r[i] * r[i] / m);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> F;
        for(int i = 0; i < N; i++)
        {
            cin >> r[i];
        }

        double left = 0;
        double right = *max_element(r, r + N);
        right = PI * right * right;
        double eps = 1e-7;

        while(right - left > eps){
            double mid = (left + right) / 2;
            if(count_pie(mid) >= F + 1){
                left = mid;
            }
            else{
                right = mid;
            }
        }

        cout << fixed << setprecision(6) << left << endl;
    }

    return 0;
}
