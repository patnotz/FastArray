#include <gtest/gtest.h>
#include <FastArray.hpp>

const fa::IndexT SIZE = 100000;

// This test is mostly meant as a concise example of how to parse and access
// Json data and to make sure the build is working. It's not meant to an
// exhaustive test of the JsonCPP package.
TEST(FastArray, resize)
{
  const fa::IndexT orig_size = SIZE;
  fa::FastArray fa(orig_size);
  ASSERT_EQ(orig_size,fa.size());
  ASSERT_EQ(orig_size,fa.capacity());

  const fa::IndexT smaller_size = SIZE / 2;
  fa.resize(smaller_size);
  ASSERT_EQ(smaller_size,fa.size());
  ASSERT_EQ(orig_size,fa.capacity());

  const fa::IndexT bigger_size = SIZE * 2;
  fa.resize(bigger_size);
  ASSERT_EQ(bigger_size,fa.size());
  ASSERT_EQ(bigger_size,fa.capacity());

  fa.resize(smaller_size);
  ASSERT_EQ(smaller_size,fa.size());
  ASSERT_EQ(bigger_size,fa.capacity());
}

TEST(FastArray, operator_bracket)
{
  const fa::IndexT size = SIZE;
  fa::FastArray fa(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = double(i);
  }
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(double(i), fa[i]);
  }
}

TEST(FastArray, ctor_size_val)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  fa::FastArray fb(size,a);
  ASSERT_EQ(size, fb.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, set_all)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  fa::FastArray fb(size);
  fb = a;
  ASSERT_EQ(size, fb.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, copy_ctor)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  fa::FastArray fa(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
  }

  fa::FastArray fb(fa);

  ASSERT_EQ(fa.size(), fb.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, operator_equal)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  fa::FastArray fa(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
  }

  fa::FastArray fb;
  fb = fa;

  ASSERT_EQ(size, fb.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, operator_equal_with_different_size)
{
  const fa::IndexT a_size = SIZE;
  const fa::ScalarT a = 3;
  fa::FastArray fa(a_size);
  for(fa::IndexT i=0; i < a_size; ++i) {
    fa[i] = a;
  }

  const fa::IndexT b_size = SIZE / 10;
  fa::FastArray fb(b_size);
  fb = fa;

  ASSERT_EQ(a_size, fb.size());
  for(fa::IndexT i=0; i < a_size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, plus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }

  const fa::ScalarT c = a + b;
  fc = fa + fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, minus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a - b;
  fc = fa - fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, multiply)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a * b;
  fc = fa * fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, divide)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a / b;
  fc = fa / fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, plus_plus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  const fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  fa::FastArray fd(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  const fa::ScalarT d = a + b + c;
  fd = fa + fb + fc;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(d, fd[i]);
  }
}

TEST(FastArray, mult_plus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  const fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  fa::FastArray fd(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  const fa::ScalarT d = a * (b + c);
  fd = fa * (fb + fc);

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(d, fd[i]);
  }
}

TEST(FastArray, plus_equals)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c += a + b;
  fc += fa + fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, minus_equals)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c -= a + b;
  fc -= fa + fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, multiply_equals)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  fa = a;
  fb = b;
  fc = c;
  c *= a + b;
  fc *= fa + fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, divide_equals)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c /= a + b;
  fc /= fa + fb;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, plus_double)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fc(size);
  for(fa::IndexT i=0; i < size; ++i) {
    fa[i] = a;
  }
  const fa::ScalarT c = a + b;
  fc = fa + b;

  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, several_binop)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 5;
  const fa::ScalarT c = 7;
  const fa::ScalarT d = 11;
  const fa::ScalarT e = 13;

  fa::FastArray fa(size,a);
  fa::FastArray fb(size,b);
  fa::FastArray fc(size,c);
  fa::FastArray fd(size,d);

  const fa::ScalarT f = a + b * c / (d + e);
  fa::FastArray ff(size);
  ff = fa + fb * fc / (fd + e);

  ASSERT_EQ(size,ff.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(f, ff[i]);
  }
}

TEST(FastArray, unary_minus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;

  fa::FastArray fa(size, a);
  fa::FastArray fb(size);
  fb = -fa;
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(-a, fb[i]);
  }
}

TEST(FastArray, unary_plus)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;

  fa::FastArray fa(size, a);
  fa::FastArray fb(size);
  fb = +fa;
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

