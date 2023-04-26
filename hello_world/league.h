#pragma once
#include<iostream>
#include"Team.h"
#include<vector>
using namespace std;

class Leagues {

private:

	int leagueId;
	int numOfTeams = 0;



public:
    string leagueName;
    vector<Team> teams;
    Leagues();
	Leagues(string name, int ID);
	Leagues(string name, int ID, vector<Team> t);


	void addTeam(Team team);
	void deleteTeam(string teamName);

	string displayLeagueName();
	int getLeagueId();
	int getIndex(string teamName);
	int getNumOfTeams();
    void setID(int id);






};
