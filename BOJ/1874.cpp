#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int>s;
vector<char> str;
vector<int> arr;
int n, a;

bool Func(vector<int> & arr)
{
    int num = 1 ;
    for(auto & a : arr)
    {
        if(!s.empty()&& s.top()>a) return false;
        while(s.empty() || s.top() != a)
        {
            s.push(num++);
            str.push_back('+');
        }
        s.pop();
        str.push_back('-');
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    if(Func(arr))
    {
        for(auto &c : str) cout<<c<<'\n';
    }
    else cout<<"NO";
}
