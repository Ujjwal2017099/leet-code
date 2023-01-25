class Solution {
public:
    int closestMeetingNode(vector<int>& e, int n1, int n2) {
        int n=e.size();
        vector<int> d1(n,-1);
        vector<int> d2(n,-1);
        d1[n1]=0;d2[n2]=0;
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);
        vis1[n1]=1;
        vis2[n2]=1;
        int stp=1;
        while(e[n1]!=-1){
            int a = e[n1];
            if(vis1[a]) break;
            vis1[a]=1;
            d1[a] = stp++;
            n1=a;
        }
        stp=1;
        while(e[n2]!=-1){
            int a = e[n2];
            if(vis2[a]) break;
            vis2[a]=1;
            d2[a] = stp++;
            n2=a;
        }
        int ans=INT_MAX;
        int dis=INT_MAX;
        for(int i=0;i<n;i++){
            if(d1[i]==-1 || d2[i]==-1) continue;
            
            if(dis > max(d1[i],d2[i])){
                dis = max(d1[i],d2[i]);
                ans = i;
            }
        }
        // for(int i:d1) cout<<i<<" ";
        // cout<<endl;
        // for(int i:d2) cout<<i<<" ";
        if(dis==INT_MAX) return -1;
        
        return ans;
    }
};