// bslstl_function.h                                                  -*-C++-*-
#ifndef INCLUDED_BSLSTL_FUNCTION
#define INCLUDED_BSLSTL_FUNCTION

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a polymorphic function object with a specific prototype.
//
//@CLASSES:
// bsl::function: polymorphic function object with a specific prototype.
// bsl::bad_function_call: exception object thrown when invoking null function
//
//@SEE_ALSO:
//
//@DESCRIPTION: This component provides a polymorphic function object
// (functor) that can be invoked like a function and that wraps a run-time
// invokable object such as a function pointer, member function pointer, or
// functor.  The return type and the number and type of arguments at
// invocation are specified by the template parameter, which is a function
// prototype.  A "functor" is similar to a C/C++ function pointer, but unlike
// function pointers, functors can be used to invoke any object that can be
// syntactically invoked as a function.  Objects of type 'bsl::function' are
// generally used as callback functions to avoid templatizing a function or
// class.
//
///Usage
///-----

// Prevent this header from being included directly in 'BSL_OVERRIDES_STD'
// mode.  Doing so is unsupported, and is likely to cause compilation errors.
#if defined(BSL_OVERRIDES_STD) && !defined(BSL_STDHDRS_PROLOGUE_IN_EFFECT)
#error "include <bsl_functional.h> instead of <bslstl_function.h> in \
BSL_OVERRIDES_STD mode"
#endif

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLSTL_PAIR
#include <bslstl_pair.h>
#endif

#ifndef INCLUDED_BSLMA_ALLOCATOR
#include <bslma_allocator.h>
#endif

#ifndef INCLUDED_BSLMA_ALLOCATORADAPTOR
#include <bslma_allocatoradaptor.h>
#endif

#ifndef INCLUDED_BSLMA_CONSTRUCTIONUTIL
#include <bslma_constructionutil.h>
#endif

#ifndef INCLUDED_BSLMA_DEFAULT
#include <bslma_default.h>
#endif

#ifndef INCLUDED_BSLMA_DESTRUCTIONUTIL
#include <bslma_destructionutil.h>
#endif

#ifndef INCLUDED_BSLMA_STDALLOCATOR
#include <bslma_stdallocator.h>
#endif

#ifndef INCLUDED_BSLMA_USESBSLMAALLOCATOR
#include <bslma_usesbslmaallocator.h>
#endif

#ifndef INCLUDED_BSLMF_ADDLVALUEREFERENCE
#include <bslmf_addlvaluereference.h>
#endif

#ifndef INCLUDED_BSLMF_ADDRVALUEREFERENCE
#include <bslmf_addrvaluereference.h>
#endif

#ifndef INCLUDED_BSLMF_ALLOCATORARGT
#include <bslmf_allocatorargt.h>
#endif

#ifndef INCLUDED_BSLMF_ASSERT
#include <bslmf_assert.h>
#endif

#ifndef INCLUDED_BSLMF_CONDITIONAL
#include <bslmf_conditional.h>
#endif

#ifndef INCLUDED_BSLMF_FORWARDINGTYPE
#include <bslmf_forwardingtype.h>
#endif

#ifndef INCLUDED_BSLMF_FUNCTIONPOINTERTRAITS
#include <bslmf_functionpointertraits.h>
#endif

#ifndef INCLUDED_BSLMF_ISBITWISEMOVEABLE
#include <bslmf_isbitwisemoveable.h>
#endif

#ifndef INCLUDED_BSLMF_ISEMPTY
#include <bslmf_isempty.h>
#endif

#ifndef INCLUDED_BSLMF_ISPOINTER
#include <bslmf_ispointer.h>
#endif

#ifndef INCLUDED_BSLMF_ISRVALUEREFERENCE
#include <bslmf_isrvaluereference.h>
#endif

#ifndef INCLUDED_BSLMF_MEMBERFUNCTIONPOINTERTRAITS
#include <bslmf_memberfunctionpointertraits.h>
#endif

#ifndef INCLUDED_BSLMF_MOVABLEREF
#include <bslmf_movableref.h>
#endif

#ifndef INCLUDED_BSLMF_NTHPARAMETER
#include <bslmf_nthparameter.h>
#endif

#ifndef INCLUDED_BSLMF_REMOVECONST
#include <bslmf_removeconst.h>
#endif

#ifndef INCLUDED_BSLMF_REMOVECV
#include <bslmf_removecv.h>
#endif

#ifndef INCLUDED_BSLMF_REMOVEREFERENCE
#include <bslmf_removereference.h>
#endif

#ifndef INCLUDED_BSLMF_SELECTTRAIT
#include <bslmf_selecttrait.h>
#endif

#ifndef INCLUDED_BSLMF_USESALLOCATORARGT
#include <bslmf_usesallocatorargt.h>
#endif

#ifndef INCLUDED_BSLS_ALIGNMENTUTIL
#include <bsls_alignmentutil.h>
#endif

#ifndef INCLUDED_BSLS_ASSERT
#include <bsls_assert.h>
#endif

#ifndef INCLUDED_BSLS_COMPILERFEATURES
#include <bsls_compilerfeatures.h>
#endif

#ifndef INCLUDED_BSLS_EXCEPTIONUTIL
#include <bsls_exceptionutil.h>
#endif

#ifndef INCLUDED_BSLS_NULLPTR
#include <bsls_nullptr.h>
#endif

#ifndef INCLUDED_BSLS_OBJECTBUFFER
#include <bsls_objectbuffer.h>
#endif

#ifndef INCLUDED_BSLS_UNSPECIFIEDBOOL
#include <bsls_unspecifiedbool.h>
#endif

#ifndef INCLUDED_CSTDLIB
#include <cstdlib>
#define INCLUDED_CSTDLIB
#endif

#ifndef INCLUDED_TYPEINFO
#include <typeinfo>
#define INCLUDED_TYPEINFO
#endif

#ifndef INCLUDED_UTILITY
#include <utility>
#define INCLUDED_UTILITY
#endif

#ifndef INCLUDED_STDDEF_H
#include <stddef.h>
#define INCLUDED_STDDEF_H
#endif

#ifndef INCLUDED_STDLIB_H
#include <stdlib.h>
#define INCLUDED_STDLIB_H
#endif


namespace bsl {

template <class FUNC>
class Function_Imp;  // Primary template declared but not defined.

template <class MEM_FUNC_PTR, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke; // Primary template declared but not defined.

template <class ALLOC>
struct Function_AllocTraits;

template <class FUNC>
struct Function_ArgTypes;

template <class FUNC>
struct Function_NothrowWrapperUtil;

                // ===============================================
                // class template Function_DisableIfLosslessCnvrsn
                // ===============================================

template <class FROM_TYPE, class TO_TYPE, class RESULT_TYPE>
struct Function_DisableIfLosslessCnvrsn
    : enable_if<! is_same<FROM_TYPE, TO_TYPE>::value, RESULT_TYPE>
{
    // This metafunction defines a 'type' aliased to the specified
    // 'RESULT_TYPE' parameter if the specified 'FROM_TYPE' parameter type is
    // *not* convertible to the specified 'TO_TYPE' parameter type with no loss
    // of information; otherwise, no 'type' member is defined.  By default,
    // this metafunction always yields a 'type' member if, after stripping off
    // any reference and/or 'const' qualifier from 'FROM_TYPE', it is different
    // from 'TO_TYPE'.  However, this template can be specialized to suppress
    // 'type' for other parameters that supply lossless conversions. This
    // metafunction is used to prevent types that provide lossless conversions
    // to 'bsl::function' from matching template parameters in 'function'
    // constructors and assignment operators, prefering, instead, the
    // non-template overloads.
};

template <class FROM_TYPE, class TO_TYPE, class RESULT_TYPE>
struct Function_DisableIfLosslessCnvrsn<const FROM_TYPE, TO_TYPE, RESULT_TYPE>
    : Function_DisableIfLosslessCnvrsn<FROM_TYPE, TO_TYPE, RESULT_TYPE>
{
    // Specialization of 'Function_DisableIfLosslessCnvrsn' for 'FROM_TYPE'
    // being const.
};

template <class FROM_TYPE, class TO_TYPE, class RESULT_TYPE>
struct Function_DisableIfLosslessCnvrsn<FROM_TYPE&, TO_TYPE, RESULT_TYPE>
    : Function_DisableIfLosslessCnvrsn<FROM_TYPE, TO_TYPE, RESULT_TYPE>
{
    // Specialization of 'Function_DisableIfLosslessCnvrsn' for 'FROM_TYPE'
    // being an lvalue reference.
};

#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
template <class FROM_TYPE, class TO_TYPE, class RESULT_TYPE>
struct Function_DisableIfLosslessCnvrsn<FROM_TYPE&&, TO_TYPE, RESULT_TYPE>
    : Function_DisableIfLosslessCnvrsn<FROM_TYPE, TO_TYPE, RESULT_TYPE>
{
    // Specialization of 'Function_DisableIfLosslessCnvrsn' for 'FROM_TYPE'
    // being an rvalue reference.
};
#endif // BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES


                        // =======================
                        // class bad_function_call
                        // =======================

#ifdef BDE_BUILD_TARGET_EXC

class bad_function_call : public native_std::exception {
    // Standard exception object thrown when attempting to invoke a null
    // function object.

  public:
    bad_function_call() BSLS_NOTHROW_SPEC;
        // Constructs this exception object.

    const char* what() const BSLS_NOTHROW_SPEC;
        // Returns "bad_function_call".
};

#endif // BDE_BUILD_TARGET_EXC

                        // ======================================
                        // class template Function_NothrowWrapper
                        // ======================================

template <class FUNC>
class Function_NothrowWrapper
{
    // If a functor can throw on move, 'bsl::function' will always allocate it
    // out-of-place so that move and swap will always be nothrow operations, as
    // is required by the standard.  Thus, many small functors will fail to
    // take advantage of the small-object optimization because they might throw
    // on move, no matter how unlikely that may be.  A function object wrapped
    // in 'Function_NothrowWrapper', however, will be treated by
    // 'bsl::function' as though it were a function object with a 'noexcept'
    // move constructor (even though it does not have the interface of a
    // function object).  This wrapper is especially useful in C++03 mode,
    // where 'noexcept' does not exist, so even non-throwing operations
    // are assumed to throw unless they delcare the bitwise movable trait.
    // Note that, in the unlikely event that moving the wrapped object *does*
    // throw at runtime, the result will likely be a call to 'terminate()'.

    FUNC d_func;

  public:
    typedef FUNC UnwrappedType;

    Function_NothrowWrapper(const FUNC& other) : d_func(other) { }

#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    Function_NothrowWrapper(FUNC&& other)
      : d_func(BloombergLP::bslmf::MovableRefUtil::move(other))
    {
    }
#endif

    //! Function_NothrowWrapper(const Function_NothrowWrapper&) = default;
    //! Function_NothrowWrapper& operator=(const Function_NothrowWrapper&)
    //!    = default;
    //! ~Function_NothrowWrapper() = default;

    FUNC&       unwrap()       { return d_func; }
    FUNC const& unwrap() const { return d_func; }
};

                        // ======================================
                        // class Function_SmallObjectOptimization
                        // ======================================

class Function_SmallObjectOptimization {
    // Namespace for several definitions related to use of the small object
    // optimization.

    class Dummy;  // Declared but not defined

    // Short aliases for type with maximum platform alignment
    typedef BloombergLP::bsls::AlignmentUtil::MaxAlignedType MaxAlignedType;

  public:
    union InplaceBuffer {
        // This 'union' defines the storage area for a functor representation.
        // The design uses the "small-object optimization" in an attempt to
        // avoid allocations for objects that are no larger than
        // 'InplaceBuffer'.  When using the in-place representation, the
        // invocable, whether a function pointer or function object (if it
        // should fit in the size of 'InplaceBuffer') is stored directly in the
        // 'InplaceBuffer'.  Anything bigger than 'sizeof(InplaceBuffer)' will
        // be stored out-of-place and its address will be stored in
        // 'd_object_p'.  Discriminating between the two representations can be
        // done by the manager with the opcode 'e_GET_SIZE'.
        //
        // Note that union members other than 'd_object_p' are just fillers to
        // make sure that a function or member function pointer can fit without
        // allocation and that alignment is respected.  The 'd_minbuf' member
        // ensures that 'InplaceBuffer' is at least large enough so that
        // modestly-complex functors (e.g., functors that own embedded
        // arguments, such as 'bdef_Bind' objects) to be constructed in-place
        // without triggering further allocation.  The benefit of avoiding
        // allocation for those function objects is balanced against the waste
        // of space when used with smaller function objects.
        //
        // The size of this 'union' was chosen so that the inplace buffer will
        // be 6 pointers in size and the total footprint of a 'bsl::function'
        // object on most platforms will be 10 pointers, which matches the
        // sizes of previous implementations of 'bdef_Function'.

        void                *d_object_p;     // pointer to external rep
        void               (*d_func_p)();    // pointer to function
        void        (Dummy::*d_memFunc_p)(); // pointer to member function
        MaxAlignedType       d_align;        // force align
        void                *d_minbuf[6];    // force minimum size
    };

    static const size_t k_NON_SOO_SMALL_SIZE = ~sizeof(InplaceBuffer);
        // This value is added to the size of a small stateful functor to
        // indicate that, despite being small, it should not be allocated
        // inplace using the small object optimization (SOO), e.g., because it
        // does not have a nothrow move constructor and cannot, therefore, be
        // swapped safely.  When a size larger than this constant is seen, the
        // actual object size can be determined by subtracting this constant.
        // A useful quality of this encoding is that if 'SZ <=
        // sizeof(InplaceBuffer)' for some object size 'SZ', then 'SZ +
        // k_NON_SOO_SMALL_SIZE > sizeof(InplaceBuffer)', so the 'SooFuncSize'
        // (below) for any object that should not be allocated inplace is
        // larger than 'sizeof(InplaceBuffer)', and the 'SooFuncSize' for any
        // object that *should* be allocated inplace is smaller than or equal
        // to 'sizeof(InplaceBuffer)', making the test for "is inplace
        // function" simple.

