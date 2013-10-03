/*
 * How would you design a stack which, in addition to push and pop,
 * also has a function min which returns the minimum element? 
 * Push, pop and min should all operate in O(1) time.
 * */
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
 * first solution: every stack node add a element to save the minimum
 * */
const int MAX_INT = ~(1<<31); //2147483647

struct node
{
	int val;
	int min;
	
	node() : val(0), min(0) {}
};

class StackWithMin
{
public:
	StackWithMin(int size=1000)
	{
		buf_ = new node[size];
		buf_[0].min = MAX_INT;
		top_pos_ = 0;
	}
	
	~StackWithMin()
	{
		delete [] buf_;
	}
	
	void push(int val)
	{
		buf_[++top_pos_].val = val;
		if(val < buf_[top_pos_ - 1].min)
			buf_[top_pos_].min = val;
		else
			buf_[top_pos_].min = buf_[top_pos_ - 1].min;
	}
	
	void pop()
	{
		top_pos_--;
	}
	
	int top()
	{
		return buf_[top_pos_].val;
	}
	
	int min()
	{
		return buf_[top_pos_].min;
	}

private:
	node* buf_;
	int top_pos_; // the position of top
};


/*
 * better solution: use a auxiliary stack to save the minimum element
 * */

class stack
{
public:
	stack(int size=1000)
	{
		buf_ = new int[size];
		cur_top_ = -1;
	}
	
	~stack()
	{
		delete [] buf_;
	}
	
	void push(int val)
	{
		buf_[++cur_top_] = val;
	}
	
	void pop()
	{
		--cur_top_;
	}
	
	int top()
	{
		return buf_[cur_top_];
	}
	
	bool empty()
	{
		return cur_top_ == -1;
	}
	
private:
	int* buf_;
	int cur_top_;
};


class StackWithMin1
{
public:
	StackWithMin1() {}
	~StackWithMin1() {}
	
	void push(int val)
	{
		s1_.push(val);
		if(val <= min())
			s2_.push(val);
	}
	
	void pop()
	{
		if(s1_.top() == min())
			s2_.pop();
			
		s1_.pop();
	}
	
	int top()
	{
		return s1_.top();
	}
	
	bool empty()
	{
		return s1_.empty();
	}
	
	int min()
	{
		if(s2_.empty())
			return MAX_INT;
		else
			return s2_.top();
	}
	
private:
	stack s1_, s2_;
};


int main()
{
	StackWithMin1 mystack;
	for(int i = 0; i < 20; ++i)
		mystack.push(i);
		
	printf("the minimum element is %d, the top element is %d\n", mystack.min(), mystack.top());
	mystack.push(-5);
	mystack.push(-5);
	printf("the minimum element is %d, the top element is %d\n", mystack.min(), mystack.top());
	mystack.pop();
	printf("the minimum element is %d, the top element is %d\n", mystack.min(), mystack.top());
	return 0;
}
