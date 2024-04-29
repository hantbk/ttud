/*
    A database contains a sequence of key k1, k2, ..., kn. Perform a sequence of actions of two kinds:
    - find k: find and return 1 if k is in the database, otherwise return 0.
    - insert k: insert k into the database and return 1 if the insertion is successful, otherwise return 0.
    Input: Two blocks of information.
    - The first block contains a key of (k1, k2, ..., kn) (1 ≤ n ≤ 1000, 1 ≤ ki ≤ 1000) in each line
    - The second block contains a sequence of actions (1 ≤ m ≤ 1000) in each line. Each action is either "find k" or "insert k".
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

set<string> database;

void input() {
    string info;
    while (cin >> info) {
        if (info == "*") break;
        database.insert(info);
    }
    // for(string s : database) {
    //     cout << s << endl;
    // }
}

void query() {
    string action;
    while (cin >> action)
    {
        if (action == "***") break;
        if (action == "find")
        {
            string key;
            cin >> key;
            if (database.find(key) != database.end()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (action == "insert")
        {
            string key;
            cin >> key;
            if (database.find(key) != database.end()) cout << "0" << endl;
            else {
                database.insert(key);
                cout << "1" << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    query();

    return 0;
}