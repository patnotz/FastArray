#ifndef FASTARRAY_HPP_
#define FASTARRAY_HPP_

namespace fa {

typedef double ScalarT;
typedef unsigned IndexT;

//
// Type promotion -- helper template for deducing
// the appropriate return type for operations
// involving different types
//
template <class T1, class T2> struct promote {};
template <class T> struct promote<T,T> {
  typedef T type;
};
#define FA_PROMOTE(TYPE1,TYPE2,RESULT_TYPE) \
  template <> struct promote<TYPE1,TYPE2> { \
    typedef RESULT_TYPE type; \
  }; \
  template <> struct promote<TYPE2,TYPE1> { \
    typedef RESULT_TYPE type; \
  };

FA_PROMOTE(double,float,double);
FA_PROMOTE(double,int,double);
FA_PROMOTE(double,long,double);
FA_PROMOTE(double,unsigned,double);
FA_PROMOTE(float,int,float);
FA_PROMOTE(float,long,float);
FA_PROMOTE(float,unsigned,float);
#undef FA_PROMOTE

//
// Term wrapper -- helper template that allows
// POD types, FastArrays and Expression Templates
// to be treated polymorphically
//
template <class T>
struct term {
  typedef term<T> TermT;
  typedef typename T::ValueT ValueT;
  // implicit constructor
  term(const T & t) : m_t(t) {}
  ScalarT operator[](const IndexT i) const {
    return m_t[i];
  }
  const T & m_t;
};


//
// FastArray - array class with Expression Template
// support and designed for SIMD vectorization
//
struct FastArray {
  typedef ScalarT ValueT;

  FastArray() : m_x(0), m_size(0) {}

  FastArray(const IndexT size) : m_x(0), m_size(size) {
    m_x = new ScalarT[m_size];
    // not initialized for efficiency
  }

  FastArray(const IndexT size, const ScalarT val) : m_x(0), m_size(size) {
    m_x = new ScalarT[m_size];
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = val;
  }

  FastArray(const FastArray & other) {
    m_size = other.m_size;
    m_x = new ScalarT[m_size];
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = other.m_x[i];
  }

  FastArray & operator=(const FastArray & other) {
    if(this == &other)
      return *this;

    // need to resize : FIXME: size vs. capacity
    if (m_size != other.m_size) {
      if (m_x != 0) delete[] m_x;
      m_size = other.m_size;
      m_x = new ScalarT[m_size];
    }
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = other.m_x[i];
    return *this;
  }

  ~FastArray() {
    if ( m_x != 0 ) delete[] m_x;
  }

  FastArray & operator=(const ScalarT & value) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = value;
    return *this;
  }

  template <class T>
  FastArray & operator=(const term<T> & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] = rhs[i];
    return *this;
  }

  template <class T>
  FastArray & operator+=(const term<T> & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] += rhs[i];
    return *this;
  }

  template <class T>
  FastArray & operator-=(const term<T> & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] -= rhs[i];
    return *this;
  }

  template <class T>
  FastArray & operator*=(const term<T> & rhs) {
    for(IndexT i=0; i < m_size; ++i)
      m_x[i] *= rhs[i];
    return *this;
  }

  template <class T>
  FastArray & operator/=(const term<T> & rhs) {
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
  IndexT size() const {
    return m_size;
  }
private:
  ScalarT * m_x;
  IndexT m_size;
};

template <>
struct term<FastArray> {
  typedef term<FastArray> TermT;
  typedef ScalarT ValueT;
  // implicit constructor
  term(const FastArray & fa) : m_fa(fa) {}
  const ScalarT & operator[](const IndexT i) const {
    return m_fa[i];
  }
  const FastArray & m_fa;
};

template <>
struct term<ScalarT> {
  typedef term<ScalarT> TermT;
  typedef ScalarT ValueT;
  // implicit constructor
  term(const ScalarT c) : m_c(c) {}
  const ScalarT & operator[](const IndexT) const {
    return m_c;
  }
  const ScalarT m_c;
};

#define FA_BINARY_OP(LABEL,OPERATOR,EXPR) \
template <class L, class R> struct LABEL {}; \
\
template <class L, class R> \
struct term< LABEL< term<L>, term<R> > > { \
  typedef term<L> TermL; \
  typedef term<R> TermR; \
  typedef typename TermL::ValueT ValueTL; \
  typedef typename TermR::ValueT ValueTR; \
  typedef typename promote<ValueTL,ValueTR>::type ValueT; \
  term(const term<L> & left, const term<R> & right) : \
    m_left(left), m_right(right) {} \
  ValueT operator[](const IndexT i) const { \
    return EXPR; \
  } \
  const term<L> m_left; \
  const term<R> m_right; \
}; \
\
template <class L, class R> \
inline term< LABEL< term<L>, term<R> > > \
OPERATOR(const L & left, const R & right) { \
  typedef LABEL< term<L>, term<R> > TermT; \
  return term<TermT>(left,right); \
}

FA_BINARY_OP(addition,       operator+, m_left[i] + m_right[i]);
FA_BINARY_OP(subtraction,    operator-, m_left[i] - m_right[i]);
FA_BINARY_OP(mulitiplication,operator*, m_left[i] * m_right[i]);
FA_BINARY_OP(division,       operator/, m_left[i] / m_right[i]);
#undef FA_BINARY_OP

} // namespace fa

#endif // FASTARRAY_HPP_
