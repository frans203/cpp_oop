#include <iostream>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0; //anstract function
    //we need to use =0 because it needs a definition
};



class Employee:AbstractEmployee {
private:
    //private by default
    string Company;
    int Age;
protected:
    string Name;
public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;

    }

    void IntroduceYourself() {
        cout << "Name - "<< this->Name << endl;
        cout << "Company - "<< this->Company << endl;
        cout << "Age - "<< this->Age << endl;
        cout << "\n";
    }

    void setName(string name){
        Name = name;
    }

    void setCompany(string company){
        Company = company;
    }

    void setAge(int age){
        if(age >= 18 && age < 99){
            Age = age;
        }else{
            cout << age << " is not a valid age for " << Name << endl;
        }
    }

    string getName(){
        return Name;
    }

    string getCompany(){
        return Company;
    }

    int getAge(){
        return Age;
    }

    void AskForPromotion() {
        if(Age>30){
            cout << Name << " got promoted\n";
        }else{
            cout << Name << " does not get a promotion\n";
        }
    }

    virtual void Work() {
        std::cout << Name << " is checking email, task backlog, perfoming tasks" << endl;
    }


};

class Developer:public Employee {
    private:
        string FavProgrammingLang;
    public:
        void setFavLang(string lang){
            FavProgrammingLang = lang;
        }

        string getFavLang(){
            return FavProgrammingLang;
        }

        Developer(string name, string company, int age, string favLang) : Employee(name, company, age) {
            FavProgrammingLang = favLang;
        }

        void IntroduceYourself() {
            cout << "Name - "<< getName() << endl;
            cout << "Company - "<< this->getCompany() << endl;
            cout << "Age - "<< this->getAge() << endl;
            cout << "Fav Pro Lang - " << this->getFavLang() << endl;
        }

        void fixBug() {
            std::cout<< Name <<" Fixed bug using:" << getFavLang() << std::endl;
        }
        //override
        void Work() override {
            std::cout << Name << " is fixing bugs, delivering tasks, all using " << FavProgrammingLang << endl;
        }


        
};

class Teacher:public Employee {
    private:
    string Subject;
    public:
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
        Subject = subject;
    }
    
    void PrepareLesson() {
        std:cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }

    //override
    void Work() override {
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};

int main () {
    Employee alanTuring = Employee("Alan Turing", "Amazon", 23);
    Employee mark = Employee("Mark", "Amazon 2", 32);
    Developer developer1 = Developer("Turing", "Netflix", 32, "Java");
    Teacher jack = Teacher("Jack Harryson", "CI", 32, "ED3");
    developer1.Work();
    jack.Work();

    Employee *e = &developer1;
    Employee *e2 = &jack;

    e->Work();
    e2->Work();
   
    return 0;
}