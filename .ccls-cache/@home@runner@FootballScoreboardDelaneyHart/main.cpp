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
        name = "DefaultTeamName"; 
        timeout_Count = 0; //I don't actually know what this is
        coach_Name = "DefaultCoachName"; 
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
  
};

int main() {
  //1 scoreboard and 2 teams
  Team team1;
  Team team2;
  Scoreboard sb;
  
}