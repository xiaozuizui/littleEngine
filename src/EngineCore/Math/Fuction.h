#pragma once
#include "../Math/Common.h"
#include "../Math/Vector.h"
//
//INLINE float Sqrt(float s) { return Sqrt(Scalar(s)); }
//INLINE float Recip(float s) { return Recip(Scalar(s)); }
//INLINE float RecipSqrt(float s) { return RecipSqrt(Scalar(s)); }
//INLINE float Floor(float s) { return Floor(Scalar(s)); }
//INLINE float Ceiling(float s) { return Ceiling(Scalar(s)); }
//INLINE float Round(float s) { return Round(Scalar(s)); }
//INLINE float Abs(float s) { return s < 0.0f ? -s : s; }
//INLINE float Exp(float s) { return Exp(Scalar(s)); }
//INLINE float Pow(float b, float e) { return Pow(Scalar(b), Scalar(e)); }
//INLINE float Log(float s) { return Log(Scalar(s)); }
//INLINE float Sin(float s) { return Sin(Scalar(s)); }
//INLINE float Cos(float s) { return Cos(Scalar(s)); }
//INLINE float Tan(float s) { return Tan(Scalar(s)); }
//INLINE float ASin(float s) { return ASin(Scalar(s)); }
//INLINE float ACos(float s) { return ACos(Scalar(s)); }
//INLINE float ATan(float s) { return ATan(Scalar(s)); }
//INLINE float ATan2(float y, float x) { return ATan2(Scalar(y), Scalar(x)); }
namespace littleEngine
{
	namespace Math
	{
		INLINE float Lerp(float a, float b, float t) { return a + (b - a) * t; }
		INLINE float Max(float a, float b) { return a > b ? a : b; }
		INLINE float Min(float a, float b) { return a < b ? a : b; }
		INLINE float Clamp(float v, float a, float b) { return Min(Max(v, a), b); }


#define CREATE_SIMD_FUNCTIONS( TYPE ) \
    INLINE TYPE Sqrt( TYPE s ) { return TYPE(XMVectorSqrt(s)); } \
    INLINE TYPE Recip( TYPE s ) { return TYPE(XMVectorReciprocal(s)); } \
    INLINE TYPE RecipSqrt( TYPE s ) { return TYPE(XMVectorReciprocalSqrt(s)); } \
    INLINE TYPE Floor( TYPE s ) { return TYPE(XMVectorFloor(s)); } \
    INLINE TYPE Ceiling( TYPE s ) { return TYPE(XMVectorCeiling(s)); } \
    INLINE TYPE Round( TYPE s ) { return TYPE(XMVectorRound(s)); } \
    INLINE TYPE Abs( TYPE s ) { return TYPE(XMVectorAbs(s)); } \
    INLINE TYPE Exp( TYPE s ) { return TYPE(XMVectorExp(s)); } \
    INLINE TYPE Pow( TYPE b, TYPE e ) { return TYPE(XMVectorPow(b, e)); } \
    INLINE TYPE Log( TYPE s ) { return TYPE(XMVectorLog(s)); } \
    INLINE TYPE Sin( TYPE s ) { return TYPE(XMVectorSin(s)); } \
    INLINE TYPE Cos( TYPE s ) { return TYPE(XMVectorCos(s)); } \
    INLINE TYPE Tan( TYPE s ) { return TYPE(XMVectorTan(s)); } \
    INLINE TYPE ASin( TYPE s ) { return TYPE(XMVectorASin(s)); } \
    INLINE TYPE ACos( TYPE s ) { return TYPE(XMVectorACos(s)); } \
    INLINE TYPE ATan( TYPE s ) { return TYPE(XMVectorATan(s)); } \
    INLINE TYPE ATan2( TYPE y, TYPE x ) { return TYPE(XMVectorATan2(y, x)); } \
    INLINE TYPE Lerp( TYPE a, TYPE b, TYPE t ) { return TYPE(XMVectorLerpV(a, b, t)); } \
    INLINE TYPE Max( TYPE a, TYPE b ) { return TYPE(XMVectorMax(a, b)); } \
    INLINE TYPE Min( TYPE a, TYPE b ) { return TYPE(XMVectorMin(a, b)); } \
    INLINE TYPE Clamp( TYPE v, TYPE a, TYPE b ) { return Min(Max(v, a), b); } \
    INLINE BoolVector operator<  ( TYPE lhs, TYPE rhs ) { return XMVectorLess(lhs, rhs); } \
    INLINE BoolVector operator<= ( TYPE lhs, TYPE rhs ) { return XMVectorLessOrEqual(lhs, rhs); } \
    INLINE BoolVector operator>  ( TYPE lhs, TYPE rhs ) { return XMVectorGreater(lhs, rhs); } \
    INLINE BoolVector operator>= ( TYPE lhs, TYPE rhs ) { return XMVectorGreaterOrEqual(lhs, rhs); } \
    INLINE BoolVector operator== ( TYPE lhs, TYPE rhs ) { return XMVectorEqual(lhs, rhs); } \
    INLINE TYPE Select( TYPE lhs, TYPE rhs, BoolVector mask ) { return TYPE(XMVectorSelect(lhs, rhs, mask)); }

	CREATE_SIMD_FUNCTIONS(Vector3)
	}



}
