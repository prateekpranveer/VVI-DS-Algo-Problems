//Algorithm

// Creating HashArray and storing count to find the not appearing element
// ** if every element appears then the not appearing will be last element + 1
// declaring flag and assigning it every value that we iterate, if the value if met again the flag already consisting, then its a duplicate

// Algorithm



int *findTwoElement(int *arr, int n) {
        int *found = new int[2];
        sort(arr,arr+n);
        int maxe = arr[n-1];
        
        vector <int> v(maxe+1,0);
        
        for (int i = 0; i<n; i++){
            v[arr[i]] ++;
        }
        
        for (int i = 1; i<v.size(); i++){
            if(v[i]==0) {
                found[1] = i;
                break;
            }
            else{
                if (i == v.size()-1) found[1] = arr[n-1]+1;
            } 
        }
        int flag = -1;
        for (int i = 0; i<n; i++){
            if (arr[i]==flag) found[0] = flag;
            flag = arr[i];
        }
        
        return found;
    }
