/*@brief:反转链表并且输出反转链表的头结点*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode* create()
{
    int n;
    ListNode *head = nullptr;
    ListNode *p,*q;
    while(cin>>n)
    {
        p = new ListNode();
        p->val = n;
        if(head == nullptr) head = p;
        else q->next = p;
        q = p;
        if(cin.get()=='\n') break;
    }
    q->next = nullptr;
    return head;
}
ListNode* transList(ListNode *head)
{
   if(head == nullptr) return nullptr;
   ListNode *pre = nullptr;
   ListNode *current = head;
   while(current)
   {
       ListNode *next = current->next;
       if(!next) head = current;
       current->next = pre;
       pre = current;
       current = next;
   }
   return head;
}
int main()
{
    ListNode *head = create();
    ListNode *trans = transList(head);
    cout<<trans->val<<endl;
    while(trans)
    {
        cout<<trans->val<<" ";
        trans = trans->next;
    }
    cout<<endl;
    return 0;
}