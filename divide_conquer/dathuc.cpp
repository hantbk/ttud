/*
    Dãy số a0, a1, a2, ..., an và số thực x cho trước. 
    Hãy tính giá trị của đa thức Pn(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
    bằng cách sử dụng phương pháp chia để trị và không sử dụng phương pháp chia để trị.
    Input:  3
            a[0] = 1
            a[1] = 2
            a[2] = 3
            a[3] = 4
            x = 2
    Output: Pn(x) = 49
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
double x, a[MAX];

void nhapdulieu() {
    cout<<"N = "; cin>>n;
    for (int i = 0; i <= n; i++)
    {
        cout<< "a[" << i <<"] = "; cin>>a[i];
    }
    cout<<"X = "; cin>>x;
}

// Naive 
double tinh() {
    double z = 0;
    for (int i = 0; i <= n; i++)
    {
        double p = a[i];
        for (int j = 1; j <= n - i; j++)
        {
            p = p * x;
        }
        z += p;
    }
    return z;
}

// Chia de tri 
double P(int n) {
    if(n == 0) return a[0];
    return P(n-1) * x + a[n];
}

int main() {
    nhapdulieu();
    cout<<"Pn(x) = "<<tinh()<<endl;
    cout<<"Pn(x) = "<<P(n)<<endl;
    return 0;
}