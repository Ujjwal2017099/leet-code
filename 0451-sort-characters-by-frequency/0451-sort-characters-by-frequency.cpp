class Solution {
public:
    string frequencySort(string s) {
        map<char,int> arr;
        for(char c:s){
            arr[c]++;
        }
        priority_queue<vector<int>> pq;
        for(auto it:arr){
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(!pq.empty()){
            int x = pq.top()[0];
            char y = pq.top()[1];
            while(x--){
                ans += y;
            }
            pq.pop();
        }
        return ans;
    }
};