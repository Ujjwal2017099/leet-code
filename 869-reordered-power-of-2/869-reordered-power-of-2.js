/**
 * @param {number} n
 * @return {boolean}
 */
var reorderedPowerOf2 = function(n) {
    let s = fun(n);
    for(let i=0;i<32;i++){
        if(s === fun(1<<i)) return 1;
    }
    return 0;
};

function fun(n){
    let str = n.toString();
    
    return str.split('').sort().join('');;
}