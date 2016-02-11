//


#include <iostream>
#include <iomanip>
#include <fstream>
//#include<cstdlib>
#include <stdio.h>

#include "Patterns.h"

const int MAX_RANGE=74;
const unsigned int MAX_DRAWS=10000;

using namespace std;

//numbers in fxs
int countN1(int &n1,int arrayN1[MAX_RANGE]);
int countN2(int &n2,int arrayN2[MAX_RANGE]);
int countN3(int &n3,int arrayN3[MAX_RANGE]);
int countN4(int &n4,int arrayN4[MAX_RANGE]);
int countN5(int &n5,int arrayN5[MAX_RANGE]);
int countpb(int &pb,int arraypb[MAX_RANGE]);

//

//patterns fxs
int p_plus_1(int n1,int n2,int n3, int n4,int n5,int pb,int pp1_ctr);
int p_plus_2(int n1,int n2,int n3, int n4,int n5,int pb,int pp2_ctr);
int p_plus_3(int n1,int n2,int n3, int n4,int n5,int pb,int pp3_ctr);
int p_plus_4(int n1,int n2,int n3, int n4,int n5,int pb,int pp4_ctr);
int p_plus_5(int n1,int n2,int n3, int n4,int n5,int pb,int pp5_ctr);

int patternChecker(int &n1, int &n2, int &n3, int &n4, int &n5, int &pb, int ct_array,double percent_array[1000]); 
int p_7(int n1,int n2,int n3,int n4,int n5,int pb,int pp7_ctr);

int user_guess(int n1,int n2,int n3,int n4,int n5,int pb,int g1, int g2, int g3, int g4, int g5, int g6,int pp_guess_ctr);

