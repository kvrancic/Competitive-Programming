#include <bits/stdc++.h>

typedef long long int llint;
using namespace std;

/* 
n heroja, ai snaga i-tog heroja 
x obrana zmaja, snaga heroja mora biti barem x da ga reši
y napad zmaja, ukupna snaga heroja barem y 
1 zlatnik za pojačavanje snage heroja 
m zmajeva u igri, i-ti ima obranu xi i napad yi 
task se rješava za svakog zmaja posebno 

prvo unosimo n(heroji), pa njihove snage ai, pa m broj zmajeva, pa obranu i napad zmajeva
isprintamo količinu integera za svakog zmaja 

*/
llint find_min(int n, vector<llint> &heroes, llint def, llint att); 

int main(){
    vector<llint> heroes; 
    map<llint, llint> dragons; 
    llint n, m, coins; 
    vector<llint> mapOrder; 

    cin >> n;
    for(int i = 0; i < n; i++){
        int a; 
        cin >> a; 
        heroes.push_back(a);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b; 
        dragons[a] = b;
        mapOrder.push_back(a);
    }    

    for (auto key : mapOrder)
    {
        cout << find_min(n, heroes, key, dragons[key]) << endl;
    } 
    
}

llint find_min(int n, vector<llint> &heroes, llint def, llint att){
    llint strongest = *max_element(heroes.begin(), heroes.end());
    llint total = reduce(heroes.begin(), heroes.end());

    /*
    sortiram jer ako lower bound pokaže na zadnji element onda to ne znači nužno da je on lower bound nego da možda i ne postoji
    u tom slučaju bih trebao nekako doznati koja je od te dvije mogućnosti, te ako ne postoji odabrati najveći broj, a ako postoji odabrati zadnji broj 
    sortiranjem vektora je najveći broj ujedno i posljednji, pa sam na taj način elegantno riješio problem 
    */

    sort(heroes.begin(), heroes.end());
    auto low = lower_bound(heroes.begin(), heroes.end(), def);

    //uvijek je rješenje ili lower bound ili onaj prije njega, ali lakše i kraće od smišljanja algoritma jest da rješimo za oba pa ih usporedimo 

    //prvo biramo najslabijeg heroja koji može pobijediti zmaja
    auto attacker1 = heroes[low - heroes.begin()];
    auto defender1 = total - attacker1; 
    llint coins1 = 0; 
    coins1 += (def - attacker1 <= 0) ? 0 : def - attacker1; 
    coins1 += (att - defender1 <= 0) ? 0 : att - defender1;

    if(low == heroes.begin())
        return coins1; 

    //zatim biramo heroja kojeg bi trebalo najmanje nadograditi da pobijedi zmaja (nikada nećemo trebati uzeti još slabijeg jer koliko uštedimo na jednoj strani ćemo potrošiti na drugoj ) 
    auto attacker2 = heroes[low - 1 - heroes.begin()];
    auto defender2 = total - attacker2; 
    llint coins2 = 0; 
    coins2 += (def - attacker2 <= 0) ? 0 : def - attacker2; 
    coins2 += (att - defender2 <= 0) ? 0 : att - defender2;

    return min(coins1, coins2); 
}