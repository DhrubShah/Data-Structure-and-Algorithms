#include<iostream>
#define size 5
using namespace std;

class LinearQueue {
private:
    int rear = -1;
    int front = -1;
    int Q[size];
public:
    void Insert() {
        if (rear == size - 1) {
            cout << "Queue is Full\n";
        } else {
            rear = rear + 1;
            cout << "Enter a Number: ";
            cin >> Q[rear];
            if (front == -1) {
                front = 0; // Update front only when inserting the first element
            }
        }
    }

    void Delete() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            int data = Q[front];
            front = front + 1;
            cout << "Deleted Data is " << data << endl;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
        } else {
            cout << "Elements in the Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << Q[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int choice;
    LinearQueue l;
    while (true) {
        cout << "Enter Your Choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                l.Insert();
                break;
            case 2:
                l.Delete();
                break;
            case 3:
                l.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Please Enter correct Choice\n";
                break;
        }
    }
    return 0;
}
