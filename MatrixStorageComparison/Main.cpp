#include "CoordinateMatrix.h"

int main()
{
	int n = 3;
	OneArrayMatrix oneArrMatr1(n), oneArrMatr2(n);
	cin >> oneArrMatr1;
	cin >> oneArrMatr2;

	cout << oneArrMatr1.OneArrayMult(oneArrMatr2);

	CoordinateMatrix coordMatr1(oneArrMatr1), coordMatr2(oneArrMatr2);
	cout << coordMatr1;

	return 0;
}