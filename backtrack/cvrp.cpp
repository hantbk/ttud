#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define MAX_N 20
#define MAX_K 10

int N; // So khach hang
int K; // So xe
int Q; // Tai trong cua xe

int y[MAX_K]; // y[k] la diem khach hang dau tien trong lo trinh cua xe k
int x[MAX_N]; // x[v] la diem tiep theo cua diem v
int d[MAX_N]; // d[v] la luong hang yeu cau cua khach hang v
bool visited[MAX_N];
int load[MAX_N]; // load[k] la luong hoang hoa cua cac khach hang tren lo trinh cua cac xe
int segments;

void solution(){
    for(int k = 1; k <= K; k++){
        cout<<"Route["<<k<<"]: 0";
        int v = y[k]; 
        while (v > 0)
        {
            cout<<" - "<<v;
            v = x[v];
        }
        cout<<" - 0"<<endl;
    }
    cout<<"-----------------------\n";
}

bool checkX(int v, int u, int k)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryX(int u, int k)
{ // Thu cac gia tri cho x[u] tren lo trinh xe k
    for (int v = 0; v <= N; v++)
    {
        if (checkX(v, u, k))
        {
            x[u] = v;
            visited[v] = true;
            load[k] += d[v];
            segments++;
            if (v == 0)
            {
                if (k == K)
                {
                    if (segments == N + K)
                        solution();
                }
                else
                {
                    TryX(y[k + 1], k + 1);
                }
            }
            else
            {
                TryX(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            segments--;
        }
    }
}

bool checkY(int v, int k)
{
    if (visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryY(int k)
{ // thu cac gia tri cho y[k] (y[1]<y[2]<...<y[k])
    for (int v = y[k - 1] + 1; v <= N; v++)
    {
        if (checkY(v, k))
        {
            y[k] = v;
            load[k] += d[v];
            visited[v] = true;
            segments++;
            if (k == K)
            {
                TryX(y[1], 1);
            }
            else
            {
                TryY(k + 1);
            }
            load[k] -= d[v];
            visited[v] = false;
            segments--;
        }
    }
}

void inp(){
    cin>>N>>K>>Q;
    for(int i = 1; i<= N; i++) cin>>d[i];
}

void solve(){
    for(int i = 1; i<= N; i++) visited[i] = false;
    for(int k =1; k <= K; k++) load[k] = 0;
    segments = 0;
    y[0] = 0;
    TryY(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inp();
    solve();

    return 0;
}