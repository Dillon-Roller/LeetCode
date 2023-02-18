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

