#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
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

ll segmentedSieve(ll a,ll b)
{
    ll i,p,j;
    bool arr[b-a+1];
    memset(arr,false,sizeof arr);

    if(a==1)
    {
        a++;
    }
    ll sqrtb=sqrt(b);

    for( i=0; i<prime.size() && prime[i]<=sqrtb; i++)
    {
        p=prime[i];
        j=p*p;
        if(j<a)
        {
            j=((a+p-1)/p)*p;
        }
        for(; j<=b; j=j+p)
        {
            arr[j-a]=true;
        }
    }

    for(i=a; i<=b; i++)
    {
        if(arr[i-a]==false)
        {
            printf("%lld \n",i);
        }
    }
    printf("\n");
}

int main()
{
    ll a,b,t;
    cin>>t;
    sieve(10000000);
    for(ll i=0; i<t; i++)
    {
        cin>>a>>b;
        segmentedSieve(a,b);
    }
    return 0;
}
