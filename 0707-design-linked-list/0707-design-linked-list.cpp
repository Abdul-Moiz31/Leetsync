class Node {
public:
    int val;
    Node* next;

    Node(int value) : val(value), next(nullptr) {}
};
class MyLinkedList {
private:
        Node* head;
        int size;
public:        
    MyLinkedList() : head(nullptr) , size(0) {}
    
    int get(int index) {
        if(index < 0 || index >=size)
        return -2;
        Node* curr = head;
        for(int i =0 ; i<index ; i++){
            curr = curr ->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode =new Node(val);
       newNode->next = head ;
       head =newNode;
       size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if( head == nullptr){
            head =newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if( index == 0){
            addAtHead(val);
        } else {
            Node* newNode = new Node(val);
            Node* curr = head;
            for(int i =0 ; i< index -1 ; i++){
                curr = curr ->next;
            }
            newNode->next =  curr->next;
            curr->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
        return;
        if(index == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        } else {
            Node* curr =head;
            for( int i = 0 ; i < index-1 ; i ++) {
                curr = curr ->next;
            }
            Node * temp = curr ->next;
            curr->next = curr->next->next;
            delete temp;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */