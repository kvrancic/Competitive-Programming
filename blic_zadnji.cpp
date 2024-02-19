#include<bits/stdc++.h>
using namespace std;

#define max_ind( a, b ) ( arr[tree[a]] < arr[tree[b]] ? tree[b]:tree[a] )

vector<long long> tree;
vector<long long> arr;
vector<string> num_to_name;


long n,q;

void build(long l, long r, long index) {
	//cout<<index<<' '<<l<<' '<<r<<endl;
	if(l == r) {
		tree[index] = l;
		return;
	}
	if(l > r) {
		return;
	}
	long mid = (l+r)/2;
	build(l,mid,index*2);
	build(mid+1,r, index*2+1);

	tree[index] = max_ind(index*2,index*2+1);
}

long long query(long l, long r, long ql, long qr, long index) {
	if(ql > r || l > qr) {
		return 0;
	}

	if(ql <= l and r <= qr) {
		return tree[index];
	}
	long mid = (r+l)/2;

	long left_ans = query(l,mid,ql,qr,index*2);
	long right_ans = query(mid+1,r,ql,qr,index*2+1);
	return arr[left_ans]<arr[right_ans] ? right_ans:left_ans;

}

void add(long l, long r, long index, long pos, long val) {
	if(l == r and l == pos) {
		arr[l] += val;
		return;
	}
	if(pos < l or pos > r) {
		return;
	}

	long mid = (r+l)/2;
	add(l,mid,index*2,pos,val);
	add(mid+1,r,index*2+1,pos,val);

	tree[index] = max_ind(index*2,index*2+1);
	return;
}

int main() {

	cin>>n;
	string s;
	long long num;

	arr.resize(n+10);
	tree.resize(2*n+10);
	num_to_name.resize(n+10);
	arr[0] = -1000;
	tree[0] = -1000;
	for(int i=1; i<=n; i++) {
		cin>>num>>s;
		arr[i] = num;
		num_to_name[i] = s;

	}
	build(1,n,1);

	cin>>q;
	int l,r;

	for(int i=0; i<q; i++) {
		char c;
		cin>>c;
		if(c == 'q') {
			cin>>l>>r;
			//cout<<query(1,n,l,r,1)<<endl;
			cout<<num_to_name[query(1,n,l,r,1)]<<endl;
		}
		if(c == 'c') {
			cin>>l>>r;
			add(1,n,1,l,r);
		}
	}
	
	return 0;
}
