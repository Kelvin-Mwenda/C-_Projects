#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class Student {
private:
    int regno, age;
    string name;
public:
    Student(string stdname, int stdregno, int stdage) {
        name = stdname;
        regno = stdregno;
        age = stdage;
    }
    void setregno(int stdregno) {
        regno = stdregno;
    }
    int getregno() {
        return regno;
    }
    void setage(int stdage) {
        age = stdage;
    }
    int getage() {
        return age;
    }
    void setname(string stdname) {
        name = stdname;
    }
    string getname() {
        return name;
    }
    void displaystudent() {
       std::cout << "Name:" << name << endl;
        std::cout << "Registration number:" << regno << endl;
        std::cout << "Age:" << age << endl;
    }
};

//updates students record
void updatestudent(vector<Student>& students)
{
    bool found = false;
    do {
        int regno1;
        std::cout << "\tEnter registration number:";
        std::cin >> regno1;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getregno() == regno1) {
                found = true;
                break;
            }
        }
    } while (found == false);

    for (int i = 0; i < students.size(); i++) {
        if (found == true)
        {
            std::cout << "\t----------Record found----------" << endl;
            std::cout << "\t----------Record Update----------\n";
            std::cout << "\t1. Update Name\n\t2.Update Registration number\n\t3.Update Age\n\tEnter your choice:";
            int choice;
            std::cin >> choice;
            string name1;
            switch (choice)
            {
            case 1: {
                std::cout << "\tEnter new name:";
                std::cin.ignore();
                std::getline(std::cin, name1);
                students[i].setname(name1);
                std::cout << "\tNew Name is " << students[i].getname() << endl;
                return;
            }
                break;
            case 2: {
                int regno2;
                std::cout << "\tEnter newregistration number:";
                std::cin >> regno2;
                    for (int j = 0; j < students.size(); j++)
                    {
                        if (students[j].getregno() == regno2)
                        {
                            std::cout << "\tSorry, this registration number is already owned..." << endl;
                            return;
                        }
                    }
                students[i].setregno(regno2);
                std::cout << "\tNew Registration Number  is  " << students[i].getregno()<<endl;
                return;
            }
                  break;
            case 3: {
                int age1;
                std::cout << "\tEnter New Age:";
                std::cin >> age1;
                students[i].setage(age1);
                std::cout << "\tNew age is " << students[i].getage();
                return;
            } break;
            default:
                std::cout << "\tInvalid choice\n";
                break;
            }
        }
    }
}

//searches for a student
void searchstudent(vector<Student> &students){
    std::cout << "\tEnter registration number:";
    int regno;
    cin >> regno;
    for (int i = 0; i < students.size(); i++) 
    {
        if (students[i].getregno() == regno) {
            students[i].displaystudent();
            cout << endl;
            break;
        }
        else {
            std::cout << "\tThis record does not exist" << endl;
        }
    }
}

//displays list of all students
void displayallstudents(vector<Student> &students) {
    if (students.empty())
    {
        cout << "\t\tNo student found!" << endl;
    }
    else
    {
        for (int i = 0; i < students.size(); i++)
        {
            students[i].displaystudent();
            cout << endl;
        }
    }
}

//A function to add a new student  
void addnewstudent(vector<Student> &students)
{
    int regno3, age;
    string name;
    cout << "\tEnter student's registration number:";
    cin >> regno3;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getregno() == regno3) {
            cout << "\tSorry,the student already exist..." << endl;
            return;
        }
    }
    cout << "\tEnter name:";
    cin >> name;
    cout << "\tEnter student's age:";
    cin >> age;

    Student newstudent(name, regno3, age);
    students.push_back(newstudent);
    cout << "\tStudent added successfully...\n";
}

//deletes students
void deletestudent(vector<Student> &students){
    string name;
    cout<<"\t------DELETING A STUDENT-------\n";
    cout<<"\tEnter name:";
    cin>>name;
    for(int i=0;i<students.size();i++){
        if(name==students[i].getname()){
            students.erase((students.begin()));
            cout<<"\t"<<students[i].getname()<<" removed successfully...!\n";
            return;
        }
    }
    cout<<"\tThis student does not exist...!\n";
}

int main() {
    vector<Student> students;
    char choice;
    do {
        system("cls");
        int op;
        cout << "\t-----------------------------------------------------\n\t\t\tStudent Management System\n\t-----------------------------------------------------\n";
        cout << "\t\t1. Add New Student\n\t\t2. Display All Students\n\t\t3. Search Student\n\t\t4. Update Student\n\t\t5. Delete Student\n\t\t6. exit" << endl;
        cout << "\t\tEnter your choice:";
        cin >> op;

        switch (op) 
        {
        case 1:addnewstudent(students);
        break;
        case 2:displayallstudents(students);
        break;
        case 3:searchstudent(students);
        break;
        case 4:updatestudent(students);
        break;
        case 5:deletestudent(students);
        break;
        case 6:exit(1);
        break;
        default:cout << "Invalid choice!!" << endl;
        break;
        }
        std::cout << "\t\tDo you want to  continue?[y/n]:";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

return 0;
}