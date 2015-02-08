#include <iostream>
#define RANDOM 100
using namespace std;

///@mainpage Test project "Matrix multiplication"
///@author Maxim Shpakovich
///@page Class Matr
///@brief Test brief
/**
 @class Matr
 * Class Matr creates a the two-dimensional matrix
 * of size n*m.
 */
class Matr
{
    int n;
    int m;
    int **matr;

public:

    ///@name Constructor / Constructor with parameters / Destructor
    /// @{
    Matr() {n = 0; m = 0;}
    Matr(int a, int b);
    ~Matr();
    /// @}
    /// @name main functions
    /// @{
    void Multiplication(Matr &ft, Matr &sd);
    void Create(int q, int w);
    void Print_Matr();
    void Fill_in(int a);
    /// @}
    /// @name Modified operators
    /// @{
    Matr operator*(Matr op2); ///< Operator * is owerloaded
    Matr operator=(Matr op2); ///< Operator = is owerloaded
    /// @}
};



int main()
{
    Matr a(2,4), b(4,2),result;
    a.Fill_in(5);
    b.Fill_in(6);
    a.Print_Matr();
    b.Print_Matr();
    result.Multiplication(a,b); /// Matrixes are multiplicated by function.
    result.Print_Matr();
    (a*b).Print_Matr(); /// Matrixes are multiplicated by owerload operator *.
    return 0;
}


/**
 * @brief Matr::Fill_in is the function that fills tha matrix by parameter "a".
 * @param a is integer.
 */
void Matr::Fill_in(int a)
{
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < m; ++j)
            matr[i][j] = a;
}
/**
 * @brief Matr::Create
 * @param q
 * @param w
 */
void Matr::Create(int q, int w)
{
    n = q;
    m = w;
    matr = new int*[n];
    for( int i = 0; i < n; ++i)
        matr[i] = new int [m];
}
/**
 * @brief Matr::Print_Matr prints the matrix on console
 */
void Matr::Print_Matr()
{
    for( int i = 0; i < n; ++i, cout<<endl )
        for( int j = 0; j < m; ++j)
            cout << matr[i][j] << '\t';
    cout << endl;
}
/**
 * @brief Matr::Matr
 * @param a is assigned param "n"
 * @param b is assigned param "m"
 */
Matr::Matr(int a, int b)
{
   n = a;
   m = b;
   matr = new int*[n];
   for( int i = 0; i < n; ++i)
       matr[i] = new int [m];

}
/**
 * @brief Matr::~Matr is a destructor that frees the dynamic memory
 */
Matr::~Matr()
{
   for( int i = 0; i < n; ++i)
       delete[]matr[i];
   delete[]matr;
   //cout<<"destructor"<<endl;
}
/**
 * @function Matr::Multiplication
 * @param ft - first matrix
 * @param sd - second matrix
 */
void Matr::Multiplication(Matr& ft, Matr& sd)
{
   Create(ft.n, sd.m);
   if ( ft.m != sd.n )
   {
       cout << "Matrix sizes aren't correct!!!" << endl;
       exit(1);
   }
   int pt1 = 0, pt2 = 0, x = 0;
   bool done = false;


   while(!done)
   {
       for(int j = 0; j < ft.m; ++j)
           x += ft.matr[pt1][j] * sd.matr[j][pt2];
       matr[pt1][pt2] = x;
       x = 0;
       ++pt2;
       if(pt2 == sd.m) {pt2 = 0; ++pt1;}
       if(pt1 == ft.n) {done = true;}
   }
}
/**
 * @brief Matr::operator *
 * @param op2
 * @return
 */
Matr Matr::operator *(Matr op2)
{
    Matr temp(this->n,op2.m);
    if ( this->m != op2.n )
    {
        cout << "Matrix sizes aren't correct!!!" << endl;
        exit(1);
    }
    int pt1 = 0, pt2 = 0, x = 0;
    bool done = false;


    while(!done)
    {
        for(int j = 0; j < this->m; ++j)
            x += this->matr[pt1][j] * op2.matr[j][pt2];
        temp.matr[pt1][pt2] = x;
        x = 0;
        ++pt2;
        if(pt2 == op2.m) {pt2 = 0; ++pt1;}
        if(pt1 == this->n) {done = true;}
    }
    return temp;
}











