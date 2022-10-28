#include<iostream>
#include<string>
#include <unordered_map>
#include<map>
#include <list>
using namespace std;

//for AC sleeper
#define upper_double 800;
#define upper_single 900;
#define lower_double 900;
#define lower_single 1000;

//for AC seeter
#define seeter_price 700;


struct cancel {
	string passenger_name;
	int cancel_amount;
	int bus_id;
	int row;
	int column;
};

struct customer {
	int id;
	string name;
	string user_name;
	string password;
	unordered_map<int, int> M_book_bus_id;
};

struct seat {
	string booker_name;
	int booking_id;
	string passenger_name;
	string passenger_gender;
	int seat_amount;
	int cancel_amount;
	seat() {
		booker_name = "";
		booking_id = -1;
		passenger_name = "";
		passenger_gender = "o";
		seat_amount = 0;
		cancel_amount = 0;
	}
};

struct bus {
	int bus_id;
	string bus_type;
	bool ac;
	int row;
	int col;
	int count;
	vector<vector<seat>> V_bus_seat;
};

int Cust_ID = 0;
int Bus_ID = 0;
map<string, customer> Customer_DB;
customer log_Cust;
vector<bus> Bus_DB;
int booking_id = -1;
list<cancel> cancel_list;

void init_cust() {
	customer obj;

	obj.id = Cust_ID++;
	obj.name = "aaa";
	obj.user_name = "aaa_";
	obj.password = "111";
	pair<string, customer> pair_data;
	pair_data = make_pair(obj.user_name, obj);
	Customer_DB.insert(pair_data);

	obj.id = Cust_ID++;
	obj.name = "bbb";
	obj.user_name = "bbb_";
	obj.password = "222";
	pair_data = make_pair(obj.user_name, obj);
	Customer_DB.insert(pair_data);

	obj.id = Cust_ID++;
	obj.name = "ccc";
	obj.user_name = "ccc_";
	obj.password = "333";
	pair_data = make_pair(obj.user_name, obj);
	Customer_DB.insert(pair_data);

}

void init_bus() {
	bus obj;
	obj.bus_id = Bus_ID++;
	obj.bus_type = "sleeper";
	obj.ac = 1;
	obj.row = 6;
	obj.col = 2;
	obj.count = 6 * 2;

	seat sobj;
	vector<seat> temp;
	for (int i = 0; i < obj.row; i++) {
		temp.clear();
		for (int j = 0; j < obj.col; j++) {
			temp.push_back(sobj);
		}
		obj.V_bus_seat.push_back(temp);
	}

	Bus_DB.push_back(obj);

	obj.bus_id = Bus_ID++;
	obj.bus_type = "sleeper";
	obj.ac = 0;
	obj.row = 6;
	obj.col = 2;
	obj.count = 6 * 2;
	obj.V_bus_seat.clear();

	for (int i = 0; i < obj.row; i++) {
		temp.clear();
		for (int j = 0; j < obj.col; j++) {
			temp.push_back(sobj);
		}
		obj.V_bus_seat.push_back(temp);
	}

	Bus_DB.push_back(obj);

	obj.bus_id = Bus_ID++;
	obj.bus_type = "seeter";
	obj.ac = 1;
	obj.row = 4;
	obj.col = 3;
	obj.count = 4 * 3;
	obj.V_bus_seat.clear();

	for (int i = 0; i < obj.row; i++) {
		temp.clear();
		for (int j = 0; j < obj.col; j++) {
			temp.push_back(sobj);
		}
		obj.V_bus_seat.push_back(temp);
	}

	Bus_DB.push_back(obj);

	obj.bus_id = Bus_ID++;
	obj.bus_type = "seeter";
	obj.ac = 0;
	obj.row = 4;
	obj.col = 3;
	obj.count = 4 * 3;
	obj.V_bus_seat.clear();

	for (int i = 0; i < obj.row; i++) {
		temp.clear();
		for (int j = 0; j < obj.col; j++) {
			temp.push_back(sobj);
		}
		obj.V_bus_seat.push_back(temp);
	}

	Bus_DB.push_back(obj);

}


void canceled_details() {

	
	for (auto it = cancel_list.begin(); it != cancel_list.end(); ++it) {
		cout << (*it).bus_id << " " << (*it).passenger_name << " " << (*it).cancel_amount << " " << (char)(((*it).column) + 65) << ((*it).row)+1 << endl;
	}

}

