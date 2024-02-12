#include <iostream>
#include <string>

using namespace std;

class node {
  public:
    string key;

    string firstname, middlename, lastname;

    int subject1, subject2, subject3, subject4, subject5;
		int totalMarks, avarageMarks;

		char grade;
  
    node* next;
    node* previous;

		node() {
			key = "Empty";

			firstname = "Empty";
			middlename = "Empty";
			lastname = "Empty";

			totalMarks = 0;
			avarageMarks = 0;
			grade = 'Z';

			next = nullptr;
			previous = nullptr;
		}

    node(
      string k,
      string fn,
      string mn,
      string ln,

      int s1,
			int s2,
			int s3,
			int s4,
			int s5,
            
			int tm,
			int am,
			char gr
		) {
			key = k;

			firstname = fn;
			middlename = mn;
			lastname = ln;

			subject1 = s1;
			subject2 = s2;
			subject3 = s3;
			subject4 = s4;
			subject5 = s5;

			totalMarks = tm;
			avarageMarks = am;
			grade = gr;
    }
};

class StudentData
{
	public:
		node* head;

		StudentData() {
			head = nullptr;
		}

		StudentData(node* n){
			head = n;
    }

		// Student existing using Registration Number. Non-formal.
		node* studentExistsChecker(string k) {
			node* temp = nullptr;
			node* ptr = head;

			while (ptr != nullptr) {
				if (ptr -> key == k) {
					temp = ptr;
				}
				ptr = ptr -> next;
			}
			return temp;
    }

		// Student exist using Registration Number. Formal. Used to get option 1 of main.
		void studentExists(node* n) {
			if (studentExistsChecker(n -> key) != nullptr) {
				cout << "Details and marks of student with Registration Number: " << n -> key << " is already in the system. You can select option 4 to edit already existing student details." << endl;
			} else {
				cout << "Details and marks of student with Registration Number: " << n -> key << " is not in the system. You can select option 2 to add the student details" << endl;
			}
		}

		// Add student to the list.
		void addStudent(node* n) {
      if (studentExistsChecker(n -> key) != nullptr) {
				cout << "Student with Registration Number: " << n -> key << " already exists in the system. Details not added." << endl;
				cout << "Please re-check the Registration Number and try again or choose option 4 to edit already existing student details." << endl;
      } else {
				if (head == nullptr) {
					head = n;
					cout << "Details and marks of student with Registration Number: " << n -> key << " has been successfully added to the system." << endl;
				} else {
					node* ptr = head;
					while (ptr -> next != nullptr) {
						ptr = ptr -> next;
					}
					ptr -> next = n;
					n -> previous = ptr;
					cout << "Details and marks of student with Registration Number: " << n -> key << " has been successfully added to the system." << endl;
				}
      }
    }

		// Delete a student record.
		void deleteStudentRecord (string k) {
			node* ptr = studentExistsChecker(k);
			if (ptr == nullptr) {
				cout << "Student with Registration Number: " << k << " doesn't exists in the system. Cannot be deleted." << endl;
				cout << "Please re-check the Registration Number and try again" << endl;
			} else {
				if (head -> key == k) {
					head = head -> next;
					cout << "Student details with Registration Number: " << k << "has been deleted successfully" << endl;
				} else {
					node* nextNode = ptr -> next;
					node* prevNode = ptr -> previous;
					if (nextNode == nullptr) {
						prevNode -> next = nullptr;
						cout << "Student details with Registration Number: " << k << "has been deleted successfully" << endl;
					} else {
						prevNode -> next = nextNode;
						nextNode -> previous = prevNode;
						cout << "Student details with Registration Number: " << k << "has been deleted successfully" << endl;
					}
        }
      }
    }

		// Update or change student details.
		void updateStudentDetails (node* n) {
			int tm, am, s1, s2, s3, s4, s5;
			tm = 0;
			am = 0;
			s1 = 0;
			s2 = 0;
			s3 = 0;
			s4 = 0;
			s5 = 0;

			string fn, mn, ln;
			char gr;
			node* ptr = studentExistsChecker(n -> key);
			if (ptr != nullptr) {
				ptr -> firstname = fn;
				ptr -> middlename = mn;
				ptr -> lastname = ln;
				ptr -> subject1 = s1;
				ptr -> subject2 = s2;
				ptr -> subject3 = s3;
				ptr -> subject4 = s4;
				ptr -> subject5 = s5;

				tm = s1 + s2 + s3 + s4 + s5;
        ptr -> totalMarks = tm;

				am = tm / 5;
				ptr -> avarageMarks = am;

				if (am >= 70) {
					gr = 'A';
				} else if (am >= 60) {
					gr = 'B';
				} else if (am >= 50) {
					gr = 'C';
				} else if (am >= 40){
					gr = 'D';
        } else {
					gr = 'E';
        }
				ptr -> grade = gr;

				cout << "Student details with Registration Number: " << n -> key << " changed successfully." << endl;
      } else {
				cout << "Student details with Registration Number: " << n -> key << " doesn't exist in the system." << endl;
				cout << "Please check the Registration Number or choose 2 to add the student details to the system." << endl;
      }
    }