#define TEST_STD_MATH_UNARY(TESTNAME, FCN, VAL) \
TEST(FastArray, TESTNAME) \
{ \
  const fa::IndexT size = SIZE; \
  const fa::ScalarT a = VAL; \
 \
  fa::FastArray fa(size, a); \
  fa::FastArray fb(size); \
  fb = FCN(fa); \
  const fa::ScalarT b = std::FCN(a); \
 \
  for(fa::IndexT i=0; i < size; ++i) { \
    ASSERT_DOUBLE_EQ(b, fb[i]); \
  } \
}

TEST_STD_MATH_UNARY(math_exp,exp,3);
TEST_STD_MATH_UNARY(math_log,log,3);
TEST_STD_MATH_UNARY(math_log10,log10,3);
TEST_STD_MATH_UNARY(math_sqrt,sqrt,7);

TEST_STD_MATH_UNARY(math_cos,cos,2.1);
TEST_STD_MATH_UNARY(math_sin,sin,2.1);
TEST_STD_MATH_UNARY(math_tan,tan,2.1);
TEST_STD_MATH_UNARY(math_acos,acos,0.7);
TEST_STD_MATH_UNARY(math_asin,asin,0.7);
TEST_STD_MATH_UNARY(math_atan,atan,0.7);

TEST_STD_MATH_UNARY(math_cosh,cosh,2.1);
TEST_STD_MATH_UNARY(math_sinh,sinh,2.1);
TEST_STD_MATH_UNARY(math_tanh,tanh,2.1);

TEST_STD_MATH_UNARY(math_abs_pos,abs,1.1);
TEST_STD_MATH_UNARY(math_abs_neg,abs,-1.1);
TEST_STD_MATH_UNARY(math_fabs_pos,fabs,1.1);
TEST_STD_MATH_UNARY(math_fabs_neg,fabs,-1.1);
#undef TEST_STD_MATH_UNARY

#define TEST_STD_MATH_BINARY(TESTNAME, FCN, VAL_A, VAL_B, OBJ_A, OBJ_B) \
TEST(FastArray, TESTNAME) \
{ \
  const fa::IndexT size = SIZE; \
  const fa::ScalarT a = VAL_A; \
  const fa::ScalarT b = VAL_B; \
 \
  fa::FastArray fa(size, a); \
  fa::FastArray fb(size, b); \
  fa::FastArray fc(size); \
  fc = FCN(OBJ_A,OBJ_B); \
  const fa::ScalarT c = std::FCN(a,b); \
 \
  for(fa::IndexT i=0; i < size; ++i) { \
    ASSERT_DOUBLE_EQ(c, fc[i]); \
  } \
}
TEST_STD_MATH_BINARY(math_pow_aa, pow, 2, 3, fa, fb);
TEST_STD_MATH_BINARY(math_pow_ac, pow, 2, 3, fa, b);
TEST_STD_MATH_BINARY(math_pow_ca, pow, 2, 3, a, fb);
TEST_STD_MATH_BINARY(math_pow_cc, pow, 2, 3, a, b);
TEST_STD_MATH_BINARY(math_max_aa, max, 2, 3, fa, fb);
TEST_STD_MATH_BINARY(math_max_ac, max, 2, 3, fa, b);
TEST_STD_MATH_BINARY(math_max_ca, max, 2, 3, a, fb);
TEST_STD_MATH_BINARY(math_min_aa, min, 2, 3, fa, fb);
TEST_STD_MATH_BINARY(math_min_ac, min, 2, 3, fa, b);
TEST_STD_MATH_BINARY(math_min_ca, min, 2, 3, a, fb);
TEST_STD_MATH_BINARY(math_atan2_aa, atan2, 2, 3, fa, fb);
TEST_STD_MATH_BINARY(math_atan2_ac, atan2, 2, 3, fa, b);
TEST_STD_MATH_BINARY(math_atan2_ca, atan2, 2, 3, a, fb);
TEST_STD_MATH_BINARY(math_atan2_cc, atan2, 2, 3, a, b);
#undef TEST_STD_MATH_BINARY

TEST(FastArray, kitchen_sink)
{
  const fa::IndexT size = SIZE;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 5;
  const fa::ScalarT c = 7;
  const fa::ScalarT d = 11;
  const fa::ScalarT e = 13;

  fa::FastArray fa(size,a);
  fa::FastArray fb(size,b);
  fa::FastArray fc(size,c);
  fa::FastArray fd(size,d);

  const fa::ScalarT f = log10(exp(a) + cos(b) * pow(c,2.5) / (-d + e));
  fa::FastArray ff(size);
  ff = log10(exp(fa) + cos(fb) * pow(fc,2.5) / (-fd + e));

  ASSERT_EQ(size,ff.size());
  for(fa::IndexT i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(f, ff[i]);
  }
}

