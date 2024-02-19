#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n; 
    cin >> n; 
    vector<pair<int, int>> rectangles; 
    for(int i = 0; i < n; i++){
        int x,y; 
        cin >> x >> y; 
        pair <int, int> par; 
        par.first = x; 
        par.second = y; 
        rectangles.push_back(par);
    }
    // pohlepni --> gledamo je li sljedeći manji od prošloga i tjt
    int prosli = max(rectangles[0].first, rectangles[0].second);
    int i;
    for(i = 1; i < rectangles.size(); i++){ 
        if(prosli >= max(rectangles[i].first, rectangles[i].second)) prosli = max(rectangles[i].first, rectangles[i].second); 
        else if(prosli >= min(rectangles[i].first, rectangles[i].second)) prosli = min(rectangles[i].first, rectangles[i].second);
        else {cout << "NO"; return 0;}
    }
    cout << "YES"; 

    return 0;

}