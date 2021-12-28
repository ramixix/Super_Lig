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
			
				team[team_index].name = data.substr(0, data.find(delimiter));
				team[team_index].directive = data.substr(team[team_index].name.length() + 1, data.find(delimiter, data.find(delimiter) + 1) - team[team_index].name.length() - 1);
				team[team_index].ab_name = data.substr(team[team_index].name.length() + team[team_index].directive.length() + 2, data.length());
		
		}
		else
			std::cout << "[Error] Could Not Open The File!!! (please check if file is exist)" << std::endl;

	}
}

void Teams::print_teams() {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		std::cout << team[team_index].name << " # " << team[team_index].directive << " # " << team[team_index].ab_name << std::endl;
	}

}

void Teams::find_team(std::string team_name) {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		if (team[team_index].name == team_name) {
			std::cout << team[team_index].directive << " # " << team[team_index].ab_name << std::endl;
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

					team[team_index].players[player_index].first_name = first_name;
					team[team_index].players[player_index].last_name = last_name;
					team[team_index].players[player_index].age = random_age;
					team[team_index].players[player_index].uniform_num = random_uniform_num;
					team[team_index].players[player_index].performance = random_performance;
					team[team_index].players[player_index].position = positions[position];
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
			std::cout << this->team[team_index].name << "# " << team[team_index].players[player_index].first_name << " " << team[team_index].players[player_index].last_name << " " << team[team_index].players[player_index].age << " " << team[team_index].players[player_index].performance << " " << team[team_index].players[player_index].position << " " << team[team_index].players[player_index].uniform_num << std::endl;
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
		team[team_index].players[player_index].performance = (rand() % (max_performance - min_performance + 1)) + min_performance;;
	}
}

void Teams::reset_age_of_team(int team_index) {
	srand(time(0));
	int max_age = 25;
	int min_age = 32;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		team[team_index].players[player_index].age = (rand() % (max_age- min_age+ 1)) + min_age;;
	}
}

void Teams::print_a_team_info(std::string ad_name) {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		if (team[team_index].ab_name == ad_name){
			int mean_age = calculate_mean_team_age(team_index);
			int mean_performance = calculate_mean_team_performance(team_index);
			std::cout << std::left << std::setw(30) << "Team Name" << std::setw(30) << "Team Directive" << std::setw(30) << "Team abriviate name" << std::setw(20) << "Team's average age" << std::setw(30) << "Team's average performance"<<std::endl;
			std::cout << std::left << std::setw(30) << this->team[team_index].name << std::setw(30) << this->team[team_index].directive << std::setw(30) << this->team[team_index].ab_name << std::setw(30) << mean_age << std::setw(30) << mean_performance << std::endl;
			std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << std::left << std::setw(30) << "Player Name" << std::setw(30) << "Player Last Name" << std::setw(4) << "age" << std::setw(30) << "Player Performance" << std::setw(20) << "Player Position" << std::setw(30) << "Player Uniform number" << std::endl;
			std::cout << "#############################################################################################################################################################################################################\n";
			for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
				std::cout << std::left << std::setw(30) << team[team_index].players[player_index].first_name << std::setw(30) << team[team_index].players[player_index].last_name << std::setw(4) << team[team_index].players[player_index].age << std::setw(30) << team[team_index].players[player_index].performance << std::setw(20) << team[team_index].players[player_index].position << std::setw(30) << team[team_index].players[player_index].uniform_num << std::endl;
			}
		}
	}
}


int Teams::calculate_mean_team_age(int team_index) {
	int total_age = 0;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		total_age += team[team_index].players[player_index].age;
	}
	double team_mean_age = total_age / Players_in_each_team;
	return round(team_mean_age);
}

int Teams::calculate_mean_team_performance(int team_index) {
	int total_performance = 0;
	for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
		total_performance += team[team_index].players[player_index].performance;
	}
	double team_mean_performance = total_performance / Players_in_each_team;
	return round(team_mean_performance);
}


