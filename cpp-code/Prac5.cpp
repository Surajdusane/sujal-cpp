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
            bool first = true;

            for(int i = degree ; i>=0 ; i--){
                if(a[i]==0){
                    continue;
                }

                if(!first && a[i]>0){
                    cout<<"+";
                }

                if(i==0){
                    cout<<a[i];
                }
                else{
                    if(a[i]!=1 && a[i]!=-1){
                        cout<<a[i];
                    }
                    else if(a[i]==-1){
                        cout<<"-";
                    }

                    cout<<"x";

                    if(i>1){
                        cout<<"^"<<i;
                    }
                }

                first = false;
            }

            if(first){
                cout<<"0";
            }

            cout<<endl;
        }

            void add(polynomial p){
                int max = (degree>p.degree) ? degree : p.degree;

                polynomial sum;
                sum.degree = max;

                for(int i = 0 ; i<=max ; i++){
                    int x = (i<=degree) ? a[i] : 0;
                    int y = (i<=p.degree) ? p.a[i] : 0 ;

                    sum.a[i] = x + y;
                }

                cout<<"Sum: ";
                sum.display();
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

