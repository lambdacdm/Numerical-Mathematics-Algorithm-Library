#ifndef NUMERICAL_H
#define NUMERICAL_H
#include "polynomial.h"
#include<iomanip>
#include<typeinfo>
#include<functional>
#include<deque>
#include<thread>
#include<tuple>
#include<utility>
using std::deque;
using std::function;
using std::get;
using std::ios;
using std::pair;
using std::ref;
using std::swap;
using std::tuple;
using namespace ply;

namespace nmr{

//-----常量部分-----
const double Machine_Epsilon = pow(2, -52);

//-----声明部分-----

//杂例I
template <class DM>
double Norm(const vector<DM> &, double);
template<class DJ> DJ Abs(DJ);
template <class DJ> DJ Sign(DJ);
template <class DJ> vector<DJ> Range(DJ, DJ,DJ);
template <class DJ> vector<DJ> Range(DJ, DJ);
template <class DJ> vector<DJ> Rand(int);
template <class DJ> DJ Limit(std::function<DJ(DJ)>, DJ);
template <class DJ> DJ N(DJ,int);
inline int Sig(){return rand()%2?1:-1;}//random Sign(+/-)

//矩阵类
template<class DM>
class Matrix
{
public:
    Matrix();
    Matrix(DM);
    Matrix(int,int);
    Matrix(DM, int, int);
    Matrix(const vector<vector<DM>>&, int, int);
    Matrix(const vector<vector<DM>>&);
    Matrix(const vector<vector<DM>> &, const char[]);