    BSLMF_ASSERT(k_NON_SOO_SMALL_SIZE > 0);  // Assert unsigned size_t

    template <class TP>
    struct SooFuncSize
    {
        // Metafunction to determine the size of an object for the purposes of
        // the small object optimization (SOO).  The 'VALUE' member is encoded
        // as follows:
        //
        //: o If 'TP' is not larger than 'InplaceBuffer' but has a throwing
        //:   destructive move operation (and therefore should not be allocated
        //:   inplace), then 'VALUE == sizeof(TP) + k_NON_SOO_SMALL_SIZE'.
        //: o Otherwise, 'VALUE == sizeof(TP)'.
        //
        // Note that the 'Soo' prefix is used to indicate that an identifier
        // uses the above protocol.  Thus a variable called 'SooSize' is
        // assumed to be encoded as above, whereas a variable called 'size'
        // can generally be assumed not to be encoded that way.

#if    defined(BSLS_COMPILERFEATURES_SUPPORT_NOEXCEPT)           \
    && defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)
        template <class SOME_TYPE>
            static typename bsl::add_rvalue_reference<SOME_TYPE>::type
                myDeclVal() noexcept;
            // The older versions of clang on OS/X do not provide declval even
            // in c++11 mode.
#endif

        static const bool k_AVOID_SOO =
            sizeof(TP) > sizeof(InplaceBuffer)                ? false :
            BloombergLP::bslmf::IsBitwiseMoveable<TP>::value  ? false :
            Function_NothrowWrapperUtil<TP>::IS_WRAPPED       ? false :
#if    defined(BSLS_COMPILERFEATURES_SUPPORT_NOEXCEPT)           \
    && defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)
            // Check if nothrow move constructible.  The use of '::new' lets
            // us check the constructor without also checking the destructor.
            // This is especially important in gcc 4.7 and before because
            // destructors are not implicitly 'noexcept' in those compilers.
            noexcept(::new((void*) 0) TP(myDeclVal<TP>())) ? false :
#endif
            // If not nonthrow or bitwise moveable, then add
            // 'k_NON_SOO_SMALL_SIZE' to the size indicate that we should not
            // use the small object optimization for this type.
            true;

        // The actual calculation of 'VALUE' is separated from the logic that
        // determines whether or not we should use small object optimization.
        // This prevents the compiler from assembling the intermediate value
        // 'sizeof(TP) + k_NON_SOO_SMALL_SIZE', which will be thrown away when
        // 'false == k_AVOID_SOO' but may cause overflow warnings nonetheless.

        static const std::size_t VALUE =
                         sizeof(TP) + (k_AVOID_SOO ? k_NON_SOO_SMALL_SIZE : 0);
    };

    template <class FN>
    struct IsInplaceFunc :
        integral_constant<bool,SooFuncSize<FN>::VALUE <= sizeof(InplaceBuffer)>
    {
        // Metafunction to determine whether the specified 'FN' template
        // parameter should be allocated within the 'InplaceBuffer'.

        // TBD: 'InplaceFunc' should also take alignment into account, but
        // since we don't (yet) have the ability to specify alignment when
        // allocating memory, there's nothing we can do at this point.
    };
};

                        // ==================
                        // class Function_Rep
                        // ==================

class Function_Rep {
    // This is a component-private class.  Do not use.
    //
    // This class provides a non-template representation for a 'bsl::function'
    // instance.  It handles all of the object-management parts of
    // 'bsl::function' that are not specific to the argument list or return
    // type: storing, copying, and moving the function object and allocator,
    // but not invoking the function (which would require knowledge of the
    // function prototype).  These management functions are run-time
    // polymorphic, and therefore do not require that this class be templated
    // (although several of the member functions are templated).  For technical
    // reasons, this class must be defined before 'bsl::function' (although a
    // mere forward declaration would be all right with most compilers, the Gnu
    // compiler emits an error when trying to do syntactic checking on template
    // code even though it does not instantiate template).

    // TYPES

    union PtrOrSize_t {
        // This union stores either a pointer to const void or a size_t.  It
        // is used as the input argument and return type for manager functions
        // (below).
      private:
        std::size_t  d_asSize_t;
        void        *d_asPtr;

      public:
        PtrOrSize_t(std::size_t s) : d_asSize_t(s) { }
        PtrOrSize_t(void *p) : d_asPtr(p) { }
        PtrOrSize_t() : d_asPtr(0) { }

        std::size_t asSize_t() const { return d_asSize_t; }
        void *asPtr() const { return d_asPtr; }
    };

    enum ManagerOpCode {
        // This enumeration provide values to identify operations to be
        // performed by an object manager function (below).  The object being
        // managed is either the function object in the case of the function
        // manager or the allocator object in the case of the allocator
        // manager.

        e_MOVE_CONSTRUCT
            // move-construct the object in 'rep' from the object pointed to
            // by 'input'.  Return the number of bytes needed to hold the
            // object.

      , e_COPY_CONSTRUCT
            // copy-construct the object in 'rep' from the object pointed to
            // by 'input'.  Return the number of bytes needed to hold the
            // object.

      , e_DESTROY
            // Call the destructor on the object in 'rep'.  Return the number
            // of bytes needed to hold the destroyed object.  Some managers
            // also deallocate memory.

      , e_DESTRUCTIVE_MOVE
            // move-construct the object in 'rep' from the object pointed to
            // by 'input' and destroy the object at 'input'.  Return nothing.
            // This operation is guaranteed not to throw.  Uses bitwise move
            // where possible.

      , e_GET_SIZE
            // Return the size of the object.  For function objects, the
            // computed size is modified by the SOO convention described in
            // the 'SooFuncSize' metafunction.  ('rep' and 'input' are
            // ignored.)

      , e_GET_TARGET
            // Return a pointer to the object in 'rep'.

      , e_GET_TYPE_ID
            // Return a pointer to the 'type_info' for the object in 'rep'.

      , e_IS_EQUAL
            // (Allocator manager only) Return whether the allocator stored in
            // '*rep' is equal to the allocator stored in 'input', where
            // 'input' is the 'd_allocator_p' member of another 'Function_Rep'
            // object.  For 'STL-style' allocators, the allocators will be
            // considered equal only if 'rep->d_allocator_p' and 'input' both
            // point to 'bslma::AllocatorAdaptor' objects of the same type
            // wrapping allocators that compare equal.  For all other
            // allocators types, the allocators are considered equal only if
            // 'rep->d_allocator_p' is equal to the pointer stored in 'input'.

      , e_INIT_REP
            // (Allocator manager only) Initialize 'rep' using the 'input'
            // allocator.  Requires that 'input' point to an object of the
            // manager's 'ALLOC' type and that 'rep->d_funcManager_p' is
            // already set.
    };

  public:

    // Not really public: made public to work around a Sun compiler bug.
    enum AllocCategory {
        // Category of allocator supplied to a constructor.

        e_BSLMA_ALLOC_PTR        // Ptr to type derived from 'bslma::Allocator'
      , e_BSL_ALLOCATOR          // Instantiation of 'bsl::allocator'
      , e_ERASED_STATEFUL_ALLOC  // C++03 STL-style stateful allocator
      , e_ERASED_STATELESS_ALLOC // C++03 STL-style stateless allocator
    };

  private:

    typedef PtrOrSize_t (*Manager)(ManagerOpCode  opCode,
                                   Function_Rep  *rep,
                                   PtrOrSize_t    input);
        // 'Manager' is an alias for a pointer to a function that manages a
        // specific object type (i.e., it copies, moves, or destroys it).  It
        // implements a kind of hand-coded virtual-function dispatch.  The
        // specified 'opCode' is used to choose the "virtual function" to
        // invoke, where the specified 'rep' and 'input' are arguments to that
        // function.  Internally, a 'Manager' function uses a 'switch'
        // statement rather than performing a virtual-table lookup.  This
        // mechanism is chosen because it saves a significant amount of space
        // over the C++ virtual-function mechanism, especially when the number
        // of different instantiations of 'bsl::function' is large.

    typedef Function_SmallObjectOptimization Soo;
        // Type alias for convenience.

    typedef Soo::InplaceBuffer InplaceBuffer;
        // Type alias for convenience.

    typedef BloombergLP::bslma::Allocator Allocator;
        // Type alias for convenience.

    static const size_t k_NON_SOO_SMALL_SIZE = Soo::k_NON_SOO_SMALL_SIZE;
        // Constant alias for convenience.

    template <class FUNC>
    friend class bsl::Function_Imp;

    template <class ALLOC>
    friend struct Function_AllocTraits;

    template <class ALLOC>
    void copyInit(const ALLOC& alloc, const Function_Rep& other);
        // Using the specified 'alloc', copy-initialize this rep from the
        // specified 'other' rep.

    void moveInit(Function_Rep& other);
        // Move-initialize this rep from the specified 'other' rep, leaving
        // the latter empty.

    void makeEmpty();
        // Change this object to be an empty object without changing its
        // allocator.  Note that value returned by 'allocator()' might change,
        // but will point to an allocator with the same type managing the same
        // memory resource.

    void *initRep(std::size_t sooFuncSize, Allocator* alloc,
                  integral_constant<AllocCategory, e_BSLMA_ALLOC_PTR>);
    void *initRep(std::size_t sooFuncSize, const bsl::allocator<char>& alloc,
                  integral_constant<AllocCategory, e_BSL_ALLOCATOR>);
    template <class ALLOC>
    void *initRep(std::size_t sooFuncSize, const ALLOC& alloc,
                  integral_constant<AllocCategory, e_ERASED_STATEFUL_ALLOC>);
    template <class ALLOC>
    void *initRep(std::size_t sooFuncSize, const ALLOC& alloc,
                  integral_constant<AllocCategory, e_ERASED_STATELESS_ALLOC>);
        // Initialize this object's 'd_objbuf', 'd_allocator_p', and
        // 'd_allocManager_p' fields, allocating (if necessary) enough storage
        // to hold a function object of the specified 'sooFuncSize' and
        // holding a copy of 'alloc'.  If the function and allocator fit
        // within 'd_objbuf', then no memory is allocated.  The actual wrapped
        // function object is not initialized, nor is 'd_funcManager_p' set.
        // Note that, for STL-style allocators, including 'bsl::allocator',
        // the element type should be rebound to 'char' before calling
        // 'initRep'.

    bool equalAlloc(Allocator* alloc,
                    integral_constant<AllocCategory, e_BSLMA_ALLOC_PTR>) const;
    template <class T>
    bool equalAlloc(const bsl::allocator<T>& alloc,
                    integral_constant<AllocCategory, e_BSL_ALLOCATOR>) const;
    template <class ALLOC>
    bool equalAlloc(const ALLOC& alloc,
              integral_constant<AllocCategory, e_ERASED_STATEFUL_ALLOC>) const;
    template <class ALLOC>
    bool equalAlloc(const ALLOC& alloc,
              integral_constant<AllocCategory,e_ERASED_STATELESS_ALLOC>) const;
        // Return true if the specified 'alloc' can be used to free memory
        // from the allocator stored in this object and vice versa, and false
        // otherwise.

    template <class ALLOC, AllocCategory ATP>
    void copyRep(const Function_Rep&                   other,
                 const ALLOC&                          alloc,
                 integral_constant<AllocCategory, ATP> atp);

    void assignRep(ManagerOpCode moveOrCopy, Function_Rep *from);
        // Move or copy the value of the specified '*from' object into
        // '*this', depending on the the value of the specified 'moveOrCopy'
        // argument.  The previous value of '*this' is discarded.  The
        // bahavior is undefined unless 'moveOrCopy' is either
        // 'e_MOVE_CONSTRUCT' or 'e_COPY_CONSTRUCT'.

    static void destructiveMove(Function_Rep *to,
                                Function_Rep *from) BSLS_NOTHROW_SPEC;
        // Move the state from the specified 'from' location to the specified
        // 'to' location, where 'to' points to uninitialized storage.  After
        // the move, 'from' points to uninitialized storage.  The move is
        // performed using only non-throwing operations.

    template <class FUNC, bool IS_INPLACE>
    static PtrOrSize_t functionManager(ManagerOpCode  opCode,
                                       Function_Rep  *rep,
                                       PtrOrSize_t    input);

    static PtrOrSize_t unownedAllocManager(ManagerOpCode  opCode,
                                           Function_Rep  *rep,
                                           PtrOrSize_t    input);
        // Note that this function is not a template.  It is defined in the
        // component .cpp file.

    template <class ALLOC>
    static PtrOrSize_t ownedAllocManager(ManagerOpCode  opCode,
                                         Function_Rep  *rep,
                                         PtrOrSize_t    input);

    template <class FUNC>
    static Manager getFunctionManager();

    static void nothing(...);
        // A function that does nothing but can be called to avoid an inlining
        // error in gcc 4.3.5 64-bit mode.

  private:
    // DATA
    mutable InplaceBuffer d_objbuf;  // in-place representation (if fits, as
                                     // indicated by the manager), or pointer
                                     // to external representation

    Manager               d_funcManager_p;
                                     // pointer to manager function used to
                                     // operate on function object instance
                                     // (which knows about the erased type
                                     // 'FUNC' of the function object), or null
                                     // for raw function pointers.

    Allocator            *d_allocator_p; // allocator (held, not owned)

