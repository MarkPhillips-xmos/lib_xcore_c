#pragma once

#define _XMM_SHIM(FLM, ...) FLM(__VA_ARGS__)
#define _XMM_UNIQUE_LABEL_I(BNAME, CNT) BNAME ## CNT ## _
#define _XMM_UNIQUE_LABEL(BNAME) _XMM_SHIM(_XMM_UNIQUE_LABEL_I, BNAME, __COUNTER__)
#define _XMM_STRINGIFY_I(S) #S
#define _XMM_STRINGIFY(S) _XMM_STRINGIFY_I(S)

#define _XMM_SEP_COMMA ,
#define _XMM_SEP_NONE

#define _XMM_APPLY0(F, SEP)
#define _XMM_APPLY1(F, SEP, A0, ...) F(A0) _XMM_APPLY0(F, SEP, ## __VA_ARGS__)
#define _XMM_APPLY2(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY1(F, SEP, __VA_ARGS__)
#define _XMM_APPLY3(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY2(F, SEP, __VA_ARGS__)
#define _XMM_APPLY4(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY3(F, SEP, __VA_ARGS__)
#define _XMM_APPLY5(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY4(F, SEP, __VA_ARGS__)
#define _XMM_APPLY6(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY5(F, SEP, __VA_ARGS__)
#define _XMM_APPLY7(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY6(F, SEP, __VA_ARGS__)
#define _XMM_APPLY8(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY7(F, SEP, __VA_ARGS__)
#define _XMM_APPLY9(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY8(F, SEP, __VA_ARGS__)
#define _XMM_APPLY10(F, SEP, A0, ...) F(A0) _XMM_SEP_##SEP _XMM_APPLY9(F, SEP, __VA_ARGS__)

#define _XMM_GET10(I0, I1, I2, I3, I4, T5, T6, T7, T8, T9, N, ...) N
#define _XMM_APPLICATOR(...) _XMM_GET10(__VA_ARGS__, _XMM_APPLY10, _XMM_APPLY9, _XMM_APPLY8, _XMM_APPLY7, _XMM_APPLY6, _XMM_APPLY5, _XMM_APPLY4, _XMM_APPLY3, _XMM_APPLY2, _XMM_APPLY1, _XMM_APPLY0)

#define _XMM_APPLY_I(F, SEP, ...) _XMM_APPLICATOR(__VA_ARGS__)(F, SEP, ## __VA_ARGS__)
#define _XMM_APPLY(F, ...) _XMM_APPLY_I(F, COMMA, ## __VA_ARGS__)
#define _XMM_APPLY_NOSEP(F, ...) _XMM_APPLY_I(F, NONE, ## __VA_ARGS__)
#define _XMM_LABELADDR(LABEL) &&LABEL

#define _XMM_DEPAREN(...) __VA_ARGS__
#define _XMM_PSHIM(FLM, PACK) _XMM_SHIM(FLM, _XMM_DEPAREN PACK)