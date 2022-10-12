class Solution {
public:
    int largestPerimeter(vector<int>& n) {
        sort(n.begin(),n.end());
        int i=n.size()-1;
        while(i>=2){
            int x=n[i],y=n[i-1],z=n[i-2];
            bool ok=1;
            if(x+y<=z or x+z<=y or y+z<=x) ok=0;
            if(ok){
                return x+y+z;
            }
            i--;
        }
        return 0;
    }
};