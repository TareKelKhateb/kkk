
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

//find a player by name and return the index of leauge,team,player
void admin::find_player_by_name(bool &found,int &legindx,int &tmindex,int &pindex,string name){
    found =false;

    //loop through all players
    for(legindx =0;legindx<leagues.size();legindx++){


        for(tmindex =0 ;tmindex<leagues[legindx].teams.size();tmindex++){

            for(pindex =0;pindex<11;pindex++){
                if(name == leagues[legindx].teams[tmindex].players[pindex].pl_name){
                    found = true;
                    break;

                }
            }

            if(found)
                break;
        }


        if(found)
            break;
    }

}


player admin::pick_random_player(){


    //int a =rand()&5;

    int legindex = rand()%leagues.size();
    int tmindex = rand()%(leagues[legindex].teams.size());
    int plindex = rand()%11;
    qDebug()<<legindex <<" "<<tmindex<<" "<< plindex;
    return leagues[legindex].teams[tmindex].players[plindex];



}
