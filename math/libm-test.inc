/* Copyright (C) 1997-2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Jaeger <aj@suse.de>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* The bulk of the implementation, other than the tests of individual
   functions, is in a separate file.  */
#include "libm-test-driver.c"

/****************************************************************************
  Tests for single functions of libm.
  Please keep them alphabetically sorted!
****************************************************************************/

#include "libm-test-acos.c"
#include "libm-test-acosh.c"
#include "libm-test-asin.c"
#include "libm-test-asinh.c"
#include "libm-test-atan.c"
#include "libm-test-atan2.c"
#include "libm-test-atanh.c"
#include "libm-test-cabs.c"
#include "libm-test-cacos.c"
#include "libm-test-cacosh.c"
#include "libm-test-canonicalize.c"
#include "libm-test-carg.c"
#include "libm-test-casin.c"
#include "libm-test-casinh.c"
#include "libm-test-catan.c"
#include "libm-test-catanh.c"
#include "libm-test-cbrt.c"
#include "libm-test-ccos.c"
#include "libm-test-ccosh.c"
#include "libm-test-ceil.c"
#include "libm-test-cexp.c"
#include "libm-test-cimag.c"
#include "libm-test-clog.c"
#include "libm-test-clog10.c"
#include "libm-test-conj.c"
#include "libm-test-copysign.c"
#include "libm-test-cos.c"
#include "libm-test-cosh.c"
#include "libm-test-cpow.c"
#include "libm-test-cproj.c"
#include "libm-test-creal.c"
#include "libm-test-csin.c"
#include "libm-test-csinh.c"
#include "libm-test-csqrt.c"
#include "libm-test-ctan.c"
#include "libm-test-ctanh.c"
#include "libm-test-erf.c"
#include "libm-test-erfc.c"
#include "libm-test-exp.c"
#include "libm-test-exp10.c"
#include "libm-test-exp2.c"
#include "libm-test-expm1.c"
#include "libm-test-fabs.c"
#include "libm-test-fdim.c"
#include "libm-test-floor.c"
#include "libm-test-fma.c"
#include "libm-test-fmax.c"
#include "libm-test-fmaxmag.c"
#include "libm-test-fmin.c"
#include "libm-test-fminmag.c"
#include "libm-test-fmod.c"
#include "libm-test-fpclassify.c"
#include "libm-test-frexp.c"
#include "libm-test-fromfp.c"
#include "libm-test-fromfpx.c"
#include "libm-test-getpayload.c"
#include "libm-test-hypot.c"
#include "libm-test-ilogb.c"
#include "libm-test-iscanonical.c"
#include "libm-test-iseqsig.c"
#include "libm-test-isfinite.c"
#include "libm-test-isgreater.c"
#include "libm-test-isgreaterequal.c"
#include "libm-test-isinf.c"
#include "libm-test-isless.c"
#include "libm-test-islessequal.c"
#include "libm-test-islessgreater.c"
#include "libm-test-isnan.c"
#include "libm-test-isnormal.c"
#include "libm-test-issignaling.c"
#include "libm-test-issubnormal.c"
#include "libm-test-isunordered.c"
#include "libm-test-iszero.c"
#include "libm-test-j0.c"
#include "libm-test-j1.c"
#include "libm-test-jn.c"
#include "libm-test-lgamma.c"
#include "libm-test-llogb.c"
#include "libm-test-llrint.c"
#include "libm-test-llround.c"
#include "libm-test-log.c"
#include "libm-test-log10.c"
#include "libm-test-log1p.c"
#include "libm-test-log2.c"
#include "libm-test-logb.c"
#include "libm-test-lrint.c"
#include "libm-test-lround.c"
#include "libm-test-modf.c"
#include "libm-test-nearbyint.c"
#include "libm-test-nextafter.c"
#include "libm-test-nextdown.c"
#include "libm-test-nexttoward.c"
#include "libm-test-nextup.c"
#include "libm-test-pow.c"
#include "libm-test-remainder.c"
#include "libm-test-remquo.c"
#include "libm-test-rint.c"
#include "libm-test-round.c"
#include "libm-test-roundeven.c"
#include "libm-test-scalb.c"
#include "libm-test-scalbln.c"
#include "libm-test-scalbn.c"
#include "libm-test-setpayload.c"
#include "libm-test-setpayloadsig.c"
#include "libm-test-signbit.c"
#include "libm-test-significand.c"
#include "libm-test-sin.c"
#include "libm-test-sincos.c"
#include "libm-test-sinh.c"
#include "libm-test-sqrt.c"
#include "libm-test-tan.c"
#include "libm-test-tanh.c"
#include "libm-test-tgamma.c"
#include "libm-test-totalorder.c"
#include "libm-test-totalordermag.c"
#include "libm-test-trunc.c"
#include "libm-test-ufromfp.c"
#include "libm-test-ufromfpx.c"
#include "libm-test-y0.c"
#include "libm-test-y1.c"
#include "libm-test-yn.c"

