#include <iostream>

using namespace std;



class Human
{
private:
    string name;
    string vozrast;

public:

    Human()
    {
        this->name = "имя";
        this->vozrast = "Сколько лет";
    }


    void say()
    {
        cout << this->name << " Скажите: " << endl;
    }

    virtual void saySpecPhrase(Human* Human)
    {
        Human->say();
    }

    void whatisyourname()
    {
        cout << "Меня зовут " << this->name << "." << endl;
    }

    void whatisyourvozrast()
    {

        cout << "На данный момент " << this->name << " в возрасте " << this->vozrast << " лет." << endl;
    }

protected:

    void setName(string name1)
    {
        this->name = name1;
    }

    string getName()
    {
        return this->name;
    }

    void setvozrast(string vozrast1)
    {
        this->vozrast = vozrast1;
    }

    string getdateofbirth()
    {
        return this->vozrast;
    }

};



class Employee : public Human
{
private:
    string nameofcar;

public:



    void say()
    {
        cout << this->getName() << "Скажите: '...'" << endl;
    }

    void whatisyourwork()
    {
        cout  << this->getName() << " ездит на " << this->nameofcar << "." << endl;
    }

protected:

    void setnameofcar(std::string nameofcar1)
    {
        this->nameofcar = nameofcar1;
    }

    string getnameofcar()
    {
        return this->nameofcar;
    }

};

class Student : public Human
{
private:
    string nameofunivestity;

public:

    void say()
    {
        cout << this->getName() << " Скажи: 'я студент'" << endl;
    }


    void whatisyouruniversity()
    {
        cout << "Студент " << this->getName() << " обучается в " << this->nameofunivestity << "." << endl;
    }

protected:

    void setnameofunivestity(std::string nameofunivestity1)
    {
        this->nameofunivestity = nameofunivestity1;
    }

    string getnameofunivestity()
    {
        return this->nameofunivestity;
    }

};

class vladelechavto : public Employee
{
private:
    unsigned short int Srokvladenia;

public:

    vladelechavto(string name1,string vozrast1,string nameofcar1, unsigned short int Srokvladenia1)
    {
        this->setName(name1);
        this->setvozrast(vozrast1);
        this->setnameofcar(nameofcar1);
        this->setSrokvladenia(Srokvladenia1);
    };

    void say()
    {
        cout << this->getName() << " Скажите: 'Она классная?'" << endl;
    }

    void whatsrokraboty()
    {
        cout << "Машина находится у " << this->getName() << "а " << this->Srokvladenia << " лет." << endl;
    }

protected:

    void setSrokvladenia(unsigned short int Srokvladenia1)
    {
        this->Srokvladenia = Srokvladenia1;
    }

    unsigned short int getSrokvladenia()
    {
        return this->Srokvladenia;
    }

};


class Calculator
{
private:

public:

    void summint(int a, int b)
    {
        cout << "сумма чисел " << a << " + " << b << " = " << a + b << "." << endl;
    }

protected:



};


class MathFacStudent : public Student, public Calculator
{
private:

public:
    bool isOtlichnoForMathematicalAnalysis;
    MathFacStudent(std::string name1, std::string vozrast1, std::string nameofunivestity1, bool isOtlichnoForMathematicalAnalysis1)
    {
        this->setName(name1);
        this->setvozrast(vozrast1);
        this->setnameofunivestity(nameofunivestity1);
        this->setisOtlichnoForMathematicalAnalysis(isOtlichnoForMathematicalAnalysis1);
    };



    void say()
    {
        cout << this->getName() << " Скажи: 'математика'" << endl;
    }
    void MathematicalNot()
    {
        if (this->isOtlichnoForMathematicalAnalysis == true)
        {
            cout << "Студент " << this->getName() << " имеет оценку хорошо ." << endl;
        }
        else
        {
            cout << "Студент " << this->getName() << " вообразил себе оценку хорошо но имеет удовлетворительно." << endl;

        }
    }

protected:

    void setisOtlichnoForMathematicalAnalysis(bool isOtlichnoForMathematicalAnalysis)
    {
        this->isOtlichnoForMathematicalAnalysis = isOtlichnoForMathematicalAnalysis;
    }

    bool getisOtlichnoForMathematicalAnalysis()
    {
        return this->isOtlichnoForMathematicalAnalysis;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Human* DefaultMan1 = new Human();
    Human* DefaultMan2 = new Human();

    DefaultMan1->whatisyourname();
    DefaultMan1->whatisyourvozrast();
    cout << endl;
    DefaultMan2->whatisyourname();
    DefaultMan2->whatisyourvozrast();
    cout << endl;


    vladelechavto* Иван = new vladelechavto("Иван", "22", "Nissan Lift", 3);
    MathFacStudent* Петя = new MathFacStudent("Петя", "17", "МГУ", false);
    MathFacStudent* Вова = new MathFacStudent("Вова", "19", "Двфу", true);

    Иван->whatisyourname();
    Иван->whatisyourvozrast();
    Иван->say();
    Иван->whatisyourwork();
    Иван->whatsrokraboty();
    cout << endl;

    Петя->whatisyourname();
    Петя->whatisyourvozrast();
    Петя->say();
    Петя->whatisyouruniversity();
    Петя->MathematicalNot();
    Петя->summint(3234, 212434);
    cout << endl;

    Вова->whatisyourname();
    Вова->whatisyourvozrast();
    Вова->say();
    Вова->whatisyouruniversity();
    Вова->MathematicalNot();
    Вова->summint(14214, 1314);
    cout << endl;

    return 0;
}