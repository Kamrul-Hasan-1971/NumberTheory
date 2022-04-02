#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long int,long long int>
#define ll long long int

vector<long long int>prime;
vector<pii>v;

bool status[115];
void siveve(int N)
{
    for(int i=4; i<=N; i+=2) status[i]=1;
    for(int i=3; i*i <= N; i+=2)
        if(!status[i])
            for(int j=i*i; j <= N; j += (i*2))
                status[j]=1;
    status[1]=1;
    status[0]=1;
    prime.push_back(2);
    for(int i=3; i<=N ; i+=2)
        if(!status[i])
            prime.push_back(i);
}

void factFactorization(int r)
{
    for(int i=0;i<prime.size();i++){
        int s=r,num=0;
        while(1){
            s /= prime[i];
            num += s;
            if(s==0) break;
        }
        v.push_back({prime[i],num});
    }
}


int main()
{
    ll a,b,c,d,i,j;
    cin>>a;
    for(i=0;i<a;i++){
        scanf("%lld", &b);
        siveve(b);
        factFactorization(b);
        printf("Case %lld: %lld = %lld (%lld)",i+1,b,v[0].first,v[0].second);
        for(j=1;j<v.size();j++){
            printf(" * %lld (%lld)",v[j].first,v[j].second);
        }
        prime.clear();
        v.clear();
        printf("\n");
    }
    return 0;
}
