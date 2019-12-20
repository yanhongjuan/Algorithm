/*@brief:合并两个有序链表*/
#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
};
ListNode* create()
{
    int k;
    ListNode *head = nullptr;
    ListNode *p,*q;
    while(cin>>k)
    {
        p = new ListNode();
        p->val = k;
        if(head == nullptr) head = p;
        else
        {
            q->next = p;
        }
        q=p;
        if(cin.get()=='\n') break;
    }
    q->next = nullptr;
    return head;
}
//递归法
ListNode* merge_list(ListNode *p1,ListNode *p2)
{
    if(p1 == nullptr) return p2;
    if(p2 == nullptr) return p1;
    ListNode *pMergeHead = nullptr;
    if(p1->val < p2->val) 
    {
        pMergeHead = p1;
        pMergeHead->next = merge_list(p1->next,p2);
    }
    else
    {
        pMergeHead = p2;
        pMergeHead->next = merge_list(p1,p2->next);
    }
    return pMergeHead;
}
//迭代法
ListNode* merge_list2(ListNode *p1,ListNode *p2)
{
    ListNode *cur = new ListNode();
    ListNode *pre = cur;
    while(p1!=nullptr && p2!=nullptr)
    {
        if(p1->val < p2->val)
        {
             pre->next = p1;
             p1 = p1->next;
        }
        else
        {
            pre->next = p2;
            p2 = p2->next;
        }  
        pre = pre->next; 
    }
    pre->next = p1?p1:p2;
    return cur->next;
}
int main()
{
   ListNode *p1 = create();
   ListNode *p2 = create();
   //ListNode *p3 = merge_list(p1,p2);
   ListNode *p3 = merge_list2(p1,p2);
   ListNode *head = p3;
   while(head)
   {
       cout<<head->val<<" ";
       head = head->next;
   }
   cout<<endl;
   return 0;
}