int main ()
{
	ifstream fin;
	ofstream fout;

	fin.open("Powerball_2000_2015.txt");
	fout.open("Out_powerball_2000_2015.txt");
	if(!fin)
	{
		cout<<"error!"<<endl<<endl;
	}
	//ofstream fout;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int pb = 0;
	int line =0;
	// guesses entered by user, keyboard
	int g1=0;//number guess #1
	int g2=0;
	int g3=0;
	int g4=0;
	int g5=0;
	int g6=0;



	int pp1_ctr=0;
	int pp2_ctr=0;
	int pp3_ctr=0;
	int pp4_ctr=0;
	int pp5_ctr=0;

	int pp7_ctr=0;
	int pp_guess_ctr=0;
	
// declare all my arrays
	int arrayN1[MAX_RANGE];
	int arrayN2[MAX_RANGE];
	int arrayN3[MAX_RANGE];
	int arrayN4[MAX_RANGE];
	int arrayN5[MAX_RANGE];
	int arraypb[MAX_RANGE];

	//int ctr_array [1000];
	double percent_array [1000];

// initializes all my number arrays

	for(int i=0; i < MAX_RANGE; i++)
	{
		arrayN1[i]=0;
		arrayN2[i]=0;
		arrayN3[i]=0;
		arrayN4[i]=0;
		arrayN5[i]=0;
		arraypb[i]=0;
		
	}

	// initializes all my ctr and percentage arrays
	int ctr_array=0;

	for(int i=0; i < 1000; i++)
	{
		//ctr_array[i]=0;
		percent_array[i]=0;
		
	}

	// get users numbers
	cout<<"enter 6 numbers to check!"<<endl;
	cin>>g1>>g2>>g3>>g4>>g5>>g6;
	cout<<"checking your numbers...."<<endl;


	// collect numbers from text file and calls fxs to count numbers
	while(!fin.eof())// read all numbers while not eof
	{

	

		fin>>n1>>n2>>n3>>n4>>n5>>pb;
		//cout<<n1<<" "<<n2<<" " <<n3<<" "<<n4<<" "<<n5<<" "<<pb<<endl;
		countN1(n1,arrayN1);
		countN2(n2, arrayN2);
		countN3(n3,arrayN3);
		countN4(n4, arrayN4);
		countN5(n5,arrayN5);
		countpb(pb, arraypb);

		// PATTERNS
		pp1_ctr=p_plus_1(n1,n2,n3,n4,n5,pb,pp1_ctr);
		pp2_ctr=p_plus_2(n1,n2,n3,n4,n5,pb,pp2_ctr);
		pp3_ctr=p_plus_3(n1,n2,n3,n4,n5,pb,pp3_ctr);
		pp4_ctr=p_plus_4(n1,n2,n3,n4,n5,pb,pp4_ctr);
		pp5_ctr=p_plus_5(n1,n2,n3,n4,n5,pb,pp5_ctr);
		pp7_ctr=p_7(n1,n2,n3,n4,n5,pb,pp7_ctr);


		ctr_array=patternChecker(n1,n2,n3,n4,n5,pb,ctr_array,percent_array); 
		pp_guess_ctr=user_guess(n1,n2,n3,n4,n5,pb,g1,g2,g3,g4,g5,g6,pp_guess_ctr);
		
		line++;
	}

	// title
	fout<<endl<<endl<<endl;
	fout<<"               DANA'S COOL LOTTERY NUMBERS "<<endl<<endl<<endl;
	fout<<"output updated date:1-6-2016"<<endl;
	//print out my N1 array
	for(int j=0; j<MAX_RANGE; j++)
	{
	fout<<"number #"<<setw(2)<<right<<j+1<<" >"
	<<setw(3)<<right<<arrayN1[j] +arrayN2[j] +arrayN3[j]+arrayN4[j] +arrayN5[j] 
	<<"  POWERBALL:"<<setw(3)<<right<<arraypb[j]<<endl;
	fout<<"_____________________________________"<<endl;
	}
	fout<<endl<<endl;
	fout<<"             PATTERNS:"<<endl;
	fout<<"PATTERN: a number plus 1 happens "<<pp1_ctr<<" times."<<endl<<endl;
	fout<<"PATTERN: a number plus 2 happens "<<pp2_ctr<<" times."<<endl<<endl;
	fout<<"PATTERN: a number plus 3 happens "<<pp3_ctr<<" times."<<endl<<endl;
	fout<<"PATTERN: a number plus 4 happens "<<pp4_ctr<<" times."<<endl<<endl;
	fout<<"PATTERN: a number plus 5 happens "<<pp5_ctr<<" times."<<endl<<endl;
	//???????????????????????????????????????????????????????????????????????????????????????????????????????????
	// I need to replace all counters withan arrau of counters, and add a perctegae array and a powerball array????
	fout<<"PATTERN: n1+13, n2+15, n3+25, n4+5 "<<ctr_array<<" times."<<endl<<endl;
    fout<<"PATTERN: n1+24, n2+10, n3+2, n4+3 "<<pp7_ctr<<" times."<<endl<<endl;
	//cout<<"NUMERS: "<<g1<<","<<g2<<","<<g3<<","<<g4<<","<<g5<<","<<g6<<endl;
	fout<<"NUMERS: "<<g1<<","<<g2<<","<<g3<<","<<g4<<","<<g5<<","<<g6<<endl;
	fout<<"USER guessed numbers: "<<pp_guess_ctr<<" times."<<endl<<endl;
	fout<<"number of draws: "<<line<<endl;
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++fout to file


	// title to screeen
	cout<<endl<<endl<<endl;
	cout<<"               DANA'S COOL LOTTERY NUMBERS "<<endl<<endl<<endl;
	cout<<"1-16-2016"<<endl;
	//print out my N1 array
	for(int j=0; j<MAX_RANGE; j++)
	{
	cout<<"number #"<<setw(2)<<right<<j+1<<" >"
	<<setw(3)<<right<<arrayN1[j] +arrayN2[j] +arrayN3[j]+arrayN4[j] +arrayN5[j] 
	<<"  POWERBALL:"<<setw(3)<<right<<arraypb[j]<<endl;
	cout<<"_____________________________________"<<endl;
	}
	cout<<endl<<endl;
	cout<<"             PATTERNS:"<<endl;
	cout<<"PATTERN: a number plus 1 happens "<<pp1_ctr<<" times."<<endl<<endl;
	cout<<"PATTERN: a number plus 2 happens "<<pp2_ctr<<" times."<<endl<<endl;
	cout<<"PATTERN: a number plus 3 happens "<<pp3_ctr<<" times."<<endl<<endl;
	cout<<"PATTERN: a number plus 4 happens "<<pp4_ctr<<" times."<<endl<<endl;
	cout<<"PATTERN: a number plus 5 happens "<<pp5_ctr<<" times."<<endl<<endl;
	//???????????????????????????????????????????????????????????????????????????????????????????????????????????
	// I need to replace all counters withan array of counters, and add a percentage array and a powerball array????
	cout<<"PATTERN: n1+13, n2+15, n3+25, n4+5 "<<ctr_array<<" times."<<endl<<endl;
cout<<"PATTERN: n1+24, n2+10, n3+2, n4+3 "<<pp7_ctr<<" times."<<endl<<endl;
cout<<"NUMERS: "<<g1<<","<<g2<<","<<g3<<","<<g4<<","<<g5<<","<<g6<<endl;
	//cout<<"fibbonacci sequence calculated: " <<fib_num_calc<<endl<<endl;
	//cout<<"matches fibbonaccie sequence"<< fib_ctr<<" times."<<endl;
cout<<"USER guessed numbers: "<<pp_guess_ctr<<" times."<<endl<<endl;
	cout<<"number of draws: "<<line<<endl;





	fin.close();
	system("pause");

	return 0;
}// END OF MAIN
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int patternChecker(int &n1, int &n2, int &n3, int &n4, int &n5, int &pb, int ctr_array,double percent_array[1000]){
	
	
	if (( n2-n1==13) && (n3-n2 ==15) && (n4-n3 ==25) && (n5-n4 ==5))
	{ctr_array++;}
	return ctr_array;
}
//*****************************************************