int display_bus(int s) {
	cout << endl;
	int count = 0;
	for (int i = 0; i < Bus_DB.size(); i++) {
		if (Bus_DB[i].count > 0) {
			switch (s) {
			case 1: {
				if (Bus_DB[i].ac && Bus_DB[i].bus_type == "sleeper") {
					cout << "Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
					count++;
				}
				break;
			}
			case 2: {
				if (Bus_DB[i].ac && Bus_DB[i].bus_type == "seeter") {
					cout << "Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
					count++;
				}
				break;
			}
			case 3: {
				if (!(Bus_DB[i].ac) && Bus_DB[i].bus_type == "sleeper") {
					cout << "Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
					count++;
				}
				break;
			}
			case 4: {
				if (!(Bus_DB[i].ac) && Bus_DB[i].bus_type == "seeter") {
					cout << "Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
					count++;
				}
				break;
			}
			case 5: {
				if (Bus_DB[i].ac && Bus_DB[i].bus_type == "sleeper") {
					cout << "AC Sleeper Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
				}
				if (Bus_DB[i].ac && Bus_DB[i].bus_type == "seeter") {
					cout << "AC Seeter Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
				}
				if (!(Bus_DB[i].ac) && Bus_DB[i].bus_type == "sleeper") {
					cout << "Sleeper Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
				}
				if (!(Bus_DB[i].ac) && Bus_DB[i].bus_type == "seeter") {
					cout << "Seeter Bus ID : " << Bus_DB[i].bus_id << " available seats : " << Bus_DB[i].count << endl;
				}
				count++;
				break;
			}
			}
		}
	}cout << endl;
	return count;
}

void cancel_particular_ticket(int busid) {
	cout << "Enter Column :";
	char c;
	cin >> c;
	c = c - 65;
	cout << "Enter Row :";
	int r;
	cin >> r;
	r = r - 1;

	if (Bus_DB[busid].V_bus_seat[r][c].booker_name == log_Cust.user_name) {
		cancel cobj;
		cobj.bus_id = busid;
		cobj.passenger_name = Bus_DB[busid].V_bus_seat[r][c].passenger_name;
		if (Bus_DB[busid].ac) {
			cobj.cancel_amount = Bus_DB[busid].V_bus_seat[r][c].seat_amount / 2;
			Bus_DB[busid].V_bus_seat[r][c].cancel_amount = Bus_DB[busid].V_bus_seat[r][c].cancel_amount + cobj.cancel_amount;
		}
		else {
			cobj.cancel_amount = Bus_DB[busid].V_bus_seat[r][c].seat_amount / 4;
			Bus_DB[busid].V_bus_seat[r][c].cancel_amount = Bus_DB[busid].V_bus_seat[r][c].cancel_amount + cobj.cancel_amount;
		}
		cobj.column = c;
		cobj.row = r;
		cancel_list.push_back(cobj);

		Bus_DB[busid].V_bus_seat[r][c].booker_name = "";
		Bus_DB[busid].V_bus_seat[r][c].booking_id = -1;
		Bus_DB[busid].V_bus_seat[r][c].passenger_gender = "o";
		Bus_DB[busid].V_bus_seat[r][c].passenger_name = "";
		Bus_DB[busid].V_bus_seat[r][c].seat_amount = 0;
		Bus_DB[busid].count++;
	}
	else {
		cout << "This seat is not booked by you"<<endl;
	}

}

void cancel_bookingid(int bookid) {
	int busid = -1;
	for (auto itr = log_Cust.M_book_bus_id.begin(); itr != log_Cust.M_book_bus_id.end(); itr++) {
		if (itr->first == bookid) {
			busid = itr->second;
			break;
		}
	}

	for (int i = 0; i < Bus_DB[busid].row; i++) {
		for (int j = 0; j < Bus_DB[busid].col; j++) {
			if (Bus_DB[busid].V_bus_seat[i][j].booking_id == bookid) {

				int r = i;
				int c = j;
				cancel cobj;
				cobj.bus_id = busid;
				cobj.passenger_name = Bus_DB[busid].V_bus_seat[r][c].passenger_name;
				if (Bus_DB[busid].ac) {
					cobj.cancel_amount = Bus_DB[busid].V_bus_seat[r][c].seat_amount / 2;
					Bus_DB[busid].V_bus_seat[r][c].cancel_amount = Bus_DB[busid].V_bus_seat[r][c].cancel_amount + cobj.cancel_amount;
				}
				else {
					cobj.cancel_amount = Bus_DB[busid].V_bus_seat[r][c].seat_amount / 4;
					Bus_DB[busid].V_bus_seat[r][c].cancel_amount = Bus_DB[busid].V_bus_seat[r][c].cancel_amount + cobj.cancel_amount;
				}
				cobj.column = c;
				cobj.row = r;
				cancel_list.push_back(cobj);

				Bus_DB[busid].V_bus_seat[r][c].booker_name = "";
				Bus_DB[busid].V_bus_seat[r][c].booking_id = -1;
				Bus_DB[busid].V_bus_seat[r][c].passenger_gender = "o";
				Bus_DB[busid].V_bus_seat[r][c].passenger_name = "";
				Bus_DB[busid].V_bus_seat[r][c].seat_amount = 0;
				Bus_DB[busid].count++;
			}
		}
	}

}

