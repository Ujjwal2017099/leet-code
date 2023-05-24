class Solution {
public:
    int removeElement(vector<int>& n, int v) {
        deque<int> t;
        int ans=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==v) t.push_back(i);
            if(n[i]!=v){
                ans++;
                if(!t.empty()){
                    swap(n[i],n[t.front()]);t.pop_front();
                    t.push_back(i);
                }
            }
        }
        return ans;
    }
};