/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let n = matrix.length -1;
    let s = (n+1)/2;
    for(let i=0;i<s;i++){
        for(let j = i ; j<n-i ; j++){
            let x = i, y = j,t = matrix[x][y];
            for(let k=1;k<=4;k++){
                let z = matrix[y][n-x];
                x = n-x;
                matrix[y][x] = t;
                t = z;
                [x,y] = [y,x];
            }
        }
    }
};