void book_seat(int bus_id) {
	seat obj;

	obj.booker_name = log_Cust.user_name;
	obj.booking_id = booking_id;
	cout << endl;
	cout << "enter passenger Name : ";
	cin>>obj.passenger_name;
	cout << "enter passenger Gender";
	cin>>obj.passenger_gender;

	label:
	cout << "Enter column :";
	char c;
	cin >> c;
	c = c - 65;
	cout << "Enter row";
	int r;
	cin >> r;
	r = r - 1;

	if (Bus_DB[bus_id].V_bus_seat[r][c].passenger_name == "") {
		if (Bus_DB[bus_id].bus_type == "sleeper") {


			if (r == 2 || r == 5) {
				Bus_DB[bus_id].V_bus_seat[r][c].booker_name = obj.booker_name;
				Bus_DB[bus_id].V_bus_seat[r][c].booking_id = obj.booking_id;
				Bus_DB[bus_id].V_bus_seat[r][c].passenger_name = obj.passenger_name;
				Bus_DB[bus_id].V_bus_seat[r][c].passenger_gender = obj.passenger_gender;
				if (Bus_DB[bus_id].ac) {
					if (r == 2)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_single;
					if (r == 5)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_single;
				}
				else {
					if (r == 2)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_single-100;
					if (r == 5)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_single-100;
				}
				Bus_DB[bus_id].count--;
				
			}
			if (r == 0 || r == 3) {
				if (Bus_DB[bus_id].V_bus_seat[r+1][c].passenger_name == "" || Bus_DB[bus_id].V_bus_seat[r + 1][c].booker_name == obj.booker_name || Bus_DB[bus_id].V_bus_seat[r + 1][c].passenger_gender == obj.passenger_gender) {

					Bus_DB[bus_id].V_bus_seat[r][c].booker_name = obj.booker_name;
					Bus_DB[bus_id].V_bus_seat[r][c].booking_id = obj.booking_id;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_name = obj.passenger_name;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_gender = obj.passenger_gender;
					if (Bus_DB[bus_id].ac) {
						if (r == 0)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_double;
						if (r == 3)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_double;
					}
					else {
						if (r == 0)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_double - 100;
						if (r == 3)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_double - 100;
					}
					Bus_DB[bus_id].count--;
				}
				else {
					cout << "opposite gender is nearby book another seat"<<endl;
					goto label;
				}
			}
			if (r == 1 || r == 4) {
				if (Bus_DB[bus_id].V_bus_seat[r - 1][c].passenger_name == "" || Bus_DB[bus_id].V_bus_seat[r - 1][c].booker_name == obj.booker_name || Bus_DB[bus_id].V_bus_seat[r - 1][c].passenger_gender == obj.passenger_gender) {

					Bus_DB[bus_id].V_bus_seat[r][c].booker_name = obj.booker_name;
					Bus_DB[bus_id].V_bus_seat[r][c].booking_id = obj.booking_id;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_name = obj.passenger_name;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_gender = obj.passenger_gender;
					if (Bus_DB[bus_id].ac) {
						if (r == 1)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_double;
						if (r == 4)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_double;
					}
					else {
						if (r == 1)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = lower_double - 100;
						if (r == 4)Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = upper_double - 100;
					}
					Bus_DB[bus_id].count--;
				}
				else {
					cout << "opposite gender is nearby book another seat" << endl;
					goto label;
				}


			}
		}
		if (Bus_DB[bus_id].bus_type == "seeter") {

			if (r == 0 || r == 2) {
				if (Bus_DB[bus_id].V_bus_seat[r + 1][c].passenger_name == "" || Bus_DB[bus_id].V_bus_seat[r + 1][c].booker_name == obj.booker_name || Bus_DB[bus_id].V_bus_seat[r + 1][c].passenger_gender == obj.passenger_gender) {

					Bus_DB[bus_id].V_bus_seat[r][c].booker_name = obj.booker_name;
					Bus_DB[bus_id].V_bus_seat[r][c].booking_id = obj.booking_id;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_name = obj.passenger_name;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_gender = obj.passenger_gender;
					if (Bus_DB[bus_id].ac) {
						Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = seeter_price;		
					}
					else {
						Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = seeter_price-100;
					}
					Bus_DB[bus_id].count--;
				}
				else {
					cout << "opposite gender is nearby book another seat" << endl;
					goto label;
				}
			}
			if (r == 1 || r == 3) {
				if (Bus_DB[bus_id].V_bus_seat[r - 1][c].passenger_name == "" || Bus_DB[bus_id].V_bus_seat[r - 1][c].booker_name == obj.booker_name || Bus_DB[bus_id].V_bus_seat[r - 1][c].passenger_gender == obj.passenger_gender) {

					Bus_DB[bus_id].V_bus_seat[r][c].booker_name = obj.booker_name;
					Bus_DB[bus_id].V_bus_seat[r][c].booking_id = obj.booking_id;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_name = obj.passenger_name;
					Bus_DB[bus_id].V_bus_seat[r][c].passenger_gender = obj.passenger_gender;
					if (Bus_DB[bus_id].ac) {
						Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = seeter_price;
					}
					else {
						Bus_DB[bus_id].V_bus_seat[r][c].seat_amount = seeter_price-100;
					}
					Bus_DB[bus_id].count--;
				}
				else {
					cout << "opposite gender is nearby book another seat" << endl;
					goto label;
				}


			}

		}
	}
	else {
		cout << "Seat is already booker " << endl;
	}

}

