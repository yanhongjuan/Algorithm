/*@brief:删除链表中指定的结点*/
#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
};
/*创建单个结点*/
ListNode* createListNode(int value)
{
    ListNode *pNode = new ListNode;
    pNode->data = value;
    pNode->next = nullptr; 
    return pNode;
}
/*将结点链接起来构成单链表*/
void connectListNode(ListNode *pCur,ListNode *pNex)
{
    if(pCur == nullptr)
    {
        exit(1);//在调用处强行退出程序
    }
    pCur->next = pNex;
}
void deleteNode(ListNode *&head,ListNode *pNode)
{
    if(!head || !pNode)
      return;
    //nullptr是特殊字面值,NULL是预处理量,c++11新标准中尽量避免使用NULL
    //①当要删除的结点不是尾结点;则用下一个结点覆盖被删除结点
    if(pNode->next != nullptr)
    {
       ListNode* pNext = pNode->next;
       pNode->data = pNext->data;
       pNode->next = pNext->next;

       delete pNext;
       pNext = nullptr;
    }  
    else if(head == pNode)//②只有一个结点,头结点也是尾结点,直接删除
        {
           delete pNode;
           pNode = nullptr;
           head = nullptr;
        }
    else
    {
        //③链表中有多个结点,删除尾结点,遍历找到尾结点删除
        ListNode *pHead = head;
        while(pHead->next != pNode)
        {
            pHead = pHead->next;
        }
        pHead->next = nullptr;
        delete pNode;
        pNode = nullptr;
    }
    
}
void print(ListNode *head)
{
    while(head != nullptr)
    {
        cout<<head->data;
        head = head->next;
    }
    cout<<endl;
}
/*----------------------------测试代码---------------------------------------*/
/*情况①删除中间结点*/
void test1()
{
    ListNode *pNode1 = createListNode(1);
    ListNode *pNode2 = createListNode(2);
    ListNode *pNode3 = createListNode(3);
    ListNode *pNode4 = createListNode(4);
    ListNode *pNode5 = createListNode(5);
    ListNode *pNode6 = createListNode(6);
    connectListNode(pNode1,pNode2);
    connectListNode(pNode2,pNode3);
    connectListNode(pNode3,pNode4);
    connectListNode(pNode4,pNode5);
    connectListNode(pNode5,pNode6);
    deleteNode(pNode1,pNode4);
    print(pNode1);
}
/*情况②只有一个结点*/
void test2()
{
    ListNode *pNode1 = createListNode(1);
    deleteNode(pNode1,pNode1);
    print(pNode1);
}
/*情况③删除尾结点*/
void test3()
{
    ListNode *pNode1 = createListNode(1);
    ListNode *pNode2 = createListNode(2);
    ListNode *pNode3 = createListNode(3);
    ListNode *pNode4 = createListNode(4);
    ListNode *pNode5 = createListNode(5);
    ListNode *pNode6 = createListNode(6);
    connectListNode(pNode1,pNode2);
    connectListNode(pNode2,pNode3);
    connectListNode(pNode3,pNode4);
    connectListNode(pNode4,pNode5);
    connectListNode(pNode5,pNode6);
    deleteNode(pNode1,pNode6);
    print(pNode1);
}
int main()
{
    //test1();
    test2();
    //test3();
    return 0;
}