class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        // sort(arr.begin(),arr.end());
        sort(arr.begin(), arr.end());
        int ans = -1;
        int left = 0;
        int right = 1; // Start right pointer from the next element of left

        while (right < n) {
            int diff = arr[right] - arr[left];
            if (diff == x) {
                ans = 1;
                break;
            } else if (diff < x) {
                right++;
            } else {
                left++;
            }
            
            // Ensure left and right pointers are not the same
            if (left == right) {
                right++;
            }
        }
        return ans;
        
    }
};
