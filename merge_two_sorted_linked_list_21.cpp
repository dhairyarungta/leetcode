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
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* curHead = nullptr;
        ListNode* prev = nullptr;
        if(head1 == nullptr)
            return head2;
        else if (head2 ==nullptr)
            return head1;

        // if(head1->val <head2->val){
        //     curHead=head1;
        //     head1= head1->next;
        // }
        // else {
        //     curHead= head2;
        //     head2 = head2->next;
        // }
        
        while(head1!=nullptr && head2!=nullptr){
            ListNode*temp =nullptr;
            if(head1->val < head2->val){
                temp = head1;
                head1=head1->next;
            }
            else {
                temp = head2;
                head2 = head2->next;
            }
            cout<<temp->val <<" ";

            if(prev!=nullptr){
                prev->next = temp;
            }
            prev = temp;
            
        }
        if(head1!= nullptr){
            prev->next = head1;
        }
        else if(head2!= nullptr){
            prev->next = head2;
        }


        return list1->val<list2->val?list1:list2;

    }
};