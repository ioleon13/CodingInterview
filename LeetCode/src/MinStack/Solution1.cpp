/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-6
 *      Author: liya
 *
 *  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *  push(x) -- Push element x onto stack.
 *  pop() -- Removes the element on top of the stack.
 *  top() -- Get the top element.
 *  getMin() -- Retrieve the minimum element in the stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;


class MinStack {
public:
    void push(int x) {
    	s.push(x);

    	if (min_stack.empty() || x < min_stack.top()) {
			min_stack.push(x);
		} else {
			min_stack.push(min_stack.top());
		}
    }

    void pop() {
		s.pop();
		min_stack.pop();
    }

    int top() {
    	return s.top();
    }

    int getMin() {
    	return min_stack.top();
    }

private:
    stack<int> s;
    stack<int> min_stack;
};

int main() {
	MinStack minStack;
	minStack.push(10);
	minStack.push(7);
	minStack.push(70);
	minStack.push(1);
	minStack.push(10);
	minStack.push(1);
	minStack.pop();

	printf("top is %d, min is %d\r\n", minStack.top(), minStack.getMin());
	return 0;
}




