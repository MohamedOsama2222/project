#include "TheMenu.h"
#include "Matrix.h"
//menu to display the option of matrix
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
        cout << "1- Perform Matrix Addition" <<endl<< "2- Perform Matrix Subtraction" <<endl<< "3- Perform Matrix Multiplication." <<endl <<"4- Matrix Transpose" <<endl<<" 5-enter 5 to exit " << endl;
        cin >> option;
        // switch  case t
        switch (option)
        {
    // case 1 to sum to 2 matrix ( matrix + matrix 2)
        case 1:
            cout << "Enter Your First Matrix : " ;
            cin >> object;
            cout << "Enter Your Second Matrix : " ;
            cin >> qmm2;
            if (object.gettherows()==qmm2.gettherows()&&object.getthecolmuns()== qmm2.getthecolmuns()){
                qmm3 = object + qmm2;
                cout << "first matrix + second matrix equal " <<qmm3;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other) " ; }
            break;
            // case 2 to subtract 2 matrix ( matrix 1 -matrix 2 )
        case 2:
            cout << " Enter first matrix  " ;
            cin >> object;
            cout << "Enter Your Second Matrix : ";
            cin >> qmm2 ;
            if (object.gettherows()== qmm2.gettherows()&& object.getthecolmuns()== qmm2.getthecolmuns()) {
                qmm3 = object - qmm2;
                cout << " first matrix - second matrix = " << qmm3 ;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other)"; }
            break;
        case 3:
            // case 3 to Multiplication 2 matrix ( matrix 1 * matrix 2)
            cout << "Enter  Matrix 1 ";
            cin >> object ;
            cout << "Enter Matrix 2 ";
            cin >> qmm2;
            if (object.gettherows() == qmm2.gettherows()) {
                cout << " first matrix *  secondMatrix = " << (object * qmm2) ;
            }
            else { cout << "the columns and the rows are not equal ( Different from each other)" ; }
            break;
        case 4:
            //case  4 to tronspose the  matrix
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
     getch();
    system("system system system");
}







