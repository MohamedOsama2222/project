
using namespace std;
template<class MATR>
class Matrix
{// the rows and the columns  and  pointer 2d
private:
	MATR** element;
	int therows ;
	int thecolmuns;
public:
	Matrix();
	// the  Constructor
	Matrix(int therows, int thecolmuns, MATR num[]);
	// the Constructor which create empty Matrix
	Matrix(int therows, int thecolmuns);
    // the copy Constructor
	Matrix(const Matrix<MATR>& thecopy);
	// function to get rows of matrix
	int gettherows();
	// function to get the columns of matrix
	int getthecolmuns();
	//operator >> to make user to input elemrnts
	template<class MATR2>
	 istream& operator>> (istream& theinput, Matrix<MATR2>& qmm);
	//operator << to  to outbut  elements
	template <class MATR2>
	 ostream& operator<< (ostream& theoutbut,const Matrix<MATR2>& qmm);
	// sum matix 1 and matrix 2
	Matrix<MATR> operator+(Matrix<MATR> & qmmm2);
     // this function used to remove the value from matrix 2
	Matrix<MATR> operator-(Matrix<MATR> &qmm2);
	// functiom make use to produse value to matrix( matrix * value)
	Matrix<MATR> operator*(Matrix<MATR> &qmm2);
    // function make user to  sum  value to matrix ( matrix * value  )
	Matrix<MATR> operator+(MATR value);
	// opertor - make the user to remove value of elements of matrix
	Matrix<MATR> operator-(MATR value);
    // opertor - make the user to remove value of elements
	Matrix<MATR> operator*(MATR value);
	// function can make the user to transpose matrix
	template <class MATR2>
	 Matrix<MATR2>& transpose(Matrix<MATR2>&qmm);
	virtual ~Matrix();
};
