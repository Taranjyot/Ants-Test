
#include "stdafx.h"
#include <iostream>

using namespace std;

int test[64][3],n=27,faults[10], faults1[10];
int path[64], path1[64], red[64][3], red1[64][3], rej[64][3], red_no1 = 0, red_no = 0, rej_no = 0, pos,t=0,finalrset[64][3];
float phermone[10];

void initTestCases(int);
void setTestCases();
void selecTestCase();
void selecTestCase1();
void updatePheromone();
int lagestPheromone();
void retRedusedCases(int,int);
void dispOutput(int);
void printRTestCases(int);
void printRJTestCases();
void calRJTestCases();
int calPath();
int calPath1();
void compare();

void printFaults(int);
int main()
{
//Largest of 3 num
	initTestCases(0);
	setTestCases();
	//test Case selection 
	selecTestCase();
	//Display Pheromone Trail
	dispOutput(0);
	//Displaying reduced test cases
	printRTestCases(0);
	//Displaying Rejected test cases 
	calRJTestCases();
	printRJTestCases();
	//Display faults
	printFaults(0);
	
//Lowest of 3 num
	initTestCases(1);
	setTestCases();
	//test Case selection 
	selecTestCase1();
	
	//Display Pheromone Trail
	dispOutput(1);
	//Displaying reduced test cases
	printRTestCases(1);
	//Displaying Rejected test cases 
	calRJTestCases();
	printRJTestCases();
	//Display faults
	printFaults(1);
//compare
	compare();


	cin.get();
	return 0;
}

//Get Final reduced sets by comp low and high red sets 
void compare() {
	int k = 0;
	for (int i = 0; i < red_no; i++) {
		for (int j = 0; j < red_no1; j++) {
			if (red[i][0] == red1[j][0] && red[i][1] == red1[j][1] && red[i][2] == red1[j][2]) {
				finalrset[k][0] = red[i][0];
				finalrset[k][1] = red[i][1];
				finalrset[k][2] = red[i][2];
				k++;
			}
		}
	}
	//k =- 1;
	//printing final reduced sets
	cout << "\n Final Reduced sets are";
	for (int i = 0; i < k; i++) {
		cout << "\n [" << finalrset[i][0]<<"," << finalrset[i][1]<<"," << finalrset[i][1]<<"]";
	}



}



//printing faults 
void printFaults(int check) {


	cout << "Faults"<<" \t " << 1 << " \t "<<2 << " \t "<<3<< " \t "<<4 << " \t "<<5 << " \t "<<6 << " \n \n \n";
	if (check == 0) {
		cout << "     " << " \t ";
		for (int i = 0; i < 6; i++) {
			cout << faults[i] << " \t ";
		}
	}else{
		cout << "     " << " \t ";
		for (int i = 0; i < 6; i++) {
			cout << faults1[i] << " \t ";
		}
	}
}

//Calculating path Largest of three no's
int calPath(int a, int b, int c) {
	
	if (b > c) {
		faults[0]++;
		if (a < b) {
			faults[1]++;
			return 1;
		}else 
			if (a < c) {
				faults[2]++;
				return 1;
			}
	}
	else {
		faults[3]++;
		if (a <= b) {
			faults[4]++;
			return 2;
		}else
			if (a > c){
				faults[5]++;
				return 0;
			}
			else if(c >= a){
				return 2;
			}
	}
	return -1;
}

//Calculating path Smallest of three no's
int calPath1(int a, int b, int c) {
	
	if (b < c) {
		faults1[0]++;
		if (a > b) {
			faults1[1]++;
			return 1;
		}else 
			if (a <= b) {
				faults1[2]++;
				return 0;
			}
	}
	else {
		faults1[3]++;
		if (a >= c) {
			faults1[4]++;
			return 2;
		}else
			if (a < c){
				faults1[5]++;
				return 0;
			}
	}

	return 3;
}



