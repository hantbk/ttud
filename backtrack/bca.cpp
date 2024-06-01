#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

#define MAX_M 11
#define MAX_N 35

vector<int> teacherCanTeachCourse[MAX_N]; // teacherCanTeachCourse[i][j] = k means course i can be taught by teacher k
int loadOfTeacher[MAX_M];                 // loadOfTeacher[i] = j means teacher i has j courses
int teacherOfCourse[MAX_N];               // teacherOfCourse[k] = i means course k is taught by teacher i
int m, n;                                 // n: courses, m: teachers
int minLoad = INF;
int courseConflict[MAX_N][MAX_N] = {0};

void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int numCourse;
        cin >> numCourse;
        for (int j = 1; j <= numCourse; j++)
        {
            int courseId;
            cin >> courseId;
            teacherCanTeachCourse[courseId].push_back(i);
        }
    }
    int numConflict;
    cin >> numConflict;
    for (int i = 0; i < numConflict; i++)
    {
        int u, v;
        cin >> u >> v;
        courseConflict[u][v] = courseConflict[v][u] = 1;
    }
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Course " << i << " can teach by: ";
        for (int j = 0; j < teacherCanTeachCourse[i].size(); j++)
        {
            cout << teacherCanTeachCourse[i][j] << " ";
        }
        cout << endl;
    }
}

// Kiem tra xem co the cho teacherId dạy course k hay không
bool check(int teacherId, int course_k_th)
{
    for (int i = 1; i <= n; i++)
    {
        // Kiểm tra xem course i đã được dạy chưa và có xung đột với course k không
        if (teacherOfCourse[i] == teacherId && courseConflict[i][course_k_th])
            return false;
    }
    return true;
}

void solution()
{
    int currentMaxLoad = 0;
    for (int i = 1; i <= m; i++)
    {
        currentMaxLoad = max(currentMaxLoad, loadOfTeacher[i]);
    }
    minLoad = min(minLoad, currentMaxLoad);
}

void Try(int course_k)
{
    for (int teacherId : teacherCanTeachCourse[course_k])
    {
        if (check(teacherId, course_k))
        {
            teacherOfCourse[course_k] = teacherId;
            loadOfTeacher[teacherId]++;
            if (course_k == n)
            {
                solution();
            }
            else
            {
                if (loadOfTeacher[teacherId] <= minLoad)
                    Try(course_k + 1);
            }
            teacherOfCourse[course_k] = 0;
            loadOfTeacher[teacherId]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    // print();
    Try(1);
    cout << minLoad << endl;

    return 0;
}