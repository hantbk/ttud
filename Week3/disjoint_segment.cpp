#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9+7
#define INF 1e9+18
#define endl "\n"

int n; // number of segments
int start[1000000]; // start point of each segment
int finish[1000000]; // end point of each segment
int a[1000000]; // Mang chua thu tu xep tang dan theo thoi diem ket thuc

// Sap xep tang dan theo thoi diem ket thuc
bool cmp(int i, int j){
    return finish[i] < finish[j];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>start[i]>>finish[i];
    }
    
    for (int i = 0; i < n; i++) a[i] = i;
    sort(a, a+n, cmp);

    int e = finish[a[0]];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        // Neu thoi diem bat dau cua doan i lon hon hoac bang thoi diem ket thuc cua doan truoc do
        if (start[a[i]] > e)
        {
            count++;
            e = finish[a[i]];
        }
    }
    cout<<count;
    
    return 0;
}
