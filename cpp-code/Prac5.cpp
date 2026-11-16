#include<iostream>
using namespace std;


    class polynomial{
        int a[10], degree;


    public:
        void input(){
            cin>>degree;

            cout<<"Enter the coeff from x^0 to x^"<<degree<<":" <<endl;
            for(int i = 0 ; i<=degree ; i++){

                cin>>a[i];

            }

            cout<<endl;
        }

        void display(){

            for(int i = degree ; i>=0 ; i--){
                if(a[i]!=0 ){
                    cout<<a[i];

                }

                if(i>0){
                    cout<<"x";
                }

                if(i>1){
                    cout<<"^"<<i;
                }

                if(i>0){
                    cout<<"+";
                }
            }
                cout<<endl;

            
        }

            void add(polynomial p){
                int max = (degree>p.degree) ? degree : p.degree;
                cout<<"Sum:";

                for(int i =  max ; i>=0; i--){
                    int x = (i<=degree) ? a[i] : 0;
                    int y = (i<=p.degree) ? p.a[i] : 0 ;


                    int sum =  x+y;

                    if(sum != 0 ){
                        cout<<sum;

                        if(i>0){
                            cout<<"x";

                        }
                        if(i>1){
                            cout<<"^"<<i;

                        }

                        if(i>0){
                            cout<<"+";
                        }
                    }
                }

                    cout<<endl;



                

            }
        };

int main(){

    polynomial p1,p2;

    cout<<"Enter Degree of 1st Polynomial:"<<endl;
    p1.input();

    cout<<"Enter the Degree of 2nd Polynomial:"<<endl;
    p2.input();

    cout<<"First Polynomial:"<<endl;
    p1.display();

    cout<<"Second Polynomial:"<<endl;
    p2.display();

    p1.add(p2);



}

