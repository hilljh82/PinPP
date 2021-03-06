// -*- C++ -*-

//==============================================================================
/**
 *  @file        Callback.h
 *
 *  $Id: Callback.h 2302 2013-10-05 05:54:21Z hillj $
 *
 *  @author      James H. Hill
 */
//==============================================================================

#ifndef _OASIS_PIN_CALLBACK_H_
#define _OASIS_PIN_CALLBACK_H_

#include "pin.H"
#include "Arg_List.h"
#include "Insert_T.h"

namespace OASIS
{
namespace Pin
{

// Forward decl.
class Ins;

// Forward decl.
class Bbl;

// Forward decl.
class Routine;

///////////////////////////////////////////////////////////////////////////////
// class Callback_Guard

/**
 * @class Callback_Guard
 *
 * Wrapper class that handles executing _InsertIfCall and _InsertThenCall
 * for the sampling cb and the analysis cb. The wrapper ensures
 * that the same object and location is applied to either cb object. 
 * This is necessary per the Pin specification.
 */
template <typename GUARD, typename CALLBACK>
class Callback_Guard
{
public:
  /// Type definition of the guard type.
  typedef GUARD guard_type;

  /// Type definition of the cb type.
  typedef CALLBACK callback_type;

  /**
   * Initializing constructor
   *
   * @param[in]       guard         Reference to conditional cb object
   * @param[in]       cb      Callback object being guareded 
   */
  Callback_Guard (GUARD & guard, CALLBACK & cb)
    : guard_ (guard),
      callback_ (cb) { }

  /**
   * Copy constructor.
   */
  Callback_Guard (const Callback_Guard & src)
    : guard_ (src.guard_),
      callback_ (src.callback_) { }

  /**
   * Assignment operator
   */
  const Callback_Guard & operator = (const Callback_Guard & rhs)
  {
    this->guard_ = rhs.guard_;
    this->callback_ = rhs.callback_;

    return *this;
  }

  /**
   * Insert the conditional cb and the regular cb into the 
   * \a obj at the specification \a location.
   *
   * @param[in]       location        Location to perform insert
   * @param[in]       obj             Target object for insert
   */
  template <typename S>
  void insert (IPOINT location, const S & obj)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1>
  void insert (IPOINT location, const S & obj, XARG1 xarg1)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1, typename XARG2>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1, xarg2);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1, xarg2, xarg3);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1, xarg2, xarg3, xarg4);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5);
  }

  /**
   * @overloaded
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5, typename XARG6>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5, XARG6 xarg6)
  {
    Insert_T <S, GUARD, GUARD::arglist_length> __if (S::__insert_if_call, this->guard_);
    __if (obj, location, &GUARD::__do_next);

    Insert_T <S, CALLBACK, CALLBACK::arglist_length> __then (S::__insert_then_call, this->callback_);
    __then (obj, location, &CALLBACK::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5, xarg6);
  }

private:
  /// Guard object that determine when the cb is called.
  GUARD & guard_;

  /// Target cb object.
  CALLBACK & callback_;
};

///////////////////////////////////////////////////////////////////////////////
// class Callback_Base

/**
 * @class Callback_Base
 *
 * Base class for all callbacks. The callbacks are where the analysis code 
 * resides.
 */
template <typename T, typename List>
class Callback_Base
{
public:
  /// Type definition of the cb.
  typedef T type;

  /// Type definition of the cb argument list.
  typedef List arglist_type;

  /// The number of arguments expected by the insert method.
  static const int arglist_length = Length <arglist_type>::RET;

  /// @{ InsertCall

