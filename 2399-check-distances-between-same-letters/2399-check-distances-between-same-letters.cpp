class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        map<char,vector<int>> m;
        for(int i=0;i<s.length();i++){
            m[s[i]].push_back(i);
        }   
        for(auto it:m){
            int u = it.second[0],v=it.second[1];
            int a = d[it.first - 'a'];
            if(a != v-u-1 ) return 0;
        }
        return 1;
    }
};