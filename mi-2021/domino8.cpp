#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n, q, x = 0;
    cin >> n;
    int pos[n], height[n], val[n] = {0}, lindex[n] = {0};
    for(int i=0; i<n; i++) cin >> pos[i] >> height[i];
    for(int i=1; i<n; i++){
        if(pos[i] - pos[i-1] > height[i-1]) x++;
        val[i] = x;
        lindex[x] = i;
    }
    ++x;
    vector<int> result;
    cin >> q;
    for(int i = 0; i < q; i++){
        map<int,int> rec;
        int m; 
        cin >> m;
        for(int j = 0; j < m; j++){
            int s; 
            cin >> s; 
            s--; //da se poklapa s indeksima
            if (!rec.count(val[s])) rec.insert({val[s], s});
            else if(rec.at(val[s]) > s) rec.at(val[s]) = s; 
        }
        int dropped = 0;
        for(auto el : rec){
            int a = el.first;
            int b = el.second;
            dropped += lindex[a] - b + 1; 
        }
        result.push_back(dropped);
    }
    for(auto i : result) cout << i << endl;
    return 0;
}