  /**
   * Instrument the object with this analysis routine. The analysis routine
   * is inserted at \a location in relation to the object being instrumented.
   * Valid locations are:
   * 
   * = \a IPOINT_BEFORE
   * = \a IPOINT_AFTER
   * = \a IPOINT_ANYWHERE
   *
   * The \a obj is the object being instrumented. Based on Pin, the following
   * are acceptable objects types (or scopes):
   *
   *  = Ins
   *  = Bbl
   *  = Trace
   *  = Routine
   *
   * If the cb has parameters that require additional arguments, then the
   * additional arguments must come after the object being instrumented. The 
   * framework will take care of forming the correct argument list for you.
   *
   * @param[in]       location      Location to insert instrument
   * @param[in]       obj           Object to instrument
   */
  template <typename S>
  void insert (IPOINT location, const S & obj)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1>
  void insert (IPOINT location, const S & obj, XARG1 xarg1) 
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5, typename XARG6>
  void insert (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5, XARG6 xarg6)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5, xarg6);
  }

  /// @}

  /// @{ InsertPredicatedCall

  /**
   * Instrument the object with this predicated analysis routine. The analysis 
   * routine is inserted at \a location in relation to the object being instrumented.
   * Valid locations are:
   * 
   * = \a IPOINT_BEFORE
   * = \a IPOINT_AFTER
   * = \a IPOINT_ANYWHERE
   *
   * The \a obj is the object being instrumented. Based on Pin, the following
   * are acceptable objects types (or scopes):
   *
   *  = Ins
   *  = Bbl
   *  = Trace
   *  = Routine
   *
   * If the cb has parameters that require additional arguments, then the
   * additional arguments must come after the object being instrumented. The 
   * framework will take care of forming the correct argument list for you.
   *
   * @param[in]       location      Location to insert instrument
   * @param[in]       obj           Object to instrument
   */
  template <typename S>
  void insert_predicated (IPOINT location, const S & obj)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1) 
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5);
  }

  /**
   * @overload
   */
  template <typename S, typename XARG1, typename XARG2, typename XARG3, typename XARG4, typename XARG5, typename XARG6>
  void insert_predicated (IPOINT location, const S & obj, XARG1 xarg1, XARG2 xarg2, XARG3 xarg3, XARG4 xarg4, XARG5 xarg5, XARG6 xarg6)
  {
    Insert_T <S, T, arglist_length> insert (S::__insert_predicated_call, (T &)*this);
    insert (obj, location, &T::__analyze, xarg1, xarg2, xarg3, xarg4, xarg5, xarg6);
  }
  /// @}

  /**
   * Create a cb guard for the cb object. The purpose of the
   * cb guard is to insert a conditional guard into the target object.
   * The conditionl guard controls when the Callback object is invoked.
   */
  template <typename GUARD>
  Callback_Guard <GUARD, T> operator [] (GUARD & guard)
  {
    return Callback_Guard <GUARD, T> (guard, (T &)*this);
  }
};
  
///////////////////////////////////////////////////////////////////////////////
// Callback

// Forward decl.
template <typename T> class Callback;

/**
 * @class Callback
 *
 * Callback for passing 0 arguments to the analysis routine.
 */
template <typename T>
class Callback <T (void)> : public Callback_Base <T, End>
{
public:
  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb)
  {  
    reinterpret_cast <T *> (cb)->handle_analyze ();
  }
};

template <typename T, typename A1>
class Callback <T (A1)> :
    public Callback_Base <T, Type_Node <A1> >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  /// @}

  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1)
  {
    param_type1 pp1 (p1);
    
    reinterpret_cast <T *> (cb)->handle_analyze (pp1);
  }
};

template <typename T, typename A1, typename A2>
class Callback <T (A1, A2)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2> > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  /// @}
  
  /// @{ Analysis Methods
  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    
    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2);
  }
  /// @}
};

template <typename T, typename A1, typename A2, typename A3>
class Callback <T (A1, A2, A3)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3> > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  /// @}
  
  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3);
  }
};

