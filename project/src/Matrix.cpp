#include "Matrix.h"
template <class MATR>
Matrix<MATR>::Matrix() {}
template <class MATR>
Matrix<MATR>::Matrix(int therows, int thecolmuns, MATR num[])
{
   this->therows = therows;
   this -> thecolmuns = thecolmuns;
    element = new MATR*[therows];

    for (int k = 0; k < therows; k++)
        element[k] = new MATR[thecolmuns];

    for (int k = 0; k < therows; k++)
        for (int m = 0; m< thecolmuns; m++)
            element[k][m] = num[k * thecolmuns + m];

}
template <class MATR>
Matrix<MATR>::Matrix(int therows, int thecolmuns)
{
    this->therows = therows;
    this->thecolmuns = thecolmuns;
    element= new MATR*[therows];
    for (int k = 0; k < therows; k++)
        element[k] = new MATR[thecolmuns];
}
template<class MATR>
Matrix<MATR>::gettherows()
{
    return therows;
}

template<class MATR>
Matrix<MATR>::getthecolmuns()
{
    return thecolmuns;
}
template<class MATR2>
istream&operator>> (istream& theinput,Matrix<MATR2>&qmm)
{
    cin >> qmm.therows>> qmm.thecolmuns;
    qmm.element = new MATR2*[qmm.therows];
    for (int k = 0; k< qmm.therows; k++)
        qmm.element[k] = new MATR2[qmm.thecolmuns];
    for (int k = 0; k< qmm.therows; k++)
    for (int m = 0; m < qmm.thecolmuns; m++)
        theinput>> qmm.element[k][m];

    return theinput;
}
template<class MATR2>
ostream&operator<<(ostream& theoutbut, const Matrix<MATR2>& qmm)
{
    for (int k = 0; k < qmm.therows; k++)
    {
        theoutbut<< endl;
        for (int m = 0; m < qmm.thecolmuns; m++)
            theoutbut<< qmm.element[k][m] << "  ";
    }
    theoutbut << endl;

    return theoutbut;
}




template<class MATR>
Matrix<MATR>::Matrix(const Matrix<MATR>&thecopy)
{
    this->thecolmuns = thecopy.thecolmuns;
    this->therows = thecopy.therows;
    this->element=new MATR*[therows];

    for (int k = 0; k < therows; k++)
        this->element[k] = new MATR[thecolmuns];

    for (int k = 0; k < therows; k++)
        for (int m = 0; m < thecolmuns; m++)
            this->element[k][m] = thecopy.element[k][m];
}

template<class MATR>
Matrix<MATR> Matrix<MATR>::operator+( Matrix<MATR> & qmm2)
{
    Matrix<MATR> qmm(therows,thecolmuns);
    for (int k = 0; k < therows; k++)
        for (int m = 0; m < thecolmuns; m++)
            qmm.element[k][m] = 0;
 for (int k= 0; k < qmm.therows; k++)
    {
        for (int m = 0; m< qmm.thecolmuns; m++)
        {
            qmm.element[k][m] = (element[m][k] + qmm2.element[k][m]);
        }
    }
    return qmm;
}

// A function to remove the value of another matrix from it

template<class MATR>
Matrix<MATR> Matrix<MATR>::operator-(Matrix<MATR> &qmm2)
{
    Matrix<MATR> qmm(therows,thecolmuns);
    for (int k = 0; k < therows; k++)
        for (int m = 0; m < thecolmuns; m++)
            qmm.element[k][m] = 0;


    for (int k = 0; k < qmm.therows; k++)
    {
        for (int m = 0; m < qmm.thecolmuns; m++)
        {
            qmm.element[k][m] = (element[k][m] - qmm2.element[k][m]);
        }
    }
    return qmm;
}

template<class MATR>
Matrix<MATR> Matrix<MATR>::operator*(Matrix<MATR> &qmm2)
{
    Matrix<MATR> qmm(therows,thecolmuns);

    for (int k = 0; k < therows; k++)
        for (int m = 0; m < qmm2.thecolmuns;m++)
            qmm.element[k][m] = 0;
for (int k = 0; k < therows; k++)
        for (int m = 0; m < qmm2.thecolmuns; m++)
            for (int z = 0; z < thecolmuns; z++)
            {
                qmm.element[k][m] += element[k][z] * qmm2.element[z][m];
            }
    return qmm;
}

template <class MATR>
Matrix<MATR> Matrix<MATR>::operator+(MATR value)
{
    Matrix<MATR> qmm(therows,thecolmuns);

    for (int k = 0; k < therows; k++)
        for (int m = 0; m < thecolmuns; m++)
            qmm.element[k][m] = 0;
    for (int k = 0; k < qmm.therows; k++)
    {
        for (int m = 0; m < qmm.thecolmuns; m++)
        {
            qmm.element[k][m] = (element[k][m] + value);
        }
    }
    return qmm;
}

//A matrix to remove a value from a matrix
template <class MATR>
Matrix<MATR> Matrix<MATR>::operator-(MATR value)
{
    Matrix<MATR> qmm(therows,thecolmuns);

    for (int k = 0; k < therows; k++)
        for (int m = 0; m < thecolmuns; m++)
            qmm.element[k][m] = 0;
     for (int k = 0; k < qmm.therows; k++)
    {
        for (int m = 0; m < qmm.thecolmuns; m++)
        {
            qmm.element[k][m] = (element[k][m] - value);
        }
    }
    return qmm;
}


// A function to produce a value in  a matrix

template<class MATR2>
Matrix<MATR2>& transpose(Matrix<MATR2>& qmm)
{
    Matrix<MATR2> qmm1(qmm.thecolmuns, qmm.therows);

  for (int k = 0; k < qmm.therows; k++)
        for (int m = 0; m < qmm.thecolmuns; m++)
            qmm1.element[k][m] = qmm.element[m][k];
    for (int k = 0; k < qmm.therows; k++)
        for (int m = 0; m < qmm.thecolmuns; m++)
            qmm.element[k][m] = qmm1.element[k][m];
    return qmm;
}
template<class MATR>
Matrix<MATR>::~Matrix()
{
}
