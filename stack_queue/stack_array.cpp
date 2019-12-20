/*顺序栈的实现:①采用类模板的方式实现存储任意类型的数据 ②采用数组的栈,支持动态扩容*/
#include <iostream>
using namespace std;

template <class T> class ArrayStack//这里的class也可以替换为typename
{
public:
    ArrayStack();
    ArrayStack(int count);
    ~ArrayStack();//析构函数没有参数,没有返回值,不能重载,一个类中有且只有一个析构函数
    void push(T data);     //入栈
    T pop();      //出栈，并删除栈顶元素
    T peek();     //返回栈顶元素，不删除栈顶元素，栈顶指针不变
    int stackSize();
    int stackMaxSize();

private:
    int flag;       //栈顶标签，指向栈顶
    int count;     //栈的容量
    T *array;       //指针
};
//构造函数创建栈
template<class T> ArrayStack<T>::ArrayStack()
{
    this->count = 10;
    this->flag = 0;
    this->array = new T[this->count];
    if(!this->array)
        cout<<"array malloc memory failure"<<endl;
}
//有参构造函数
template<class T> ArrayStack<T>::ArrayStack(int count)
{
    this->count = count;
    this->flag = 0;
    this->array = new T[this->count];
    if(!this->array)
      coout<<"array malloc memory failure"<endl;
}
//析构函数摧毁栈
template<class T> ArrayStack<T>::~ArrayStack()
{
    this->count = 0;
    this->flag = 0;
    if(this->array)
    {
        delete []this->array;
        this->array = nullptr;
    }
}
//入栈
template<class T> void ArrayStack<T>::push(T data)
{
    //支持动态扩容,每次扩容1.5倍,初始栈大小是10
    if(this->flag == this->count)
    {
        cout<<"the stack is full,so need to enlarge 1.5x"<<endl;
        this->count = int(1.5*this->count);
        T* temp = new T[this->count];
        for(int i = 0;i<this->flag;i++)
            temp[i] = this->array[i];//把之前的数据存储 
    delete [] this->array;//释放原来的空间
    temp[this->flag] = data;
    temp->flag++;
    this->array = temp;
    }
    else
    {
        this->array[this->flag] = data;
        this->flag++;
    }  
}
//出栈,并删除栈顶元素
template<class T> T ArrayStack<T>::pop()
{
    this->flag--;//删除栈顶元素
    T temp = this->array[this->flag];
    return temp;
}
//出栈,不删除栈顶元素
template<class T> T ArrayStack<T>::peek()
{
    T temp = this->array[this->flag-1];//flag从0开始
    return temp;
}
template<class T> int ArrayStack<T>::stackSize()
{
    return this->flag;
}
template<class T> int ArrayStack<T>::stackMaxSize()
{
    return this->count;
}

int main()
{
    ArrayStack<int> arraystack(5);
    arraystack.push(10);
    arraystack.push(12);
    arraystack.push(10);
    arraystack.push(15);
    arraystack.push(30);
    arraystack.push(15);
    arraystack.push(15);
    cout<<"peek,no delete"<<arraystack.peek()<<endl;
    cout<<"pop,delete"<<arraystack.pop()<<endl;
    arraystack.push(85);
    arraystack.push(75);
    cout<<"peek,no delete"<<arraystack.peek()<<endl;
    cout<<"pop,delete"<<arraystack.pop()<<endl;
    return 0;
}