#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, S;
int a[MAX];
bool L[MAX]; // L[i] = 1 nếu tồn tại dãy con có tổng bằng i

void dp(){
    L[0] = true; // Không chọn phần tử nào

    for(int i = 1; i <= n; i++){
        for(int t = S; t >= a[i]; t--){
            if(!L[t] && L[t - a[i]]){
                L[t] = true;
            }
        }
    }
    if(L[S]){
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