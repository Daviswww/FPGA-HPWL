#include<iostream>
#include<map>
#include<fstream>
#include"header.h"

using namespace std;

int main(){
	string tmp, str, v[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	int p, n;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/alu4_4.info");

	fin >> tmp >> clb_dim.width >> clb_dim.high;
	fin >> tmp >> num_io.width >> num_io.high;
	p = pace(clb_dim.width, num_io.width);
	
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
	}
	
	fin >> tmp >> n;
	for(int i = 0; i < n; i++){
		int x, y, q;
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		cout << input[tmp] << endl;
	}
	fin.close();
	fin.open("../benchmarks/alu4_4.nets");
	fin >> n;
	for(int i = 0; i < n; i++){
		cout << ".";
		int num = 0, set = 0;
		getline(fin, str);
		
		while(str.find(" ") != -1){
			v[num++] = tmp.assign(str, 0, str.find(" "));
			str.erase(0, str.find(" ")+1);
//			cout << v[num-1] << endl;
		}
		
		cout << input[v[1]] << ":" << input[v[num]] << endl;
//
//		for(int i = 1; i < num; i++){
//			input[v[i]] = set;
//		}
	}
	
	cout << input.size();
	printf("%d:::%d:::%d:::%d::::::%d", q1, q2, q3, q4, input.size());
	
	return 0;	
}

