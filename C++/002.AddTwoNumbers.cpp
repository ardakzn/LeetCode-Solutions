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
        ListNode* temp = new ListNode(0);//temp result
        ListNode* result = temp;
        int carry = 0;
        while(l1||l2||carry){
        //this condition for if there is any null value in the list, then assume it is 0 for sum.
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a+b;
        temp->next=new ListNode((sum+carry)%10);//Create new node and assign value to next nodelist of result.
        carry=(sum+carry)/10;//calculate carry value
        temp = temp->next;//assign next node of temp result
         //assign current node to next node if there is. If there is not, then set null.
        l1 =l1 ? l1->next : nullptr;
        l2 =l2 ? l2->next : nullptr;
        //
        };
        return result->next;
    }
};