


/*
 * Filename: program6.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 6
 * Description: Sorting strings array using dynamic arrays, alphabetically sorting and selection sort algorithm
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * 
 */
void selectionsort(string *input,int numWords);
int main(int argc, char** argv) {
    
    //Initialize variable
    int numWords;
    string * strArray;
    string input;
    
    //Input number of words
    cout <<"How many words will you enter? ";
    cin>>numWords;
    cout<<endl;
    
    strArray=new string[numWords];//dynamically allocate
    
    for(int i=0;i<numWords;i++){    // Input each words
        cout<<"Enter a word: ";
        cin>>input;
        if(input=="0"){             // If input is "0", exits
            break;
        }
        strArray[i]=input;
    }
    
    selectionsort(strArray,numWords);
    
    
    //Print output
    cout<<endl;
    cout<<"Your sorted list is: ";
    for (int i=0;i< numWords;i++){
        cout <<strArray[i]<<" ";
    }
}

void selectionsort(string *input,int numWords){ //Using bubble sort + alphabetical sorting
    for(int i=0;i<numWords-1;i++){
        for (int j=i+1;j<numWords;j++){
            string A= input[i];
            transform(A.begin(),A.end(),A.begin(),::tolower);
            string B= input[j];
            transform(B.begin(),B.end(),B.begin(),::tolower);
            
            string tmp;
            if(A>B){
                tmp=input[i];
                input[i]=input[j];
                input[j]=tmp;    
            }
                
        }
    }
    return ;
}