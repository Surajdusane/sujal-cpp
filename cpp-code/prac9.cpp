#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
const int MAX = 10;

int main(){

    int choice,order;

    do{
        cout << "\n1. Place Order";
        cout << "\n2. Serve Order";
        cout << "\n3. Display Orders";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin>>choice;
    

    switch(choice){
        case 1:
             if(q.size() == MAX){
                cout<<"Max orders are there";
             }
             else{
                cout<<"Enter order number: ";
                cin>>order;

                q.push(order);
                cout<<"Order placed";
             }
             break;

        case 2:
             if (!q.empty()){
                cout<<"Order Served: "<<q.front()<<endl;
                q.pop();
             }
             else{
                cout<<"No orders to serve";
             }
             break;

        case 3:
             if(!q.empty()){
                queue<int> tem = q;

                while(!tem.empty()){
                    cout<<tem.front()<<endl;
                    tem.pop();
                }

                cout<<endl;
             }
             else{
                cout<<"No orders in queue";
             }
             break;

        case 4:
           cout<<"EXITING";
           break;

        default:
           cout<<"Invalid Choice";
    }
    
}

    while(choice!=4);

    return 0;
}    