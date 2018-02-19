
/* 
 * Filename: program2.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 2
 * Description: A program to compute Body Mass Index (BMI) by using input weight and height 
 * with the formula BMI=weight/(height^2 )
 */
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(int argc, char ** argv) {

    //Initialize input variables
    float minWeight;    //Type of Weight and Heigh should be both float  
    float maxWeight;
    float WeightStep;    
    
    float minHeight;    
    float maxHeight;
    float HeightStep;
    
    //Create variable for storing results
    float WeightStack[1000];   //Array to store weight values each weight steps
    int numWeightStackElements=0;   //number of element in WeightStack
                                    //There are 0 elements when first created
    
    float HeightStack[1000]; //Array to store height values each height steps 
    int numHeightStackElements=0; //number of element in HeightStack
        
    float BMI[1000][1000]={}; //A matrix used to save the results. Initialize with 0 
    
    char op='y';    //Input operator to control the flow of infinity-loop
                    //  1/ 'y' or 'Y'-> compute and show table
                    //  2/ 'n' or 'N'-> Exit the loop
                    //  3/ Otherwise, have to re-enter the operator
    
    do{
        if (op=='y' || op=='Y'){ //Character compare should use SINGLE QUOTATION MARK instead double
            cout << "This program can calculate the BMI of a person for given limits and value "
                    "steps and creates a matrix based on these inputs."<<endl;
            cout << endl;

            // Enter necessary input
            cout << "Please enter minimum weight in kg: ";
            cin >> minWeight;
            cout << "Please enter maximum weight in kg: ";
            cin >> maxWeight;
            cout << "Please enter weight step in kg: ";
            cin >> WeightStep;
            cout << "Please enter minimum height in meters: ";
            cin >> minHeight;
            cout << "Please enter maximum height in meters: ";
            cin >> maxHeight;
            cout << "Please enter height step in meters: ";
            cin >> HeightStep;

            cout << endl;
            cout<<"The BMI for the given inputs is the following: "<<endl;
            cout<<endl;

            /*Refresh our Matrix from last computation
            //  1/  Can re-use the matrix again, that element in WeightStack and HeightStack =0
            //      but this method won't give the completely correct matrix (the last computation can still be stored in the matrix too) 
            */ 
            //numWeightStackElements=0; //Uncomment this part to do method 1
            //numHeightStackElements=0;
            
            //  2/ Refresh all the value in BMI to 0 before doing any computations
            for(int i=0 ; i< numWeightStackElements ; i++){
                for ( int j=0 ; j < numHeightStackElements ; j++){
                    BMI[i][j]=0;
                }
            }
            numWeightStackElements=0;
            numHeightStackElements=0;
            
            
            //Initialize Weight Array
            for (float i=minWeight; i<=maxWeight;i+=WeightStep){     
                WeightStack[numWeightStackElements]=i;
                numWeightStackElements++; //Each time a new element assigned, number of element increase 1
            }
            
            //Initialize Height Array
            for (float j= minHeight; j<maxHeight; j+=HeightStep){ //according to example, DO NOT CONTAIN FINAL VALUE  
                
                HeightStack[numHeightStackElements]=j;
                numHeightStackElements++; //Each time a new element assigned, number of element increase 1
            }

            //Compute value and assign to the matrix
            for (int i=0 ; i< numWeightStackElements;i++){
                for(int j=0 ; j < numHeightStackElements;j++){
                    BMI[i][j]=WeightStack[i]/pow(HeightStack[j],2);
                }
            }
            
            //Print results as standard table
            cout<<"Height\t";
            for(int i=0 ; i<numHeightStackElements;i++){
                cout<<setprecision(2)<<fixed <<HeightStack[i]<<"\t";
            }
            cout<<endl;
            cout<<"Weight"<<endl;

            for(int i=0;i<numWeightStackElements;i++){
                cout<<setprecision(2)<<fixed <<WeightStack[i]<<"\t"; 
                for(int j=0;j<numHeightStackElements;j++){
                    cout<<setprecision(2)<<fixed <<BMI[i][j]<<"\t";
                }
                cout<<endl;
            }
            
            //Choose next action: 1/Yes 2/No
            cout <<"Do you want to repeat (Y/N)?"<<endl;
            cin>>op;
        }
        else if( op=='n' || op =='N'){//If don't want to do anymore
            cout<<"Program Quitting..."<<endl;
            return 0; //Escape program 
        }
        else{// If choice is neither "y" or "n" -> need to choose again
            cout<<"Invalid Input! Please answer Y or N: ";
            cin >>op;
        }
        
    }   while(1); //Infinity-loop, so must specific exit cases (when op=="n"|| op == "N" in this case)
    
    return 0;
}

