#include <iostream>
using namespace std;
//todo сделать проверку невырожденной матрицы


void print(double**a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void printAns(double** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

double** summer(double** a, int n, int col) {
	for (int i = 0; i < n; i++) {
		if (i == col) continue;  // пропускаем диагональную строкуc
		double factor = a[i][col];
		for (int j = 0; j < 2 * n; j++) {
			a[i][j] -= a[col][j] * factor;
		}
	}
	return a;
}
//обновленно на гите
double**proc(double** a, int n) {
	double* temp = new double[n];
	for (int i = 0; i < n; i++) {
		int index = i;
		//cout << "\niteration " << i << endl;
		double m = a[i][i];
		//нахождение макс строки
		for (int j = i; j < n; j++) {
			if (abs(m) < abs(a[j][i])) {
				index = j;
				m = a[j][i];
			}
		}

		if (abs(m) < 1e-9) {
			cout << "\nThe matrix is virojdena((";
			return nullptr; // Прерываем выполнение
		}

		//ставим ее на первое место
		if (index != i) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}

		//cout << "\n";
		//print(a, n);

		//делаем первый элемент единицей
		m = a[i][i];
		for (int t = i; t < 2*n; t++) {
			a[i][t] /= m;
		}
		//cout << "\n";
		//print(a,n);
		//cout << "\n";
		a = summer(a, n, i);
		
		//print(a,n);
	}

	double** ans = new double* [n];
	for (int i = 0; i < n; i++) {
		ans[i] = new double[n];
		for (int j = 0; j < n; j++) {
			ans[i][j] = a[i][j+n];
		}
	}

	return ans;
}

int main() {
	double num = 1;
	int n = 2;

	double** a = new double*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[2*n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		for (int j = n; j < 2*n; j++) {
			a[i][j] = 0;
		}
		a[i][n + i] = 1;
	}

	//print(a,n);

	a = proc(a,n);

	printAns(a,n);
}

//2 5 7
//6 3 4
//5 - 2 - 3