    Matrix<DM> &operator=(const Matrix<DM> &);
    DM &operator()(int,int);
    DM operator()(int, int) const;
    DM &operator()(int);
    DM operator()(int) const;
    const vector<DM> &operator[](int);
    template <class DB> friend bool operator==(const Matrix<DB> &, const Matrix<DB> &);
    template<class DB> friend ostream &operator<< (ostream &,const Matrix<DB> &);
    template<class DB> friend Matrix<DB> operator+(const Matrix<DB> &,const Matrix<DB>&);
    template<class DB> friend Matrix<DB> operator-(const Matrix<DB> &,const Matrix<DB>&);
    template <class DB>friend Matrix<DB> operator-(const Matrix<DB> &);
    template<class DB> friend Matrix<DB> operator*(const Matrix<DB> &,const Matrix<DB>&);
    template<class DB> friend Matrix<DB> operator/(const Matrix<DB> &,const Matrix<DB>&);
    template<class DB> friend Matrix<DB> operator^(const Matrix<DB> &,int);
    template <class DB> friend Matrix<DB> operator+(DB, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> operator+(const Matrix<DB>&,DB);
    template <class DB> friend Matrix<DB> operator-(DB, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> operator-(const Matrix<DB>&,DB);
    template <class DB> friend Matrix<DB> operator*(DB, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> operator*(const Matrix<DB>&,DB);
    template<class DB> friend Matrix<DB> operator/(const Matrix<DB> &,DB);
    Matrix<DM> &operator+=(const Matrix<DM> &);
    Matrix<DM> &operator-=(const Matrix<DM> &);

    template <class DB> friend DB Get(const Matrix<DB> &, int, int);
    template <class DB> friend void Make(Matrix<DB> &, int, int, DB);
    template<class DB> friend void Clear(Matrix<DB>&);
    template<class DB> friend void Disp(const Matrix<DB>&);
    template <class DB> friend Matrix<DB> Generate(int, int);
    template <class DB> friend Matrix<DB> Act(std::function<DB(DB)>, const Matrix<DB> &);
    template <class DB> friend Matrix<DB> Act(std::function<DB(DB, DB)>, const Matrix<DB> &, const Matrix<DB> &);
    template <class DB> friend Matrix<DB> Table(std::function<DB(DB)>, const vector<DB>&);
    template<class DB> friend Matrix<DB> Transpose(const Matrix<DB>&); 
    template<class DB> friend vector<DB> Diagonal(const Matrix<DB>&);
    template <class DB> friend Matrix<DB> DiagonalMatrix(const vector<DB> &);
    template <class DB> friend DB Min(const Matrix<DB>&);
    template <class DB> friend DB Max(const Matrix<DB>&);
    template <class DB> friend DB ColumnMin(const Matrix<DB> &,int );
    template <class DB> friend DB ColumnMax(const Matrix<DB> &,int);
    template<class DB> friend int RowSize(const Matrix<DB>&);
    template<class DB> friend int ColumnSize(const Matrix<DB>&);
    template <class DB> friend void Resize(Matrix<DB> &,int,int);
    template <class DB> friend Matrix<DB> SubRow(const Matrix<DB> &, int, int);
    template <class DB> friend Matrix<DB> SubColumn(const Matrix<DB> &, int, int);
    template <class DB> friend Matrix<DB> SubMatrix(const Matrix<DB> &, int, int, int, int);
    template <class DB> friend void ReplaceMatrix(Matrix<DB> &, int, int, int, int, const Matrix<DB> &);
    template <class DB> friend void DeleteRow(Matrix<DB> &,int n);
    template <class DB> friend void ReplaceRow(Matrix<DB> &, int n,const Matrix<DB>&);
    //解线性方程组
    template<class DB> friend Matrix<DB> RowCat(const Matrix<DB>&, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> RowCat(const vector<Matrix<DB>>&);
    template <class DB> friend Matrix<DB> ColumnCat(const Matrix<DB> &, const Matrix<DB> &);
    template<class DB> friend void SwapRow(Matrix<DB>&,int,int);
    template <class DB> friend Matrix<DB> USplit(const Matrix<DB>&);
    template <class DB> friend vector<Matrix<DB>> GaussianElimination(const Matrix<DB>&,const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LUCompactDecomposition(const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LUPCompactDecomposition(const Matrix<DB>&, vector<int> &, int&, DB&);
    template <class DB> friend Matrix<DB> GaussianElimination(const Matrix<DB>&);
    template <class DB> friend int MatrixRank(const Matrix<DB>&);
    template <class DB> friend DB Det(const Matrix<DB>&);
    template <class DB> friend vector<Matrix<DB>> LUDecomposition(const Matrix<DB>&);
    template <class DB> friend vector<Matrix<DB>> LUPDecomposition(const Matrix<DB> &);
    template <class DB> friend vector<vector<DB>> Tridiagonal(const Matrix<DB>&);
    template <class DB> friend vector<vector<DB>> TridiagonalSeparation(const vector<vector<DB>>&);
    template <class DB> friend Matrix<DB> CholeskyCompactDecomposition(const Matrix<DB>&);
    template <class DB> friend vector<Matrix<DB>> CholeskyDecomposition(const Matrix<DB> &);
    template <class DB> friend vector<Matrix<DB>> JacobiIterationMatrix(const Matrix<DB>&, const Matrix<DB>&);
    template <class DB> friend vector<Matrix<DB>> GSIterationMatrix(const Matrix<DB>&, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LUSolve(const Matrix<DB>&,const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LUPSolve(const Matrix<DB>&,const vector<int>&,const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LSolve(const Matrix<DB>&,const Matrix<DB>&);
    template <class DB> friend Matrix<DB> USolve(const Matrix<DB>&,const Matrix<DB>&);
    template <class DB> friend Matrix<DB> TridiagonalSolve(const vector<vector<DB>>&, const Matrix<DB>&);
    template <class DB> friend Matrix<DB> Iteration(const Matrix<DB>&, const Matrix<DB>&);
    template<class DB> friend Matrix<DB> LinearSolve(const Matrix<DB>&,const Matrix<DB>&,string,double);
    template<class DB> friend Matrix<DB> LinearSolve(const Matrix<DB>&,const Matrix<DB>&,string);
    template<class DB> friend Matrix<DB> LinearSolve(const Matrix<DB>&,const Matrix<DB>&);
    //求逆
    template<class DB> friend Matrix<DB> Eye(int);
    template<class DB> friend Matrix<DB> Inverse(const Matrix<DB>&);
    //范数、条件数
    template <class DB> friend DB Trace(const Matrix<DB>&);
    template <class DB> friend DB VectorNorm(const Matrix<DB> &, double);
    template <class DB> friend DB Norm(const Matrix<DB>&, double);
    template <class DB> friend DB Norm(const Matrix<DB>&, string);
    template <class DB> friend double Cond(const Matrix<DB>&, double);
    template <class DB> friend double Cond(const Matrix<DB>&, string);
    //插值
    template <class DB> friend vector<std::function<DB(DB)>> LagrangeBasis(const Matrix<DB> &);
    template <class DB> friend DB LBasisToInterp(const vector<std::function<DB(DB)>>&,const Matrix<DB> &,DB);
    template <class DB> friend Matrix<DB> DifferenceQuotientTable(const Matrix<DB> &);
    template <class DB> friend Matrix<DB> DividedDifferenceTable(const Matrix<DB> &);
    template <class DB> friend DB DifferenceQuotient(const Matrix<DB> &);
    template <class DB> friend DB DifferenceQuotient(std::function<DB(DB)>, const Matrix<DB> &);
    template <class DB> friend DB DQTableToInterp(const Matrix<DB> &, const Matrix<DB> &,DB);
    template <class DB> friend DB DDTableToInterp(const Matrix<DB> &, const Matrix<DB> &,DB);
    template <class DB> friend DB _2P3DHermiteInterp(const Matrix<DB> &,int i,int j,DB);
    template <class DB> friend DB _3P3DHermiteInterp(const Matrix<DB> &,DB);
    template <class DE> friend Matrix<DE> SplineSlope(const Matrix<DE> &);
    template <class DE> friend DE Interpolation(const Matrix<DE> &,DE,string);
    template <class DE> friend DE Interpolation(const Matrix<DE> &,DE);
    template <class DE> friend Matrix<DE> Interpolation(const Matrix<DE> &A, const Matrix<DE> &x, string);
    template <class DE> friend std::function<DE(DE)> Interpolation(const Matrix<DE> &,string);
    //拟合与逼近
    template <class DB> friend Matrix<DB> PseudoInverse(const Matrix<DB>&);
    template <class DB> friend Matrix<DB> LeastSquares(const Matrix<DB>&, const Matrix<DB>&);
    template <class DB> friend Polynomial<DB> PolyFit(const Matrix<DB> &, const vector<Polynomial<DB>> &);
    template <class DB> friend Polynomial<DB> PolyFit(const Matrix<DB>&,int);
    template <class DB> friend Polynomial<DB> PolyFit(std::function<DB(DB)>,const vector<Polynomial<DB>>&,DB,DB);
private:
    vector<vector<DM>> value;
    int row_num;
    int column_num;
};
template <class DB> const Matrix<DB> EmptyMatrix = Matrix<DB>(0, 0);

//积分
template <class DI> DI Integrate(std::function<DI(DI)>,DI,DI,string);
template <class DI> DI Integrate(std::function<DI(DI)>,DI,DI);
template <class FS> FS FourierSinCoefficient(const std::function<FS(FS)> &, int32_t, FS);
template <class FS> FS FourierCosCoefficient(const std::function<FS(FS)> &, int32_t, FS);

//微分
template <class DD> DD D(std::function<DD(DD)>, DD);

//方程(组)求根
template <class DD> DD Iteration(std::function<DD(DD)>, DD);
template<class DD> DD FindRoot(std::function<DD(DD)>, DD,DD);
template <class DD> DD FindRoot(std::function<DD(DD)>, DD,string);
template <class DD> DD FindRoot(std::function<DD(DD)>, DD);
template <class DD> DD FindRoot(std::function<DD(DD)>, DD,string,int);
template <class DD> DD Sqrt(DD);
template <> double Sqrt(double);

//常微分方程
template<class DS,class DO> DO DSolve(std::function<DO(DS,DO)>,const pair<DS,DO>&,DS,string);
template <class DS, class DO>DO DSolve(std::function<DO(DS, DO)>, const pair<DS, DO> &, DS, int);
template <class DS, class DO> DO DSolve(std::function<DO(DS, DO)>, const pair<DS, DO> &, DS);
template <class DS, class DO> 
std::function<DO(DS)> DSolve(std::function<DO(DS, DO)>, const pair<DS, DO> &, string);
template <class DS, class DO>
std::function<DO(DS)> DSolve(std::function<DO(DS, DO)>, const pair<DS, DO> &);


//-----定义部分-----


//杂例I
template<class DM> double Norm(const vector<DM> &a, double p)
{
    if(p==INFINITY)
    {
        double max = 0;
        for (long long unsigned int i = 0; i < a.size();++i)
        {
            if(Abs(a[i])>max)
                max = Abs(a[i]);
        }
        return max;
    }
    double s = 0;
    for (long long unsigned int i = 0; i < a.size();++i)
    {
        s += pow(Abs(a[i]), p);
    }
    s = pow(s, 1 / p);
    return s;
}
template<class DJ> DJ Abs(DJ a)
{
    if(a>0)
        return a;
    return -a;
}
template<class DJ> DJ Sign(DJ a)
{
    if(a>0)
        return 1;
    if(a<0)
        return -1;
    return 0;
}
template <class DJ> vector<DJ> Range(DJ a, DJ b,DJ c)
{
    vector<DJ> r;
    DJ s = a;
    while(s<=b)
    {
        r.emplace_back(s);
        s = s + DJ(c);
    }
    return r;
}
template <class DJ> vector<DJ> Range(DJ a, DJ b)
{
    return Range(a, b, DJ(1));
}
template <class DJ> vector<DJ> Rand(int a)
{
    vector<DJ> r(a);
    for (int i = 0;i<a;++i)
        r[i]=std::rand()*Sig();
    return r;
}
template <class DJ> DJ Limit(std::function<DJ(DJ)> f, DJ x0)
{
    const DJ h = 1e-7;
    return 0.5 * (f(x0+h)+f(x0-h));
}
template <class DJ> DJ N(DJ a,int n)
{
    cout << std::setprecision(n) << a << '\n';
    return a;
}

//矩阵类
template<class DB> Matrix<DB>::Matrix()
{
    row_num=1;
    column_num = 1;
    value = {{0}};
}
template<class DB> Matrix<DB>::Matrix(DB a)
{
    row_num = 1;
    column_num = 1;
    value ={{a}};
}
template<class DB> Matrix<DB>::Matrix(int r,int c)
{
    row_num=r;
    column_num=c;
    vector<DB> rr(c);
    for(int i=0;i<r;++i)
    {
        value.push_back(rr);
    }
}
template<class DB> Matrix<DB>::Matrix (DB a,int r,int c)
{
    row_num=r;
    column_num=c;
    vector<DB> rr(c, a);
    for(int i=0;i<r;++i)
    {
        value.push_back(rr);
    }
}
template<class DB> Matrix<DB>::Matrix (const vector<vector<DB>> &a,int r,int c)
{
    row_num=r;
    column_num = c;
    value = a;
}
template<class DB> Matrix<DB>::Matrix (const vector<vector<DB>> &a)
{
    row_num = a.size();
    column_num = a[0].size();
    value = a;
}
template<class DB> Matrix<DB>::Matrix (const vector<vector<DB>> &a, const char [])
{
    row_num = a.size();
    column_num = a[0].size();
    value = a;
}
template<class DB> Matrix<DB>& Matrix<DB>::operator=(const Matrix<DB> &b)
{
    row_num = b.row_num;
    column_num = b.column_num;
    value = b.value;
    return *this;
}
template<class DB> DB& Matrix<DB>::operator()(int r,int c)
{
    if(r>=row_num || c>=column_num)
    {
        cerr << "错误：矩阵下标越界" << '\n';
        return value[0][0];
    }
    return value[r][c];
}
template<class DB> DB Matrix<DB>::operator()(int r,int c) const
{
    if(r>=row_num || c>=column_num)
    {																	
        cerr << "错误：矩阵下标越界" << '\n';
        return value[0][0];
    }
    return value[r][c];
}
template<class DB> DB& Matrix<DB>::operator()(int r)
{
    return (*this)(r,0);
}
template<class DB> DB Matrix<DB>::operator()(int r) const
{
    return (*this)(r,0);
}
template<class DB> const vector<DB>& Matrix<DB>::operator[](int r)
{
    if(r>=row_num)
    {
        cerr << "错误：矩阵下标越界" << '\n';
        return value[0];
    }
    return value[r];
}
template<class DB> int RowSize(const Matrix<DB> &a)
{
    return a.row_num;
}
template<class DB> int ColumnSize(const Matrix<DB> &a)
{
    return a.column_num;
}
template <class DB> bool operator==(const Matrix<DB> &A, const Matrix<DB> &B)
{
    int r=A.row_num;
    int c=A.column_num;
    if(r!=B.row_num ||c!=B.column_num)
        return false;
    for (int i = 0; i < r;++i)
        if(A.value[i]!=B.value[i])
            return false;
    return true;
}
template<class DB> ostream &operator<< (ostream &os,const Matrix<DB> &a)
{
    for (int i = 0;i<a.row_num;++i)
    {
        os << '[' << a.value[i][0];
        for (int j = 1;j<a.column_num;++j)
        {
            os <<", "<<a.value[i][j];
        }
        os << "]" << '\n';
    }
    return os;
}
template<class DB> Matrix<DB> operator+(const Matrix<DB> &a,const Matrix<DB>&b)
{
    if(a.row_num!=b.row_num ||a.column_num!=b.column_num)
    {
        cerr << "错误：规格不同的矩阵不能相加。" << '\n';
        return a;
    }
    int r = a.row_num;
    int c = a.column_num;
    Matrix<DB> d(r,c);
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            d.value[i][j] = a.value[i][j] + b.value[i][j];
        }
    }
    return d;
}
template<class DB> Matrix<DB> operator-(const Matrix<DB> &a,const Matrix<DB>&b)
{
    if(a.row_num!=b.row_num ||a.column_num!=b.column_num)
    {
        cerr << "错误：规格不同的矩阵不能相减。" << '\n';
        return a;
    }
    int r = a.row_num;
    int c = a.column_num;
    Matrix<DB> d(r,c);
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            d.value[i][j] = a.value[i][j] - b.value[i][j];
        }
    }
    return d;
}
template <class DB> Matrix<DB> operator-(const Matrix<DB> &b)
{
    int r = b.row_num;
    int c = b.column_num;
    Matrix<DB> d(r,c);
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            d.value[i][j] = DB(0)-b.value[i][j];
        }
    }
    return d;
}
template<class DB> Matrix<DB> operator*(const Matrix<DB> &a,const Matrix<DB>&b)
{
    if(a.column_num!=b.row_num)
    {
        cerr << "错误：矩阵相乘时，前一个矩阵的列数必须等于后一个矩阵的行数。" << '\n';
        return a;
    }
    int p=a.row_num;
    int q=a.column_num;
    int r = b.column_num;
    Matrix<DB> d(p, r);
    int kernel =4;
    int pend = p / kernel * kernel;
    int rend = r / kernel * kernel;
    for (int i = 0; i < pend; i+=kernel) 
        for (int k = 0; k < q; ++k) 
        {
            for (int j= 0; j< rend; j+=kernel) 
                for (int iker = 0; iker < kernel;++iker)
                    for (int jker = 0; jker < kernel; ++jker)
                        d.value[i + iker][j + jker] += a.value[i + iker][k] * b.value[k][j + jker]; 
            for (int iker = 0; iker < kernel;++iker)
                for (int jker= rend; jker <r; ++jker)
                    d.value[i + iker][jker] += a.value[i + iker][k] * b.value[k][jker]; 
        }                                  
    for (int k = 0; k < q; ++k) 
    {
        for (int j= 0; j< rend; j+=kernel) 
            for (int iker =pend; iker < p;++iker)
                for (int jker = 0; jker < kernel; ++jker)
                    d.value[iker][j + jker] += a.value[iker][k] * b.value[k][j + jker]; 
        for (int iker = pend; iker < p;++iker)
            for (int jker= rend; jker <r; ++jker)
                d.value[iker][jker] += a.value[iker][k] * b.value[k][jker]; 
    }  
    return d;
}
template <class DC> Matrix<DC> operator+(DC r, const Matrix<DC> &a)
{
    Matrix<DC> d(a.row_num,a.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0; j < a.column_num;++j)
        {
            d.value[i][j] = r+a.value[i][j];
        }
    }
    return d;
}
template <class DC> Matrix<DC> operator+(const Matrix<DC> &a,DC r)
{
    return r + a;
}
template <class DC> Matrix<DC> operator-(DC r,const Matrix<DC> &a)
{
    Matrix<DC> d(a.row_num,a.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0; j < a.column_num;++j)
        {
            d.value[i][j] = r-a.value[i][j];
        }
    }
    return d;
}
template <class DC> Matrix<DC> operator-(const Matrix<DC> &a,DC r)
{
    Matrix<DC> d(a.row_num,a.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0; j < a.column_num;++j)
        {
            d.value[i][j] = a.value[i][j]-r;
        }
    }
    return d;
}
template <class DC> Matrix<DC> operator*(DC r, const Matrix<DC> &a)
{
    Matrix<DC> d(a.row_num,a.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0; j < a.column_num;++j)
        {
            d.value[i][j] = r * a.value[i][j];
        }
    }
    return d;
}
template <class DC> Matrix<DC> operator*(const Matrix<DC> &a,DC r)
{
    return r * a;
}
template<class DB> Matrix<DB> operator/(const Matrix<DB> &a,DB r)
{
    Matrix<DB> d(a.row_num,a.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0; j < a.column_num;++j)
        {
            d.value[i][j] = a.value[i][j]/r;
        }
    }
    return d;
}
template<class DB> Matrix<DB> &Matrix<DB>::operator+=(const Matrix<DB> &b)
{
    *this = *this + b;
    return *this;
}
template<class DB> Matrix<DB> &Matrix<DB>::operator-=(const Matrix<DB> &b)
{
    *this = *this - b;
    return *this;
}
template <class DB> DB Get(const Matrix<DB> &A, int r, int c)
{
    return A.value[r][c];
}
template <class DB> void Make(Matrix<DB> &A, int r, int c, DB val)
{
    if(r<0 || r>=A.row_num || c<0 || c>=A.column_num)
    {
        cerr<<"错误：矩阵下标访问越界\n";
        return;
    }
    A.value[r][c]=val;
}
template<class DB> void Clear(Matrix<DB> &a)
{
    a.value.clear();
}
template<class DB> void Disp(const Matrix<DB> &a)
{
    cout << a << '\n';
}
template <class DB> Matrix<DB> Generate(int r, int c)
{
    Matrix<DB> G(r,c);
    for(int i=0;i<r;++i)
        G.value[i] = Rand<DB>(c);
    return G;
}
template <class DB> Matrix<DB> Act(std::function<DB(DB)> f, const Matrix<DB> &A)
{
    Matrix<DB> r(A.row_num,A.column_num);
    for (int i = 0; i < A.row_num;++i)
        for (int j = 0; j < A.column_num;++j)
            r.value[i][j] = f(A.value[i][j]);
    return r;
}
template <class DB> 
Matrix<DB> Act(std::function<DB(DB, DB)> f, const Matrix<DB> &A, const Matrix<DB> &B)
{
    int r=A.row_num;
    int c=A.column_num;
    if(r!=B.row_num || c!=B.column_num)
    {
        cerr<<"错误：两个矩阵规格不同，无法作用"<<'\n';
        return A;
    }
    Matrix<DB> R(r,c);
    for (int i = 0; i < r;++i)
        for (int j = 0; j <c;++j)
            R.value[i][j] = f(A.value[i][j],B.value[i][j]);
    return R;
}
template <class DB> Matrix<DB> Table(std::function<DB(DB)> f,const vector<DB>& r)
{
    vector<DB> vt;
    for(auto i:r)
        vt.push_back(f(i));
    Matrix<DB> M({vt});
    return M;
}
template<class DB> Matrix<DB> Transpose(const Matrix<DB> &a)
{
    Matrix<DB> T(a.column_num, a.row_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j =0; j<a.column_num;++j)
            T.value[j][i] = a.value[i][j];
    }
    return T;
}
template<class DB> vector<DB> Diagonal(const Matrix<DB> &a)
{
    int n = a.row_num<a.column_num?a.row_num:a.column_num;
    vector<DB> d(n);
    for (int i = 0; i < n;++i)
        d[i]=a.value[i][i];
    return d;
}
template<class DB> Matrix<DB> DiagonalMatrix(const vector<DB> &d)
{
    int n = d.size();
    Matrix<DB> A(n,n);
    for(int i=0;i<n;++i)
        A.value[i][i]=d[i];
    return A;
}
template <class DB> DB Min(const Matrix<DB> &a)
{
    int rows=a.row_num;
    int columns=a.column_num;
    if(rows==0 || columns==0)
        return DB(0);
    DB minimum = a.value[0][0];
    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            if(a.value[i][j]<minimum)
                minimum=a.value[i][j];
    return minimum;
}
template <class DB> DB Max(const Matrix<DB> &a)
{
    int rows=a.row_num;
    int columns=a.column_num;
    if(rows==0 || columns==0)
        return DB(0);
    DB maximum = a.value[0][0];
    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            if(a.value[i][j]>maximum)
                maximum=a.value[i][j];
    return maximum;
}
template <class DB> DB ColumnMin(const Matrix<DB> &a,int j)
{
    int rows=a.row_num;
    int columns=a.column_num;
    if(j<0 || j>=columns)
    {
        std::cerr<<"错误：列数超出矩阵范围。\n";
        return DB(0);
    }
    DB minimum=a.value[0][j];
    for(int i=1;i<rows;++i)
        if(a.value[i][j]<minimum)
            minimum=a.value[i][j];
    return minimum;
}
template <class DB> DB ColumnMax(const Matrix<DB> &a,int j)
{
    int rows=a.row_num;
    int columns=a.column_num;
    if(j<0 || j>=columns)
    {
        std::cerr<<"错误：列数超出矩阵范围。\n";
        return DB(0);
    }
    DB maximum=a.value[0][j];
    for(int i=1;i<rows;++i)
        if(a.value[i][j]>maximum)
            maximum=a.value[i][j];
    return maximum;
}
template<class DB> Matrix<DB> Eye(int n)
{
    if(n<0)
    {
        cerr << "错误：矩阵的规模必须非负。" << '\n';
        Matrix<DB> e(1, 1);
        return e;
    }
    Matrix<DB> e(n, n);
    for (int i = 0; i < n;++i)
    {
        e.value[i][i] = 1;
    }
    return e;
}
template <class DB> void Resize(Matrix<DB> &A,int r,int c)
{
    if(r<A.row_num)
        A.value.resize(r);
    if(r>A.row_num)
        for (int i = A.row_num; i < r;++i)
            A.value.emplace_back(vector<DB>(c));
    if(c==A.column_num)
        return;
    for (auto item : A.value)
        item.resize(c);
    A.row_num=r;
    A.column_num=c;
}
template <class DB> Matrix<DB> SubRow(const Matrix<DB> &A, int a, int b)
{
    Matrix<DB> r(b-a+1,A.column_num);
    for (int i = a; i <= b;++i)
        r.value[i-a]=A.value[i];
    return r;
}
template <class DB> Matrix<DB> SubColumn(const Matrix<DB> &A, int a, int b)
{
    Matrix<DB> r(A.row_num,b-a+1);
    for(int i=0;i<A.row_num;++i)
        for(int j=a;j<=b;++j)
            r.value[i][j-a]=A.value[i][j];
    return r;
}
template <class DB> Matrix<DB> SubMatrix(const Matrix<DB> &A, int lur, int luc, int rdr, int rdc)
{
    //左上点的坐标：(lur,luc)，右下点的坐标：(rdr,rdc)
    Matrix<DB> r(rdr - lur + 1, rdc - luc + 1);
    for (int i = lur; i <= rdr;++i)
    {
        for (int j = luc; j <= rdc;++j)
        {
            r.value[i - lur][j - luc] = A.value[i][j];
        }
    }
    return r;
}
template <class DB> void ReplaceMatrix(Matrix<DB> &A,int lur,int luc,int rdr,int rdc,const Matrix<DB> &R)
{
    if(R.row_num!=rdr-lur+1 || R.column_num!=rdc-luc+1)
        cerr<<"错误：替换矩阵的规格必须与指定的区域规格相同"<<'\n';
    for(int i=lur;i<=rdr;++i)
        for(int j=luc;j<=rdc;++j)
            A.value[i][j] = R.value[i - lur][j - luc];
}
template <class DB> void DeleteRow(Matrix<DB> &A,int n)
{
    if(n<0||n>=A.row_num)
    {
        cerr<<"错误：矩阵行数越界"<<'\n';
        return ;
    }
    --A.row_num;
    A.value.erase(A.value.begin() + n);
}
template <class DB> void ReplaceRow(Matrix<DB> &A,int n,const Matrix<DB> &B)
{
    if(n<0||n>=A.row_num)
    {
        cerr<<"错误：矩阵行数越界"<<'\n';
        return ;
    }
    if(B.row_num==0)
    {
        DeleteRow(A, n);
        return;
    }
    A.value[n] = B.value[0];
}
template<class DB> void _MatProd(const Matrix<DB> &A,const Matrix<DB> &B,Matrix<DB> &C)
{
    C = A * B;
}
/*template<class DB> Matrix<DB> ThreadMatProd(const Matrix<DB> &A,const Matrix<DB> &B)
{
    int p=RowSize(A);
    int q=RowSize(B);
    int r=ColumnSize(B);
    int halfp=p/2;
    int halfq=q/2;
    int halfr=r/2;
    Matrix<DB> C(p, r);
    const Matrix<DB> &ALU=SubMatrix(A,0,0,halfp-1,halfq-1);
    const Matrix<DB> &ARU = SubMatrix(A, 0,halfq, halfp- 1, q - 1);
    const Matrix<DB> &ALD=SubMatrix(A,halfp,0,p-1,halfq-1);
    const Matrix<DB> &ARD = SubMatrix(A, halfp, halfq, p - 1, q- 1);
    const Matrix<DB> &BLU=SubMatrix(B,0,0,halfq-1,halfr-1);
    const Matrix<DB> &BRU = SubMatrix(B, 0,halfr, halfq - 1, r- 1);
    const Matrix<DB> &BLD=SubMatrix(B,halfq,0,q-1,halfr-1);
    const Matrix<DB> &BRD = SubMatrix(B,halfq, halfr, q- 1,r- 1);
    Matrix<DB> LULU, RULD, LURU, RURD, LDLU, RDLD, LDRU, RDRD;
    thread t1(_MatProd<DB>,ref(ALU),ref(BLU),ref(LULU));
    thread t2(_MatProd<DB>,ref(ARU),ref(BLD),ref(RULD));
    thread t3(_MatProd<DB>,ref(ALU),ref(BRU),ref(LURU));
    thread t4(_MatProd<DB>,ref(ARU),ref(BRD),ref(RURD));
    thread t5(_MatProd<DB>,ref(ALD),ref(BLU),ref(LDLU));
    thread t6(_MatProd<DB>,ref(ARD),ref(BLD),ref(RDLD));
    thread t7(_MatProd<DB>,ref(ALD),ref(BRU),ref(LDRU));
    thread t8(_MatProd<DB>,ref(ARD),ref(BRD),ref(RDRD));
    t1.join();t2.join();t3.join();t4.join();
    t5.join();t6.join();t7.join();t8.join();
    return ColumnCat(RowCat(LULU+RULD,LURU+RURD),RowCat(LDLU+RDLD,LDRU+RDRD));
}*/

