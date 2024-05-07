#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define MAX_N 100
#define MAX_M 30

int N;                            // number of courses
int M;                            // number of teachers
int sizeOfCourse[MAX_N];          // sizeOfCourse[k] là số giáo viên có thể dạy môn k
vector<int> courseTeachBy[MAX_N]; // courseTeachBy[k] là tập giáo viên có thể dạy môn k
int conflictCourse[MAX_N][MAX_N]; // conflictCourse[i][j] = 1 nếu có mâu thuẫn giữa môn i và môn j
int cnt;                          // number of solutions
int X[MAX_N];                     // X[k] = v là thử phân công giáo viên v cho môn k
int maxLoad = - INF;

// Kiểm tra xem có thể phân công giáo viên v cho môn k không
bool check(int v, int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        // Kiểm tra xem có mâu thuẫn với các môn trước đó hay không vì giả thiết xếp lần lượt các môn
        // và kiểm tra xem giáo viên v đã được gán cho dạy môn khác chưa
        if (conflictCourse[i][k] && v == X[i])
            return false;
    }
    return true;
}

void solution() {
    cnt++;
    cout<<"solution "<<cnt<<endl;
    for (int t = 1; t <= M; t++)
    {
        cout<<"course of teacher "<<t<<": ";
        for(int i =1; i<= N; i++) if(X[i] == t) cout<<i<<", ";
        cout<<endl;
    }
    cout<<"-------------------"<<endl;
}

void checkMaxLoad(){
    for(int t = 1; t <= M; t++){
        int load = 0;
        for(int i = 1; i <= N; i++){
            if(X[i] == t) load++;
        }
        maxLoad = max(maxLoad, load);
    }
    if(maxLoad == - INF) cout<<-1;
    else cout<<maxLoad;
}

void Try(int k){
    for(int v = 0; v < sizeOfCourse[k]; v++){
        int teacher = courseTeachBy[k][v];
        if(check(teacher, k)){
            X[k] = teacher;
            if(k == N) {
                // solution();
                checkMaxLoad();
            }
            else Try(k+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        int courses;
        cin >> courses;
        for (int k = 1; k <= courses; k++)
        {
            int course;
            cin >> course;
            courseTeachBy[course].push_back(i);
            sizeOfCourse[course]++;
        }
    }
    int numConflicts;
    cin >> numConflicts;
    for (int i = 1; i <= numConflicts; i++)
    {
        int u, v;
        cin >> u >> v;
        conflictCourse[u][v] = conflictCourse[v][u] = 1;
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout<<conflictCourse[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout<<i<<": "<<sizeOfCourse[i]<<endl;
    // }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 0; j < courseTeachBy[i].size(); j++){
    //         cout<<"course "<<i<<" teach by "<<courseTeachBy[i][j]<<endl;
    //     }
    // }

    Try(1);

    return 0;
}