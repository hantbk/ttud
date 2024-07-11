#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n,m;
int a[10009];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    bool flag = false;
    if(a[m-1] < n){
        a[m-1]++;
        flag = true;
    } else {
        for(int i = m -2 ; i >= 0; i--){
            if(a[i] < a[i+1] - 1){
                a[i]++;
                for(int j = i + 1; j < m; j++){
                    a[j] = a[j-1] + 1;
                }
                flag = true;
                break;
            }
        }
    }
    if(flag){
        for(int i = 0; i < m; i++)
            cout << a[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}