//函数形式转换
template <class OT, class IT> function<OT(Matrix<IT>)> MatrizeInput(const function<OT(IT)> &f)
{
    return [&](Matrix<IT> M)
    { return f(Get(M, 0, 0)); };
}
template <class OT, class IT> function<OT(Matrix<IT>)> MatrizeInputs
(const function<OT(IT,IT)> &f)
{
    return [&](Matrix<IT> M)
    { return f(Get(M, 0, 0), Get(M, 1, 0)); };
}
template <class OT, class IT> function<OT(Matrix<IT>)> MatrizeInputs
(const function<OT(IT,IT,IT)> &f)
{
    return [&](Matrix<IT> M)
    { return f(Get(M, 0, 0), Get(M, 1, 0), Get(M, 2, 0)); };
}
template <class OT, class IT> function<OT(Matrix<IT>)> MatrizeInputs
(const function<OT(IT,IT,IT,IT)> &f)
{
    return [&](Matrix<IT> M)
    { return f(Get(M, 0, 0), Get(M, 1, 0), Get(M, 2, 0), Get(M, 3, 0)); };
}

//迹、向量范数
template <class DB> DB Trace(const Matrix<DB> &a)
{
    if(a.row_num!=a.column_num)
    {
        cerr << "只有方阵才有迹！" << '\n';
        return 0;
    }
    DB s = 0;
    for (int i = 0; i < a.row_num;++i)
    {
        s += a.value[i][i];
    }
    return s;
}
template <class DB> DB VectorNorm(const Matrix<DB> &a,double p)
{
    int n=RowSize(a);
    DB s = 0;
    for(int i=0;i<n;++i)
    {
        s += pow(Abs(Get(a, i, 0)), p);
    }
    return pow(s, DB(1) / p);
}
//解线性方程组
template<class DB> Matrix<DB> RowCat(const Matrix<DB> &a,const Matrix<DB> &b)
{
    if(a.row_num!=b.row_num)
    {
        cerr << "错误：行数不相等的两个矩阵无法行连接。" << '\n';
        return a;
    }
    Matrix<DB> c(a.row_num, a.column_num+b.column_num);
    for (int i = 0; i < a.row_num;++i)
    {
        for (int j = 0;j<a.column_num;++j)
        {
            c.value[i][j] = a.value[i][j];
        }
        for (int j = a.column_num; j < a.column_num + b.column_num;++j)
        {
            c.value[i][j] = b.value[i][j - a.column_num];
        }
    }
    return c;
}
template <class DB> Matrix<DB> RowCat(const vector<Matrix<DB>> &a)
{
    Matrix<DB> r=a[0];
    for (long long unsigned int i = 1;i<a.size();++i)
    {
        r=RowCat(r, a[i]);
    }
    return r;
}
template <class DB> Matrix<DB> ColumnCat(const Matrix<DB> &a, const Matrix<DB> &b)
{
    if(a.column_num!=b.column_num)
    {
        cerr << "错误：列数不相等的两个矩阵无法列连接。" << '\n';
        return a;
    }
    vector<vector<DB>> r = a.value;
    for (int i = 0; i < b.row_num;++i)
        r.emplace_back(b.value[i]);
    return Matrix<DB>(r);
}
template<class DB> void SwapRow(Matrix<DB> &m,int a,int b)
{
    if(a==b)
    {
        return;
    }
    vector<DB> temp;
    temp=m.value[a];
    m.value[a]=m.value[b];
    m.value[b] = temp;
}
template <class DB> Matrix<DB> USplit(const Matrix<DB> &A)
{
    if(A.row_num!=A.column_num)
    {
        cerr << "错误：只有方阵才能进行上三角部分分割。" << '\n';
        return A;
    }
    int n=A.row_num;
    Matrix<DB> U(n,n);
    for (int i = 0; i < n;++i)
    {
        for (int j = i + 1; j < n;++j)
        {
            U.value[i][j] = -A.value[i][j];
        }
    }
    return U;
}
template<class DB> Matrix<DB> LSolve(const Matrix<DB> &L,const Matrix<DB> &b)
{
    int n = L.row_num;
    int m = b.column_num;
    Matrix<DB> y(n, m);
    DB s = 0;
    for (int j = 0; j < m;++j)
    {
        for (int i = 0; i < n;++i)
        {
            s = 0;
            for (int k = 0; k < i;++k)
            {
                s += L.value[i][k] *y.value[k][j];
            }
            y.value[i][j] = (b.value[i][j] - s)/L.value[i][i];
        }
        
    }
    return y;
}
template<class DB> Matrix<DB> USolve(const Matrix<DB> &U,const Matrix<DB> &y)
{
    int n = U.row_num;
    int m = y.column_num;
    Matrix<DB> x(n,m);
    DB s = 0;
    for (int j = 0; j < m;++j)
    {
        for (int i = n-1; i>=0;--i)
        {
            s = 0;
            for (int k =i+1 ; k <n;++k)
            {
                s += U.value[i][k] * x.value[k][j];
            }
            x.value[i][j] = (y.value[i][j] - s) / U.value[i][i];
        }
    }
    return x;
}
template <class DB> vector<Matrix<DB>> GaussianElimination(const Matrix<DB> &A, const Matrix<DB> &b)
{
    Matrix<DB> GA = A;
    Matrix<DB> Gb = b;
    DB epsilon = 1e-14;
    int n=GA.row_num;
    int m = Gb.column_num;
    DB max = 0;
    int maxposition = 0;
    DB pivot=1;//主元
    DB multiplicator=1;//乘数
    for(int i=0;i<n;++i)
    {
        max = Abs(GA.value[i][i]);
        maxposition = i;
        for (int j = i+1; j < n;++j)
        {
            if(Abs(GA.value[j][i])>max)
            {
                max = Abs(GA.value[j][i]);
                maxposition = j;
            }
        }
        if(max<=epsilon)
        {
            return {GA,Gb};
        }
        SwapRow(GA, i, maxposition);
        SwapRow(Gb, i, maxposition);
        pivot = GA.value[i][i];
        for(int k=i+1;k<n;++k)
        {
            multiplicator = GA.value[k][i]/pivot;
            for (int j = i; j < n;++j)
            {
                GA.value[k][j] = GA.value[k][j] - multiplicator * GA.value[i][j];
            }
            for (int j = 0; j < m;++j)
            {
                Gb.value[k][j] = Gb.value[k][j] - multiplicator * Gb.value[i][j];
            }
        }
    }
    return {GA,Gb};
}
template <class DB> Matrix<DB> LUCompactDecomposition(const Matrix<DB> &A)
{
    if(A.row_num!=A.column_num)
    {
        cerr << "错误：只有方阵才能进行LU分解。" << '\n';
        return A;
    }
    int n = A.row_num;
    Matrix<DB> LU = A;
    DB s = 0;
    for (int i = 0; i < n;++i)
    {
        if(LU.value[i][i]==0)
        {
            cerr << "错误：有一个顺序主子式等于0，不能LU分解。" << '\n';
            return A;
        }
        for (int j = i; j < n;++j)
        {
            s = 0;
            for (int k = 0; k < i;++k)
            {
                s += LU.value[i][k] * LU.value[k][j];
            }
            LU.value[i][j] = LU.value[i][j] - s;
        }
        for (int t = i + 1; t < n;++t)
        {
            s = 0;
            for (int k = 0; k < i;++k)
            {
                s += LU.value[t][k] * LU.value[k][i];
            }
            LU.value[t][i] = (LU.value[t][i] - s) / LU.value[i][i];
        }
    }
    return LU;
}
template <class DB> Matrix<DB> LUPCompactDecomposition(const Matrix<DB> &A, vector<int> &pi, int &rank, DB &det)
{
    Matrix<DB> LU;
    if(A.row_num>A.column_num)
        LU = Transpose(A);
    else
        LU = A;
    DB epsilon = 1e-14;
    int n=LU.row_num;
    int m = LU.column_num;
    DB max = 0;
    int maxposition = 0;
    DB pivot=1;//主元
    DB multiplicator=1;//乘数
    det = 1;
    for (int i = 0; i < n;++i)
        pi.push_back(i);
    for(int i=0;i<n;++i)
    {
        max = Abs(LU.value[i][i]);
        maxposition = i;
        for (int j = i+1; j < n;++j)
        {
            if(Abs(LU.value[j][i])>max)
            {
                max = Abs(LU.value[j][i]);
                maxposition = j;
            }
        }
        if(max<=epsilon)
        {
            rank = i;
            det = 0;
            return LU;
        }
        SwapRow(LU, i, maxposition);
        swap(pi[i], pi[maxposition]);
        pivot = LU.value[i][i];
        det =det*pivot;
        for(int k=i+1;k<n;++k)
        {
            multiplicator = LU.value[k][i]/pivot;
            for (int j = i; j < m;++j)
            {
                LU.value[k][j] = LU.value[k][j] - multiplicator * LU.value[i][j];
            }
            LU.value[k][i] = multiplicator;
        }
    }
    rank = n;
    return LU;
}
template<class DB> vector<Matrix<DB>> LUDivideConquer(const Matrix<DB> &A,unsigned n,const Matrix<DB> &Id)
{
    if(n==0)
    {
        cerr << "错误：进行LU分解时，矩阵的大小至少是1阶的" <<"\n";
        return {A, A};
    }
    if(n==1)
        return {Id, A};
    unsigned halfn = n >> 1;
    const auto &A11 = SubMatrix(A, 0, 0, halfn - 1, halfn - 1);
    const auto &A12 = SubMatrix(A, 0, halfn, halfn-1, n - 1);
    const auto &A21 = SubMatrix(A, halfn, 0, n - 1, halfn - 1);
    const auto &A22 = SubMatrix(A, halfn, halfn, n - 1, n - 1);
    const auto &L11U11 = LUDivideConquer(A11, halfn,Id);
    const auto &L11=L11U11[0];
    const auto &U11=L11U11[1];
    const auto &U12 = LSolve(L11, A12);
    const auto &L21 = Transpose(LSolve(Transpose(U11), Transpose(A21)));
    const auto &L22U22 = LUDivideConquer(A22 - L21 * U12,n-halfn,Id);
    const auto &L22=L22U22[0];
    const auto &U22=L22U22[1];
    Matrix<DB> L(n,n);
    Matrix<DB> U(n,n);
    ReplaceMatrix(L, 0, 0, halfn - 1, halfn - 1, L11);
    ReplaceMatrix(L, halfn, 0, n - 1, halfn - 1, L21);
    ReplaceMatrix(L, halfn, halfn, n - 1, n - 1, L22);
    ReplaceMatrix(U, 0, 0, halfn - 1, halfn - 1, U11);
    ReplaceMatrix(U, 0, halfn, halfn - 1, n - 1, U12);
    ReplaceMatrix(U, halfn, halfn, n - 1, n - 1, U22);
    return {L, U};
}
template<class DB> vector<Matrix<DB>> LUDivideConquer(const Matrix<DB> &A)
{
    const Matrix<DB> Id = Matrix<DB>({{DB(1)}}, 1, 1);
    return LUDivideConquer(A, unsigned(RowSize(A)),Id);
}
template <class DB> Matrix<DB> GaussianElimination(const Matrix<DB> &A)
{
    vector<int> pi;
    int rank = 0;
    DB det = 1;
    Matrix<DB> LU=LUPCompactDecomposition(A, pi, rank, det);
    int n=LU.row_num;
    for (int i = 0;i<n;++i)
    {
        for (int j = 0; j < i;++j)
        {
            LU.value[i][j] = 0;
        }
    }
    return LU;
}
template <class DB> int MatrixRank(const Matrix<DB> &A)
{
    vector<int> pi;
    int rank = 0;
    DB det = 1;
    LUPCompactDecomposition(A, pi, rank, det);
    return rank;
}
template <class DB> DB Det(const Matrix<DB> &A)
{
    vector<int> pi;
    int rank = 0;
    DB det = 1;
    LUPCompactDecomposition(A, pi, rank, det);
    return det;
}
template <class DB> vector<Matrix<DB>> LUDecomposition(const Matrix<DB> &A)
{
    Matrix<DB> LU=LUCompactDecomposition(A);
    int n = LU.row_num;
    Matrix<DB> L = LU;
    Matrix<DB> U = LU;
    for (int i = 0; i < n;++i)
    {
        L.value[i][i] = 1;
        for (int j = 0; j < i;++j)
        {
            U.value[i][j] = 0;
        }
        for (int j = i + 1; j < n; ++j)
        {
            L.value[i][j] = 0;
        }
    }
    return {L, U};
}
template <class DB> vector<Matrix<DB>> LUPDecomposition(const Matrix<DB> &A)
{
    int _rank;
    DB det;
    vector<int> pi;
    const Matrix<DB> &LUP=LUPCompactDecomposition(A, pi, _rank, det);
    int n=A.column_num;
    Matrix<DB> L(n,n);
    Matrix<DB> U(n,n);
    Matrix<DB> P(n,n);
    for (int i = 0; i < n;++i)
    {
        P.value[i][pi[i]] = 1;
        L.value[i][i]=1;
        for(int j=0;j<i;++j)
            L.value[i][j] = LUP.value[i][j];
        for (int j = i;j<n;++j)
            U.value[i][j]=LUP.value[i][j];
    }
    return {L, U, P};
}
template <class DB> vector<vector<DB>> Tridiagonal(const Matrix<DB> &A)
{
    int n = A.row_num;
    vector<DB> a, b, c;
    a.push_back(0);
    for (int i = 0; i < n-1;++i)
    {
        b.push_back(A.value[i][i]);
        c.push_back(A.value[i][i + 1]);
        a.push_back(A.value[i+1][i]);
    }
    b.push_back(A.value[n - 1][n - 1]);
    c.push_back(0);
    return {a, b, c};
}
template <class DB> vector<vector<DB>> TridiagonalSeparation(const vector<vector<DB>> &T)
{
    int n = T[0].size();
    vector<DB> l(n);
    vector<DB> u(n);
    l[0] = 0;
    u[0] = T[1][0];
    for (int i = 1; i < n;++i)
    {
        l[i] = T[0][i] / u[i - 1];
        u[i] = T[1][i] - l[i] * T[2][i - 1];
    }
    return {l, u,T[2]};
}
template <class DB> Matrix<DB> CholeskyCompactDecomposition(const Matrix<DB> &A)
{
    if(A.row_num!=A.column_num)
    {
        cerr << "错误：只有方阵才能进行Cholesky分解。" << '\n';
        return A;
    }
    int n = A.row_num;
    Matrix<DB> L(n,n);
    DB s = 0;
    for (int j = 0; j < n;++j)
    {
        s = 0;
        for (int k = 0; k < j;++k)
        {
            s += L.value[j][k]*L.value[j][k];
        }
        if (A.value[j][j] - s <= 0)
        {
            cerr << "错误：这不是一个正定矩阵，不能Cholesky分解" << '\n';
            return A;
        }
        L.value[j][j] = Sqrt(A.value[j][j] - s);
        for (int i = j+1; i < n;++i)
        {
            s=0;
            for (int k = 0; k <j ;++k)
            {
                s += L.value[i][k] * L.value[j][k];
            }
            L.value[i][j] = (A.value[i][j] -s) / L.value[j][j];
        }    
    }
    return L;
}
template <class DB> vector<Matrix<DB>> CholeskyDecomposition(const Matrix<DB> &A)
{
    const Matrix<DB> &L=CholeskyCompactDecomposition(A);
    return {L,Transpose(L)};
}
template<class DB> Matrix<DB> Givens(const Matrix<DB> &x,int i,int j,int c)
{
    int n = RowSize(x);
    const DB length=Sqrt(Get(x,i,c)*Get(x,i,c)+Get(x,j,c)*Get(x,j,c));
    if(length<1e-14)
        return Eye<DB>(n);
    Matrix<DB> G=Eye<DB>(n);
    G(i,i)=Get(x,i,c)/length;
    G(i,j)=Get(x,j,c)/length;
    G(j,j)=G(i,i);
    G(j,i)=DB(0)-G(i,j);
    return G;
}
template<class DB> Matrix<DB> HouseholderNormal(const Matrix<DB> &u)
{
    int n=RowSize(u);
    Matrix<DB> e1(n, 1);
    e1(0, 0) = 1;
    const DB alpha = Sign(Get(u,0,0))*VectorNorm(u, 2);
    const Matrix<DB> &v = u + alpha * e1;
    DB beta=VectorNorm(v,2);
    if(beta<Machine_Epsilon)
        return Matrix<DB>(n,1);
    const Matrix<DB> &w=v/beta;
    return w;
}
template<class DB> Matrix<DB> ReflectorFromNormal(const Matrix<DB> &w)
{
    int n = RowSize(w);
    return Eye<DB>(n)-DB(2)*w*Transpose(w);
}
template<class DB> Matrix<DB> Householder(const Matrix<DB> &u)
{
    return ReflectorFromNormal(HouseholderNormal(u));
}
template<class DB> void _HessenbergControl(const Matrix<DB> &A,Matrix<DB> &H,Matrix<DB> &Q,bool open)
{
    int n=RowSize(A);
    H = A;
    if(open) Q=Eye<DB>(n);
    for (int i = 1; i < n - 1;++i)
    {
        const Matrix<DB> &x=SubMatrix(H,i,i-1,n-1,i-1);
        const Matrix<DB> &Reflector=Householder(x);
        Matrix<DB> P(n,n);
        ReplaceMatrix(P,0,0,i-1,i-1,Eye<DB>(i));
        ReplaceMatrix(P,i,i,n - 1, n - 1, Reflector);
        H = P*H*P;
        if(open) Q =P*Q;
    }
    for(int i=2;i<n;++i)
        for(int j=0;j<i-1;++j)
            H(i,j)=0;
}
template<class DB> vector<Matrix<DB>> HessenbergDecomposition(const Matrix<DB> &A)
{
    Matrix<DB> H, Q;
    _HessenbergControl(A,H,Q,true);
    return {Q, H, Q};
}
template<class DB> Matrix<DB> Hessenberg(const Matrix<DB> &A)
{
    Matrix<DB> H, Q;
    _HessenbergControl(A,H,Q,false);
    return H;
}
template <class DB> vector<Matrix<DB>> QRDecomposition(const Matrix<DB> &A,string str)
{
    if(RowSize(A)!=ColumnSize(A))
    {
        cerr << "错误：只有方阵才能进行QR分解。" << '\n';
        return {A,A};
    }
    if(str=="Gram-Schmidt" || str=="modified Gram-Schmidt" || str=="GS")
    {
        int n=RowSize(A);
        Matrix<DB> Q=A;
        Matrix<DB> R(n,n);
        for (int j = 0; j < n;++j)
        {
            for (int k = 0; k < j;++k)
            {
                DB r_kj= DB(0);
                for (int i = 0; i < n;++i)
                {
                    r_kj+= Get(Q, i, k) * Get(Q, i, j);
                }
                R(k, j) = r_kj;
                for (int i = 0; i < n;++i)
                {
                    Q(i, j) = Q(i, j) - r_kj * Q(i, k);
                }
            }
            DB r_jj = VectorNorm<DB>(SubColumn(Q, j, j),2.);
            R(j,j)=r_jj;
            for(int i=0;i<n;++i)
            {
                Q(i, j) = Get(Q, i, j) / r_jj;
            }
        }
        return {Q,R};
    }
    if(str=="Householder")
    {
        int n = RowSize(A);
        Matrix<DB> Q=Eye<DB>(n);
        Matrix<DB> R = A;
        for (int i = 0; i < n-1;++i)
        {
            const Matrix<DB> &u = SubMatrix(R, i, i,n-1,i);
            const Matrix<DB> &w = HouseholderNormal(u);
            const auto &R_22 = SubMatrix(R, i, i, n - 1, n - 1);
            const auto &Q_12 = SubMatrix(Q, 0, i, i - 1, n - 1);
            const auto &Q_22 = SubMatrix(Q, i, i, n - 1, n - 1);
            ReplaceMatrix(R, i, i, n - 1, n - 1, R_22 - (DB(2)*w) * (Transpose(w) * R_22));
            ReplaceMatrix(Q, 0, i, i - 1, n - 1, Q_12 - DB(2) * (Q_12*w)*Transpose(w));
            ReplaceMatrix(Q, i, i, n - 1, n - 1, Q_22 - (Q_22 * (DB(2)*w))*Transpose(w));
        }
        for (int i = 1; i < n;++i)
            for(int j=0;j<i;++j)
                R(i, j) = 0;
        return {Q, R};
    }
    if(str=="Givens")
    {
        int n=RowSize(A);
        Matrix<DB> Q=Eye<DB>(n);
        Matrix<DB> R = A;
        for (int j = 0; j < n - 1;++j)
        {
            for(int i=n-1;i>j;--i)
            {
                if(Abs(R(i,j))>1e-10)
                {
                    const Matrix<DB> &G = Givens(R, j, i,j);
                    R=G*R;
                    Q=G*Q;
                }  
            }
        }
        for (int i = 1; i < n;++i)
            for(int j=0;j<i;++j)
                R(i, j) = 0;
        return {Transpose(Q), R};
    }
    cerr<<"错误：未定义该方法"<<'\n';
    return {A,A};
}
template <class DB> vector<Matrix<DB>> QRDecomposition(const Matrix<DB> &A)
{
    return QRDecomposition(A,"modified Gram-Schmidt");
}
template <class DB> vector<Matrix<DB>> QRForHessenberg(const Matrix<DB> &A)
{
    int n=RowSize(A);
    Matrix<DB> Q=Eye<DB>(n);
    Matrix<DB> R = A;
    for (int j = 0; j < n - 1;++j)
    {
        const Matrix<DB> &G = Givens(R, j, j+1,j);
        R=G*R;
        Q=G*Q;
    }
    return {Transpose(Q), R};
}
template <class DB> void _SchurControl(const Matrix<DB> &A,Matrix<DB> &Acur,Matrix<DB> &EV,bool open)
{
    const int n=RowSize(A);
    const int times=20*std::log2(n+1);
    const DB eps=1e-6;
    int count = 0;
    DB s = 0;
    vector<DB> r(n);
    if(open)
    {
        const auto &hlist = HessenbergDecomposition(A);
        Acur = hlist[1];
        EV = hlist[0];
    }
    else
        Acur = Hessenberg(A);
    do
    {
        for(int i=0;i<n;++i)
            r[i] = Get(Acur, i, i);
        const vector<Matrix<DB>> &QR = QRForHessenberg(Acur);
        Acur=QR[1]*QR[0];
        if(open) EV = EV*QR[0];
        s = 0;
        for(int i=0;i<n;++i)
            s=std::max(s,Abs(r[i] - Get(Acur, i, i)));
        ++count;
    }while (count < times && s>eps);
}
template <class DB> vector<Matrix<DB>> SchurDecomposition(const Matrix<DB> &A)
{
    Matrix<DB> Acur,EV;
    _SchurControl(A,Acur,EV,true);
    return {EV, Acur, Transpose(EV)};
}
template <class DB> Matrix<DB> SchurForm(const Matrix<DB> &A)
{
    Matrix<DB> Acur,EV;
    _SchurControl(A,Acur,EV,false);
    return Acur;
}
template <class DB> DB RayleighQuotient(const Matrix<DB> &A, const Matrix<DB> &x)
{
    Matrix<DB> xT = Transpose<DB>(x);
    return Get(xT * A * x, 0, 0) / Get(xT * x, 0, 0);
}
template <class DB> pair<DB,Matrix<DB>> PowerIteration(const Matrix<DB> &A, 
const Matrix<DB> &initial_eigenvector, DB epsilon)
{
    Matrix<DB> eigenvector = initial_eigenvector;
    DB eigenvalue = RayleighQuotient(A, eigenvector);
    while(Norm(A*eigenvector-eigenvalue*eigenvector,"Frobenius")>epsilon)
    {
        eigenvector = A * eigenvector;
        eigenvector = eigenvector / Norm(eigenvector, "Frobenius");
        eigenvalue =  RayleighQuotient(A, eigenvector);
    }
    return {eigenvalue, eigenvector};
}
template <class DB> pair<DB,Matrix<DB>> PowerIteration(const Matrix<DB> &A)
{
    return PowerIteration(A, Matrix<DB>(DB(1), ColumnSize(A), 1), DB(1e-7));
}
template <class DB> DB DominatingEigenvalue(const Matrix<DB> &A)
{
    return std::get<0>(PowerIteration(A));
}
template <class DB> Matrix<DB> DominatingEigenvector(const Matrix<DB> &A)
{
    return std::get<1>(PowerIteration(A));
}
template <class DB> vector<DB> Eigenvalues(const Matrix<DB> &A)
{
    return Diagonal(SchurForm(A));
}
template<class DB> Matrix<DB> EigenvalueMatrix(const Matrix<DB> &A)
{
    return DiagonalMatrix(Eigenvalues(A));
}
template<class DB> vector<Matrix<DB>> Decomposition(const Matrix<DB> &A,string str)
{
    if(str=="LU")
        return LUDecomposition(A);
    if(str=="LUP")
        return LUPDecomposition(A);
    if(str=="Cholesky")
        return CholeskyDecomposition(A);
    if(str=="QR")
        return QRDecomposition(A);
    if(str=="Schur")
        return SchurDecomposition(A);
    cerr<<"错误：没有定义该方法"<<'\n';
    return {A};
}
template <class DB> vector<Matrix<DB>> JacobiIterationMatrix(const Matrix<DB> &A,const Matrix<DB>&b)
{
    int n = A.row_num;
    int m = b.column_num;
    Matrix<DB> B(n,n);
    Matrix<DB> f(n, m);
    Matrix<DB> x(n, m);
    for (int i = 0; i < n;++i)
    {
        if(A.value[i][i]==0)
        {
            cerr << "错误：Jacobi迭代法需要系数矩阵的主对角元不为0" << '\n';
            return {A,b};
        }
        for (int j = 0;j<i;++j)
        {
            B.value[i][j] = -A.value[i][j] / A.value[i][i];
        }
        B.value[i][i]=0;
        for (int j = i + 1; j < n;++j)
        {
            B.value[i][j] = -A.value[i][j] / A.value[i][i];
        }
    }
    for (int j = 0; j < m;++j)
    {
        for (int i = 0; i < n;++i)
        {
            f.value[i][j] = b.value[i][j] / A.value[i][i];
        }
    }
    return {B, f};
}
template <class DB> vector<Matrix<DB>> GSIterationMatrix(const Matrix<DB> &A,const Matrix<DB> &b)
{
    return {LSolve(A, USplit(A)), LSolve(A, b)};
}
template <class DB> Matrix<DB> LUSolve(const Matrix<DB> &LU,const Matrix<DB> &b)
{
    int n = LU.row_num;
    int m = b.column_num;
    Matrix<DB> y(n, m);
    Matrix<DB> x(n,m);
    DB s = 0;
    for (int j = 0; j < m;++j)
    {
        for (int i = 0; i < n;++i)
        {
            s = 0;
            for (int k = 0; k < i;++k)
            {
                s += LU.value[i][k] *y.value[k][j];
            }
            y.value[i][j] = (b.value[i][j] - s);
        }
        for (int i = n-1; i>=0;--i)
        {
            s = 0;
            for (int k =i+1 ; k <n;++k)
            {
                s += LU.value[i][k] * x.value[k][j];
            }
            x.value[i][j] = (y.value[i][j] - s) / LU.value[i][i];
        }
    }
    return x;
}
template <class DB> Matrix<DB> LUPSolve(const Matrix<DB> &LU, const vector<int> &pi,const Matrix<DB> &b)
{
    int n = LU.row_num;
    int m = b.column_num;
    Matrix<DB> y(n, m);
    Matrix<DB> x(n,m);
    DB s = 0;
    for (int j = 0; j < m;++j)
    {
        for (int i = 0; i < n;++i)
        {
            s = 0;
            for (int k = 0; k < i;++k)
            {
                s += LU.value[i][k] *y.value[k][j];
            }
            y.value[i][j] = (b.value[pi[i]][j] - s);
        }
        for (int i = n-1; i>=0;--i)
        {
            s = 0;
            for (int k =i+1 ; k <n;++k)
            {
                s += LU.value[i][k] * x.value[k][j];
            }
            x.value[i][j] = (y.value[i][j] - s) / LU.value[i][i];
        }
    }
    return x;
}
template <class DB> Matrix<DB> TridiagonalSolve(const vector<vector<DB>> &T, const Matrix<DB> &f)
{
    const vector<vector<DB>> &LUC = TridiagonalSeparation(T);
    int n = f.row_num;
    int m = f.column_num;
    Matrix<DB> y(n,m);
    Matrix<DB> x(n, m);
    for (int j = 0; j < m;++j)
    {
        y.value[0][j] = f.value[0][j];
        for (int i = 1; i < n;++i)
        {
            y.value[i][j]=f.value[i][j] - LUC[0][i] * y.value[i - 1][j];
        }
        x.value[n - 1][j] = y.value[n - 1][j]/ LUC[1][n - 1];
        for (int i = n - 2; i >= 0;--i)
        {
            x.value[i][j] = (y.value[i][j]-LUC[2][i]*x.value[i+1][j]) / LUC[1][i];
        }
    }
    return x;
}
template <class DB> Matrix<DB> Iteration(const Matrix<DB> &B,const Matrix<DB> &f)
{
    Matrix<DB> x = f;
    int times = 10;//迭代次数
    for (int i = 1; i < times;++i)
    {
        x=B*x+f;
    }
    return x;
}
template<class DB> Matrix<DB> LinearSolve(const Matrix<DB> &A ,const Matrix<DB> &b,string str,double w)
{
    if(A.row_num!=b.row_num)
    {
        cerr << "错误：系数矩阵与列向量的行数必须相等。" << '\n';
        return b;
    }
    if(A.row_num>A.column_num)
    {
        cerr<<"错误：系数矩阵的行数大于列数，可能是超定的方程组。"<<'\n';
        return b;
    }
    if(A.row_num<A.column_num)
    {
        cerr<<"错误：系数矩阵的行数小于列数，可能是欠定的方程组。"<<'\n';
        return b;
    }
    if(str=="SOR")
    {
        if(w<=0 || w>=2)
        {
            cerr<<"错误：参数w不在(0,2)范围内，这会导致SOR方法不收敛。" <<'\n';
            return b;
        }
        int n = A.row_num;
        int m = b.column_num;
        int times=10;//迭代次数
        int k = 0;
        Matrix<DB> x(n,m);
        DB part = 0;
        DB s = 0;
        vector<DB> rightcoeff;
        for (int i = 0; i < n;++i)
        {
            if(A.value[i][i]==0)
            {
                cerr << "错误：SOR迭代法要求主对角元素全不为0" << '\n';
                return b;
            }
            rightcoeff.push_back(w / A.value[i][i]);
        }
        while(k<times)
        {
            for (int j = 0; j < m;++j)
            {
                for (int i = 0; i < n;++i)
                {
                    part = (1 - w) * x.value[i][j];
                    s = b.value[i][j];
                    for (int r = 0; r < i;++r)
                    {
                        s -= A.value[i][r] * x.value[r][j];
                    }
                    for (int r = i + 1; r < n;++r)
                    {
                        s -= A.value[i][r] * x.value[r][j];
                    }
                    s *=rightcoeff[i]; 
                    x.value[i][j] = part + s;
                }
            }
            ++k;
        }
        return x;
    }
    cerr<<"错误：未定义该方法。"<<'\n';
    return b;
}
template<class DB> Matrix<DB> LinearSolve(const Matrix<DB> &A,const Matrix<DB> &b,string str)
{
    if(A.row_num!=b.row_num)
    {
        cerr << "错误：系数矩阵与列向量的行数必须相等。" << '\n';
        return b;
    }
    if(A.row_num>A.column_num)
    {
        cerr<<"错误：系数矩阵的行数大于列数，可能是超定的方程组。"<<'\n';
        return b;
    }
    if(A.row_num<A.column_num)
    {
        cerr<<"错误：系数矩阵的行数小于列数，可能是欠定的方程组。"<<'\n';
        return b;
    }
    if(str=="Gauss")
    {
        vector<Matrix<DB>> Ab = GaussianElimination(A, b);
        return USolve(Ab[0], Ab[1]);
    } 
    if(str=="LU")
    {
        return LUSolve(LUCompactDecomposition(A), b);
    }
    if(str=="LUP")
    {
        vector<int> pi;
        int rank;
        DB det;
        Matrix<DB> LU=LUPCompactDecomposition(A, pi, rank, det);
        if(rank<A.row_num)
        {
            cerr << "错误：遇到奇异矩阵，无法求解。" << '\n';
            return b;
        }
        return LUPSolve(LU, pi, b);
    }
    if(str=="Thomas"|| str=="chase" || str=="TDMA")
    {
        return TridiagonalSolve(Tridiagonal(A), b);
    }
    if(str=="Cholesky"|| str=="squareroot")
    {
        Matrix<DB> L = CholeskyCompactDecomposition(A);
        return USolve(Transpose(L), LSolve(L, b));
    }
    if(str=="QR")
    {
        auto QR=QRDecomposition(A);
        auto Q=QR[0];
        auto R=QR[1];
        return USolve(R, Transpose(Q) * b);
    }
    if(str=="Jacobi")
    {
        /*vector<Matrix<DB>> Bf = JacobiIterationMatrix(A, b);
        return Iteration(Bf[0],Bf[1]);*/
        int n = A.row_num;
        int m = b.column_num;
        int times = 10;//迭代次数
        int k = 0;
        Matrix<DB> xpre(n, m);
        Matrix<DB> x(n, m);
        DB s = 0;
        for (int i = 0; i < n;++i)
        {
            if(A.value[i][i]==0)
            {
                cerr << "错误：Jacobi迭代法要求主对角元素全不为0" << '\n';
                return b;
            }
        }
        while(k<times)
        {
            for (int j = 0; j < m;++j)
            {
                for (int i = 0; i < n;++i)
                {
                    s= b.value[i][j];
                    for (int r = 0; r < i;++r)
                    {
                        s-= A.value[i][r] * xpre.value[r][j];
                    }
                    for (int r = i + 1; r < n;++r)
                    {
                        s-= A.value[i][r] * xpre.value[r][j];
                    }
                    x.value[i][j] = s/ A.value[i][i];
                }
            }
            xpre = x;
            ++k;
        }
        return x;
    }
    if(str=="Gauss-Seidel"|| str=="G-S" || str=="GS")
    {
        int n = A.row_num;
        int m = b.column_num;
        int times = 10;//迭代次数
        int k = 0;
        Matrix<DB> x(n, m);
        DB s = 0;
        for (int i = 0; i < n;++i)
        {
            if(A.value[i][i]==0)
            {
                cerr << "错误：Gauss-Seidel迭代法要求主对角元素全不为0" << '\n';
                return b;
            }
        }
        while(k<times)
        {
            for (int j = 0; j < m;++j)
            {
                for (int i = 0; i < n;++i)
                {
                    s= b.value[i][j];
                    for (int r = 0; r < i;++r)
                    {
                        s-= A.value[i][r] * x.value[r][j];
                    }
                    for (int r = i + 1; r < n;++r)
                    {
                        s-= A.value[i][r] * x.value[r][j];
                    }
                    x.value[i][j] = s/ A.value[i][i];
                }
            }
            ++k;
        }
        return x;
    }
    cerr<<"错误：未定义该方法。"<<'\n';
    return b;
}
template<class DB> Matrix<DB> LinearSolve(const Matrix<DB> &a,const Matrix<DB> &b)
{
    return LinearSolve(a, b, "LUP");
}

