#include<iostream>
#include<map>
#include<set>
using namespace std;

void book_seat(int s);

struct Customer {
	int id;
	string name;
	string username;
	string password;
	int age;
	char gender;
};

struct Bus {
	string Booker_name;
	string Passenger_name;
	char gender = 'o';
	int amount = 0;
};

map<string, Customer> Customer_DB;
int Cust_ID = 1;
Customer log_Cust;

map<char, Bus> ACSleep[7];
map<char, Bus> NonACSleep[7];
map<char, Bus> ACSeeter[5];
map<char, Bus> NonACSeeter[5];

int ACSleep_count = 12;
int NonACSleep_count = 12;
int ACSeeter_count = 12;
int NonACSeeter_count = 12;

void Ini_Customer_DB() {
	pair<string, Customer> pair_data;
	Customer obj1;
	obj1.id = Cust_ID++;
	obj1.name = "aaa";
	obj1.username = "aaa_";
	obj1.password = "111";
	obj1.age = 25;
	obj1.gender = 'F';

	pair_data = make_pair(obj1.username, obj1);
	Customer_DB.insert(pair_data);

	Customer obj2;
	obj2.id = Cust_ID++;
	obj2.name = "bbb";
	obj2.username = "bbb_";
	obj2.password = "222";
	obj2.age = 61;
	obj2.gender = 'M';

	pair_data = make_pair(obj2.username, obj2);
	Customer_DB.insert(pair_data);

	Customer obj3;
	obj3.id = Cust_ID++;
	obj3.name = "ccc";
	obj3.username = "ccc_";
	obj3.password = "333";
	obj3.age = 22;
	obj3.gender = 'M';

	pair_data = make_pair(obj3.username, obj3);
	Customer_DB.insert(pair_data);

	Customer obj4;
	obj4.id = Cust_ID++;
	obj4.name = "ddd";
	obj4.username = "ddd_";
	obj4.password = "444";
	obj4.age = 36;
	obj4.gender = 'F';

	pair_data = make_pair(obj4.username, obj4);
	Customer_DB.insert(pair_data);

}

void Ini_Bus_DB() {
	Bus obj;
	pair<char, Bus> pair_data;

	for (int i = 1; i <= 6; i++) {
		pair_data = make_pair('A', obj);
		ACSleep[i].insert(pair_data);
		pair_data = make_pair('B', obj);
		ACSleep[i].insert(pair_data);
	}
	for (int i = 1; i <= 6; i++) {
		pair_data = make_pair('A', obj);
		NonACSleep[i].insert(pair_data);
		pair_data = make_pair('B', obj);
		NonACSleep[i].insert(pair_data);
	}
	for (int i = 1; i <= 4; i++) {
		pair_data = make_pair('A', obj);
		ACSeeter[i].insert(pair_data);
		pair_data = make_pair('B', obj);
		ACSeeter[i].insert(pair_data);
		pair_data = make_pair('C', obj);
		ACSeeter[i].insert(pair_data);
	}
	for (int i = 1; i <= 4; i++) {
		pair_data = make_pair('A', obj);
		NonACSeeter[i].insert(pair_data);
		pair_data = make_pair('B', obj);
		NonACSeeter[i].insert(pair_data);
		pair_data = make_pair('C', obj);
		NonACSeeter[i].insert(pair_data);
	}

}

