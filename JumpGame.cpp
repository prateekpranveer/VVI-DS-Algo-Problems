//For every element find the maximum position you can jump


int canReach(int A[], int N) {
       int maxpos = 0;
       for (int i = 0; i<N; i++){
           maxpos = max(maxpos, A[i]+i);
           if (maxpos == i) break;
       }
       
       if(maxpos>=N-1) return 1;
       else return 0;
        // code here
    }
