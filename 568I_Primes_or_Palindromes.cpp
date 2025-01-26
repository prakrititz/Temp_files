#include<bits/stdc++.h>
using namespace std;
int a[100];
int check(int x)
{
    int ji=0;
    while(x)
    {
        a[ji++]=x%10;
        x/=10;
    }
    for(int i=0;i<ji/2;i++)
    {
        if(a[i]!=a[ji-1-i])
        return 0;
    }
    return 1;
}
int prime(int n)
{
    if(n<=1)
    return 0;
    if(n==2)
    return 1;
    if(n%2==0)
    return 0;
    int k, upperBound=n/2;
    for(k=3; k<=upperBound; k+=2)
    {
        upperBound=n/k;
        if(n%k==0)
            return 0;
    }
    return 1;
}
#define ll __int64
const int N=2e6+10;
ll p[N],h[N];
int main()
{
    for(ll i=1;i<=1200000;i++)
    {
        p[i]=p[i-1];
        h[i]=h[i-1];
        if(prime(i))
        p[i]++;
        if(check(i))
        h[i]++;
    }
    ll u,v;
    scanf("%I64d%I64d",&u,&v);
    for(int i=1200000;i>0;i--)
    if(v*p[i]<=u*h[i])
    {
        printf("%d\n",i);
        return 0;
    }
    printf("Palindromic tree is better than splay tree\n");
    return 0;
}