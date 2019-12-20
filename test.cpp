#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
/*你媳妇完美版!*/
ListNode *creat_ListNode()
{
	int k;
	ListNode *head = nullptr;
	ListNode *p = nullptr;
	ListNode *q = nullptr;
	/*动态创建链表*/
	while(cin>>k)
	{
		p = new ListNode(k);//c++中最好用new,malloc和new的区别面试常考
        if(head == nullptr) head = p;
		else
		{
			q->next = p;
		}
		q = p;
		if(cin.get()=='\n') break;
	}
	q->next = nullptr;
	return head;
}
void printList(ListNode *head)
{
	while(head != nullptr)
	{
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main()
{
	ListNode *head = creat_ListNode();//创建链表
	printList(head);//输出链表
	return 0;
}