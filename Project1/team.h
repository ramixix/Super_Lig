#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip> 
#define Team_number 18
#define Players_in_each_team 11


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
};



class Teams{
public:
	Teams() {
		teams = new Team_data[Team_number];
		for (int team_index = 0; team_index < Team_number; team_index++) {
			teams[team_index].players = new Player_data[Players_in_each_team];
		}
	}

	~Teams() {
		delete[]teams;
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

protected:
	Team_data* teams;
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