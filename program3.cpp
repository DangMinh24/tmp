
/* 
 * Filename: program3.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 3
 * Description: A program simulates encrypt and decrypt prototype
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int readNumber(){
    int input;
    cin >> input;
    if (input <0 or input >9999 ){// Check for negative number or more than 4 digits
        cout << "You must enter a four digit nonnegative number!" <<endl;
        return -1;      // Return a negative number that is used for condition in main flow
    }
    else {
        return input;   //Else the value is valid
    }   
}

int encrypt(int data){
    int digits[4];  //Array to save each digits from data 
    int digit;      
    
    for( int i=3 ; i >=0 ; i--){    //Use i as index to digits. Access from right to left
        digit = data%10;            //split integer value into each digit
        data = data/10;             //update new value
        digits[i]=digit;            
        digits[i]=(digits[i]+7)%10; //Encrypting by formula
    }
    
    int swap_tmp;                   //temporary variable for swapping
    //Swap 1st and 4th element
    swap_tmp=digits[0];
    digits[0]=digits[3];
    digits[3]=swap_tmp;
    
    //Swap 2nd and 3rd element
    swap_tmp=digits[1];
    digits[1]=digits[2];
    digits[2]=swap_tmp;
    
    // Combine digits list into integer number
    int encryptedData=0;
    for( int i=3 ; i>=0 ;i-- ){     //Combine all digits as method: value= 1st*10^3 + 2nd*10^2 +3rd*10^1 +4th*10^0 
        encryptedData+=digits[i]*pow(10,3-i);
    }
    return encryptedData;
}
int decrypt(int data){
    int digits[4];
    int digit;
    
    for( int i=3 ; i >=0 ; i--){    //Use i as index for digits, access from right to left 
        digit = data%10;            //Split integer into digits  
        data = data/10;             //Update data
        
        digits[i]=digit;
        digits[i]=(digits[i]+3)%10;  //Decrypt using formula
    }
    
    int swap_tmp;
    //swap 1st and 4th
    swap_tmp=digits[0];
    digits[0]=digits[3];
    digits[3]=swap_tmp;
    
    //swap 2nd and 3rd
    swap_tmp=digits[1];
    digits[1]=digits[2];
    digits[2]=swap_tmp;
    
    //Combine digits into single integer
    int decryptedData=0;
    for( int i=3 ; i>=0 ;i-- ){
        decryptedData+=digits[i]*pow(10,3-i);
    }
    return decryptedData;

    
}
int main(int argc, char** argv) {
    //Initialize variable
    int op;
    int data;
    int encrypted_data;
    int decrypted_data;
    
    cout << "Select one of the following:\n"
            " 1. Encode a number.\n"
            " 2. Decode a number.\n";
    cout << endl;
    cout << "Enter choice: ";
    cin >> op;
    cout << endl;
    
    switch (op){ //Op to control the menu
        case 1:
            cout << "Enter the four digit number: ";
            data=readNumber();
            if (data == -1){    //If data is invalid -> break
                break;
            }else{  //If data is valid -> do encrypt
                encrypted_data=encrypt(data);
                cout << "The encrypted number is:" << encrypted_data << endl;
                break;
            }
        case 2:
            cout << "Enter the four digit number: ";
            data=readNumber();
            if (data==-1)       //If data is invalid -> break
                break;
            else{
                decrypted_data=decrypt(data); //If data is valid -> do decrypt
                cout << "The decrypted number is:" << decrypted_data << endl;
                break;
            }
        default: //If not valid option
            cout << "Wrong choice. Try again...";   
            break;
    }
}

