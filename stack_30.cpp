/*@brief:包含min函数的栈*/
/*使用辅助栈实现时间复杂度O(1)求得栈中最小值以及入栈出栈*/
#include <iostream>
#include <stack>
using namespace std;
template <typename T> class StackWithMin
{
    public:
    StackWithMin() {}
    virtual ~StackWithMin() {}
    T &top();
    void push(const T& value);
    void pop();
    const T& min() const;
    bool empty() const;
    size_t size() const;
    private:
    stack<T> m_data;//数据栈
    stack<T> m_min;//最小值辅助栈
};
template <typename T> void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if(m_min.size()==0 || value<m_min.top())
       m_min.push(value);
    else
    {
        m_min.push(m_min.top());
    }
}
template <typename T> void StackWithMin<T>::pop()
{
    m_data.pop();
    m_min.pop();
}
template <typename T> const T& StackWithMin<T>::min() const
{
    return m_min.top();
}
template <typename T> T& StackWithMin<T>::top()
{
    return m_data.top();
}
template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}
template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}
int main()
{
    StackWithMin<int> stack_min;
    stack_min.push(3);
    cout<<stack_min.min()<<endl;
    stack_min.push(4);
    cout<<stack_min.min()<<endl;
    stack_min.push(2);
    cout<<stack_min.min()<<endl;
    stack_min.pop();
    stack_min.push(5);
    cout<<stack_min.min()<<endl;
    stack_min.push(1);
    cout<<stack_min.min()<<endl;
}