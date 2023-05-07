#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<vector>
#include"league.h"
#include <map>
class admin 
{	
	private:
	string user_name ="admin";
	string password = "admin";
    int league_id_generator =1;
    int team_id_generator =1;

    public:

        int player_id_generator =1;

        map<int,player>players_map;
		vector<Leagues>leagues;
		void add_league(string league_name, int id);
		admin(string set_admin,string set_pass);
        admin();
        void add_team(int league_num , Team new_team);
		int gw_num = 0;//game week counter
		void update(Team,int);
        int get_player_an_id();
        void find_player_by_name(bool &found,int &legindx,int &tmindex,int &pindex,string name);

	std::string get_user_name() const {
		return user_name;
	}

	std::string get_password() const {
		return password;
	}
	void set_user(string user) 
	
	{
		user_name = user;
	}

    int get_league_id(){

        league_id_generator+=1;
        return (league_id_generator);
    }

    int get_team_id(){

        team_id_generator+=1;
        return (team_id_generator);
    }



	void set_pass(string pass){
		password=pass;
	}

    void set_league_id(int id){
        league_id_generator=id;
    }
    void set_team_id(int id){
        team_id_generator=id;
    }

};

#endif