int book_bus(int s) {
	int count = display_bus(s);
	if (count == 0) {
		cout << "No Bus Available"<<endl;
		return 0;
	}
	cout << "Enter the bus ID in which you want to book : ";
	int id;
	cin >> id;
	cout << endl;

	cout << "available seats in bus " << id<<" : " << endl << endl;

	for (int i = 0; i < Bus_DB[id].row; i++) {
		for (int j = 0; j < Bus_DB[id].col; j++) {
			if (Bus_DB[id].V_bus_seat[i][j].passenger_name == "") {
				cout << (char)(j+65)<<i+1 << " ";
			}
		}cout << endl;
	}cout << endl;

	cout << "Enter How many seats you want to book" << endl;
	int n;
	cin >> n;
	booking_id++;
	for (int i = 0; i < n; i++) {
		book_seat(id);
	}

	pair<int, int> pair_data;                     // booking id as key , bus id as value
	pair_data = make_pair(booking_id, id);
	log_Cust.M_book_bus_id.insert(pair_data);

	auto itr = Customer_DB.find(log_Cust.user_name);
	itr->second = log_Cust;

}

int view_bus() {
	while (1) {

		cout << "View AC Sleeper : 1" << endl;
		cout << "View AC Seeter : 2" << endl;
		cout << "View Sleeper : 3" << endl;
		cout << "View Seeter : 4" << endl;
		cout << "View All : 5" << endl;
		cout << "Back : 10" << endl << endl;
		int n;
		cin >> n;
		if (n == 10) return(0);
		else display_bus(n);


	}
}

