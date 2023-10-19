#pragma once

#include <iostream>
using namespace std;

#include "OneArrayMatrix.h"

class CoordinateMatrix
{
public:
    int n, nz;
    int *array, *rows, *cols;
    OneArrayMatrix oneArrMatr;

    CoordinateMatrix(OneArrayMatrix& matr) : oneArrMatr(matr), n(matr.n), nz(0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (oneArrMatr.arr[i * n + j])
                    nz++;
        array = new int[nz];
        rows = new int[nz];
        cols = new int[nz];
        
        int ind = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (oneArrMatr.arr[i * n + j])
                {
                    array[ind] = oneArrMatr.arr[i * n + j];
                    rows[ind] = i;
                    cols[ind] = j;
                    ind++;
                }
    }

    friend ostream& operator<<(ostream& ostr, const CoordinateMatrix& matr)
    {
        /*ostr << "array: ";
        for (int i = 0; i < matr.nz; i++)
            ostr << matr.array[i] << " ";
        ostr << endl;

        ostr << "rows:  ";
        for (int i = 0; i < matr.nz; i++)
            ostr << matr.rows[i] << " ";
        ostr << endl;

        ostr << "cols:  ";
        for (int i = 0; i < matr.nz; i++)
            ostr << matr.cols[i] << " ";
        ostr << endl;

        return ostr;*/

        ostr << matr.oneArrMatr;
        return ostr;
    }

    /*CoordinateMatrix CoordMult(CoordinateMatrix& matr)
    {
        CoordinateMatrix res(oneArrMatr);
        for (int ind = 0; ind < nz; ind++)
            
        return res;
    }*/
};