/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function(matches) {
    let arr = new Array(100001);
    for(let i=0;i<100001;i++){
        arr[i]=-1;
    }
    matches.forEach((e)=>{
        if(arr[e[0]]===-1) arr[e[0]]=0;
        if(arr[e[1]]===-1) arr[e[1]]=0;
        arr[e[1]]++;
    })
    
    let ans = new Array(2);
    for(let i=0;i<2;i++){
        ans[i] = new Array();
    }
    for(let i=1;i<100001;i++){
        if(arr[i]===0){
            ans[0].push(i);
        }
        if(arr[i]===1){
            ans[1].push(i);
        }
    }
    return ans;
};