int dashboard() {
	cout << "||--------------- welcome "<<log_Cust.name<<" ------------------||" << endl << endl;

	while (1) {

		cout << "View Busses : 1" << endl;
		cout << "Book Buss : 2" << endl;
		cout << "Cancel Bus : 3" << endl;
		cout << "Logout : 10" << endl << endl;

		int n;
		cin >> n;
		switch (n) {
		case 1:
			view_bus();
			break;
		case 2: {
			cout << "Enter which Bus you want to book : "<<endl;
			cout << "AC Sleeper : 1" << endl;
			cout << "AC Seeter : 2" << endl;
			cout << "Sleeper : 3" << endl;
			cout << "Seeter : 4" << endl;
			int o;
			cin >> o;
			book_bus(o);
			break;
		}
		case 3: {
			int count = 0;
			cout << "Tickets Booked by "<<log_Cust.name <<" :" << endl;
			
			for (auto itr = log_Cust.M_book_bus_id.begin(); itr != log_Cust.M_book_bus_id.end(); itr++){
				cout << "Booking id : "<< itr->first<<endl;
				
				cout << "Bus id : " << Bus_DB[itr->second].bus_id<<endl;
				cout << "Bus Type : " << Bus_DB[itr->second].bus_type<<endl;
				cout << "AC : " << Bus_DB[itr->second].ac<<endl;
				cout << "list of seats Booked :"<<endl;
				for (int i = 0; i < Bus_DB[itr->second].row; i++) {
					for (int j = 0; j < Bus_DB[itr->second].col; j++) {
						if (Bus_DB[itr->second].V_bus_seat[i][j].booking_id == itr->first) {
							cout << (char)(j + 65) << i + 1 << " ";
							count++;
						}
					}cout << endl;
				}cout << endl;

			}
			if (count == 0) {
				cout << "Not booked any tickets yet"<<endl;
			}
			else {
				cout << "cancel ticket by booking id : 1" << endl;
				cout << "cancel a particular ticket : 2" << endl;
				cout << "back : 10"<<endl;
				int t;
				cin >> t;
				switch (t) {
					case 1: {
						cout << "Enter the booking id :" << endl;
						int u;
						cin >> u;
						cancel_bookingid(u);
						break;
					}
					case 2: {
						cout << "Enter bus id :" << endl;
						int bid;
						cin >> bid;
						cancel_particular_ticket(bid);

						break;
					}
					case 10: {
						return 0;
						break;
					}
				}
			}
				
			

			break;
		}
		case 10:
			return(0);
		}


	}

}

void add_bus() {
	bus obj;
	obj.bus_id = Bus_ID++;
	cout << "Your Bus ID : " << obj.bus_id<<endl;
	cout << "Enter Your Bus type (sleeper/seeter) : ";
	cin>>obj.bus_type;

	if (obj.bus_type == "sleeper")obj.row = 6;
	else if (obj.bus_type == "seeter")obj.row = 4;

	cout << "AC available (1/0) : ";
	cin>>obj.ac;
	
	cout << "Enter No. of columns Your Bus has : ";
	cin>>obj.col;

	seat sobj;
	vector<seat> temp;
	for (int i = 0; i < obj.row; i++) {
		temp.clear();
		for (int j = 0; j < obj.col; j++) {
			temp.push_back(sobj);
		}
		obj.V_bus_seat.push_back(temp);
	}	

	obj.count = obj.row * obj.col;
	Bus_DB.push_back(obj);

	cout << "bus added successfully "<<endl;

}

int admin() {
	while (1) {

		cout << "||----------- admin dashboard -------------||" << endl << endl;
		cout << "Add Bus : 1" << endl;
		cout << "View cancel ticket details : 2" << endl;
		cout << "back : 10" << endl << endl;
		cout << "||------------------------------------------------||" << endl << endl;

		int n;
		cin >> n;
		switch (n) {
		case 1:
			add_bus();
			break;
		case 2:
			canceled_details();
			break;
		case 10:
			return(0);
		}


	}
}

void Customer_signup() {
	customer obj;
	obj.id = Cust_ID++;
	cout << "Enter ur Name : ";
	cin >> obj.name;
label:                                                  // if exist na enter another user name
	cout << "Set User Name : ";
	cin >> obj.user_name;
	if (Customer_DB.find(obj.user_name) != Customer_DB.end()) {  // check user name already exist
		cout << "User name already exist -:";
		goto label;
	}
	cout << "Enter ur Pass : ";
	cin >> obj.password;
	

	pair<string, customer> pair_data;                     // username as key , cust data as value
	pair_data = make_pair(obj.user_name, obj);
	Customer_DB.insert(pair_data);

}

void Customer_login() {
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
		}
		else {
			cout << "||--------------- Password Wrong ------------------||" << endl << endl;
		}
	}

}

int main() {

	init_cust();
	init_bus();

	while (1) {

		cout << "||----------- Login to book BUS -------------||" << endl << endl;
		cout << "Login : 1" << endl;
		cout << "SignUp : 2" << endl;
		cout << "Admin : 3" << endl;
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
			admin();
			break;
		case 10:
			exit(0);
		}


	}
	
}
