class Solution {
public:
    int arr[26];
    bool equationsPossible(vector<string>& e) {
        for(int i=0;i<26;i++){
            arr[i] = i;
        }
        
        for(auto i:e){
            char c=i[1];
            if(c=='='){
                Union(min(i[0]-'a',i[3]-'a'),max(i[0]-'a',i[3]-'a'));
            }
        }
        for(int i=0;i<26;i++){
            arr[i] = find(arr[i]);
        }
        for(int i:arr) cout<<i<<" ";
        for(auto i:e){
            char c=i[1];
            if(c=='!'){
                int x=i[0]-'a' , y=i[3]-'a';
                if(arr[x]==arr[y] or arr[y]==x or x==y) return 0;
            }
        }
        return 1;
    }
    void Union(int a,int b){
        int x=find(a);
        int y=find(b);
        
        x>=y?arr[y]=x:arr[x]=y;
    }
    int find(int a){
        if(arr[a]==a) return a;
        
        return arr[a] = find(arr[a]);
    }
};