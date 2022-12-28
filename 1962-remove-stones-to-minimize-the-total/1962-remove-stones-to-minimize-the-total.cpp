class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int> pq;
        int cnt=0;
        for(int i:p) {cnt+=i;pq.push(i);}
        while(k--){
            int x = pq.top();pq.pop();
            pq.push(x-x/2);
            cnt-=x/2;
        }
        return cnt;
    }
};