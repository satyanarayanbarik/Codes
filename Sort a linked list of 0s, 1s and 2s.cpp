//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        
        // BRUTE FORCE
        /*
        
        Node *temp = head;
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        
        while(temp!=NULL){
            if(temp->data  == 0) count0++;
            if(temp->data  == 1) count1++;
            if(temp->data  == 2) count2++;
            
            temp = temp->next;
            
        }
        temp = head;
        while(temp != NULL){
            if(count0){
                temp->data  = 0;
                count0--;
            }
            else if(count1){
                temp->data  = 1;
                count1--;
            }
            else{
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }
        return head;
        
        */
        
        //OPTIMAL
        
        if( head == NULL || head->next == NULL ) return head;
        
        Node *temp = head;
        
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        
        temp = head;
        
        while(temp!=NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            if(temp->data == 1){
                one->next = temp;
                one = temp;
            }
            if(temp->data == 2){
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next)? oneHead->next : twoHead->next;
        
        one->next = twoHead->next;
        two->next = NULL;
        Node *newHead = zeroHead->next;
        
        return newHead;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends