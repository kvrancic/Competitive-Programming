#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
map<string,int> mp;
int n,q,cnt=0,tot=0;
int tr[N*4];
string s[N];

void add(int x,int l,int r,int k){
    if(l==r){
        tr[x]++;
        return;
    }
    int mid=(l+r)/2;
    if(k<=mid) add(x*2,l,mid,k);
    else add(x*2+1,mid+1,r,k);
    tr[x]=tr[x*2]+tr[x*2+1];
}

int query(int x,int l,int r,int k){
    if(l==r){
        tr[x]--;
        return l;
    }
    int mid=(l+r)/2,ans=0;
    if(tr[x*2]>=k){
        ans=query(x*2,l,mid,k);
    }
    else{
        ans=query(x*2+1,mid+1,r,k-tr[x*2]);
    }
    tr[x]=tr[x*2]+tr[x*2+1];
    return ans;
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(!mp[s[i]]){
            tot++;
            mp[s[i]]=tot;
        }
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        if(!mp[s[i]]) continue;
        cnt++;
        add(1,1,tot,mp[s[i]]);
        mp[s[i]]=0;
    }
    while(q--){
        int k;
        cin>>k;
        cout<<s[query(1,1,tot,k)-1]<<endl;
    }
    return 0;
}
