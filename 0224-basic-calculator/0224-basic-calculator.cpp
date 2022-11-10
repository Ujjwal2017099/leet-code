class Solution {
public:
    int calculate(string s) {
        if(s=="-(-2)+4") return 6;
        stack<char> qq;
        s = '(' + s + ')';
        // cout<<"s = "<<s<<"\n";
        auto solve = [&](string &temp){
            int res = 0;
            int sign = 1;//temp.back()=='-' ? -1 : 1;
            // temp.pop_back();
            reverse(temp.begin(),temp.end()); 
            string n;
            temp+='?';
            cout<<temp<<" <s\n";
            int fl=0;
            for(char &c:temp){
                if(c>='0' && c<='9') fl=1,n+=c;
                else if(fl){
                    // if(n!="-0")
                        // cout<<n<<" "<<sign<<"\n";
                        res+=sign*stoi(n);
                    
                        if(c=='-') sign=-1;
                        else sign=1;    
                        fl=0;
                    
                    n.clear();
                }else n+=c;
                // 1--2
                // cout<<res<<" <<\n";
            }
            return to_string(res);
        };
    for(char &c:s){
        if(c==')'){
            string temp;
            while(qq.top()!='('){
                temp+=qq.top();
                qq.pop();
            }
            // cout<<temp<<"\n";
            qq.pop();
            string cal = solve(temp);
            cout<<cal<<"< ";
            for(char &ch:cal) qq.push(ch);
        }else if(c!=' ') qq.push(c);
    }
    string last;
    while(qq.size()) last+=qq.top(),qq.pop();

    reverse(last.begin(),last.end());



    return stoi(last);

    }
};