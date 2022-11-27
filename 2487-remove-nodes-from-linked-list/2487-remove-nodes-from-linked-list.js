/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeNodes = function(head) {
    return fun(head,null);
};

var fun = (head,prev)=>{
    if(head.next===null){
        return head;
    }
    
    let x = fun(head.next,head);
    if(head.val < x.val){
        if(prev) prev.next = x;
        return x;
    }
    return head;
}