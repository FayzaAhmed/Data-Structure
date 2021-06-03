# Data-Structure


## Assignment1

### Problem 1 (Big Decimal):
Different variations of types int and float exist in C++ and other languages. They are usually limited by minimum and maximum values. Sometimes it is desired to have versions of these types with unlimited bounds. 
Java solves this problem by providing BigInteger and BigDecimal classes. In this problem it is required to develop a new C++ type (class) that can hold unlimited decimal integer values and performs
arithmetic operations on them. You will develop in C++ a class, BigDecimalInt that supports writing statements with extremely long integer values like these:<br />
BigDecimalInt num1("123456789012345678901234567890");<br />
BigDecimalInt num2("113456789011345678901134567890");<br />
BigDecimalInt num3 = num2 + num1;<br />
cout << "num1 = " << num1 << endl;<br />
cout << "num2 = " << num2 << endl;<br />
//236913578023691357802369135780 <br />
cout << "num2 + num1 = " << num3 << endl;<br />
The task is:
<br />1. Design the class BigDecimalInt that hasthe following public interface (set of operations available
to use by developers using the class): <br />
BigDecimalInt (string decStr); // Initialize from string and rejects bad input  <br />
BigDecimalInt (int decInt); // Initialize from integer <br />
BigDecimalInt operator+ (BigDecimalInt anotherDec); <br />
BigDecimalInt operator= (BigDecimalInt anotherDec); <br />
Intsize(); <br />
You will also need to overwrite the << operator as follows: <br />
friend ostream& operator << (ostream& out, BigDecimalInt b) <br />
Using data encapsulation, you are free to store the digits of the big decimal integer in whatever container you like. 
You might store them in an array, a vector, a string or whatever. 
These are details that are not important to the user of your class. 
You will need to build + and – operations that work on the representation you chose.
<br />2. Implement the class BigDecimalInt and write five test cases (including –ve numbers) to test it. 
Implement a program that runs the test cases and verifies the result. 



### Problem 2 (Fraction):
You will develop an application for performing calculations on fractions.
<br />1. First, develop a class Fraction that represents a fraction by one integer divided by another, e.g., 1/3 or 3/7. 
<br /> _ a. This class defines adding,subtracting, multiplying, dividing and comparing (<, >, ==, <= and >=) fractions by overloading the standard operators for these operations. 
<br /> _ b. Itshould also contain a function for reducing fractions. For example 2/6 is reduced after calling the function to 1/3, etc. 
<br /> _ c. You also need to overload I/O operators to be able to input and output fractions naturally using >> and << operators. 
<br /><br />2. Separate class specifications from implementation by creating Fraction.h forspecs and Fraction.cpp for implementation. 
<br /><br />3. Second, develop a class FractionCalculator that utilizes the class Fraction and allows the user to input a fraction and perform calculations by adding, subtracting, etc. another fraction and then keeping the result as a fraction for further calculations.



### Problem 3 (Matrix):
You will develop an application for matrix calculations.
<br />1. It is required to design and implement a generic class Matrix, in the form of a class template that accepts a type parameter. 
This way, when the class Matrix is instantiated, we decide if it should accept float, int or double, etc. 
<br />2. Matrix class holds a matrix of any size and allocates the required memory as needed.
<br />3. Matrix class should have a destructor that frees used memory at the end of lifetime of each
Matrix objects. 
<br />4. Matrix class specificationsshould be in a separate header “.h” file. 
<br />5. Itshould have a pointer to pointer attribute that points to the matrix content. 
It should have suitable constructors and methods for allocating the required memory space based on the dimensions decided by the user. 
<br />6. Overload standard operators and I/O operators to enable Matrix class with addition,subtraction and multiplication and suitable input and output capabilities. 
Add a method for matrix transpose. 
<br />7. Then develop a MatrixCalculator class which offersthe user a menu of operations to perform on int matrices as follows. 
Each of these options should be able to accept matrices of varying dimensions, which the user inputs. For multiplication, the calculator should check that two matrices are of dimensions n x m and m x p. <br />
**Welcome to (Your Name) Matrix Calculator** <br />
 1. Perform Matrix Addition
 2. Perform Matrix Subtraction
 3. Perform Matrix Multiplication
 4. Matrix Transpose
