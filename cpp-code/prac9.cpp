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
                cout<<"Enter order nummber";
                cin>>order;
             
             q.push(order);
             cout<<"Order placed";
             }
             break;

        case 2:
             if (!q.empty()){

                cout<<"Order Served";
                cout<< q.front();
                q.pop();

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

                break;
             }
             
        case 4:
           cout<<"EXITING";

        default:cout<<"Invalid Choice";   
    }   
    
}

    while(choice!=4);

}    