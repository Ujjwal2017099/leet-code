struct comp{
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[2]>b[2];
        return a[1]>b[1];
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        int p=0;
        for(vector<int>& a:t){
            a.push_back(p);p++;
        }
        sort(t.begin(),t.end(),[&](vector<int>& a,vector<int> &b){
            if(a[0]==b[0]){
                if(a[1]==b[1]) return a[2]<b[2];
                return a[1]<b[1];
            } 
            return a[0]<b[0];
        });
        // for(auto it:t){
        //     for(int i:it) cout<<i<<" ";
        //     cout<<endl;
        // }
        priority_queue<vector<int> ,vector<vector<int>> , comp> pq;
        vector<int> ans;
        int st = t[0][0];
        // cout<<st;
        for(int i=0;i<t.size();i++){
            while(!pq.empty() && t[i][0]>st){
                vector<int> x = pq.top();pq.pop();
                ans.push_back(x[2]);
                st += x[1];
            }
            if(st < t[i][0]) st = t[i][0];
            while(i<t.size() && t[i][0]<=st){
                pq.push(t[i]);
                i++;
            }
            vector<int> x = pq.top();pq.pop();
            ans.push_back(x[2]);
            st+=x[1];
            i--;
        }
        while(!pq.empty()){
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
        return ans;
    }
};