//void Lig_operations::create_matches() {
//	int number_of_matches = 0;
//	for (int i = 1; i < Team_number; i++) {
//		number_of_matches += i;
//	}
//
//	this->match_array = new Match[number_of_matches];
//	
//	int i = 0;
//	for (int team_index = 0; team_index < Team_number; team_index++) {
//		for (int match_index = 0; match_index < (Team_number - team_index - 1); match_index ++) {
//			this->match_array[i].assign_match(all_teams.team[team_index], all_teams.team[match_index + team_index + 1], i);
//			i += 1;
//		}
//	}
//	this->total_matches = number_of_matches;
//}
//
//
////void Lig_operations::print_all_matches_info() {
////	for (int match_index = 0; match_index < total_matches; match_index++) {
////		match_array[match_index].print_match_info();
////	}
////}
//
//void Lig_operations::create_lig() {
//	this->create_matches();
//}
//
//void Lig_operations::print_all_matches_specific_to_aTeam(std::string team_name){
//	for (int match_index = 0; match_index < total_matches; match_index++) {
//		if (match_array[match_index].get_team1_name() == team_name) {
//			match_array[match_index].print_match_info();
//		}
//	}
//}

void Teams::create_lig() {
	int number_of_matches = 0;
	int index_team = 0;
	for (int num_matches_for_every_team = Team_number-1; num_matches_for_every_team >= 0 ; num_matches_for_every_team--) {
		number_of_matches += num_matches_for_every_team;
		this->team[index_team].matches = new Match[num_matches_for_every_team];
		index_team += 1;
	}

	int match_id = 0;
	for (int team_index = 0; team_index < Team_number; team_index++) {
		for (int match_index = 0; match_index < (Team_number - team_index - 1); match_index++) {
			this->team[team_index].matches[match_index].assign_match(team_index, (match_index + team_index + 1), match_id);
			match_id += 1;
		}
	}
}


void Teams:: print_all_matches() {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		for (int match_index = 0; match_index < (Team_number - team_index - 1); match_index++) {
			std::string team1_name = this->team[team_index].name;
			std::string team2_name = this->team[match_index + team_index + 1].name;
			int match_id = this->team[team_index].matches[match_index].get_match_id();
			this->team[team_index].matches[match_index].print_match_info(team1_name, team2_name, match_id);
		}
	}
}


void Teams::print_all_matches_specific_to_aTeam(std::string team_name){
	for (int team_index = 0; team_index < Team_number; team_index++) {
		for (int match_index = 0; match_index < (Team_number - team_index - 1); match_index++) {
			int team1_index = this->team[team_index].matches[match_index].get_team1_index();
			int team2_index = this->team[team_index].matches[match_index].get_team2_index();
			if (this->team[team1_index].name == team_name ) {
				std::string team1_name = this->team[team_index].name;
				std::string team2_name = this->team[match_index + team_index + 1].name;
				int match_id = this->team[team_index].matches[match_index].get_match_id();
				this->team[team_index].matches[match_index].print_match_info(team1_name, team2_name, match_id);
			}
			else if (this->team[team2_index].name == team_name) {
				std::string team1_name = this->team[team_index].name;
				std::string team2_name = this->team[match_index + team_index + 1].name;
				int match_id = this->team[team_index].matches[match_index].get_match_id();
				this->team[team_index].matches[match_index].print_match_info(team1_name, team2_name, match_id);
			}
		}
	}
}


void Teams::print_match_by_id(int match_id) {
	for (int team_index = 0; team_index < Team_number; team_index++) {
		for (int match_index = 0; match_index < (Team_number - team_index - 1); match_index++) {
			if (this->team[team_index].matches[match_index].get_match_id() == match_id) {
				
				int team1_index = this->team[team_index].matches[match_index].get_team1_index();
				int team2_index = this->team[team_index].matches[match_index].get_team2_index();
				std::string team1_name = this->team[team1_index].name;
				std::string team2_name = this->team[team2_index].name;
				this->team[team_index].matches[match_index].print_match_info(team1_name, team2_name, match_id);

				for (int player_index = 0; player_index < Players_in_each_team; player_index++) {
					std::cout << std::to_string(player_index) << ".\t" << team[team1_index].players[player_index].first_name << '-' << team[team1_index].players[player_index].last_name << "-" << team[team1_index].players[player_index].position << "-"  << std::setw(4) << team[team1_index].players[player_index].performance << "\t | ";
					std::cout <<  team[team2_index].players[player_index].first_name << '-' << team[team2_index].players[player_index].last_name << "-" << team[team2_index].players[player_index].position << "-" << team[team2_index].players[player_index].performance << std::endl;
				}
				
			}
		}
	}
}




void Match::print_match_info(std::string team1_name , std::string team2_name, int match_id) {
	std::cout << "teams :" << team1_name << '\t' << team2_name << "\tmatch id : " << match_id << std::endl;
}
