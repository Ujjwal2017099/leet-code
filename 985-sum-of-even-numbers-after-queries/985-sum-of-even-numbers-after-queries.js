/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(n, q) {
    let arr = [];
    let sum=0;
    for(let i=0;i<n.length;i++){
        if(!(n[i]&1)){
            sum += n[i];
        }
    }
    
    q.forEach((element)=>{
        let val = element[0];
        let x = element[1];
        let prev = n[x];
        n[x] += val;
        if(!(n[x]&1)){
            sum += val;
            if(prev&1) sum+=prev;
        }else if(!(prev&1)){
            sum-=prev;
        }
        arr.push(sum);
    })
    return arr;
};