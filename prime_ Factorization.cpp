bool mark[50005];
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
    prime.pb(2);
    for(i=3; i<=x; i+=2)
    {
        if(mark[i]==0)
            prime.pb(i);
    }
}

ll prime_fact( ll n )
{
    for( int i = 0 ; prime[i]*prime[i] <= n ; i++ )
    {
        if( n % prime[i] == 0 )
        {
            v1.pb(prime[i]);
            
            while( n % prime[i] == 0 )
            {
                n = n / prime[i] ;
            }
        }
    }
    if( n > 1 )
    {
        v1.pb( n ) ;
    }
}