    Manager               d_allocManager_p;
                                     // pointer to manager function used to
                                     // operate on allocator instance (which
                                     // knows about the erased type 'ALLOC' of
                                     // the allocator object), or null if
                                     // 'ALLOC' is 'bslma::Allocator*'.
                                     // INVARIANT: Must be NULL unless
                                     // 'd_allocator_p' has been set to a
                                     // fully-constructed allocator.

    void (*d_invoker_p)();           // Pointer to invoker function

    // The 'isInplace function is public in BDE legacy mode and private
    // otherwise.

    bool isInplace() const BSLS_NOTHROW_SPEC;
        // Return true if the wrapped functor is allocated in place within the
        // footprint of this 'function' object; otherwise return false.

  public:
    // CREATORS
    Function_Rep();
    ~Function_Rep();

    // MANIPULATORS
    void swap(Function_Rep& other) BSLS_NOTHROW_SPEC;

    // ACCESSORS
    const std::type_info& target_type() const BSLS_NOTHROW_SPEC;
    template<class TP> TP*       target()       BSLS_NOTHROW_SPEC;
    template<class TP> const TP* target() const BSLS_NOTHROW_SPEC;
    Allocator *allocator() const;
};

#if !BSLS_COMPILERFEATURES_SIMULATE_CPP11_FEATURES // $var-args=12

                    // =======================
                    // class template function
                    // =======================

template <class RET, class... ARGS>
class Function_Imp<RET(ARGS...)> :
        public Function_ArgTypes<RET(ARGS...)>,
        public Function_Rep  {
    // Implementation "guts" of 'bsl::function' (see class and component
    // documentation for 'bsl::function').  IMPLEMENTATION NOTE: This
    // implementation class is defined, in addition to the primary template,
    // to work around issues with the Sun CC compiler, which has trouble with
    // argument type deduction when a template argument has a partial
    // specialization (as 'Function_Imp' does). 'bsl::function' is a thin
    // wrapper that does not have a partial specialization.

    // PRIVATE TYPES
    typedef RET Invoker(const Function_Rep* rep,
              typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args);
        // A function of this type is used to invoke the wrapped functor.

    // PRIVATE MEMBER FUNCTIONS
    void setInvoker(Invoker *p);
        // Set the invoker to the address in the specified 'p' argument.

    Invoker *invoker() const;
        // Return the current invoker.

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);
        // Initialize this object to wrap the specified '*func' target
        // invocable, using the specified 'alloc' allocator. The '*func'
        // object is moved-from.

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);
        // Move or copy the specified '*func' into the invocable target of
        // '*this', depending on the value of 'moveOrCopy'. The previous
        // target is discarded. The behavior is undefined unless 'moveOrCopy'
        // is either 'e_MOVE_CONSTRUCT' or 'e_COPY_CONSTRUCT'. Note that, for
        // the copy case, 'FUNC' might be a 'const'-qualified type.

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
        // Return the invoker for an invocable of
        // pointer-to-(non-member)function.  Defined inline to work around Sun
        // CC bug.
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;                         // RETURN
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            // G++ 4.3.5 64-bit with optimization has an error which causes
            // this function to seemingly always return null unless this
            // useless use of 'f' is present.
            Function_Rep::nothing(f);
#endif
            return NULL;                                              // RETURN
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
        // Return the invoker for an invocable of pointer-to-member-function
        // type.  Defined inline to work around Sun CC bug.
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;                          // RETURN
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            // G++ 4.3.5 64-bit with optimization has an error which causes
            // this function to seemingly always return null unless this
            // useless use of 'f' is present.
            Function_Rep::nothing(f);
#endif
            return NULL;                                              // RETURN
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
        // Return the invoker for an invocable of in-place functor type.
        // Defined inline to work around Sun CC bug.
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
        // Return the invoker for an invocable of out-of-place functor type.
        // Defined inline to work around Sun CC bug.
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
        // Return the invoker for an invocable of the specified 'FUNC' type.
        // Defined inline to work around Sun CC bug.
    {
        typedef Function_SmallObjectOptimization Soo;

        // Unwrap FUNC type if it is a specialization of
        // 'Function_NothrowWrapper'.
        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        // Determine dispatch based on the traits of 'FuncType'.
        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        // The only reason that the original and unwrapped 'FUNC' would result
        // in different 'SooFuncSize' is if 'FUNC' is wrapping a small object
        // that would otherwise have a throwing move.  In that case, we force
        // the dispatch to choose 'Soo::IsInplaceFunc', otherwise we dispatch
        // on the selection traits of the original 'FUNC' type.
        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        // Dispatch to the correct variant of 'invokerForFunc'
        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    // UNSPECIFIED BOOL

    // This type is needed only in C++03 mode, where 'explicit' conversion
    // operators are not supported.  A 'function' is implicitly converted to
    // 'UnspecifiedBool' when used in 'if' statements, but is not implicitly
    // convertible to 'bool'.
    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    // PUBLIC TYPES
    typedef RET result_type;

    // CREATORS
    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    // MANIPULATORS
    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(FUNC&& func);
    Function_Imp& operator=(nullptr_t);

    // TBD: Need to implement reference_wrapper.
    // template<class FUNC>
    // Function_Imp& operator=(reference_wrapper<FUNC>) BSLS_NOTHROW_SPEC;

    // template<class FUNC, class ALLOC> void assign(FUNC&&, const ALLOC&);
    //     // We have filed an issue report and have elected not to support
    //     // this function because the arguments and definition in the
    //     // standard make no sense.  Replacing the allocator of an existing
    //     // object is inconsistent with the rest of the standard.
    //     // This function does not appear in C++17.

    RET operator()(ARGS...) const;

    // ACCESSORS
#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit  // Explicit conversion available only with C++11
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    // Simulation of explicit conversion to bool.
    // Inlined to work around xlC bug when out-of-line.
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};

#elif BSLS_COMPILERFEATURES_SIMULATE_VARIADIC_TEMPLATES
// {{{ BEGIN GENERATED CODE
// The following section is automatically generated.  **DO NOT EDIT**
// Generator command line: sim_cpp11_features.pl --var-args=12 bslstl_function.h
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT
#define BSLSTL_FUNCTION_VARIADIC_LIMIT 12
#endif
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT_A
#define BSLSTL_FUNCTION_VARIADIC_LIMIT_A BSLSTL_FUNCTION_VARIADIC_LIMIT
#endif


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 0
template <class RET>
class Function_Imp<RET()> :
        public Function_ArgTypes<RET()>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()() const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 1
template <class RET, class ARGS_01>
class Function_Imp<RET(ARGS_01)> :
        public Function_ArgTypes<RET(ARGS_01)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
class Function_Imp<RET(ARGS_01,
                       ARGS_02)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07,
                       ARGS_08)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07,
                                     ARGS_08)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07,
                   ARGS_08) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07,
                       ARGS_08,
                       ARGS_09)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07,
                                     ARGS_08,
                                     ARGS_09)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07,
                   ARGS_08,
                   ARGS_09) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07,
                       ARGS_08,
                       ARGS_09,
                       ARGS_10)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07,
                                     ARGS_08,
                                     ARGS_09,
                                     ARGS_10)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07,
                   ARGS_08,
                   ARGS_09,
                   ARGS_10) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07,
                       ARGS_08,
                       ARGS_09,
                       ARGS_10,
                       ARGS_11)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07,
                                     ARGS_08,
                                     ARGS_09,
                                     ARGS_10,
                                     ARGS_11)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
           typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07,
                   ARGS_08,
                   ARGS_09,
                   ARGS_10,
                   ARGS_11) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
class Function_Imp<RET(ARGS_01,
                       ARGS_02,
                       ARGS_03,
                       ARGS_04,
                       ARGS_05,
                       ARGS_06,
                       ARGS_07,
                       ARGS_08,
                       ARGS_09,
                       ARGS_10,
                       ARGS_11,
                       ARGS_12)> :
        public Function_ArgTypes<RET(ARGS_01,
                                     ARGS_02,
                                     ARGS_03,
                                     ARGS_04,
                                     ARGS_05,
                                     ARGS_06,
                                     ARGS_07,
                                     ARGS_08,
                                     ARGS_09,
                                     ARGS_10,
                                     ARGS_11,
                                     ARGS_12)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
           typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
           typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type,
                   typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS_01,
                   ARGS_02,
                   ARGS_03,
                   ARGS_04,
                   ARGS_05,
                   ARGS_06,
                   ARGS_07,
                   ARGS_08,
                   ARGS_09,
                   ARGS_10,
                   ARGS_11,
                   ARGS_12) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_A >= 12

#else
// The generated code below is a workaround for the absence of perfect
// forwarding in some compilers.


template <class RET, class... ARGS>
class Function_Imp<RET(ARGS...)> :
        public Function_ArgTypes<RET(ARGS...)>,
        public Function_Rep  {

    typedef RET Invoker(const Function_Rep* rep,
              typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args);

    void setInvoker(Invoker *p);

    Invoker *invoker() const;

    template<class FUNC, class ALLOC>
    void initFromTarget(FUNC *func, const ALLOC& alloc);

    template<class FUNC>
    void assignTarget(ManagerOpCode moveOrCopy, FUNC *func);

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                                   BloombergLP::bslmf::SelectTraitCase<
                                       BloombergLP::bslmf::IsFunctionPointer>)
    {
        if (f) {
            return &functionPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f,
                              BloombergLP::bslmf::SelectTraitCase<
                                  BloombergLP::bslmf::IsMemberFunctionPointer>)
    {
        if (f) {
            return &memFuncPtrInvoker<FUNC>;
        }
        else {
#if BSLS_PLATFORM_CMP_GNU              &&                                     \
    BSLS_PLATFORM_CMP_VERSION <= 40305 &&                                     \
    BSLS_PLATFORM_CPU_64_BIT           &&                                     \
    __GNUC_GNU_INLINE__
            Function_Rep::nothing(f);
#endif
            return NULL;
        }
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                       BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>)
    {
        return &inplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC&,
                                   BloombergLP::bslmf::SelectTraitCase<>)
    {
        return &outofplaceFunctorInvoker<FUNC>;
    }

    template <class FUNC>
    static Invoker *invokerForFunc(const FUNC& f)
    {
        typedef Function_SmallObjectOptimization Soo;

        typedef typename
            Function_NothrowWrapperUtil<FUNC>::UnwrappedType UwFuncType;

        typedef typename
            BloombergLP::bslmf::SelectTrait<
                UwFuncType,
                BloombergLP::bslmf::IsFunctionPointer,
                BloombergLP::bslmf::IsMemberFunctionPointer,
                Soo::IsInplaceFunc
            >::Type UwFuncSelection;

        const std::size_t kSOOSIZE       = Soo::SooFuncSize<FUNC>::VALUE;
        const std::size_t kUNWRAPPED_SOOSIZE
                                         = Soo::SooFuncSize<UwFuncType>::VALUE;

        typedef typename
            bsl::conditional<kSOOSIZE != kUNWRAPPED_SOOSIZE,
            BloombergLP::bslmf::SelectTraitCase<Soo::IsInplaceFunc>,
            UwFuncSelection>::type FuncSelection;

        return invokerForFunc(Function_NothrowWrapperUtil<FUNC>::unwrap(f),
                FuncSelection());
    }

    template <class FUNC>
    static RET functionPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET memFuncPtrInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET inplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

    template <class FUNC>
    static RET outofplaceFunctorInvoker(const Function_Rep *rep,
                   typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...);

#ifndef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT

    typedef BloombergLP::bsls::UnspecifiedBool<Function_Imp>
                                                          UnspecifiedBoolUtil;
    typedef typename UnspecifiedBoolUtil::BoolType        UnspecifiedBool;

#endif

  public:
    typedef RET result_type;

    template<class ALLOC> Function_Imp(const ALLOC& alloc);
    template<class ALLOC>
    Function_Imp(const ALLOC& alloc, const Function_Imp& other);
    template<class FUNC, class ALLOC>
    Function_Imp(const ALLOC& alloc, FUNC func);

    Function_Imp(BloombergLP::bslmf::MovableRef<Function_Imp> other);
    template<class ALLOC>
    Function_Imp(const ALLOC&                                 alloc,
                 BloombergLP::bslmf::MovableRef<Function_Imp> other);

    ~Function_Imp();

    Function_Imp& operator=(const Function_Imp&);
    Function_Imp& operator=(BloombergLP::bslmf::MovableRef<Function_Imp>);
    template<class FUNC>
    Function_Imp& operator=(FUNC&& func);
    Function_Imp& operator=(nullptr_t);



    RET operator()(ARGS...) const;

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
    explicit
    operator bool() const BSLS_NOTHROW_SPEC;
#else
    operator UnspecifiedBool() const BSLS_NOTHROW_SPEC
    {
        return UnspecifiedBoolUtil::makeValue(invoker());
    }
#endif


};

// }}} END GENERATED CODE
#endif

template <class PROTOTYPE>
class function : public Function_Imp<PROTOTYPE> {
    // An instantiation of this class template generalizes the notion of a
    // pointer to a function taking the specified 'ARGS' types and returning
    // the specified 'RET' type, i.e., a function pointer of type
    // 'RET(*)(ARGS)'.  An object of this class wraps a run-time invokable
    // object specified at construction, such as a function pointer, member
    // function pointer, or functor.  Note that 'function' is defined only for
    // template parameters that specify a function prototype; the primary
    // template (taking an arbitrary template parameter) is not defined.
    //
    // IMPLEMENTATION NOTE: This class is a thin wrapper around
    // 'Function_Imp' in order to work around a SunCC bug. Note that
    // 'Function_Imp' is partially specialized on the return type and argument
    // types in the 'PROTOTYPE' whereas this template has no parital
    // specializations. This indirection prevents argument deduction errors in
    // the SunCC compiler.