//求逆
template<class DB> Matrix<DB> Inverse(const Matrix<DB> &a)
{
    if(a.row_num!=a.column_num)
    {
        cerr << "错误：只有方阵才具有逆矩阵" << '\n';
        return a;
    }
    return LinearSolve(a, Eye<DB>(a.row_num));
}
template<class DB> Matrix<DB> operator/(const Matrix<DB> &a,const Matrix<DB>&b)
{
    if(b.column_num==1 && b.row_num==1)
        return a / Get(b, 0, 0);
    return a * Inverse(b);
}
template<class DB> Matrix<DB> operator^(const Matrix<DB> &a,int n)
{
    if(a.column_num!=a.row_num)
    {
        cerr << "错误：只有方阵才能进行幂运算。" << '\n';
        return a;
    }
    Matrix<DB> m = a;
    Matrix<DB> b = Eye<DB>(a.row_num);
    if(n<0)
    {
        //m = Inverse(m);
        //n = -n;
        cerr << "施工：不打算实现负数次方幂了。每定义一个类都要重载一大堆运算符，累死" << '\n';
    }
    while(n>=1)
    {
        if(n&1)
        {
            b = m * b;
        }
        n=n>>1;
        m = m * m;
    }
    return b;
}
//范数、条件数
template <class DB> DB SpectralRadius(const Matrix<DB> &a)
{
    auto v=Eigenvalues(a);
    DB maximum = DB(0);
    for(auto item:v)
    {
        auto temp = Abs(item);
        if(temp>maximum)
            maximum = temp;
    }
    return maximum;
}
template <class DB> DB Norm(const Matrix<DB> &a, double p)
{
    if(p==INFINITY)
    {
        DB max=0;
        DB s= 0;
        for (int i = 0; i < a.row_num;++i)
        {
            s = 0;
            for (int j = 0; j < a.column_num;++j)
            {
                s += Abs(a.value[i][j]);
            }
            if(s>max)
                max = s;
        }
        return max;
    }
    if(p==1)
    {
        DB max=0;
        DB s= 0;
        for (int j = 0; j < a.column_num;++j)
        {
            s = 0;
            for (int i = 0; i < a.row_num;++i)
            {
                s += Abs(a.value[i][j]);
            }
            if(s>max)
                max = s;
        }
        return max;
    }
    if(p==2)
    {
        return Sqrt(SpectralRadius(Transpose(a) * a));
    }
    cerr << "错误：待开发。" << '\n';
    return 0;
}
template <class DB> DB Norm(const Matrix<DB> &a, string str)
{
    if(str=="Frobenius")
    {
        return Sqrt(Trace(a * Transpose(a)));
    }
    cerr << "错误：矩阵范数没有该方法。" << '\n';
    return 0;
}
template <class DB> double Cond(const Matrix<DB> &a, double p)
{
    return Norm(a, p) * Norm(Inverse(a), p);
}
template <class DB> double Cond(const Matrix<DB> &a, string str)
{
    return Norm(a, str) * Norm(Inverse(a), str);
}

