class Solution {
public:
    bool closeStrings(string w1, string w2) {
        set<char> s1;
        set<char> s2;
        int arr[26] = {0};
        int arr2[26] = {0};
        for(char c:w1){
            s1.insert(c);
            arr[c-'a']++;
        }
        for(char c:w2){
            s2.insert(c);
            arr2[c-'a']++;
        }
        if(s1.size()!=s2.size()) return 0;
        while(!s1.empty()){
            char t1 = *(s1.begin()); s1.erase(t1);
            char t2 = *(s2.begin()); s2.erase(t2);
            if(t1!=t2) return 0;
        }
        sort(arr,arr+26);
        sort(arr2,arr2+26);
        
        for(int i=0;i<26;i++){
            if(arr[i]!=arr2[i]) return 0;
        }
        return 1;
    }
};