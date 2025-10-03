#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    // create nodes
    Node* head = new Node{10, NULL, NULL};
    Node* second = new Node{20, NULL, head};
    Node* third = new Node{30, NULL, second};
    Node* fourth= new Node{40,NULL, third};

    third->next=fourth;
    second->next = third;
    head->next = second;

    // forward traversal
    cout << "Forward: ";
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;

    // backward traversal
    cout << "Backward: ";
    for (Node* cur = third; cur; cur = cur->prev)
        cout << cur->data << " ";
    cout << endl;

    return 0;
}