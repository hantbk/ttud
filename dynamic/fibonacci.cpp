#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;

// Sol 1: Đệ quy
int Fib0(int n)
{
    if (n <= 2)
        return 1;
    return Fib0(n - 1) + Fib0(n - 2);
}

// Sol 2: Đệ quy có nhớ
map<int, int> memory;
int Fib1(int n)
{
    if (n <= 2)
        return 1;

    if (memory.find(n) != memory.end())
        return memory[n];

    int res = Fib1(n - 1) + Fib1(n - 2);
    memory[n] = res;
    return res;
}

// Hoặc như sau
int mem[10005];
int Fib2(int n){
    if(n <= 2) return 1;
    if(mem[n] != -1) return mem[n];

    int res = Fib2(n-1) + Fib2(n-2);
    mem[n] = res;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout<<Fib0(n)<<endl;
    cout<<Fib1(n)<<endl;
    cout<<Fib2(n)<<endl;

    return 0;
}