  private:
    typedef Function_Imp<PROTOTYPE>            Base;
    typedef BloombergLP::bslmf::MovableRefUtil MovableRefUtil;
        // Create a type aliases to simplify rendering.

    static Base& upcast(function& f);
    static const Base& upcast(const function& f);
        // Upcast specified  'function' reference to 'Function_Imp' reference.

    // Since 'function' does not support 'operator==' and 'operator!=', they
    // must be deliberately supressed; otherwise 'function' objects would be
    // implicitly comparable by implicit conversion to 'UnspecifiedBool'.
    bool operator==(const function&) const;  // Declared but not defined
    bool operator!=(const function&) const;  // Declared but not defined

  public:

    // CREATORS
    function() BSLS_NOTHROW_SPEC;

    function(nullptr_t) BSLS_NOTHROW_SPEC;

    function(const function& other);

    template <class FUNC>
    function(
        FUNC func,
        typename Function_DisableIfLosslessCnvrsn<FUNC, function, int>::type =
            0)
        : Base(BloombergLP::bslma::Default::defaultAllocator(), func) {
        // Must be in-place inline because the use of 'DisableIf' will
        // otherwise break the MSVC 2010 compiler.
    }

    template<class ALLOC>
    function(allocator_arg_t, const ALLOC& alloc);

    template <class ALLOC>
    function(allocator_arg_t, const ALLOC& alloc, nullptr_t);

    template <class ALLOC>
    function(allocator_arg_t, const ALLOC& alloc, const function& other);

    template<class FUNC, class ALLOC>
    function(allocator_arg_t,
             const ALLOC& alloc,
             FUNC         func,
        typename Function_DisableIfLosslessCnvrsn<FUNC,function,int>::type = 0)
        : Base(alloc, func) {
        // Must be in-place inline because the use of 'DisableIf' will
        // otherwise break the MSVC 2010 compiler.
    }

    function(BloombergLP::bslmf::MovableRef<function> other);

    template <class ALLOC>
    function(allocator_arg_t,
             const ALLOC&                             alloc,
             BloombergLP::bslmf::MovableRef<function> other);

    // MANIPULATORS
    function& operator=(const function& rhs);

    function& operator=(BloombergLP::bslmf::MovableRef<function> rhs);

    template <class FUNC>
    typename Function_DisableIfLosslessCnvrsn<FUNC, function, function&>::type
    operator=(BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
    {
        // Must be in-place inline because the use of 'DisableIf' will
        // otherwise break the MSVC 2010 compiler.
        Base::operator=(BSLS_COMPILERFEATURES_FORWARD(FUNC, func));
        return *this;
    }

    function& operator=(nullptr_t);
};

// FREE FUNCTIONS
template <class PROTOTYPE>
bool operator==(const function<PROTOTYPE>&, nullptr_t) BSLS_NOTHROW_SPEC;

template <class PROTOTYPE>
bool operator==(nullptr_t, const function<PROTOTYPE>&) BSLS_NOTHROW_SPEC;

template <class PROTOTYPE>
bool operator!=(const function<PROTOTYPE>&, nullptr_t) BSLS_NOTHROW_SPEC;

template <class PROTOTYPE>
bool operator!=(nullptr_t, const function<PROTOTYPE>&) BSLS_NOTHROW_SPEC;

template <class PROTOTYPE>
void swap(function<PROTOTYPE>& a, function<PROTOTYPE>& b);


#ifndef BSLS_PLATFORM_CMP_SUN
#define BSLSTL_FUNCTION_CAST_RESULT(X) static_cast<RET>(X)
#else
#define BSLSTL_FUNCTION_CAST_RESULT(X) (RET)(X)
#endif


// ============================================================================
//                TEMPLATE AND INLINE FUNCTION IMPLEMENTATIONS
// ============================================================================

                        // ---------------------------------
                        // struct template Function_ArgTypes
                        // ---------------------------------

template <class FUNC>
struct Function_ArgTypes {
    // This is a component-private struct template.  Do not use.
    //
    // The standard requires that 'function' define certain typedefs for
    // compatibility with one- and two-argument legacy functor adaptors.  This
    // template provides the following nested typedefs:
    //..
    //  argument_type        -- Only if FUNC takes exactly one argument
    //  first_argument_type  -- Only if FUNC takes exactly two arguments
    //  second_argument_type -- Only if FUNC takes exactly two arguments
    //..

    // No typedefs for the unspecialized case
};

template <class R, class ARG>
struct Function_ArgTypes<R(ARG)> {
    // Specialization for functions that take exactly one argument.

    typedef ARG argument_type;
};

template <class R, class ARG1, class ARG2>
struct Function_ArgTypes<R(ARG1, ARG2)> {
    // Specialization for functions that take exactly two arguments.

    typedef ARG1 first_argument_type;
    typedef ARG2 second_argument_type;
};

                        // -------------------------------------------
                        // struct template Function_NothrowWrapperUtil
                        // -------------------------------------------

template <class FUNC>
struct Function_NothrowWrapperUtil {
    // This is a component-private struct template.  Do not use.
    //
    // Namesapace for 'Function_NothrowWrapper' traits and utilities.

    typedef FUNC UnwrappedType;

    enum { IS_WRAPPED = false };
         // True for specializations of 'Function_NothrowWrapper', else false.

    static FUNC&       unwrap(typename bsl::remove_cv<FUNC>::type&       f)
        { return f; }
    static FUNC const& unwrap(typename bsl::remove_cv<FUNC>::type const& f)
        { return f; }
};

template <class FUNC>
struct  Function_NothrowWrapperUtil<Function_NothrowWrapper<FUNC> > {
    // This is a component-private struct template.  Do not use.
    //
    // Namesapace for 'Function_NothrowWrapper' traits and utilities,
    // specialized for instantiations of 'Function_NothrowWrapper<FUNC>'.

    typedef Function_NothrowWrapper<FUNC> WrappedType;
    typedef FUNC                          UnwrappedType;

    enum { IS_WRAPPED = true };
         // True for specializations of 'Function_NothrowWrapper', else false.

    static FUNC&       unwrap(WrappedType&       f) { return f.unwrap(); }
    static FUNC const& unwrap(WrappedType const& f) { return f.unwrap(); }
};

#if !BSLS_COMPILERFEATURES_SIMULATE_CPP11_FEATURES

                    // -------------------------------------
                    // class template Function_MemFuncInvoke
                    // -------------------------------------

template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE,
          class RET, class... ARGS>
struct Function_MemFuncInvokeImp {
    // This is a component-private class template.  Do not use.
    //

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS = sizeof...(ARGS) };

    static
    RET invoke_imp(true_type /* DirectInvoke */, FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args) {
        // If 'OBJ_ARG_TYPE' is a non-const rvalue, then it will have been
        // forwarded as a const reference, instead.  In order to call a
        // potentially non-const member function on it, we must cast the
        // reference back to the original type.  The 'const_cast', below, will
        // have no effect unless 'OBJ_ARG_TYPE' is a non-const rvalue.
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args...);
    }

    static
    RET invoke_imp(false_type /* DirectInvoke */, FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args) {
        // If 'OBJ_ARG_TYPE' is a non-const rvalue, then it will have been
        // forwarded as a const reference, instead.  In order to call a
        // potentially non-const member function on it, we must cast the
        // reference back to a the original type.  The 'const_cast', below,
        // will have no effect unless 'OBJ_ARG_TYPE' is a non-const rvalue.
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args...);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
        { return invoke_imp(DirectInvoke(), f, obj, args...); }

};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS...>
{
    // This is a component-private struct template.  Do not use.
    //
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS...>
{
    // This is a component-private struct template.  Do not use.
    //
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS...>
{
    // This is a component-private struct template.  Do not use.
    //
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS...>
{
    // This is a component-private struct template.  Do not use.
    //
};

#elif BSLS_COMPILERFEATURES_SIMULATE_VARIADIC_TEMPLATES
// {{{ BEGIN GENERATED CODE
// The following section is automatically generated.  **DO NOT EDIT**
// Generator command line: sim_cpp11_features.pl --var-args=12 bslstl_function.h
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT
#define BSLSTL_FUNCTION_VARIADIC_LIMIT 12
#endif
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT_B
#define BSLSTL_FUNCTION_VARIADIC_LIMIT_B BSLSTL_FUNCTION_VARIADIC_LIMIT
#endif


template <class FUNC,
          class OBJ_TYPE,
          class OBJ_ARG_TYPE,
          class RET
#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
,
          class ARGS_0 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
,
          class ARGS_1 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
,
          class ARGS_2 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
,
          class ARGS_3 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
,
          class ARGS_4 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
,
          class ARGS_5 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
,
          class ARGS_6 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
,
          class ARGS_7 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
,
          class ARGS_8 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
,
          class ARGS_9 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
,
          class ARGS_10 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
,
          class ARGS_11 = BSLS_COMPILERFEATURES_NILT
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
,
          class = BSLS_COMPILERFEATURES_NILT>
struct Function_MemFuncInvokeImp;

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  0u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)();
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)();
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj)
        { return invoke_imp(DirectInvoke(), f, obj); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  1u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01)
        { return invoke_imp(DirectInvoke(), f, obj, args_01); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  2u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  3u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  4u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  5u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  6u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  7u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07,
          class ARGS_08>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07,
                                                                    ARGS_08> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  8u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07,
                                           args_08);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07,
                                              args_08);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07,
                                                    args_08); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07,
          class ARGS_08,
          class ARGS_09>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07,
                                                                    ARGS_08,
                                                                    ARGS_09> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS =  9u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07,
                                           args_08,
                                           args_09);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07,
                                              args_08,
                                              args_09);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07,
                                                    args_08,
                                                    args_09); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07,
          class ARGS_08,
          class ARGS_09,
          class ARGS_10>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07,
                                                                    ARGS_08,
                                                                    ARGS_09,
                                                                    ARGS_10> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS = 10u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07,
                                           args_08,
                                           args_09,
                                           args_10);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07,
                                              args_08,
                                              args_09,
                                              args_10);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07,
                                                    args_08,
                                                    args_09,
                                                    args_10); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07,
          class ARGS_08,
          class ARGS_09,
          class ARGS_10,
          class ARGS_11>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07,
                                                                    ARGS_08,
                                                                    ARGS_09,
                                                                    ARGS_10,
                                                                    ARGS_11> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS = 11u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
          typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07,
                                           args_08,
                                           args_09,
                                           args_10,
                                           args_11);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
          typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07,
                                              args_08,
                                              args_09,
                                              args_10,
                                              args_11);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
           typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07,
                                                    args_08,
                                                    args_09,
                                                    args_10,
                                                    args_11); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12
template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE, class RET,
          class ARGS_01,
          class ARGS_02,
          class ARGS_03,
          class ARGS_04,
          class ARGS_05,
          class ARGS_06,
          class ARGS_07,
          class ARGS_08,
          class ARGS_09,
          class ARGS_10,
          class ARGS_11,
          class ARGS_12>
struct Function_MemFuncInvokeImp<FUNC, OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                    ARGS_02,
                                                                    ARGS_03,
                                                                    ARGS_04,
                                                                    ARGS_05,
                                                                    ARGS_06,
                                                                    ARGS_07,
                                                                    ARGS_08,
                                                                    ARGS_09,
                                                                    ARGS_10,
                                                                    ARGS_11,
                                                                    ARGS_12> {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS = 12u };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
          typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
          typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args_01,
                                           args_02,
                                           args_03,
                                           args_04,
                                           args_05,
                                           args_06,
                                           args_07,
                                           args_08,
                                           args_09,
                                           args_10,
                                           args_11,
                                           args_12);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
          typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
          typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
          typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
          typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
          typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
          typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
          typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
          typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
          typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
          typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
          typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
          typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args_01,
                                              args_02,
                                              args_03,
                                              args_04,
                                              args_05,
                                              args_06,
                                              args_07,
                                              args_08,
                                              args_09,
                                              args_10,
                                              args_11,
                                              args_12);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
           typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
           typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
           typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
           typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
           typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
           typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
           typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
           typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
           typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
           typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
           typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12)
        { return invoke_imp(DirectInvoke(), f, obj, args_01,
                                                    args_02,
                                                    args_03,
                                                    args_04,
                                                    args_05,
                                                    args_06,
                                                    args_07,
                                                    args_08,
                                                    args_09,
                                                    args_10,
                                                    args_11,
                                                    args_12); }

};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
template <class RET, class OBJ_TYPE, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
template <class RET, class OBJ_TYPE, class ARGS_01, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10,
                                                   ARGS_11>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11,
                                     class ARGS_12, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11,
                                                ARGS_12), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11,
                                                  ARGS_12), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10,
                                                   ARGS_11,
                                                   ARGS_12>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
template <class RET, class OBJ_TYPE, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)() const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)() const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
template <class RET, class OBJ_TYPE, class ARGS_01, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07,
                                                                   ARGS_08>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07,
                                                                   ARGS_08,
                                                                   ARGS_09>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07,
                                                                   ARGS_08,
                                                                   ARGS_09,
                                                                   ARGS_10>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07,
                                                                   ARGS_08,
                                                                   ARGS_09,
                                                                   ARGS_10,
                                                                   ARGS_11>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11,
                                     class ARGS_12, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11,
                                                ARGS_12) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11,
                                                  ARGS_12) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                   ARGS_02,
                                                                   ARGS_03,
                                                                   ARGS_04,
                                                                   ARGS_05,
                                                                   ARGS_06,
                                                                   ARGS_07,
                                                                   ARGS_08,
                                                                   ARGS_09,
                                                                   ARGS_10,
                                                                   ARGS_11,
                                                                   ARGS_12>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
