#include<iostream>
#include<cstdlib>
using namespace std;

class Polynomial
{
  private:
    // Variables to store information about polynomial
    int no_of_terms;
    int *coefficients;
  public:
    Polynomial()
    {
      // Behavior of default constructor
      no_of_terms = 0;
      coefficients = NULL;
    }
    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      no_of_terms = deg + 1;
      coefficients = new int[no_of_terms];
    }
    Polynomial(Polynomial &P)
    {
      // Copy Constructor
      no_of_terms = P.no_of_terms;
      coefficients = new int[no_of_terms];
      for(int i = P.no_of_terms-1; i >= 0; i--)
        coefficients[i] = P.coefficients[i];
    }

    Polynomial operator + (Polynomial& P)
    {
      // + Operator Overloading
      int i, j, k = 0;
      int terms = (no_of_terms > P.no_of_terms) ? no_of_terms : P.no_of_terms;
      Polynomial result(terms - 1);
      for(i = 0, j = 0; i < no_of_terms && j < P.no_of_terms; )
          result.coefficients[k++] = coefficients[i++] + P.coefficients[j++];
      if(i < no_of_terms)
        while(i < no_of_terms)
          result.coefficients[k++] = coefficients[i++];
      else if(j < P.no_of_terms)
        while(j < P.no_of_terms)
          result.coefficients[k++] = P.coefficients[j++];
      return result;
    }
    Polynomial operator - (Polynomial& P)
    {
      // - Operator Overloading
      int i, j, k = 0;
      int terms = (no_of_terms > P.no_of_terms) ? no_of_terms : P.no_of_terms;
      Polynomial result(terms - 1);
      for(i = 0, j = 0; i < no_of_terms && j < P.no_of_terms; )
          result.coefficients[k++] = coefficients[i++] - P.coefficients[j++];
      if(i < no_of_terms)
        while(i < no_of_terms)
          result.coefficients[k++] = coefficients[i++];
      else if(j < P.no_of_terms)
        while(j < P.no_of_terms)
          result.coefficients[k++] = -P.coefficients[j++];
      return result;
    }
    Polynomial& operator = (const Polynomial &P)
    {
      // = Operator Overloading
      no_of_terms = P.no_of_terms;
      coefficients = new int[no_of_terms];
      for(int i = P.no_of_terms-1; i >= 0; i--)
        coefficients[i] = P.coefficients[i];
      return *this;
    }

    ~Polynomial()
    {
      // Behavior of destructor
      delete[] coefficients;
    }

    void storePolynomial()
    {
      //  Code to enter and store polynomial
      cout<<"Enter the coefficients of the variable with decreasing order of their degrees..."<<endl;
      for(int i = no_of_terms - 1; i >= 0; i--)
        cin>>coefficients[i];
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      for(int i = no_of_terms - 1; i >= 0; i--)
      {
        cout<<coefficients[i];
        if(i != 0)
          cout<<"x^"<<i<<" + ";
      }
    }
};

int main()
{
  int degFirst, degSecond;
  char choice = 'N';
  do
  {
    system("cls");
    cout<<"\t Addition and Subtraction of Polynomials!!!\n";
    cout<<"Enter the highest degree of first and second polynomials: ";
    cin>>degFirst>>degSecond;
    if(degFirst < 0 || degSecond < 0)
      cout<<"Invalid Degrees of Polynomial!!!";
    else
    {
    Polynomial firstPolynomial(degFirst);
    Polynomial secondPolynomial(degSecond);
    Polynomial thirdPolynomial;
    Polynomial fourthPolynomial;
    system("cls");
    cout<<"1st Polynomial...\n"<<endl;
    firstPolynomial.storePolynomial();
    system("cls");
    cout<<"2nd Polynomial...\n"<<endl;
    secondPolynomial.storePolynomial();
    system("cls");
    thirdPolynomial = firstPolynomial + secondPolynomial;
    fourthPolynomial = firstPolynomial - secondPolynomial;
    cout<<"\t Addition and Subtraction of Polynomial\n";
    cout<<"1st Polynomial: ";
    firstPolynomial.display();
    cout<<"\n2nd Polynomial: ";
    secondPolynomial.display();
    cout<<"\nThe Added Polynomial: ";
    thirdPolynomial.display();
    cout<<"\nThe Subtracted Polynomial: ";
    fourthPolynomial.display();
    }
    cout<<endl<<"\nDo you want to operate more (Y/N): ";
    cin>>choice;
  }while(choice == 'Y' || choice == 'y');
  return 0;
}
