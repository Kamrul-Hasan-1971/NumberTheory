#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back


vector<ll>v;
bool prime[2000006];

void findPrime(ll n)
{
    for(ll i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }


    for(ll i=3; i*i<=n; i+=2)
    {
        if(!prime[i])
        {
            for(ll j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(ll i=2; i<=n; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
}

int NOD(ll a)
{
    ll cnt,x=1,n;

    for(ll i =0; v[i]*v[i]<=a; i++)
    {
        n=v[i];
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
    findPrime(n);
    cin>>a;
    cout<<NOD(a);
}
