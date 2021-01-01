int quadrant(double x, double y, int width, int high, double pace) {
	double a = pace * width + pace;
	double b = pace * high + pace;
	if(x == 0){
		if(y > b / 2) {
			return 2;
		}else{
			return 3;
		}
	}else if(y == 0){
		if(x > a / 2) {
			return 4;
		}else{
			return 3;
		}
	}else if(x == a){
		if(y > a / 2) {
			return 1;
		}else{
			return 4;
		}
	}else if(y == b){
		if(y > b / 2) {
			return 1;
		}else{
			return 2;
		}
	}
	std::cout << a <<"#" << b << ">>";
	return 0;
}

double pace(int a, int b) {
	if(a == b) {
		return 1;
	}else if(2 * a + 1 == b){
		return 0.5;
	}else{
		return 0.25;
	}
}


