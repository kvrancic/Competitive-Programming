#include <bits/stdc++.h>

using namespace std;

// funkcija preuzeta s https://www.codingninjas.com/codestudio/library/longest-repeating-subsequence
int longestRepeatingSubsequence(vector<int> str, int pos1, int pos2, int n, vector<vector<int>>& dp)

      {
          /*
              base case
              if pos1 or pos2 reaches n, it means there are no further 
              characters to consider, so return 0 
          */
          if(pos1 == n || pos2 == n) return 0;
          /*

              If this state is already computed, then directly return it from 
              the “dp” vector

          */
          if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
          if(pos1 != pos2 && str[pos1] == str[pos2]) return dp[pos1][pos2] = 1 + longestRepeatingSubsequence(str, pos1 + 1, pos2 + 1, n, dp);
          else return dp[pos1][pos2] = max(longestRepeatingSubsequence(str, pos1 + 1, pos2, n, dp),longestRepeatingSubsequence(str,pos1,pos2+1,n,dp));

      }

 

int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> maska(n, 0);

    for(int i = 0; i < m; i++){
        int x; 
        cin >> x; 
        maska[x - 1] = x; 
    }
    
    for(int i = 0; i < n; i++) cout << maska[i] << ", ";
    
    vector<vector<int>> dp(n + 1,vector<int>(n + 1,-1));

    cout << longestRepeatingSubsequence(maska, 0, 0, n, dp)<<endl;

    return 0;
}