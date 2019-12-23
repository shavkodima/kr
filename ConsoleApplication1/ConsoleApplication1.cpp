#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Users {
	string login;
	string password;
	int role = 0;
	string f, i, o;
	int tabelNumber;
};
const int SIZE = 100;
const string FILES_USERS = "account.txt";
void addUsersArray(Users* array_users, int& number_users);
void writeEndFileUsers(Users new_users);
void displayUsers(Users* array_users, int& number_users);

int main()
{
	setlocale(LC_ALL, "rus");
	Users array_users[SIZE];
	int number_users = 0;

	addUsersArray(array_users, number_users);
	displayUsers(array_users, number_users);
}



void addUsersArray(Users* array_users, int& number_users) {
	string newLogin, newPassword, repeatPassword, newF, newI, newO;
	int role = 0;
	number_users++;
	cout << "Введите логин" << endl;

	cin >> newLogin;
	array_users[number_users - 1].login = newLogin;
	bool flag = true;

	while (flag) {
		cout << "Введите пароль" << endl;
		cin >> newPassword;
		cout << "Повторите пароль" << endl;
		cin >> repeatPassword;
		if (newPassword == repeatPassword) {
			array_users[number_users - 1].password = newPassword;
			flag = false;
		}
		else {
			cout << "Пароли не совпадают" << endl;
			cout << "Повторите еще раз" << endl;
		}

	}

	cout << "Укажите тип учетной записи, где 1-Администратор, 0-Пользователь" << endl;

	cin >> role;
	while (role > 1 || role < 0) {
		cout << "Указан неверный тип,  1-Администратор, 0-Пользователь" << endl;
		cout << "Повторите еще раз" << endl;
		cin >> role;
	}
	array_users[number_users - 1].role = role;

	cout << "Введите фамилию" << endl;
	cin >> newF;
	array_users[number_users - 1].f = newF;

	cout << "Введите Имя" << endl;
	cin >> newI;
	array_users[number_users - 1].i = newI;

	cout << "Введите Отчество" << endl;
	cin >> newO;
	array_users[number_users - 1].o = newO;


	array_users[number_users - 1].tabelNumber = number_users;

	writeEndFileUsers(array_users[number_users - 1]);
}
void readFileUsers(Users* array_users, int& number_users) {

}
void writeEndFileUsers(Users new_users) {

	ofstream fout(FILES_USERS, ios::app);
	if (!fout.is_open()) cout << "файл не найден" << endl;
	fout << new_users.login << " " <<
		new_users.password << " " <<
		new_users.role << " " <<
		new_users.f << " " <<
		new_users.i << " " <<
		new_users.o << " " <<
		new_users.tabelNumber << endl;

	fout.close();
}

void displayUsers(Users* array_users, int& number_users) {

	for (int i = 0; i < number_users; i++) {
		cout << array_users[i].login << " " <<
			array_users[i].password << " " <<
			array_users[i].role << " " <<
			array_users[i].f << " " <<
			array_users[i].i << " " <<
			array_users[i].o << " " <<
			array_users[i].tabelNumber << endl;
	}
}