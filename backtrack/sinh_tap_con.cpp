#include <iostream>
#define MAX 100

using namespace std;

int a[MAX], n, m;

void solution(){
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int k){
    // Da sinh xong cau hinh
    if (k > n)
    {
        solution();
        return;
    } 
    else // Chua sinh xong cau hinh
    {
        for (int i = a[k-1] + 1; i <= m - n + k; i++)
        {
            a[k] = i;
            Try(k+1);
        }
    }
} 

int main() {
    // Initialize n and m here
    // For example:
    cin>>n>>m;

    Try(1);

    return 0;
}