		// Give list of all students in the recored.
		void printAllStudents() {
			node* temp = head;
			clearScreen();
			cout << endl << "LIST OF ALL STUDENTS. NOT RANKED.";
			while (temp != nullptr) {
				cout << endl;
				cout << "NAME: " << temp ->firstname << " " << temp -> middlename << " " << temp -> lastname << endl;
				cout << "REGISTRATION NUMBER: " << temp -> key << endl;
				cout << "SUBJECTS" << endl;
				cout << "\t Subject 1: " << temp -> subject1 << endl;
				cout << "\t Subject 2: " << temp -> subject2 << endl;
				cout << "\t Subject 3: " << temp -> subject3 << endl;
				cout << "\t Subject 4: " << temp -> subject4 << endl;
        cout << "\t Subject 5: " << temp -> subject5 << endl;
        cout << "TOTAL MARKS: " << temp -> totalMarks << endl;
        cout << "AVARAGE MARKS: " << temp -> avarageMarks << endl;
        cout << "GRADE: " << temp -> grade << endl;
        cout << endl;
        temp = temp -> next;
      }
    }

    // Display top 5 students.
    void dispayTop5() {
      if (head == nullptr) {
				cout << "No student in the system. Can't display top 5." << endl;
				cout << "You can press option 2 to add student details to the system." << endl;
      } else if (head -> next == nullptr) {
				node* temp = head;
				clearScreen();
				cout << endl << "LIST OF TOP 5 STUDENTS. RANKED.";
				while (temp != nullptr) {
					cout << endl;
					cout << "NAME: " << temp ->firstname << " " << temp -> middlename << " " << temp -> lastname << endl;
					cout << "REGISTRATION NUMBER: " << temp -> key << endl;
					cout << "SUBJECTS" << endl;
					cout << "\t Subject 1: " << temp -> subject1 << endl;
					cout << "\t Subject 2: " << temp -> subject2 << endl;
					cout << "\t Subject 3: " << temp -> subject3 << endl;
					cout << "\t Subject 4: " << temp -> subject4 << endl;
					cout << "\t Subject 5: " << temp -> subject5 << endl;
					cout << "TOTAL MARKS: " << temp -> totalMarks << endl;
					cout << "AVARAGE MARKS: " << temp -> avarageMarks << endl;
					cout << "GRADE: " << temp -> grade << endl;
					cout << endl;
					temp = temp -> next;
        }
      } else {
				node* current = head;
				node* sorted = nullptr;
				while (current != nullptr) {
					node* nextNode = current -> next;
					current -> previous = current -> next = nullptr;
					if (sorted == nullptr || current -> totalMarks >= sorted -> totalMarks) {
						current -> next = sorted;
						if (sorted != nullptr) {
							sorted -> previous = current;
						}
						sorted = current;
					} else {
						node* temp = sorted;
						while (temp -> next != nullptr && temp -> next -> totalMarks < current -> totalMarks) {
							temp = temp -> next;
						}
						current -> next = temp -> next;
						if (temp -> next != nullptr) {
							temp -> next -> previous = current;
						}
						temp -> next = current;
						current -> previous = temp;
          }
          current = nextNode;
        }
				head = sorted;

				node* temp = head;
				clearScreen();
				cout << endl << "LIST OF TOP 5 STUDENTS. RANKED.";
				while (temp != nullptr) {
					cout << endl;
					cout << "NAME: " << temp ->firstname << " " << temp -> middlename << " " << temp -> lastname << endl;
					cout << "REGISTRATION NUMBER: " << temp -> key << endl;
					cout << "SUBJECTS" << endl;
					cout << "\t Subject 1: " << temp -> subject1 << endl;
					cout << "\t Subject 2: " << temp -> subject2 << endl;
					cout << "\t Subject 3: " << temp -> subject3 << endl;
					cout << "\t Subject 4: " << temp -> subject4 << endl;
					cout << "\t Subject 5: " << temp -> subject5 << endl;
					cout << "TOTAL MARKS: " << temp -> totalMarks << endl;
					cout << "AVARAGE MARKS: " << temp -> avarageMarks << endl;
					cout << "GRADE: " << temp -> grade << endl;
					cout << endl;
					temp = temp -> next;
        }
      }
    }

		void clearScreen () {
			// uncomment based on your OS
			// clear console on linux and mac
			//system("clear");
			//clear console on windows
			//system("cls");
		}
};

