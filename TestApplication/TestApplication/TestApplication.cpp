// TestApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <complex>
#include "include\GnuSLcomplex.h"


int main()
{
    std::complex<double> a{1,3};
    std::complex<double> b{2,3};
    b = GnuSL::pow(a,b);
    return 0;
}