//插值
template <class DB> vector<std::function<DB(DB)>> LagrangeBasis(const Matrix<DB> &A)
{
    int n = RowSize(A);
    vector<std::function<DB(DB)>> r;
    std::function<DB(DB)> f;
    for (int i = 0; i <n;++i)
    {
        f = [=](DB x) {
            DB s1=DB(1);
            DB s2=DB(1);
            for (int j = 0; j < i;++j)
            {
                s1=s1*(x-A(j,0));
                s2=s2*(A(i,0) - A(j,0));
            }
            for (int j = i + 1;j<n;++j)
            {
                s1=s1*(x-A(j,0));
                s2=s2*(A(i,0) - A(j,0));
            }
            return s1 / s2;
        };
        r.push_back(f);
    }
    return r;
}
template <class DB> DB LBasisToInterp(const vector<std::function<DB(DB)>> &lb,const Matrix<DB> &A,DB x)
{
    int n = RowSize(A);
    DB s = lb[0](x) * A.value[0][1];
    for (int i = 1; i < n;++i)
    {
        s += lb[i](x) * A(i,1);
    }
    return s;
}
template <class DB> Matrix<DB> DifferenceQuotientTable(const Matrix<DB> & A)
{
    int n = RowSize(A);
    Matrix<DB> table(n,n);
    for (int i = 0; i < n;++i)
        table(i,0) = A(i,1);
    for (int j = 1; j <n;++j)
    {
        for (int i = j; i < n;++i)
        {
            table(i,j) =(table(i,j-1)-table(i-1,j-1))/(A(i,0)-A(i-j,0));
        }
    }
    return table;
}
template <class DB> Matrix<DB> DividedDifferenceTable(const Matrix<DB> &A)
{
    int data_num= RowSize(A);
    int der_deg = A.column_num-1;
    int n = data_num * der_deg;
    int factorial = 1;
    vector<DB> z(n);
    for (int i = 0; i <n;++i)
        z[i] = A(i/der_deg,0);
    Matrix<DB> table(n, n);
    for (int j = 0; j <der_deg;++j)
    {
        for (int i = j; i < n;++i)
        {
            if((i%der_deg)<j)
                table(i,j)=(table(i,j-1)-table(i-1,j-1))/(z[i]-z[i-j]);
            else
                table(i,j) = A(i/der_deg, j+1)/factorial;
        }
        factorial = factorial * (j + 1);
    }
    for(int j=der_deg;j<n;++j)
        for (int i = j; i < n;++i)
            table(i,j)=(table(i,j-1)-table(i-1,j-1))/(z[i]-z[i-j]);
    return table;
}
template <class DB> DB DifferenceQuotient(const Matrix<DB> &A)
{
    int n = RowSize(A);
    return DifferenceQuotientTable(A).value[n-1][n-1];
}
template <class DB> DB DifferenceQuotient(std::function<DB(DB)> f, const Matrix<DB> &x)
{
    int n = RowSize(x);
    Matrix<DB> A(n,2);
    for (int i = 0; i < n;++i)
    {
        A(i,0) = x(i,0);
        A(i,1) = f(x(i,0));
    }
    return DifferenceQuotient(A);
}
template <class DB> DB DQTableToInterp(const Matrix<DB> &A, const Matrix<DB> &table,DB x)
{
    int n = RowSize(A);
    DB s = table(n-1,n-1);
    for (int i = n - 2; i >= 0;--i)
    {
        s = table.value[i][i] + (x -A(i,0)) * s;
    }
    return s;
}
template <class DB> DB DDTableToInterp(const Matrix<DB> &A, const Matrix<DB> &table,DB x)
{
    int data_num = RowSize(A);
    int der_deg=A.column_num-1;
    int n = data_num * der_deg;
    vector<DB> nest(n);
    nest[0] = DB(1);
    for(int i=0;i<n-1;++i)
        nest[i+1] = nest[i] * (x - A.value[i/der_deg][0]);
    DB s=DB(0);
    for (int i = 0;i<n;++i)
        s += nest[i] * table.value[i][i];
    return s;
}
template <class DE> DE _2P3DHermiteInterp(const Matrix<DE> &M,int i,int j,DE x)
{
    DE l0x = (x-M(j,0)) / (M(i,0) - M(j,0));
    DE l1x = (x - M(i,0)) / (M(j,0) - M(i,0));
    DE l0x2 = l0x * l0x;
    DE l1x2 = l1x * l1x;
    return M(i,1) * (1 + 2 * l1x) * l0x2 + M.value[j][1] * (1 + 2 * l0x) * l1x2 +
           M.value[i][2] * (x - M(i,0)) * l0x2 + M.value[j][2] * (x - M(j,0)) *l1x2;
}
template <class DE> DE _3P3DHermiteInterp(const Matrix<DE> &M,DE x)
{
    std::function<DE(DE)> L2 = [=](DE t) {
        return DQTableToInterp(M, DifferenceQuotientTable(M),t);
    };
    DE k = (M.value[1][2]-D(L2,M.value[1][0]))/
           ((M.value[1][0]-M.value[0][0])*(M.value[1][0]-M.value[2][0]));
    return L2(x) + k * (x - M.value[0][0]) * (x - M.value[1][0]) * (x - M.value[2][0]);
}
template <class DE> Matrix<DE> SplineSlope(const Matrix<DE> &A)
{
    int n = RowSize(A);
    vector<DE> h(n);
    vector<DE> lambda(n);
    vector<DE> mu(n);
    Matrix<DE> g(n, 1);
    h[0] = A.value[1][0] - A.value[0][0];
    lambda[0]=DE(0);
    mu[0] = DE(1);
    g.value[0][0] = 3 * (A.value[1][1]-A.value[0][1]) / h[0];
    for (int k = 1; k<= n - 2;++k)
    {
        h[k]=A.value[k+1][0]-A.value[k][0];
        lambda[k] = h[k] / (h[k] + h[k - 1]);
        mu[k]=1-lambda[k];
        g.value[k][0]=3*(lambda[k]*(A.value[k][1]-A.value[k-1][1])/h[k-1]
        +mu[k]*(A.value[k+1][1]-A.value[k][1])/h[k]);
    }
    lambda[n-1]=DE(1);
    mu[n-1]=DE(0);
    g.value[n - 1][0] = 3 * (A.value[n - 1][1] - A.value[n - 2][1]) / h[n - 2];
    Matrix<DE> m=TridiagonalSolve({lambda, vector<DE>(n, DE(2)), mu}, g);
    return m;
}
template <class DE> DE Interpolation(const Matrix<DE> &A,DE x,string str)
{
    if(RowSize(A)<2)
    {
        cerr << "错误：至少需要两个点才能插值" << '\n';
        return x;
    }
    if(A.column_num<2)
    {
        cerr<<"错误：传入的数据矩阵至少两列"<<'\n';
        return x;
    }
    if(str=="Lagrange")
    {
        return LBasisToInterp(LagrangeBasis(A), A, x);
    }
    if(str=="Newton")
    {
        return DQTableToInterp(A, DifferenceQuotientTable(A),x);
    }
    if(str=="Hermite")
    {
        return DDTableToInterp(A, DividedDifferenceTable(A), x);
    }
    if(str=="non-standard Hermite")
    {
        return _3P3DHermiteInterp(A, x);
    }
    if(str=="linear" || str=="piecewise Lagrange")
    {
        int n = RowSize(A);
        int k= 1;
        while(k<n)
        {
            if(x<A.value[k][0])
            {
                return A.value[k - 1][1] * (x - A.value[k][0]) / (A.value[k - 1][0] - A.value[k][0]) + 
                       A.value[k][1] * (x - A.value[k-1][0]) / (A.value[k][0] - A.value[k - 1][0]);
            }
            ++k;
        }
        return A.value[n-2][1]*(x-A.value[n-2][0])/(A.value[n-2][0]-A.value[n-1][0])+
               A.value[n-1][1]*(x-A.value[n-2][0])/(A.value[n-1][0]-A.value[n-2][0]);
    }
    if(str=="pchip" || str=="piecewise Hermite")
    {
        int n = RowSize(A);
        int i = 1;
        while(i<n)
        {
            if(x<A(i,0))
                return _2P3DHermiteInterp(A,i-1,i, x);
            ++i;
        }
        return _2P3DHermiteInterp(A,n-2,n-1, x);
    }
    if(str=="spline")
    {
        int n = RowSize(A);
        int k= 1;
        const Matrix<DE> &m = SplineSlope(A);
        Matrix<DE> B(2, 3);
        while(k<n)
        {
            if(x<A.value[k][0])
            {
                for (int i = 0; i < 2;++i)
                {
                    B.value[i][2] = m.value[k - 1 + i][0];
                    for (int j = 0; j < 2;++j)
                        B(i,j) = A.value[k - 1 + i][j];
                }
                return _2P3DHermiteInterp(B, 0, 1, x);
            }               
            ++k;
        }
        for (int i = 0; i < 2;++i)
        {
            B.value[i][2] = m.value[n-2+i][0];
            for (int j = 0; j < 2;++j)
                B(i,j) = A.value[n-2+ i][j];
        }
        return _2P3DHermiteInterp(B, 0, 1, x);
    }
    cerr<<"错误：没有定义该方法"<<'\n';
    return x;
}
template <class DE> DE Interpolation(const Matrix<DE> &A,DE x)
{
    if(A.column_num<=2)
        return Interpolation(A,x,"linear");
    return Interpolation(A, x, "piecewise Hermite");
}
template <class DE> Matrix<DE> Interpolation(const Matrix<DE> &A,const Matrix<DE> &x,string str)
{
    if(RowSize(A)<2)
    {
        cerr << "错误：至少需要两个点才能插值" << '\n';
        return x;
    }
    if(A.column_num<2)
    {
        cerr<<"错误：传入的数据矩阵至少两列"<<'\n';
        return x;
    }
    if(str=="Lagrange")
    {
        vector<std::function<DE(DE)>> L = LagrangeBasis(A);
        Matrix<DE> s(RowSize(x), 1);
        for (int i = 0; i < RowSize(x);++i)
            s(i,0) = LBasisToInterp(L, A, x(i,0));
        return s;
    }
    if(str=="Newton")
    {
        Matrix<DE> D = DifferenceQuotientTable(A);
        Matrix<DE> s(RowSize(x), 1);
        for (int i = 0; i < RowSize(x);++i)
            s(i,0) = DQTableToInterp(A, D, x(i,0));
        return s;
    }
    if(str=="Hermite")
    {
        Matrix<DE> D = DividedDifferenceTable(A);
        Matrix<DE> s(RowSize(x), 1);
        for (int i = 0; i < RowSize(x);++i)
            s(i,0) = DDTableToInterp(A, D, x(i,0));
        return s;
    }
    if(str=="non-standard Hermite")
    {
        Matrix<DE> s(RowSize(x),1);
        for (int i = 0; i < RowSize(x);++i)
            s(i,0) = _3P3DHermiteInterp(A, x(i,0));
        return s;
    }
    if(str=="linear" || str=="piecewise Lagrange")
    {
        int n = RowSize(A);
        Matrix<DE> s(RowSize(x), 1);
        int k= 1;
        int j = 0;
        while(j<RowSize(x) && k<n)
        {
            if(x(j,0)<A.value[k][0])
            {
                s(j,0)=A.value[k - 1][1] * (x(j,0)- A.value[k][0]) / (A.value[k - 1][0] - A.value[k][0]) + 
                       A.value[k][1] * (x(j,0) - A.value[k-1][0]) / (A.value[k][0] - A.value[k - 1][0]);
                ++j;
                continue;
            }
            ++k;
        }
        for (int t = j; t < RowSize(x);++t)
        {
            s.value[t][0] =A.value[n-2][1]*(x.value[t][0]-A.value[n-2][0])/(A.value[n-2][0]-A.value[n-1][0])+
               A.value[n-1][1]*(x.value[t][0]-A.value[n-2][0])/(A.value[n-1][0]-A.value[n-2][0]);
        }
        return s;
    }
    if(str=="pchip" || str=="piecewise Hermite")
    {
        int n = RowSize(A);
        Matrix<DE> s(RowSize(x), 1);
        int i=1;
        int j = 0;
        while(j<RowSize(x) && i<n)
        {
            if(x(j,0)<A(i,0))
            {
                s(j,0) = _2P3DHermiteInterp(A,i-1,i, x(j,0));
                ++j;
                continue;
            }
            ++i;
        }
        for (int t = j; t < RowSize(x);++t)
            s.value[t][0] = _2P3DHermiteInterp(A,n-2,n-1, x.value[t][0]);
        return s;
    }
    if(str=="spline")
    {
        int n = RowSize(A);
        Matrix<DE> s(RowSize(x), 1);
        int k= 1;
        int j = 0;
        const Matrix<DE> &m = SplineSlope(A);
        Matrix<DE> B(2, 3);
        while(j<RowSize(x) && k<n)
        {
            if(x(j,0)<A.value[k][0])
            {
                for (int i = 0; i < 2;++i)
                {
                    B.value[i][2] = m.value[k - 1 + i][0];
                    for (int j = 0; j < 2;++j)
                        B(i,j) = A.value[k - 1 + i][j];
                }
                s(j,0) = _2P3DHermiteInterp(B, 0, 1, x(j,0));
                ++j;
                continue;
            }
            ++k;
        }
        for (int t = j; t < RowSize(x);++t)
        {
            for (int i = 0; i < 2;++i)
            {
                B.value[i][2] = m.value[n-2+i][0];
                for (int j = 0; j < 2;++j)
                    B(i,j) = A.value[n-2+ i][j];
            }
            s.value[t][0]=_2P3DHermiteInterp(B, 0, 1, x.value[t][0]);
        }
        return s;
    }
    cerr<<"错误：没有定义该方法"<<'\n';
    return x;
}
template <class DE> Matrix<DE> Interpolation(const Matrix<DE> &A, const Matrix<DE> &x)
{
    if(ColumnSize(A)<=2)
        return Interpolation(A,x,"linear");
    return Interpolation(A, x, "piecewise Hermite");
}
template <class DE> std::function<DE(DE)> Interpolation(const Matrix<DE> &A,string str)
{
    return [=](DE x) { return Interpolation(A, x, str); };
}

