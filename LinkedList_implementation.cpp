#include <iostream>
#include <string>

using namespace std;

// Node class for linked list (used in both Stack and Queue)
class Node {
public:
    string data;  // Store the commit message or branch name
    Node* next;   // Pointer to the next node

    // Constructor for creating a node
    Node(string value){
        data = value;
        next = nullptr;
    }
};

// Stack class for managing commits using a linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor for initializing stack
    Stack(){top = nullptr;}

    // Add a commit to the stack
    void push(string commit) {
        Node* newNode = new Node(commit);  // Create a new node
        newNode->next = top;  // Link the new node to the current top
        top = newNode;  // Update top to the new node
        cout << "Commit added: " << commit << endl;
    }

    // Revert the latest commit
    string pop() {
        if (top == nullptr) {
            return "No commits to revert.";  // No commits available
        } else {
            string poppedCommit = top->data;  // Get the commit at the top
            Node* temp = top;  // Temporarily store the top node
            top = top->next;  // Move top to the next node
            delete temp;  // Delete the old top node
            return poppedCommit;  // Return the popped commit
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;  // Returns true if stack is empty
    }
};

// Queue class for managing branches using a linked list
class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor for initializing queue
    Queue(){front = rear = nullptr;}

    // Add a branch to the queue
    void enqueue(string branch) {
        Node* newNode = new Node(branch);  // Create a new node
        if (rear == nullptr) {
            // If queue is empty, both front and rear are the new node
            front = rear = newNode;
        } else {
            // Link the new node to the rear and update the rear pointer
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Branch added to queue: " << branch << endl;
    }

    // Merge the oldest branch
    string dequeue() {
        if (front == nullptr) {
            return "No branches to merge.";  // No branches available
        } else {
            string dequeuedBranch = front->data;  // Get the branch at the front
            Node* temp = front;  // Temporarily store the front node
            front = front->next;  // Move front to the next node
            if (front == nullptr) {
                // If the queue becomes empty, rear should also be null
                rear = nullptr;
            }
            delete temp;  // Delete the old front node
            return dequeuedBranch;  // Return the dequeued branch
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;  // Returns true if queue is empty
    }
};

// Main function for the menu-driven program
int main() {
    Stack commitStack;  // Create commit stack using linked list
    Queue branchQueue;  // Create branch queue using linked list
    int choice;  // User's choice for menu

    // Menu-driven loop
    do {
        cout << "\nVersion Control System Menu:\n";
        cout << "1. Add Commit\n";
        cout << "2. Revert Latest Commit\n";
        cout << "3. Add Branch\n";
        cout << "4. Merge Branch\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Get user's choice

        switch (choice) {
            case 1: {  // Add Commit
                string commit;
                cout << "Enter commit message: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, commit);  // Get full commit message
                commitStack.push(commit);  // Push commit onto stack
                break;
            }
            case 2: {  // Revert Latest Commit
                string reverted = commitStack.pop();  // Revert commit
                cout << "Reverted commit: " << reverted << endl;
                break;
            }
            case 3: {  // Add Branch
                string branch;
                cout << "Enter branch name: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, branch);  // Get full branch name
                branchQueue.enqueue(branch);  // Enqueue branch
                break;
            }
            case 4: {  // Merge Branch
                string merged = branchQueue.dequeue();  // Dequeue branch
                cout << "Merged branch: " << merged << endl;
                break;
            }
            case 5:  // Exit
                cout << "Exiting the version control system." << endl;
                break;
            default:  // Invalid choice
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);  // Continue until user chooses to exit

    return 0;  // End of program
}