template <typename T, typename A1, typename A2, typename A3, typename A4>
class Callback <T (A1, A2, A3, A4)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3, Type_Node <A4> > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  /// @}

  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3, pp4);
  }
};

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
class Callback <T (A1, A2, A3, A4, A5)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3, Type_Node <A4, Type_Node <A5> > > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  static const IARG_TYPE arg_type5 = A5::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  typedef typename A5::pinpp_type param_type5;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  typedef typename A5::pin_type pin_type5;
  /// @}
  
  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4, pin_type5 p5)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);
    param_type5 pp5 (p5);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3, pp4, pp5);
  }
};

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
class Callback <T (A1, A2, A3, A4, A5, A6)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3, Type_Node <A4, Type_Node <A5, Type_Node <A6> > > > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  static const IARG_TYPE arg_type5 = A5::arg_type;
  static const IARG_TYPE arg_type6 = A6::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  typedef typename A5::pinpp_type param_type5;
  typedef typename A6::pinpp_type param_type6;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  typedef typename A5::pin_type pin_type5;
  typedef typename A6::pin_type pin_type6;
  /// @}

  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4, pin_type5 p5, pin_type6 p6)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);
    param_type5 pp5 (p5);
    param_type6 pp6 (p6);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3, pp4, pp5, pp6);
  }
};

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
class Callback <T (A1, A2, A3, A4, A5, A6, A7)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3, Type_Node <A4, Type_Node <A5, Type_Node <A6, Type_Node <A7> > > > > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  static const IARG_TYPE arg_type5 = A5::arg_type;
  static const IARG_TYPE arg_type6 = A6::arg_type;
  static const IARG_TYPE arg_type7 = A7::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  typedef typename A5::pinpp_type param_type5;
  typedef typename A6::pinpp_type param_type6;
  typedef typename A7::pinpp_type param_type7;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  typedef typename A5::pin_type pin_type5;
  typedef typename A6::pin_type pin_type6;
  typedef typename A7::pin_type pin_type7;
  /// @}

  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4, pin_type5 p5, pin_type6 p6, pin_type7 p7)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);
    param_type5 pp5 (p5);
    param_type6 pp6 (p6);
    param_type7 pp7 (p7);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3, pp4, pp5, pp6, pp7);
  }
};

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
class Callback <T (A1, A2, A3, A4, A5, A6, A7, A8)> :
  public Callback_Base <T, Type_Node < A1, Type_Node <A2, Type_Node <A3, Type_Node <A4, Type_Node <A5, Type_Node <A6, Type_Node <A7, Type_Node <A8> > > > > > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  static const IARG_TYPE arg_type5 = A5::arg_type;
  static const IARG_TYPE arg_type6 = A6::arg_type;
  static const IARG_TYPE arg_type7 = A7::arg_type;
  static const IARG_TYPE arg_type8 = A8::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  typedef typename A5::pinpp_type param_type5;
  typedef typename A6::pinpp_type param_type6;
  typedef typename A7::pinpp_type param_type7;
  typedef typename A8::pinpp_type param_type8;
  /// @}

  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  typedef typename A5::pin_type pin_type5;
  typedef typename A6::pin_type pin_type6;
  typedef typename A7::pin_type pin_type7;
  typedef typename A8::pin_type pin_type8;
  /// @}

  static void PIN_FAST_ANALYSIS_CALL __analyze (void * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4, pin_type5 p5, pin_type6 p6, pin_type7 p7, pin_type8 p8)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);
    param_type5 pp5 (p5);
    param_type6 pp6 (p6);
    param_type7 pp7 (p7);
    param_type8 pp8 (p8);

    reinterpret_cast <T *> (cb)->handle_analyze (pp1, pp2, pp3, pp4, pp5, pp6, pp7, pp8);
  }
  /// @}
};

///////////////////////////////////////////////////////////////////////////////
// Conditional_Callback


/**
 * @class Callback_Base
 *
 * Base class for all callbacks. The callbacks are where the analysis code 
 * resides.
 */
template <typename T, typename List>
class Conditional_Callback_Base
{
public:
  /// Type definition of the cb.
  typedef T type;

  /// Type definition of the cb argument list.
  typedef List arglist_type;

  /// The number of arguments expected by the insert method.
  static const int arglist_length = Length <arglist_type>::RET;
};

/**
 * @class Conditional_Callback
 *
 * Conditional cb are cb back objects that determine when a 
 * regular \a Callback object should fire. It therefore acts like a guard
 * to the cb it is associated with.
 *
 * Each conditional cb object is required to implemented do_next ()
 * method. This is similar to the handle_analyze () method on regular
 * \a Callback objects. The return type of the method must be bool. If
 * the return value is \a true, then the traditional cb object will
 * fire. If it is \a false, then nothing happens. This allows the conditional
 * cb to have different logic that determines when the traditional
 * callbakc object should fire.

 * Similar to regular \a Callack objects, the do_next () method can take 
 * multiple parameters. You just need to define the parameters when defining
 * the \a T template parameter as done with \a Callback objects.
 */
