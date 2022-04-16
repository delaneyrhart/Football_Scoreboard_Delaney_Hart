/* Delaney Hart
COSC 1437 - Dr. McMillan


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
    string home_Status;
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