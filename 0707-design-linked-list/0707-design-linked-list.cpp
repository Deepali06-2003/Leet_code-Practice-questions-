class MyLinkedList {
    private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    ListNode* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;    
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
        
    }
    
    void addAtHead(int val) {
    ListNode* x = new ListNode(val);
    x->next = head;
    head = x;
    size++;
}
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = node;
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = node;
        }
        size++;

    }
    
    void addAtIndex(int index, int val) {

       if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        ListNode* prev = head;
        for (int i = 1; i < index; i++) {
            prev = prev->next;
        }

        ListNode* node = new ListNode(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* prev = head;
            for (int i = 1; i < index; i++) {
                prev = prev->next;
            }
            ListNode* toDelete = prev->next;
            prev->next = toDelete->next;
            delete toDelete;
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