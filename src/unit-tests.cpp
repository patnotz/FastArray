#include <gtest/gtest.h>
#include <FastArray.hpp>

// This test is mostly meant as a concise example of how to parse and access
// Json data and to make sure the build is working. It's not meant to an
// exhaustive test of the JsonCPP package.
TEST(FastArray, pass)
{
  const fa::IndexT size = 1000;
  fa::FastArray fa(size);
  for(int i=0; i < size; ++i) {
    fa[i] = double(i);
  }
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(double(i), fa[i]);
  }
}

TEST(FastArray, ctor_size_val)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  fa::FastArray fb(size,a);
  ASSERT_EQ(size, fb.size());
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, set_all)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  fa::FastArray fb(size);
  fb = a;
  ASSERT_EQ(size, fb.size());
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, copy_ctor)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  fa::FastArray fa(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
  }

  fa::FastArray fb(fa);

  ASSERT_EQ(fa.size(), fb.size());
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, operator_equal)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  fa::FastArray fa(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
  }

  fa::FastArray fb;
  fb = fa;

  ASSERT_EQ(size, fb.size());
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, operator_equal_with_different_size)
{
  const fa::IndexT a_size = 1000;
  const fa::ScalarT a = 3;
  fa::FastArray fa(a_size);
  for(int i=0; i < a_size; ++i) {
    fa[i] = a;
  }

  const fa::IndexT b_size = 10;
  fa::FastArray fb(b_size);
  fb = fa;

  ASSERT_EQ(a_size, fb.size());
  for(int i=0; i < a_size; ++i) {
    ASSERT_DOUBLE_EQ(a, fb[i]);
  }
}

TEST(FastArray, plus)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }

  const fa::ScalarT c = a + b;
  fc = fa + fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, minus)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a - b;
  fc = fa - fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, multiply)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a * b;
  fc = fa * fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, divide)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
  }
  const fa::ScalarT c = a / b;
  fc = fa / fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, plus_plus)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  const fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  fa::FastArray fd(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  const fa::ScalarT d = a + b + c;
  fd = fa + fb + fc;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(d, fd[i]);
  }
}

TEST(FastArray, mult_plus)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  const fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  fa::FastArray fd(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  const fa::ScalarT d = a * (b + c);
  fd = fa * (fb + fc);

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(d, fd[i]);
  }
}

TEST(FastArray, plus_equals)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c += a + b;
  fc += fa + fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, minus_equals)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c -= a + b;
  fc -= fa + fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, multiply_equals)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c *= a + b;
  fc *= fa + fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, divide_equals)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;
  fa::ScalarT c = 11;

  fa::FastArray fa(size);
  fa::FastArray fb(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
    fb[i] = b;
    fc[i] = c;
  }
  c /= a + b;
  fc /= fa + fb;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, plus_double)
{
  const fa::IndexT size = 1000;
  const fa::ScalarT a = 3;
  const fa::ScalarT b = 4;

  fa::FastArray fa(size);
  fa::FastArray fc(size);
  for(int i=0; i < size; ++i) {
    fa[i] = a;
  }
  const fa::ScalarT c = a + b;
  fc = fa + b;

  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(c, fc[i]);
  }
}

TEST(FastArray, complext_binop)
{
  const fa::IndexT size = 1000;
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
  for(int i=0; i < size; ++i) {
    ASSERT_DOUBLE_EQ(f, ff[i]);
  }
}
