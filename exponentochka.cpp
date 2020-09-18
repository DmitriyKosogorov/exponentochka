#include<iostream>
#include<cmath>
#include<algorithm>
typedef long long mytype;
using namespace std;
void SetData(int k, mytype* mas, int first)
{
	mas[0] = first;
	for (int i=1; i < k; i++)
	{
		mas[i] = 0;
	}
}
void print_e(mytype* e, int sizec)
{
	cout << e[0] << ",";
	for (int i = 1; i < sizec; i++)
		cout << e[i];
}

bool IsZero(int sizec, mytype* mas)
{
	for (int i=0; i < sizec; i++)
		if (mas[i] != 0)
			return(false);
	return(true);
}

void Div(int sizec, mytype* mas, int l)
{
	//print_e(mas, sizec);
	//cout << endl<<l<<endl;
	int i = 0;
	long long deli = 0;
	for (i = 0; i < sizec; i++)
	{
		deli = deli * 10 + mas[i];
		if (deli == 0)
			mas[i] = 0;
		else
		{
			if (deli >= l)
			{
				mas[i] = deli / l;
				deli = deli % l;
			}
			else
				mas[i] = 0;
		}
	}
	//print_e(mas, sizec);
	//cout << endl << endl;
}

void Add(int sizec, mytype* e, mytype* mas)
{
	//print_e(mas, sizec);
	//cout << endl;
	//print_e(e, sizec);
	//cout << endl;
	int oldadded = 0, newadded=0;
	for (int i = sizec - 1; i >= 0; i--)
	{
		if (mas[i] + e[i] + oldadded > 9)
			newadded = (mas[i] + e[i] + oldadded) / 10;
		else
			newadded = 0;
		e[i]= (mas[i] + e[i] + oldadded) % 10;
		oldadded = newadded;
	}
	//print_e(e, sizec);
	//cout << endl << endl;
}


int main()
{
	int B = 10;
	int N = 1000;
	int loga = log10(B);
	int K = (N / loga) + 1;
	int k = 1;
	mytype* e = new mytype[K];
	mytype* uk = new mytype[K];
	SetData(K, e, 1);
	SetData(K, uk, 1);
	while (!IsZero(K, uk))
	{
		Add(K, e, uk);
		Div(K, uk, k);
		k++;
		//cout << e[0]<<e[1]<<e[2] << endl;
	}
	e[0] = e[0] - 1;
	print_e(e, K);
	delete[] uk;
	delete[] e;
	return(0);
}