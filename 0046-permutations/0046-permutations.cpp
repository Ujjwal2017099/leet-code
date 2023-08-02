class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& n,deque<int>& ch,vector<int>& t){
        if(ch.empty()) {
            ans.push_back(t);
            return;
        }
        
        for(int i=0;i<ch.size();i++){
            int x = ch.front();
            t.push_back(n[x]);
            // ch.erase(ch.begin()+i);
            ch.pop_front();
            fun(n,ch,t);
            t.pop_back();
            ch.push_back(x);
        }
    }
    vector<vector<int>> permute(vector<int>& n) {
        deque<int> ch;
        for(int i=0;i<n.size();i++) ch.push_back(i);
        vector<int> t;
        fun(n,ch,t);
        return ans;
    }
};