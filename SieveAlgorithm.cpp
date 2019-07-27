#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

bool mark[1000005];
ll nPrime;
vector<ll>allPrimeUp2N;

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
    for(i=1;i<=x;i++){
        if(mark[i]==0)allPrimeUp2N.pb(i);
    }
    nPrime = allPrimeUp2N.size();
}
