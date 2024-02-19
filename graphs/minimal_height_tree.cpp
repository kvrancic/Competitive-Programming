#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t; 
    vector<vector<int>> stabla;
    for(int i = 0; i < t; i++){
        int n;
        vector<int> trenutno; 
        cin >> n; 
        for(int j = 0; j < n; j++){
            int x; 
            cin >> x; 
            trenutno.push_back(x);
        }
        stabla.push_back(trenutno);
        trenutno.empty();
    }

    int height = 0; 
    for(auto stablo : stabla){
        
    }



    return 0;

}