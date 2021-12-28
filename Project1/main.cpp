#include "team.h"

using namespace std;
extern int total_mathcesss;
int main() {

	//Teams Teamss;
	//
	//Teamss.read_teams();
	//Teamss.assign_playrs_to_team();
	//Teamss.print_a_team_info("sdf");
	Lig_operations a;
	a.dosome();
	//a.create_lig();
	//a.print_all_matches_info();
	//a.print_all_matches_specific_to_aTeam("WHITE");
	/*Players playersss;
	playersss.assign_playrs_to_team();
	playersss.print_players();*/
	/*Teamss.print_teams();
	string name;
	string dir;
	string ab;
	cout << "team name : ";
	cin >> name;
	cout << "team dri : ";
	cin >> dir;
	cout << "team ab : ";
	cin >> ab;

	Teamss.add_team(name, dir, ab);*/
	//Teamss.print_teams();
	/*for (int i = 0; i < Team_number; i++) {
		teams[i].read_teams(i);
	}
	for (int i = 0; i < Team_number; i++) {
		teams[i].print_team();
	}*/

	/*char team_name[] = "SMITH-123456-ass";
	char name[50];
	char number[50];
	char fu[3];
	size_t size = sizeof(team_name) / sizeof(team_name[0]);
	int i ;*/
	//for(i=0; i < 3; i++){
	//	for (int j = 0; j < size; j++ ) {
	//		if (team_name[j] != '-') {
	//			if (i == 0) {
	//				name[j] = team_name[j];
	//			}
	//			else if (i == 1) {
	//				number[j] = team_name[j];
	//			}
	//			else {
	//				fu[j] = team_name[j];
	//			}
	//		}
	//		else {
	//			break;
	//		}
	//	
	//	}

	//}
	//strtok(team_name, "-");
	/*i = 0;
	char* ptr;
	ptr = strtok_s(team_name, "-",);
	while (ptr != NULL) {
		if (i == 0)
			strcpy_s(name, 50, ptr);
		else if (i == 1)
			strcpy_s(number, 50, ptr);
		else
			strcpy_s(fu, 50, ptr);
		ptr = strtok(NULL, "-");
		i++;
	}*/
	//std::cout << "fic";

	//string a = "SMITH-123456-ass";
	//string delimiter = "-";
	//string name;
	//string number;
	//string fu;
	//int i = 0;

	//		name = a.substr(0, a.find(delimiter));
	//		cout << a.find(delimiter, a.find(delimiter) + 1);
	//		number = a.substr(name.length() + 1, a.find(delimiter, a.find(delimiter)+1) - name.length()-1);
	//		cout << number.length();
	//		fu = a.substr(name.length() + number.length() + 2, a.length());

	//
	// std::cout <<name << endl<< number << endl << fu << endl;
	return 0;
}