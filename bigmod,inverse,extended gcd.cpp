#include<bits/stdc++.h>
using namespace std;

#define  ll             long long int

//https://www.youtube.com/watch?v=6KmhCKxFWOs  extended
//https://www.youtube.com/watch?v=svKA_d5CLxk&t=9s bigmood & inverse
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}
ll bigmod(ll a , ll b , ll m)
{
    if(b==0) return 1;
    if(b&1) return (a%m * bigmod(a,b-1,m))%m;
    ll x = bigmod(a,b/2,m);
    return (x*x)%m;
}
ll inverse(ll a , ll b , ll m)
{
    return ((a%m)*bigmod(b,m-2,m)%m);
}
int main()
{
    ll x,y;
    cout<<gcdExtended(15,56,&x,&y)<<endl;
    cout<<x<<" "<<y<<endl;
    cout<<bigmod(15,56,1000000007)<<endl;
    cout<<inverse(150000000000000,100000007,10000000007)<<endl;
    return 0 ;
}

