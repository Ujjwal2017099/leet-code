
var averageOfLevels = function(root) {
    let ans = []
    let q = [];
    q.push(root);
    q.push(null);
    let sum=0.0;
    let cnt=0;
    while(q.length>0){
        let node = q[0];
        q.shift();
        if(node===null){
            ans.push(sum/cnt);
            sum=0.0;
            cnt=0;
            if(q.length > 0) q.push(null);
        }
        else{
            if(node.left) q.push(node.left);
            if(node.right) q.push(node.right);
            sum += node.val;
            cnt++;
        }
    }
    return ans;
};