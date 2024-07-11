#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int m, n;
int loadOfTeacher[50];                 // loadOfTeacher[i] = j nghĩa là giáo viên i có j tiết dạy
int teacherOfCourse[50];               // teacherOfCourse[i] = j nghĩa là môn i được giáo viên j dạy
vector<int> teacherCanTeachCourse[50]; // teacherCanTeachCourse[i] là tập giáo viên có thể dạy môn i
int minLoad = INF;
int courseConflict[50][50]; // courseConflict[i][j] = 1 nghĩa là môn i và môn j không thể dạy cùng một giáo viên

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
    for (int i = 1; i <= numConflict; i++)
    {
        int course1, course2;
        cin >> course1 >> course2;
        courseConflict[course1][course2] = 1;
        courseConflict[course2][course1] = 1;
    }
}

bool check(int teacherId, int course_k_th)
{
    for (int i = 1; i <= n; i++)
    {
        if (teacherOfCourse[i] == teacherId && courseConflict[i][course_k_th] == 1)
            return false;
    }
    return true;
}

void Try(int k)
{
    for (int teacherId : teacherCanTeachCourse[k])
    {
        if (check(teacherId, k))
        {
            teacherOfCourse[k] = teacherId;
            loadOfTeacher[teacherId]++;
            if (k == n)
            {
                int maxLoad = 0;
                for (int i = 1; i <= m; i++)
                {
                    maxLoad = max(maxLoad, loadOfTeacher[i]);
                }
                minLoad = min(minLoad, maxLoad);
            }
            else if (loadOfTeacher[teacherId] < minLoad)
            {
                Try(k + 1);
            }
            teacherOfCourse[k] = 0;
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
    Try(1);
    cout << minLoad << endl;

    return 0;
}