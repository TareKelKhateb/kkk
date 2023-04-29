#ifndef PLAYER_H
#define PLAYER_H
#pragma once

/*

class player{
arr_goals[36];
arr_points[36];
update_price() //depending on the last price(will be used in admin update)
update_points(GW_index)


}*/
#include<iostream>
using namespace std;

class player
{


public:
    int player_id;
    int arr_goals[36] = {0};
    int arr_points[36] = {0};
	double price;
    string pl_name;
	// string team;
	// string league;

	player();
	player(string p_name);

	void update_price(double new_price);
	void update_price_auto(int GW);
	void update_points(int GW_index);
	void update_goals(int GW, int goals);
	void update_name(string name);
    void update_all(double new_price, int Gw, int goals, string name);



	
};

#endif
