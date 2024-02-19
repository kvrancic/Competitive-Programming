#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

long long int lcm(int a, int b){
    return ((long long int) (a * b)) / GCD(a,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t; 

    for(int i = 0; i < t; i++){
        
    }



    return 0;

}