/*
    Find the maximum subsequence sum of an array
    Input:  8
            -2 1 -3 4 -1 2 1 -5
    Output: 6
            4 -1 2 1
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, a[1005];
int mem[1005];
bool mark[1005];
int S[1005]; // S[i] là trọng số của đoạn có trọng số lớn nhất giới hạn trong đoạn 1,2,..,i mà kết thúc tại a[i]

// Bottom-up
void dp()
{
    int res = 0;
    S[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        S[i] = max(a[i], S[i - 1] + a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, S[i]);
    }
    cout << res;
}

// Top-down
int MaxSum(int i)
{
    if (i == 1)
        return a[1];
    // return max(a[i], a[i] + MaxSum(i-1));
    if (mark[i])
        return mem[i];
    int res = max(a[i], a[i] + MaxSum(i - 1));
    mark[i] = true;
    mem[i] = res;

    return res;
}

void Trace(int i)
{
    if (i != 1 && mem[i] == a[i] + mem[i - 1])
    {
        Trace(i - 1);
    }
    cout << a[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(mark, 0, sizeof(mark));

    int ans = MaxSum(n);
    int pos = -1;
    for (int i = 1; i <= n; i++)
    {
        // ans = max(ans, mem[i]);
        if(ans < mem[i]){
            ans = mem[i];
            pos = i;
        }
    }
    cout << ans << endl;

    int left = pos, right = pos, sum = a[left];
    while (sum != ans)
    {
        left--;
        sum += a[left];
    }
    
    for(int i = left; i <= right; i++){
        cout<<a[i]<<" ";
    }
    
    // // Find the ending index of the maximum subarray
    // int endIndex = n;
    // for (int i = 1; i <= n; i++) {
    //     if (mem[i] == ans) {
    //         endIndex = i;
    //         break;
    //     }
    // }

    // Trace(endIndex);
    return 0;
}