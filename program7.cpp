
/*
 * Filename: program7.cpp
 * Name: Dang M Tran
 * WSUID: S856F975
 * HW: Assignment 7
 * Description: Find best NBA players using struct prototype using dynamic allocate 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
struct player{
    string firstName;
    string lastName;
    double points;
    double minutes;
    double ratio;           //Save ratio at once for convenience
};

void readData(player &p);
void printData(player p);
player MVP(player *p,int numsPlayers);
void announceMVP(player p);

int main(int argc, char** argv) {
    
    int numPlayers;
    cout << "How many players will you enter? ";
    cin >> numPlayers;
    cout << endl;
    
    player * listPlayers;               //dynamic locating
    listPlayers= new player[numPlayers];
    
    for(int i=0; i< numPlayers;i++){
        readData(listPlayers[i]);
        cout<<endl;
    }
    
    player BestPlayer=MVP(listPlayers,numPlayers);
    announceMVP(BestPlayer);
  
    delete[] listPlayers;
    
    return 0;
}

void readData(player &p){                   //Read data for each player + compute ratio
    cout <<"Enter first name: ";
    cin >> p.firstName;
    cout <<"Enter last name: ";
    cin >> p.lastName;
    cout <<"Enter points: ";
    cin >>p.points;
    cout << "Enter minutes: ";
    cin >>p.minutes;
    
    p.ratio=p.points/p.minutes;
    return;
}

void printData(player p){
    cout <<p.firstName<<endl;
    cout <<p.lastName<<endl;
    cout <<p.points<<endl;
    cout <<p.minutes<<endl;
    return;
}

player MVP(player *p,int numsPlayers){      //Find player with best ratio
    player bestPlayer=p[0]; 
    for(int i=0;i <numsPlayers;i++){
        if(bestPlayer.ratio<p[i].ratio){
            bestPlayer=p[i];
        }
    }
    
    return bestPlayer;
}

void announceMVP(player p){                 //Announce best player
    cout<<"The maximum ratio of points per minute is: " <<setprecision(2)<<p.ratio<<endl;
    cout<<"Players with maximum ratio of points per minute: "<<p.firstName<<" "<<p.lastName<<endl;
    return;
}