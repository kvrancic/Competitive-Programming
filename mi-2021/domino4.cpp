#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    
    cin >> n;
    
    int x[n];
    int height[n];
    
    for(int i=0; i<n; i++){
        
        cin >> x[i];
        cin >> height[i];
        
    }
    
    int skupina[n];
    int zadnji[n];
    
    int k = 0;
    
    skupina[0] = 0;
    zadnji[0] = 0;
    
    for(int i=1; i<n; i++){
        
        int pozTren = x[i];
        int pozPret = x[i-1];
        int visinaPret = height[i-1];
        
        if(pozTren - pozPret <= visinaPret){
            
            skupina[i] = k;
            zadnji[k] = i;
            
        } else {
            
            ++k;
            skupina[i] = k;
            zadnji[k] = i;
            
        }
    }
    
    ++k;
    int q;
    
    cin >> q;
    
    for(int i=0; i<q; i++){
       
        map<int, int> sruseni;
        
        int m;
        
        cin >> m;
        
        for(int j=0; j<m; j++) {
            
            int s;
            
            cin >> s;
            
            --s;
            
            int sSkupina = skupina[s];
            
            if(!sruseni.count(sSkupina)) {
                
                sruseni.insert({sSkupina, s});
                
            } else {
                
                if(sruseni.at(sSkupina) > s) {
                    
                    auto it = sruseni.find(sSkupina);
                    
                    it->second = s;
                    
                }
            }
        }
        
        int dosadSruseni = 0;
        
        for(auto itr = sruseni.begin(); itr != sruseni.end(); ++itr) {
            
            int indeksSkup, indeksPoz;
            
            indeksSkup = itr->first;
            indeksPoz = itr->second;
            
            int zadnjaPoz = zadnji[indeksSkup];
            
            dosadSruseni += zadnjaPoz - indeksPoz + 1;
            
        }
        
        
        cout << dosadSruseni << endl;
        
    }

    
}