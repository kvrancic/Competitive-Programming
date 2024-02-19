#include<bits/stdc++.h>
using namespace std;

long long n,m;

vector<bool> visited;
vector<long long> dist;
vector<vector<pair<long long,long long> > > graph;
vector<long long> parent;

vector<long long> real_path;
long long real_distance = 0;

long long ans = 1e10;



pair<long long,vector<long long> > find_shortest_path(long long X) {

	visited.resize(n+10);
	dist.resize(n+10);
	parent.resize(n+10);
	for(int i=0; i<n+10; i++) {

		dist[i] = 1e14;
		visited[i] = 0;
		parent[i] = -1;

	}

	dist[1] = 0;

	priority_queue<pair<pair<long long,long long>, pair<long long,long long> > > pq; // - distance, -path l node, parent
	pq.push(make_pair(make_pair(0,0), make_pair(1,-1)));

	while(!pq.empty()) {
		pair<pair<long long,long long>, pair<long long,long long> > temp = pq.top();
		pq.pop();
		long long d = -temp.first.first;
		long long plen = -temp.first.second;
		long long node = temp.second.first;
		long long p = temp.second.second;

		if(visited[node]) {
			continue;
		}

		dist[node] = d;
		visited[node] = 1;
		parent[node] = p;

		if(node == n) {
			break;
		}
		for(long long i=0; i<graph[node].size(); i++) {
			long long t = graph[node][i].first;
			long long w = graph[node][i].second;

			if(visited[t]) {
				continue;
			}

			pq.push(make_pair(make_pair(-(d+w+X),plen+1),make_pair(t,node)));
		}
	}

	vector<long long> path;
	long long curr = n;
	while(curr != -1) {
		path.push_back(curr);
		curr = parent[curr];
	}

	return make_pair(dist[n],path);
}

void bin_search(long long low, long long high) {
	if(high < low) {
		return;
	}
	long long mid = (low + high) / 2;
	vector<long long> new_path;
	long long new_distance;
	tie(new_distance, new_path) = find_shortest_path(mid);

	if(new_distance > real_distance) {
		if(mid < ans) {
			ans = mid;
		}
		bin_search(low, mid - 1);
	}
	else {
		bin_search(mid + 1, high);
	}
}


int main() {
	cin>>n>>m;
	graph.resize(n+10);
	visited.resize(n+10);
	for(long long i=0; i<m; i++) {
		long long t1,t2,t3;
		cin>>t1>>t2>>t3;
		graph[t1].push_back(make_pair(t2,t3));
	}


	tie(real_distance,real_path) = find_shortest_path(0);

	bin_search(1,1e8);
	if(ans == 1e10 or ans == 0) {
		cout<<-1<<endl;
	}
	else {
		cout<<ans<<endl;
	}


	return 0;
}