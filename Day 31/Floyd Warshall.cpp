//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int a=0; a<matrix.size(); a++)
	    {
	        for(int b=0; b<matrix.size(); b++)
	        {
	               
	            for(int c=0 ;c<matrix.size(); c++)
	            {
	               if(b==c)
	                matrix[b][c] = 0;
	                   
	                if(matrix[b][a]!=-1 && matrix[a][c]!=-1){
	                    if(matrix[b][c]==-1)
	                        matrix[b][c] = matrix[b][a] + matrix[a][c];
	                    else
	                        matrix[b][c] = min(matrix[b][c], matrix[b][a] + matrix[a][c]);
	                }
	            }
	        }
	    }
	}
};