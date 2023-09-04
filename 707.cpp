class Node 
{
    public :
    int val ;
    Node* next = nullptr;

    Node(int val, Node*next)
        :val(val), next(next)
    {}
    
};


class MyLinkedList {

private:
    Node* head = nullptr;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        Node * temp=head;
        if(temp==nullptr)
        {
            return -1;
        }

        while(index!=0 && temp->next!=nullptr)
        {
            temp = temp->next;
            index--;
        }

        if(index!=0)
            return -1;
        else 
            return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newHead = new Node(val, head);
        head = newHead;
    }
    
    void addAtTail(int val) {
        Node*temp =  head ;

        if(temp==nullptr)
        {
            addAtHead(val);
            return;
        }
        
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        Node* addNode = new Node(val, nullptr);
        temp->next = addNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index ==0)
        {
            addAtHead(val);
            return;
        }
        Node*temp = head;
        if(temp==nullptr)
            return;
            
        while(temp->next!=nullptr && index!=1)
        {
            temp = temp->next;
            index--;

        }
        Node* addNode = new Node(val, temp->next);
        temp->next = addNode;
        return ;

    }
    
    void deleteAtIndex(int index) {
        if(head==nullptr)
            return ;

        if(index ==0)
        {
            Node*temp = head;
            head = head->next;
            delete (temp);
            return ;
        }

        Node*temp = head;
        while(temp->next!=nullptr && index!=1 )
        {
            temp = temp->next;
            index--;

        }
        if(index!=1 || temp->next==nullptr)
            return ;
        
        

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete(deleteNode);
        return;

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