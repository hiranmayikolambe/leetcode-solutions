class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        ListNode* temp = head;
        for (int i = 0; i < k; i++){
            if (temp == NULL) return head;
            temp = temp->next;
        }
        ListNode* newHead = reverseList(head, k);
        head->next = reverseKGroup(temp, k);
        return newHead;
    }
    ListNode* reverseList(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (k--){
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
};