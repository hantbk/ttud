#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

// O(n^3) - Brute Force
void solve1(){
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += v[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
}

// O(n^2) - Brute Force
void solve2(){
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
}

// O(n) - Kadane's Algorithm
void solve3(){
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += v[i];
        if (max_sum < curr_sum)
        {
            max_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    cout<< max_sum<<endl;
    return;
}

// O(nlogn) - Divide and Conquer
int vt1, vt2, vt;
int maxleft(vector<int> &v, int i, int j){
    int maxSum = -10000000, sum = 0;
    for (int k = j; k >= i; k--)
    {
        sum += v[k];
        if (sum > maxSum)
        {
            maxSum = sum;
            vt1 = k;
        }        
    }
    return maxSum;
}

int maxright(vector<int> &v, int i, int j){
    int maxSum = -10000000, sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += v[k];
        if (sum > maxSum)
        {
            maxSum = sum;
            vt2 = k;
        }
    }
    return maxSum;
}

int maxsub(vector<int> &v, int i, int j){
    if (i == j)
    {
        return v[i];
    }
    int m = (i + j) / 2;
    int wL = maxsub(v, i, m);
    int wR = maxsub(v, m + 1, j);
    int wM = maxleft(v, i, m) + maxright(v, m + 1, j);
    if (wL > wR)
    {
        vt = vt1;
    } else {
        vt = vt2;
    }
    return max(max(wL, wR), wM);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }  

    // int sum = maxsub(v, 0, n - 1);
    solve3();
    // cout << sum << " " <<endl;
    return 0;
}