class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0 ,indexl = 0 , indexr = 0;
        while(i < j)
        {
            if(min(height[i] , height[j]) * (j-i) > max * (indexr-indexl))
            {
                max = min(height[i],height[j]);
                indexl = i;
                indexr = j;
            }
            if(height[i] < height[j]) i++;
            else j--;
        }
        
        int length = indexr-indexl;
        
        return length*max;
    }
};