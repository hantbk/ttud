#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<char> myDeque;
    string s;
    cin >> s;

    for (char c : s)
    {
        myDeque.push_front(c);
    }

    bool match = true;
    while (myDeque.size() > 1 && match == true)
    {
        char firstChar = myDeque.front();
        myDeque.pop_front();
        char lastChar = myDeque.back();
        myDeque.pop_back();
        if (firstChar != lastChar)
        {
            match = false;
            break;
        }
    }

    if (match)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }

    return 0;
}