#include "Deck.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include<algorithm>
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
//bool hasPair(const vector<Card> &pair);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
//ostream & operator<<(ostream &out, const vector<Card> &print);
ostream & operator<<(ostream &out, const vector<Card> &print){
    for(unsigned int i =0; i < print.size()-1; i++){
        out << print[i] << ",";
         }
         out << print[print.size()-1];
         return out;
}
 
 
bool hasPair(const vector<Card> &pair){
    
    for(unsigned i = 0; i < pair.size(); i++){
        for(unsigned x = i+1; x < pair.size(); x++){
            if(pair[i].getRank() == pair[x].getRank()){
                return true;
            }
        }
    }
    return false;
}

 int main(){
     double percentage;
     int numcards, deals;
     int match = 0;
     vector <Card> player;
     Deck hand;
     ofstream myfile;
     string file;
     string filename ="";
     srand(2222);
     
    cout <<"Do you want to output all hands to a file?(Yes/No) ";
    cin >> file;
    cout << endl;
   
    if(file == "Yes" || file == "yes"){
        cout << "Enter name of output file: ";
        cin >> filename;
        cout << endl;
       myfile.open(filename.c_str());
       
       if(!myfile.is_open()){
           cout <<"Error opening file: " << filename << endl;
           return 1;
       }
        }
   
    cout <<"Enter number of cards per hand: ";
    cin >> numcards;
    cout << endl;
    cout <<"Enter number of deals (simulations): ";
    cin >> deals;
    cout << endl;
    
    for( int i = 0; i < deals; i++){
        //hand.shuffleDeck();
        for(int x = 0; x <= numcards; x++){
            player.push_back(hand.dealCard());
            
        }
        if(hasPair(player)){
            
            match+=1;
        
            if(myfile.is_open()){
                myfile << "Found Pair!! " << player << endl;
             }
        }
        else{
            myfile << "\t\t\t " << player << endl;
        }
        
        hand.shuffleDeck();
        cout << hand.deckSize();
        player.clear();
    
    }
   percentage = ((match*1.0)/(deals*1.0))*100.0;
    myfile.close();
     cout << "Chances of receiving a pair in a hand of " << numcards << " cards is: " << percentage << "%" << endl;
    
    
     
     
     return 0;
     
 }




    
    