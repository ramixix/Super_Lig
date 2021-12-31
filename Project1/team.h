#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip> 

#define Team_number 18
#define Players_in_each_team 11
#define match_season_time Team_number-1

class Match {
public:
	Match() {
	}
	~Match() {

	}

	void print_match_info(std::string team1_name, std::string team2_name, int match_id);

	void assign_match(int team1_index, int team2_index, int match_id) {
		this->team1_index = team1_index;
		this->team2_index = team2_index;
		this->match_id = match_id;
	}

	int get_team1_index() {
		return this->team1_index;
	}

	int get_team2_index() {
		return this->team2_index;
	}

	int get_match_id() {
		return this->match_id;
	}

protected:
	int team1_index;
	int team2_index;
	int match_id;

};
//struct Match_info {
//	int team1_index;
//	int team2_index;
//	int match_id;
//};

struct Player_data {
	std::string first_name;
	std::string last_name;
	int age;
	int uniform_num;
	int	performance;
	char position;
};

struct Team_data {
	std::string name;
	std::string directive;
	std::string ab_name;
	Player_data *players;
	Match* matches;
};





class Teams{
public:
	Teams() {
		team = new Team_data[Team_number];
		for (int team_index = 0; team_index < Team_number; team_index++) {
			team[team_index].players = new Player_data[Players_in_each_team];
		}
	}

	~Teams() {
		delete[]team;
	}

	void read_teams();
	void print_teams();
	void find_team(std::string team_name);
	void add_team(std::string team_name, std::string team_directive, std::string ab_name);
	void assign_playrs_to_team();
	void print_players();
	void test_team(int team_index);
	void reset_performance_of_team(int team_index);
	void reset_age_of_team(int team_index);
	void print_a_team_info(std::string ad_name);
	int calculate_mean_team_performance(int team_index);
	int calculate_mean_team_age(int team_index);
	void create_lig();
	void print_all_matches();
	void print_all_matches_specific_to_aTeam(std::string team_name);
	void print_match_by_id(int match_id);

	friend class Lig_operations;

protected:
	Team_data* team;
};




class Lig_operations:Teams {
public:
	void dosome() {

		all_teams.read_teams();
		all_teams.assign_playrs_to_team();
		all_teams.print_a_team_info("sdf");
		all_teams.create_lig();
		/*all_teams.print_all_matches();*/
		all_teams.print_match_by_id(67);
		//all_teams.print_all_matches_specific_to_aTeam("MILLER");
	}
	//void create_lig();
	//void create_matches();
	//void print_all_matches_info();
	//void print_all_matches_specific_to_aTeam(std::string team_name);
protected:
	Teams all_teams;
	Match* match_array;
	int total_matches = 0;
};


//
//class Players : Teams {
//public:
//	Players() {
//		players_num = Team_number * Players_in_each_team;
//		players = new Player_data[players_num];
//	}
//	~Players() {
//		delete[] players;
//	}
//	void assign_players_data();
//
//	void change_performace(std::string first_name, std::string last_name, int performance);
//	void create_teams();
//
//private:
//	int players_num;
//	Player_data *players;
//};