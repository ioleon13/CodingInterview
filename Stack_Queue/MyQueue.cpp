/*
 * Implement a MyQueue class which implements a queue using two stacks.
 * */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stack>
 #include <iostream>
 
 using namespace std;
 
 //fisrt solution
 template<typename T>
 class MyQueue
 {
public:
	MyQueue()
	{}
	
	~MyQueue()
	{}
	
	void push(T val)
	{
		move(stack_out_, stack_in_);
		
		stack_in_.push(val);
	}
	
	void pop()
	{
		move(stack_in_, stack_out_);
		
		stack_out_.pop();
	}
	
	T front()
	{
		move(stack_in_, stack_out_);
		
		return stack_out_.top();
	}
	
	T back()
	{
		move(stack_out_, stack_in_);
		
		return stack_in_.top();
	}
	
	int size()
	{
		return stack_in_.size() + stack_out_.size();
	}
	
	int empty()
	{
		return stack_in_.empty() && stack_out_.empty();
	}
	
	void move(stack<T> &src, stack<T> &dst)
	{
		while(!src.empty())
		{
			dst.push(src.top());
			src.pop();
		}
	}
	
private:
	stack<T> stack_in_, stack_out_;
 };
 
 
 //efficient solution
 template <typename T>
 class MyQueue1
 {
public:
	MyQueue1(){}
	~MyQueue1(){}
	
	void push(T val)
	{
		stack_in_.push(val);
	}
	
	void pop()
	{
		if(!stack_out_.empty())
			stack_out_.pop();
		else
		{
			move(stack_in_, stack_out_);
			stack_out_.pop();
		}
	}
	
	T front()
	{
		if(!stack_out_.empty())
			return stack_out_.top();
		else
		{
			move(stack_in_, stack_out_);
			return stack_out_.top();
		}
	}
	
	T back()
	{
		if(!stack_in_.empty())
			return stack_in_.top();
		else
		{
			move(stack_out_, stack_in_);
			return stack_in_.top();
		}
	}
	
	int size()
	{
		return stack_in_.size() + stack_out_.size();
	}
	
	int empty()
	{
		return stack_in_.empty() && stack_out_.empty();
	}
	
	void move(stack<T> &src, stack<T> &dst)
	{
		while(!src.empty())
		{
			dst.push(src.top());
			src.pop();
		}
	}
private:
	stack<T> stack_in_, stack_out_;
 };
 
 int main()
 {
    MyQueue<int> q;
    MyQueue1<int> q1;
    for(int i=0; i<10; ++i)
	{
        q.push(i);
        q1.push(i);
    }

    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    q.pop();
    q1.pop();
    q.push(10);
    q1.push(10);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    cout<<q.size()<<" "<<q.empty()<<endl;
    cout<<q1.size()<<" "<<q1.empty()<<endl;        
    return 0;
}