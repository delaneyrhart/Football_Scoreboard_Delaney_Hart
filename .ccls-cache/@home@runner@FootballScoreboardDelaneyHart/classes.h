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
        visitor_coachName = "Steve Sarkisian";
        home_City = "Austin";
        visitor_City = "Lubbock";
        score = 0; 
        home_Status = false; //visitor = false, home = true
        timeout_Count = 0; //I don't actually know what this is
     }
    void setScore(int s) { score = s; }
    void setHomeStatus(bool hs) { home_Status = hs; }
    void setHome_City(string hc) {home_City = hc; }
    void setVisitor_City(string vc) {visitor_City = vc; }
    void setName1(string n1) { name1 = n1; }
    void setName2(string n2) {name2 = n2; }
    void setTimeout(int tc) {  timeout_Count = tc; }
    void setCoachName(string hcn) { home_coachName = hcn; }
    void setCoachName2(string vcn) {visitor_coachName = vcn; }
    int getScore() const { return score; }
    bool getHomeStatus() const { return home_Status; }
    string getHome_City() const {return home_City; }
    string getVisitor_City() const {return visitor_City; }
    string getName1() const { return name1; }
    string getName2() const { return name2; }
    int getTimeout() const { return timeout_Count; }
    string getCoachName() const { return home_coachName; }
    string getCoachName2() const {return visitor_coachName; }
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
    int getDown() const { return down; }
    int gettoGo () const { return toGo; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[45;1m"; //pink for numbers
      string score = "\x1b[36;4m"; //blue for teams
      string title = "\x1b[46;1m"; //title
      cout << title << "\t\tFOOTBALL SCOREBOARD PROGRAM\n\n" << reset << endl;
      cout << " " << score << home.getName1() << reset << "\t\t\t\t\t\t" << score << visitor.getName2() << reset << endl; //to keep track of teams
      cout << " " << home.getHome_City() << "\t\t\t\t\t\t\t" << visitor.getVisitor_City() << endl;
      cout << " " << home.getCoachName() << "\t\t\t\t\t" << visitor.getCoachName2() << endl; //keep track of coaches
      cout << " _______________________________________________" << endl;
      cout << "|     HOME" << "                          " 
            << "VISITOR     |" << endl;
      cout << "|\t\t" << color << home.getScore() << "\t\t\t\t\t\t\t\t" << visitor.getScore() << reset << "\t\t|" << endl; 
      cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
      cout << "|" << " TO LEFT\t\t\t" << " QTR " << color << qtr 
        << reset << "\t\t\t\tTO LEFT "<< "|" << endl;
      cout << "|\t" << color << home.getTimeout() << "\t\t" << down << reset << " DOWN" << "\t\t\t" << " TO GO " << color << toGo << "\t\t" << visitor.getTimeout() << reset << "\t|" << endl;
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
         cout << "Default"; 
       }
       cout  << endl; 
    }
  
};