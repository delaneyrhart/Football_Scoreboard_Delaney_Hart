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
    string name1;
    string name2;
    string home_coachName;
    string visitor_coachName;
    string home_City;
    string visitor_City;
    bool home_Status;
    int score;
    int timeout_Count;
  public:
    Team() //default constructor
    {
        name1 = "Longhorns";
        name2 = "Red Raiders";
        home_coachName = "Joey McGuire";
        visitor_coachName = "";
        home_City = "Austin";
        visitor_City = "Lubbock";
        score = 0; 
        home_Status = false; //visitor = false, home = true
        timeout_Count = 0; //I don't actually know what this is
     }
    void setScore(int s) { score = s; }
    void setHomeStatus(bool hs) { home_Status = hs; }
    void setName1(string n1) { name1 = n1; }
    void setName2(string n2) {name2 = n2; }
    void setShotsOnGoal(int tc) {  timeout_Count = tc; }
    void setCoachName(string cn) { coach_Name = cn; }
    int getScore() const { return score; }
    bool getHomeStatus() const { return home_Status; }
    string getName1() const { return name1; }
    string getName2() const { return name2; }
    int getShotsOnGoal() const { return timeout_Count; }
    string getCoachName() const { return coach_Name; }
};

class Scoreboard
{
  private:
    Team home;
    Team visitor;
    int qtr; //The quarter (1-4)
    int down; //Also 1-4
    int toGo; //Yards to go
  public:
    Scoreboard() //Default constructor?
    { qtr = 0; 
      down = 0;
      toGo = 0; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    void setQtr(int q) { qtr = q; }
    void setDown(int d) { down = d; }
    void setToGo(int tG) { toGo = tG; }
    int getQtr() const { return qtr; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[45;1m"; //pink for numbers
      string score = "\x1b[36;4m"; //blue for teams
      string title = "\x1b[46;1m"; //title
      cout << title << "\t\tFOOTBALL SCOREBOARD PROGRAM\n\n" << reset << endl;
      cout << " " << score << home.getName1() << reset << "\t\t\t\t" << score << visitor.getName2() << reset << endl; //to keep track of teams
      cout << " " << home.getCoachName() << "\t\t\t\t\t" << visitor.getCoachName() << endl; //keep track of coaches
      cout << " _______________________________________________" << endl;
      cout << "|     HOME" << "                          " 
            << "VISITOR     |" << endl;
      cout << "|\t\t" << color << home.getScore() << "\t\t\t\t\t\t\t\t" << visitor.getScore() << reset << "\t\t|" << endl; 
      cout << "|                    QTR " << color << qtr 
        << reset << "                      |" << endl;
      cout << "|\t\t\t" << color << down << reset << " DOWN" << "\t\t\t\t" << "TO GO " << color << toGo << reset << "\t\t\t|" << endl;
      cout << "|_______________________________________________|" << endl;

      cout << "\n******MENU******" << endl;
       //proces to choose the home team
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName1() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName2() << "*"; 
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

  sb.setHome(team1);
  sb.setVisitor(team2);

    do 
  {
      system("clear"); //clear the screen of previous content 
      sb.showScoreboard(); //show the current scoreboard data
      //menu options 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Coach" << endl; 
      cout << "C = Update Home Team Score" << endl;
      cout << "D = Update Home Team City" << endl;
      cout << "E = Update Visiting Team Name" << endl; 
      cout << "F = Update Visiting Team Coach" << endl; 
      cout << "G = Update Visiting Team Score" << endl;
      cout << "H = Update Visiting Team City" << endl;
      cout << "Q = Update Quarter" << endl; 
      cout << "X - Exit" << endl;
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        cout << "\nChoose the Home Team" << endl; 
        cout << "\nWho is the home team? 1 = Team 1, 2 = Team 2: "; 
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