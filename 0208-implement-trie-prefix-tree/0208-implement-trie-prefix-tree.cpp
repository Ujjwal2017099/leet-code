class Node{
public:
    Node* arr[26];
    bool eow;
    Node(){
        eow=0;
        for(int i=0;i<26;i++) arr[i] = nullptr;
    }
};
class Trie {
public:
    Node* x;
    Trie() {
        x = new Node();
    }
    
    void insert(string word) {
        Node* ptr = x;
        for(char& c:word){
            if(ptr->arr[c-'a']) ptr = ptr->arr[c-'a'];
            else {
                ptr->arr[c-'a'] = new Node();
                ptr = ptr->arr[c-'a'];
            }
        }
        ptr->eow=1;
    }
    
    bool search(string word) {
        Node* ptr = x;
        
        for(char& c:word){
            if(ptr->arr[c-'a']) ptr = ptr->arr[c-'a'];
            else return 0;
        }
        
        return ptr->eow;
    }
    
    bool startsWith(string word) {
        Node* ptr = x;
        
        for(char& c:word){
            if(ptr->arr[c-'a']) ptr = ptr->arr[c-'a'];
            else return 0;
        }
        
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */