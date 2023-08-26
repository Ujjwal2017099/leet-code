class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size()==1 ){
            if(!f[0]) n--;
            
            return n<=0;
        }
        for(int i=0;i<f.size();i++){
            if(i==0 && !f[i] && !f[i+1]){
                n--;
                f[i]=1;
            }
            else if(i==f.size()-1 && !f[i] && !f[i-1]){
                n--;
                f[i]=1;
            }
            else if(i!=0 && i!=f.size()-1 && !f[i] && !f[i-1] && !f[i+1]){
                n--;
                f[i]=1;
            }
        }
        
        return n<=0;
    }
};