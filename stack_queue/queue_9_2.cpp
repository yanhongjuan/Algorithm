/*@brief:使用两个队列实现栈*/
/*实现思想*/
#include <iostream>
#include <queue>
using namespace std;
template<typename T> class StackWithTwoQueue
{
    public:
    StackWithTwoQueue();
    ~StackWithTwoQueue();
    void appendTail(const T& node);
    T deleteHead();
    private:
    queue<T> que1;
    queue<T> que2;
};
template<typename T> StackWithTwoQueue<T>::StackWithTwoQueue()
{

}
template<typename T> StackWithTwoQueue<T>::~StackWithTwoQueue()
{

}
template<typename T> void StackWithTwoQueue<T>::appendTail(const T& node)
{
    if(!que1.empty()) que1.push(node);
    else
    {
         que2.push(node);
    }
}
template<typename T> T StackWithTwoQueue<T>::deleteHead()
{
    if(!que1.empty())
    {
        while(que1.size()>1)
        {
            T data = que1.front();
            que1.pop();
            que2.push(data);
        }
        if(que1.size() == 1)
         {
            T data = que1.front();
            que1.pop();
            return data;
         }
    }
    else
    {
        while(que2.size()>1)
        {
            T data = que2.front();
            que2.pop();
            que1.push(data);
        }
        if(que2.size() == 1)
         {
            T data = que2.front();
            que2.pop();
            return data;
         }
    }    
}
int main()
{
    StackWithTwoQueue<int> stack;
    stack.appendTail(1);
    stack.appendTail(2);
    stack.appendTail(3);
    stack.appendTail(4);
    stack.appendTail(5);
    int top1 = stack.deleteHead();
    int top2 = stack.deleteHead();
    int top3 = stack.deleteHead();
    int top4 = stack.deleteHead();
    int top5 = stack.deleteHead();
    stack.appendTail(99);
    stack.appendTail(42);
    stack.appendTail(53);
    int top6 = stack.deleteHead();
    int top7 = stack.deleteHead();
    int top8 = stack.deleteHead();
    cout<<top1<<" "<<top2<<" "<<top3<<" "<<top4<<" "<<top5<<" "<<top6<<" "<<top7<<" "<<top8<<endl;
}