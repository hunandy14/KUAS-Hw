#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
        double *ptr = NULL;
        int Dim = 0, i=0;

        cout << "please input Dim:" ;
        cin >> Dim;
        
        // malloc the memory address
        ptr = new double[Dim];
        // set the value - method 1
        for(i=0; i<Dim; i++) *(ptr+i) = (double)(i*i);
        // show the value - method 2
        for(i=0; i<Dim; i++) cout << "ptr[" << i << "]=" << ptr[i] << endl;

        cout << "please input Dim again:" ;
        cin >> Dim;
        // before you malloc the new memory addree.
        // free the old memory address first.
        delete [] ptr;
        
        // malloc the memory address
        ptr = new double[Dim];
        // set the value - method 1
        for(i=0; i<Dim; i++) *(ptr+i) = (double)(i*i);
        // show the value - method 2
        for(i=0; i<Dim; i++) cout << "ptr[" << i << "]=" << ptr[i] << endl;


        // free the memory address
        delete [] ptr;

        return 0;
}