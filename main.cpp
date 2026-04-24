#include <iostream>
#include <cmath>
using namespace std;

// Node structure for linked list
struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~LinkedList() {
        if (head == nullptr) return;
        
        // Break the circular link first
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = newNode; // circular
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        size++;
    }
    
    void moveFirstToEnd() {
        if (head == nullptr || head == tail) return;
        head = head->next;
        tail = tail->next;
    }
    
    void removeFirst() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        size--;
    }
    
    int getFirst() const {
        return head ? head->value : -1;
    }
    
    int getSize() const {
        return size;
    }
};

void subtask1(long long n) {
    LinkedList list;
    for (int i = 1; i <= n; i++) {
        list.append(i);
    }
    
    for (int round = 0; round < n - 1; round++) {
        list.moveFirstToEnd();  // "Good luck stays"
        list.removeFirst();     // "Troubles go away"
        cout << list.getFirst() << "\n";
    }
}

long long subtask2(long long n) {
    // Josephus problem: J(n, 2)
    // Find the highest power of 2 less than or equal to n
    long long powerOf2 = 1;
    while (powerOf2 * 2 <= n) {
        powerOf2 *= 2;
    }
    
    long long L = n - powerOf2;
    return 2 * L + 1;
}

int main() {
    int id;
    long long n;
    cin >> id >> n;
    
    if (id == 1) {
        subtask1(n);
    } else if (id == 2) {
        cout << subtask2(n) << "\n";
    }
    
    return 0;
}
