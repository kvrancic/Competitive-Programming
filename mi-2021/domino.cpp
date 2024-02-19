#include <bits/stdc++.h>

using namespace std;

//OVE DVIJE FUNKCIJE SU UZETE IZ MATERIJALA: https://materijali.xfer.hr/docs/upiti-nad-intervalima-1/difference-array

vector <int> initializeDiffArray(vector <int> &arr) {
    vector <int> differenceArray(arr.size(), 0);

    differenceArray[0] = arr[0];

    for(int i = 1; i < arr.size(); ++i) {
        differenceArray[i] = arr[i] - arr[i - 1];
    }

    return differenceArray;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rješenje vašeg zadatka
     int n, q; 
     vector<int> arr(n, 0); 
     int cnt = 1;
     for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        if(h >= x) cnt++;
        else cnt = 1;
        arr[i] = cnt;  
     }

    cin >> q; 
    vector<int> rjesenja; 

    for(int br = 0; br < q; br++){
        vector<int> diff = initializeDiffArray(arr);
        int suma = 0;
        int m; 
        cin >> m;

        for(int it = 0; it < m; m++){
            int x; 
            cin >> x; 
            

        }


        
    }


    return 0;
    
}