//积分
template<class DI> DI Integrate(std::function<DI(DI)> f,DI a,DI b,string str,int n)
{
    if(str=="Newton-Cotes"|| str=="N-C")
    {
        if(n<=0)
        {
            cerr<<"错误：Newton-Cotes法要求最后一个参数大于0"<<'\n';
            return (b - a) * f(a);
        }
        if(n>6)
        {
            cerr << "警告：插入过多的点可能会造成Newton-Cotes法数值不稳定。为了确保稳定性，已减少插入的点。" << '\n';
            return Integrate(f, a, b, "Newton-Cotes", 6);
        }
        const vector<vector<DI>> CotesTable({
            {0.5,0.5},
            {1.0/6,4.0/6,1.0/6},
            {0.125,0.375,0.375,0.125},
            {7.0/90,32.0/90,12.0/90,32.0/90,7.0/90},
            {19.0/288,75.0/288,50.0/288,50.0/288,75.0/288,19.0/288},
            {41.0/840,216.0/840,27.0/840,272.0/840,27.0/840,216.0/840,41.0/840}
        }); 
        DI s=0;
        DI divpoint = a;
        DI interval = b - a;
        DI h = interval / n;
        for (int k = 0; k <= n;++k)
        {
            s=s+CotesTable[n-1][k]*f(divpoint);
            divpoint = divpoint + h;
        }
        return interval * s;
    }
    if(str=="Gauss-Legendre" || str=="G-L" || str=="Gauss")
    {
        if(n<0)
        {
            cerr << "错误：Gauss-Legendre法要求至少插入一个点" << '\n';
            return (b - a) * f((a + b) / 2);
        }
        if(n>4)
        {
            cerr<<"警告：不支持插入过多点的Gauss-Legendre法。已自动减少插入的点。"<<'\n';
            return Integrate(f, a, b, "Gauss", 4);
        }
        const vector<vector<DI>> GaussPoint({
            {0},
            {0.5773502692,-0.5773502692},
            {0.7745966692,-0.7745966692,0},
            {0.8611363116,-0.8611363116,0.3399810436,-0.3399810436},
            {0.9061798459,-0.9061798459,0.5384693101,-0.5384693101,0}
        });
        const vector<vector<DI>> GaussCoef({
            {2},
            {1,1},
            {5.0/9,5.0/9,8.0/9},
            {0.3478548451,0.3478548451,0.6521451549,0.6521451549},
            {0.2369268851,0.2369268851,0.4786286705,0.4786286705,0.5688888889}
        });
        DI interval=b-a;
        DI halfinterval=interval/2;
        DI midpoint = (a + b) / 2;
        DI s = 0;
        for (int k = 0; k <=n;++k)
        {
            s = s + GaussCoef[n][k] * f(halfinterval*GaussPoint[n][k]+midpoint);
        }
        return halfinterval * s;
    }
    cerr << "错误：没有定义这种方法" << '\n';
    return f(a) * (b - a);
}
template<class DI> DI CompoundIntegrate(std::function<DI(DI)> f,DI a,DI b,string str,int n,int m)
{
    if(m<0)
    {
        cerr<<"错误：需要划分至少一个区间"<<'\n';
        return f(a) * (b - a);
    }
    DI s = 0;
    DI interval = b - a;
    DI h = interval / m;
    DI leftdiv = a;
    DI rightdiv = a + h;
    for (int i = 0; i < m;++i)
    {
        s = s + Integrate(f, leftdiv, rightdiv, str, n);
        leftdiv = rightdiv;
        rightdiv = rightdiv + h;
    }
    return s;
}
template <class DI> DI Integrate(std::function<DI(DI)> f,DI a,DI b,string str)
{
    if(str=="Romberg")
    {
        const DI epsilon = 1e-14;
        vector<DI> pre(1);
        vector<DI> now(1, (b - a) / 2 * (f(a) + f(b)));
        int k= 0;
        int times_max=20;
        DI accu = 0;
        int powof2 = 1;
        int powof4 = 1;
        do{
            ++k;
            pre = now;
            accu = 0;
            powof2 =(powof2<<1);
            for (int j = 0; j <(powof2>>1);++j)
            {
                accu = accu + f(a + (2 * j + 1) * (b - a) / powof2);
            }
            now[0] = 0.5 * pre[0] + (b - a) / powof2 * accu;
            powof4 = 4;
            for (int m= 1; m< k;++m)
            {
                now[m] = 1 / DI(powof4 - 1) * (powof4 * now[m - 1] - pre[m - 1]);
                powof4 = powof4 * 4;
            }
            now.emplace_back(1 / DI(powof4 - 1)*(powof4 * now[k-1] - pre[k-1]));
        }while(k<times_max && Abs(now[k]-pre[k-1])>=epsilon);
        if(k>=times_max)
            cerr << "警告：未在指定次数内达到预期精度"<<'\n';
        return now[k];
    }
    if(str=="trapz")
    {
        return Integrate(f, a, b, "Newton-Cotes", 1);
    }
    if(str=="compound trapz")
    {
        return CompoundIntegrate(f, a, b, "Newton-Cotes", 1, 100);
    }
    if(str=="Simpson")
    {
        return Integrate(f, a, b, "Newton-Cotes", 2);
    }
    if(str=="compound Simpson")
    {
        return CompoundIntegrate(f, a, b, "Newton-Cotes", 2, 100);
    }
    if(str=="Simpson3/8")
    {
        return Integrate(f, a, b, "Newton-Cotes", 3);
    }
    if(str=="compound Simpson3/8")
    {
        return CompoundIntegrate(f, a, b, "Newton-Cotes", 3, 100);
    }
    if(str=="Cotes"||str=="Milne")
    {
        return Integrate(f, a, b, "Newton-Cotes", 4);
    }
    if(str=="compound Cotes" || str=="compound Milne")
    {
        return CompoundIntegrate(f, a, b, "Newton-Cotes", 4, 100);
    }
    cerr << "错误：没有定义这种方法" << '\n';
    return f(a) * (b - a);
}
template <class DI> DI Integrate(std::function<DI(DI)> f,DI a,DI b)
{
    return Integrate(f, a,b,"Romberg");
}
template<class DI> DI CompoundIntegrate(std::function<DI(DI)>f ,DI a,DI b,string str,int m)
{
    if(m<0)
    {
        cerr<<"错误：需要划分至少一个区间"<<'\n';
        return f(a) * (b - a);
    }
    DI s = 0;
    DI interval = b - a;
    DI h = interval / m;
    DI leftdiv = a;
    DI rightdiv = a + h;
    for (int i = 0; i < m;++i)
    {
        s = s + Integrate(f, leftdiv, rightdiv, str);
        leftdiv = rightdiv;
        rightdiv = rightdiv + h;
    }
    return s;
}
template <class FS> FS FourierSinCoefficient(const std::function<FS(FS)> &f, int32_t n, FS w)
{
    if (Abs(w) < Machine_Epsilon)
    {
        std::cerr << "错误：频率不能为0" << std::endl;
        return 0;
    }
    return 2 * w / Pi<FS> * Integrate<FS>([&](FS t)
                           { return f(t) * sin(w * n * t); }, 0, Pi<FS> / w);
}
template <class FS> FS FourierCosCoefficient(const std::function<FS(FS)> &f, int32_t n, FS w)
{
    if (Abs(w) < Machine_Epsilon)
    {
        std::cerr << "错误：频率不能为0" << std::endl;
        return 0;
    }
    return 2 * w / Pi<FS> * Integrate<FS>([&](FS t)
                           { return f(t) * cos(w * n * t); }, 0, Pi<FS> / w);
}

