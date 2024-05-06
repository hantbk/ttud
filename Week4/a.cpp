#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MAX 10000009
#define ll long long
 
ll n, a[MAX], SumChan, SumLe, result, sum[MAX];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
 
    SumChan = 0;
    SumLe = INF;
    result = - INF;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
        if(sum[i] % 2 == 0) {
            result = max(result, sum[i] - SumChan);
            SumChan = min(SumChan, sum[i]);
        } else {
            if(SumLe == INF){
                SumLe = sum[i];
            }else {
                result = max(result, sum[i] - SumLe);
                SumLe = min(SumLe, sum[i]);
            }
        }
    }
 
    if(result == -INF) {
        cout<<"NOT_FOUND";
    }else{
        cout<<result;
    }
 
    return 0;
}