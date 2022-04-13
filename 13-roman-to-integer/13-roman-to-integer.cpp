class Solution {
public:
    int romanToInt(string s) {
        int thousand = 0 ,hundred = 0, tens = 0,num =0 ;
        
        int length = s.length();
        
        vector<char> temp(2);
        
        for(int i = 0 ; i < (length) ; i++)
        {
            temp.at(0) = s[i];
            temp.at(1) = s[i+1];
            
            if((temp.at(0) == 'C' && temp.at(1) == 'M'))
            {
                hundred += 9;
                i++;
            }
            else if (temp.at(0) == 'C' && temp.at(1) == 'D') 
            {
                hundred += 4;
            i++;
            }
            else if(temp.at(0) == 'X' && temp.at(1) == 'C')
            {
                tens += 9;
            i++;
            }
            else if(temp.at(0) == 'X' && temp.at(1) == 'L')
            {
                tens += 4;
            i++;
            }
           else if(temp.at(0) == 'I' && temp.at(1) == 'X') 
           {
               num += 9;
           i++;
           }
            else if(temp.at(0) == 'I' && temp.at(1) == 'V')
            {
                num += 4;
            i++;
            }
            
            else{
                
                if(s[i] == 'M') thousand++;
                else if(s[i] == 'D') hundred += 5;
                else if(s[i] == 'C') hundred++;
                else if(s[i] == 'L') tens += 5;
                else if(s[i] == 'X') tens++;
                else if(s[i] == 'V') num += 5;
                else if(s[i] == 'I') num++;
                
                
            }
                
            
                
                
        }
            int ans = thousand*1000 + hundred*100 + tens*10 + num;
        
        
        return ans;
        
    }
};