
#pragma once

#include<string>
#include "player.h"
#include <map>

class Team
{
	
public:
	 string team_name ;
	 int team_id;
     player players[11] = {};


public:
    Team();
    Team(string name, int id, player[]);
    int get_index(string pl_name);
    int get_id(map<int, player> players_map, string pl_name);
    void set_specific_player(int index, string name, int price, int GW, int goals);
    void delete_specific_player(int index);
 
    void set_id(int new_id) {
        team_id = new_id;
    }

    void set_players(player* new_players) {
        for (int i = 0; i < 11; i++) {
            players[i] = new_players[i];
        }
    }

    



};
