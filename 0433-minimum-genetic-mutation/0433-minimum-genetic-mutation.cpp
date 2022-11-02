class Solution {
public:
    int minMutation(string s, string e, vector<string>& b) {
        queue<pair<string,int>> q;
        unordered_map<string,bool> mp;

        q.push({s,0});
        while(!q.empty()){
            string x = q.front().first;
            int st = q.front().second;q.pop();
            if(x==e) return st;
            for(string str:b){
                int cnt=0;
                for(int i=0;i<8;i++){
                    if(x[i]!=str[i]){
                        cnt++;
                    }
                    if(cnt>1) break;
                }
                if(cnt==1 and !mp[str]){
                    q.push({str,st+1});
                    mp[str]=1;
                }
            }
        }
        return -1;
    }
};