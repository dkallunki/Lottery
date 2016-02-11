// text converter


#include <iostream>
#include <fstream>
#include <stdio.h>

#include <string>


using namespace std;

int main(){
	ifstream fin;
	ofstream fout;

	fin.open("pb_orig.txt");// file going in
	fout.open("Out_pb_orig1.txt");//file going out

	string date=" ";
	int n1=0;
	char c1=' ';
	int n2=0;
	char c2=' ';
	int n3=0;
	char c3=' ';
	int n4=0;
	char c4= ' ';
	int n5 =0;
	char c5=' ';
	string mega =" ";
	string ball =" ";
	int powerBall=0;
	int playnumber=0;

	int line=0;
	

	while(!fin.eof()){
		
		// for megamillions file to lotto101 format
		/*fin>>date>>n1>>c1>>n2>>c2>>n3>>c3>>n4>>c4>>n5>>c5>>mega>>ball>>powerBall;
		fout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" " <<n5<<" "<<powerBall<<endl;
		*/

		// for powerball file to convert lotto101 format
		fin>>date>>n1>>n2>>n3>>n4>>n5>>powerBall;
		fout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" " <<n5<<" "<<powerBall<<endl;

		line++;
	}

	cout<<"draws; "<<line<<endl;

	fin.close();
	fout.close();

	





	return 0;
}