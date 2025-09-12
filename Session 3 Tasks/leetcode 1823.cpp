class Node{
public:
	int data;
	Node *next;

	Node(int data){
		(*this).data = data;
		this->next = nullptr;
	}
};

class Solution{
private:
	Node *head = nullptr;
	Node *tail = nullptr;

public:
	void push_back(int val){
		Node *n = new Node(val);
		if (head == nullptr){
			head = tail = n;
			n->next = head;
		}
		else{
			tail->next = n;
			n->next = head;
			tail = n;
		}
	}

	int findTheWinner(int n, int k){
		for (int i = 1; i <= n; i++){
			push_back(i);
		}

		Node *current = head;
		Node *prev = tail;

		while (current->next != current){

			for (int i = 1; i < k; i++){
				prev = current;
				current = current->next;
			}

			prev->next = current->next;

			if (current == head)
				head = head->next;

			if (current == tail)
				tail = prev;

			delete current;
			current = prev->next;
		}

		int Winner = current->data;
		delete current;
		return Winner;
	}
};