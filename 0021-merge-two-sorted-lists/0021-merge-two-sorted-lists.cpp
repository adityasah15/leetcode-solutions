/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* head = (list1->val <= list2->val)? list1 : list2;
        ListNode* tail = head;
        ListNode* t1 = (list1 == head)? list1->next: list1;
        ListNode* t2 = (list2 == head)? list2->next: list2;
        
        while (t1 && t2){
            if(t1->val <= t2->val){
                tail->next = t1;  
                t1 = t1->next;
            } else{
                tail->next = t2;
                t2 = t2->next;
            }
            tail = tail->next;
        }
        if(t1 == nullptr) tail->next = t2;
        if(t2 == nullptr) tail->next = t1;
        return head;
    }
};