// Solution using 3d vector
//  Function 1 - Returns true if the Queen not under attack
//  Function 2 - Returns the 3d array that contains all the solution filled up chess board
//  Function 3 - Returns the set of columns that contains all the columns where queens were successfully placed without under attack

bool notQueenUnderAttack(int row, int col, vector<vector<int>> &chess, int n){
        int originalRow = row;
        int originalCol = col;
        
        while(row>=0 && col>=0){
            if (chess[row][col]==1) return false;
            row--;
            col--;
        }
        row = originalRow;
        col = originalCol;
        
        while(col>=0){
            if(chess[row][col]==1) return false;
            col--;
        }
        
        row = originalRow;
        col = originalCol;
        
        while(col>=0 && row<n){
            if (chess[row][col]==1) return false;
            row++;
            col--;
        }
        
        return true;
    }

    void placeQueen(int col, vector<vector<int>> &chess, vector<vector<vector<int>>> &final, int n){
        if (col==n){
            final.push_back(chess);
            return;
        }
        for (int row = 0; row<n; row++){
            if (notQueenUnderAttack(row,col,chess,n)){
                chess[row][col] = 1;
                placeQueen(col+1, chess, final, n);
                chess[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<vector<int>>> final;
        vector<vector<int>> chess(n,vector<int> (n, 0));
        placeQueen(0,chess,final,n);
        vector <vector<int>> ans(final.size());
        
        for (int i = 0; i<final.size(); i++){
            for (int j = 0; j<final[0].size(); j++){
                for (int k = 0; k<final[0][0].size(); k++){
                    if (final[i][j][k] == 1){
                        ans[i].push_back(k+1);
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
