#include <bits/stdc++.h>

using namespace std;

bool test(vector<int> maska, int duljina, int n, int praznici, int slobodni);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n, m, s; 
    cin >> n >> m;
    vector<int> maska(n, 2);

    for(int i = 0; i < m; i++){
        int x; 
        cin >> x; 
        maska[x - 1] = 1; 
    }

    cin >> s;


    int radni_dani = 0; // ovom mehanikom dijelimo slozenost s n (zasluge kolegama koji su me uputili na 5. lekciju) 
    for(int i = 0; i < maska.size(); i++){
        if(maska[i] == 2){
            ++radni_dani; 
            maska[i] = radni_dani - 1;
        } else maska[i] = radni_dani;
    }

    //for(int i : maska) cout << i<< ", ";

    //koristiti binary search da se smanji i slozenost 
    int l = 0; 
    int r = n; 
    int mid;
    int rjesenje;
    while(l != r){
        if(test(maska, mid, n, m, s)) //trazimo postoji li veci najdulji
        {
            rjesenje = mid; 
            l = mid + 1;    
            mid = (l + r) / 2; 
        }
        else{
            r = mid;  
            mid = (l + r) / 2;
        }
    }

    cout << rjesenje; 
    return 0;

}

bool test(vector<int> maska, int duljina, int n, int praznici, int slobodni){
    int limit;
    for(int i = 0; i + duljina < n; i++){
        for(int j = i + duljina; j + duljina <= n; j++){
            limit = maska[i + duljina] - maska[i] + maska[j + duljina] - maska[j];
            if((limit <= slobodni) && (n >= praznici + slobodni)) return true;
        }
    }
    return false; 
}