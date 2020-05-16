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
    ListNode *oddEvenList(ListNode *head) {
        if (!head)
            return NULL;

        auto odd = head;
        auto even = head->next;

        auto firstEven = even;

        while (odd && even && even->next) {
            odd->next = even->next;
            odd = even->next;

            if (!odd->next) {
                even->next = NULL;
                break;
            }

            even->next = odd->next;
            even = odd->next;
        }
        odd->next = firstEven;
        return head;
    }
};
