#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009
#define pii pair<int, int>

int n;
pii a[100005]; // a[i] = {start, finish} of the i-th segment
int res = 0;

// Greedy: Sort the segments by finish in increasing order
bool compare(pii a, pii b) {
    return a.second < b.second;
}

int greedy(){
    sort(a,a + n, compare);
    int end = a[0].second;
    res++;
    for(int i = 1; i < n; i++){
        if(a[i].first > end){
            res++;
            end = a[i].second;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i].first>>a[i].second;
    }

    cout<<greedy()<<endl;

    return 0;
}