/*

21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

*/



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
        if (list1 == nullptr) {
            return sortList(list2);
        } 
        else if (list2 == nullptr) {
            return sortList(list1);
        } 
        else {
            ListNode* temp = list1;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = list2;
            return sortList(list1);
        }
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } 
        else {
            bool swapped;
            do {
                swapped = false;
                ListNode* temp = head;
                while (temp->next != nullptr) {
                    if (temp->val > temp->next->val) {
                        swap(temp->val, temp->next->val);
                        swapped = true;
                    }
                    temp = temp->next;
                }
            } while (swapped);

            return head;
        }
    }
};
