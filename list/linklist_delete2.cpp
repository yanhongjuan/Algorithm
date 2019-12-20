/*@brief:链表实现之:在排好序的链表中删除所有重复的结点,这里的已排序很重要*/
#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
};
void DeleteDuplication(ListNode** pHead)//这里不能使用一级指针,因为当删除头结点时就会出错,一级指针只是对该指针指向的变量操作,实参不会删除该指针
{
    if(pHead == nullptr)
      return;
    ListNode* preNode = nullptr;//当前结点的前一个结点
    ListNode* pNode = *pHead;//当前结点
    while(pNode != nullptr)
    {
        ListNode* pNext = pNode->next;//下一个结点
        bool needDelete = false;//删除标志位
        if(pNext != nullptr && pNext->val == pNode->val) needDelete = true;
        else
        {
            preNode = pNode;
            pNode = pNode->next;
        }
        //删除操作
        if(needDelete == true)
        {
            int value = pNode->val;
            ListNode* pToBeDel = pNode;//需要一个中间结点进行删除
            while(pToBeDel != nullptr && pToBeDel->val == value)
            {
                pNext = pToBeDel->next;
                delete pToBeDel;//删除用delete,因为是通过new创建
                pToBeDel = nullptr;
                pToBeDel = pNext;
            }
            if(preNode == nullptr)//头结点重复被删除
                 *pHead = pNext;
            else
            {
                preNode->next = pNext;
            }
            pNode = pNext;
        }
    }
}
ListNode* CreateListNode(int val)
{
     ListNode *p = new ListNode;
     p->val = val;
     p->next = nullptr;
     return p;
}
void ConnectListNode(ListNode* p1,ListNode* p2)
{
    if(p1 == nullptr)
    {
        exit(1);
    }
    p1->next = p2;
}
void outList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void DestroyList(ListNode* head)
{
    ListNode* pNode = head;
    while(pNode != nullptr)
    {
        head = head->next;
        delete pNode;//这里每个结点都是通过new的方式创建的,所以为了避免内存泄露,最后通过delete释放内存
        pNode = head;
    }
}
/*---------------------------测试代码------------------------------------*/
void test2()
{
    ListNode* pNode1 = CreateListNode(2);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    ConnectListNode(pNode3,pNode4);
    ConnectListNode(pNode4,pNode5);
    ConnectListNode(pNode5,pNode6);
    ConnectListNode(pNode6,pNode7);
    DeleteDuplication(&pNode1);
    outList(pNode1);
    DestroyList(pNode1);
}
//②测试重复结点不在头结点处
void test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    ConnectListNode(pNode3,pNode4);
    ConnectListNode(pNode4,pNode5);
    ConnectListNode(pNode5,pNode6);
    ConnectListNode(pNode6,pNode7);
    DeleteDuplication(&pNode1);
    outList(pNode1);
}
int main()
{
    test1();
    test2();
    return 0;
}