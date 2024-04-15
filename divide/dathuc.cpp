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