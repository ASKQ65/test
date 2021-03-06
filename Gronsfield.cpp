// Gronsfield.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <limits>

using namespace std;




//void new_file_coding() {
	string user_key, user_text;
	ofstream user_file;
	user_file.open("user_file.txt");
	cout << "Your key: \n";
	getline(cin, user_key);
	for (int i = 0; i < user_key.size() || user_key.empty(); i++) { //проверка на тип данных в буфере
		if (!isdigit(user_key[i])) {
			i = -1;
			cout << "Error!\nTry again!\n";
			getline(cin, user_key);
		}
	}
	system("cls");
	cout << "Your text:\n";
	getline(cin, user_text);
	while (user_text.empty()) {
		cout << "Empty input!\nTry again!\n";
		getline(cin, user_text);
	}
	for (int i = user_key.size(), a = 0; i < user_text.size(); i++, a++) {
		user_key += user_key[a];
	}
	for (int i = 0; i < user_text.size(); i++) {
		user_text[i] += (user_key[i] - '0');
	}
	user_file << user_text;
	user_file.close();
	cout << "File successfully coded!\nEnter any key...\n";
	cin.get();
	system("cls");
}

void open_file_decode() {
	ifstream coded_file;
	coded_file.open("user_file.txt");
	string decode_key, decode_text;
	getline(coded_file, decode_text);
	cout << "Your key:\n";
	getline(cin, decode_key);
	for (int i = 0; decode_key[i] != '\0' || decode_key.empty(); i++) { //проверка на тип данных в буфере
		if (!isdigit(decode_key[i])) {
			cout << "Error!\nTry again!\n";
			getline(cin, decode_key);
			i = 0;
		}
	}
	for (int i = decode_key.size(), a = 0; i < decode_text.size(); i++, a++) {
		decode_key += decode_key[a];
	}
	for (int i = 0; i < decode_text.size(); i++) {
		decode_text[i] -= (decode_key[i] - '0');
	}
	coded_file.close();
	system("cls");
	cout << "Your text:\n" << decode_text << endl << "Enter any key...\n";
	cin.get();
	system("cls");
}



	