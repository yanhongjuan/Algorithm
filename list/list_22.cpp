/*@brief:输出链表中倒数第k个结点*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* create()
{
      ListNode *head;
      ListNode *p,*q;
      head = nullptr;
      int n;
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
      q->next = nullptr;
      return head;
}
ListNode* k_last(ListNode* head,int k)
{
    if(head == nullptr || k==0) return nullptr;
    ListNode *p = head;
    ListNode *q = head;
    k=k-1;
    while(k)
    {
        if(p->next != nullptr)
        {p = p->next;
        k--;}
        else return nullptr;
    }
    while(p->next)
    {
        q = q->next;
        p = p->next;
    }
    return q;
}
int main()
{
    int k;
    cin>>k;
    ListNode* head = create();
    ListNode* node = k_last(head,k);
    cout<<node->val<<endl;
    return 0;
}