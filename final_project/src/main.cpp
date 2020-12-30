#include<iostream>
#include<map>
#include<fstream>
#include"header.h"

using namespace std;

int main(){
	int count[5] = {0};
	string tmp, str, v[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	int p, n, num, set;
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
	}
	fin.close();
	fin.open("../benchmarks/alu4_4.nets");
	fin >> n;
	for(int i = 0; i < n; i++){	
		num = 0, set = 0;
		getline(fin, str);
		
		while(str.find(" ") != -1){
			v[num++] = tmp.assign(str, 0, str.find(" "));
			str.erase(0, str.find(" ")+1);
			if(input.find(v[i]) == input.end()){
				input[v[i]] = 0;
			}
//			cout << v[num-1] << endl;
		}
		for(int i = 1; i < num; i++){
			if(input[v[i]] > 0) {
				set = input[v[i]];
				cout << "@"<< set <<"@";
				break;
			}
		}
		if(set == 0){
			break;
		}
		for(int i = 1; i < num; i++){
			if(input[v[i]] == 0) {
				input[v[i]] = set;
			}
			count[input[v[i]]]++;
			printf("<%s:%d>", v[i].c_str(), input[v[i]]);
		}
	}

	cout << input.size() << endl;
	return 0;	
}