template <typename T> class Conditional_Callback;

/**
 * @class Conditional_Callback <T (void)>
 *
 * Conditional cb with no arguments.
 */
template <typename T>
class Conditional_Callback <T (void)> : 
  public Conditional_Callback_Base <T, End>
{
public:
  static ADDRINT PIN_FAST_ANALYSIS_CALL __do_next (VOID * cb) 
  {
    return static_cast <ADDRINT> (reinterpret_cast <T *> (cb)->do_next ());
  }
};

/**
 * @class Conditional_Callback <T (A1)>
 *
 * Conditional cb with 1 argument.
 */
template <typename T, typename A1>
class Conditional_Callback <T (A1)> :
  public Conditional_Callback_Base <T, Type_Node <A1> >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  /// @}

  static ADDRINT PIN_FAST_ANALYSIS_CALL __do_next (VOID * cb, pin_type1 p1)
  {  
    param_type1 pp1 (p1);

    return static_cast <ADDRINT> (reinterpret_cast <T *> (cb)->do_next (pp1));
  }
};

/**
 * @class Conditional_Callback <T (A1, A2)>
 *
 * Conditional cb with 2 arguments.
 */
template <typename T, typename A1, typename A2>
class Conditional_Callback <T (A1, A2)> :
  public Conditional_Callback_Base <T, Type_Node <A1, Type_Node <A2> > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  /// @}

  static ADDRINT PIN_FAST_ANALYSIS_CALL __do_next (VOID * cb, pin_type1 p1, pin_type2 p2)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);

    return static_cast <ADDRINT> (reinterpret_cast <T *> (cb)->do_next (pp1, pp2));
  }
};
 
/**
 * @class Conditional_Callback <T (A1, A2, A3)>
 *
 * Conditional cb with 3 arguments.
 */
template <typename T, typename A1, typename A2, typename A3>
class Conditional_Callback <T (A1, A2, A3)> :
  public Conditional_Callback_Base <T, Type_Node <A1, Type_Node <A2, Type_Node <A3> > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  /// @}

  static ADDRINT PIN_FAST_ANALYSIS_CALL __do_next (VOID * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);

    return static_cast <ADDRINT> (reinterpret_cast <T *> (cb)->do_next (pp1, pp2, pp3));
  }
};

/**
 * @class Conditional_Callback <T (A1, A2, A3, A4)>
 *
 * Conditional cb with 4 arguments.
 */
template <typename T, typename A1, typename A2, typename A3, typename A4>
class Conditional_Callback <T (A1, A2, A3, A4)> :
  public Conditional_Callback_Base <T, Type_Node <A1, Type_Node <A2, Type_Node <A3, Type_Node <A4> > > > >
{
public:
  /// @{ Argument Type Definitions
  static const IARG_TYPE arg_type1 = A1::arg_type;
  static const IARG_TYPE arg_type2 = A2::arg_type;
  static const IARG_TYPE arg_type3 = A3::arg_type;
  static const IARG_TYPE arg_type4 = A4::arg_type;
  /// @}

  /// @{ Parameter Type Definitions
  typedef typename A1::pinpp_type param_type1;
  typedef typename A2::pinpp_type param_type2;
  typedef typename A3::pinpp_type param_type3;
  typedef typename A4::pinpp_type param_type4;
  /// @}
  
  /// @{ Native Pin Type Definitions
  typedef typename A1::pin_type pin_type1;
  typedef typename A2::pin_type pin_type2;
  typedef typename A3::pin_type pin_type3;
  typedef typename A4::pin_type pin_type4;
  /// @}

  static ADDRINT PIN_FAST_ANALYSIS_CALL __do_next (VOID * cb, pin_type1 p1, pin_type2 p2, pin_type3 p3, pin_type4 p4)
  {  
    param_type1 pp1 (p1);
    param_type2 pp2 (p2);
    param_type3 pp3 (p3);
    param_type4 pp4 (p4);

    return static_cast <ADDRINT> (reinterpret_cast <T *> (cb)->do_next (pp1, pp2, pp3, pp4));
  }
};

} // namespace OASIS
} // namespace Pin

#endif  // _OASIS_PIN_INSTRUCTION_CALLBACK_H_
