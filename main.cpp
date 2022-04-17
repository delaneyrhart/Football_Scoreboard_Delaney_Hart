/* Delaney Hart
COSC 1437 - Dr. McMillan
4/16/2022
A program meant to replicate a football scoreboard
*/
#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

int main() {
  //1 scoreboard and 2 teams
  Team team1;
  Team team2;
  Scoreboard sb; 
  string userChoice = ""; 
  string newName = "";
  string newName2 = "";
  string newHomeCoachName = ""; 
  string newVisitingCoachName = "";
  string newHomeCity = "";
  string newVisitorCity = "";
  int homeTeamQuestion = 0; 
  int newScore = 0; 
  int newQtr = 0;
  int newTimeOut = 0;

  sb.setHome(team1);
  sb.setVisitor(team2);

    do 
  {
      system("clear"); //clear the screen of previous content 
      sb.showScoreboard(); //show the current scoreboard data
      //menu options 
      cout << "A = Update Home Team Status" << endl; 
      cout << "B = Update Home Team Name" << endl;
      cout << "C = Update Home Team Coach" << endl; 
      cout << "D = Update Home Team City" << endl;
      cout << "E = Update Home Team Score" << endl;
      cout << "F = Update Visiting Team Name" << endl; 
      cout << "G = Update Visiting Team Coach" << endl; 
      cout << "H = Update Visiting Team City" << endl;
      cout << "I = Update Visiting Team Score" << endl;
      cout << "T = Timeout Count" << endl;
      cout << "Q = Update Quarter" << endl; 
      cout << "X - Exit" << endl;
      
      validateString(userChoice); 

      if(userChoice == "A" || userChoice == "a") //home statue
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
      else if(userChoice == "B" || userChoice == "b")//home name
      { 
        cout << "\nPlease enter a new name for the home team: ";
        validateString(newName); 
        //change team1 default name
        team1.setName1(newName);
      }
      else if(userChoice == "C" || userChoice == "c")//home coach
      {
          cout << "\nPlease enter the new home coach name: "; 
          validateString(newHomeCoachName); 
          team1.setCoachName(newHomeCoachName); 
      }
      else if(userChoice == "D" || userChoice == "d")//home city
      {
        cout << "\nPlease enter the new home team city: ";
        validateString(newHomeCity);
        team1.setHome_City(newHomeCity);
      }
      else if(userChoice == "E" || userChoice == "e") //home score
      {
        cout << "\nPlease enter a new score for the home team: "; 
        validateInt(newScore); 
        team1.setScore(newScore);
      }
      else if(userChoice == "F" || userChoice == "f")//team name
      { 
        cout << "\nPlease enter a new name for the visiting team: ";
        validateString(newName2); 
        //change team2 default name
        team2.setName2(newName2);
      }
      else if(userChoice == "G" || userChoice == "g")//coach
      {
          cout << "\nPlease enter the new visiting coach name: "; 
          validateString(newVisitingCoachName); 
          team2.setCoachName2(newVisitingCoachName); 
      }
      else if(userChoice == "H" || userChoice == "h")//city
      {
        cout << "\nPlease enter the new visiting team city: ";
        validateString(newVisitorCity);
        team2.setVisitor_City(newVisitorCity);
      }
      else if(userChoice == "I" || userChoice == "i") //score
      {
        cout << "\nPlease enter a new score for the visiting team: "; 
        validateInt(newScore); 
        team2.setScore(newScore);
      }
      else if(userChoice == "Q" || userChoice == "q")
      {
        cout << "What is the quarter? ";
        validateInt(newQtr);
      }
      else if(userChoice == "T" || userChoice == "t")
      {
        cout << "Update time out count: ";
        validateInt(newTimeOut);
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