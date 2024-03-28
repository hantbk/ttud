#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9+7
#define INF 1e9+18
#define endl "\n"

int N; // number of clients
int K; // number of trucks
int Q; // capacity of each truck
int d[32]; // package size of each client
int c[32][32]; // distance between each client
int y[32]; // Diem giao dau tien cua xe thu i
int x[32]; // Diem tiep theo cua diem giao i tren lo trinh
int f = 0; // Tong do dai cua lo trinh hien tai
int f_best = INF; // Tong do dai cua lo trinh tot nhat
int load[32]; // Tai trong cua xe thu i
bool visited[32]; // Kiem tra xem client i da duoc giao chua
int nbRoutes; // So luong xe thuc su duoc lap lo trinh giao hang
int segments; // Ghi nhan so chang duong cua lo trinh
int cmin = INF; // Gia tri nho nhat cua c[i][j]

bool checkY(int v, int k){
    if (v == 0) 
        return true;
    if (load[k] + d[v] > Q) 
        return false;
    if (visited[v]) 
        return false;    
    return true;
}

bool checkX(int v, int k){
    if(v > 0 && visited[v]) 
        return false;
    if(load[k] + d[v] > Q) 
        return false;
    return true;
}

// Thu gia tri cho x[s]
void Try_X(int s, int k) {
    if (s == 0)
    {
        if (k < K)
        {
            Try_X(y[k+1], k + 1);
        }
        return;
    }
    for (int v = 0; v <= N; v++)
    {
        if (checkX(v, k))
        {
            x[s] = v; // Thu gia tri cho x[s]
            visited[v] = true;
            f = f + c[s][v]; // Cap nhat do dai lo trinh
            load[k] = load[k] + d[v]; // Cap nhat tai trong
            segments = segments + 1; // Cap nhat so chang duong
            if (v > 0) 
            {
                if (f + (N + nbRoutes - segments) * cmin < f_best)
                {
                    Try_X(v, k);
                }
            } else
            {
                if (k == K)
                {
                    if (segments == N + nbRoutes) 
                    {
                        f_best = min(f, f_best);
                    }
                } else {
                    if (f + (N + nbRoutes - segments) * cmin < f_best)
                    {
                        Try_X(y[k+1], k + 1);
                    }
                }  
            }
            // Khoi phuc lai trang thai ban dau
            visited[v] = false;
            f = f - c[s][v];
            load[k] = load[k] - d[v];
            segments = segments - 1;
        }
    }
}

// Thu gia tri cho y[k]
void Try_Y(int k)
{
    int s = 0;
    if (y[k - 1] > 0)
    {
        s = y[k - 1] + 1;
    }
    for (int v = s; v <= N; v++)
    {
        if (checkY(v, k))
        {
            y[k] = v; // Thu gia tri cho y[k]
            if (v > 0)
                segments = segments + 1;
            visited[v] = true;
            load[k] = load[k] + d[v];
            f = f + c[0][v];

            if (k < K)
            {
                Try_Y(k + 1);
            }
            else
            {
                nbRoutes = segments;
                Try_X(y[1], 1);
            }

            // Khoi phuc lai trang thai ban dau
            load[k] = load[k] - d[v];
            f = f - c[0][v];
            visited[v] = false;
            if (v > 0)
                segments = segments - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>> N >> K >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin>> d[i];
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cin>> c[i][j];
            if(c[i][j] > 0)
                cmin = min(cmin, c[i][j]);
        }
    }

    y[0] = 0;
    Try_Y(1);
    cout<< f_best << endl;

    return 0;
}
