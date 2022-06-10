//**Sort the vector and then check which element is not at its original position
//if element is not at its original position, then swap it with the best position that can be found, and move the pointer 1 unit back to check that element again, if it is sorted.

/*
for (int i = 0; i<v.size(); i++){
	       if (temp[i].second!=i){
	           ct++;
	           swap(temp[i], temp[temp[i].second]);
	           i--;
	       }
	   }
*/


class Solution 
{
    public:
    //Function to Swap pairs
    void swap(pair<int,int> &a, pair<int,int> &b){
        int temp;
        temp = a.first; a.first = b.first; b.first = temp;
        int temp2;
        temp = a.second; a.second = b.second; b.second = temp;
    }
  
  // There is no need to create a vector then assign it to temp and then sort the temp, the original vector can directly be copied and sorted.
 
	int minSwaps(vector<int>&nums)
	{
	   
	   vector <pair<int,int>>v;
	   for (int i = 0; i<nums.size(); i++){
	       v.push_back({nums[i],i});
	   }
	   
	   vector <pair<int,int>> temp = v;
	   sort(temp.begin(), temp.end());
	   
	   int ct = 0;
	   
	   for (int i = 0; i<v.size(); i++){
	       if (temp[i].second!=i){
	           ct++;
	           swap(temp[i], temp[temp[i].second]);
	           i--;
	       }
	   }

	   return ct;
	    // Code here
	}
};