bool confirm_cseat(int s) {
	switch (s) {
	case 1: {
		cout << "cancellation charge will be : 350" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 2: {
		cout << "cancellation charge will be : 150" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 3: {
		cout << "cancellation charge will be : 275" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 4: {
		cout << "cancellation charge will be : 112" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	}
}

void cancel_seat(int s) {
	switch (s) {
		case 1: {
		cout << "Enter seat row" << endl;
		int r;
		cin >> r;
		cout << "enter seat column" << endl;
		char c;
		cin >> c;
		auto pr = ACSleep[r].find(c);
		if (pr->second.Booker_name == log_Cust.name) {
			if (confirm_cseat(1)) {
				pr->second.Passenger_name = "";
				pr->second.Booker_name = "";
				pr->second.gender = 'o';
				cout << "cancelled" << endl;
				pr->second.amount = (pr->second.amount) - 350;
				ACSleep_count++;
			}
			else {
				cout << "cancellation cancelled" << endl;
			}

		}
		else {
			cout << "This seat is not booked by you" << endl;
		}
		break;
		}
		case 2: {
		cout << "Enter seat row" << endl;
		int r;
		cin >> r;
		cout << "enter seat column" << endl;
		char c;
		cin >> c;
		auto pr = NonACSleep[r].find(c);
		if (pr->second.Booker_name == log_Cust.name) {
			if (confirm_cseat(2)) {
				pr->second.Passenger_name = "";
				pr->second.Booker_name = "";
				pr->second.gender = 'o';
				cout << "cancelled" << endl;
				pr->second.amount = (pr->second.amount) - 450;
				NonACSleep_count++;
			}
			else {
				cout << "cancellation cancelled" << endl;
			}

		}
		else{
			cout << "This seat is not booked by you" << endl;
		}
		break;
		}
		case 3: {
			cout << "Enter seat row" << endl;
			int r;
			cin >> r;
			cout << "enter seat column" << endl;
			char c;
			cin >> c;
			auto pr = ACSeeter[r].find(c);
			if (pr->second.Booker_name == log_Cust.name) {
				if (confirm_cseat(3)) {
					pr->second.Passenger_name = "";
					pr->second.Booker_name = "";
					pr->second.gender = 'o';
					cout << "cancelled" << endl;
					pr->second.amount = (pr->second.amount) - 275;
					ACSeeter_count++;
				}
				else {
					cout << "cancellation cancelled" << endl;
				}

			}
			else {
				cout << "This seat is not booked by you" << endl;
			}
			break;
		}
		case 4: {
			cout << "Enter seat row" << endl;
			int r;
			cin >> r;
			cout << "enter seat column" << endl;
			char c;
			cin >> c;
			auto pr = NonACSeeter[r].find(c);
			if (pr->second.Booker_name == log_Cust.name) {
				if (confirm_cseat(4)) {
					pr->second.Passenger_name = "";
					pr->second.Booker_name = "";
					pr->second.gender = 'o';
					cout << "cancelled" << endl;
					pr->second.amount = (pr->second.amount) - 338;
					NonACSeeter_count++;
				}
				else {
					cout << "cancellation cancelled" << endl;
				}

			}
			else {
				cout << "This seat is not booked by you" << endl;
			}
			break;
		}
	}
}

bool confirm_seat(int s) {
	switch (s) {
	case 1: {
		cout << "seat available for : 700" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 2: {
		cout << "seat available for : 600" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 3: {
		cout << "seat available for : 550" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 4: {
		cout << "seat available for : 450" << endl;
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	}
	

}

void check_availablity(string pname , char g , int r , char c , int s) {
	//cout << pname << " " << g << " " << 3 << " " << b;
	Bus obj;
	obj.Booker_name = log_Cust.name;
	obj.Passenger_name = pname;
	obj.gender = g;

	switch (s) {
	case 1: {

		if (r == 3 || r == 6) {
			auto pr = ACSleep[r].find(c);
			if (pr->second.Passenger_name == "") {
				if (confirm_seat(1)) {
					pr->second = obj;
					cout << "booked" << endl;
					pr->second.amount = (pr->second.amount) + 700;
					ACSleep_count--;
				}
				else {
					cout << "canceled";
				}

			}
			else {
				cout << "Seat already booked select from available seats :" << endl;
				book_seat(1);
			}
		}
		if (r == 1 || r == 2 || r == 4 || r == 5) {
			auto pr = ACSleep[r].find(c);
			
			if (pr->second.Passenger_name == "") {
				pr->second = obj;
				if (r == 1) {
					auto pseat = ACSleep[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {

						if (confirm_seat(1)) {
							
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 700;
							ACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(1);
					}
				}
				else if (r == 2) {
					auto pseat = ACSleep[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(1)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 700;
							ACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(1);
					}
				}
				else if (r == 4) {
					auto pseat = ACSleep[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(1)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 700;
							ACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(1);
					}
				}
				else if (r == 5) {
					auto pseat = ACSleep[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(1)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 700;
							ACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(1);
					}
				}

			}
			else {
				cout << "Seat already booked select from available seats :" << endl;
				book_seat(1);
			}
		}

		break;
	}
	case 2:
	{
		if (r == 3 || r == 6) {
			auto pr = NonACSleep[r].find(c);
			if (pr->second.Passenger_name == "") {
				if (confirm_seat(2)) {
					pr->second = obj;
					cout << "booked" << endl;
					pr->second.amount = (pr->second.amount) + 600;
					NonACSleep_count--;
				}
				else {
					cout << "canceled";
				}

			}
			else {
				cout << "Seat already booked select from available seats :" << endl;
				book_seat(2);
			}
		}
		if (r == 1 || r == 2 || r == 4 || r == 5) {
			auto pr = NonACSleep[r].find(c);
			if (pr->second.Passenger_name == "") {
				pr->second = obj;
				if (r == 1) {
					auto pseat = NonACSleep[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(2)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 600;
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(2);
					}
				}
				else if (r == 2) {
					auto pseat = NonACSleep[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(2)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 600;
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(2);
					}
				}
				else if (r == 4) {
					auto pseat = NonACSleep[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(2)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 600;
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(2);
					}
				}
				else if (r == 5) {
					auto pseat = NonACSleep[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(2)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 600;
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(2);
					}
				}

			}
			else {
				cout << "Seat already booked select from available seats :" << endl;
				book_seat(2);
			}
		}

		break;
	}
	case 3: {
		if (r == 1 || r == 2 || r==3 || r==4){
			auto pr = ACSeeter[r].find(c);
			if (pr->second.Passenger_name == "") {
				pr->second = obj;

				if (r == 1) {
					auto pseat = ACSeeter[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {

						if (confirm_seat(3)) {

							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(3);
					}
				}
				else if (r == 2) {
					auto pseat = ACSeeter[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(3)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(3);
					}
				}
				else if (r == 3) {
					auto pseat = ACSeeter[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(3)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(3);
					}
				}
				else if (r == 4) {
					auto pseat = ACSeeter[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(3)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(3);
					}
				}


			}
		}
	}
	case 4: {
		if (r == 1 || r == 2 || r == 3 || r == 4) {
			auto pr = NonACSeeter[r].find(c);
			if (pr->second.Passenger_name == "") {
				pr->second = obj;

				if (r == 1) {
					auto pseat = NonACSeeter[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {

						if (confirm_seat(4)) {

							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(4);
					}
				}
				else if (r == 2) {
					auto pseat = NonACSeeter[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(4)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(4);
					}
				}
				else if (r == 3) {
					auto pseat = NonACSeeter[r + 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(4)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(4);
					}
				}
				else if (r == 4) {
					auto pseat = NonACSeeter[r - 1].find(c);
					if (pseat->second.gender == pr->second.gender || pseat->second.Booker_name == pr->second.Booker_name || pseat->second.gender == 'o') {
						if (confirm_seat(4)) {
							pr->second = obj;
							cout << "booked" << endl;
							pr->second.amount = (pr->second.amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							pr->second.Passenger_name = "";
							pr->second.Booker_name = "";
							pr->second.gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						pr->second.Passenger_name = "";
						pr->second.Booker_name = "";
						pr->second.gender = 'o';
						book_seat(4);
					}
				}


			}
		}
	}
	}

}

void book_seat(int s) {
	switch (s) {
	case 1: {

		cout << "List of seats available in AC Sleeper:" << endl;
		for (int i = 1; i <= 6; i++) {  // looping in number
			for (auto pr : ACSleep[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name == "") {
					cout << i << pr.first << " ";
				}
			}	cout << endl;
		}

		cout << "Enter passenger name :";
		string pname;
		cin >> pname;
		cout << "Enter passenger gender :";
		char g;
		cin >> g;


		cout << "Enter col : ";
		char c; cin >> c;
		cout << "Enter row : ";
		int r; cin >> r;

		check_availablity(pname, g, r, c ,s);

		break;
	}
	case 2: {
		cout << "List of seats available in Non-AC Sleeper:" << endl;
		for (int i = 1; i <= 6; i++) {  // looping in number
			for (auto pr : NonACSleep[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name == "") {
					cout << i << pr.first << " ";
				}
			}	cout << endl;
		}

		cout << "Enter passenger name :";
		string pname;
		cin >> pname;
		cout << "Enter passenger gender :";
		char g;
		cin >> g;


		cout << "Enter col : ";
		char c; cin >> c;
		cout << "Enter row : ";
		int r; cin >> r;

		check_availablity(pname, g, r, c, s);

		break;
	}
	case 3: {
		cout << "List of seats available in AC Seeter:" << endl;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : ACSeeter[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name == "") {
					cout << i << pr.first << " ";
				}
			}	cout << endl;
		}

		cout << "Enter passenger name :";
		string pname;
		cin >> pname;
		cout << "Enter passenger gender :";
		char g;
		cin >> g;


		cout << "Enter col : ";
		char c; cin >> c;
		cout << "Enter row : ";
		int r; cin >> r;

		check_availablity(pname, g, r, c, s);

		break;
	}
	case 4: {
		cout << "List of seats available in Non-AC Seeter:" << endl;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : NonACSeeter[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name == "") {
					cout << i << pr.first << " ";
				}
			}	cout << endl;
		}

		cout << "Enter passenger name :";
		string pname;
		cin >> pname;
		cout << "Enter passenger gender :";
		char g;
		cin >> g;


		cout << "Enter col : ";
		char c; cin >> c;
		cout << "Enter row : ";
		int r; cin >> r;

		check_availablity(pname, g, r, c, s);

		break;
	}
	}
	

}

int dashboard() {
	
	while (1) {

		cout << "AC Sleeper : " << ACSleep_count << " press 1" << endl;
		cout << "Non-AC Sleeper : " << NonACSleep_count << " press 2" << endl;
		cout << "AC Seeter : " << ACSeeter_count << " press 3" << endl;
		cout << "Non AC Seeter : " << ACSeeter_count << " press 4" << endl;
		cout << "To cancel Ticket : press 5" << endl;
		cout << "To Exit : 10"<<endl;

		int s;
		cin >> s;
		switch (s) {
		case 1: {
			cout << "enter no. of seats to be booked in AC-Sleeper: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				book_seat(1);
			}
			break;
		}
		case 2: {
			cout << "enter no. of seats to be booked in Non AC-Sleeper: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				book_seat(2);
			}
			break;
		}
		case 3: {
			cout << "enter no. of seats to be booked in AC-Seeter: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				book_seat(3);
			}
			break;
		}
		case 4: {
			cout << "enter no. of seats to be booked in NonAC-Seeter: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				book_seat(4);
			}
			break;
		}
		case 5: {
			cout << "which ticket u need to calcel :" << endl;
			cout << "AC Sleeper : press 1" << endl;
			cout << "Non-AC Sleeper : press 2" << endl;
			cout << "AC Seeter : press 3" << endl;
			cout << "Non-AC Seeter : press 4" << endl;
			int k;
			cin >> k;
			switch (k) {
				case 1: {
					cancel_seat(1);
					break;
				}
				case 2: {
					cancel_seat(2);
					break;
				}
				case 3: {
					cancel_seat(3);
					break;
				}
				case 4: {
					cancel_seat(4);
					break;
				}
			}
			
			break;
		}
		case 10: {
			return 1;
		}

		}

	}
	
	
}


void Customer_signup() {
	Customer obj;
	obj.id = Cust_ID++;
	cout << "Enter ur Name : ";
	cin >> obj.name;
label:
	cout << "Enter ur UName : ";
	cin >> obj.username;
	if (Customer_DB.find(obj.username) != Customer_DB.end()) {
		cout << "User name already exist -:";
		goto label;
	}
	cout << "Enter ur Pass : ";
	cin >> obj.password;
	cout << "Enter ur Age : ";
	cin >> obj.age;
	cout << "Enter ur Gender : ";
	cin >> obj.gender;

	pair<string, Customer> pair_data;
	pair_data = make_pair(obj.username, obj);
	Customer_DB.insert(pair_data);

}

int Customer_login() {
	string UName;
	string pass;
	cout << "Enter User Name : ";
	cin >> UName;
	cout << "Enter PassWord : ";
	cin >> pass;
	if (Customer_DB.find(UName) == Customer_DB.end()) {
		cout << "User name not exist -:"<<endl;
	}
	else {
		auto itr = Customer_DB.find(UName);
		if (itr->second.password == pass) {
			log_Cust = itr->second;
			cout << "Login Success : " << endl;
			int a = dashboard();
			if (a) { return 1; }
		}
		else {
			cout << "Password Wrong"<<endl;
		}
	}

}

void admin() {
	cout << "This is admin Dashboard :"<<endl;
	cout<<"select the bus details to be displayed"<<endl;
	cout << "AC Sleeper : 1" << endl;
	cout << "Non AC Sleeper : 2" << endl;
	cout << "AC Seeter : 3" << endl;
	cout << "Non AC Seeter : 4" << endl;

	int n;
	cin >> n;
	switch (n) {
	case 1: {
		cout << "Number of seats filled : "<< (12 - ACSleep_count)<<endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : ACSleep[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name != "") {
					cout << i << pr.first << " "<<pr.second.Passenger_name<<" "<<pr.second.gender;
					
				}cout << endl;
				amount = amount + pr.second.amount;
			}
		}
		cout << "amount collected : "<<amount << endl;
		break;
	}
	case 2: {
		cout << "Number of seats filled : " << (12 - NonACSleep_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : NonACSleep[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name != "") {
					cout << i << pr.first << " " << pr.second.Passenger_name << " " << pr.second.gender;
					
				}cout << endl;
				amount = amount + pr.second.amount;
			}
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	case 3: {
		cout << "Number of seats filled : " << (12 - ACSeeter_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : ACSeeter[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name != "") {
					cout << i << pr.first << " " << pr.second.Passenger_name << " " << pr.second.gender;

				}cout << endl;
				amount = amount + pr.second.amount;
			}
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	case 4: {
		cout << "Number of seats filled : " << (12 - NonACSeeter_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 1; i <= 4; i++) {  // looping in number
			for (auto pr : NonACSeeter[i])       // looping in char a/b
			{
				if (pr.second.Passenger_name != "") {
					cout << i << pr.first << " " << pr.second.Passenger_name << " " << pr.second.gender;

				}cout << endl;
				amount = amount + pr.second.amount;
			}
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	}
}

void view_bus_details() {
	/*multiset<pair<int, string>> ms;
	pair<int, string> pair_data;

	pair_data = make_pair(ACSeeter_count, "AC Seeter");
	ms.insert(pair_data);
	pair_data = make_pair(ACSleep_count, "AC Sleeper");
	ms.insert(pair_data);
	pair_data = make_pair(NonACSeeter_count, "NonAC Seeter");
	ms.insert(pair_data);
	pair_data = make_pair(NonACSleep_count, "NonAC Sleeper");
	ms.insert(pair_data);

	for (multiset< pair<int, string > >::iterator it = ms.begin(); it != ms.end(); it++) {
		cout<< it->first <<" " << it->second << endl;
	}

	for (auto it : ms) {
		pair_data = it;
		cout << pair_data.first << " " << pair_data.second << endl;
	} */

	if (ACSeeter_count <= ACSleep_count) {
		cout << "AC Sleeper " << ACSleep_count << endl;
		cout << "AC Seeter " << ACSeeter_count << endl;
	}
	if (ACSeeter_count > ACSleep_count) {
		cout << "AC Seeter " << ACSeeter_count << endl;
		cout << "AC Sleeper " << ACSleep_count << endl;
	}
	if (NonACSeeter_count <= NonACSleep_count) {
		cout << "Non AC Sleeper " << NonACSleep_count << endl;
		cout << "Non AC Seeter " << NonACSeeter_count << endl;
	}
	if (NonACSeeter_count > NonACSleep_count) {
		cout << "Non AC Seeter " << NonACSeeter_count << endl;
		cout << "Non AC Sleeper " << NonACSleep_count << endl;
	}

}

int main() {
	
	Ini_Customer_DB();
	Ini_Bus_DB();
	
	while (1) {

		cout << "welcome to ZOBUS" << endl;
		cout << "Login : 1" << endl;
		cout << "SignUp : 2" << endl;
		cout << "view bus details : 3"<<endl;
		cout << "admin : 4" << endl;
		cout << "exit : 10" << endl;

		int n;
		cin >> n;
		switch (n) {
		case 1:
			Customer_login();
			break;
		case 2:
			Customer_signup();
			break;
		case 3:
			view_bus_details();
			break;
		case 4:
			admin();
			break;
		case 10:
			exit(0);
		}


	}
	
	//Customer_signup();
	/*for (auto i : Customer_DB)
		cout << i.first << "   " << i.second.id
		<< endl;*/

	//Customer_login();
	//cout << log_Cust.name;

}
