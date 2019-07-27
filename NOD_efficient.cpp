#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back


bool mark[10000005];
vector<ll>prime;

void sieve(ll x)
{
    ll i,j;
    mark[1] = 1;
    for(ll i =4;i<=x;i=i+2)
        mark[i]=1;

    for(i=3;i*i<=x;i+=2)
    {
        if(!mark[i]){
            for(j=i*i;j<=x;j+=2*i)
                mark[j]=1;
        }
    }
    prime.pb(2);
    for(i=3;i<=x;i+=2){
        if(mark[i]==0)prime.pb(i);
    }
}

int NOD(ll a)
{
    ll cnt,x=1,n;

    for(ll i =0; prime[i]*prime[i]<=a; i++)
    {
        n=prime[i];
        cnt=1;
        while(a%n==0)
        {
            cnt++;
            a=a/n;
        }
        x=x*cnt;
    }
    if(a!=1)
    {
        x=x*2;
    }
    return x;
}



int main()
{

    ll a,n;
    n=2000002;
    sieve(n);
    cin>>a;
    cout<<NOD(a);
}
