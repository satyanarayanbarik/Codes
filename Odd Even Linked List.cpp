/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


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
/*
SELF TRIED
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //BRUTE FORCE
        vector<int> result;
        if(head == NULL || head->next == NULL) return head;
        ListNode *temp = head;
        //int arr[] = { };
        //For odd node elements
        while(temp!=NULL){

            result.push_back(temp->val);
            if(temp->next!= NULL)temp = temp->next->next;

        }
        if(temp) result.push_back(temp->val); // for last element if its odd
        //FOR EVEN NODE ELEMENTS
        temp = head->next ;
        while(temp!=NULL && temp->next!= NULL){

            result.push_back(temp->val);
            temp = temp->next->next;

        }
        //if(temp) result.push_back(temp->val);

        
        // Reset temp to start at head again for modifying nodes with array values
        temp = head;
        int i = 0;
        while (temp != NULL && i < result.size()) {
            temp->val = result[i++];
            temp = temp->next;
        }

        return head;

    }
};
*/
// BRUTE FORCE
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
/* 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Array to hold values in required odd-even order
        vector<int> arr;
        ListNode *temp = head;

        // Collect values of odd-positioned nodes
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val); // Add last odd node if it exists

        // Collect values of even-positioned nodes
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val); // Add last even node if it exists

        // Reassign the values from arr back to the original list
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};
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

 // OPTIMAL 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL) return head;

        ListNode *odd = head;             // Pointer for odd nodes
        ListNode *even = head->next;      // Pointer for even nodes
        ListNode *evenHead = head->next;  // Save the head of the even list

        // Rearrange the nodes in odd-even order
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next; // Link the next odd node
            even->next = even->next->next; // Link the next even node

            odd = odd->next;  // Move to the next odd node
            even = even->next; // Move to the next even node
        }

        // Connect the end of odd list to the head of even list
        odd->next = evenHead;

        return head; // Return the rearranged list
    }
};
