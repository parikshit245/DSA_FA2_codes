#include <iostream>
#include <cstring>
#define MAX_SIZE 100    // Maximum size for stack and queue
using namespace std;

  

// Stack class for managing commits
class Stack {
private:
    string commits[MAX_SIZE];  // Array to store commits
    int top;  // Index for the top of the stack

public:
    Stack(){top = -1;}  // Initialize stack

    // Add a commit to the stack
    void push(string commit) {
        if (top < MAX_SIZE - 1) {
            commits[++top] = commit;  // Increment top and add commit
            cout << "Commit added: " << commit << endl;
        } else {
            cout << "Stack overflow! Can't add more commits." << endl;
        }
    }

    // Revert the latest commit
    string pop() {
        if (top >= 0) {
            return commits[top--];  // Return the top commit and decrement top
        } else {
            return "No commits to revert.";  // No commits available
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;  // Returns true if stack is empty
    }
};

// Queue class for managing branches
class Queue {
private:
    string branches[MAX_SIZE];  // Array to store branches
    int front, rear;  // Indices for front and rear of the queue

public:
    Queue(){front = rear = 0;}  // Initialize queue

    // Add a branch to the queue
    void enqueue(string branch) {
        if (rear < MAX_SIZE) {
            branches[rear++] = branch;  // Add branch and increment rear
            cout << "Branch added to queue: " << branch << endl;
        } else {
            cout << "Queue overflow! Can't add more branches." << endl;
        }
    }

    // Merge the oldest branch
    string dequeue() {
        if (front < rear) {
            return branches[front++];  // Return the front branch and increment front
        } else {
            return "No branches to merge.";  // No branches available
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == rear;  // Returns true if queue is empty
    }
};

// Main function for the menu-driven program
int main() {
    Stack commitStack;  // Create commit stack
    Queue branchQueue;  // Create branch queue
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