template <class RET, class OBJ_TYPE, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)() volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)() volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
template <class RET, class OBJ_TYPE, class ARGS_01, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07,
                                                                      ARGS_08>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07,
                                                                      ARGS_08,
                                                                      ARGS_09>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07,
                                                                      ARGS_08,
                                                                      ARGS_09,
                                                                      ARGS_10>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07,
                                                                      ARGS_08,
                                                                      ARGS_09,
                                                                      ARGS_10,
                                                                      ARGS_11>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11,
                                     class ARGS_12, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11,
                                                ARGS_12) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11,
                                                  ARGS_12) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS_01,
                                                                      ARGS_02,
                                                                      ARGS_03,
                                                                      ARGS_04,
                                                                      ARGS_05,
                                                                      ARGS_06,
                                                                      ARGS_07,
                                                                      ARGS_08,
                                                                      ARGS_09,
                                                                      ARGS_10,
                                                                      ARGS_11,
                                                                      ARGS_12>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0
template <class RET, class OBJ_TYPE, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)() const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)() const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1
template <class RET, class OBJ_TYPE, class ARGS_01, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10,
                                                   ARGS_11>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12
template <class RET, class OBJ_TYPE, class ARGS_01,
                                     class ARGS_02,
                                     class ARGS_03,
                                     class ARGS_04,
                                     class ARGS_05,
                                     class ARGS_06,
                                     class ARGS_07,
                                     class ARGS_08,
                                     class ARGS_09,
                                     class ARGS_10,
                                     class ARGS_11,
                                     class ARGS_12, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS_01,
                                                ARGS_02,
                                                ARGS_03,
                                                ARGS_04,
                                                ARGS_05,
                                                ARGS_06,
                                                ARGS_07,
                                                ARGS_08,
                                                ARGS_09,
                                                ARGS_10,
                                                ARGS_11,
                                                ARGS_12) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS_01,
                                                  ARGS_02,
                                                  ARGS_03,
                                                  ARGS_04,
                                                  ARGS_05,
                                                  ARGS_06,
                                                  ARGS_07,
                                                  ARGS_08,
                                                  ARGS_09,
                                                  ARGS_10,
                                                  ARGS_11,
                                                  ARGS_12) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS_01,
                                                   ARGS_02,
                                                   ARGS_03,
                                                   ARGS_04,
                                                   ARGS_05,
                                                   ARGS_06,
                                                   ARGS_07,
                                                   ARGS_08,
                                                   ARGS_09,
                                                   ARGS_10,
                                                   ARGS_11,
                                                   ARGS_12>
{
};
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_B >= 12

#else
// The generated code below is a workaround for the absence of perfect
// forwarding in some compilers.


template <class FUNC, class OBJ_TYPE, class OBJ_ARG_TYPE,
          class RET, class... ARGS>
struct Function_MemFuncInvokeImp {

    typedef typename is_convertible<
            typename remove_reference<OBJ_ARG_TYPE>::type*,
            OBJ_TYPE*
        >::type DirectInvoke;

    enum { NUM_ARGS = sizeof...(ARGS) };

    static
    RET invoke_imp(true_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return (const_cast<ObjTp>(obj).*f)(args...);
    }

    static
    RET invoke_imp(false_type , FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args) {
        typedef typename bsl::add_lvalue_reference<OBJ_ARG_TYPE>::type ObjTp;
        return ((*const_cast<ObjTp>(obj)).*f)(args...);
    }

  public:
    static
    RET invoke(FUNC f,
           typename BloombergLP::bslmf::ForwardingType<OBJ_ARG_TYPE>::Type obj,
           typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
        { return invoke_imp(DirectInvoke(), f, obj, args...); }

};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...), OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...), OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS...>
{
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) const, OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) const,
                                const OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS...>
{
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) volatile,
                                volatile OBJ_TYPE, OBJ_ARG_TYPE, RET, ARGS...>
{
};

template <class RET, class OBJ_TYPE, class... ARGS, class OBJ_ARG_TYPE>
struct Function_MemFuncInvoke<RET (OBJ_TYPE::*)(ARGS...) const volatile,
                              OBJ_ARG_TYPE>
    : Function_MemFuncInvokeImp<RET (OBJ_TYPE::*)(ARGS...) const volatile,
                                const volatile OBJ_TYPE,
                                OBJ_ARG_TYPE, RET, ARGS...>
{
};

// }}} END GENERATED CODE
#endif

class Function_PairBufDesc {
    // This is a component-private struct template.  Do not use.
    //
    // Descriptor for a maximally-aligned memory buffer that can hold two
    // objects.  Given a pointer to a maximally-aligned memory buffer, it
    // provides sufficient information to access the first and second objects
    // stored within that memory buffer, as if the memory buffer were a pair
    // struct.  In order to generate a descriptor, we need only the size of
    // the two objects being stored, thus allowing a descriptor to be created
    // dynamically for objects whose types are not known until runtime.  Note
    // that no attempt is made to match the layout of a 'std::pair' containing
    // the members of the same data types and, in practice, the layout will
    // often differ from 'std::pair'.

    std::size_t d_totalSize;    // Total size of the buffer
    std::size_t d_secondOffset; // Offset within the buffer of the 2nd object

  public:
    // CREATORS
    Function_PairBufDesc(std::size_t t1Size, std::size_t t2Size);
        // Construct a descriptor for a maximally-aligned pair of objects with
        // the specified sizes 't1Size' and 't2Size'.

    //! Function_PairBufDesc(const Function_PairBufDesc&);
    //! ~Function_PairBufDesc();
    //! Function_PairBufDesc& operator=(const Function_PairBufDesc&);

    // ACCESSORS
    std::size_t totalSize() const;
        // Return the total size of the maximally-aligned buffer needed to
        // hold two objects whose sizes were specified in the constructor.

    void       *first(void       *buffer) const;
    void const *first(void const *buffer) const;
        // Treat the specified 'buffer' as a pointer to memory intended to
        // hold two objects whose sizes were specified in the constructor of
        // this 'Function_PairBufDesc' and return the address of the first of
        // those two objects.  The behavior is undefined unless 'buffer' is
        // the address of a maximally-aligned block of memory of at least
        // 'totalSize()' bytes.

    void       *second(void       *buffer) const;
    void const *second(void const *buffer) const;
        // Treat the specified 'buffer' as a pointer to memory intended to
        // hold two objects whose sizes were specified in the constructor of
        // this 'Function_PairBufDesc' and return the address of the second of
        // those two objects.  The behavior is undefined unless 'buffer' is
        // the address of a maximally-aligned block of memory of at least
        // 'totalSize()' bytes.
};

template <class ALLOC>
struct Function_AllocTraits
{
    // This is a component-private struct template.  Do not use.
    //
    // Determine the category of an allocator and compute a normalized type
    // for allocators that belong to the same family.

  private:
    typedef Function_Rep::AllocCategory         AllocCategory;

  public:
    static const AllocCategory k_CATEGORY =
        (bsl::is_empty<ALLOC>::value ?
         Function_Rep::e_ERASED_STATELESS_ALLOC :
         Function_Rep::e_ERASED_STATEFUL_ALLOC);

    typedef bsl::integral_constant<AllocCategory, k_CATEGORY> Category;
    typedef typename ALLOC::template rebind<char>::other      Type;
};

template <class ALLOC>
struct Function_AllocTraits<ALLOC *>
{
    // Specialization for pointer to type derived from 'bslma::Allocator'.

  private:
    typedef BloombergLP::bslma::Allocator Allocator;

    BSLMF_ASSERT((bsl::is_convertible<ALLOC *, Allocator*>::value));

    typedef Function_Rep::AllocCategory AllocCategory;

  public:
    static const AllocCategory k_CATEGORY = Function_Rep::e_BSLMA_ALLOC_PTR;

    typedef bsl::integral_constant<AllocCategory, k_CATEGORY>  Category;
    typedef Allocator                                         *Type;
};

template <class TYPE>
struct Function_AllocTraits<bsl::allocator<TYPE> >
{
    // Specialization for 'bsl::allocator<TYPE>'

  private:
    typedef Function_Rep::AllocCategory AllocCategory;

  public:
    static const AllocCategory k_CATEGORY = Function_Rep::e_BSL_ALLOCATOR;

    typedef bsl::integral_constant<AllocCategory, k_CATEGORY> Category;
    typedef bsl::allocator<char>                              Type;
};

template <class ALLOC>
const Function_Rep::AllocCategory Function_AllocTraits<ALLOC>::k_CATEGORY;

template <class ALLOC>
const Function_Rep::AllocCategory Function_AllocTraits<ALLOC *>::k_CATEGORY;

template <class TYPE>
const Function_Rep::AllocCategory
    Function_AllocTraits<bsl::allocator<TYPE> >::k_CATEGORY;

}  // close namespace bsl

                        // ------
                        // TRAITS
                        // ------

namespace BloombergLP {
namespace bslma {

template <class PROTOTYPE>
struct UsesBslmaAllocator<bsl::function<PROTOTYPE> > : bsl::true_type { };

}  // close namespace bslma

namespace bslmf {

template <class PROTOTYPE>
struct UsesAllocatorArgT<bsl::function<PROTOTYPE> > : bsl::true_type { };

}  // close namespace bslmf
}  // close enterprise namespace

                        // --------------------------
                        // class Function_PairBufDesc
                        // --------------------------

// CREATORS
inline
bsl::Function_PairBufDesc::Function_PairBufDesc(std::size_t t1Size,
                                                std::size_t t2Size)
{
    static const std::size_t k_MAX_ALIGNMENT =
        BloombergLP::bsls::AlignmentUtil::BSLS_MAX_ALIGNMENT;

    d_totalSize = ((t1Size + t2Size + k_MAX_ALIGNMENT - 1) &
                   ~(k_MAX_ALIGNMENT - 1));

    d_secondOffset = d_totalSize - t2Size;
}

// ACCESSORS
inline std::size_t bsl::Function_PairBufDesc::totalSize() const
{
    return d_totalSize;
}

inline void       *bsl::Function_PairBufDesc::first(void       *buffer) const
{
    return buffer;
}

inline void const *bsl::Function_PairBufDesc::first(void const *buffer) const
{
    return buffer;
}

inline void       *bsl::Function_PairBufDesc::second(void       *buffer) const
{
    return d_secondOffset + static_cast<char*>(buffer);
}

inline void const *bsl::Function_PairBufDesc::second(void const *buffer) const
{
    return d_secondOffset + static_cast<const char*>(buffer);
}

                        // --------------------------------------
                        // class Function_SmallObjectOptimization
                        // --------------------------------------

template <class TP>
const std::size_t
bsl::Function_SmallObjectOptimization::SooFuncSize<TP>::VALUE;

                        // -----------------------
                        // class bad_function_call
                        // -----------------------

#ifdef BDE_BUILD_TARGET_EXC

inline
bsl::bad_function_call::bad_function_call() BSLS_NOTHROW_SPEC
    : std::exception()
{
}

#endif

                        // -----------------------
                        // class bsl::Function_Rep
                        // -----------------------

template <class ALLOC>
inline
void bsl::Function_Rep::copyInit(const ALLOC& alloc, const Function_Rep& other)
{
    d_funcManager_p = other.d_funcManager_p;
    d_invoker_p = other.d_invoker_p;

    std::size_t sooFuncSize = d_funcManager_p ?
        d_funcManager_p(e_GET_SIZE, this, PtrOrSize_t()).asSize_t() : 0;

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(sooFuncSize,
            typename Traits::Type(alloc), typename Traits::Category());

    if (d_funcManager_p) {
        PtrOrSize_t source = d_funcManager_p(e_GET_TARGET,
                                             const_cast<Function_Rep*>(&other),
                                             PtrOrSize_t());
        d_funcManager_p(e_COPY_CONSTRUCT, this, source);
    }
}

template <class FUNC, bool IS_INPLACE>
inline
bsl::Function_Rep::PtrOrSize_t
bsl::Function_Rep::functionManager(ManagerOpCode  opCode,
                                   Function_Rep  *rep,
                                   PtrOrSize_t    input)
{
    using namespace BloombergLP;

    static const std::size_t k_SOO_FUNC_SIZE =
        IS_INPLACE ? sizeof(FUNC) : Soo::SooFuncSize<FUNC>::VALUE;
    static const bool k_IS_INPLACE = IS_INPLACE;

    // If a function manager exists, then functor must have non-zero size.
    BSLMF_ASSERT(0 != k_SOO_FUNC_SIZE);

    // If wrapped function fits in 'd_objbuf', then it is inplace; otherwise,
    // its heap-allocated address is found in 'd_objbuf.d_object_p'.  There is
    // no need to computed this using metaprogramming; the compiler will
    // optimize away the conditional test.
    void *wrappedFuncBuf_p =
        k_IS_INPLACE ? &rep->d_objbuf : rep->d_objbuf.d_object_p;
    FUNC *wrappedFunc_p = static_cast<FUNC*>(wrappedFuncBuf_p);

    switch (opCode) {

      case e_MOVE_CONSTRUCT: {
        // Move-construct function object.  There is no point to optimizing
        // this operation for trivial types.  If the type is trivially
        // moveable or copyable, then the move or copy operation below will do
        // it trivially.

        FUNC &srcFunc = *static_cast<FUNC*>(input.asPtr());
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
        bslma::ConstructionUtil::construct(
                                         wrappedFunc_p,
                                         rep->d_allocator_p,
                                         bslmf::MovableRefUtil::move(srcFunc));
#else
        bslma::ConstructionUtil::construct(wrappedFunc_p,
                                           rep->d_allocator_p,
                                           srcFunc);
#endif
        return wrappedFunc_p;                                         // RETURN
      } break;

      case e_COPY_CONSTRUCT: {

        // Copy-construct function object.  There is no point to optimizing
        // this operation for bitwise copyable types.  If the type is trivially
        // copyable, then the copy operation below will do it trivially.
        const FUNC &srcFunc = *static_cast<const FUNC*>(input.asPtr());
        bslma::ConstructionUtil::construct(wrappedFunc_p,
                                           rep->d_allocator_p,
                                           srcFunc);
        return wrappedFunc_p;                                         // RETURN
      } break;

      case e_DESTROY: {

        // Call destructor for functor.
        wrappedFunc_p->~FUNC();

        // Return size of destroyed function object
        return k_SOO_FUNC_SIZE;                                       // RETURN
      } break;

      case e_DESTRUCTIVE_MOVE: {
        void *input_p      = input.asPtr();
        FUNC *srcFunc_p    = static_cast<FUNC*>(input_p);
        bslma::ConstructionUtil::destructiveMove(wrappedFunc_p,
                                                 rep->d_allocator_p,
                                                 srcFunc_p);
      } break;

      case e_GET_SIZE:     return k_SOO_FUNC_SIZE;                    // RETURN
      case e_GET_TARGET:   return wrappedFunc_p;                      // RETURN
      case e_GET_TYPE_ID:
        return const_cast<std::type_info*>(&typeid(FUNC));            // RETURN

      case e_IS_EQUAL:
      case e_INIT_REP: {
        BSLS_ASSERT(0 && "Opcode not implemented for function manager");
      } break;

    } // end switch

    return PtrOrSize_t();
}

