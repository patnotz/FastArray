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
