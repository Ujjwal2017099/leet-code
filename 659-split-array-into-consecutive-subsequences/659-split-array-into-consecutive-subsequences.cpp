class Solution {
public:
    bool isPossible(vector<int>& n) {
        vector<int> length(n.size(),0);
        vector<bool> ch(n.size(),0);
        map<int , vector<int>> m;
        for(int i=0;i<n.size();i++){
            m[n[i]].push_back(i);
        }
        length[0] = 1;
        for(int i=1;i<n.size();i++){
            if(length[i]==0){
                int x = n[i]-1;
                int l=0,r=i-1;
                int mid = -1;
                while(l<=r){
                    mid = (l+r)/2;
                    if(n[mid] == x) break;
                    if(n[mid] > x) r=mid-1;
                    if(n[mid] < x) l=mid+1;
                }
                if(mid==-1 ) return 0;
                if(n[mid]!=x ) length[i] = 1;
                else if(ch[mid] == 1){
                    // bool f=0;
                    int in = -1,len = INT_MAX;
                    for(int j:m[n[mid]]){
                        if(!ch[j] and length[j]<len){
                            in = j;
                            len = length[j];
                        }
                    }
                    if(in != -1){
                        length[i] = length[in]+1;
                        ch[in] = 1;
                    }
                    else{
                        length[i] = 1;
                    }
                }
                else {
                    // bool f=0;
                    int in = -1,len = INT_MAX;
                    for(int j:m[n[mid]]){
                        if(!ch[j] and length[j]<len){
                            in = j;
                            len = length[j];
                        }
                    }
                    if(in != -1){
                        length[i] = length[in]+1;
                        ch[in] = 1;
                    }
                    else {
                        length[i] = length[mid]+1;
                        ch[mid] = 1;
                    }
                }
            }
        }
        for(int i=0;i<n.size();i++){
            if(!ch[i] and length[i] < 3) return 0;
            // cout<<length[i]<<" ";
        }
        return 1;
    }
};