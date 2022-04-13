class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        if(target > startValue)
        {
            while(target > startValue)
            {
                if(target % 2 != 0) {target ++; count++;}
                (target /= 2);
                count++;
            }
            while(startValue > target)
            {
                target++;
                count++;
            }
        }
        else
        {
            while(startValue > target)
            {
                target += 1;
                count++;
            }
        }
        return count;
    }
};