/* Delaney Hart
COSC 1437 - Dr. McMillan
4/16/2022
A program meant to replicate a football scoreboard
*/
#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"
using namespace std;

class Team
{
  private:
    string name;
    string coach_Name;
    string home_City;
    bool home_Status;
    int score;
    int timeout_Count;
  public:
    Team() //default constructor
    {
        score = 0; 
        home_Status = false; //visitor = false, home = true
        timeout_Count = 0; //I don't actually know what this is
     }
    void setScore(int s) { score = s; }
    void setHomeStatus(bool hs) { home_Status = hs; }
    void setName(string n) { name = n; }
    void setShotsOnGoal(int tc) {  timeout_Count = tc; }
    void setCoachName(string cn) { coach_Name = cn; }
    int getScore() const { return score; }
    bool getHomeStatus() const { return home_Status; }
    string getName() const { return name; }
    int getShotsOnGoal() const { return timeout_Count; }
    string getCoachName() const { return coach_Name; }
};

class Scoreboard
{
  private:
    Team home;
    Team visitor;
  public:
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color
      cout << "***********SCOREBOARD**********" << endl;
      cout << " _______________________________________" << endl;
      cout << "| HOME" << "                          " 
            << "VISITOR |" << endl;
      cout << "|" << home.getName() << "\t\t\t\t" << visitor.getName() << endl; 
      cout << "| QTR" << endl;
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << score << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << endl; 
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to choose the home team
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       cout  << endl; 
    }
  
};

int main() {
  //1 scoreboard and 2 teams
  Team team1;
  Team team2;
  Scoreboard sb; 
  string userChoice = ""; 
  string newName = "";
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 



    do 
  {
      system("clear"); //clear the screen of previous content 
      sb.showScoreboard(); //show the current scoreboard data
      //menu options 
      cout << "A - Update Home Status" << endl;
      cout << "C - Update Home Team City" << endl;
      cout << "D - Update Home Team Score" << endl;
      cout << "X - Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
      
        //change that home team's default name
        team1.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        team1.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          team1.setHomeStatus(true); 
          team2.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          team1.setHomeStatus(false); 
          team2.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl; 
        }
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          team2.setCoachName(newCoachName); 
      }
      else if(userChoice == "X" || userChoice == "x")
      {
        cout << "Exiting...Bye!" << endl; 
      }
      else 
      {
        cout << "\nInvalid input. Please try again." << endl;  
      }

      sb.setHome(team1); //refresh the data in s to the new updates...
      sb.setVisitor(team2); //refresh the data
  
  }while(userChoice != "X" && userChoice != "x");

};