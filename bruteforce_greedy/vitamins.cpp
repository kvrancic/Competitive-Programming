#include <bits/stdc++.h>

using namespace std;

double taktika(vector<pair<double, string>> sokovi, int limit)
{
    int minimum, cijena1, cijena2, cijena3;
    set<char> slova;  
    bool postavljen = false; 
    for(auto sok1 : sokovi){
        cijena1 = sok1.first;
        for(auto sok2 : sokovi) {
            if(sok1 == sok2) cijena2 = 0; 
            else cijena2 = sok2.first; 
            for(auto sok3 : sokovi){
                if(sok1 == sok3 || sok2 == sok3) cijena3 = 0;
                else cijena3 = sok3.first; 

                auto tekst = sok1.second + sok2.second + sok3.second;
                int numUniqeChars = std::unordered_set<char>(begin(tekst), end(tekst)).size();

                if(numUniqeChars == 3)
                    if(cijena1 + cijena2 + cijena3 < minimum || !postavljen) {
                        minimum = cijena1 + cijena2 + cijena3;  
                        postavljen = true; 
                    }
            }
        }

    }
    if(!postavljen) return -1;
    return minimum; 
}

bool contains(string str, char x){
    for(int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
    for(auto c : str){
        if(c == x) return true; 
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n; 
    cin >> n;
    vector<pair<double, string>> sokovi;  
    for(int i = 0; i < n; i++){
        double x; 
        string y; 
        cin >> x >> y; 
        pair<double, string> par; 
        par.first = x; 
        par.second = y;
        sokovi.push_back(par);
    } 

    cout << taktika(sokovi, n);

}