int p_7(int n1,int n2,int n3,int n4,int n5,int pb,int pp7_ctr){
	if((n2-n1 ==24) && (n3-n2==10) && (n4-n3==2) && (n5-n4 ==3))
	{pp7_ctr++;}
	return pp7_ctr;
}
//**********************************************************
//user guess pattern

int user_guess(int n1,int n2,int n3,int n4,int n5,int pb,int g1, int g2, int g3, int g4, int g5, int g6,int pp_guess_ctr){
	
	if((n1==g1) && (n2==g2) && (n3==g3) && (n4 ==g4) && (n5==g5) && (pb == g6))
	{pp_guess_ctr++;}
	return pp_guess_ctr;
}
//*****************************************************
//fibbonacci made seq and then check against sequence for a match

/* {
    int n, firstTerm = 1, secondTerm = 1, nextTerm;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: " << firstTerm << " + " << secondTerm << " + ";
    for (int i = 1; i <= n-2; ++i) {
        nextTerm = firstTerm + secondTerm;
        cout << nextTerm << " + ";
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }*/
    
//????????????????????????????????????????????????????????????????????


//*****************************************************
int countN1(int &n1,int arrayN1[MAX_RANGE])
{
	for(int b=0; b<MAX_RANGE; b++)
	{
		if(n1==b+1)
		{arrayN1[b]++;}
	}
	return arrayN1[MAX_RANGE];
}

	int countN2(int &n2,int arrayN2[MAX_RANGE])
{
	for(int c=0; c<MAX_RANGE; c++)
	{
		if(n2==c+1)
		{arrayN2[c]++;}
	}
	return arrayN2[MAX_RANGE];
}

int countN3(int &n3,int arrayN3[MAX_RANGE])
{
	for(int d=0; d<MAX_RANGE; d++)
	{
		if(n3==d+1)
		{arrayN3[d]++;}
	}
	return arrayN3[MAX_RANGE];
}

int countN4(int &n4,int arrayN4[MAX_RANGE])
{
	for(int k=0; k<MAX_RANGE; k++)
	{
		if(n4==k+1)
		{arrayN4[k]++;}
	}
	return arrayN4[MAX_RANGE];
}

int countN5(int &n5,int arrayN5[MAX_RANGE])
{
	for(int m=0; m<MAX_RANGE; m++)
	{
		if(n5==m+1)
		{arrayN5[m]++;}
	}
	return arrayN5[MAX_RANGE];
}

int countpb(int &pb,int arraypb[MAX_RANGE])
{
	for(int n=0; n<MAX_RANGE; n++)
	{
		if(pb==n+1)
		{arraypb[n]++;}
	}
	return arraypb[MAX_RANGE];
}

