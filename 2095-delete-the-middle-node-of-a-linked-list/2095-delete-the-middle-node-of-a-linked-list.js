/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

var md = 0;
var deleteMiddle = function(head) {
    // md=0;
    return fun(head,0);
};

let fun = (ptr,n)=>{
    if(ptr===null){
        md = Math.floor(n/2);
        return null;
    }
    ptr.next=fun(ptr.next,n+1);
         // console.log(md);
    if(n==md){
        return ptr.next;
    }
    return ptr;
}