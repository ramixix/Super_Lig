#include "team.h"

void Teams::read_teams() {
	for(int team_index = 0 ; team_index < Team_number; team_index++){

		std::string data;
		std::fstream teams_file;
		teams_file.open("teams.txt");

		if (teams_file.is_open()) {
				for (int i = 0; i <= team_index; i++){
					std::getline(teams_file, data);
				}

				std::string delimiter = "-";
			
				teams[team_index].name = data.substr(0, data.find(delimiter));
				teams[team_index].directive = data.substr(teams[team_index].name.length() + 1, data.find(delimiter, data.find(delimiter) + 1) - teams[team_index].name.length() - 1);
				teams[team_index].ab_name = data.substr(teams[team_index].name.length() + teams[team_index].directive.length() + 2, data.length());
		
		}
		else
			std::cout << "[Error] Could Not Open The File!!! (please check if file is exist)" << std::endl;

	}
}

void Teams::print_teams() {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		std::cout << teams[team_index].name << " # " << teams[team_index].directive << " # " << teams[team_index].ab_name << std::endl;
	}

}

void Teams::find_team(std::string team_name) {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		if (teams[team_index].name == team_name) {
			std::cout << teams[team_index].directive << " # " << teams[team_index].ab_name << std::endl;
		}
	}
}


void Teams::add_team(std::string team_name, std::string team_directive, std::string ab_name) {
	
	std::ofstream team_file("teams.txt", std::ios::app); 
	if(team_file.is_open())
		team_file << std::endl  << team_name << "-" << team_directive << "-" << ab_name ;
	else
		std::cout << "[Error] Could Not Open The File!!! (please check if file is exist)" << std::endl;
	team_file.close();
}

void Teams::assign_playrs_to_team() {
	int defance=4, middle=4, forward=3;
	std::cout << "Enter the format of Teams(Defance middle Forward) :";
	std::cin >> defance >> middle >> forward;
	if (defance + middle + forward != 11) {
		std::cout << "[Error] Wrong format, Try again." << std::endl;
		assign_playrs_to_team();
	}
	else {
		char positions[3] = { 'D', 'O', 'F' };
		srand(time(0));
		for (int team_index = 0; team_index < Team_number; team_index++) {
			int d = defance;
			int m = middle;
			int f = forward;

			for (int player_index = 0; player_index < Players_in_each_team; player_index++) {

				std::fstream first_names_file;
				std::fstream last_names_file;
				std::string first_name;
				std::string last_name;
				first_names_file.open("first_names.txt");
				last_names_file.open("last_names.txt");

				if (first_names_file.is_open() && last_names_file.is_open()) {

					int random_age = (rand() % (36 - 18 + 1)) + 18;
					int random_uniform_num = (rand() % (99 - 1 + 1)) + 1;
					int random_performance = (rand() % (100 - 30 + 1)) + 30;
					int random_first_name_row = rand() % 1000;
					int random_last_name_row = rand() % 1000;

					int position = 0;
					if (d > 0) {
						position = 0;
						d--;
					}
					else if (m > 0) {
						position = 1;
						m--;
					}
					else {
						position = 2;
					}

					for (int i = 0; i <= random_first_name_row; i++) {
						std::getline(first_names_file, first_name);
					}
					for (int i = 0; i <= random_last_name_row; i++) {
						std::getline(last_names_file, last_name);
					}

					teams[team_index].players[player_index].first_name = first_name;
					teams[team_index].players[player_index].last_name = last_name;
					teams[team_index].players[player_index].age = random_age;
					teams[team_index].players[player_index].uniform_num = random_uniform_num;
					teams[team_index].players[player_index].performance = random_performance;
					teams[team_index].players[player_index].position = positions[position];
				}
				else
					std::cout << "[Error] Could Not Open The File!!! (please check if file is exist)" << std::endl;
			}
			test_team(team_index);

		}
	}
}

