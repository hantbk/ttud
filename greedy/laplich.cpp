#include <bits/stdc++.h>
using namespace std;
#define MAX 8

int s[MAX] = {0, 1, 3, 3, 4, 5, 6, 8}; // bat dau
int f[MAX] = {6, 4, 5, 8, 7, 9, 10, 11}; // ket thuc
int a[MAX]; // Mang chua thu tu xep tang dan theo thoi diem ket thuc

bool sosanh(int i, int j) {
    return f[i] < f[j];
}

int main()
{
    int e; // thoi diem ket thuc
    for(int i = 0; i < MAX; i++) a[i] = i;
    sort(a, a + MAX, sosanh); 
    cout<<"Mang A sau khi sap xep:";
    for (int i = 0; i < MAX; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Chon cac cuoc hop sau: "<<a[0];
    e = f[a[0]];
    for (int i = 1; i < MAX; i++)
    {
        // Dieu kien khong xung dot voi cuoc hop truoc
        if (e <= s[a[i]])
        {
            cout<< " "<<a[i];
            e = f[a[i]];
        }
    }
    

    return 0;
}