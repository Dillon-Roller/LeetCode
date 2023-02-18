using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val): val(val), next(nullptr) {};
};

int getSum(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    return head->val + getSum(head->next);
}

void add_node(Node* prev_node, Node* node_to_add) {
    node_to_add->next = prev_node->next;
    prev_node->next = node_to_add;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next; // first, make sure we don't lose the next node
        curr->next = prev;              // reverse the direction of the pointer
        prev = curr;                   // set the current node to prev for the next node
        curr = nextNode;               // move on
    }

    return prev;
}

bool hasCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