template <class ALLOC>
inline
bsl::Function_Rep::PtrOrSize_t
bsl::Function_Rep::ownedAllocManager(ManagerOpCode  opCode,
                                     Function_Rep  *rep,
                                     PtrOrSize_t    input)
{
    using namespace BloombergLP;
    typedef typename bslma::AllocatorAdaptor<ALLOC>::Type Adaptor;

    switch (opCode) {
      case e_MOVE_CONSTRUCT: // Fall through: allocators are always copied
      case e_COPY_CONSTRUCT: {
        const Adaptor& other = *static_cast<const Adaptor*>(input.asPtr());
        return ::new ((void*) rep->d_allocator_p) Adaptor(other);     // RETURN
      } break;

      case e_DESTROY: {
        // Allocator cannot deallocate itself, so make a copy of the allocator
        // on the stack and use the copy for deallocation.
        Adaptor allocCopy(*static_cast<Adaptor*>(rep->d_allocator_p));
        std::size_t sooFuncSize = input.asSize_t();

        rep->d_allocator_p->~Allocator();  // destroy allocator

        if (sooFuncSize > sizeof(InplaceBuffer)) {
            // Deallocate memory holding both functor and allocator
            allocCopy.deallocate(rep->d_objbuf.d_object_p);
        }
        else {
            // Functor is inplace but allocator is not.
            // Deallocate space used by allocator.
            allocCopy.deallocate(rep->d_allocator_p);
        }

        // Return size allocator adaptor.
        return sizeof(Adaptor);                                       // RETURN
      }

      case e_DESTRUCTIVE_MOVE: {
        const Adaptor& other = *static_cast<const Adaptor*>(input.asPtr());

        // Compute the distance (in bytes) between the start of the source and
        // the start of the destination to see if they overlap.
        std::size_t dist = static_cast<std::size_t>(
            std::abs(reinterpret_cast<const char*>(rep->d_allocator_p) -
                     reinterpret_cast<const char*>(&other)));

        if (dist >= sizeof(Adaptor)) {
            // Input and output don't overlap.
            ::new ((void*) rep->d_allocator_p)
                                   Adaptor(bslmf::MovableRefUtil::move(other));
            other.~Adaptor();
        }
        else {
            // Input and output overlap so we need to move through a temporary
            // variable.
            Adaptor temp(bslmf::MovableRefUtil::move(other));
            other.~Adaptor();
            ::new ((void*) rep->d_allocator_p)
                                    Adaptor(bslmf::MovableRefUtil::move(temp));
        }
      } break;

      case e_GET_SIZE: {
        // The SOO size of the adaptor is always the same as the true size of
        // the adaptor because it is always nothrow moveable.
        return sizeof(Adaptor);                                       // RETURN
      }

      case e_GET_TARGET:  return rep->d_allocator_p;                  // RETURN
      case e_GET_TYPE_ID:
          return const_cast<std::type_info*>(&typeid(Adaptor));       // RETURN

      case e_IS_EQUAL: {
        const Allocator *inputAlloc =
            static_cast<const Allocator *>(input.asPtr());
        const Adaptor *inputAdaptor = dynamic_cast<const Adaptor*>(inputAlloc);
        Adaptor *thisAdaptor = static_cast<Adaptor*>(rep->d_allocator_p);
        return inputAdaptor ?
            inputAdaptor->adaptedAllocator() == thisAdaptor->adaptedAllocator()
            : false;                                                  // RETURN
      } break;

      case e_INIT_REP: {
        const Allocator *inputAlloc =
            static_cast<const Allocator *>(input.asPtr());
        const Adaptor *inputAdaptor =
            dynamic_cast<const Adaptor*>(inputAlloc);
        BSLS_ASSERT(inputAdaptor);

        std::size_t sooFuncSize = rep->d_funcManager_p ?
            rep->d_funcManager_p(e_GET_SIZE, rep,
                                 PtrOrSize_t()).asSize_t() : 0;

        rep->initRep(sooFuncSize, inputAdaptor->adaptedAllocator(),
                  integral_constant<AllocCategory, e_ERASED_STATEFUL_ALLOC>());

      } break;
    } // end switch

    return PtrOrSize_t();
}

template <class FUNC>
inline
bsl::Function_Rep::Manager bsl::Function_Rep::getFunctionManager()
{
    static const bool k_IS_INPLACE = Soo::IsInplaceFunc<FUNC>::value;
    typedef typename
        Function_NothrowWrapperUtil<FUNC>::UnwrappedType UnwrappedFunc;
    return &functionManager<UnwrappedFunc, k_IS_INPLACE>;
}

inline
void *bsl::Function_Rep::initRep(std::size_t                 sooFuncSize,
                                 const bsl::allocator<char>& alloc,
                                 integral_constant<AllocCategory,
                                                   e_BSL_ALLOCATOR>)
{
    return initRep(sooFuncSize, alloc.mechanism(),
                   integral_constant<AllocCategory, e_BSLMA_ALLOC_PTR>());
}

template <class ALLOC>
inline
void *bsl::Function_Rep::initRep(std::size_t  sooFuncSize,
                                 const ALLOC& alloc,
                                 integral_constant<AllocCategory,
                                                   e_ERASED_STATEFUL_ALLOC>)
{
    using namespace BloombergLP;
    typedef typename bslma::AllocatorAdaptor<ALLOC>::Type Adaptor;

    static const std::size_t allocSize = sizeof(Adaptor);

    // Get real size of invocable from the soo-encoded size.
    const std::size_t funcSize = (sooFuncSize >= k_NON_SOO_SMALL_SIZE ?
                                  sooFuncSize - k_NON_SOO_SMALL_SIZE :
                                  sooFuncSize);

    const bool isInplaceFunc = sooFuncSize <= sizeof(InplaceBuffer);

    void *function_p;
    void *allocator_p;

    // A type-erased allocator is never allocated inplace.  Allocating the
    // allocator out of place allows the allocator to be moved from one
    // function object to another without changing its address.  This pointer
    // stability is critical to ensuring that move-constructing an inplace
    // functor does not result in a functor holding an pointer to a different
    // 'function' object's allocator.  Not having the erased allocator inplace
    // also simplifies the logic in a number of places.
    //
    // If the functor is allocated out of place, then the functor and the
    // out-of-place allocator can be allocated in a single memory block, since
    // they will always move together as a unit and the allocator's address
    // will not change.
    //
    // At the end if this 'if-else' statement, 'function_p' and 'allocator_p'
    // will point to storage allocated for the invocable and the allocator
    // adaptor, respectively.  Although this is a run-time 'if' statement, the
    // compiler will usually optimize away the conditional when 'sooFuncSize'
    // is known at compile time, if this function is inlined.  (Besides, it's
    // cheap even if not optimized away).
    if (isInplaceFunc) {
        // Function object fits in-place, but allocator is out-of-place
        function_p = &d_objbuf;
        // Allocate allocator adaptor from allocator itself
        allocator_p = Adaptor(alloc).allocate(allocSize);
    }
    else {
        // Not in-place.  Allocate (from the allocator) a single block to hold
        // the function and allocator adaptor.
        Function_PairBufDesc pairDesc(funcSize, allocSize);
        void *pair_p = Adaptor(alloc).allocate(pairDesc.totalSize());
        d_objbuf.d_object_p = pair_p;
        function_p = pairDesc.first(pair_p);
        allocator_p = pairDesc.second(pair_p);
    }

    // Construct allocator adaptor in its correct location.
    // Note that allocator copy constructor is not allowed to throw.
    d_allocator_p = ::new((void*) allocator_p) Adaptor(alloc);
    d_allocManager_p = &ownedAllocManager<ALLOC>;

    return function_p;
}

template <class ALLOC>
inline
void *bsl::Function_Rep::initRep(std::size_t sooFuncSize,
                                 const ALLOC& alloc,
                                 integral_constant<AllocCategory,
                                                   e_ERASED_STATELESS_ALLOC>)
{
    using namespace BloombergLP;

    // Since all instances of 'ALLOC' compare equal, we need only one instance
    // of it.  This single instance is wrapped in an adaptor.  Note that
    // 'ALLOC' should have been rebound to a common element type, so only one
    // singleton will be created for 'Foo<int(*)()>' and 'Foo<Bar>', where
    // 'Foo' is an STL-style allocator template.
    static typename bslma::AllocatorAdaptor<ALLOC>::Type allocInstance(alloc);

    return initRep(sooFuncSize, &allocInstance,
                   integral_constant<AllocCategory, e_BSLMA_ALLOC_PTR>());
}

inline
bool bsl::Function_Rep::equalAlloc(Allocator* alloc,
                     integral_constant<AllocCategory, e_BSLMA_ALLOC_PTR>) const
{
    return alloc == d_allocator_p;
}

template <class TP>
inline
bool bsl::Function_Rep::equalAlloc(const bsl::allocator<TP>& alloc,
                       integral_constant<AllocCategory, e_BSL_ALLOCATOR>) const
{
    return alloc.mechanism() == d_allocator_p;
}

template <class ALLOC>
inline
bool bsl::Function_Rep::equalAlloc(const ALLOC&,
              integral_constant<AllocCategory,e_ERASED_STATELESS_ALLOC>)  const
{
    using namespace BloombergLP;

    BSLMF_ASSERT((is_same<typename ALLOC::value_type, char>::value));

    typedef typename bslma::AllocatorAdaptor<ALLOC>::Type Adaptor;

    // If the our allocator has the same type as the adapted stateless
    // allocator, then they are assumed equal.
    return NULL != dynamic_cast<Adaptor*>(d_allocator_p);
}

template <class ALLOC>
inline
bool bsl::Function_Rep::equalAlloc(const ALLOC& alloc,
               integral_constant<AllocCategory, e_ERASED_STATEFUL_ALLOC>) const
{
    using namespace BloombergLP;

    BSLMF_ASSERT((is_same<typename ALLOC::value_type, char>::value));

    typedef typename bslma::AllocatorAdaptor<ALLOC>::Type Adaptor;

    // Try to cast our allocator into the same type as the adapted 'ALLOC'.
    Adaptor *thisAdaptor = dynamic_cast<Adaptor*>(d_allocator_p);

    if (! thisAdaptor) {
        // Different type.  Cannot compare equal.
        return false;                                                 // RETURN
    }

    // Compare the wrapped STL allocator to 'alloc'.
    return thisAdaptor->adaptedAllocator() == alloc;
}

template <class ALLOC, bsl::Function_Rep::AllocCategory ATP>
inline
void bsl::Function_Rep::copyRep(const Function_Rep&                   other,
                                const ALLOC&                          alloc,
                                integral_constant<AllocCategory, ATP> atp)
{
    // Compute function size.
    std::size_t sooFuncSize =
        other.d_funcManager_p(e_GET_SIZE, this, PtrOrSize_t()).asSize_t();

    initRep(sooFuncSize, alloc, atp);

    void *otherFunction_p = (sooFuncSize <= sizeof(InplaceBuffer) ?
                             &other.d_objbuf : other.d_objbuf.d_object_p);

    d_funcManager_p = other.d_funcManager_p;

    // Construct a copy of the function int its correct location
    d_funcManager_p(e_COPY_CONSTRUCT, this, otherFunction_p);
}

inline
bsl::Function_Rep::Function_Rep()
{
    d_objbuf.d_func_p = NULL;
    d_funcManager_p   = NULL;
    d_allocator_p     = NULL;
    d_allocManager_p  = NULL;
    d_invoker_p       = NULL;
}

template<class TP>
inline
TP* bsl::Function_Rep::target() BSLS_NOTHROW_SPEC
{
    if ((! d_funcManager_p) || target_type() != typeid(TP)) {
        return NULL;                                                  // RETURN
    }

    PtrOrSize_t target = d_funcManager_p(e_GET_TARGET, this, PtrOrSize_t());
    return static_cast<TP*>(target.asPtr());
}

template<class TP>
inline
const TP* bsl::Function_Rep::target() const BSLS_NOTHROW_SPEC
{
#if defined(BSLS_PLATFORM_CMP_MSVC) && BSLS_PLATFORM_CMP_VERSION < 1900
    return reinterpret_cast<const TP *>(
                                const_cast<Function_Rep*>(this)->target<TP>());
#else
    return const_cast<Function_Rep*>(this)->target<TP>();
#endif
}

inline
BloombergLP::bslma::Allocator *bsl::Function_Rep::allocator() const
{
    return d_allocator_p;
}

                        // ---------------------------
                        // class template Function_Imp
                        // ---------------------------

