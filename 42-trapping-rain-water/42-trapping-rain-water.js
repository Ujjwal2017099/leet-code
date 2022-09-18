/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(h) {
    let l = new Array(h.length);
    let r = new Array(h.length);
    let n = h.length-1;
    l[0] = h[0];
    r[n] = h[n];
    
    for(let i=1;i<=n;i++){
        l[i] = Math.max(l[i-1],h[i]);
    }
    for(let i=n-1;i>=0;i--){
        r[i] = Math.max(r[i+1],h[i]);
    }
    let ans = 0;
    for(let i=0;i<=n;i++){
        ans += Math.min(l[i],r[i]) - h[i];
    }
    return ans;
};