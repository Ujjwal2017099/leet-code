class NumArray {
public:
    vector<int> t;
    NumArray(vector<int>& n) {
        t.resize(n.size()+1,0);
        partial_sum(n.begin(),n.end(),t.begin()+1);
    }
    
    int sumRange(int l, int r) {
        return t[r+1]-t[l];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */