class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        fun(rooms,vis,0);
        for(int i:vis){
            if(!i) return 0;
        }
        return 1;
    }
    
    void fun(vector<vector<int>>& r,vector<int>& vis,int i){
        vis[i]=1;
        
        for(int x:r[i]){
            if(!vis[x]){
                fun(r,vis,x);
            }
        }
    }
};