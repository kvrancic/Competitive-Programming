#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// graf koji sadrzi ogranicenja
vector<int> graf[2000]; 
int indegree[2000]; // polje za pohranu ulaznih stupnjeva elemenata
queue<int> q; // red za pohranu elemenata koji mogu biti dodani u rezultat

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // ucitaj ogranicenja
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b); 
        indegree[b]++;
    }

    // provjeri koji se elementi mogu izvrsiti prvi
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) { 
            q.push(i);
        }
    }

    // pohrani redoslijed
    vector<int> rez;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        rez.push_back(curr); 

    // provjeri sve elemente koje je moguce izvrsiti nakon curr
    for (int susjed : graf[curr]) { 
        indegree[susjed]--; 
        if (indegree[susjed] == 0) {
            q.push(susjed);
        }
    }
}

    // ispisi rezultat
    if (rez.size() != n) {
        cout << -1 << endl;
    } else {
        for(int i=rez.size()-1;i>=0;i--)
            cout << rez[i] << " ";
        cout << endl;
    }

    return 0;
}

