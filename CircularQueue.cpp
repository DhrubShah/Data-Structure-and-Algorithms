#include<iostream>
using namespace std;
#define size 6
class CircularQueue{
    private:
    int rear=-1;
    int front=-1;
    int Q[size];
    public:
    void Display(){
        if(front==-1&&rear==-1){
            cout<<"Queue is Empty";
        }
        else{
            cout<<"Queue Elements are : "; //display front to rear
            for(int i=front;i!=rear;i=(i+1)%size){
                cout<<Q[i]<<" "; // include a space after printing each element
            }
            cout << Q[rear]; // print the last element
        }

    }
    void Delete(){
        if(rear==-1&&front==-1){
            cout<<"Queue is empty";
        }
        else{
            if(front==rear){ // Queue contains Single elements
                front=-1;
                rear=-1;
            }
            else{
                int data=Q[front];
                front=(front+1)%size; // increase front by 1
                cout<<"Deleted data is : "<<data<<"\n"; // include a newline character
            }
        }

    }
    void Insert(){
        if((rear+1)%size==front){
            cout<<"Queue is full";
        }
        else{
            if(front==-1){ // Front is increase only once(when First Element is inserted)
                front=front+1;
            }
            rear=(rear+1)%size;
            cout<<"Enter data to be inserted: ";
            cin>>Q[rear];
        }

    }

};
int main(){
    int choice;
    CircularQueue c;
    while(true){
        cout<<"Enter your Choice: \n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n  ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            c.Insert();
            break;

         case 2:
            c.Delete();
            break;
        case 3:
            c.Display();
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}
