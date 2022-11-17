class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l1 = ax2-ax1 ;
        int b1 = ay2-ay1 ;
        
        int l2 = bx2-bx1;
        int b2 = by2-by1;
        
        int lin = 0,bin = 0;
        
        if(bx1 >= ax1 && bx1 < ax2){
            if(bx2 < ax2){
                lin = l2;
            }else{
                lin = ax2-bx1 ;
            }
        }else if(bx2 > ax1 && bx2 <= ax2){
            if(bx1 > ax1){
                lin = l2;
            }else{
                lin =  bx2-ax1 ;
            }
        }else if(ax2<=bx2 && ax1 >= bx1){
            lin = l1;
        }
        
        if(by1 >= ay1 && by1 < ay2){
            if(by2 < ay2){
                bin = b2;
            }else{
                bin =  ay2-by1 ;
            }
        }else if(by2 > ay1 && by2 <= ay2){
            if(by1 > ay1){
                bin = b2;
            }else{
                bin =  by2-ay1 ;
            }
        }else if(ay2<=by2 && ay1 >= by1){
            bin = b1;
        }
        
        
        int ans = l1*b1 + l2*b2 - lin*bin;
        
        return ans;
    }
};