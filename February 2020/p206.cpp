/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode * rest = head->next;
        head->next = nullptr;
        
        ListNode * rev = reverseList(rest);
        rest->next = head;
        return rev;
    }
};
