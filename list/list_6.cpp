/*@brief:从尾到头输出链表*/
#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* test()
{
    ListNode* head;//头指针
    ListNode *p,*q;//各个结点,移动指针
    int n;
    head = nullptr;
    while(cin>>n)
    {
        p = new ListNode();
        p->val = n;
        if(head == nullptr) head = p;
        else
        {
            q->next = p;
        }
        q = p;
        if(cin.get()=='\n') break;
    }
    q->next = NULL;
    return head;
}
//用栈的方式输出
void printList1(ListNode* head)
{
     stack<ListNode*> res;
     ListNode* listNode = head;
     while(listNode!=nullptr)
     {
         res.push(listNode);
         listNode = listNode->next;
     }
     while(!res.empty()) 
     {
         listNode=res.top();
         cout<<listNode->val<<" ";
         res.pop();
     }
     cout<<endl;
}
//递归方式实现
void printList2(ListNode* head)//printList2表示输出当前结点为头结点的逆序列
{
    if(head!=nullptr)
    {
        if(head->next!=nullptr)
          printList2(head->next);
        cout<<head->val<<" ";
    }
}
int main()
{
    ListNode* list=test();
    printList1(list);
    printList2(list);
    cout<<endl;
    return 0;
}