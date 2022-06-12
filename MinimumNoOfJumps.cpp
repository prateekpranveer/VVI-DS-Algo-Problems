//Problem GFG
//Minimum no of jumps;

class Solution{
  public:
    int minJumps(int arr[], int n){
        if (n==1) return 0;
        if (arr[0]==0) return -1;
        int maxReach = arr[0];
        int ct = 1;
        int stairs = arr[0];
        for (int i = 1; i<n; i++){
            if (i==n-1) return ct;
            maxReach = max(maxReach, i+arr[i]);
            stairs--;
            if(stairs==0){
                ct++;
                if(i>=maxReach) return -1;
                stairs = maxReach-i;
            }
        }
        // Your code here
    }
};
