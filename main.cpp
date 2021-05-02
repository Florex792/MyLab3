#include<iostream>
#include<fstream>
#include<string>
#include"list.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Error: provide database filename\n";
		return 1;
	}
	Animal rhino("rhino", "mammals", "rhino has big horn");
	List list(rhino);
	std::ifstream in(argv[1]);
	std::string a, b, c, m;
		if (in.is_open())
		{
			while (1)
			{
				if (std::getline(in, a) && std::getline(in, b) && std::getline(in, c)) {
					list.addAnimal(a, b, c);
				}
				else {
					break;
				}
			}
			in.close();
		}
		else {
			return 1;
		}
	
	char number = 0;
	while (number != '6') {
		cout << "\n";
		cout << " Main Menu\n";
		cout << "1) me the zoo \n";
		cout << "2) add animal\n";
		cout << "3) look info about animal \n";

		cout << "4) edit animal info \n";
		cout << "5) delete animal \n";
		cout << "6) exit \n";
		cout << "\n";
		cout << "Enter one symbol from 1 to 6:\n";
		cin >> number;
		switch (number) {
		case '1':
			list.print();
			break;
		case '2':
		{
			string a, b, c;
			cout << "Enter animal: " << endl;
			cout << "Name: ";
			cin >> a;
			cout << "Type: ";
			cin >> b;
			cout << "Info: ";
			cin >> c;
			list.addAnimal(a, b, c);
		}
			break;
		case '3':
		{
			string name;
			cout << "enter name: " << '\n';
			cin >> name;
			cout<<list.findAnimalByName(name)->GetInfo()<<'\n';
		}
			break;
		case '4':
		{
			int index;
			string info;
			cout << "enter index: " << '\n';
			cin >> index;
			cout << "enter info: " << '\n';
			cin >> info;
			list.editInfo(index, info);
		}
			break;
		case '5':
		{
			int index;
			cout << "enter index: " << '\n';
			cin >> index;
			list.del(index);
		}
			break;
		case '6':
		default:
			break;
		}
	}
	list.printFile(argv[1]);
	list.free();
	return 0;
}
