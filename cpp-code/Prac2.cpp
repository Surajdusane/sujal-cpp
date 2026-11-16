#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int Tiles[50][50];

void display_tiles(int M,int N){

    cout<<"\nTiles to walk:\n";

    for(int i = 0; i<M ; i++){
        for(int j=0;j<N;j++)
            cout<<"__";
    
        cout<<endl;

        for(int j=0;j<N;j++)
            cout<<"|"<<i<<j;
     
        cout<<"|"<<endl;
        
    }

    for(int j = 0; j<N;j++)
        cout<<"__";

     cout<<endl;
}

int checker(int M,int N){
    for(int i=0;i<M;i++){
        for(int j = 0 ; j<N;j++){
            if(Tiles[i][j] == 0){
                return 1;
            }
        }

        return 0;
    }

}
int main(){
    srand(time(0));
    int M,N,x,y;
    int moves = 0;

    cout<<"Enter tiles dimesnion (M*N):";
    cin>>M>>N;
    cout<<"Enter the initial position:";
    cin>>x>>y;

    if(M<1||M<50||N<1||N>50 || x<0 || x>=M || y<0 || y>=N){
        cout<<"Invalid Choice;";
        return 0;
    }

    display_tiles(M,N);

    Tiles[x][y] = 1;

    cout<<"("<<x<<","<<y<<")";

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    while(checker(M,N)){
        int r = rand() % 8;

        int a = x + dx[r];
        int b = y + dy[r];
        
        if(a>=0 && a<M && b>=0 && b<N){
            x = a;
            y = b;
            Tiles[x][y] = 1;
            cout << "\n(" << x << "," << y << ")";
            moves++;
        }
    }

    cout<<"Total Moves:"<<moves;

    return 0;


    
}
