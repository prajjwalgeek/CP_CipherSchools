//3. Search in the sorted matrix
//https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i = N-1, j=0;
	    
	    while(i>=0 && j < M) {
	        if(mat[i][j] > X)
	            i--;
	        else if(mat[i][j] < X)
	            j++;
	        else if(mat[i][j] == X)
	            return 1;
	    }
	    return 0;
	}
};