#include<bits/stdc++.h>
using namespace std;

int cur_num = 1;
int res = 0;
stack<int> S;
vector<int> adj[100005];
int Num[100005], Low[100005];
int N, M;

void SCC(int u, int pv){
    Low[u] = Num[u] = cur_num++;
    S.push(u);
    for(int v : adj[u]){
        //if(v == pv) continue;
        if(Num[v] == -1){
            SCC(v, u);
            Low[u] = min(Low[u], Low[v]);
        } else Low[u] = min(Low[u], Num[v]);
    }
    if(Num[u] == Low[u]){
            res++;
            while(true){
                int v = S.top();
                S.pop();
                //cout<<v<<" ";
                Low[v] = Num[v] = 1e9;
                if(v == u){
                    break;
                }
            }
            //cout<<endl;

    }
}

int main(){
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= N; i++){
        Num[i] = -1;
    }
    for(int i = 1; i <= N; i++){
        if(Num[i] == -1)  {SCC(i,i);}
    }

    cout<<res;

    return 0;
}
