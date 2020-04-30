/*@brief:使用两个栈实现一个队列*/
/*重要的是实现思想,代码比较容易*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class queue_stack
{
public:
	queue_stack() {}
	void transData(stack<int> &s1, stack<int> &s2);//从s1转移数据到s2
	void add(int n);//添加元素
	void poll();//弹出队列首元素
	int peek();//获取队列头元素
private:
	stack<int> stack1;//作为接收数据栈
	stack<int> stack2;//作为队列使用
};
void queue_stack::transData(stack<int> &s1, stack<int> &s2)
{
	while (!s2.empty()) s2.pop();
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
}
//保证队列首元素和栈首元素顺序相同
void queue_stack::add(int n)
{
	transData(stack2,stack1);
	stack1.push(n);
	transData(stack1, stack2);
}
void queue_stack::poll()
{
	if (!stack2.empty()) stack2.pop();
	else return;
}
int queue_stack::peek()
{
	return stack2.top();
}
int main()
{
	queue_stack qu;
	int n, x;
	string str;
	cin >> n;//多少次操作
	while (n--)
	{
		cin >> str;
		if (str == "add")
		{
			cin >> x;
			qu.add(x);
		}
		else if (str == "poll")
			qu.poll();
		else if (str == "peek")
			cout << qu.peek() << endl;
	}
	return 0;
}
