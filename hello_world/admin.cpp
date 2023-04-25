
#include "admin.h"
#include<iostream>


admin::admin(string set_admin, string set_password){
	//user_name(set_username),password(set_pass)
	set_pass("admin");
	set_user("admin");
}

admin::admin(){
    //user_name(set_username),password(set_pass)
    set_pass("admin");
    set_user("admin");
}


void admin::add_team(int league_num , Team new_team){


    leagues[league_num].addTeam(new_team);

}

void admin::add_league(string name , int id){
	
	Leagues l(name, id);
	leagues.push_back(l);
}


void admin::update(Team teams,int pl_id){
	
	
}

int admin::get_player_an_id(){

    player_id_generator++;
    return player_id_generator;

}
