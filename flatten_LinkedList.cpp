/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* down , Node* right){
	if(down == NULL)
	return right;

	if(right == NULL)
	return down;

	Node* res = new Node(-1);
	Node* temp = res;


	while(down!=NULL && right!=NULL){
		if(down -> data < right-> data){
			//temp-> next = left
			temp-> child = down;
			temp = down;
			down = down -> child;
		}
		else{
			temp-> child = right;
			temp = right;
			right = right -> child;
		}
	}

	while(down!=NULL){
		temp-> child = down;
		temp = down;
		down = down -> child;
	}

	while(right!=NULL){
		temp-> child = right;
		temp = right;
		right = right -> child;
	}

	res = res-> child;
	return res;
}
Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head-> next==NULL){
		return head;
	}
	// Write your code here
	Node * down = head;
	Node* right = flattenLinkedList(head->next);
	down-> next = NULL;

	Node* ans = merge(down,right);
	return ans;
}
