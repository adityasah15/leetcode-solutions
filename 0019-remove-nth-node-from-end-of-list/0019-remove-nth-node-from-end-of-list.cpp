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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1)
            return nullptr;
        ListNode* temp = head;
        int sz = 1;
        while (temp->next) {
            temp = temp->next;
            sz++;
        }
        if (n == sz) {
            temp = head->next;
            delete head;
            return temp;
        }
        if (n > sz)
            return nullptr;
        temp = head;
        int steps = sz - n - 1;
        while (steps > 0) {
            temp = temp->next;
            steps--;
        }
        ListNode* todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
        return head;
    }
};