class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int ans=0;
        for(int i=1;i<c.length();i++){
            priority_queue<int> pq;
            while(c[i]==c[i-1]){
                pq.push(t[i-1]);
                i++;
            }
            if(!pq.empty()){
                pq.push(t[i-1]);
                pq.pop();
                while(pq.size()){
                    ans+=pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
    
};