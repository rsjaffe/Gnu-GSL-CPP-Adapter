#pragma once
#include <complex>
#include "gsl\complex\gsl_complex_math.h"

namespace GnuSL
{
    auto cplxb = [](auto binary) {
        return [=](std::complex<double> a, std::complex<double>  b) {
            gsl_complex arga = gsl_complex_rect(a.real(), a.imag());
            gsl_complex argb = gsl_complex_rect(b.real(), b.imag());
            gsl_complex ret = binary(arga, argb);
            return std::complex<double>{GSL_REAL(ret), GSL_IMAG(ret)};
        };
    };

    auto cplxu = [](auto unary) {
        return [=](std::complex<double> a) {
            gsl_complex arga = gsl_complex_rect(a.real(), a.imag());
            gsl_complex ret = unary(arga);
            return std::complex<double>{GSL_REAL(ret), GSL_IMAG(ret)};
        };
    };

    auto cplxur = [](auto unary) {
        return [=](std::complex<double> a) {
            gsl_complex arga = gsl_complex_rect(a.real(), a.imag());
            return unary(arga);
        };
    };

    auto pow = cplxb(gsl_complex_pow);
    auto arg = cplxur(gsl_complex_arg);
    auto abs = cplxur(gsl_complex_abs);
    auto abs2 = cplxur(gsl_complex_abs2);
    auto logabs = cplxur(gsl_complex_logabs);
    auto add = cplxb(gsl_complex_add);

};