#include <iostream>
#include <vector>
using namespace std;

class Point {
    /*
    'x' is the width  of the grid
    'y' is the height of the grid
    
    'x1' is the coordinate of the width 
    'y1' is the coordinate of the height
    
    'N' is number of generations
    
    'countOfPoint' is how many times does it occur in (x1,y1)
    
    */
    
    private:
        int x=false, x1, y=false, y1, N, countOfPoint = 0;
    public:
        int neighbours[8][8];
        vector<vector<int> > initVector;
        // Point(int setX, int seY);// This is the constructor
        
        // Set and Get methods
        int getX(){
            return x;
        }
        
        int getY(){
            return y;
        }
        
        int getX1(){
            return x1;
        }
        
        int getY1(){
            return y1;
        }
        
        int getN(){
            return N;
        }
        
        int getCountOfPoint(){
            return countOfPoint;
        }
        
        void setX( int setX ) {
           x = setX;
        }
        
        void setY( int setY ) {
           y = setY;
        }
        
        void setX1( int setX1 ) {
           x1 = setX1;
        }
        
        void setY1( int setY1 ) {
           y1 = setY1;
        }
        
        void setN( int setN ) {
           N = setN;
        }
        
        // set the grid of type XxY (width x height)
        void generationZero(){
        
            if(initVector.size() == 0){
                initVector.resize(x); // x rows
                for(int i = 0; i < x; ++i)
                    initVector[i].resize(y);// in every row, create y columns
                
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        cin >> initVector[i][j]; // input value for grid position
                    }
                }
            }else{
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        if(neighbours[i][0] == 3 || neighbours[i][0] == 6){
                            initVector[i][j] = 1;
                        }else if(neighbours[i][1] != 2 && neighbours[i][1] != 3 && neighbours[i][1] != 6){
                            initVector[i][j] = 0;
                        }else {
                            initVector[i][j] = rand() % (1 + 1);
                        }
                    }    
                }
                
            }
            
            if(initVector[x1][y1] == 1){
                countOfPoint++;
            }
        }
};

// // Member functions definitions including constructor
// Point::Point(int initX, int initY) {
//   cout << "Grid is being created, width = " <<initX<< " height = " <<initY<< endl;
//   x = initX;
//   y = initY;
// }

// NewGenerations class inheritance Point class
class NewGenerations: public Point{
    
    public:
        //NewGenerations(int x, int y):Point(x,y){};
        
        // generation new grids
        void newGeneration(){
            for(int i = 1; i < getN(); ++i){
                generationZero();
            }
        }
        
        // count neighbours in each row
        void countNeighbours(){
            // count of 0s and 1s
            int br_0 = 0, br_1 = 0;
    
            for (int i = 0; i < getX(); i++) {
                br_0 = 0;
                br_1 = 0;
                for (int j = 0; j < getY(); j++) {
                    if((initVector[i][j] == 1 && initVector[i][j-1] == 1) || initVector[i][j] == 1){
                        br_1++;
                    }
                    
                    if((initVector[i][j] == 0 && initVector[i][j-1] == 0) || initVector[i][j] == 0){
                        br_0++;
                    }
                }
                neighbours[i][0] = br_0;
                neighbours[i][1] = br_1;
            }
        }
    
};

// Main function for the program
int main(void) {
    int x=0, x1, y=0, y1, N, choose;
    
    // NewGenerations point(x,y);
    NewGenerations point; // definition variable of class
    
    // menu
    do
	{
		cin.sync();
		cout << "\n\t Make your choice \n";

		cout << "1. Set grid size. \n";
		cout << "2. Set coordinates.\n";
		cout << "3. Set number of generations.\n";
		cout << "4. Print Result\n";
		cout << "0. Exit\n";

		cout << "\t Set number :";
		while (!(cin >> choose))
		{
			cout << "\n\t Choose again!" << endl;
			cin.clear();
// 			cin.ignore(INT_MAX, '\n');
		}
        cout<<endl;

		switch (choose)
		{
		case 1: {
		    cout<<"The size of our Grid: "<<endl;
            cout<<"width: "; cin>>x;
            cout<<"height: "; cin>>y;
            
            point.setX(x);
            point.setY(y);
            
            // or Point Point(x,y);
		}; break;
		case 2: {
		    cout<<"Set the x1 and y1 coordinates: "<<endl;
            cout<<"x1: "; cin>>x1;
            cout<<"y1: "; cin>>y1;
            
            point.setX1(x1);
            point.setY1(y1);
		}; break;
		case 3: {
		    if(point.getX() and point.getY()){
    		    cout<<"Set number of generations: "<<endl;
                cout<<"N: "; cin>>N;
                
                point.setN(N);
                cout<<"Set first grid: "<<endl;
                point.generationZero();
                point.countNeighbours();
                point.newGeneration();
		    }else{
		        cout<<"First set size of Grid!"<<endl;
		    }
		}; break;
		case 4: cout<<"Result is: "<<point.getCountOfPoint()<<endl; break;
		}
	} while (choose != 0);
    
    return 0;
}