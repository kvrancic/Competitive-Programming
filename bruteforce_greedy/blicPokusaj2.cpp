#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
    int n, m, s; 
    cin >> n >> m;
    vector<int> slobodni; 
    for(int i = 0; i < m; i++){
        int x; 
        cin >> x; 
        slobodni.push_back(x);
    }
    slobodni.push_back(n + 1); 

    cin >> s; 
    int najdulji = s/2; 

    sort(slobodni.begin(), slobodni.end());

    for(int i = 0; i < slobodni.size(); i++) cout << slobodni[i] << ", "; //kontrola
    cout << endl;

    vector<int> rasponi; 
    rasponi.push_back(slobodni[0] - 1);
    for(int i = 1; i < slobodni.size(); i++){
        rasponi.push_back(slobodni[i] - slobodni[i - 1] - 1);
    }

    for(int i = 0; i < rasponi.size(); i++) cout << rasponi[i] << ", "; //kontrola
    cout << endl;

    sort(rasponi.begin(), rasponi.end());
    for(int i = rasponi.size() - 1; rasponi[i] > najdulji; i--) //izbriši sve raspone za koje odmor nije dovoljno dug
    {
        rasponi.pop_back();
    }

    for(int i = 0; i < rasponi.size(); i++) cout << rasponi[i] << ", "; //kontrola
    cout << endl;

    cout << rasponi[rasponi.size() - 2];

    

    cout << 0;
    return 0;

}