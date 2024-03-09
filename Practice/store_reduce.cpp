#include<bits/stdc++.h>
using namespace std;

void solve(){
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }    
    std::sort(arr, arr + 4); 
    int sum = 0;
    if(arr[0] < 0) sum += arr[0];
    if(arr[1] < 0) sum += arr[1];
    cout<<sum<<"\n";
}

int main(){
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}