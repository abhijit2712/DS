	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;  
	            if(i==j) matrix[i][j] = 0;
	        }
	    }
	    
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               //k represent the via 1,2,3,4,5, like waise used k
	                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    //to check if there is negative age is present or not
	    for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][j] == 1e9){
	                   matrix[i][j] = -1;
	               }
	           }
	     }
	    
	}
