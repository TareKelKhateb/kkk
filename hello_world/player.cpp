#include "player.h"

using namespace std;



player::player() {
    pl_name = "NONE";
    player_id = -1;
    price = 100000;

}

player::player(string p_name) {
    if(p_name == "")
        p_name="None";


	pl_name = p_name;
    player_id = 0;
    price = 100000;
}



void player :: update_price(double new_price) {
	price = new_price;
}

void player::update_price_auto(int GW) {
	
	price = price + double(arr_points[GW - 1] * 0.05);

}



void player :: update_points(int GW){

	arr_points[GW - 1] =arr_goals[GW - 1]*3;
}


void player::update_goals(int GW, int goals){
  
	arr_goals[GW-1]=goals;
 //	update_points(GW);
 //	update_price_auto(GW);

}


void player::update_name(string name) {

	pl_name = name;

	
}
void player::update_all(double new_price, int Gw, int goals, string name) {
	
	update_name(name);
	update_price(new_price);
	update_goals(Gw, goals);
	update_points(Gw);

}