//微分
template <class DD> DD D(std::function<DD(DD)> f,DD x,string str)
{
    if(str=="center")
    {
        const DD h = 1e-7;
        return (f(x + h) - f(x - h)) / (2 * h);
    }
    if(str=="forward")
    {
        const DD h = 1e-7;
        return (f(x + h) - f(x))/h;
    }
    if(str=="backward")
    {
        const DD h = 1e-7;
        return (f(x) - f(x-h))/h;
    }
    cerr << "错误：没有定义该方法。" << '\n';
    return x;
}
template <class DD> DD D(std::function<DD(DD)> f, DD x)
{
    return D(f, x, "center");
}
template<class DD> std::function<DD(DD)> D(std::function<DD(DD)> f)
{
    return [=](DD x) { return D(f, x); };
}
template<class DD> std::function<DD(DD)> D(int n,std::function<DD(DD)> f)
{
    if(n==0)
        return f;
    return D(n - 1, D(f));
}
template<class DD> DD D(int n,std::function<DD(DD)>f, DD x)
{
    return D(n, f)(x);
}
template<class DD> DD D(std::function<DD(Matrix<DD>)>f,int n,const Matrix<DD> &x)
{
    if(n>=RowSize(x))
    {
        cerr << "错误：求偏导的分量越界" << '\n';
        return f(x);
    }
    const DD h=1e-7;
    auto y=x;
    y(n,0)=Get(x,n,0)+h;
    return (f(y) - f(x)) / h;
}
template<class DD> std::function<DD(Matrix<DD>)> D(std::function<DD(Matrix<DD>)>f,int n)
{
    return [=](Matrix<DD> x){return D(f,n,x);};
}
template<class DD> Matrix<DD> D(const vector<std::function<DD(Matrix<DD>)>> &f,const Matrix<DD> &x)
{
    int n=f.size();
    Matrix<DD> J(n,n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            J(i, j) = D(f[i], j, x);
    return J;
}

//方程(组)求根
template <class DD> DD Iteration(std::function<DD(DD)> phi, DD a)
{
    int times = 100;//迭代次数
    int k = 0;
    DD pre=a;
    DD x = phi(a);
    while (Abs(x-pre)>1e-14 && k < times)
    {
        pre = x;
        x = phi(x);
        ++k;
    } 
    if(k>=times)
    {
        cerr<<"警告：未在指定次数内达到预期精度。"<<'\n';
        cerr << "可能是初值的选择使迭代法不收敛，或者迭代函数的选择使收敛速度很慢。" << '\n';
    }
    return x;
}
template<class DD,class DM,class DF> 
Matrix<DD> Iteration(const DF &ini,const DM &phi,const Matrix<DD>&x0)
{
    const int times = 20;//迭代次数
    const DD eps = 1e-10;//精度
    int count = 0;
    auto x = x0;
    int n = RowSize(x0);
    Matrix<DD> fx(n, 1);
    Matrix<DD> B;
    ini(x,fx, B);
    do
    {
        phi(x, fx,B);
        ++count;
    } while (VectorNorm(fx,2) >= eps && count<times);
    if(count>=times)
        cerr << "警告：未在指定次数内达到预期精度" << '\n';
    return x;
}
template<class DD> 
Matrix<DD> FindRoot(const vector<std::function<DD(Matrix<DD>)>> &f,const Matrix<DD> &x0,string str)
{
    if(str=="Newton")
    {
        int n = RowSize(x0);
        auto ini=[](Matrix<DD> &,Matrix<DD>&,Matrix<DD>&){};
        auto phi = [=](Matrix<DD> &x, Matrix<DD> &fx, Matrix<DD> &B) 
        {
            for(int j=0;j<n;++j)
                fx(j, 0) = f[j](x);
            B = Inverse(D(f, x));
            x=x-B*fx;
        };
        return Iteration(ini, phi, x0);
    }
    if(str=="Broyden")
    {
        int n = RowSize(x0);
        auto ini=[=](Matrix<DD> &x,Matrix<DD> &fx,Matrix<DD> &B)
        {
            for(int j=0;j<n;++j)
                fx(j, 0) = f[j](x);
            B = Inverse(D(f, x));
        };
        auto phi = [=](Matrix<DD> &x, Matrix<DD> &fx, Matrix<DD> &B) 
        {
            auto fxpre = fx;
            auto xpre = x;
            x = x - B * fx;
            auto s = x - xpre;
            for(int j=0;j<n;++j)
                fx(j, 0) = f[j](x);
            auto y = fx - fxpre;
            auto stb = Transpose(s) * B;
            B = B + (s - B * y) * stb / (stb * y);
        };
        return Iteration(ini, phi, x0);
    }
    cerr << "错误：没有定义该方法" << '\n';
    return x0;
}
template<class DD> 
Matrix<DD> FindRoot(const vector<std::function<DD(Matrix<DD>)>> &f,const Matrix<DD> &x0)
{
    return FindRoot(f, x0, "Newton");
}
template<class DD> DD FindRoot(std::function<DD(DD)> f, DD a,DD b,string str)
{
    if(str=="bisection")
    {
        if(a>=b)
        {
            cerr << "错误：区间左端值需小于右端。" << '\n';
            return a;
        }
        if(f(a)*f(b)>0)
        {
            cerr << "错误：区间两端函数值同号，无法使用二分法。" << '\n';
            return a;
        }
        int times = 30;//迭代次数
        DD _left = a;
        DD _right=b;
        int n = 1;
        DD x = (_left + _right) / 2;
        while(n<=times)
        {
            if(f(x)==0) return x;
            if(f(_left)*f(x)<0)
            {
                _right=x;
            }
            else
            {
                _left = x;
            }
            x = (_left + _right) / 2;
            ++n;
        }
        return x;
    }
    if(str=="secant")
    {
        DD epsilon = 1e-14;
        if(Abs(a-b)<=epsilon)
        {
            cerr << "错误：弦截法的前两个初值选取的过于接近。" << '\n';
            return a;
        }
        int times = 100;//迭代次数
        int k = 0;
        DD pre = a;
        DD now = b;
        DD x =0;
        while (Abs(now-pre)>epsilon && k < times)
        {
            x = now - f(now) / (f(now) - f(pre)) * (now - pre);
            pre = now;
            now = x;
            ++k;
        } 
        if(k>=times)
        {
            cerr<<"警告：未在指定次数内达到预期精度。"<<'\n';
            cerr << "可能是初值的选择使迭代法不收敛，或者迭代函数的选择使收敛速度很慢。" << '\n';
        }
        return x;
    }
    cerr << "错误：没有定义该方法。" << '\n';
    return a;
}
template <class DD> DD FindRoot(std::function<DD(DD)> f, DD a,string str)
{
    if(str=="Newton")
    {
        std::function<DD(DD)> phi = [&](DD x) { return x-f(x) / D(f, x); };
        return Iteration(phi, a);
    }
    if(str=="multiplicity")
    {
        std::function<DD(DD)> F = [&](DD x) { return f(x) / D(f, x); };
        std::function<DD(DD)> phi = [&](DD x) { return x - F(x) / D(F, x); };
        return Iteration(phi, a);
    }
    if(str=="simplified Newton")
    {
        DD g = D(f, a);
        std::function<DD(DD)> phi = [&](DD x) { return x - f(x) / g; };
        return Iteration(phi, a);
    }
    if(str=="downhill")
    {
        DD lambda = 1;//下山因子
        DD b = 0;
        int k = 0;
        int times = 30;//下山次数
        for (k = 0; k <times;++k)
        {
            b = a - lambda * f(a) / D(f, a);
            if(Abs(f(b))<Abs(f(a)))
                break;
            lambda = lambda / 2;
        }
        if(k==times)
        {
            cerr << "警告：超出下山次数，未找到合适的下山因子。" << '\n';
        } 
        std::function<DD(DD)> phi=[&](DD x) { return x - lambda * f(x) / D(f, x); };
        return Iteration(phi, a);
    }
    cerr << "错误：没有定义该方法" << '\n';
    return a;
}
template <class DD> DD FindRoot(std::function<DD(DD)> f, DD a)
{
    return FindRoot(f, a, "Newton");
}
template <class DD> DD FindRoot(std::function<DD(DD)> f, DD a,string str,int m)
{
    if(str=="multiplicity")
    {
        std::function<DD(DD)> phi=[&](DD x) { return x - m* f(x) / D(f, x); };
        return Iteration(phi, a);
    }
    cerr << "错误：没有定义该方法" << '\n';
    return a;
}
template<class DD> DD Sqrt(DD c)
{
    std::function<DD(DD)> phi = [&](DD x) { return (x + c / x) / 2; };
    return Iteration(phi,c);
}
template<> double Sqrt<double>(double c)
{
    if(c<0)
    {
        cerr << "错误：根号下不能是负数。" << '\n';
        return NAN;
    }
    double pre=0;
    double x = 0.5*c;
    while (fabs(pre-x)>1e-14)
    {
        pre = x;
        x = 0.5 * (x + c / x);
    }
    return x;
}

//拟合与逼近
template<class DF> DF InnerProductC(const Matrix<DF> &A,const Matrix<DF> &B)
{
    return Get(Transpose(A)*B,0,0);
}
template<class DF> DF InnerProductR(const Matrix<DF> &A,const Matrix<DF> &B)
{
    return Get(A*Transpose(B),0,0);
}
template<class DI,class DF,class DG> DI InnerProduct(DF f,DG g,DI a,DI b)
{
    std::function<DI(DI)> h = [&](DI x) { return f(x) * g(x); };
    return Integrate(h, a, b);
}
template<class DF> Matrix<DF> FindFit(const Matrix<DF> &data,const vector<std::function<DF(DF)>> &phi)
{
    int m=RowSize(data);
    int n = phi.size();
    Matrix<DF> f(1,m);
    vector<Matrix<DF>> Phi(n,Matrix<DF>(1,m));
    Matrix<DF> Gram(n,n);
    Matrix<DF> B(n, 1);
    for(int j=0;j<m;++j)
    {
        for (int i = 0; i < n;++i)
            Phi[i](0,j)= phi[i](Get(data,j,0));   
        f(0, j) = Get(data, j, 1);  
    }    
    for (int i = 0; i < n;++i)
    {
        for (int j =i; j < n;++j)
            Gram(i, j) = InnerProductR(Phi[i], Phi[j]);
        B(i, 0) = InnerProductR(Phi[i], f);
    }
    for (int i = 0; i < n;++i)
        for (int j = 0; j < i;++j)
            Gram(i, j) = Gram(j, i);
    return Transpose(LinearSolve(Gram,B));
}
template<class DF> Matrix<DF> FindFit(std::function<DF(DF)> f,const vector<std::function<DF(DF)>> &phi,DF a,DF b)
{
    int n = phi.size();
    Matrix<DF> Gram(n,n);
    Matrix<DF> B(n, 1);
    for(int i=0;i<n;++i)
    {
        for (int j = i;j<n;++j)
            Gram(i, j) = InnerProduct(phi[i],phi[j],a,b);
        B(i, 0) = InnerProduct(phi[i], f, a, b);
    }
    for (int i = 0; i < n;++i)
        for (int j = 0; j < i;++j)
            Gram(i, j) = Gram(j, i);
    return Transpose(LinearSolve(Gram,B));
}
template<class DF> DF Fit(const Matrix<DF> &data,const vector<std::function<DF(DF)>> &phi,DF x)
{
    int n = phi.size();
    const Matrix<DF> &Coef=FindFit(data,phi);
    DF s = 0;
    for (int i = 0;i<n;++i)
        s = s + Get(Coef,0,i)* phi[i](x);
    return s;
}
template<class DF> DF Fit(std::function<DF(DF)> f,const vector<std::function<DF(DF)>> &phi,DF a,DF b,DF x)
{
    int n = phi.size();
    const Matrix<DF> &Coef=FindFit(f,phi,a,b);
    DF s = 0;
    for(int i=0;i<n;++i)
        s=s+Get(Coef,0,i)*phi[i](x);
    return s;
}
template<class DF> std::function<DF(DF)> Fit(const Matrix<DF> &data,const vector<std::function<DF(DF)>> &phi)
{
    return [=](double x) { return Fit(data, phi, x); };
} 
template<class DF> std::function<DF(DF)> Fit(std::function<DF(DF)> f,const vector<std::function<DF(DF)>> &phi,DF a,DF b)
{
    return [=](double x) { return Fit(f, phi, a, b, x); };
} 
template <class DB> Matrix<DB> PseudoInverse(const Matrix<DB> &A)
{
    Matrix<DB> T = Transpose(A);
    return Inverse(T * A) * T;
}
template <class DB> Matrix<DB> LeastSquares(const Matrix<DB> &A, const Matrix<DB> &y)
{
    Matrix<DB> T = Transpose(A);
    return LinearSolve(T * A, T * y);
}
template <class DB> Polynomial<DB> PolyFit(const Matrix<DB> &data, const vector<Polynomial<DB>> &phi)
{
    int m = data.row_num;
    int n = phi.size();
    Matrix<DB> A(m,n);
    Matrix<DB> y(m, 1);
    for (int i = 0;i<m;++i)
    {
        for (int j = 0;j<n;++j)
        {
            A(i,j) =Get(phi[j],data(i,0));
        }
        y(i,0) = data(i,1);
    }
    const Matrix<DB> &c = LeastSquares(A, y);
    vector<DB> r(n);
    for (int i = 0; i <n;++i)
        r[i]=c(i,0);
    return Polynomial<DB>(r);
}
template <class DB> Polynomial<DB> PolyFit(const Matrix<DB> &xy,int deg)
{
    if(xy.column_num!=2)
    {
        cerr << "错误：传入数据矩阵的列数必须为2" << '\n';
        return X;
    }
    int n = xy.row_num;
    Matrix<DB> A(n, deg + 1);
    Matrix<DB> b(n, 1);
    for (int i = 0; i < n;++i)
    {
        b(i,0) = xy(i,1);
        A(i,0) = 1;
        for(int j=1;j<=deg;++j)
        {
            A(i,j) = A.value[i][j - 1] * xy(i,0);
        }
    }
    const Matrix<DB> &c=LeastSquares(A, b);
    vector<DB> r;
    for (int i = 0; i <= deg;++i)
        r.push_back(c(i,0));
    Polynomial<DB> f(r);
    return f;
}
template <class DB> Polynomial<DB> PolyFit(std::function<DB(DB)> f,const vector<Polynomial<DB>>&phi,DB a,DB b)
{
    int n = phi.size();
    Matrix<DB> Gram(n, n);
    Matrix<DB> B(n, 1);
    for(int i=0;i<n;++i)
    {
        for (int j = i;j<n;++j)
            Gram(i, j) = InnerProduct(phi[i],phi[j],a,b);
        B(i, 0) = InnerProduct(phi[i], f, a, b);
    }
    for (int i = 0; i < n;++i)
        for (int j = 0; j < i;++j)
            Gram(i, j) = Gram(j, i);
    const Matrix<DB> &c = LinearSolve(Gram, B);
    vector<DB> r(n);
    for (int i = 0; i <n;++i)
        r[i]=c(i,0);
    return Polynomial<DB>(r);

}

//常微分方程
template<class DS,class DO,class DP> DO Iteration(const DP &phi,const pair<DS,DO> &initial,DS x,int n)
{
    if(n==0)
        return get<1>(initial);
    DS h= (x - get<0>(initial))/n;//步长
    DS xk = get<0>(initial);
    DO yk= get<1>(initial);
    for (int i = 0; i < n;++i)
    {
        phi(xk, yk, h);
        xk = xk + h;
    }
    return yk;
}
template<class DS,class DO> DO RKSolve(std::function<DO(DS,DO)> f,const pair<DS,DO>& initial,DS x,int n)
{
    auto phi = [=](DS &xk, DO &yk, DS &h) {
            DS halfh = h / 2.0;
            DS xk_plus_halfh = xk + halfh;
            DO k1=f(xk,yk);
            DO k2 =f(xk_plus_halfh,yk+halfh*k1);
            DO k3 =f(xk_plus_halfh,yk+halfh*k2);
            DO k4=f(xk+h,yk+h*k3);
            yk = yk + h / 6.0 * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        };
    return Iteration(phi, initial, x, n);
}
template<class DS,class DO,class DP,class DF> 
DO LinearMultiStep(const DP &phi,const DF &f,const pair<DS,DO> &initial,DS x,int n,int startstep)
{
    if(n==0)
        return get<1>(initial);
    DS h = (x - get<0>(initial))/n;
    std::deque<DS> xk={get<0>(initial)};
    std::deque<DO> yk={get<1>(initial)};
    std::deque<DO> fk={f(xk[0],yk[0])};
    for (int i =1; i<=std::min(startstep-1,n);++i)
    {
        yk.push_back(RKSolve(f,{xk.back(),yk.back()},xk.back()+h,1));
        xk.push_back(xk.back()+h);
        fk.push_back(f(xk.back(), yk.back()));
    }
    DO y0adpt = yk.back();
    for (int i = startstep; i <=n;++i)
    {
        phi(xk, yk, fk,h,y0adpt);
        xk.push_back(xk.back() + h);
        fk.push_back(f(xk.back(), yk.back()));
        xk.pop_front();
        yk.pop_front();
        fk.pop_front();
    }
    return yk.back();
}
template<class DS,class DO> DO DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO>& initial,DS x,int n,string str)
{
    if(str=="Euler"|| str=="forward Euler" || str=="explicit Euler")
    {
        auto phi = [=](DS &xk, DO &yk, DS &h) 
        {   yk = yk + h * f(xk, yk);
        };
        return Iteration(phi, initial, x, n);
    }
    if(str=="backward Euler" || str=="implicit Euler")
    {
        auto phi = [=](DS &xk, DO &yk, DS &h) {
            DS x_plus_h = xk + h;
            DO y=yk+h*f(xk,yk);
            for (unsigned i = 0; i <3;++i)
                y = yk + h * f(x_plus_h, y);
            yk = yk + h * f(x_plus_h, y);
        };
        return Iteration(phi, initial, x, n);
    }
    if(str=="trapz" || str=="trapezoidal")
    {
        auto phi = [=](DS &xk, DO &yk, DS &h) {
            DO fk=f(xk,yk);
            DS halfh = h / 2.0;
            DS x_plus_h = xk + h;
            DO y0 = yk + h * fk;
            DO y1=yk+halfh*(fk+f(x_plus_h,y0));
            yk = yk + halfh * (fk + f(x_plus_h, y1));
        };
        return Iteration(phi, initial, x, n);
    }
    if(str=="Heun" || str=="improved Euler")
    {
        auto phi = [=](DS &xk, DO &yk, DS &h) {
            DO k1=f(xk,yk);
            DO k2=f(xk+h,yk+h*k1);
            yk=yk+h/2.0*(k1+k2);
        };
        return Iteration(phi, initial, x, n);
    }
    if(str=="midpoint")
    {
        auto phi = [=](DS &xk, DO &yk, DS &h) {
            DS halfh = h / 2.0;
            DO k1=f(xk,yk);
            DO k2=f(xk+halfh,yk+halfh*k1);
            yk=yk+h*k2;
        };
        return Iteration(phi, initial, x, n);
    }
    if(str=="RK4" || str=="Runge-Kutta" || str=="RK")
    {
        return RKSolve(f, initial, x, n);
    }
    if(str=="Adams-Bashforth")
    {
        auto phi = [=](deque<DS> &xk, deque<DO> &yk, deque<DO> &fk, DS &h, DO &y0adpt) {
            yk.push_back(yk[1] + 3.0 / 2.0 * h * fk[1] - 1.0 / 2.0 * h * fk[0]);
        };
        return LinearMultiStep(phi, f, initial, x, n, 2);
    }
    if(str=="Adams")
    {
        auto phi = [=](deque<DS> &xk, deque<DO> &yk, deque<DO> &fk, DS &h,DO &y0adpt) {
            yk.push_back(yk[3]+h/24.0*(55.0*fk[3]-59.0*fk[2]+37.0*fk[1]-9.0*fk[0]));
        };
        return LinearMultiStep(phi, f, initial, x, n, 4);
    }
    if(str=="Milne")
    {
        auto phi = [=](deque<DS> &xk, deque<DO> &yk, deque<DO> &fk, DS &h,DO &y0adpt) {
            yk.push_back(yk[0]+4.0*h/3.0*(2.0*fk[3]-fk[2]+2.0*fk[1]));
        };
        return LinearMultiStep(phi, f, initial, x, n, 4);
    }
    if(str=="adaptive Adams")
    {
        auto phi = [=](deque<DS> &xk, deque<DO> &yk, deque<DO> &fk, DS &h,DO &y0adpt) {
            DO y0=yk[3]+h/24.0*(55.0*fk[3]-59.0*fk[2]+37.0*fk[1]-9.0*fk[0]);
            DO y1 = y0 + 251.0 * (yk[3] - y0adpt)/270.0;
            DO y2 = yk[3] + h / 24.0 * (9.0 * f(xk[3] + h, y1) + 19.0 * fk[3] - 5.0* fk[2] + fk[1]);
            yk.push_back(y2-19.0*(y2-y0)/270.0);
            y0adpt = y0;
        };
        return LinearMultiStep(phi, f, initial, x, n, 4);
    }
    if(str=="adaptive Milne-Hamming")
    {
        auto phi = [=](deque<DS> &xk, deque<DO> &yk, deque<DO> &fk, DS &h,DO &y0adpt) {
            DO y0=yk[0]+4.0*h/3.0*(2.0*fk[3]-fk[2]+2.0*fk[1]);
            DO y1=y0 + 112.0*(yk[3]-y0adpt)/121.0;
            DO y2 = (9.0 * yk[3] - yk[1]) / 8.0 + 3.0 * h / 8.0 * (f(xk[3] + h, y1)+ 2.0 * fk[3] - fk[2]);
            yk.push_back(y2 - 9.0 * (y2 - y0) / 121.0);
            y0adpt = y0;
        };
        return LinearMultiStep(phi, f, initial, x, n, 4);
    }
    cerr<<"错误：没有定义该方法"<<'\n';
    return x;
}
template<class DS,class DO> DO DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO>& initial,DS x,string str)
{
    return DSolve(f, initial, x, 100, str);
}
template<class DS,class DO> DO DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO>& initial,DS x,int n)
{
    return DSolve(f, initial, x, n,"adaptive Milne-Hamming");
}
template<class DS,class DO> DO DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO>& initial,DS x)
{
    return DSolve(f, initial, x, 100);
}
template<class DS,class DO> std::function<DO(DS)> DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO> &initial,string str)
{
    return [=](DS x) { return DSolve(f, initial, x, str); };
}
template<class DS,class DO> std::function<DO(DS)> DSolve(std::function<DO(DS,DO)> f,const pair<DS,DO> &initial)
{
    return [=](DS x) { return DSolve(f, initial, x); };
}

}
#endif