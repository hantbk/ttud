/*
    Lap lich cuoc hop
    Cho n cuoc hop, moi cuoc hop co thoi gian bat dau s[i] va thoi gian ket thuc f[i]
    Chon cac cuoc hop sao cho khong xung dot thoi gian
    Y tuong: Sap xep cac cuoc hop theo thoi gian ket thuc tang dan
    Chon cuoc hop dau tien, sau do chon cuoc hop tiep theo 
    neu thoi gian bat dau lon hon thoi gian ket thuc cua cuoc hop truoc
    Input:  8
            0 1 3 3 4 5 6 8
            6 4 5 8 7 9 10 11
    Output: Chon cac cuoc hop sau: 1 2 4 6
*/

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