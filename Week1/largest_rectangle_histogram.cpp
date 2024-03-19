#include<bits/stdc++.h>
using namespace std;

stack<int> hStack, pStack;
int n, h, pos, arr[100000], tempH, tempPos, tempArea, maxArea = 0;

int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (int pos = 0; pos < n; pos++)
    {
        h = arr[pos];
        if (hStack.size() == 0 || h > hStack.top())
        {
            hStack.push(h);
            pStack.push(pos);
        } else if (h < hStack.top())
        {
            while (hStack.size() > 0 && h < hStack.top())
            {
                tempH = hStack.top();
                hStack.pop();
                tempPos = pStack.top();
                pStack.pop();
                tempArea = tempH * (pos - tempPos);
                maxArea = max(maxArea, tempArea);
            }
            hStack.push(h);
            pStack.push(tempPos);       
        }
    }
    while (hStack.size() > 0)
    {
        tempH = hStack.top();
        hStack.pop();
        tempPos = pStack.top();
        pStack.pop();
        tempArea = tempH * (n - tempPos);
        maxArea = max(maxArea, tempArea);
    }
    cout<<maxArea;
    
    return 0;
}