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
	string Booker_name = "";
	string Passenger_name = "";
	char gender = 'o';
	int amount = 0;
};

map<string, Customer> Customer_DB;      // customer database
int Cust_ID = 1;                        // to increase id after signup
Customer log_Cust;                      // store login data 

//map<char, Bus> ACSleep[6];              // bus database
//map<char, Bus> NonACSleep[6];
//map<char, Bus> ACSeeter[4];
//map<char, Bus> NonACSeeter[4];

Bus ACSleeper[6][2];
Bus NonACSleeper[6][2];
Bus ACSeeter[4][3];
Bus NonACSeeter[4][3];

int ACSleep_count = 12;                //count of seats available
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

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 1; j++) {
			ACSleeper[i][j] = obj;
		}
	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 1; j++) {
			NonACSleeper[i][j] = obj;
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 2; j++) {
			ACSeeter[i][j] = obj;
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 2; j++) {
			NonACSeeter[i][j] = obj;
		}
	}

}

//called from cancel seat to confirm
bool confirm_cseat(int s, int r = -1) {
	switch (s) {
	case 1: {
		if (r == 3 || r == 4) {
			cout << "cancellation charge will be : 350" << endl;     //keep the balance amount
		}
		if (r == 0 || r == 1 || r == 5) {
			cout << "cancellation charge will be : 400" << endl;
		}
		if (r == 2) {
			cout << "cancellation charge will be : 450" << endl;
		}
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

// called from dashboard after login
// in which bus u need to cancel will be in s
void cancel_seat(int s) {
	switch (s) {
	case 1: {                                           // enter position to be canceled
		cout << "Enter seat row" << endl;
		int r;
		cin >> r;
		r = r - 1;
		cout << "enter seat column" << endl;
		char c;
		cin >> c;
		//auto pr = ACSleep[r].find(c);                          // take data from that position
		c = c - 65;
		if (ACSleeper[r][c].Booker_name == log_Cust.name) {          // check login name and booker name matches
			if (confirm_cseat(1, r)) {                             // confirm cancellation
				ACSleeper[r][c].Passenger_name = "";
				ACSleeper[r][c].Booker_name = "";
				ACSleeper[r][c].gender = 'o';
				cout << "cancelled" << endl;
				if (r == 3 || r == 4) {
					ACSleeper[r][c].amount = (ACSleeper[r][c].amount) - 350;     //keep the balance amount
				}
				if (r == 0 || r == 1 || r == 5) {
					ACSleeper[r][c].amount = (ACSleeper[r][c].amount) - 400;
				}
				if (r == 2) {
					ACSleeper[r][c].amount = (ACSleeper[r][c].amount) - 450;
				}
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
		c=c-65;
		//auto pr = NonACSleep[r].find(c);
		if (NonACSleeper[r][c].Booker_name == log_Cust.name) {
			if (confirm_cseat(2, r)) {
				NonACSleeper[r][c].Passenger_name = "";
				NonACSleeper[r][c].Booker_name = "";
				NonACSleeper[r][c].gender = 'o';
				cout << "cancelled" << endl;
				if (r == 3 || r == 4) {
					NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) - 450;   //25 of 600 is 150  //keep the balance amount
				}
				if (r == 0 || r == 1 || r == 5) {
					NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) - 525;   // 25% of 700 is 175
				}
				if (r == 2) {
					NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) - 600;  //25% of 800 is 200
				}
				NonACSleep_count++;
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
	case 3: {
		cout << "Enter seat row" << endl;
		int r;
		cin >> r;
		cout << "enter seat column" << endl;
		char c;
		cin >> c;
		c = c - 65;
		//auto pr = ACSeeter[r].find(c);
		if (ACSeeter[r][c].Booker_name == log_Cust.name) {
			if (confirm_cseat(3)) {
				ACSeeter[r][c].Passenger_name = "";
				ACSeeter[r][c].Booker_name = "";
				ACSeeter[r][c].gender = 'o';
				cout << "cancelled" << endl;
				ACSeeter[r][c].amount = (ACSeeter[r][c].amount) - 275;
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
		c = c - 65;
		//auto pr = NonACSeeter[r].find(c);
		if (NonACSeeter[r][c].Booker_name == log_Cust.name) {
			if (confirm_cseat(4)) {
				NonACSeeter[r][c].Passenger_name = "";
				NonACSeeter[r][c].Booker_name = "";
				NonACSeeter[r][c].gender = 'o';
				cout << "cancelled" << endl;
				NonACSeeter[r][c].amount = (NonACSeeter[r][c].amount) - 338;
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

// called from check availability to confirm
bool confirm_seat(int s, int r = -1) {
	switch (s) {
	case 1: {
		if (r == 3 || r == 4) {
			cout << "seat available for : 700" << endl;
		}
		if (r == 0 || r == 1 || r == 5) {
			cout << "seat available for : 800" << endl;
		}
		if (r == 2) {
			cout << "seat available for : 900" << endl;
		}
		cout << "press 1 to confirm : " << endl;
		cout << "press 0 to cancel : " << endl;
		int n;
		cin >> n;
		return n;
	}
	case 2: {
		if (r == 3 || r == 4) {
			cout << "seat available for : 600" << endl;
		}
		if (r == 0 || r == 1 || r == 5) {
			cout << "seat available for : 700" << endl;
		}
		if (r == 2) {
			cout << "seat available for : 800" << endl;
		}
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

// called after customer enters passenger details
void check_availablity(string pname, char g, int r, char c, int s) {
	//which bus is s
	Bus obj; //it has --> passenger name , gender , row , column 
	obj.Booker_name = log_Cust.name;
	obj.Passenger_name = pname;
	obj.gender = g;

	switch (s) {
	case 1: {                                                                // AC Sleeper
		c = c - 65;
		if (r == 2 || r == 5) {                                              // side single seats
			//auto pr = ACSleep[r].find(c);
			if (ACSleeper[r][c].Passenger_name == "") {
				if (confirm_seat(1, r)) {
					ACSleeper[r][c] = obj;
					cout << "booked" << endl;
					if (r == 2) {
						ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 900; //lower deck single
					}
					if (r == 5) {
						ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 800; // upper deck single
					}

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
		if (r == 0 || r == 1 || r == 3 || r == 4) {                           // AC Sleeper Double Seats
			//auto pr = ACSleep[r].find(c);

			if (ACSleeper[r][c].Passenger_name == "") {
				ACSleeper[r][c] = obj;                                       // sit and check algo
				if (r == 0 || r == 3) {
					//auto pseat = ACSleep[r + 1].find(c);                 // get nearby seat
					if (ACSleeper[r+1][c].gender == ACSleeper[r][c].gender || ACSleeper[r+1][c].Booker_name == ACSleeper[r][c].Booker_name || ACSleeper[r+1][c].gender == 'o') {

						if (confirm_seat(1, r)) {                          // get confirmation

							cout << "booked" << endl;
							if (r == 3) {
								ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 700; //upper deck double
							}
							if (r == 0) {
								ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 800; // lower deck double
							}
							ACSleep_count--;
							//if booked na amount will be added
						}                                                   // in amount of that seat
						else {
							cout << "canceled";
							ACSleeper[r][c].Passenger_name = "";
							ACSleeper[r][c].Booker_name = "";
							ACSleeper[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						ACSleeper[r][c].Passenger_name = "";
						ACSleeper[r][c].Booker_name = "";
						ACSleeper[r][c].gender = 'o';
						book_seat(1);                                     // to again book another seat
					}
				}
				else if (r == 1 || r == 4) {
					//auto pseat = ACSleep[r - 1].find(c);
					if (ACSleeper[r-1][c].gender == ACSleeper[r][c].gender || ACSleeper[r-1][c].Booker_name == ACSleeper[r][c].Booker_name || ACSleeper[r-1][c].gender == 'o') {
						if (confirm_seat(1, r)) {
							ACSleeper[r][c] = obj;
							cout << "booked" << endl;
							if (r == 1) {
								ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 800;  // lower doble
							}
							if (r == 4) {
								ACSleeper[r][c].amount = (ACSleeper[r][c].amount) + 700;  // upper double
							}

							ACSleep_count--;
						}
						else {
							cout << "canceled";
							ACSleeper[r][c].Passenger_name = "";
							ACSleeper[r][c].Booker_name = "";
							ACSleeper[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						ACSleeper[r][c].Passenger_name = "";
						ACSleeper[r][c].Booker_name = "";
						ACSleeper[r][c].gender = 'o';
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
	case 2:                                                         // non ac sleeper
	{
		c = c - 65;
		if (r == 2 || r == 5) {
			//auto pr = NonACSleep[r].find(c);
			if (NonACSleeper[r][c].Passenger_name == "") {
				if (confirm_seat(2, r)) {
					NonACSleeper[r][c] = obj;
					cout << "booked" << endl;
					if (r == 2) {
						NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 800; //lower deck single
					}
					if (r == 5) {
						NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 700; // upper deck single
					}
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
		if (r == 0 || r == 1 || r == 3 || r == 4) {
			//auto pr = NonACSleep[r].find(c);
			if (NonACSleeper[r][c].Passenger_name == "") {
				NonACSleeper[r][c] = obj;
				if (r == 0 || r == 3) {
					//auto pseat = NonACSleep[r + 1].find(c);
					if (NonACSleeper[r+1][c].gender == NonACSleeper[r][c].gender || NonACSleeper[r+1][c].Booker_name == NonACSleeper[r][c].Booker_name || NonACSleeper[r+1][c].gender == 'o') {
						if (confirm_seat(2, r)) {
							NonACSleeper[r][c] = obj;
							cout << "booked" << endl;
							if (r == 3) {
								NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 600; //upper deck double
							}
							if (r == 0) {
								NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 700; // lower deck double
							}
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							NonACSleeper[r][c].Passenger_name = "";
							NonACSleeper[r][c].Booker_name = "";
							NonACSleeper[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						NonACSleeper[r][c].Passenger_name = "";
						NonACSleeper[r][c].Booker_name = "";
						NonACSleeper[r][c].gender = 'o';
						book_seat(2);
					}
				}
				else if (r == 1 || r == 4) {
					//auto pseat = NonACSleep[r - 1].find(c);
					if (NonACSleeper[r-1][c].gender == NonACSleeper[r][c].gender || NonACSleeper[r-1][c].Booker_name == NonACSleeper[r][c].Booker_name || NonACSleeper[r-1][c].gender == 'o') {
						if (confirm_seat(2, r)) {
							NonACSleeper[r][c] = obj;
							cout << "booked" << endl;
							if (r == 1) {
								NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 800;  // lower doble
							}
							if (r == 4) {
								NonACSleeper[r][c].amount = (NonACSleeper[r][c].amount) + 700;  // upper double
							}
							NonACSleep_count--;
						}
						else {
							cout << "canceled";
							NonACSleeper[r][c].Passenger_name = "";
							NonACSleeper[r][c].Booker_name = "";
							NonACSleeper[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						NonACSleeper[r][c].Passenger_name = "";
						NonACSleeper[r][c].Booker_name = "";
						NonACSleeper[r][c].gender = 'o';
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
		if (r == 0 || r == 1 || r == 2 || r == 3) {
			//auto pr = ACSeeter[r].find(c);
			c = c - 65;
			if (ACSeeter[r][c].Passenger_name == "") {
				ACSeeter[r][c] = obj;

				if (r == 0 || r == 2) {
					//auto pseat = ACSeeter[r + 1].find(c);
					if (ACSeeter[r + 1][c].gender == ACSeeter[r][c].gender || ACSeeter[r + 1][c].Booker_name == ACSeeter[r][c].Booker_name || ACSeeter[r + 1][c].gender == 'o') {

						if (confirm_seat(3)) {

							cout << "booked" << endl;
							ACSeeter[r][c].amount = (ACSeeter[r][c].amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							ACSeeter[r][c].Passenger_name = "";
							ACSeeter[r][c].Booker_name = "";
							ACSeeter[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						ACSeeter[r][c].Passenger_name = "";
						ACSeeter[r][c].Booker_name = "";
						ACSeeter[r][c].gender = 'o';
						book_seat(3);
					}
				}
				else if (r == 1 || r == 3) {
					//auto pseat = ACSeeter[r - 1].find(c);
					if (ACSeeter[r - 1][c].gender == ACSeeter[r][c].gender || ACSeeter[r - 1][c].Booker_name == ACSeeter[r][c].Booker_name || ACSeeter[r - 1][c].gender == 'o') {
						if (confirm_seat(3)) {
							ACSeeter[r][c] = obj;
							cout << "booked" << endl;
							ACSeeter[r][c].amount = (ACSeeter[r][c].amount) + 550;
							ACSeeter_count--;
						}
						else {
							cout << "canceled";
							ACSeeter[r][c].Passenger_name = "";
							ACSeeter[r][c].Booker_name = "";
							ACSeeter[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						ACSeeter[r][c].Passenger_name = "";
						ACSeeter[r][c].Booker_name = "";
						ACSeeter[r][c].gender = 'o';
						book_seat(3);
					}
				}

			}break;
		} 
	}
	case 4: {
		if (r == 0 || r == 1 || r == 2 || r == 3) {
			//auto pr = NonACSeeter[r].find(c);
			c = c - 65;
			if (NonACSeeter[r][c].Passenger_name == "") {
				NonACSeeter[r][c] = obj;

				if (r == 0 || r == 2) {
					//auto pseat = NonACSeeter[r + 1].find(c);
					if (NonACSeeter[r + 1][c].gender == NonACSeeter[r][c].gender || NonACSeeter[r + 1][c].Booker_name == NonACSeeter[r][c].Booker_name || NonACSeeter[r + 1][c].gender == 'o') {

						if (confirm_seat(4)) {

							cout << "booked" << endl;
							NonACSeeter[r][c].amount = (NonACSeeter[r][c].amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							NonACSeeter[r][c].Passenger_name = "";
							NonACSeeter[r][c].Booker_name = "";
							NonACSeeter[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						NonACSeeter[r][c].Passenger_name = "";
						NonACSeeter[r][c].Booker_name = "";
						NonACSeeter[r][c].gender = 'o';
						book_seat(4);
					}
				}
				else if (r == 1 || r == 3) {
					//auto pseat = NonACSeeter[r - 1].find(c);
					if (NonACSeeter[r - 1][c].gender == NonACSeeter[r][c].gender || NonACSeeter[r - 1][c].Booker_name == NonACSeeter[r][c].Booker_name || NonACSeeter[r - 1][c].gender == 'o') {
						if (confirm_seat(4)) {
							NonACSeeter[r][c] = obj;
							cout << "booked" << endl;
							NonACSeeter[r][c].amount = (NonACSeeter[r][c].amount) + 450;
							NonACSeeter_count--;
						}
						else {
							cout << "canceled";
							NonACSeeter[r][c].Passenger_name = "";
							NonACSeeter[r][c].Booker_name = "";
							NonACSeeter[r][c].gender = 'o';
						}
					}
					else {
						cout << "ur opposite gender is nearby cant book " << endl;
						NonACSeeter[r][c].Passenger_name = "";
						NonACSeeter[r][c].Booker_name = "";
						NonACSeeter[r][c].gender = 'o';
						book_seat(4);
					}
				}


				}
			}
		} break;
	} 

}

// int s has which bus needs to be booked
void book_seat(int s) {
	switch (s) {
	case 1: {

		cout << "List of seats available in AC Sleeper:" << endl << endl;
		for (int i = 0; i <= 5; i++) {  // looping in array of (first NUMBER is row)
			for (int j = 0; j <= 1; j++)       // looping in maps (second OBJECT is bus object)
			{
				if (ACSleeper[i][j].Passenger_name == "") {      // if no passesger name na not booked
					cout << i + 1 << ((j == 0) ? 'A' : 'B') << " ";            //so display
				}
			}	cout << endl;
		}
		cout << endl;                                  // for we need to book first we need details of
		cout << "Enter passenger name :";             //passenger so that we can check
		string pname;
		cin >> pname;
		cout << "Enter passenger gender :";
		char g;
		cin >> g;


		cout << "Enter col : ";
		char c; cin >> c;
		cout << "Enter row : ";
		int r; cin >> r;
		
		check_availablity(pname, g, r - 1, c, s);             //checking is done

		break;
	}
	case 2: {
		cout << "List of seats available in Non-AC Sleeper:" << endl << endl;
		for (int i = 0; i <= 5; i++) {  // looping in number
			for (int j = 0; j <= 1; j++)       // looping in char a/b
			{
				if (NonACSleeper[i][j].Passenger_name == "") {      // if no passesger name na not booked
					cout << i + 1 << ((j == 0) ? 'A' : 'B') << " ";            //so display
				}
			}	cout << endl;
		}
		cout << endl;
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

		check_availablity(pname, g, r - 1, c, s);

		break;
	}
	case 3: {
		cout << "List of seats available in AC Seeter:" << endl << endl;
		for (int i = 0; i <= 3; i++) {  // looping in number
			for (int j = 0; j <= 2; j++)       // looping in char a/b
			{
				if (ACSeeter[i][j].Passenger_name == "") {
					cout << i + 1 << ((char)(j+65)) << " ";
				}
			}	cout << endl;
		}
		cout << endl;
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

		check_availablity(pname, g, r - 1, c, s);

		break;
	}
	case 4: {
		cout << "List of seats available in Non-AC Seeter:" << endl << endl;
		for (int i = 0; i <= 3; i++) {  // looping in number
			for (int j = 0; j <= 2; j++)       // looping in char a/b
			{
				if (NonACSeeter[i][j].Passenger_name == "") {
					cout << i + 1 << ((char)(j + 65)) << " ";
				}
			}	cout << endl;
		}
		cout << endl;
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

		check_availablity(pname, g, r - 1, c, s);

		break;
	}
	}


}

// if login successful na directed to dashboard from Customer_login()
int dashboard() {

	while (1) {

		cout << endl;
		cout << "AC Sleeper : " << ACSleep_count << " press 1" << endl;
		cout << "Non-AC Sleeper : " << NonACSleep_count << " press 2" << endl;
		cout << "AC Seeter : " << ACSeeter_count << " press 3" << endl;
		cout << "Non AC Seeter : " << ACSeeter_count << " press 4" << endl;
		cout << "To cancel Ticket : press 5" << endl;
		cout << "To Exit : 10" << endl;
		cout << endl;

		int s;
		cin >> s;
		switch (s) {
		case 1: {
			cout << "enter no. of seats to be booked in AC-Sleeper: " << endl;
			int n;
			cin >> n;
			if (n <= ACSleep_count) {
				for (int i = 0; i < n; i++) {
					book_seat(1);
				}
			}
			else {
				cout << "seats are lesser than ur booking count" << endl;
			}

			break;
		}
		case 2: {
			cout << "enter no. of seats to be booked in Non AC-Sleeper: " << endl;
			int n;
			cin >> n;
			if (n <= NonACSleep_count) {
				for (int i = 0; i < n; i++) {
					book_seat(2);
				}
			}
			else {
				cout << "seats are lesser than ur booking count" << endl;
			}

			break;
		}
		case 3: {
			cout << "enter no. of seats to be booked in AC-Seeter: " << endl;
			int n;
			cin >> n;
			if (n <= ACSeeter_count) {
				for (int i = 0; i < n; i++) {
					book_seat(3);
				}
			}
			else {
				cout << "seats are lesser than ur booking count" << endl;
			}

			break;
		}
		case 4: {
			cout << "enter no. of seats to be booked in NonAC-Seeter: " << endl;
			int n;
			cin >> n;
			if (n <= NonACSeeter_count) {
				for (int i = 0; i < n; i++) {
					book_seat(4);
				}
			}
			else {
				cout << "seats are lesser than ur booking count" << endl;
			}

			break;
		}
		case 5: {
			cout << "which ticket u need to cancel :" << endl;
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


//signup page from main
void Customer_signup() {
	Customer obj;
	obj.id = Cust_ID++;
	cout << "Enter ur Name : ";
	cin >> obj.name;
label:                                                  // if exist na enter another user name
	cout << "Enter ur UName : ";
	cin >> obj.username;
	if (Customer_DB.find(obj.username) != Customer_DB.end()) {  // check user name already exist
		cout << "User name already exist -:";
		goto label;
	}
	cout << "Enter ur Pass : ";
	cin >> obj.password;
	cout << "Enter ur Age : ";
	cin >> obj.age;
	cout << "Enter ur Gender : ";
	cin >> obj.gender;

	pair<string, Customer> pair_data;                     // username as key , cust data as value
	pair_data = make_pair(obj.username, obj);
	Customer_DB.insert(pair_data);

}

//login page from main
int Customer_login() {
	string UName;
	string pass;
	cout << "Enter User Name : ";
	cin >> UName;
	cout << "Enter PassWord : ";
	cin >> pass;
	cout << endl;

	if (Customer_DB.find(UName) == Customer_DB.end()) { // checking if username exist
		cout << "User name not exist -:" << endl;
	}
	else {
		auto itr = Customer_DB.find(UName);
		if (itr->second.password == pass) {    // checking password
			log_Cust = itr->second;
			cout << "||--------------- Login Success ------------------||" << endl << endl;
			int a = dashboard();
			if (a) { return 1; }
		}
		else {
			cout << "||--------------- Password Wrong ------------------||" << endl << endl;
		}
	}

}

//to display bus datas from main
void admin() {
	cout << "This is admin Dashboard :" << endl;
	cout << "select the bus details to be displayed" << endl;
	cout << "AC Sleeper : 1" << endl;
	cout << "Non AC Sleeper : 2" << endl;
	cout << "AC Seeter : 3" << endl;
	cout << "Non AC Seeter : 4" << endl;

	int n;
	cin >> n;
	switch (n) {
	case 1: {
		cout << "Number of seats filled : " << (12 - ACSleep_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 0; i <= 5; i++) {  // looping in number
			for (int j = 0; j <= 1; j++)       // looping in char a/b
			{
				if (ACSleeper[i][j].Passenger_name != "") {
					cout << ((j == 0) ? 'A' : 'B') << i + 1 << " " << ACSleeper[i][j].Passenger_name << " " << ACSleeper[i][j].gender;

				}
				amount = amount + ACSleeper[i][j].amount;
			}cout << endl;
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	case 2: {
		cout << "Number of seats filled : " << (12 - NonACSleep_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 0; i <= 5; i++) {  // looping in number
			for (int j = 0; j <= 1; j++)       // looping in char a/b
			{
				if (NonACSleeper[i][j].Passenger_name != "") {
					cout << ((j == 0) ? 'A' : 'B') << i + 1 << " " << NonACSleeper[i][j].Passenger_name << " " << NonACSleeper[i][j].gender;

				}
				amount = amount + NonACSleeper[i][j].amount;
			}cout << endl;
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	case 3: {
		cout << "Number of seats filled : " << (12 - ACSeeter_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 0; i <= 3; i++) {  // looping in number
			for (int j = 0; j <= 2; j++)       // looping in char a/b
			{
				if (ACSeeter[i][j].Passenger_name != "") {
					cout << i + 1 << ((char)(j + 65)) << " " << ACSeeter[i][j].Passenger_name << " " << ACSeeter[i][j].gender;

				}
				amount = amount + ACSeeter[i][j].amount;
			}cout << endl;
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	case 4: {
		cout << "Number of seats filled : " << (12 - NonACSeeter_count) << endl;
		cout << "seat details" << endl;
		int amount = 0;
		for (int i = 0; i <= 3; i++) {  // looping in number
			for (int j = 0; j <= 2; j++)       // looping in char a/b
			{
				if (NonACSeeter[i][j].Passenger_name != "") {
					cout << i + 1 << ((char)(j + 65)) << " " << NonACSeeter[i][j].Passenger_name << " " << NonACSeeter[i][j].gender;

				}
				amount = amount + NonACSeeter[i][j].amount;
			}cout << endl;
		}
		cout << "amount collected : " << amount << endl;
		break;
	}
	}
}

//to display bus details from main
void view_bus_details() {

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

//main function is for front page
int main() {

	Ini_Customer_DB();
	Ini_Bus_DB();

	while (1) {

		cout << "||----------- welcome to ZOBUS login -------------||" << endl << endl;
		cout << "Login : 1" << endl;
		cout << "SignUp : 2" << endl;
		cout << "view bus details : 3" << endl;
		cout << "admin : 4" << endl;
		cout << "exit : 10" << endl << endl;
		cout << "||------------------------------------------------||" << endl << endl;

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
