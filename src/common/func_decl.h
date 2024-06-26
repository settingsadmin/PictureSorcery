#if !defined(_INCLUDE_func_decl_h)
#define _INCLUDE_func_decl_h


#if defined(__DISABLE_INLINING__) && (__DISABLE_INLINING__ == 1)


#define _ALWIN /*blank*/
#define _NEVIN /*blank*/


#else


#define _ALWIN __##attribute##__((__##always_inline##__)) inline
#define _NEVIN __##attribute##__((__##no_inline##__))


#endif


#endif
