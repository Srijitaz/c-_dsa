/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findMiddle(node* head){
    node* slow = head;
    node* fast = head-> next;

    while(fast!= NULL && fast-> next!=NULL){
        slow = slow-> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left==NULL)
     return right;

    if(right==NULL)
     return left;

    node* res = new node(-1);
    node* temp = res;

    while(left!=NULL && right!=NULL){
        if(left -> data < right -> data){
            temp->next = left;
            temp = left;
            left = left-> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left-> next;
    }

    while(right!=NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    res = res-> next;
    return res;
}
node* mergeSort(node *head) {
    // Write your code here.
    if(head==NULL || head->next == NULL){
        return head;
    }
    // splitting the ll in two halves
    node* middle = findMiddle(head);
    node*  left = head;
    node* right = middle -> next;
    middle -> next = NULL;

    // recursion to sort both left and right
    left = mergeSort(left);
    right = mergeSort(right);

    node* ans = merge(left, right);
    return ans;
}