#if !BSLS_COMPILERFEATURES_SIMULATE_CPP11_FEATURES

// PRIVATE STATIC MEMBER FUNCTIONS
template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...  args)
{
    // Note that 'FUNC' might be different than 'RET(*)(ARGS...)'. All that is
    // required is that it be Callable with 'ARGS...' and return something
    // convertible to 'RET'.
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    // Cast to 'RET' is needed to avoid compilation error if 'RET' is void and
    // 'f' returns non-void.
    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS>::
                    forwardToTarget(args)...));
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::memFuncPtrInvoker(const Function_Rep *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    using namespace BloombergLP;

    // Workaround Sun compiler issue - it thinks we're trying to cast away
    // const or volatile if we use reinterpret_cast.
    // FUNC f = reinterpret_cast<const FUNC&>(rep->d_objbuf.d_memFunc_p);
    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS...>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT(sizeof...(ARGS) == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args...);
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    // Cast to 'RET' is needed to avoid compilation error if 'RET' is void and
    // 'f' returns non-void.
    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args...));
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS...)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    // Cast to 'RET' is needed to avoid compilation error if 'RET' is void and
    // 'f' returns non-void.
    return BSLSTL_FUNCTION_CAST_RESULT(f(args...));
}

template <class RET, class... ARGS>
inline
void bsl::Function_Imp<RET(ARGS...)>::setInvoker(Invoker *p)
{
    // Verify the assumption that all function pointers are the same size.
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}

template <class RET, class... ARGS>
inline
typename bsl::Function_Imp<RET(ARGS...)>::Invoker *
bsl::Function_Imp<RET(ARGS...)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}

// CREATORS
template <class RET, class... ARGS>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}

template <class RET, class... ARGS>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}

template <class RET, class... ARGS>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}

template <class RET, class... ARGS>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS...)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        // Empty 'function' object
        d_funcManager_p = NULL;
    }
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}

template <class RET, class... ARGS>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::~Function_Imp()
{
    // Assert class invariants
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    // Destroying the functor is not done in the base class destructor because
    // the invariant of the functor being fully constructed is not maintained
    // in the base class.  Moving this destruction to the base class would
    // cause exception handling to break if an exception were thrown when
    // constructing the wrapped functor.
    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}

// MANIPULATORS
template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>& bsl::Function_Imp<RET(ARGS...)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        // Equal allocators.  Just swap.
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}

template <class RET, class... ARGS>
template<class FUNC>
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(FUNC&& func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<FUNC&&>::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}

template <class RET, class... ARGS>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS...)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    // Remove possible const from 'FUNC' to get underlying functor type.
    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    // Initialize tempRep using allocator from 'this'
    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    // Move 'func' into initialized 'tempRep'
    if (tempRep.d_funcManager_p) {
        // Get non-const pointer to 'func'
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    // If successful (no exceptions thrown) swap 'tempRep' into '*this'.
    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        // Destroy the functor in 'tempRep' before 'tempRep' goes out of scope
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}

// TBD: Need to implement reference_wrapper.
// template <class RET, class... ARGS>
// template<class FUNC>
// function& bsl::Function_Imp<RET(ARGS...)>::operator=(reference_wrapper<FUNC>)
//     BSLS_NOTHROW_SPEC

template <class RET, class... ARGS>
inline
RET bsl::Function_Imp<RET(ARGS...)>::operator()(ARGS... args) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args...);                              // RETURN
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    // Non-exception build
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args...);
#endif
}

// ACCESSORS

#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::operator bool() const BSLS_NOTHROW_SPEC
{
    // If there is an invoker, then this function is non-empty (return true);
    // otherwise it is empty (return false).
    return invoker();
}
#endif // BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT


#elif BSLS_COMPILERFEATURES_SIMULATE_VARIADIC_TEMPLATES
// {{{ BEGIN GENERATED CODE
// The following section is automatically generated.  **DO NOT EDIT**
// Generator command line: sim_cpp11_features.pl --var-args=12 bslstl_function.h
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT
#define BSLSTL_FUNCTION_VARIADIC_LIMIT 12
#endif
#ifndef BSLSTL_FUNCTION_VARIADIC_LIMIT_C
#define BSLSTL_FUNCTION_VARIADIC_LIMIT_C BSLSTL_FUNCTION_VARIADIC_LIMIT
#endif

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template <class FUNC>
inline
RET bsl::Function_Imp<RET()>::functionPtrInvoker(
    const Function_Rep                                         *rep)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
    typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_08>::
                    forwardToTarget(args_08)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
    typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
    typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_08>::
                    forwardToTarget(args_08),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_09>::
                    forwardToTarget(args_09)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
    typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
    typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
    typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_08>::
                    forwardToTarget(args_08),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_09>::
                    forwardToTarget(args_09),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_10>::
                    forwardToTarget(args_10)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
    typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
    typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
    typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
    typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_08>::
                    forwardToTarget(args_08),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_09>::
                    forwardToTarget(args_09),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_10>::
                    forwardToTarget(args_10),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_11>::
                    forwardToTarget(args_11)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11,
                          ARGS_12)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
    typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
    typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
    typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
    typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
    typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
    typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
    typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
    typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
    typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
    typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
    typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS_01>::
                    forwardToTarget(args_01),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_02>::
                    forwardToTarget(args_02),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_03>::
                    forwardToTarget(args_03),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_04>::
                    forwardToTarget(args_04),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_05>::
                    forwardToTarget(args_05),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_06>::
                    forwardToTarget(args_06),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_07>::
                    forwardToTarget(args_07),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_08>::
                    forwardToTarget(args_08),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_09>::
                    forwardToTarget(args_09),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_10>::
                    forwardToTarget(args_10),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_11>::
                    forwardToTarget(args_11),
                    BloombergLP::bslmf::ForwardingTypeUtil<ARGS_12>::
                    forwardToTarget(args_12)));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template <class FUNC>
inline
RET bsl::Function_Imp<RET()>::memFuncPtrInvoker(const Function_Rep *rep)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 0u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 1u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 2u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 3u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 4u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 5u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 6u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 7u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07,
                                            ARGS_08>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 8u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07,
                                       args_08);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07,
                                            ARGS_08,
                                            ARGS_09>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT( 9u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07,
                                       args_08,
                                       args_09);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07,
                                            ARGS_08,
                                            ARGS_09,
                                            ARGS_10>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT(10u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07,
                                       args_08,
                                       args_09,
                                       args_10);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07,
                                            ARGS_08,
                                            ARGS_09,
                                            ARGS_10,
                                            ARGS_11>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT(11u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07,
                                       args_08,
                                       args_09,
                                       args_10,
                                       args_11);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11,
                          ARGS_12)>::memFuncPtrInvoker(const Function_Rep *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
            typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS_01,
                                            ARGS_02,
                                            ARGS_03,
                                            ARGS_04,
                                            ARGS_05,
                                            ARGS_06,
                                            ARGS_07,
                                            ARGS_08,
                                            ARGS_09,
                                            ARGS_10,
                                            ARGS_11,
                                            ARGS_12>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT(12u == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args_01,
                                       args_02,
                                       args_03,
                                       args_04,
                                       args_05,
                                       args_06,
                                       args_07,
                                       args_08,
                                       args_09,
                                       args_10,
                                       args_11,
                                       args_12);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template <class FUNC>
inline
RET bsl::Function_Imp<RET()>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07,
                    args_08));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07,
                    args_08,
                    args_09));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07,
                    args_08,
                    args_09,
                    args_10));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07,
                    args_08,
                    args_09,
                    args_10,
                    args_11));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11,
                          ARGS_12)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
            typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args_01,
                    args_02,
                    args_03,
                    args_04,
                    args_05,
                    args_06,
                    args_07,
                    args_08,
                    args_09,
                    args_10,
                    args_11,
                    args_12));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET()>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07,
                                         args_08));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07,
                                         args_08,
                                         args_09));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07,
                                         args_08,
                                         args_09,
                                         args_10));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07,
                                         args_08,
                                         args_09,
                                         args_10,
                                         args_11));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
            typename BloombergLP::bslmf::ForwardingType<ARGS_01>::Type args_01,
            typename BloombergLP::bslmf::ForwardingType<ARGS_02>::Type args_02,
            typename BloombergLP::bslmf::ForwardingType<ARGS_03>::Type args_03,
            typename BloombergLP::bslmf::ForwardingType<ARGS_04>::Type args_04,
            typename BloombergLP::bslmf::ForwardingType<ARGS_05>::Type args_05,
            typename BloombergLP::bslmf::ForwardingType<ARGS_06>::Type args_06,
            typename BloombergLP::bslmf::ForwardingType<ARGS_07>::Type args_07,
            typename BloombergLP::bslmf::ForwardingType<ARGS_08>::Type args_08,
            typename BloombergLP::bslmf::ForwardingType<ARGS_09>::Type args_09,
            typename BloombergLP::bslmf::ForwardingType<ARGS_10>::Type args_10,
            typename BloombergLP::bslmf::ForwardingType<ARGS_11>::Type args_11,
            typename BloombergLP::bslmf::ForwardingType<ARGS_12>::Type args_12)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args_01,
                                         args_02,
                                         args_03,
                                         args_04,
                                         args_05,
                                         args_06,
                                         args_07,
                                         args_08,
                                         args_09,
                                         args_10,
                                         args_11,
                                         args_12));
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
void bsl::Function_Imp<RET()>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
void bsl::Function_Imp<RET(ARGS_01)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10,
                           ARGS_11)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10,
                           ARGS_11,
                           ARGS_12)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
typename bsl::Function_Imp<RET()>::Invoker *
bsl::Function_Imp<RET()>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
typename bsl::Function_Imp<RET(ARGS_01)>::Invoker *
bsl::Function_Imp<RET(ARGS_01)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07,
                               ARGS_08)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07,
                               ARGS_08,
                               ARGS_09)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07,
                               ARGS_08,
                               ARGS_09,
                               ARGS_10)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07,
                               ARGS_08,
                               ARGS_09,
                               ARGS_10,
                               ARGS_11)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
typename bsl::Function_Imp<RET(ARGS_01,
                               ARGS_02,
                               ARGS_03,
                               ARGS_04,
                               ARGS_05,
                               ARGS_06,
                               ARGS_07,
                               ARGS_08,
                               ARGS_09,
                               ARGS_10,
                               ARGS_11,
                               ARGS_12)>::Invoker *
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class ALLOC>
inline
bsl::Function_Imp<RET()>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class ALLOC>
inline
bsl::Function_Imp<RET()>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET()>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET()>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template <class ALLOC>
inline
bsl::Function_Imp<RET()>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>&
bsl::Function_Imp<RET()>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>&
bsl::Function_Imp<RET(ARGS_01)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>& bsl::Function_Imp<RET()>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>& bsl::Function_Imp<RET(ARGS_01)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07,
                                                       ARGS_08)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07,
                                                       ARGS_08,
                                                       ARGS_09)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07,
                                                       ARGS_08,
                                                       ARGS_09,
                                                       ARGS_10)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07,
                                                       ARGS_08,
                                                       ARGS_09,
                                                       ARGS_10,
                                                       ARGS_11)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>& bsl::Function_Imp<RET(ARGS_01,
                                                       ARGS_02,
                                                       ARGS_03,
                                                       ARGS_04,
                                                       ARGS_05,
                                                       ARGS_06,
                                                       ARGS_07,
                                                       ARGS_08,
                                                       ARGS_09,
                                                       ARGS_10,
                                                       ARGS_11,
                                                       ARGS_12)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class FUNC>
bsl::Function_Imp<RET()>&
bsl::Function_Imp<RET()>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01)>&
bsl::Function_Imp<RET(ARGS_01)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class FUNC>
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
template<class FUNC>
inline
void bsl::Function_Imp<RET()>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10,
                           ARGS_11)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS_01,
                           ARGS_02,
                           ARGS_03,
                           ARGS_04,
                           ARGS_05,
                           ARGS_06,
                           ARGS_07,
                           ARGS_08,
                           ARGS_09,
                           ARGS_10,
                           ARGS_11,
                           ARGS_12)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12


#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>&
bsl::Function_Imp<RET()>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>&
bsl::Function_Imp<RET(ARGS_01)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>&
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12



#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
RET bsl::Function_Imp<RET()>::operator()() const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
RET bsl::Function_Imp<RET(ARGS_01)>::operator()(ARGS_01 args_01) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07,
                                                ARGS_08 args_08) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07,
                               args_08);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07,
                           args_08);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07,
                                                ARGS_08 args_08,
                                                ARGS_09 args_09) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07,
                               args_08,
                               args_09);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07,
                           args_08,
                           args_09);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07,
                                                ARGS_08 args_08,
                                                ARGS_09 args_09,
                                                ARGS_10 args_10) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07,
                               args_08,
                               args_09,
                               args_10);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07,
                           args_08,
                           args_09,
                           args_10);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07,
                                                ARGS_08 args_08,
                                                ARGS_09 args_09,
                                                ARGS_10 args_10,
                                                ARGS_11 args_11) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07,
                               args_08,
                               args_09,
                               args_10,
                               args_11);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07,
                           args_08,
                           args_09,
                           args_10,
                           args_11);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
