// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int size = s.length();
        vector<vector<int>> dp(size+1, vector<int>(size+1));
        for(int i=0; i<size+1; i++) {
            for(int j=0; j<size+1; j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                else if( s[i-1] == rev[j-1] ) {
                    dp[i][j]= 1+dp[i-1][j-1];
                } else {
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[size][size];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends