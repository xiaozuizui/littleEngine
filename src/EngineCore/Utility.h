#pragma once
#include <cstdarg>
#include <cstdio>
#include <string>
#include <corecrt.h>
#include <ppltasks.h>

namespace littleEngine
{
	namespace Utility
	{
		inline void Print(const char* msg) { printf("%s", msg); }
		inline void Print(const wchar_t* msg) { wprintf(L"%ws", msg); }

		inline void Printf(const char* format, ...)
		{
			char buffer[256];
			va_list ap;
			va_start(ap, format);
			vsprintf_s(buffer, 256, format, ap);
			Print(buffer);
		}

		inline void Printf(const wchar_t* format, ...)
		{
			wchar_t buffer[256];
			va_list ap;
			va_start(ap, format);
			vswprintf(buffer, 256, format, ap);
			Print(buffer);
		}

#ifndef RELEASE
		inline void PrintSubMessage(const char* format, ...)
		{
			Print("--> ");
			char buffer[256];
			va_list ap;
			va_start(ap, format);
			vsprintf_s(buffer, 256, format, ap);
			Print(buffer);
			Print("\n");
		}
		inline void PrintSubMessage(const wchar_t* format, ...)
		{
			Print("--> ");
			wchar_t buffer[256];
			va_list ap;
			va_start(ap, format);
			vswprintf(buffer, 256, format, ap);
			Print(buffer);
			Print("\n");
		}
		inline void PrintSubMessage(void)
		{
		}
#endif

	} // namespace Utility
}



#ifdef ERROR
#undef ERROR
#endif
#ifdef ASSERT
#undef ASSERT
#endif
#ifdef HALT
#undef HALT
#endif

#define HALT( ... ) ERROR( __VA_ARGS__ ) __debugbreak();

#ifdef RELEASE

#define ASSERT( isTrue, ... ) (void)(isTrue)
#define WARN_ONCE_IF( isTrue, ... ) (void)(isTrue)
#define WARN_ONCE_IF_NOT( isTrue, ... ) (void)(isTrue)
#define ERROR( msg, ... )
#define DEBUGPRINT( msg, ... ) do {} while(0)
#define ASSERT_SUCCEEDED( hr, ... ) (void)(hr)

#else    // !RELEASE

#define STRINGIFY(x) #x
#define STRINGIFY_BUILTIN(x) STRINGIFY(x)
#define ASSERT( isFalse, ... ) \
        if (!(bool)(isFalse)) { \
            littleEngine::Utility::Print("\nAssertion failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            littleEngine::Utility::PrintSubMessage("\'" #isFalse "\' is false"); \
            littleEngine::Utility::PrintSubMessage(__VA_ARGS__); \
            littleEngine::Utility::Print("\n"); \
            __debugbreak(); \
        }

#define ASSERT_SUCCEEDED( hr, ... ) \
        if (FAILED(hr)) { \
            littleEngine::Utility::Print("\nHRESULT failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            littleEngine::Utility::PrintSubMessage("hr = 0x%08X", hr); \
            littleEngine::Utility::PrintSubMessage(__VA_ARGS__); \
            littleEngine::Utility::Print("\n"); \
            __debugbreak(); \
        }


#define WARN_ONCE_IF( isTrue, ... ) \
    { \
        static bool s_TriggeredWarning = false; \
        if ((bool)(isTrue) && !s_TriggeredWarning) { \
            s_TriggeredWarning = true; \
            littleEngine::Utility::Print("\nWarning issued in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            littleEngine::Utility::PrintSubMessage("\'" #isTrue "\' is true"); \
            littleEngine::Utility::PrintSubMessage(__VA_ARGS__); \
            littleEngine::Utility::Print("\n"); \
        } \
    }

#define WARN_ONCE_IF_NOT( isTrue, ... ) WARN_ONCE_IF(!(isTrue), __VA_ARGS__)

#define ERROR( ... ) \
        littleEngine::Utility::Print("\nError reported in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
        littleEngine::Utility::PrintSubMessage(__VA_ARGS__); \
        littleEngine::Utility::Print("\n");

#define DEBUGPRINT( msg, ... ) \
    littleEngine::Utility::Printf( msg "\n", ##__VA_ARGS__ );

#endif

void SIMDMemCopy(void* __restrict Dest, const void* __restrict Source, size_t NumQuadwords);
void SIMDMemFill(void* __restrict Dest, __m128 FillVector, size_t NumQuadwords);

std::wstring MakeWStr(const std::string& str);