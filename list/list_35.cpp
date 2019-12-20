/*@brief:复杂链表的复制*/
#include <iostream>
using namespace std;
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};
ComplexListNode *CreateNode(int nValue)
{
    ComplexListNode *pNode = new ComplexListNode();
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;
    return pNode;
}
void BuildNodes(ComplexListNode *pNode,ComplexListNode *pNext,ComplexListNode *pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}
void PrintList(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        cout<<pNode->m_nValue;
        if(pNode->m_pSibling != nullptr)
            cout<<pNode->m_pSibling->m_nValue;
        cout<<endl;
        pNode = pNode->m_pNext;
    }
}
ComplexListNode *Clone(ComplexListNode *pHead)
{
    CloneNodes(pHead);//复制节点,链表变成长链
    ConnectSiblingNodes(pHead);//第二个指针确定
    return ReconnectNodes(pHead);
}
void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;
        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;//指针的移动
    }
}
void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode *pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}
ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = nullptr;
    ComplexListNode *pClonedNode = nullptr;
    if(pNode!=nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;//先得到头结点
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while(pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}
int main()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1,pNode2,pNode3);
    BuildNodes(pNode2,pNode3,pNode5);
    BuildNodes(pNode3,pNode4,nullptr);
    BuildNodes(pNode4,pNode5,pNode2);

    ComplexListNode *pClonedHead = Clone(pNode1);
    PrintList(pClonedHead);
    return 0;
}       