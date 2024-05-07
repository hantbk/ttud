#include <bits/stdc++.h>
using namespace std;

#define MAX_N 30 // Maximum number of courses
#define MAX_M 10 // Maximum number of teachers

int N;                              // Number of courses
int M;                              // Number of teachers
int teacherOfCourse[MAX_N];         // teacherOfCourse[k] = i means course k is taught by teacher i
int loadOfTeacher[MAX_M] ;     // loadOfTeacher[i] = j means teacher i has j courses to teach
vector<int> teacherCanTeach[MAX_N]; // teacherCanTeach[i][j] = k means course i can be taught by teacher k
bool conflict[MAX_N][MAX_N];        // conflict[i][j] = true means course i and course j cannot be taught by the same teacher
int resultMinLoad = INT_MAX;        // Minimum load of a teacher

int k;
int numConflict;

void input()
{
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        cin >> k; // Number of courses teacher i can teach
        int courseId;
        for (int j = 1; j <= k; j++)
        {
            cin >> courseId;
            teacherCanTeach[courseId].push_back(i); // Teacher i can teach courseId
        }
    }
    cin >> numConflict;
    for (int i = 1; i <= numConflict; i++)
    {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = conflict[b][a] = true;
    }

    // for(int i = 1; i<= N; i++){
    //     cout << "Course " << i << " can be taught by: ";
    //     for(int j = 0; j < teacherCanTeach[i].size(); j++){
    //         cout << teacherCanTeach[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << "Course " << i << " can't be taught by: ";
    //     for (int j = 1; j <= N; j++)
    //     {
    //         if (conflict[i][j])
    //         {
    //             cout << j << " ";
    //         }
    //     }
    //     cout << endl;
    // }
}

bool check(int teacherId, int courseId)
{
    for (int i = 1; i <= N; i++)
    {
        // Check if teacherId can teach course i
        if (teacherOfCourse[i] == teacherId && conflict[i][courseId])
            return false;
    }
    return true;
}

void Try(int course_k_th)
{
    for (int teacherId : teacherCanTeach[course_k_th])
    {
        if (check(teacherId, course_k_th))
        {
            // Choose teacherId to teach course_k_th
            teacherOfCourse[course_k_th] = teacherId;
            loadOfTeacher[teacherId] += 1;
            if (course_k_th == N)
            {
                // Kiem tra load cua cac giao vien trong truong hop moi
                int currentMaxLoad = 0;
                for (int i = 1; i <= M; i++)
                {
                    currentMaxLoad = max(currentMaxLoad, loadOfTeacher[i]);
                }
                // Cap nhat ket qua sao cho load cua giao vien nho nhat
                resultMinLoad = min(resultMinLoad, currentMaxLoad);
            }
            else if (loadOfTeacher[teacherId] <= resultMinLoad)
            {
                Try(course_k_th + 1);
            }
            teacherOfCourse[course_k_th] = 0;
            loadOfTeacher[teacherId] -= 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    Try(1);
    cout << resultMinLoad;

    return 0;
}