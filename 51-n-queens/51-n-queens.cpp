class Solution {
public:
    bool isSafe(vector<int>& t,int x,int a){
        for(int i=0;i<x;i++){
            if(t[i] == a) return 0;
        }
        int i=1;
        while(x-i>=0){
            if(t[x-i] == a-i) return 0;
            i++;
        }
        i=1;
        while(x-i>=0){
            if(t[x-i] == a+i) return 0;
            i++;
        }
        return 1;
    }
    vector<vector<int>> temp;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> t(n);
        fun(t,0);
        vector<vector<string>> ans;
        
        for(auto i:temp){
            vector<string> m(n,string(n,'.'));
            int k=0;
            for(int j:i){
                m[k][j] = 'Q';
                k++;
            }
            ans.push_back(m);
        }
        return ans;
    }
    void fun(vector<int> t,int x){
        if(x==t.size()){
            temp.push_back(t);
            return;
        }
        for(int i=0;i<t.size();i++){
            if(isSafe(t,x,i)){
                t[x] = i;
                fun(t,x+1);
            }
        }
    }
};