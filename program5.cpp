

/*
 * Filename: program5.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 5
 * Description: Encrypt, decrypt with text 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string encode(string input);
string decode(string input);
int main(int argc, char** argv) {
    //Initialize variables
    string message;
    string encodeMessage;
    string decodeMessage;
    
    //Input
    cout << "Enter a message: ";
    getline(cin,message);
    
    //Upper input
    for(int i=0 ; i<message.length() ; i++){
        message[i]=char(toupper(message[i]));
    }
    cout<< message <<endl;
    
    //Encoding input
    encodeMessage=encode(message);
    cout << encodeMessage;
    cout <<endl;
    
    
    //Decoding input
    decodeMessage=decode(encodeMessage);
    cout << decodeMessage;
    cout << endl;
}

string encode(string input){
    for( int i=0; i< input.length() ; i++){
        if (isalpha(input[i])){
            input[i]=((input[i]+4-65)%26)+65; //The formula is explain below
        }
    }
    return input;
}

string decode(string input){
    for( int i=0; i< input.length() ; i++){
        if (isalpha(input[i])){
            input[i]=((input[i]-4-65)%26)+65; //The formula is explain below
        }
    }
    return input;
}

// Explain formula:
// x%n operator will give result in range (0,n-1)
// x%n +a will give result in range (a,n-1+a)
// we want the range in (65,90) -> a=65, n=26
// To shift by 4, we have the formula as above