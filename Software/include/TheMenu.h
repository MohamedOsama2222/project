#include "Matrix.h"
#include <conio.h>
using namespace std;
class TheMenu {
public:
    TheMenu();
        template<class MATR>
        void display(Matrix<MATR>& object);
};
#include "TheMenu.h"
template<class MATR>
void TheMenu::display(Matrix<MATR>&object)
{
    cout << "Welcome to your Matrix Calculator" << endl;
    cout << "----------------------------------------" << endl;
    Matrix <MATR>qmm2,qmm3;
    int option;
    bool result = true;

    while (result)
    {
        cout << "1- Perform Matrix Addition" <<endl<< "2- Perform Matrix Subtraction" <<endl<< "3- Perform Matrix Multiplication." <<endl <<"4- Matrix Transpose" <<endl<<"5-enter 5 to exit " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter Your First Matrix : " << endl;
            cin >> object;
            cout << "Enter Your Second Matrix : " << endl;
            cin >> qmm2;
            if (object.gettherows()==qmm2.gettherows()&&object.getthecolmuns()== qmm2.getthecolmuns()){
                qmm3 = object + qmm2;
                cout << "first matrix + second matrix equal " <<qmm3<< endl;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other) " << endl; }
            break;
        case 2:
            cout << " Enter first matrix  " << endl;
            cin >> object;
            cout << "Enter Your Second Matrix : ";
            cin >> qmm2 ;
            if (object.gettherows()== qmm2.gettherows()&& object.getthecolmuns()== qmm2.getthecolmuns()) {
                qmm3 = object - qmm2;
                cout << " first matrix - second matrix = " << qmm3 << endl;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other)"; }
            break;
        case 3:
            cout << "Enter  Matrix 1 ";
            cin >> object ;
            cout << "Enter Matrix 2 ";
            cin >> qmm2;
            if (object.gettherows() == qmm2.gettherows()) {
                cout << " first matrix *  secondMatrix = " << (object * qmm2) << endl;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other)" << endl; }
            break;
        case 4:
            cout << "Enter  Matrix 1" << endl;
            cin >> object ;
            cout << " the  Matrix transpose " << endl;
            cout << transpose(object) << endl << endl;
            break;
        case 5:
            result = false;
            break;
        default:
            continue;
        }
    }
}




