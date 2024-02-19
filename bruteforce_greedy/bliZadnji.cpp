#include <bits/stdc++.h>

using namespace std;

int broj_nula(vector<int> test){
    int brojac = 0;
    for(int c : test){
        if (c == 2) brojac++; 
    }
    //cout << "Pronadeno dvojki: " << brojac << endl;

    return brojac;
}

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

    //for(int p : maska) cout << p;
    // cout << endl;


    int duljina = 0;
    while(true){
        bool postavljen = false;
        for(int i = 0; i + duljina < maska.size(); i++)
        {
            for(int j = i + duljina + 1; j + duljina < maska.size(); j++){
                vector<int> ivector(maska.begin() + i, maska.begin() + i + duljina + 1); 
                //cout << "vektor 1: "; 
                //for(int v : ivector) cout << v << ", ";

                vector<int> jvector(maska.begin() + j, maska.begin() + j + duljina + 1);
                //cout << "vektor 2: "; 
                //for(int v : jvector) cout << v << ", ";

                if(broj_nula(ivector) + broj_nula(jvector) <= s){
                    postavljen = true; 
                    duljina++; 
                    break;
                }
            }
            if(postavljen) break;
        }
        if(!postavljen) break; 
    }

    cout << duljina;
    return 0;

}