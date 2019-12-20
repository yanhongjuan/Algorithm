/*@brief:链表的基本操作*/
#include <iostream>
using namespace std;
/*
*0) 动态构建单链表
*1) 单链表的反转
*2) 链表中环的检测
*3) 两个有序的链表合并
*4) 删除链表倒数第n个结点
*5) 求链表的中间结点
*/
struct ListNode
{
   int data;
   ListNode* next;
};
/*5) 求链表的中间结点*/
ListNode* mid_list(ListNode *head)
{
    if(!head) return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
/*4) 删除链表倒数第k个结点*/
ListNode* delete_list(ListNode *head,int k)
{
   if(head == NULL || k==0) return head;
   ListNode *cur = head;
   ListNode *pre = head;
   for(int i=0;i<k;i++) cur = cur->next;
   if(!cur) return head->next;
   while(cur->next)
   {
       cur  = cur->next;
       pre = pre->next;
   }
   pre->next = pre->next->next;
   return head;
}
/*3) 两个有序的链表合并*/
ListNode*  merge_list(ListNode *list1,ListNode *list2)
{
     ListNode *dummy = new ListNode;
     ListNode *cur = dummy;
     while(list1 && list2)
     {
        if(list1->data < list2->data)
        {
             cur->next = list1;
             list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
     }
     cur->next = list1 ? list1 : list2;
     return dummy->next;
}
/*          /*递归合并有序链表
ListNode*  merge_list(ListNode *list1,ListNode *list2)
{
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->data < list2->data)
    {
        list1->next = merge_list(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next = merge_list(list1,list2->next);
        return list2;
    }
}*/
/*2) 链表中环的检测*/
bool circle_list(ListNode *head)
{
     if(head == NULL) return 0;
     ListNode *slow=head, *fast=head;
     while(fast!=NULL && fast->next != NULL)
     {
         slow = slow->next;
         fast = fast->next->next;
         if(slow == fast) return 1;
     }
     return 0;
}
/*1) 单链表的反转*/
void reverse_list(ListNode *&head)
{
    if(head == NULL) return;
    ListNode *pre = NULL;
    ListNode *current = head;
    while(current)
    {
        ListNode *next = current->next;
        if(!next) head = current;
        current->next = pre;
        pre = current;
        current = next;
    }
}
/*0) 创建链表:采用的是尾插法构建不带头结点的单链表*/
/*
在用new建立一个类的对象时，若存在用户定义的默认构造函数，则new T和new T()两写法效果相同，都会调用此默认构造函数；
若未定义，new T会调用系统默认构造函数，new T()除了调用系统默认构造函数，还会给基本数据类型和指针类型的成员用0赋值，且该过程是递归的。
即若该对象的某个成员对象未定义默认构造函数，那么该成员对象的基本数据类型和指针类型的成员同样会被以0赋值。
故用new的时候请加上()
*/
ListNode* create()
{
    ListNode *head,*p1,*p2;
    head = NULL;
    int n;
    while(cin>>n)
    {
        p1 = new ListNode();//为该结点分配内存空间
        p1->data = n;
        if(head == NULL)
            head = p1;//头结点
        else
        {
            p2->next = p1;
        }
        p2 = p1;//p1是每次的活动结点,p2是当前结点
        if(cin.get() == '\n')
             break;
    }
    p2->next = NULL;
    //p2->next = head->next->next->next; //人为构造有环链表,用于测试:有环的意思就是尾指针不指向空而是指向一个结点
    return head;
}
/*输出单链表*/
void print_list(ListNode *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//--------------------------------@测试代码-----------------------------------------
/*测试单链表的创建*/
void test_create()
{
   ListNode* list = create();//测试单链表的创建
   print_list(list);//输出
}
/*测试链表反转*/
void test_reverse()
{
   ListNode* rlist = create();
   reverse_list(rlist);//链表反转
   print_list(rlist);
}
/*测试链表是否有环*/
void test_circle()
{
   ListNode* clist = create();
   bool b =1;
   b = circle_list(clist);//判断链表是否有环
   cout<<b<<endl;
}
/*测试有序链表合并*/
void test_merge()
{
   ListNode* list1 = create();
   ListNode* list2 = create();
   ListNode *mlist=merge_list(list1,list2);
   print_list(mlist);
}
/*测试删除倒数第i个结点*/
void test_delete()
{
   ListNode *ddlist = create();
   int n;
   cin>>n;
   ListNode *dlist=delete_list(ddlist,n);
   print_list(dlist);
}
/*测试求中间结点*/
void test_mid()
{
   ListNode *mmlist = create();
   ListNode *mlist = mid_list(mmlist);
   cout<<mlist->data<<endl;
}
int main()
{
  //  test_create();
  // test_reverse();
  //  test_circle();
  //  test_merge();
  //  test_delete();
    test_mid();
   return 0;
}