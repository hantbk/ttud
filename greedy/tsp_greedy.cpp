#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int d[100][100];
set<int> C; // C is the set of cities 
vector<int> S; // S is the path of the salesman

void inp(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= n; j++)
            cin>>d[i][j];
}

int selectMin(int cur){
    int minD =INF; int select = -1;
    for(auto i: C){
        if(minD > d[cur][i]){
            minD = d[cur][i];
            select = i;
        }
    }
    return select;
}

// Tham lam: Chon diem gan nhat chua di qua
void greedy(){
    for(int i = 2; i <= n; i++) C.insert(i);
    int cur = 1;
    S.push_back(cur);
    int F = 0;
    while (C.size() > 0)
    {
        int x = selectMin(cur);
        C.erase(x);
        F += d[cur][x];
        S.push_back(x);
        cur = x;
    }
    F += d[cur][1];
    for(int i = 0; i< S.size(); i++) cout<<S[i]<<" ";
    cout<<1<<" length = "<<F<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inp();
    greedy();

    return 0;
}