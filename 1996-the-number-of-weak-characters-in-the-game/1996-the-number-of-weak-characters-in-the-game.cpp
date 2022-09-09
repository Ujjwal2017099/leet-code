const int N = 1e5 + 1;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int arr[N] = {0};
        vector<priority_queue<int , vector<int> , greater<int>>> def(N);
        for(int i=0;i<p.size();i++){
            arr[p[i][0]] = max(p[i][1] , arr[p[i][0]]);
            def[p[i][0]].push(p[i][1]);
        }
        int cnt=0;
        int d=0;
        for(int i=N-1;i>=0;i--){
            if(arr[i] < d) cnt+=def[i].size();
            else if(arr[i] > 0){
                while(def[i].top() < d){
                    cnt++;
                    def[i].pop();
                }   
            }
            d = max(arr[i],d);
        }
        return cnt;
    }
};