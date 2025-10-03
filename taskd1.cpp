#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n = 5;
    Node* head = new Node{1, NULL};
    Node* curr = head;

    // Create circular list
    for (int i = 2; i <= n; ++i) {
        curr->next = new Node{i, NULL};
        curr = curr->next;
    }
    curr->next = head; // last node points back to head

    cout << "Circular List: ";
    curr = head;
    for (int i = 0; i < n; ++i) { // print only once around
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}