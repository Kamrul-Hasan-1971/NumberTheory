#include <bits/stdc++.h>
using namespace std;
vector<long long int>v1;
#define pii pair<long long int,long long int>
#define ll long long int
vector<pii>v;


bool status[115];
void siveve(int N)
{
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2)
    {
        status[i]=1;
    }
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i)
            {
                status[j]=1;
            }
        }
    }
    status[1]=1;
    status[0]=1;
    for(int i=1; i<=N ; i++)
    {
        if(status[i]==0)
        {
            v1.push_back(i);
        }
    }

}

void factFactorization(int r)
{
    int num=0;
    for(int i=0;i<v1.size();i++){
        int s=r;
        while(1){
            s=s/v1[i];
            num=num+s;
            if(s==0){
                break;
            }
        }
        v.push_back(make_pair(v1[i],num));
        num=0;
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
        v1.clear();
        v.clear();
        printf("\n");
    }
    return 0;
}
