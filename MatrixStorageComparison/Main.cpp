#include "CRSMatrix.h"
#include "TestMultDuration.h"

int main()
{
	int n1 = 1000, m1 = 1000, n2 = 1000, m2 = 1000, percent = 10;

	OneArrayMatrix oneArrMatr1(n1, m1);
	oneArrMatr1 = generateSparseMatrix(n1, m1, percent);
	OneArrayMatrix oneArrMatr2(n2, m2);
	oneArrMatr2 = generateSparseMatrix(n2, m2, percent);
	cout << "OneArrayMult duration: " << testOneArrayMult(oneArrMatr1, oneArrMatr2) << " sec" << endl << endl;


	CoordinateMatrix coordMatr1(oneArrMatr1), coordMatr2(oneArrMatr2);
	cout << "CoordMult duration: " << testCoordMult(coordMatr1, coordMatr2) << " sec" << endl << endl;

	return 0;
}