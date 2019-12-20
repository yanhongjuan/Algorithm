/*@brief:电话号码的字母组合*/
/*力扣的17题*/
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;
/*
digits:数字组合
s(digits):数字的字母组合
s(digits[0.....n-1])=letter[0]+s[digits[1......n-1]]=letter[0]+letter[1]+s(digits[2......n-1]);
*/
class Solution
{
    private:
    const string letterMap[10]={
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    //s中保存了此时从digits[0....index-1]翻译得到的一个字母字符串
    //寻找和digits[index]匹配的字母,获得digits[0...index]翻译得到的解
    void findCombination(const string &digits,int index,const string &s)
    {
         if(index == digits.size()) 
         {
              res.push_back(s);
         }
         char c = digits[index];//数字
         string letters = letterMap[c-'0'];//数字字符对应的字母
         int n = letters.size();
         for(int i=0;i<n;i++)
         {
            findCombination(digits,index+1,s+letters[i]);//当前index取不同的i时进行下一步
         }
    }
    public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if(digits.empty()) return res;
        findCombination(digits,0,"");
        return res;
    }
};
int main()
{
    Solution sol;
    vector<string> res = sol.letterCombinations("23");
    int n = res.size();
    for(int i=0;i<n;i++)
    {
       cout<<res[i]<<endl;
    }
    return 0;
}