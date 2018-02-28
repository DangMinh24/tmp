
/* 
 * Filename: program4.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 4
 * Description: Copy array Program
 */


#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std; 


//Declare functions for action 1 and 2
void printArray(int myArray[] ,int size);
void copyArrays(int sourceArray[],int size_1,int destArray[], int size_2, int start_1, int start_2, int numcopy );
int main(int argc, char** argv) {
    //Initialize variables
    int size_Array1=8;                 //Declare size of Array with variables
    int size_Array2=15;
    int numArray[size_Array1];        //Input Array
    int initArray[size_Array2];      //Default Array for paste
    float sum=0;            //To get floating point-> Use float
    int min;                
    int numCopy;            //Number of element want to copy from input Array
    int startArray_1;
    int startArray_2;
    int input;              // To save each elements of input array
    
    //Initialize 1 for array
    for(int i=0;i<size_Array2;i++){
        initArray[i]=1;
    }
    
    
    cout << "Enter 8 integers to initialize the array." << endl;
    for (int i=0 ; i<size_Array1 ; i++ ){ //Read each input and assign in correct order
        cout << "Enter element at position " << i <<" : ";
        cin >> input;
        numArray[i]=input;
    }
    cout<<endl;
    
    //Action (1): Using function to print elements of array
    printArray(numArray,size_Array1);
    
    //Action (2): Print the array in reverse order to the screen
    cout <<"The elements of the array in reverse order are: ";
    for (int i=7;i>=0;i--){
        cout << numArray[i] << " ";
    }
    cout<<endl;

    //Action (3):Calculate the sum of the square root of each element
    cout <<"The sum of the square roots for each element is: ";
    for (int i=0;i<size_Array1;i++){ 
        sum+=sqrt(numArray[i]);
    }
    cout << fixed <<setprecision(2) << sum; //Fixed precision
    cout <<endl;
    
    //Action (4):Find the minimum element in the array
    cout <<"The value of the smallest element is: ";
    min=numArray[0];
    for (int i=0;i<size_Array1;i++){
        if(min>numArray[i]){
            min=numArray[i];
        }
    }
    cout << min<<endl;
    cout<<endl;
    
    //Input necessary variable for copy process
    cout << "Enter your copy request." <<endl;
    cout << "Please enter how many elements you want to copy from the first array to the second array: ";
    cin >> numCopy;
    
    cout <<"Please enter starting position for the first array: ";
    cin >> startArray_1;
    cout << "Please enter starting position for the second array: ";
    cin >> startArray_2;
    
    cout<<endl;
    if (startArray_1+numCopy>size_Array1){ //If the subarray that want to copy outside the boundary
        cout <<"Cannot copy the elements because your request is not within the first array's boundaries"<<endl;
        return -1;
    }else if (startArray_2+numCopy>size_Array2){ // If the place want to copy out of boundary
        cout <<"Cannot copy the elements because your request is not within the second array's boundaries."<<endl;
        return -1;
    }
    else{   //If both variables are valid
        
        //Action (5): Copy the elements of the array to another array
        copyArrays(numArray,size_Array1,initArray,size_Array2,startArray_1,startArray_2,numCopy);

        return 0;
    }
}

void printArray(int myArray[] ,int size){
    cout <<"The elements of the array are: ";
    for( int i=0;i<size;i++){
        cout <<myArray[i]<<" ";
    }
    cout <<endl;
    return;
}
void copyArrays(int sourceArray[],int size_1,int destArray[], int size_2, int start_1, int start_2, int numcopy ){
    for( int i=0;i< numcopy;i++){
        destArray[start_2+i]=sourceArray[start_1+i];
    }
    cout <<"The elements of the second array are: ";
    for (int i=0; i< size_2; i++){
        cout << destArray[i] << " ";
    }
    cout <<endl;

    return;
}

