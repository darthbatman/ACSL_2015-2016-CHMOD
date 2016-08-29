//Rishi Masand
//1-22-2016
#include <iostream>
#include <string>
using namespace std;

string octalToBinary(int o) {
	switch (o) {
	case 0:
		return "000";
	case 1:
		return "001";
	case 2:
		return "010";
	case 3:
		return "011";
	case 4:
		return "100";
	case 5:
		return "101";
	case 6:
		return "110";
	case 7:
		return "111";
	default:
		return "";
	}
}

char binaryToOctal(int b) {
	switch (b) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 10:
		return '2';
	case 11:
		return '3';
	case 100:
		return '4';
	case 101:
		return '5';
	case 110:
		return '6';
	case 111:
		return '7';
	default:
		return '0';
	}
}

int main() {

	for (int i = 0; i < 5; i++) {

		if (i < 2) {
			string octal;
			string tempOctalNumber = "";
			string binaryNumber = "";
			getline(cin, octal);
			for (int s1 = 0; s1 < octal.length(); s1++) {
				if (isdigit(octal[s1])) {
					tempOctalNumber += octal[s1];
				}
			}
			for (int s2 = 0; s2 < tempOctalNumber.length(); s2++) {
				int octalNum = tempOctalNumber[s2] - '0';
				binaryNumber += octalToBinary(octalNum) + ' ';
			}
			cout << binaryNumber << "and ";
			for (int s3 = 0; s3 < binaryNumber.length() - 1; s3++) {
				if (binaryNumber[s3] == '1' && (s3 == 0 || s3 == 4 || s3 == 8)) {
					cout << 'r';
				}
				else if (binaryNumber[s3] == '1' && (s3 == 1 || s3 == 5 || s3 == 9)) {
					cout << 'w';
				}
				else if (binaryNumber[s3] == '1' && (s3 == 2 || s3 == 6 || s3 == 10)) {
					cout << 'x';
				}
				else if (binaryNumber[s3] == ' ') {
					cout << ' ';
				}
				else {
					cout << '-';
				}
			}
			cout << endl;
		}
		else if (i < 4) {
			string binary;
			string tempBinaryNumber = "";
			string octalNumber = "";
			string binaryNumber = "";
			getline(cin, binary);
			for (int s1 = 0; s1 < binary.length(); s1++) {
				if (isdigit(binary[s1])) {
					tempBinaryNumber += binary[s1];
				}
			}
			for (int s2 = 0; s2 < tempBinaryNumber.length(); s2++) {
				binaryNumber += tempBinaryNumber[s2];
				if ((s2 + 1) % 3 == 0) {
					octalNumber += binaryToOctal(stoi(binaryNumber));
					binaryNumber = "";
				}
			}
			cout << octalNumber << " and ";
			for (int s3 = 0; s3 < tempBinaryNumber.length(); s3++) {
				if (tempBinaryNumber[s3] == '1' && (s3 == 0 || s3 == 3 || s3 == 6)) {
					cout << 'r';
				}
				else if (tempBinaryNumber[s3] == '1' && (s3 == 1 || s3 == 4 || s3 == 7)) {
					cout << 'w';
				}
				else if (tempBinaryNumber[s3] == '1' && (s3 == 2 || s3 == 5 || s3 == 8)) {
					cout << 'x';
				}
				else if (tempBinaryNumber[s3] == '0') {
					cout << '-';
				}
				if (s3 == 2 || s3 == 5) {
					cout << ' ';
				}
			}
			cout << endl;
		}
		else {
			string rwx;
			getline(cin, rwx);
			string tempBinaryNumber = "";
			string binaryNumber = "";
			string octalNumber = "";
			for (int s1 = 0; s1 < rwx.length(); s1++) {
				if (rwx[s1] == 'r' || rwx[s1] == 'w' || rwx[s1] == 'x') {
					tempBinaryNumber += '1';
				}
				else if (rwx[s1] == '-') {
					tempBinaryNumber += '0';
				}
			}
			for (int s2 = 0; s2 < tempBinaryNumber.length(); s2++) {
				binaryNumber += tempBinaryNumber[s2];
				if ((s2 + 1) % 3 == 0) {
					octalNumber += binaryToOctal(stoi(binaryNumber));
					binaryNumber = "";
				}
			}
			cout << octalNumber << " and ";
			for (int s3 = 0; s3 < tempBinaryNumber.length(); s3++) {
				cout << tempBinaryNumber[s3];
				if (s3 == 2 || s3 == 5) {
					cout << ' ';
				}
			}
		}

	}

	return 0;
}