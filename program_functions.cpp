#include<fstream>
#include<climits>
#include<string>
#include<vector>
#include "program_functions.h"


int load_coursefile(string filename, vector<Course> & clist)
{
	//cin >> filename;
		
	ifstream in_stream(filename);

	if (in_stream.fail())
	{
		cout << "Failed to connect to file " << filename << endl;
		return 0;
	}
	else
	{
		cout << "Connected to file " << filename << " successfully!" << endl << endl;
		
		int added = 0;		
		while (!in_stream.eof())
		{	
			//course
			vector<string> cdata;  //Loads all parameters of a course from file into a vector to easily set parameters of a course structure
			for (int i = 0; i < 8; i++)
			{
				string que;
				in_stream >> que;
				cdata.push_back(que);
			}
			
			string cID = cdata.at(0);
			Date sDate( stoi(cdata.at(1)), stoi(cdata.at(2)), stoi(cdata.at(3)) );
			Date eDate( stoi(cdata.at(4)), stoi(cdata.at(5)), stoi(cdata.at(6)) );
			int cMax = stoi(cdata.at(7));

			//
			Course tempCourse(cID, sDate, eDate, cMax);
			
			bool duplicate = false;
			for (unsigned int j = 0; j < clist.size(); j++)
			{
				if (clist.at(j).get_cid() == cID)
				{
					duplicate = true;
				}	
			}
			if (!duplicate)
			{
				clist.push_back(tempCourse);
				added++;	
			}
			cdata.clear();
		}
		return added;	
	}
}


int load_studentfile(string filename, vector<Student> & slist){
	//cin >> filename;
		
	ifstream in_stream(filename);

	if (in_stream.fail())
	{
		cout << "Failed to connect to file " << filename << endl;
		return 0;
	}

	else
	{
		cout << "Connected to file " << filename << " successfully!" << endl << endl;
		
		int added = 0;
		while (!in_stream.eof())
		{	
			vector<string> sdata;  //Loads all parameters of a course from file into a vector to easily set parameters of a course structure
			for (int i = 0; i < 7; i++)
			{
				string que;
				in_stream >> que;
			//	cout << que << endl;
				sdata.push_back(que);
			}
	
			string fname = sdata.at(1);
			string lname = sdata.at(2);
			string cell = sdata.at(3);
			string id = sdata.at(0);
			Date birthdate( stoi(sdata.at(4)), stoi(sdata.at(5)), stoi(sdata.at(6)) );
			
			Student tempStudent(fname, lname, cell, id, birthdate);
			
			
			bool duplicate = false;
			for (unsigned int j = 0; j < slist.size(); j++)
			{
				if (slist.at(j).get_ID() == id)
				{
					duplicate = true;
				}	
			}
			if (!duplicate)
			{
				slist.push_back(tempStudent);
				added++;	
			}
			sdata.clear();
		}
		return added;	
	}
}




int enrollment_file(string filename, vector<Course> & clist, vector<Student>& slist){
		
	ifstream in_stream(filename);

	if (in_stream.fail())
	{
		cout << "Failed to connect to file " << filename << endl;
		return 0;
	}

	else
	{
		cout << "Connected to file " << filename << " successfully!" << endl << endl;
		
		int student = 0;
		while (!in_stream.eof())
		{	
			student++;
			
		//	vector<string> edata;  //Will contain all data
			
			string sid;
			in_stream >> sid;

			//edata.push_back(sid); //this will be student id
			
			int courseAmount;
			in_stream >> courseAmount; //check how many courses to add
			

			
			for (int i = 0; i < courseAmount; i++)
			{
				
				//cout << endl << endl << "HERE 1" << endl << endl;
				string cid;
				
				//cout << endl << endl << "HERE 2" << endl << endl;				
				in_stream >> cid;	
				
				
			//	edata.push_back(cid);
				
				//cout << endl << endl << "HERE 3" << endl << endl;				
				enroll_to_course(sid, cid, slist, clist);
			}
			
			
		//	for (unsigned int j = 0; j < edata.size(); j++)
		//	{
			//	cout << "Student: " << student << " -> " << edata[j] << endl;
				
			//}

		}
	}
	return -1;
	
	
}





void enter_wait(){
	cout << "<<<<<< Press Enter to coninue >>>>>>" << endl << endl;
	cin.ignore(INT_MAX,'\n');		
}	

void enter_clear(){
	cin.ignore(INT_MAX,'\n');	
	cout << "<<<<<< Press Enter to coninue >>>>>>" << endl << endl;
	cin.ignore(INT_MAX,'\n');	
	system("clear");
}	

	
void buffer_cleaner(){
	cin.clear();
	cin.ignore(INT_MAX,'\n');	
}





Course* find_course(string cid, vector<Course> & clist){
	for (unsigned int i = 0; i < clist.size(); i++)
	{
		if (clist.at(i).get_cid() == cid)
		{
			Course* p = &clist.at(i);
			return p;
		}	
	}	
	//Course* c;
	return NULL;
}



Student* find_student(string sid, vector<Student> & slist){
	for (unsigned int i = 0; i < slist.size(); i++)
	{
		if (slist.at(i).get_ID() == sid)
		{
			Student* p = &slist.at(i);
			return p;
		}	
	}	
	//Student* s;
	return NULL;
}






