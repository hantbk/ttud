#include<bits/stdc++.h>
using namespace std;

int x;

bool P(double j){
    return j*j >= x;
}

int main(){

    cin>>x;

    double lo = -1000.0, hi = 1000.0, eps = 1e-10;
    while (hi - lo >= eps)
    {
        double mid = (hi + lo )/ 2.0;
        if(P(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout<<lo;

    return 0;
}