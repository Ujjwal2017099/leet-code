class Solution {
public:
    bool isPalindrome(int x) {
        
        long long int y=0;
        
        long int z = x;
        
        if(x >= 0){
            
        
            while(z!=0){

                y = y*10 + z%10;
                
                z = z/10;
            }
            
        }
        else{
            
            return false;
        }
        
        
        if( y == x)
            return true;
        else
            return false;
        
    }
};