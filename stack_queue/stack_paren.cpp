/*@brief:栈实现括号匹配*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool paren(string st)
{
    stack<char> left;//栈中存放左括号
    int n = st.size();
    for(int i=0;i<n;i++)
    {
        switch(st[i])
    {
        case '(':left.push(st[i]);break;
        case '[':left.push(st[i]);break;
        case '{':left.push(st[i]);break;
        case ')':if(left.empty() || left.top() != '(') return false;else left.pop();break;
        case ']':if(left.empty() || left.top() != '[') return false;else left.pop();break;
        case '}':if(left.empty() || left.top() != '{') return false;else left.pop();break;
        default:break;//对非括号项跳过不处理
    }
    }
    return left.empty();
}
int main()
{
    string st;
    cin>>st;
    bool pan = false;
    pan = paren(st);
    cout<<pan<<endl;
    return 0;
}