#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int n,m;
vector<int> teacher_teach[100];
bool conflict[100][100];

bool check_candidate(int i, int j){
    
}

void Try(int k){
    for (int i = 1; i <= m; i++)
    {
        
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>m>>n;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin>>k;
        int course;
        for (int j = 1; j <= k; j++)
        {
            cin>>course;
            teacher_teach[i].push_back(course);
        }
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int m,n;
        cin>>m>>n;
        conflict[m][n] = true;
        conflict[n][m] = true;
    }
    
    Try(1);

    return 0;
}
