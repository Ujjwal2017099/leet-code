var countDaysTogether = function(aa, la, ab, lb) {
    let arr = [0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let sa = parseInt(aa.slice(0,2)) , sb = parseInt(ab.slice(0,2));
        let sda=parseInt(aa.slice(3)) , sdb = parseInt(ab.slice(3));
        
        let ea = parseInt(la.slice(0,2)) , eb = parseInt(lb.slice(0,2));
        let eda=parseInt(la.slice(3)) , edb = parseInt(lb.slice(3));
        let ans = 0;
        if(sa > eb || sb > eb || (eb == sa && sda > edb) || (ea == sb && sdb > eda)){
            return 0;
        }
        if(Math.max(sa,sb) == Math.min(ea,eb)){
            if(sb>sa || (sb==sa && sdb >= sda)){
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
        else if(Math.max(sa,sb) > Math.min(ea,eb)){
            return 0;
        }
        else{
            for(let i = Math.max(sa,sb)+1 ; i < Math.min(ea,eb) ;i++){
                ans += arr[i];
                
            }
            
            if(sb>sa  || (sb==sa && sdb >= sda)){
                ans += arr[sb] - sdb+1;
            }else{
                ans += arr[sa] - sda+1;
            }
            
            if(ea < eb || (ea == eb && eda <= edb)){
                ans += eda;
            }else {
                ans += edb;
            }
        }
        return ans;
};