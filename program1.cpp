
/* 
 * Filename: program1.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 1
 * Description: The program asking the user to enter two numbers 
                and a choice of operation. Then display the result of applying the operation to numbers
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Initialize variable:
    int input1, input2;
    int op; //variable for operator
    int result; //variable to save the result of computation
    
    cout << "This program will prompt for two integers and an operation and then "
            "display the result of applying the operation to the numbers."<< endl;
    cout<<endl;
    
    //Input value of first and second variable 
    cout << "Enter the first integer: ";
    cin >> input1; 
    cout << "Enter the second integer: ";
    cin >> input2;
    
    //Input choice of operator
    cout<<endl;
    cout << "The available operators are:" << endl;
    cout << "\t1. addition"<< endl;
    cout << "\t2. subtraction"<<endl;
    cout << "\t3. multiplication"<<endl;
    cout << "\t4. division"<<endl;
    cout << "Enter the number for your choice of operation: ";
    cin >> op;
    
    cout<<endl;
    if (op == 1){
        result = input1 + input2;
        cout << input1 << " + " << input2 << " = " << result << endl;
    }else if (op == 2){
        result = input1 - input2;
        cout << input1 << " - " << input2 << " = " << result << endl;
    }else if (op == 3){
        result = input1 * input2;
        cout << input1 << " * " << input2 << " = " << result << endl;
    }else if (op == 4){
        if (input2 == 0){ // If choice is division and second variable is 0 
            // Print error
            cout << input1 << " / " << input2 << " can not be found because can't divide by zero." << endl;
        }else{ //If choice is division and second variable is NOT 0
            result = input1 / input2;
            cout << input1 << " / " << input2 << " = " <<result << endl;
        }
    }else { //Other options that not belongs to 1->4
        // Print error
        cout << op << " is an invalid operation. Valid choices were 1, 2, 3 or 4. Quitting program."<<endl; 
        cout << endl;
        return 0; //Quitting immediately without waiting to the end of the program 
    }
    
    cout << endl;   
    return 0;
}

