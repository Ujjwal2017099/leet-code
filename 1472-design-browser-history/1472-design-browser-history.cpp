class BrowserHistory {
public:
    vector<string> vis;
    int i=-1;
    int l=-1;
    BrowserHistory(string homepage) {
        vis.resize(5001);
        vis[0]=homepage;i=0;l=0;
    }
    
    void visit(string url) {
        vis[++i]=url;
        l = i;
    }
    
    string back(int steps) {
        if(i+1<=steps) i=0;
        else i-=steps;
        return vis[i];
    }
    
    string forward(int steps) {
        if(l-i<=steps) i=l;
        else i+=steps;
        return vis[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */