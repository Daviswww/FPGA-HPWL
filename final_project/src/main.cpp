#include<iostream>
#include<map>
#include<fstream>
#include"header.h"

using namespace std;

int main(){
	string tmp;
	CLB_Dim clb_dim;
	Num_IO num_io;
	int n;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/alu4_4.info");

	fin >> tmp >> clb_dim.width >> clb_dim.high;
	fin >> tmp >> num_io.width >> num_io.high;
	fin >> n;
	
	for(int i = 0; i < n; i++){
		int x, y;
		fin >> tmp >> x >> y;
	}
	return 0;	
}

