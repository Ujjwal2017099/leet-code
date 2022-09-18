class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int arr[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sa = stoi(aa.substr(0,2)) , sb = stoi(ab.substr(0,2));
        int sda=stoi(aa.substr(3)) , sdb = stoi(ab.substr(3));
        // cout<<sda<<" "<<sdb<<" ";
        int ea = stoi(la.substr(0,2)) , eb = stoi(lb.substr(0,2));
        int eda=stoi(la.substr(3)) , edb = stoi(lb.substr(3));
        int ans = 0;
        if(sa > eb or sb > eb or (eb == sa and sda > edb) or (ea == sb and sdb > eda)){
            return 0;
        }
        if(max(sa,sb) == min(ea,eb)){
            if(sb>sa or (sb==sa and sdb >= sda)){
                if(eda < edb){
                    ans = eda - sdb + 1;
                }else{
                    ans = edb - sdb + 1;
                }
            }else{
                if(eda < edb){
                    ans = eda - sda + 1;
                }else{
                    ans = edb - sda + 1;
                }
            }
        }
        else if(max(sa,sb) > min(ea,eb)){
            return 0;
        }
        else{
            int mf = min(ea,eb) - max(sa,sb);
            for(int i = max(sa,sb)+1 ; i < min(ea,eb) ;i++){
                ans += arr[i];
                
            }
            
            if(sb>sa  or (sb==sa and sdb >= sda)){
                ans += arr[sb] - sdb+1;
            }else{
                ans += arr[sa] - sda+1;
            }
            
            if(ea < eb or (ea == eb and eda <= edb)){
                ans += eda;
            }else {
                ans += edb;
            }
        }
        return ans;
    }
};