#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, I, J;
int di[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dj[8] = {2, -2, 1, -1, 2, -2, 1, -1};
bool mark[100][100];
int Xi[10000], Xj[10000];
bool found;
int cnt;

bool check(int r, int c) {
    if(r<1 || r>N) return false;
    if(c<1 || c>N) return false;
    if(mark[r][c]) return false;
    return true;
}

void solution(){
    found = true;
    cnt++;
    for (int k = 1; k <= N*N; k++)
    {
        cout<<"("<<Xi[k]<<","<<Xj[k]<<")";
    }
    cout<<endl;
}

void Try(int k){ // current cell (Xi[k-1],Xj[k-1])
    for (int q = 0; q < 8; q++)
    {
        if (check(Xi[k-1] + di[q], Xj[k-1] + dj[q]))
        {
            Xi[k] = Xi[k-1] + di[q];
            Xj[k] = Xj[k-1] + dj[q];
            mark[Xi[k]][Xj[k]] = true;
            if(k == N*N) solution();
            else Try(k+1);
            mark[Xi[k]][Xj[k]] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>I>>J;
    Xi[1] = I;
    Xj[1] = J;
    mark[I][J] = true;
    found = false;
    cnt = 0;
    Try(2);
    cout<<cnt;

    return 0;
}