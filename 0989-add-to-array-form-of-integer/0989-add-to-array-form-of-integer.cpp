class Solution {
public:
    vector<int> addToArrayForm(vector<int>& n, int k) {
        vector<int> t;
        while(k){
            t.push_back(k%10);k/=10;
        }
        reverse(n.begin(),n.end());
        int i=0;
        for(i=0;i<min(t.size(),n.size());i++){
            n[i] += t[i];
            int x = n[i]/10;
            n[i]%=10;
            if(n.size()==i+1 && x!=0){n.push_back(x);}
            else if(i+1<n.size()) n[i+1] += x;
        }
        
        while(i<n.size() && n[i]>9){
            int x = n[i]/10;
            n[i] %= 10;
            if(n.size()==i+1 && x!=0) n.push_back(x);
            else if(i+1<n.size()) n[i+1] += x;
            i++;
        }
        while(i<t.size()){
            n.push_back(t[i]);i++;
        }
        reverse(n.begin(),n.end());
        return n;
    }
};