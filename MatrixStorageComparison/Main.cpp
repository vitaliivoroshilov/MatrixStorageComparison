#include "CoordinateMatrix.h"

int main()
{
	int n1, m1, n2, m2;

	cout << "n1: ";
	cin >> n1;
	cout << "m1: ";
	cin >> m1;
	cout << endl;
	OneArrayMatrix oneArrMatr1(n1, m1);
	cout << "Matrix1 " << n1 << "*" << m1 << ":" << endl;
	cin >> oneArrMatr1;
	cout << endl;

	n2 = m1;
	cout << "n2= " << n2 << endl << "m2: ";
	cin >> m2;
	cout << endl;
	OneArrayMatrix oneArrMatr2(n2, m2);
	cout << "Matrix2 " << n2 << "*" << m2 << ":" << endl;
	cin >> oneArrMatr2;
	cout << endl;

	cout << "OneArrayMult:" << endl << oneArrMatr1.OneArrayMult(oneArrMatr2);

	
	CoordinateMatrix coordMatr1(oneArrMatr1), coordMatr2(oneArrMatr2);
	cout << "CoordMult:" << endl << coordMatr1.CoordMult(coordMatr2);

	return 0;
}