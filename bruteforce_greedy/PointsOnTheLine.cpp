#include <bits/stdc++.h>

using namespace std;

int diameter(vector<int> niz, int limit)
{
    int minimum;
    bool postavljen = false; 
    for(int i=0; i < niz.size(); i++){
        for(int j = i + 1; j < niz.size(); j++){
            int result = 0; 
            int manji = min(niz[i], niz[j]); 
            int veci = max(niz[i], niz[j]);
            if(veci - manji > limit) continue; 
            for(int k = 0; k < niz.size(); k++)
                if(niz[k] > veci || niz[k] < manji) result++;
            if(!postavljen){
                postavljen = true; 
                minimum = result;
            }
            if(result < minimum) minimum = result;
        }
    }
    if(!postavljen) return niz.size() - 1;
    return minimum; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n, x; 
    cin >> n >> x;
    vector<int> niz; 
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        niz.push_back(x); 
    } 

    cout << diameter(niz, x);

}