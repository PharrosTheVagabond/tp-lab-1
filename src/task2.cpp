bool checkPrime(unsigned int value) {
	if (value <= 1)
		return false;
	else if ((value % 2 == 0) && (value != 2)){
		return false;
	}
	else if (value == 2){
		return true;
	}
	else {
		for (int dev = 3; dev <= value; dev = dev + 2) {
			if ((value % dev == 0) && (value != dev)){
				return false;
			}
			else if (value == dev){
				return true;
			}
		}
	}
}

unsigned long long nPrime(unsigned n) {
	int count = 1;
	int num = 2;
	while (count != n) {
		num++;
		if (checkPrime(num)){
			count++;
		}
	}
	return num;
}

unsigned long long nextPrime(unsigned long long value) {

	if (value < 2){
		return 2;
	}
	value++; //������� ����� �� �� ��������� �����
	if (value % 2 == 0){
		value++;
	}
	while (checkPrime(value) != 1){
		value = value + 2;
	}
	return value;
}