#include <bits/stdc++.h> 


void solve(stack<int>& s, int x){
     //base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    int no = s.top();
    s.pop();

    solve(s, x);

    s.push(no);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
   solve(myStack, x);
   return myStack;
}


