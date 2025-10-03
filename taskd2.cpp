#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int N = 10, M = 3; // 10 people, eliminate every 3rd

    // Build circular list
    Node* head = new Node{1, NULL};
    Node* curr = head;
    for (int i = 2; i <= N; ++i) {
        curr->next = new Node{i, NULL};
        curr = curr->next;
    }
    curr->next = head; // make circular

    Node* prev = curr;
    curr = head;

    // elimination
    while (curr->next != curr) {
        for (int i = 1; i < M; ++i) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        cout << "Removing: " << curr->data << endl;
        delete curr;
        curr = prev->next;
    }

    cout << "Leader is: " << curr->data << endl;

    return 0;
}