static void
do_test (void)
{
  /* Keep the tests a wee bit ordered (according to ISO C99).  */
  /* Classification macros:  */
  finite_test ();
  fpclassify_test ();
  iscanonical_test ();
  isfinite_test ();
  isinf_test ();
  isnan_test ();
  isnormal_test ();
  issignaling_test ();
  issubnormal_test ();
  iszero_test ();
  signbit_test ();

  /* Trigonometric functions:  */
  acos_test ();
  asin_test ();
  atan_test ();
  atan2_test ();
  cos_test ();
  sin_test ();
  sincos_test ();
  tan_test ();

  /* Hyperbolic functions:  */
  acosh_test ();
  asinh_test ();
  atanh_test ();
  cosh_test ();
  sinh_test ();
  tanh_test ();

  /* Exponential and logarithmic functions:  */
  exp_test ();
  exp10_test ();
  exp2_test ();
  expm1_test ();
  frexp_test ();
  ldexp_test ();
  log_test ();
  log10_test ();
  log1p_test ();
  log2_test ();
  logb_test ();
  modf_test ();
  pow10_test ();
  ilogb_test ();
  llogb_test ();
  scalb_test ();
  scalbn_test ();
  scalbln_test ();
  significand_test ();

  /* Power and absolute value functions:  */
  cbrt_test ();
  fabs_test ();
  hypot_test ();
  pow_test ();
  sqrt_test ();

  /* Error and gamma functions:  */
  erf_test ();
  erfc_test ();
  gamma_test ();
  lgamma_test ();
  tgamma_test ();

  /* Nearest integer functions:  */
  ceil_test ();
  floor_test ();
  nearbyint_test ();
  rint_test ();
  lrint_test ();
  llrint_test ();
  round_test ();
  roundeven_test ();
  lround_test ();
  llround_test ();
  trunc_test ();
  fromfp_test ();
  fromfpx_test ();
  ufromfp_test ();
  ufromfpx_test ();

  /* Remainder functions:  */
  drem_test ();
  fmod_test ();
  remainder_test ();
  remquo_test ();

  /* Manipulation functions:  */
  copysign_test ();
  nextup_test();
  nextdown_test();
  nextafter_test ();
  nexttoward_test ();

  /* maximum, minimum and positive difference functions */
  fdim_test ();
  fmax_test ();
  fmaxmag_test ();
  fmin_test ();
  fminmag_test ();

  /* Multiply and add:  */
  fma_test ();

  /* Comparison macros:  */
  iseqsig_test ();
  isgreater_test ();
  isgreaterequal_test ();
  isless_test ();
  islessequal_test ();
  islessgreater_test ();
  isunordered_test ();

  /* Total order functions:  */
  totalorder_test ();
  totalordermag_test ();

  /* Canonicalize functions:  */
  canonicalize_test ();

  /* NaN functions:  */
  getpayload_test ();
  setpayload_test ();
  setpayloadsig_test ();

  /* Complex functions:  */
  cabs_test ();
  cacos_test ();
  cacosh_test ();
  carg_test ();
  casin_test ();
  casinh_test ();
  catan_test ();
  catanh_test ();
  ccos_test ();
  ccosh_test ();
  cexp_test ();
  cimag_test ();
  clog10_test ();
  clog_test ();
  conj_test ();
  cpow_test ();
  cproj_test ();
  creal_test ();
  csin_test ();
  csinh_test ();
  csqrt_test ();
  ctan_test ();
  ctanh_test ();

  /* Bessel functions:  */
  j0_test ();
  j1_test ();
  jn_test ();
  y0_test ();
  y1_test ();
  yn_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */
