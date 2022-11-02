class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int s = a.size()+b.size();
        vector<double> t(s);
        int x=0;
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            if(a[i]<b[j]){
                t[x] = a[i];i++;
            }else{
                t[x] = b[j];j++;
            }
            x++;
        }
        while(i<a.size()){
            t[x]=a[i];i++;x++;
        }
        while(j<b.size()){
            t[x]=b[j];j++;x++;
        }
        
        if(s&1){
            return t[s/2];
        }
        
         return (t[s/2] + t[s/2 -1])/2.0;
    }
};