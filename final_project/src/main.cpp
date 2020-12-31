#include"header.h"

using namespace std;
struct Quad{
	queue<string> q0;
	queue<string> q1;
	queue<string> q2;
	queue<string> q3;
	queue<string> q4;
};
int main(){
	int count[5] = {0};
	string tmp, str, v[10000], inst[10000];
	CLB_Dim clb_dim;
	Num_IO num_io;
	CLB clb;
	Quad quad;
	double p, x, y;
	int Num_PO, Num_PI;
	int q, n, pi, po, num, set, Num_Inst = 0, maxn = 1e9;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	map<string, int> input;
	ifstream fin;
	fin.open("../benchmarks/clma_4.info");
	// CLB_Dim
	fin >> tmp >> clb_dim.width >> clb_dim.high;
	// Num_I/O_Pad
	fin >> tmp >> num_io.width >> num_io.high;
	p = pace(clb_dim.width, num_io.width);
	// Num_PI
	fin >> tmp >> Num_PI;
	for(int i = 0; i < Num_PI; i++){
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
	}
	// Num_PO
	fin >> tmp >> Num_PO;
	for(int i = 0; i < Num_PO; i++){
		fin >> tmp >> x >> y;
		q = quadrant(x, y, num_io.width, num_io.high, p);
		input[tmp] = q;
		count[q]++;
	}
	// Num_Inst
	fin >> tmp >> pi >> po;
	Num_Inst = pi + po;
	for(int i = 0; i < Num_Inst; i++){
		fin >> tmp;
		inst[i] = tmp;
	}
	fin.close();
	// Nets
	fin.open("../benchmarks/clma_4.nets");
	fin >> n;
	for(int j = 0; j < n; j++){
		num = 0, set = 0;
		getline(fin, str);
		
		while(str.find(" ") != -1){
			v[num++] = tmp.assign(str, 0, str.find(" "));
			str.erase(0, str.find(" ")+1);
		}
		v[num] = str;
		for(int i = 1; i <= num; i++){
			if(input[v[i]] > 0) {
				set = input[v[i]];
				break;
			}
		}
		for(int i = 1; i <= num; i++) {
			if(input[v[i]] == 0) {
				input[v[i]] = set;
			}
		}
	}
	cout << "done!" << endl;
	for(int i = 0; i < Num_Inst; i++){
		count[input[inst[i]]]++;
		switch(input[inst[i]]){
			case 1:
				quad.q1.push(inst[i]);
				break;
			case 2:
				quad.q2.push(inst[i]);
				break;
			case 3:
				quad.q3.push(inst[i]);
				break;
			case 4:
				quad.q4.push(inst[i]);
				break;
			default:
				quad.q0.push(inst[i]);
	        	break;
		}
	}
	
	// layout
	for(int i = 0; i < 5; i++){
		cout << i << ":::" << count[i] << "::: " << count[i]/2 << endl;
	}
	int sc = sqrt(count[1]/2);

	clb.right.top = sc;
	clb.right.bottom = clb_dim.high - clb.right.top;
	
	for(int i = 0; clb.right.top * clb.top.right < count[1]/2; i++){
		clb.top.right = ((count[1]/2) / clb.right.top) + i;
		clb.top.left = clb_dim.width - clb.top.right;
	}

	clb.bottom.right = sc + 1;
	clb.bottom.left = clb_dim.width - clb.bottom.right;
	
	for(int i = 0; clb.left.top * clb.top.left < count[2]/2; i++){
		clb.left.top = ((count[2]/2) / clb.top.right) + i;
		clb.left.bottom = clb_dim.high - clb.left.top;
	}
	
	cout << "1->" << clb.right.top << ":" << clb.top.right << "->" << clb.right.top * clb.top.right <<endl;
	cout << "2->" << clb.top.left << ":" << clb.left.top << "->" << clb.top.left * clb.left.top <<endl;
	cout << "3->" << clb.left.bottom  << ":" << clb.bottom.left << "->" << clb.left.bottom * clb.bottom.left <<endl;
	cout << "4->" << clb.bottom.right << ":" << clb.right.bottom << "->" << clb.bottom.right * clb.right.bottom <<endl;
	cout  << "w:" << clb_dim.width << "h:" << clb_dim.high;
	return 0;
}