//
//void Players::assign_players_data() {
//
//	char positions[3] = { 'D', 'O', 'F'};
//	srand(time(0));
//
//	for(int player_index = 0 ; player_index < this->players_num; player_index++){
//		
//		std::fstream first_names_file;
//		std::fstream last_names_file;
//		std::string first_name;
//		std::string last_name;
//		first_names_file.open("first_names.txt");
//		last_names_file.open("last_names.txt");
//
//		if (first_names_file.is_open() && last_names_file.is_open()) {
//			
//			int random_age = (rand() % (36 - 18 + 1)) + 18;
//			int random_uniform_num = (rand() % (99 - 1 + 1) ) + 1;
//			int random_position = rand() % 3;
//			int random_performance = (rand() % (100 - 30 + 1) ) + 30;
//			int random_first_name_row = rand() % 1000;
//			int random_last_name_row = rand() % 1000;
//
//			for (int i = 0; i <= random_first_name_row; i++) {
//				std::getline(first_names_file, first_name);
//			}
//			for (int i = 0; i <= random_last_name_row; i++) {
//				std::getline(last_names_file, last_name);
//			}
//
//			players[player_index].first_name = first_name;
//			players[player_index].last_name = last_name;
//			players[player_index].age = random_age ;
//			players[player_index].uniform_num = random_uniform_num ;
//			players[player_index].performance = random_performance ;
//			players[player_index].position = positions[random_position] ;
//		}
//	}
//}
//


void Teams::print_players() {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
			std::cout << this->teams[team_index].name << "# " << teams[team_index].players[player_index].first_name << " " << teams[team_index].players[player_index].last_name << " " << teams[team_index].players[player_index].age << " " << teams[team_index].players[player_index].performance << " " << teams[team_index].players[player_index].position << " " << teams[team_index].players[player_index].uniform_num << std::endl;
		}
	}
}

//void Players::change_performace(std::string first_name, std::string last_name, int performance){
//	for (int player_index = 0; player_index < this->players_num; player_index++) {
//		if (players[player_index].first_name == first_name && players[player_index].last_name == last_name) {
//			players[player_index].performance = performance;
//		}
//	}
//}

void Teams::test_team(int team_index) {
	int team_mean_performance = calculate_mean_team_performance(team_index);
	int team_mean_age = calculate_mean_team_age(team_index);
	if (team_mean_performance < 60) {
		reset_performance_of_team(team_index);
	}
	if (team_mean_performance < 25 && team_mean_performance> 32) {
		reset_age_of_team(team_index);
	}
}


void Teams::reset_performance_of_team(int team_index) {
	srand(time(0));
	int max_performance = 65;
	int min_performance = 60;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		teams[team_index].players[player_index].performance = (rand() % (max_performance - min_performance + 1)) + min_performance;;
	}
}

void Teams::reset_age_of_team(int team_index) {
	srand(time(0));
	int max_age = 25;
	int min_age = 32;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		teams[team_index].players[player_index].age = (rand() % (max_age- min_age+ 1)) + min_age;;
	}
}

void Teams::print_a_team_info(std::string ad_name) {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		if (teams[team_index].ab_name == ad_name){
			int mean_age = calculate_mean_team_age(team_index);
			int mean_performance = calculate_mean_team_performance(team_index);
			std::cout << std::left << std::setw(30) << "Team Name" << std::setw(30) << "Team Directive" << std::setw(30) << "Team abriviate name" << std::setw(20) << "Team's average age" << std::setw(30) << "Team's average performance"<<std::endl;
			std::cout << std::left << std::setw(30) << this->teams[team_index].name << std::setw(30) << this->teams[team_index].directive << std::setw(30) << this->teams[team_index].ab_name << std::setw(30) << mean_age << std::setw(30) << mean_performance << std::endl;
			std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << std::left << std::setw(30) << "Player Name" << std::setw(30) << "Player Last Name" << std::setw(4) << "age" << std::setw(30) << "Player Performance" << std::setw(20) << "Player Position" << std::setw(30) << "Player Uniform number" << std::endl;
			std::cout << "#############################################################################################################################################################################################################\n";
			for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
				std::cout << std::left << std::setw(30) << teams[team_index].players[player_index].first_name << std::setw(30) << teams[team_index].players[player_index].last_name << std::setw(4) << teams[team_index].players[player_index].age << std::setw(30) << teams[team_index].players[player_index].performance << std::setw(20) << teams[team_index].players[player_index].position << std::setw(30) << teams[team_index].players[player_index].uniform_num << std::endl;
			}
		}
	}
}


int Teams::calculate_mean_team_age(int team_index) {
	int total_age = 0;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		total_age += teams[team_index].players[player_index].age;
	}
	double team_mean_age = total_age / Players_in_each_team;
	return round(team_mean_age);
}

int Teams::calculate_mean_team_performance(int team_index) {
	int total_performance = 0;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		total_performance += teams[team_index].players[player_index].performance;
	}
	double team_mean_performance = total_performance / Players_in_each_team;
	return round(team_mean_performance);
}