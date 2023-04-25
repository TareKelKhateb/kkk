#include "user.h"

user::user() {
	username="NONE";
	password="NONE";

}
user::user(string name ,string pass) {
	username = name;
	password = pass;
	budget = 100000;

}

//add player to the array of ids 
void user::ADD_player(map<int,player> players_map,int id, int index_swap){



	//take the new id 
	player new_player = players_map[id];
	
	//if the user has the budget
	if (new_player.price <= budget) {

		//modify the array_of_ids and the array_of_players
		players_ids[index_swap] = new_player.player_id;
		players[index_swap] = new_player;
		budget -= new_player.price;
	}
	else {
		//exception needed
		return;
	}
	 
	 //get the player_id
	

	//set the new player in  player array



}

void user :: sell_player(int index){
    //return budget
	
	if (players[index].player_id != 0) {

		budget += players[index].price;
		// sell player at index 
		players[index].player_id = 0;
	}
	else {
		//exception needed
	}
}

void user :: replace_player(int new_player_id, int player_old_index){
	// 
}

void user :: load_players(map<int,player> players_map){

	for (int i = 0; i < 5; i++) {

		if(players_ids[i] != 0)
		players[i] = players_map[players_ids[i]];

		else {

			players[i].pl_name = "NONE";
		}
	}
}