int p_plus_1(int n1,int n2,int n3, int n4,int n5,int pb,int pp1_ctr){

	if(n1==(n2-1))
	{pp1_ctr++;}
	if (n1==(n3-1))
	{pp1_ctr++;}
	if(n1==(n4-1))
	{pp1_ctr++;}
	if(n1==(n5-1))
	{pp1_ctr++;}
	
	if (n2==(n3-1))
	{pp1_ctr++;}
	if(n2==(n4-1))
	{pp1_ctr++;}
	if(n2==(n5-1))
	{pp1_ctr++;}
	
	if(n3==(n4-1))
	{pp1_ctr++;}
	if(n3==(n5-1))
	{pp1_ctr++;}
	
	if(n4==(n5-1))
	{pp1_ctr++;}
	

	return pp1_ctr;
}

int p_plus_2(int n1,int n2,int n3, int n4,int n5,int pb,int pp2_ctr){

	if(n1==(n2-2))
	{pp2_ctr++;}
	if (n1==(n3-2))
	{pp2_ctr++;}
	if(n1==(n4-2))
	{pp2_ctr++;}
	if(n1==(n5-2))
	{pp2_ctr++;}

	if (n2==(n3-2))
	{pp2_ctr++;}
	if(n2==(n4-2))
	{pp2_ctr++;}
	if(n2==(n5-2))
	{pp2_ctr++;}
	
	if(n3==(n4-2))
	{pp2_ctr++;}
	if(n3==(n5-2))
	{pp2_ctr++;}
	
	if(n4==(n5-2))
	{pp2_ctr++;}
	
	return pp2_ctr;
}

int p_plus_3(int n1,int n2,int n3, int n4,int n5,int pb,int pp3_ctr){

	if(n1==(n2-3))
	{pp3_ctr++;}
	if (n1==(n3-3))
	{pp3_ctr++;}
	if(n1==(n4-3))
	{pp3_ctr++;}
	if(n1==(n5-3))
	{pp3_ctr++;}
	
	if (n2==(n3-3))
	{pp3_ctr++;}
	if(n2==(n4-3))
	{pp3_ctr++;}
	if(n2==(n5-3))
	{pp3_ctr++;}
	
	if(n3==(n4-3))
	{pp3_ctr++;}
	if(n3==(n5-3))
	{pp3_ctr++;}
	
	if(n4==(n5-3))
	{pp3_ctr++;}
	
	return pp3_ctr;
}

int p_plus_4(int n1,int n2,int n3, int n4,int n5,int pb,int pp4_ctr){

	if(n1==(n2-4))
	{pp4_ctr++;}
	if (n1==(n3-4))
	{pp4_ctr++;}
	if(n1==(n4-4))
	{pp4_ctr++;}
	if(n1==(n5-4))
	{pp4_ctr++;}
	
	if (n2==(n3-4))
	{pp4_ctr++;}
	if(n2==(n4-4))
	{pp4_ctr++;}
	if(n2==(n5-4))
	{pp4_ctr++;}
	
	if(n3==(n4-4))
	{pp4_ctr++;}
	if(n3==(n5-4))
	{pp4_ctr++;}
	
	if(n4==(n5-4))
	{pp4_ctr++;}
	

	return pp4_ctr;
}

int p_plus_5(int n1,int n2,int n3, int n4,int n5,int pb,int pp5_ctr){

	if(n1==(n2-5))
	{pp5_ctr++;}
	if (n1==(n3-5))
	{pp5_ctr++;}
	if(n1==(n4-5))
	{pp5_ctr++;}
	if(n1==(n5-5))
	{pp5_ctr++;}
	
	if (n2==(n3-5))
	{pp5_ctr++;}
	if(n2==(n4-5))
	{pp5_ctr++;}
	if(n2==(n5-5))
	{pp5_ctr++;}
	
	if(n3==(n4-5))
	{pp5_ctr++;}
	if(n3==(n5-5))
	{pp5_ctr++;}
	
	if(n4==(n5-5))
	{pp5_ctr++;}
	

	return pp5_ctr;
}