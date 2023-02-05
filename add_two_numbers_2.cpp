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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* newHead = nullptr, *cur = nullptr;
        int carry =0;

        while(temp1!=nullptr && temp2!= nullptr){
        int val1 = temp1->val;
        int val2 = temp2->val;
        int newVal =(val1+val2+carry)%10;
        carry = (val1+val2+carry)/10;
        
        ListNode* addNode = new ListNode(newVal);
        if(cur!=nullptr){
            cur->next = addNode;
        }
        else{
            newHead = addNode;
        }
        cur = addNode;
        temp1= temp1->next;
        temp2 = temp2->next;
        }

        ListNode* temp = (temp1==nullptr)?temp2:temp1;
        while(temp!=nullptr){
            int newVal = ((temp->val)+carry)%10;
            carry = ((temp->val)+carry)/10;
            ListNode* addNode = new ListNode(newVal);
            cur->next = addNode;
            cur = addNode;
            temp = temp->next;
        }

        if(carry!=0){
            ListNode* addNode = new ListNode(carry);
            cur->next = addNode;
        }
        
        return newHead;
    }
};