#include <bits/stdc++.h> 


void sortedInsert(stack<int> &stack, int no){
	if(stack.empty() || (!stack.empty() && stack.top()<no)){
		stack.push(no);
		return;
	}

	int n = stack.top();
	stack.pop();

	//rec call
	sortedInsert(stack, no);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}


	int no = stack.top();
	stack.pop();

	//rec call
	sortStack(stack);

	sortedInsert(stack, no);
}
