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
//Iterative solution
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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr)
            return head;

        ListNode* cur = head;
        ListNode * temp = nullptr;
        while(cur!=nullptr){
            ListNode* nextTemp = cur->next;
            cur->next = temp;
            temp = cur;
            cur=nextTemp;

        }
        return temp;
    }
};




//Recurisve solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== nullptr){
            return head;
        }

        if(head->next ==nullptr)
            return head;

        ListNode * temp = reverseList(head->next);

        (head->next)->next = head;
        head->next =nullptr;

        return temp;
    }
};