#include<bits/stdc++.h>
using namespace std;

int SOD(int n)
{
    int limit = sqrt(n+1);
    int sum=0;
    for(int i=1; i<=limit; i++)
    {
        if(!(n%i))
        {
            sum=sum+i;
            sum=sum+(n/i);
        }
    }
    if(limit*limit==n)
    {
        sum=sum-limit;
    }
    return sum;
}

int main()
{
    int n,s;
    cin>>n;
    s=SOD(n);
    cout<<s<<endl;
}
