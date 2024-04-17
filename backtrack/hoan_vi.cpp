/*
    Cho n là số nguyên dương. Hãy liệt kê tất cả các hoán vị của 1, 2, ..., n.
    Input: n
    Output: Các hoán vị của 1, 2, ..., n
    
*/

#include <iostream>
#define MAX 100

using namespace std;

int a[MAX], n, m;
bool mark[MAX];

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
        for (int i = 1; i <= n; i++)
        {
            if (!mark[i])
            {
                mark[i] = true;
                a[k] = i;
                Try(k+1);
                mark[i] = false;
            }
        }
    }
} 

int main() {
    cin>>n;

    Try(1);

    return 0;
}