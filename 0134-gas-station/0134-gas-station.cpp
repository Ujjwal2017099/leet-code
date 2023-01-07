class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n = g.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = g[i]-c[i];
        }
        for(int i=0;i<n;i++){
            if(v[i]>=0){
                int j=(i+1)%n;
                int sum = v[i];
                while(j!=i){
                    sum += v[j];
                    if(sum<0){
                        if(j<i) return -1;
                        i = j;
                        break;
                    }
                    
                    j = (j+1)%n;
                }
                if(sum>=0) return i;
            }
        }
        return -1;
    }
};