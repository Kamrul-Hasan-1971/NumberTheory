#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int

bool mark[100000005];
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
    prime.push_back(2);
    for(i=3;i<=x;i+=2){
        if(mark[i]==0)prime.push_back(i);
    }
}

ll SOD(ll a)
{
    ll sod=1;
    for(int i =0; i<prime.size() && prime[i]*prime[i]<=a; i++)
    {
        ll pw=prime[i];
        while(a%prime[i]==0)
        {
            a/=prime[i];
            pw*=prime[i];
        }
        sod*=((pw-1)/(prime[i]-1));
    }
    if(a!=1) sod*=(((a*a)-1)/(a-1));
    return sod;
}

int main()
{
    CIN;
    sieve(100000);
    ll T,a;
    cin >> T ;
    while(T--){
        cin >> a;
        cout<<SOD(a)<<endl;
    }
    return 0 ;
}