int main() {
	StudentData object;
	int option;

	string key_s;

	string firstname_s;
	string middlename_s;
	string lastname_s;

	int subject1_s;
	int subject2_s;
	int subject3_s;
	int subject4_s;
	int subject5_s;

	int totalMarks_s;
	int avarageMarks_s;
	char grade_s;

	do {
		cout << endl;
		cout << "WELCOME TO THE STUDENT RECORD MANAGMENT" << endl;
		cout << endl;
		cout << "Please select an option. Press [0] to exit." << endl;
		cout << "[1].\t Search or Check if a particular student is already in the system." << endl;
		cout << "[2].\t Add new student details and marks to the system." << endl;
		cout << "[3].\t Delete already existing student record." << endl;
		cout << "[4].\t Modify already existing student record." << endl;
		cout << "[5].\t Display list of student in the system. Not in order." << endl;
		cout << "[6].\t Display top 5 students." << endl;
		cout << "[7].\t Clear Screen." << endl;

		cin >> option;
		node* n1 = new node();

    switch (option) {
			case 0:
				break;

			case 1:
				cout << "Enter Registration Number of the student you want to check" << endl;
				cin >> key_s;
				n1 -> key = key_s;
				object.studentExists(n1);
				break;

			case 2:
				cout << "Enter Registration Number of the student: ";
				cin >> key_s;
				n1 -> key = key_s;

				cout << "\nEnter first name of the student: ";
				cin >> firstname_s;
				n1 -> firstname = firstname_s;

				cout << "\nEnter middle name of the student: ";
				cin >> middlename_s;
				n1 -> middlename = middlename_s;

				cout << "\nEnter last name of the student: ";
				cin >> lastname_s;
				n1 -> lastname = lastname_s;

				cout << "\nEnter subject 1 marks: ";
				cin >> subject1_s;
				n1 -> subject1 = subject1_s;

				cout << "\nEnter subject 2 marks: ";
				cin >> subject2_s;
				n1 -> subject2 = subject2_s;

				cout << "\nEnter subject 3 marks: ";
				cin >> subject3_s;
				n1 -> subject3 = subject3_s;

				cout << "\nEnter subject 4 marks: ";
				cin >> subject4_s;
				n1 -> subject4 = subject4_s;

				cout << "\nEnter subject 5 marks: ";
				cin >> subject5_s;
				n1 -> subject5 = subject5_s;

				totalMarks_s = subject1_s + subject2_s + subject3_s + subject4_s + subject5_s;
				n1 -> totalMarks = totalMarks_s;

				avarageMarks_s = totalMarks_s / 11;
				n1 -> avarageMarks = avarageMarks_s;

				if (avarageMarks_s >= 70){
					grade_s = 'A';
				} else if (avarageMarks_s >= 60) {
					grade_s = 'B';
				} else if (avarageMarks_s >= 50) {
					grade_s = 'C';
				} else if (avarageMarks_s >= 40) {
					grade_s = 'D';
        } else {
          grade_s = 'E';
        }
				n1 -> grade = grade_s;

				cout << endl;
				object.addStudent(n1);
				break;

			case 3:
				cout << "Enter the Registration Number of the student you want to delete his/her details" << endl;
				cin >> key_s;
				object.deleteStudentRecord(key_s);
				break;

      case 4:
				cout << "Enter Registration Number of the student: ";
				cin >> key_s;
				n1 -> key = key_s;

				cout << "\nEnter first name of the student: ";
				cin >> firstname_s;
				n1 -> firstname = firstname_s;

				cout << "\nEnter middle name of the student: ";
				cin >> middlename_s;
				n1 -> middlename = middlename_s;

				cout << "\nEnter last name of the student: ";
				cin >> lastname_s;
				n1 -> lastname = lastname_s;

				cout << "\nEnter subject 1 marks: ";
				cin >> subject1_s;
				n1 -> subject1 = subject1_s;

				cout << "\nEnter subject 2 marks: ";
				cin >> subject2_s;
				n1 -> subject2 = subject2_s;

				cout << "\nEnter subject 3 marks: ";
				cin >> subject3_s;
				n1 -> subject3 = subject3_s;

				cout << "\nEnter subject 4 marks: ";
				cin >> subject4_s;
				n1 -> subject4 = subject4_s;

				cout << "\nEnter subject 5 marks: ";
				cin >> subject5_s;
				n1 -> subject5 = subject5_s;

				object.updateStudentDetails(n1);
				break;

			case 5:
				object.printAllStudents();
				break;

			case 6:
				object.dispayTop5();
				break;

			case 7:
				object.clearScreen();
				break;

			default:
				cout << "Please Select a Proper Option" << endl;
				break;
    }
  }
	while (option != 0);
	return 0;
}
