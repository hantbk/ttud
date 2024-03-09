#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int getMid(int l, int r){
    return l +(r - l) /2;
}

// Xay dung bang Segment Tree luu giu gia tri nho nhat trong cac khoang L -> R 
void updateValueSegmentTree(vector<int> &st, int si, int L, int R, int i, int delta, int new_val){
    if (i < L || i > R)
    {
        return;
    }
    if (R == L)
    {
        st[si] += delta;
    } else
    {
        int mid = getMid(L, R);
        updateValueSegmentTree(st, si * 2 + 1, L, mid, i, delta, new_val);
        updateValueSegmentTree(st, si *2 + 2, mid + 1, R, i, delta, new_val);
        st[si] = min(st[si * 2 +1], st[si * 2 + 2]);
    }
}

void updateValue(vector<int> &arr, vector<int> &st, int n, int i, int new_val) {
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid input";
        return;
    }
    int delta = new_val - arr[i];
    
}

int main() {

    return 0;
}