#ifndef FASTARRAY_HPP_
#define FASTARRAY_HPP_

namespace fa {

typedef double ScalarT;
typedef unsigned IndexT;

struct FastArray {
public:
  FastArray() : m_x(0) {}
  FastArray(const IndexT size) : m_x(0), m_size(size) {
    m_x = new ScalarT[size];
  }
  ~FastArray() {
    if ( m_x != 0 ) delete[] m_x;
  }

  template <class RHS>
  FastArray & operator=(const RHS & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = rhs[i];
    return *this;
  }

  template <class RHS>
  FastArray & operator+=(const RHS & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] += rhs[i];
    return *this;
  }

  template <class RHS>
  FastArray & operator-=(const RHS & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] -= rhs[i];
    return *this;
  }

  template <class RHS>
  FastArray & operator*=(const RHS & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] *= rhs[i];
    return *this;
  }

  template <class RHS>
  FastArray & operator/=(const RHS & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] /= rhs[i];
    return *this;
  }

  ScalarT & operator[](const IndexT i) {
    return m_x[i];
  }
  const ScalarT & operator[](const IndexT i) const {
    return m_x[i];
  }


private:
  ScalarT * m_x;
  IndexT m_size;
};

template <class L, class OpTag, class R>
struct BinaryOp {
  BinaryOp(const L & left_, const R & right_) :
    left(left_), right(right_) {}

  ScalarT operator[](IndexT i) const {
    return OpTag::apply(left[i],right[i]);
  }

  const L & left;
  const R & right;
};

struct plus {
  static ScalarT apply(const ScalarT a, const ScalarT b) {
    return a + b;
  }
};

template <class L, class R>
BinaryOp<L,plus,R> operator+(const L & left, const R & right) {
  return BinaryOp<L,plus,R>(left,right);
}

struct minus {
  static ScalarT apply(const ScalarT a, const ScalarT b) {
    return a - b;
  }
};

template <class L, class R>
BinaryOp<L,minus,R> operator-(const L & left, const R & right) {
  return BinaryOp<L,minus,R>(left,right);
}

struct mult {
  static ScalarT apply(const ScalarT a, const ScalarT b) {
    return a * b;
  }
};

template <class L, class R>
BinaryOp<L,mult,R> operator*(const L & left, const R & right) {
  return BinaryOp<L,mult,R>(left,right);
}

struct divide {
  static ScalarT apply(const ScalarT a, const ScalarT b) {
    return a / b;
  }
};

template <class L, class R>
BinaryOp<L,divide,R> operator/(const L & left, const R & right) {
  return BinaryOp<L,divide,R>(left,right);
}


} // namespace fa

#endif // FASTARRAY_HPP_
