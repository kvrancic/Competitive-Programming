#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define X first
#define Y second
#define pb push_back

bool jePovezan;
const int MAXN = 1000000;
int prufer[MAXN], prufer_correct[MAXN];
vector<ii> g[MAXN];
int n, a, b, c;
int mst = 0;
vector<vector<int>> adj;
vector<int> parent;

void dfs(int v) {
  for (int u : adj[v]) {
    if (u != parent[v]) {
      parent[u] = v;
      dfs(u);
    }
  }
}

vector<int> pruefer_code() {
  int n = adj.size();
  parent.resize(n);
  parent[n - 1] = -1;
  dfs(n - 1);

  int ptr = -1;
  vector<int> degree(n);
  for (int i = 0; i < n; i++) {
    degree[i] = adj[i].size();
    if (degree[i] == 1 && ptr == -1)
      ptr = i;
  }

  vector<int> code(n - 2);
  int leaf = ptr;
  for (int i = 0; i < n - 2; i++) {
    int next = parent[leaf];
    code[i] = next;
    if (--degree[next] == 1 && next < ptr) {
      leaf = next;
    } else {
      ptr++;
      while (degree[ptr] != 1)
        ptr++;
      leaf = ptr;
    }
  }
  return code;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int w = floor(abs(a * min(i, j) - b * max(i, j)) / c);
      if (w != 0) {
        g[i].pb({j, w});
        g[j].pb({i, w});
      }
    }
  }
  bool visited[n + 1];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;
    for (ii e : g[u]) {
      if (!visited[e.X]) {
        q.push(e.X);
      }
    }
  }
  bool connected = true;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      connected = false;
      break;
    }
  }
  jePovezan = connected;
  if (!connected) {
    return;
  }
  int parent[n + 1];
  int key[n + 1];
  bool inMST[n + 1];
  memset(parent, -1, sizeof(parent));
  memset(key, 0x3f, sizeof(key));
  memset(inMST, false, sizeof(inMST));
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, 1});
  key[1] = 0;
  while (!pq.empty()) {
    int u = pq.top().Y;
    pq.pop();
    inMST[u] = true;
    for (ii e : g[u]) {
      int v = e.X;
      int w = e.Y;
      if (!inMST[v] && key[v] > w) {
        key[v] = w;
        pq.push({key[v], v});
        parent[v] = u;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    mst += key[i];
  }
  int prufer[n - 2];
  vector<ii> mstGraph[n + 1];
  for (int i = 2; i <= n; i++) {
    mstGraph[parent[i]].pb({i, key[i]});
    mstGraph[i].pb({parent[i], key[i]});
  }
  adj.resize(n);
  for (int i = 1; i <= n; i++) {
    for (ii e : mstGraph[i]) {
      adj[i - 1].pb(e.X - 1);
    }
  }
  vector<int> prueferCode = pruefer_code();
  for (int i = 0; i < n - 2; i++) {
    prufer[i] = prueferCode[i] + 1;
  }
  for (int i = 0; i < n - 2; i++) {
    prufer_correct[i] = prufer[i];
  }
}

int main() {
  cout << "Unesite prirodan broj n: ";
  cin >> n;
  cout << "Unesite prirodan broj a: ";
  cin >> a;
  cout << "Unesite prirodan broj b: ";
  cin >> b;
  cout << "Unesite prirodan broj c: ";
  cin >> c;
  solve();
  if (jePovezan) {
    cout << "Graf G je povezan graf" << endl;
  } else {
    cout << "Graf G nije povezan graf" << endl;
    return 0;
  }
  cout << "Pruferov kod: ";
  for (int i = 0; i < n - 2; i++) {
      cout << prufer_correct[i] << " ";
    }
    return 0;
  }