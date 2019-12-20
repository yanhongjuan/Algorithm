/*@brief:链表中环的问题的处理*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode* create()
{
   ListNode *head;
   head = nullptr;
   ListNode *p,*q;
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
   q->next = head->next->next;
   return head;
}
/*快慢指针判断环是否存在*/
bool cur_exit(ListNode *head)
{
    if(head == nullptr) return false;
    ListNode *low = head;
    ListNode *fast = head;
    while(fast->next && fast->next->next)
    {
        low = low->next;
        fast = fast->next->next;
        if(low == fast) return true;
    }
    return false;
}
/*求得环上共有多少结点*/
//若有环,快慢指针第一次相遇后,让其中一个指针每次移动一步再次到达相遇地点即得环上结点数
int NumNode(ListNode *head)//环上共有k个结点
{
    if(head == nullptr) return 0;
    ListNode *slow = head;
    ListNode *fast = head;
    int k =1;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    while(fast->next != slow)
    {
        fast = fast->next;
        k++;
    }
    return k;
}
/*找到环的入口*/
//快指针先移动n步,然后前后两个指针同时移动,当它们相遇时即为环入口
ListNode* MeetCur(ListNode *head)
{
    int n = NumNode(head);
    ListNode* slow = head;
    ListNode* fast = head;
    for(int i=0;i<n;i++)
    {
        fast = fast->next;
    }
    while(1)
   {
       slow = slow->next;
       fast = fast->next;
       if(slow == fast) break;
   }
   return slow;
}

int main()
{
    ListNode* head = create();
    bool t = cur_exit(head);
    if(t) 
    {
        ListNode* node = MeetCur(head);
        cout<<node->val<<endl;
    }
    return 0;
}