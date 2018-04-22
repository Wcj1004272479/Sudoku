#include "stdafx.h"
#include "InputHandler.h"
#include "FinalMaker.h"
#include "SudokuSolver.h"

void InputHandler::check(int argc, char ** argv){
	if (argc == 3) {
		string parameter1 = argv[1];
		string parameter2 = argv[2];
		if (parameter1 == "-c") {
			int n = isNum(parameter2);
			if (n <= 0 || n > 1000000)
				cout << "������0<n<=1000000��" << endl;
			else {
				FianlMaker fm;
				fm.make(n);
				cout << "������" + parameter2 + "����������" << endl;
			}
		}
		else if (parameter1 == "-s") {
			ifstream in(parameter2);
			if (!in.is_open()) {
				cout << parameter2 + "�޷��򿪣�" << endl;
				return;
			}
			char ch[81];
			char c;
			int count = 0;
			SudokuSolver ss;
			FILE* out = fopen("sudoku.txt", "wt");
			while (in.get(c)) {	//in >> c ����Կհ׻س���
				if (isdigit(c)) {
					ch[count++] = c;
				}
				if (count == 81) {
					count = 0;
					fputs(ss.solve(ch),out);
				}
			}
			in.close();
			if (count != 0) {
				char *str = "���ڴ����ʽ��";
				fputs(str, out);
				cout << str << endl;
			}
			else
				cout << "�ѽ��" + parameter2 + "�������" << endl;
			fclose(out);
		}
		else {
			cout << "��������" << endl;
		}
	}
	else {
		cout << "��������" << endl;
	}
	return;
}

int InputHandler::isNum(const string & s){
	size_t size = s.size();
	if (size > 7)
		return 0;
	for (size_t i = 0; i < size; i++) {
		int ascii = int(s[i]);
		if (ascii >= 48 && ascii <= 57)
			continue;
		else
			return 0;
	}
	return stoi(s);
}
