// Edit Distance

// Insert - (i,j-1)
// Delete - (i-1,j)
// Replace - (i-1,j-1)


Base case is important
// if first string is exhaused, we will require j+1 deletion from string 2
// if second string is exhausted, we will require i+1 deletion from string 1


//for the same problem of minimum insertion and deletion

int dp[101][101];
    int helper(string &s, string &t, int i, int j){
        if (i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = helper(s,t,i-1,j-1);
        }
        return dp[i][j] = min( 1+ helper(s,t,i,j-1),min(1 + helper(s,t,i-1,j), 1 + helper(s,t,i-1,j-1)));
    }
    int editDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return helper(s,t,s.size()-1,t.size()-1);
    }
