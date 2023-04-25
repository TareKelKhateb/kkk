#include"league.h"
#include<iostream>
#include<vector>
#include"Team.h"
using namespace std;

Leagues::Leagues(){


    leagueName = "None";
    leagueId = 0;
}


Leagues::Leagues(string name, int ID) {
    leagueName = name;
    leagueId = ID;
}
Leagues::Leagues(string name, int ID, vector<Team> t) {
    leagueName = name;
    leagueId = ID;
    teams = t;
    numOfTeams += t.capacity();
}

void Leagues::addTeam(Team team) {
    teams.push_back(team);
    numOfTeams++;

}
void Leagues::deleteTeam(string teamName) {
    int index = getIndex(teamName);
    teams.erase(teams.begin() + index);
    numOfTeams--;
}

int Leagues::getIndex(string teamName) {
    int index = -1;
    for (int i = 0; i < teams.capacity(); i++)
    {
        if (teamName == teams[i].team_name) {
            index = i;
        }
    }

    return index;
}

string Leagues::displayLeagueName() {
    return leagueName;
}

int Leagues::getLeagueId() {
    return leagueId;
}

int Leagues::getNumOfTeams() {
    return numOfTeams;
}
void Leagues::setID(int id){

    leagueId = id;
}