void calRJTestCases() {
	int flagsize = 0;
	for (int i = 0; i<n; i++) {
		int flag = 0;
		for (int j = 0; j<red_no; j++) {
			if (test[i][0] == red[j][0] && test[i][1] == red[j][1] && test[i][2] == red[j][2]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			rej[flagsize][0] = test[i][0];
			rej[flagsize][1] = test[i][1];
			rej[flagsize][2] = test[i][2];
			flagsize++;
			rej_no++;
		}
	}
}

void printRJTestCases() {
	cout << "Rejected cases:" << rej_no << "\n";
	cout << "\n Rejected Test Cases \n";
	for (int j = 0; j < rej_no; j++) {
		cout << "[" << rej[j][0] << "," << rej[j][1] << "," << rej[j][2] << "]\n";
	}
}


void printRTestCases(int check) {
	if (check == 0) {
		cout << "Reduced cases:" << red_no << "\n";
		cout << "\n Reduced Test Cases \n";
		for (int j = 0; j < red_no; j++) {
			cout << "[" << red[j][0] << "," << red[j][1] << "," << red[j][2] << "]\n";
		}
	}
	else {
		cout << "Reduced cases:" << red_no1 << "\n";
		cout << "\n Reduced Test Cases \n";
		for (int j = 0; j < red_no1; j++) {
			cout << "[" << red1[j][0] << "," << red1[j][1] << "," << red1[j][2] << "]\n";
		}
	}
}
	


void dispOutput(int check) {
	if (check == 0) {
		for (int i = 0; i < 6; i++)
		{
			cout << "Phermone trail for " << i << "\t is " << phermone[i] << "\nTest cases which follow this trail are" << "\n";
			for (int j = 0; j<n; j++) {
				if (i == test[j][0] || i == test[j][1] || i == test[j][2]) {
					cout << "[" << test[j][0] << "," << test[j][1] << "," << test[j][2] << "]  Path:" << path[j] << "\n";
				}
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++)
		{
			cout << "Phermone trail for " << i << "\t is " << phermone[i] << "\nTest cases which follow this trail are" << "\n";
			for (int j = 0; j<n; j++) {
				if (i == test[j][0] || i == test[j][1] || i == test[j][2]) {
					cout << "[" << test[j][0] << "," << test[j][1] << "," << test[j][2] << "]  Path:" << path1[j] << "\n";
				}
			}
		}
	}
}



void selecTestCase1() {
	int a, b, c, count = 0;
	for (int i = 0; i < n; i++) {
		a = test[i][0];
		b = test[i][1];
		c = test[i][2];
		//Execute the program

		path1[i] = calPath1(a,b,c);
		phermone[a] ++;
		phermone[b] ++;
		phermone[c] ++;

		//Pheromone updation
		updatePheromone();
	}
	//largest Pheromone 
	pos = lagestPheromone();
	cout << "\n largest pheromone at input:" << pos << endl;
	retRedusedCases(pos,1);
}


void selecTestCase() {
	int a, b, c, count = 0;
	for (int i = 0; i < n; i++) {
		a = test[i][0];
		b = test[i][1];
		c = test[i][2];
		//Execute the program

		path[i] = calPath(a, b, c);
		phermone[a] ++;
		phermone[b] ++;
		phermone[c] ++;

		//Pheromone updation
		updatePheromone();
	}
	//largest Pheromone 
	pos = lagestPheromone();
	cout << "largest pheromone at input:" << pos << endl;
	retRedusedCases(pos,0);
}

void retRedusedCases(int pos,int check) {

	if (check == 0) {
		int flagsize = 0;
		for (int i = 0; i<n; i++) {
			if (test[i][0] == pos || test[i][1] == pos || test[i][2] == pos) {
				if (path[i] == 1 ||path[i] == 2 ) {
					int flag3 = 0;
					for (int k = 0; k < red_no; k++) {
						if (test[i][0] == red[k][0] && test[i][1] == red[k][1] && test[i][2] == red[k][2])
							flag3 = 1;
					}
					if (flag3 == 0) {
						red[flagsize][0] = test[i][0];
						red[flagsize][1] = test[i][1];
						red[flagsize][2] = test[i][2];
						flagsize++;
						red_no++;
					}
				}
			}
		}
	}
	else {
		int flagsize = 0;
		for (int i = 0; i<n; i++) {
			if (test[i][0] == pos || test[i][1] == pos || test[i][2] == pos) {
				if (path1[i] == 2) {
					int flag3 = 0;
					for (int k = 0; k < red_no1; k++) {
						if (test[i][0] == red1[k][0] && test[i][1] == red1[k][1] && test[i][2] == red1[k][2])
							flag3 = 1;
					}
					if (flag3 == 0) {
						red1[flagsize][0] = test[i][0];
						red1[flagsize][1] = test[i][1];
						red1[flagsize][2] = test[i][2];
						flagsize++;
						red_no1++;
					}
				}
			}
		}
	}
}

//Calculating largest pheromone level for phermone[];
int lagestPheromone() {
	float temp = 0;
	int p1 = 0;
	for (int i = 0; i < 6; i++) {
		if (phermone[i] > temp) {
			temp = phermone[i];
			p1 = i;
		}
	}
	return p1;
}



void updatePheromone() {
	//Decrease by 12% 

	for (int k = 0; k <6; k++) {
		float temp = 0.12 * phermone[k];
		phermone[k] = phermone[k] - temp;
	}
}

void initTestCases(int check) {
	if (check == 0) {
		for (int i = 0; i < n; i++) {
			path[i] = 0;
			path1[i] = 0;
			for (int j = 0; j<3; j++) {
				test[i][j] = 0;
				red[i][j] = -1;
				rej[i][j] = -1;
				red_no = 0;
				rej_no = 0;
			}
		}

		for (int i = 0; i < 5; i++) {
			faults[i] = 0;
			faults1[i] = 0;
		}

	}
	else {
		for (int i = 0; i < n; i++) {
			path1[i] = 0;
			for (int j = 0; j<3; j++) {
				test[i][j] = 0;
				rej[i][j] = -1;
				rej_no = 0;
			}
		}

		for (int i = 0; i < 5; i++) {
			faults1[i] = 0;
		}
	}
}


void setTestCases() {
	int fillc[3] = { 0,1,2 },
		fillb[3] = { 3,4,5 },
		filla[3] = { 0,1,2 };
	int k = 0,z=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int l = 0; l < 3; l++) {
				if (i == 0) {
					test[k][0] = filla[j];
					test[k][1] = fillb[l];
					test[k][2] = fillc[l];
					k++;
				}
				else if (i==2){
					test[k][0] = fillb[j];
					test[k][1] = fillc[l];
					test[k][2] = filla[l];
					k++;
				}
				else if (i == 1) {
					test[k][0] = fillc[j];
					test[k][1] = filla[l];
					test[k][2] = fillb[l];
					k++;
				}
			}
				
		}
	}
	/*
	cout << "Test Cases";
	for (int i = 0; i < n; i++) {
		cout <<i<< "[" << test[i][0] << "," << test[i][1] << "," << test[i][2] << "]\n";
	}
	*/

}




