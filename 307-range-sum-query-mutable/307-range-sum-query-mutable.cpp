const int N = 3e4+10;
class NumArray {
public:
    int seg[4*N];
    int n;
    int arr[N];
    NumArray(vector<int>& nums) {
        build(1,0,nums.size()-1,nums);
        n = nums.size()-1;
        for(int i=0;i<=n;i++) arr[i] = nums[i];
    }
    
    void update(int index, int val) {
        int a = val - arr[index];
        arr[index] = val;
        modify(index,a,0,n,1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,n,1);
    }
    void build(int node,int s,int e,vector<int>& v){
        if(s == e){
            seg[node] = v[s];
            return;
        }
        int mid = (s+e)/2;
        build(node*2,s,mid,v);
        build(node*2+1,mid+1,e,v);
        seg[node] = seg[node*2] + seg[node*2+1];
    }
    int query(int l,int r,int s,int e,int node){
        if(s>r or e<l) return 0;
        if(s>=l and e<=r){
            return seg[node];
        }
        int mid = (s+e)/2;
        return query(l,r,s,mid,node*2) + query(l,r,mid+1,e,node*2+1);
    }
    int modify(int i,int a,int s,int e,int node){
        
        if(i==s and i==e){
            seg[node]+=a;
            return a;
        }
        int mid = (s+e)/2;
        int x;
        if(i<=mid){
            x = modify(i,a,s,mid,node*2);
            seg[node] += x;
        }else{
            x = modify(i,a,mid+1,e,node*2+1);
            seg[node] += x;
        }
        
        return x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */