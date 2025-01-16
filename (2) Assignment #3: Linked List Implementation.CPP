#include <iostream>

using namespace std;

// Define the node structure for linked list
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// Define the class for the sparse matrix
class SparseMatrixLinkedList {
private:
    int rows, cols;
    Node* head;

public:
    SparseMatrixLinkedList(int r, int c) : rows(r), cols(c), head(nullptr) {}

    void addElement(int r, int c, int val) {
        if (val != 0) {
            Node* newNode = new Node{r, c, val, nullptr};
            if (!head || (head->row > r || (head->row == r && head->col > c))) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                while (current->next && (current->next->row < r || (current->next->row == r && current->next->col < c))) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void display() {
        Node* current = head;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (current && current->row == i && current->col == j) {
                    cout << current->value << " ";
                    current = current->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrixLinkedList sml(4, 4);
    sml.addElement(0, 1, 3);
    sml.addElement(1, 2, 5);
    sml.addElement(3, 0, 7);

    cout << "Sparse Matrix (Linked List Implementation):" << endl;
    sml.display();

    return 0;
}
