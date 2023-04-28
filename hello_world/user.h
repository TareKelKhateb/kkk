#ifndef USER_H
#define USER_H
#pragma once

#include<map>
#include<string>
#include "player.h"
class user
{
private:
	string username,password;


public:
    string Team_name;
	int budget;
	int points[36];
	player players[5];
	int players_ids[5];
	int total_points;
	user();
    user(string user, string pass , string team_name);
	void display();
	void DISPLAY_players();
	void Display_points();
	void ADD_player(map<int,player>,int id, int index);
	void sell_player(int idex);
	void replace_player(int new_player_id, int player_old_index);
	void load_players(map<int, player> player_map);

    std::string get_username() const {
        return username;
    }

    std::string get_password() const {
        return password;
    }

    void set_username(const std::string& new_username) {
        username = new_username;
    }

    void set_password(const std::string& new_password) {
        password = new_password;
    }

};

#endif
