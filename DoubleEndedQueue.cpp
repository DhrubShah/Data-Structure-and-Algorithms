#include<iostream>
#define size 5
using namespace std;
class DoubleEndedQueue{
    private:
    int rear=-1;
    int front=-1;
    int Q[size];
    public:
    void insertFromRear(){
        int data;
        cout<<"Enter data to insert";
        cin>>data;
        if(front==0 && rear==size-1){
            cout<<"Queue is Full";
        }
        else if(front==rear+1){
            cout<<"Queue is full";
        }
        else if(rear==-1 && front==-1){
            rear=0;
            front=0;
            Q[rear]=data;

        }else{
            if(rear!=size-1){
                rear=rear+1;
                Q[rear]=data;
            }else{
                for(int i=front;i<=rear;i++){
                    Q[i-1]=Q[i];
                }
                Q[rear]=data;
                front--;
            }
        }

    }
    void insertFromFront(){
        int data;
        cout<<"Enter data to insert";
        cin>>data;
        if(front==0 && rear==size-1){
            cout<<"Queue is full";
        }
        else if(front==rear+1){
            cout<<"Queue is full";
        }
        else if(rear==front){
            front=0;
            rear=0;
            Q[front]=data;
        }
        else{
            if(front!=0){
                front=front-1;
                Q[front]=data;
            }
            else{
                for(int i=rear;i>=front;i--){
                    Q[i+1]=Q[i];
                }
                Q[front]=data;
                rear++;
            }
        }

    }
    void deleteFromRear(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty";
        }
        else if(front==rear){
            rear=-1;
            front=-1;
        }
        else{
            rear=rear-1;
        }

    }
    void deleteFromFront(){

        if(front==-1 && rear==-1){
            cout<<"Queue is empty";
        }
        else if(front==rear){
            rear=-1;
            front=-1;
        }
        else{
            front=front+1;
        }


    }
    void display(){
       if(front==-1 && rear==-1){
            cout<<"Queue is empty";
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<Q[i];
            }
        }

    }


};
int main(){
    int choice;
    DoubleEndedQueue d;
    while(true){
        cout<<"Enter Your Choice: \n 1.Insert From Rear \n 2. Insert From Front \n 3. Delete from Rear \n 4. Delete From Front \5. Display \n 6. Exit \n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            d.insertFromRear();
            break;
        case 2:
            d.insertFromFront();
            break;
        case 3:
            d.deleteFromRear();
            break;
        case 4:
            d.deleteFromFront();
            break;
        case 5:
            d.display();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
