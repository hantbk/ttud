#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define N 1000
int n, K, Q;
int d[N];           // Luong hang yeu cau cua khach hang
int c[N][N];        // Ma tran khoang cach giua cac diem
vector<int> P[100]; // Hanh trinh cua xe
int F[100];         // Do dai hanh trinh cua xe
int load[100];      // Luong hang duoc dua tren xe
int best_result = INF;

void inp()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    d[0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];
}

// Chon xe co do dai hanh trinh nho nhat
int selectTruck()
{
    int minF = INF;
    int select = -1;
    for (int k = 1; k <= K; k++)
    {
        if (minF > F[k])
        {
            minF = F[k];
            select = k;
        }
    }
    return select;
}

// Chon khach hang co khoang cach nho nhat
int selectClient(set<int> &C, int k)
{
    int minF = INF;
    int select = -1;
    int last = P[k][P[k].size() - 1]; // Diem cuoi cung cua xe k
    for (auto i : C)
    {
        if (load[k] + d[i] <= Q)
        {
            if (minF > c[last][i])
            {
                minF = c[last][i];
                select = i;
            }
        }
    }
    return select;
}

pair<int, int> selectTruckClient(set<int> &C)
{
    int select_k = -1;
    int select_i = -1;
    int minF = INF;

    for (int k = 1; k <= K; k++)
    {
        for (auto i : C)
        {
            int last = P[k][P[k].size() - 1];
            if (load[k] + d[i] > Q)
                continue;
            int maxL = F[k] + c[last][i];
            for (int j = 1; j <= K; j++)
                if (j != k)
                {
                    if (maxL < F[j])
                        maxL = F[j];
                }
            if (minF > maxL)
            {
                minF = maxL;
                select_k = k;
                select_i = i;
            }
        }
    }
    return make_pair(select_k, select_i);
}

void init()
{
    for (int k = 1; k <= K; k++)
    {
        F[k] = 0;
        load[k] = 0;
        P[k].clear();
        P[k].push_back(0);
    }
}

void printSolution()
{
    int total_dis = 0;
    for (int k = 1; k <= K; k++)
    {
        F[k] += c[P[k][P[k].size() - 1]][0];
        P[k].push_back(0);
    }
    for (int k = 1; k <= K; k++)
    {
        // cout << "P[" << k << "] = ";
        // for (int i = 0; i < P[k].size(); i++)
        //     cout << P[k][i] << ", ";
        // cout << "Length = " << F[k] << endl;
        total_dis += F[k];
    }
    best_result = min(best_result, total_dis);
    // cout<<"Total length = "<<total_dis<<endl;
}

void greedy1()
{
    init();
    // cout << "greedy 1..." << endl;
    set<int> C;
    for (int i = 1; i <= n; i++)
        C.insert(i);
    while (C.size() > 0)
    {
        int k = selectTruck();
        int x = selectClient(C, k);
        if (x == -1)
        {
            // cout << "Cannot serve more clients " << endl;
            break;
        }
        int last = P[k][P[k].size() - 1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }
    printSolution();
}

void greedy2()
{
    init();
    // cout << "greedy 2 ..." << endl;
    set<int> C;
    for (int i = 1; i <= n; i++)
        C.insert(i);
    while (C.size() > 0)
    {
        pair<int, int> s = selectTruckClient(C);
        if (s.first == -1)
        {
            // cout << "Cannot serve more clients" << endl;
            break;
        }
        int k = s.first;
        int x = s.second;
        int last = P[k][P[k].size() - 1];
        F[k] += c[last][x];
        load[k] += d[x];
        P[k].push_back(x);
        C.erase(x);
    }
    printSolution();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inp();
    greedy1();
    greedy2();
    cout<<best_result<<endl;

    return 0;
}