RET bsl::Function_Imp<RET(ARGS_01,
                          ARGS_02,
                          ARGS_03,
                          ARGS_04,
                          ARGS_05,
                          ARGS_06,
                          ARGS_07,
                          ARGS_08,
                          ARGS_09,
                          ARGS_10,
                          ARGS_11,
                          ARGS_12)>::operator()(ARGS_01 args_01,
                                                ARGS_02 args_02,
                                                ARGS_03 args_03,
                                                ARGS_04 args_04,
                                                ARGS_05 args_05,
                                                ARGS_06 args_06,
                                                ARGS_07 args_07,
                                                ARGS_08 args_08,
                                                ARGS_09 args_09,
                                                ARGS_10 args_10,
                                                ARGS_11 args_11,
                                                ARGS_12 args_12) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args_01,
                               args_02,
                               args_03,
                               args_04,
                               args_05,
                               args_06,
                               args_07,
                               args_08,
                               args_09,
                               args_10,
                               args_11,
                               args_12);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args_01,
                           args_02,
                           args_03,
                           args_04,
                           args_05,
                           args_06,
                           args_07,
                           args_08,
                           args_09,
                           args_10,
                           args_11,
                           args_12);
#endif
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12



#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0
template <class RET>
inline
bsl::Function_Imp<RET()>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 0

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1
template <class RET, class ARGS_01>
inline
bsl::Function_Imp<RET(ARGS_01)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 1

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2
template <class RET, class ARGS_01,
                     class ARGS_02>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 2

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 3

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 4

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 5

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 6

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 7

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 8

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 9

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 10

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 11

#if BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12
template <class RET, class ARGS_01,
                     class ARGS_02,
                     class ARGS_03,
                     class ARGS_04,
                     class ARGS_05,
                     class ARGS_06,
                     class ARGS_07,
                     class ARGS_08,
                     class ARGS_09,
                     class ARGS_10,
                     class ARGS_11,
                     class ARGS_12>
inline
bsl::Function_Imp<RET(ARGS_01,
                      ARGS_02,
                      ARGS_03,
                      ARGS_04,
                      ARGS_05,
                      ARGS_06,
                      ARGS_07,
                      ARGS_08,
                      ARGS_09,
                      ARGS_10,
                      ARGS_11,
                      ARGS_12)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif  // BSLSTL_FUNCTION_VARIADIC_LIMIT_C >= 12

#endif

#else
// The generated code below is a workaround for the absence of perfect
// forwarding in some compilers.

template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::functionPtrInvoker(
    const Function_Rep                                         *rep,
    typename BloombergLP::bslmf::ForwardingType<ARGS>::Type...  args)
{
    FUNC f = reinterpret_cast<FUNC>(rep->d_objbuf.d_func_p);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(BloombergLP::bslmf::ForwardingTypeUtil<ARGS>::
                    forwardToTarget(args)...));
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::memFuncPtrInvoker(const Function_Rep *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    using namespace BloombergLP;

    FUNC f = (const FUNC&)(rep->d_objbuf.d_memFunc_p);
    typedef typename bslmf::NthParameter<0, ARGS...>::Type ObjType;
    typedef Function_MemFuncInvoke<FUNC, ObjType> InvokeType;
    BSLMF_ASSERT(sizeof...(ARGS) == InvokeType::NUM_ARGS + 1);
    return (RET) InvokeType::invoke(f, args...);
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET bsl::Function_Imp<RET(ARGS...)>::inplaceFunctorInvoker(
               const Function_Rep                                        *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    FUNC& f = reinterpret_cast<FUNC&>(rep->d_objbuf);

    return BSLSTL_FUNCTION_CAST_RESULT(
                  f(args...));
}

template <class RET, class... ARGS>
template <class FUNC>
inline
RET
bsl::Function_Imp<RET(ARGS...)>::outofplaceFunctorInvoker(
               const Function_Rep                                        *rep,
               typename BloombergLP::bslmf::ForwardingType<ARGS>::Type... args)
{
    FUNC& f = *reinterpret_cast<FUNC*>(rep->d_objbuf.d_object_p);
    return BSLSTL_FUNCTION_CAST_RESULT(f(args...));
}

template <class RET, class... ARGS>
inline
void bsl::Function_Imp<RET(ARGS...)>::setInvoker(Invoker *p)
{
    BSLMF_ASSERT(sizeof(Invoker*) == sizeof(d_invoker_p));

    typedef void (*VoidFn)();

    d_invoker_p = reinterpret_cast<VoidFn>(p);
}

template <class RET, class... ARGS>
inline
typename bsl::Function_Imp<RET(ARGS...)>::Invoker *
bsl::Function_Imp<RET(ARGS...)>::invoker() const
{
    return reinterpret_cast<Invoker*>(d_invoker_p);
}

template <class RET, class... ARGS>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC& alloc)
{
    setInvoker(NULL);

    typedef Function_AllocTraits<ALLOC> Traits;
    initRep(0, typename Traits::Type(alloc), typename Traits::Category());
}

template <class RET, class... ARGS>
template<class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC&    alloc,
                                              const Function_Imp& other)
{
    copyInit(alloc, other);
}

template <class RET, class... ARGS>
template<class FUNC, class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(const ALLOC& alloc, FUNC func)
{
    initFromTarget(&func, alloc);
}

template <class RET, class... ARGS>
template<class FUNC, class ALLOC>
inline void
bsl::Function_Imp<RET(ARGS...)>::initFromTarget(FUNC *func, const ALLOC& alloc)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    setInvoker(invokerForFunc(*func));

    std::size_t sooFuncSize = invoker() ? Soo::SooFuncSize<FUNC>::VALUE : 0;

    initRep(sooFuncSize, typename AllocTraits::Type(alloc),
            typename AllocTraits::Category());

    if (invoker()) {
        d_funcManager_p = getFunctionManager<FUNC>();
        d_funcManager_p(e_MOVE_CONSTRUCT, this, func);
    }
    else {
        d_funcManager_p = NULL;
    }
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(
                            BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    Function_Imp& lvalue = other;
    moveInit(lvalue);
}

template <class RET, class... ARGS>
template <class ALLOC>
inline
bsl::Function_Imp<RET(ARGS...)>::Function_Imp(
    const ALLOC&                                 alloc,
    BloombergLP::bslmf::MovableRef<Function_Imp> other)
{
    typedef Function_AllocTraits<ALLOC> AllocTraits;

    Function_Imp& lvalue = other;

    if (lvalue.equalAlloc(alloc, typename AllocTraits::Category())) {
        moveInit(lvalue);
    }
    else {
        copyInit(typename AllocTraits::Type(alloc), lvalue);
    }
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::~Function_Imp()
{
    BSLS_ASSERT(invoker() || ! d_funcManager_p);
    BSLS_ASSERT(d_allocator_p);

    if (d_funcManager_p) {
        d_funcManager_p(e_DESTROY, this, PtrOrSize_t());
    }
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(const Function_Imp& rhs)
{
    Function_Rep::assignRep(e_COPY_CONSTRUCT, const_cast<Function_Imp*>(&rhs));

    return *this;
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>& bsl::Function_Imp<RET(ARGS...)>::
operator=(BloombergLP::bslmf::MovableRef<Function_Imp> rhs)
{
    Function_Imp& lvalue = rhs;
    if (d_allocManager_p(e_IS_EQUAL, this, rhs.d_allocator_p).asSize_t()) {
        this->swap(lvalue);
    }
    else {
        Function_Rep::assignRep(e_MOVE_CONSTRUCT, &lvalue);
    }

    return *this;
}

template <class RET, class... ARGS>
template<class FUNC>
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(
                                  BSLS_COMPILERFEATURES_FORWARD_REF(FUNC) func)
{
#ifdef BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES
    if (bsl::is_rvalue_reference<BSLS_COMPILERFEATURES_FORWARD_REF(FUNC)
                                 >::value) {
        assignTarget(e_MOVE_CONSTRUCT, &func);
    }
    else
#endif
    {
        assignTarget(e_COPY_CONSTRUCT, &func);
    }
    return *this;
}

template <class RET, class... ARGS>
template<class FUNC>
inline
void bsl::Function_Imp<RET(ARGS...)>::assignTarget(ManagerOpCode  moveOrCopy,
                                               FUNC          *func)
{
    Function_Rep tempRep;

    typedef typename bsl::remove_const<FUNC>::type FuncType;

    Invoker *invoker_p = invokerForFunc(*func);
    tempRep.d_funcManager_p = invoker_p ? getFunctionManager<FuncType>() :NULL;

    this->d_allocManager_p(e_INIT_REP, &tempRep, this->d_allocator_p);

    if (tempRep.d_funcManager_p) {
        FuncType *funcAddr = const_cast<FuncType*>(func);
        tempRep.d_funcManager_p(moveOrCopy, &tempRep, funcAddr);
    }

    tempRep.swap(*this);
    if (tempRep.d_funcManager_p) {
        tempRep.d_funcManager_p(e_DESTROY, &tempRep, PtrOrSize_t());
    }

    setInvoker(invoker_p);
}

template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>&
bsl::Function_Imp<RET(ARGS...)>::operator=(nullptr_t)
{
    setInvoker(NULL);
    makeEmpty();
    return *this;
}


template <class RET, class... ARGS>
inline
RET bsl::Function_Imp<RET(ARGS...)>::operator()(ARGS... args) const
{
#ifdef BDE_BUILD_TARGET_EXC

    if (invoker()) {
        return invoker()(this, args...);
    }
    else {
        BSLS_THROW(bad_function_call());
    }

#else
    BSLS_ASSERT_OPT(invoker());
    return invoker()(this, args...);
#endif
}


#ifdef BSLS_COMPILERFEATURES_SUPPORT_OPERATOR_EXPLICIT
template <class RET, class... ARGS>
inline
bsl::Function_Imp<RET(ARGS...)>::operator bool() const BSLS_NOTHROW_SPEC
{
    return invoker();
}
#endif


// }}} END GENERATED CODE
#endif

                        // ----------------------------
                        // class template bsl::function
                        // ----------------------------

template <class PROTOTYPE>
inline typename bsl::function<PROTOTYPE>::Base&
bsl::function<PROTOTYPE>::upcast(function& f) {
    return static_cast<Base&>(f);
}

template <class PROTOTYPE>
inline const typename bsl::function<PROTOTYPE>::Base&
bsl::function<PROTOTYPE>::upcast(const function& f) {
    return static_cast<const Base&>(f);
}

    // CREATORS
template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>::function() BSLS_NOTHROW_SPEC
    : Base(BloombergLP::bslma::Default::defaultAllocator()) {}

template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>::function(nullptr_t) BSLS_NOTHROW_SPEC
    : Base(BloombergLP::bslma::Default::defaultAllocator()) {}

template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>::function(const function& other)
    : Base(BloombergLP::bslma::Default::defaultAllocator(), upcast(other)) {}

template <class PROTOTYPE>
template<class ALLOC>
inline bsl::function<PROTOTYPE>::function(allocator_arg_t, const ALLOC& alloc)
    : Base(alloc) {}

template <class PROTOTYPE>
template <class ALLOC>
inline bsl::function<PROTOTYPE>::function(allocator_arg_t,
                                          const ALLOC& alloc,
                                          nullptr_t)
    : Base(alloc) {}

template <class PROTOTYPE>
template <class ALLOC>
inline bsl::function<PROTOTYPE>::function(allocator_arg_t,
                                          const ALLOC&    alloc,
                                          const function& other)
    : Base(alloc, upcast(other)) {}

template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>::function(
                               BloombergLP::bslmf::MovableRef<function> other)
    : Base(MovableRefUtil::move(upcast(MovableRefUtil::access(other)))) {}

template <class PROTOTYPE>
template <class ALLOC>
inline bsl::function<PROTOTYPE>::function(
                                allocator_arg_t,
                                const ALLOC&                             alloc,
                                BloombergLP::bslmf::MovableRef<function> other)
    : Base(alloc, MovableRefUtil::move(upcast(MovableRefUtil::access(other))))
{
}

// MANIPULATORS
template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>&
bsl::function<PROTOTYPE>::operator=(const function& rhs)
{
    Base::operator=(upcast(rhs));
    return *this;
}

template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>&
bsl::function<PROTOTYPE>::operator=(
                                BloombergLP::bslmf::MovableRef<function> rhs) {
    Base::operator=(MovableRefUtil::move(upcast(MovableRefUtil::access(rhs))));
    return *this;
}

template <class PROTOTYPE>
inline bsl::function<PROTOTYPE>&
bsl::function<PROTOTYPE>::operator=(nullptr_t) {
    Base::operator=(nullptr_t());
    return *this;
}

// FREE FUNCTIONS
template <class PROTOTYPE>
inline
bool bsl::operator==(const bsl::function<PROTOTYPE>& f,
                     bsl::nullptr_t) BSLS_NOTHROW_SPEC
{
    return !f;
}

template <class PROTOTYPE>
inline
bool bsl::operator==(bsl::nullptr_t,
                     const bsl::function<PROTOTYPE>& f) BSLS_NOTHROW_SPEC
{
    return !f;
}

template <class PROTOTYPE>
inline
bool bsl::operator!=(const bsl::function<PROTOTYPE>& f,
                     bsl::nullptr_t                   ) BSLS_NOTHROW_SPEC
{
    return static_cast<bool>(f);
}

template <class PROTOTYPE>
inline
bool bsl::operator!=(bsl::nullptr_t,
                     const bsl::function<PROTOTYPE>& f) BSLS_NOTHROW_SPEC
{
    return static_cast<bool>(f);
}

template <class PROTOTYPE>
inline
void bsl::swap(bsl::function<PROTOTYPE>& a, bsl::function<PROTOTYPE>& b)
{
    a.swap(b);
}

// TRAITS

namespace BloombergLP {
namespace bslmf {

template <class FUNC>
struct IsBitwiseMoveable<bsl::Function_NothrowWrapper<FUNC> >
   : IsBitwiseMoveable<FUNC>::type
{
};

} // close namespace bslmf
} // close namespace BloombergLP

#endif // ! defined(INCLUDED_BSLSTL_FUNCTION)

// ----------------------------------------------------------------------------
// Copyright 2014 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
