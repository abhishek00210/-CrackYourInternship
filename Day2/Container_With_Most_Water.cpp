class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,temparea=0,areamax=0;
        while(i<j)
        {
            temparea=(j-i)*(min(height[i],height[j]));
            areamax=max(temparea,areamax);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return areamax;
        
    }
};