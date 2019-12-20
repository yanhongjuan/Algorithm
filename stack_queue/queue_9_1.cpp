/*@brief:使用两个栈实现一个队列*/
/*重要的是实现思想,代码比较容易*/
#include <iostream>
#include <stack>
using namespace std;
template<typename T> class QueueWithTwoStack
{
  public:
    QueueWithTwoStack();
    ~QueueWithTwoStack();
    void appendTail(const T& node);
    T deleteHead();
  private:
    stack<T> stack1;
    stack<T> stack2;
};
template<typename T> QueueWithTwoStack<T>::QueueWithTwoStack()
{

}
template<typename T> QueueWithTwoStack<T>::~QueueWithTwoStack()
{

}
template<typename T> void QueueWithTwoStack<T>::appendTail(const T& node)
{
     stack1.push(node);
}
template<typename T> T QueueWithTwoStack<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size()>0)
        {
            T &tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}
int main()
{
    QueueWithTwoStack<char> queue; 
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    char head1 = queue.deleteHead();
    char head2 = queue.deleteHead();
    char head3 = queue.deleteHead();
    cout<<head1<<" "<<head2<<" "<<head3<<endl;
}