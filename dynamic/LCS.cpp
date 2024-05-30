/*
Longest common subsequence (LCS) is a classic dynamic programming problem. 
Given two sequences, find the length of the longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily 
contiguous. For example, "abc", "abg", "bdf", "aeg", "acefg", .. etc are subsequences 
of "abcdefg". So a string of length n has 2^n different possible subsequences.
It is a classic computer science problem, the basis of data comparison programs 
such as the diff utility, and has applications in bioinformatics. 
It is solved using dynamic programming. 
The time complexity of the dynamic programming solution is O(m*n), 
where m and n are the lengths of the two sequences.
Giai thuat: 
    - Dùng bảng lưu kết quả của các dãy con của 2 xâu
    - Nếu 2 kí tự cuối của 2 xâu giống nhau thì lấy kết quả của 2 xâu trướng đó cộng thêm 1
    - Nếu không giống nhau thì lấy kết quả lớn nhất của 2 xâu trước đó
    - Kết quả cuối cùng là kết quả của 2 xâu
    S(p, q) = S(p-1, q-1) + 1, nếu X[p] = Y[q]
            = max(S(p-1, q), S(p, q-1)), nếu X[p] != Y[q]
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, m;
int a[MAX], b[MAX];
int L[MAX][MAX]; // Luu lai cac gia tri S(p, q)

int S(int p, int q){
    if (p == 0 || q == 0)
    {
        return 0;
    }
    if (a[p-1] == b[q-1])
    {
        return 1 + S(p-1, q-1);
    }
    return max(S(p-1, q), S(p, q-1));
}

void trace(int p, int q){
    if (p == 0 || q == 0)
    {
        return;
    }
    if (a[p-1] == b[q-1])
    {
        trace(p-1, q-1);
        cout<<a[p-1]<<" ";
    } else
    {
        if (L[p-1][q] > L[p][q-1])
        {
            trace(p-1, q);
        } else
        {
            trace(p, q-1);
        }
    }
}

void dp(){
    for (int q = 0; q <= n; q++)
    {
        L[0][q] = 0;
    }
    for (int p = 1; p <= m; p++)
    {
        L[0][0] = 0;
        L[p][0] = 0;
        for (int q = 1; q <= n; q++)
        {
            if (a[p-1] == b[q-1])
            {
                L[p][q] = 1 + L[p-1][q-1];
            } else
            {
                L[p][q] = max(L[p-1][q], L[p][q-1]);
            }
        }
    }
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<L[m][n]<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    // cout<<S(m, n)<<endl;
    dp();
    // trace(m, n);

    return 0;
}