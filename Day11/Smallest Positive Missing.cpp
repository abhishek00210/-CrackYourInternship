class Solution
{
    public:
    
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
         sort(arr,arr+n);
        int find = 1;
        
        for(int i = 0; i < n; i++){
            
            if(arr[i] == find){
                find++;
            }
        }
        return find; 
    }
    
};