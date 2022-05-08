
class NestedIterator {
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1 ; i>=0 ; i--)
            st.push(nestedList[i]);
    }
    
    int next() {
        hasNext();
        auto k = st.top();
        st.pop();
        
        return k.getInteger();
    }
    
    bool hasNext() {
        
        while(!st.empty())
        {
            auto k = st.top();
            if(k.isInteger()) return true;
            
            st.pop();
            vector<NestedInteger> v = k.getList();
            
            for(int i = v.size()-1 ; i >= 0 ; i--)
                st.push(v[i]);
        }
        
        return false;
    }
};

