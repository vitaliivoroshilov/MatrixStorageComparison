#pragma once

#include <iostream>
using namespace std;

class OneArrayMatrix
{
public:
    int* arr;
    int n;

    OneArrayMatrix(int size) : n(size)
    {
        arr = new int[n * n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i * n + j] = 0;
    }

    OneArrayMatrix(OneArrayMatrix& matr) : n(matr.n)
    {
        arr = new int[n * n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i * n + j] = matr.arr[i * n + j];
    }

    friend istream& operator>>(istream& istr, OneArrayMatrix& matr)
    {
        for (int i = 0; i < matr.n; i++)
            for (int j = 0; j < matr.n; j++)
                istr >> matr.arr[i * matr.n + j];
        return istr;
    }

    friend ostream& operator<<(ostream& ostr, const OneArrayMatrix& matr)
    {
        for (int i = 0; i < matr.n; i++)
        {
            for (int j = 0; j < matr.n; j++)
                ostr << matr.arr[i * matr.n + j] << " ";
            ostr << endl;
        }
        ostr << endl;
        return ostr;
    }

    OneArrayMatrix OneArrayMult(OneArrayMatrix& matr)
    {
        OneArrayMatrix res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.arr[i * n + j] += arr[i * n + k] * matr.arr[k * n + j];
        return res;
    }
};