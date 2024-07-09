#include<bits/stdc++.h>
using namespace std;

int n;
int a[100009];
int res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    for(int i=1; i<n; i++){
        if(a[i] <= a[i-1]) res++;
    }

    cout<<res+1<<endl;

    return 0;
}