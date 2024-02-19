#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int k, n; 
    string nizString;
    vector<char> niz;
    cin >> n >> k >> ws; 
    getline(cin, nizString); 
    for(char i : nizString) niz.push_back(i);

    int l = 0; 
    int r = 1;
    int zeroes = 1 - niz[0]; //broj nula u nizu l - r u startu 
    int maximum;
    while(r < niz.size()){
        if(zeroes > k){
            if(niz[l++] == 0) zeroes--;
        }
        if(zeroes == k){
            maximum = max(maximum, r - l + 1); 
            if(niz[++r] == 0) zeroes++;
        }
        if(zeroes < k){
            if(niz[++r] == 0) zeroes++;
        }
    }

    cout << maximum;

    return 0;
    
}