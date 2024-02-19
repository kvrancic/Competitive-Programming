#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
ll n,cnt,x[N*2],y[N*2],num[N*2],tree[N*8];
map<ll,ll> m;
bool cmp(ll a,ll b){
    return a<b;
}
ll lowbit(ll x){
    return x&(-x);
}
void update(ll x,ll k){
    while(x<=cnt){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
ll sum(ll x){
    ll ret=0;
    while(x){
        ret+=tree[x];
        x-=lowbit(x);
    }
    return ret;
}
ll find(ll x){
    if(m[x]) return m[x];
    m[x]=++cnt;
    num[cnt]=x;
    return cnt;
}
void add(ll p,ll l,ll r,ll x,ll y,ll k){
    update(x,k);
    update(y+1,-k);
    if(l==r) return;
    ll mid=(l+r)>>1;
    if(p<=mid) add(p<<1,l,mid,x,y,k);
    else add(p<<1|1,mid+1,r,x,y,k);
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x[i]=x1;y[i]=y1;
        x[i+n]=x2;y[i+n]=y2;
    }
    sort(y+1,y+1+n*2,cmp);
    cnt=unique(y+1,y+1+n*2)-y-1;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll x1=find(x[i]),y1=find(y[i]),x2=find(x[i+n]),y2=find(y[i+n]);
        add(1,1,cnt,y1,y2-1,x2-x1+1);
    }
    ll a;
    cin>>a;
    for(ll i=1;i<=cnt;i++)
        ans+=(sum(i)*(num[i+1]-num[i]));
    if(ans==a) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
