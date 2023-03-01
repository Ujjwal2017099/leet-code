class Solution {
public:
    vector<int> sortArray(vector<int>& v) {
        int l=0,r=v.size()-1;
        int md=(l+r)/2;
        fun(v,l,r);
        // int x=md+1;
        // int s=l,e=r;
        // vector<int> t;
        // // for(int i:v) cout<<i<<" ";
        // // cout<<endl;
        // while(l<=md && x<=r){
        //     if(v[l]<=v[x]) {t.push_back(v[l]); l++;}
        //     else {t.push_back(v[x]);x++;}
        // }
        // while(l<=md){
        //     t.push_back(v[l]);l++;
        // }
        // while(x<=r){
        //     t.push_back(v[x]);x++;
        // }
        // for(int i=s;i<=e;i++) v[i]=t[i-s];
        
        return v;
    }
    void fun(vector<int>& v,int l,int r){
        if(l>=r) return;
        int md=(l+r)/2;
        fun(v,l,md);
        fun(v,md+1,r);
        int x=md+1;
        int s=l,e=r;
        vector<int> t;
        while(l<=md && x<=r){
            if(v[l]<=v[x]) {t.push_back(v[l]); l++;}
            else {t.push_back(v[x]);x++;}
        }
        while(l<=md){
            t.push_back(v[l]);l++;
        }
        while(x<=r){
            t.push_back(v[x]);x++;
        }
        for(int i=s;i<=e;i++) v[i]=t[i-s];
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
    }
};