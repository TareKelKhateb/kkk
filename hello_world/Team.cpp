#include "Team.h"
#include<iostream>
using namespace std ;

Team::Team()
{
	team_name = "NONE";
	team_id = 0;

	//players[0] = {};
	
}

Team ::Team(string name, int id, player team_player[])
{
   /* if(name == ""){
        name = "NONE";
    }*/

	team_name=name;
	team_id=id;
	for (int i = 0; i < 11; i++)
		players[i] = team_player[i];
}


int Team::get_index(string pl_name) {
	
	int sol = -1;
	for (int i = 0; i < 11; i++) {
		
		if (pl_name == players[i].pl_name) {
			
			sol = i;
			break;
		}
	}
	
	return sol;
}
//NOT USED
void Team::set_specific_player(int index, string name, int price , int GW,int goals) {

	players[index].update_all(price, GW, goals, name);

}




int Team::get_id(map<int, player> players_map, string pl_name) {


	int indx=get_index(pl_name);
	player pl = players[indx];
    return pl.player_id;

}





void Team::delete_specific_player(int index) {
	
    players[index].player_id = -1;
    players[index].pl_name = "NONE";
    players[index].price = 100;



}

