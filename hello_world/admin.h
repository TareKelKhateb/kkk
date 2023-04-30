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




	void set_pass(string pass){
		password=pass;
	}

};

#endif