void show_student_details(string id,vector<Student>& slist)
{
	Student* s = find_student(id, slist);
					
	if (s != NULL){
		cout << "Student information:";
		cout << s->student_info() << endl << endl;
		//cout << "TEST: " << s->get_ID() << endl << endl;
	}
	
	else{
		cout << "Student not found "<< endl;		
	}

}



void show_course_details(string cid,vector<Course>& clist)
{
	Course* c = find_course(cid, clist);
					
	if (c != NULL){
		cout << "Course information:" << endl;
		cout << c->course_info() << endl << endl;
		//cout << "TEST: " << c->get_cid() << endl << endl;
	}
	
	else{
		cout << "Course not found "<< endl;		
	}

}

Course create_course(){
	cout << "Provide the following information for course creation" << endl;
	cout << "Course ID: ";
	string temp_cid = get_input();				

	cout << endl << "Enter start date (yyyy mm dd): ";
	Date sDate(get_int(), get_int(), get_int());
						
	cout << endl << "Enter end date (yyyy mm dd): ";
	Date eDate(get_int(), get_int(), get_int());

	cout << endl << "Enter Course Capacity: ";
	int max = get_int();		
					
	Course c(temp_cid, sDate, eDate, max);								
	return c;
						
}


Student create_student(){
	cout << "Provide the following information for student creation" << endl;

	Student s;	
	s.set_Fname(prompt_get("Enter student first name: "));
	//nl();
	s.set_Lname(prompt_get("Enter student last name: "));
	//nl();
	s.set_phone(prompt_get("Enter student cell number: "));
	//nl();
	s.set_ID(prompt_get("Enter student ID: "));
	//nl();

	cout << "Enter student birth date (yyyy mm dd): ";
	Date bDate(get_int(), get_int(), get_int());
	s.set_Date(bDate);
	return s;
			
}


void enroll_to_course(string sid, string cid,vector<Student>& slist,vector<Course>& clist){
	
	Student* s = find_student(sid, slist);
	Course* c = find_course(cid, clist);
	
	s->add_course(c, 0);
	c->enroll(s);	
}


string withdraw_from_course(string sid, string cid,vector<Student>& slist,vector<Course>& clist){
	
	//cout << "Enroll student to course not yet implemented" << endl;	

	Student* s = find_student(sid, slist);
	Course* c = find_course(cid, clist);
	
	if (s == NULL)
	{
		return "A student with that ID is not in the database";
	}
	else if (c == NULL)
	{
		return "That Course is not in the database!";
	}
	else
	{
		
		//this bit checks whether or not a students whole info changes. Because Course::withdraw is required to return void this method has to be used
		string pre_info = s->student_info();
		
		c->withdraw(sid);
		
		string post_info = s->student_info();
		
		if (pre_info != post_info)
		{
			return "Student removed from course!";				
		}
		else
		{
			return "Unable to remove student from course";				
		}
			
	}	
	
	
}

string update_grade(string sid, string cid, double grade, vector<Student>& slist,vector<Course>& clist){
	Student* s = find_student(sid, slist);
	Course* c = find_course(cid, clist);
	
	if (s == NULL)
	{
		return "A student with that ID is not in the database";
	}
	else if (c == NULL)
	{
		return "That Course is not in the database!";
	}
	else
	{	
		
		//this bit checks whether or not a students grade changes. Because Student::modify_grade is required to return void this method has to be used
		string pre_info = s->student_info();
		
		s->modify_grade(c, grade);
		
		string post_info = s->student_info();
		
		if (pre_info != post_info)
		{
			return "Grade updated!";				
		}
		else
		{
			return "Student is not enrolled in that course!";				
		}
	}
}


/*
bool save(vector<Student>& slist,vector<Course>& clist)
{
	//ofstream out_stream("courses.txt);

	//if (out_stream.fail())
	//{
	return false;
	//}
	//else
	//{
	//	for (unsigned int i = 0; i < clist.size(); i++)
		//{
		
		//	outfile << clist[i].

			
		//}
		


}

*/





void prompt(string prompt){
	cout << prompt;
}

string prompt_get(string prompt){
	cout << prompt;
	return get_input();
}

double prompt_get_double (string prompt){
	cout << prompt;
	return get_double();
}



string get_input(){
	string in;
	cin >> in;
	return in;
}

int get_int(){
	int in;
	cin >> in;
	return in;
}


double get_double(){
	double d;
	cin >> d;
	return d;
}



void nl(){
	cout << endl;
}



int main_menu()
{
	cout << "Main Menu "<< endl << endl;
	cout << "1. Load students list file" << endl;
	cout << "2. Load courses file" << endl;
	cout << "3. Enroll from file" << endl;
	cout << "4. Show course details" << endl;
	cout << "5. Show Student details" << endl;
	cout << "6. Create course" << endl;
	cout << "7. Add student to databaase" << endl;
	cout << "8. Enroll student to course" << endl;
	cout << "9. Withdraw student from course" << endl;
	cout << "10. Update student grade" << endl;
	cout << "11. Save changes" << endl;
	cout << "12. Exit" << endl << endl;
	
	int selection;
	
	cin >> selection;
	
	if (cin.fail())
	{
		buffer_cleaner();
		return -1;
	}
	
	return selection;	
}


