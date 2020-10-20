#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  all(a)         a.begin(),a.end()

bool mark[100000005];
vector<ll>prime;

void sieve(ll x)
{
    ll i,j;
    mark[1] = 1;
    for(ll i =4; i<=x; i=i+2)
        mark[i]=1;

    for(i=3; i*i<=x; i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i; j<=x; j+=2*i)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<=x; i+=2)
    {
        if(mark[i]==0)
            prime.push_back(i);
    }
}
ll ssod,sod;

void SSOD(ll a)
{
    sod=1,ssod=1;
    for(int i =0; i<prime.size() && prime[i]*prime[i]<=a; i++)
    {
        ll  n=prime[i],cnt=1;
        while(a%n==0)
        {
            cnt++;
            a=a/n;
        }
        if(cnt>1)
        {
            ll pw = 1,sum = 0;
            for (ll j=cnt; j>=1; j--)
            {
                sum += (j*pw);
                pw *= n;
            }
            pw--;
            n--;
            sod*=(pw/n);
            ssod *= sum;
        }
    }
    if(a!=1)
    {
        ll pw = 1,sum = 0;
        for (ll j=2; j>=1; j--)
        {
            sum += (j*pw);
            pw *= a;
        }
        pw--;
        a--;
        sod*=(pw/a);
        ssod *= sum;
    }
}
int main()
{
    ll  a,b,c,d,e,tc=0,f,i,j,T;
    scanf("%lld",&T);
    sieve(30000000);
    while(T--)
    {
        tc++;
        scanf("%lld",&a);
        SSOD(a);
        ll one = sod;
        ll two = ssod;
        ll x = lower_bound(all(prime),one)-prime.begin();
        ll y = upper_bound(all(prime),two)-prime.begin();
        printf("Case %lld: %lld\n",tc,y-x);
    }
    return 0 ;
}

