#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n;
    cin >> n;
    int pos[n];
    int height[n];
    int val[n];
    int lindex[n];
    for(int i=0; i<n; i++){ 
        cin >> pos[i];
        cin >> height[i];
    } 
    int x = 0;
    val[0] = 0;
    lindex[0] = 0;
    for(int i=1; i<n; i++){
        if(pos[i] - pos[i-1] <= height[i-1]){
            val[i] = x;
            lindex[x] = i;
        } else {
            ++x;
            val[i] = x;
            lindex[x] = i;
        }
    }
    ++x;
    int q;
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
            else{
                if(rec.at(val[s]) > s){
                    rec.at(val[s]) = s; 
                }
            }

        }
        int dropped = 0;
        for(auto el : rec){
            int a = el.first;
            int b = el.second;
            int last = lindex[a];
            dropped += last - b + 1; 
        }
        cout << dropped << endl;
    }
    return 0;
}