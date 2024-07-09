#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

int n;
int a[1000009];
int ta[1000009]; // temporary array

ll Merge(int left, int mid, int right){
    ll dem = 0;
    int i = left;
    int j = mid + 1;
    for(int k = left; k <= right; k++){
        if(i > mid){
            ta[k] = a[j];
            j++;
        }else if(j > right){
            ta[k] = a[i];
            i++;
        } else if(a[i] > a[j]){
            ta[k] = a[j];
            j++;
            dem += mid - i + 1;
        } else {
            ta[k] = a[i];
            i++;
        }
    }
    for(int k = left; k <= right; k++)
        a[k] = ta[k];

    return dem;
}

ll MergeSort(int left, int right){
    ll cnt = 0;
    if(left < right){
        int mid = (left + right) / 2;
        cnt += MergeSort(left, mid);
        cnt += MergeSort(mid + 1, right);
        cnt += Merge(left, mid, right);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<MergeSort(0, n - 1) % MOD<<endl;

    return 0;
}