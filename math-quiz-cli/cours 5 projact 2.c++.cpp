#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numberquestion(string name) {
    int number;
    do {
        cout << name << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

int randm(int from, int to) {
    int randm = rand() % (to - from + 1) + from;
    return randm;
}

enum pass_andfiled { pass = 1, filed = 2 };
enum typequestion { easy = 1, midal = 2, hard = 3, mixs = 4 };
enum typeprocess { add = 1, sub = 2, mul = 3, divtion = 4, mix = 5 };

struct stquiz {
    typequestion question;
    typeprocess process;
};

short ask_type_question() {
    int number;
    cout << "Choose question type [1] easy, [2] midal, [3] hard, [4] mix: ";
    cin >> number;
    return (typequestion)number;
}

short ask_type_process() {
    int number;
    cout << "Choose operation [1] +, [2] -, [3] *, [4] /, [5] %, [6] mix: ";
    cin >> number;
    return (typeprocess)number;
}
void print(int number1, int number2)
{
    //int fo= number3<number1
    if (number1 <= .5)
        cout << "yuo are pass" << endl;
    else
    {
        cout << "yup\o are filed" << endl;
    }
    cout << "the courct is :" << number1 << endl;
    cout << "the roun is :" << number2 << endl;

}
void add_sub_mud(typeprocess process, int from, int to) {
    int number1 = 0, number2 = 0;
    int sum = 0;
    int input_user;
    int pass = 0, fil = 0;

    switch (process) {
    case typeprocess::add:
        number1 = randm(from, to);
        number2 = randm(from, to);
        sum = number1 + number2;
        cout << number1 << "\n\t+" << "\n" << number2 << "\n_______" << endl;
        break;

    case typeprocess::sub:
        number1 = randm(from, to);
        number2 = randm(from, to);
        sum = number1 - number2;
        cout << number1 << "\n\t-" << "\n" << number2 << "\n_______" << endl;
        break;

    case typeprocess::mul:
        number1 = randm(from, to);
        number2 = randm(from, to);
        sum = number1 * number2;
        cout << number1 << "\n\tx" << "\n" << number2 << "\n_______" << endl;
        break;

    case typeprocess::divtion:
        number1 = randm(from, to);
        do {
            number2 = randm(from, to);
        } while (number2 == 0);
        sum = number1 / number2;
        cout << number1 << "\n\t/" << "\n" << number2 << "\n_______" << endl;
        break;

    case typeprocess::mix:
        number1 = randm(from, to);
        number2 = randm(from, to);
        sum = number1 - number2;
        cout << number1 << "\n\t-" << "\n" << number2 << "\n_______" << endl;
        break;

    default:
        break;
    }

    cin >> input_user;
    if (input_user == sum)
    {
        pass++;
        cout << "Hi, right answer!" << endl;
    }
    else
    {
        cout << "The result is: " << sum << endl;
        fil++;
    }
    print(pass, fil);

}

void questions(typequestion ques, typeprocess operation) {
    switch (ques) {
    case typequestion::easy:
        add_sub_mud(operation, 1, 10);
        break;
    case typequestion::midal:
        add_sub_mud(operation, 40, 80);
        break;
    case typequestion::hard:
        add_sub_mud(operation, 100, 200);
        break;
    case typequestion::mixs:
        cout << "Coming soon..." << endl;
        break;
    default:
        break;
    }
}

void start() {
    typequestion type;
    typeprocess operation;

    type = (typequestion)ask_type_question();
    operation = (typeprocess)ask_type_process();

    questions(type, operation);
}



void ask_number_qustion()
{
    char choces;
    do
    {
        int counter = 0;
        int  number = numberquestion("How many need qustion");
        for (int i = number; i > 0; i--)
        {
            counter++;
            cout << "\t-----qustion[" << counter << "]" << endl;

            start();
        }
        cout << "you are need exzam agin  Y or no " << endl;
        cin >>choces;
    } while (choces=='y'|| choces=='Y');

    
}

int main() {
    srand((unsigned)time(NULL));
   // start();
    ask_number_qustion();
}
