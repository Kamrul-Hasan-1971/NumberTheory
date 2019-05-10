#include<bits/stdc++.h>
using namespace std;

int NOD(int a)
{
    int limit=sqrt(a+1);
    int cnt=0;
    for(int i=1; i<=limit; i++)
    {
        if(!(a%i))
        {
            cnt=cnt+2;
        }
    }
    if(limit*limit==a)
    {
        cnt--;
    }
    return cnt;
}

int main()
{
    int a,s;
    cin>>a;
    s=NOD(a);
    cout<<s<<endl;
}
