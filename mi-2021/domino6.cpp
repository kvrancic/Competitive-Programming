#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
     int n, q; 
     vector<pair<int, int>> arr; 
     cin >> n;
     for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        pair<int, int> par;
        par.first = x; 
        par.second = h; 
        arr.push_back(par);
     }

    int x = 0;
    vector<int> val;
    val.push_back(0);
    int lindex[n];
    lindex[0] = 0;
    for(int i = 1; i < n; i++){
        if(arr[i - 1].second < arr[i].first - arr[i-1].first) x++;
            val.push_back(x);
            lindex[x] = i;
       
    }
    x++;
    cin >> q;
    map<int,int> rec;
    for(int i = 0; i < q; i++){
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