//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long find(int coins[], int N, int sum,int idx,vector<vector<long long>>&dp){
      if(idx==0){
          if(sum%coins[0]==0)return 1;
          return 0;
      }
      if(sum<0)return 0;
      if(sum==0)return 1;
      if(dp[idx][sum]!=-1)return dp[idx][sum];
      long long take=0,notTake=find(coins,N,sum,idx-1,dp);
      if(sum>=coins[idx])take=find(coins,N,sum-coins[idx],idx,dp);
      return dp[idx][sum]=take+notTake;
      
  }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>>dp(N,vector<long long>(sum+1,-1));
        return find(coins,N,sum,N-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends