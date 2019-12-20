/*采用链表实现栈*/
#include <iostream>
using namespace std;
template<class T> class LinkListStack
{
public:
    LinkListStack();
    ~LinkListStack();
    void push(const T & data);
    T peek();
    T pop();
    int size() const;//返回栈的大小,const修饰类的成员函数放置在末尾,在调用该函数时不能修改类或者对象的属性
private:
    int count;//存放栈的大小
    struct LinkedNode
    {
        T data;
        LinkedNode* next;
    };
    LinkedNode* head;//单链表的头指针,带头结点??
};
template<class T> LinkListStack<T>::LinkListStack()
{
      this->count = 0;
      this->head = new LinkNode;
      this->head->next = nullptr;
}
template<class T> LinkListStack<T>::~LinkListStack()
{
    LinkedNode *ptr,*temp;
    ptr = head;
    while(ptr->next != nullptr)
    {
        temp = ptr->next;
        ptr->next  = temp->next;
        delete temp;
    }
    delete head;
    this->head = nullptr;
    this->count = 0;
}
template<class T> void LinkListStack<T>::push(const T& data)//头插法
{
      LinkedNode* insertPtr = new LinkedNode;
      insertPtr->data = data;
      insertPtr->next = this->head->next;
      head->next = insertPtr;
      this->count++;    
}
template<class T> T LinkListStack<T>::peek()
{
    if(this->count == 0 || this->head->next == nullptr)
      return nullptr;
    else
    {
        return this->head->next->data;
    }   
}
template<class T> T LinkListStack<T>::pop()
{
    if(this->count == 0 || this->head->next == nullptr)
      return nullptr;
    else
    {
        LinkedNode* temp = this->head->next;
        this->head->next = temp->next;
        T data = temp->data;
        delete temp;
        this->count--;
        return data;
    } 
}
template<class T> int LinkListStack<T>::size() const
{
    return this->count;
}
int main()
{
    LinkListStack<float> stack;
    stack.push(10.1);
    stack.push(10.1);
    stack.push(10.1);
    stack.push(10.1);
    stack.push(10.1);
    stack.push(10.1);
    cout<<stack.peek()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.size()<<endl;
}