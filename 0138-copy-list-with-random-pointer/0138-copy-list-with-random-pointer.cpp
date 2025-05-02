/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr ) return nullptr;
         
        // Insetring in bw
        Node* temp = head;
         while(temp != nullptr){
             Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
         }


         // Connecting Random POinters
         temp = head;
         while(temp !=nullptr){
           if(temp->random)
            temp->next->random = temp->random->next;
            temp = temp->next->next;
         }

         // Connecting Next POinters
         
         Node* dummy = new Node(0);
         Node* res = dummy;
         temp = head;

         while(temp != NULL){
             Node* copyNode = temp->next;
            res->next = copyNode;
            temp->next = copyNode->next;
            res = res->next;
            temp = temp->next;
         }
         return dummy->next;
    }
};