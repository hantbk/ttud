#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[100009];

int MaxLeftMid(int i, int m){
    int ans = a[m];
    int sum = 0;
    for(int k = m; k >=i; k--){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRightMid(int m, int j){
    int ans = a[m];
    int sum = 0;
    for(int k = m; k <= j; k++){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int SubSeqMax(int i, int j){
    if(i == j) return a[i];
    int m = (i + j) / 2;
    int wL = SubSeqMax(i, m);
    int wR = SubSeqMax(m + 1, j);

    int wLM = MaxLeftMid(i, m);
    int wRM = MaxRightMid(m + 1, j);
    int wM = wLM + wRM;

    return max(max(wL, wR), wM);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];

    cout<<SubSeqMax(0, n - 1)<<endl;

    return 0;
}