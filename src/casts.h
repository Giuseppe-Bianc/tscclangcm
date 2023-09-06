#pragma once
#include <gsl/gsl>
// Macro to cast to std::byte
// Description:
//   This macro is used to cast a value to std::byte type.
// Usage example:
//   std::byte b = C_B(255);
#define C_B(x) static_cast<std::byte>(x)
#define NC_B(x) gsl::narrow_cast<std::byte>(x)
// Macro to cast to std::intptr_t
// Description:
//   This macro is used to cast a value to std::intptr_t type.
// Usage example:
//   std::intptr_t ptr = C_IPTR(somePointer);
#define C_IPTR(x) static_cast<std::intptr_t>(x)
#define NC_IPTR(x) gsl::narrow_cast<std::intptr_t>(x)
// Macro to cast to std::uintptr_t
// Description:
//   This macro is used to cast a value to std::uintptr_t type.
// Usage example:
//   std::uintptr_t ptr = C_UIPTR(somePointer);
#define C_UIPTR(x) static_cast<std::uintptr_t>(x)
#define NC_UIPTR(x) gsl::narrow_cast<std::uintptr_t>(x)
// Macro to cast to std::int8_t
// Description:
//   This macro is used to cast a value to std::int8_t type.
// Usage example:
//   std::int8_t value = C_I8T(42);
#define C_I8T(x) static_cast<std::int8_t>(x)
#define NC_I8T(x) gsl::narrow_cast<std::int8_t>(x)
// Macro to cast to std::int16_t
// Description:
//   This macro is used to cast a value to std::int16_t type.
// Usage example:
//   std::int16_t value = C_I16T(42);
#define C_I16T(x) static_cast<std::int16_t>(x)
#define NC_I16T(x) gsl::narrow_cast<std::int16_t>(x)
// Macro to cast to std::int32_t
// Description:
//   This macro is used to cast a value to std::int32_t type.
// Usage example:
//   std::int32_t value = C_I32T(42);
#define C_I32T(x) static_cast<std::int32_t>(x)
#define NC_I32T(x) gsl::narrow_cast<std::int32_t>(x)
// Macro to cast to std::int64_t
// Description:
//   This macro is used to cast a value to std::int64_t type.
// Usage example:
//   std::int64_t value = C_I64T(42);
#define C_I64T(x) static_cast<std::int64_t>(x)
#define NC_I64T(x) gsl::narrow_cast<std::int64_t>(x)
// Macro to cast to std::uint8_t
// Description:
//   This macro is used to cast a value to std::uint8_t type.
// Usage example:
//   std::uint8_t value = C_UI8T(42);
#define C_UI8T(x) static_cast<std::uint8_t>(x)
#define NC_UI8T(x) gsl::narrow_cast<std::uint8_t>(x)
// Macro to cast to std::uint16_t
// Description:
//   This macro is used to cast a value to std::uint16_t type.
// Usage example:
//   std::uint16_t value = C_UI16T(42);
#define C_UI16T(x) static_cast<std::uint16_t>(x)
#define NC_UI16T(x) gsl::narrow_cast<std::uint16_t>(x)
// Macro to cast to std::uint32_t
// Description:
//   This macro is used to cast a value to std::uint32_t type.
// Usage example:
//   std::uint32_t value = C_UI32T(42);
#define C_UI32T(x) static_cast<std::uint32_t>(x)
#define NC_UI32T(x) gsl::narrow_cast<std::uint32_t>(x)
// Macro to cast to std::uint64_t
// Description:
//   This macro is used to cast a value to std::uint64_t type.
// Usage example:
//   std::uint64_t value = C_UI64T(42);
#define C_UI64T(x) static_cast<std::uint64_t>(x)
#define NC_UI64T(x) gsl::narrow_cast<std::uint64_t>(x)
// Macro to cast to std::ptrdiff_t
// Description:
//   This macro is used to cast a value to std::ptrdiff_t type.
// Usage example:
//   std::ptrdiff_t diff = C_PTRDIFT(10);
#define C_PTRDIFT(x) static_cast<std::ptrdiff_t>(x)
#define NC_PTRDIFT(x) gsl::narrow_cast<std::ptrdiff_t>(x)
// Macro to cast to std::div_t
// Description:
//   This macro is used to cast a value to std::div_t type.
// Usage example:
//   std::div_t result = C_DIVT(10);
#define C_DIVT(x) static_cast<std::div_t>(x)
#define NC_DIVT(x) gsl::narrow_cast<std::div_t>(x)
// Macro to cast to std::ldiv_t
// Description:
//   This macro is used to cast a value to std::ldiv_t type.
// Usage example:
//   std::ldiv_t result = C_LDIVT(10);
#define C_LDIVT(x) static_cast<std::ldiv_t>(x)
#define NC_LDIVT(x) gsl::narrow_cast<std::ldiv_t>(x)
// Macro to cast to char
// Description:
//   This macro is used to cast a value to char type.
// Usage example:
//   char c = C_C(65);
#define C_C(x) static_cast<char>(x)
#define NC_C(x) gsl::narrow_cast<char>(x)
// Macro to cast to char16_t
// Description:
//   This macro is used to cast a value to char16_t type.
// Usage example:
//   char16_t c = C_C16(65);
#define C_C16(x) static_cast<char16_t>(x)
#define NC_C16(x) gsl::narrow_cast<char16_t>(x)
// Macro to cast to char32_t
// Description:
//   This macro is used to cast a value to char32_t type.
// Usage example:
//   char32_t c = C_C32(65);
#define C_C32(x) static_cast<char32_t>(x)
#define NC_C32(x) gsl::narrow_cast<char32_t>(x)
// Macro to cast to char8_t
// Description:
//   This macro is used to cast a value to char8_t type.
// Usage example:
//   char8_t c = C_C8(65);
#define C_C8(x) static_cast<char8_t>(x)
#define NC_C8(x) gsl::narrow_cast<char8_t>(x)
// Macro to cast to double
// Description:
//   This macro is used to cast a value to double type.
// Usage example:
//   double d = C_D(3.14f);
#define C_D(x) static_cast<double>(x)
#define NC_D(x) gsl::narrow_cast<double>(x)
// Macro to cast to float
// Description:
//   This macro is used to cast a value to float type.
// Usage example:
//   float f = C_F(3.14);
#define C_F(x) static_cast<float>(x)
#define NC_F(x) gsl::narrow_cast<float>(x)
// Macro to cast to int
// Description:
//   This macro is used to cast a value to int type.
// Usage example:
//   int i = C_I(3.14f);
#define C_I(x) static_cast<int>(x)
#define NC_I(x) gsl::narrow_cast<int>(x)
// Macro to cast to long
// Description:
//   This macro is used to cast a value to long type.
// Usage example:
//   long l = C_L(42);
#define C_L(x) static_cast<long>(x)
#define NC_L(x) gsl::narrow_cast<long>(x)
// Macro to cast to long double
// Description:
//   This macro is used to cast a value to long double type.
// Usage example:
//   long double ld = C_LD(3.14f);
#define C_LD(x) static_cast<long double>(x)
#define NC_LD(x) gsl::narrow_cast<long double>(x)
// Macro to cast to long int
// Description:
//   This macro is used to cast a value to long int type.
// Usage example:
//   long int li = C_LI(42);
#define C_LI(x) static_cast<long int>(x)
#define NC_LI(x) gsl::narrow_cast<long int>(x)
// Macro to cast to long long
// Description:
//   This macro is used to cast a value to long long type.
// Usage example:
//   long long ll = C_LL(42);
#define C_LL(x) static_cast<long long>(x)
#define NC_LL(x) gsl::narrow_cast<long long>(x)
// Macro to cast to long long int
// Description:
//   This macro is used to cast a value to long long int type.
// Usage example:
//   long long int lli = C_LLI(42);
#define C_LLI(x) static_cast<long long int>(x)
#define NC_LLI(x) gsl::narrow_cast<long long int>(x)
// Macro to cast to short
// Description:
//   This macro is used to cast a value to short type.
// Usage example:
//   short s = C_S(42);
#define C_S(x) static_cast<short>(x)
#define NC_S(x) gsl::narrow_cast<short>(x)
// Macro to cast to short int
// Description:
//   This macro is used to cast a value to short int type.
// Usage example:
//   short int si = C_SI(42);
#define C_SI(x) static_cast<short int>(x)
#define NC_SI(x) gsl::narrow_cast<short int>(x)
// Macro to cast to unsigned char
// Description:
//   This macro is used to cast a value to unsigned char type.
// Usage example:
//   unsigned char uc = C_UC(65);
#define C_UC(x) static_cast<unsigned char>(x)
#define NC_UC(x) gsl::narrow_cast<unsigned char>(x)
// Macro to cast to unsigned int
// Description:
//   This macro is used to cast a value to unsigned int type.
// Usage example:
//   unsigned int ui = C_UI(42);
#define C_UI(x) static_cast<unsigned int>(x)
#define NC_UI(x) gsl::narrow_cast<unsigned int>(x)
// Macro to cast to unsigned long
// Description:
//   This macro is used to cast a value to unsigned long type.
// Usage example:
//   unsigned long ul = C_UL(42);
#define C_UL(x) static_cast<unsigned long>(x)
#define NC_UL(x) gsl::narrow_cast<unsigned long>(x)
// Macro to cast to unsigned long int
// Description:
//   This macro is used to cast a value to unsigned long int type.
// Usage example:
//   unsigned long int uli = C_ULI(42);
#define C_ULI(x) static_cast<unsigned long int>(x)
#define NC_ULI(x) gsl::narrow_cast<unsigned long int>(x)
// Macro to cast to unsigned long long
// Description:
//   This macro is used to cast a value to unsigned long long type.
// Usage example:
//   unsigned long long ull = C_ULL(42);
#define C_ULL(x) static_cast<unsigned long long>(x)
#define NC_ULL(x) gsl::narrow_cast<unsigned long long>(x)
// Macro to cast to unsigned long long int
// Description:
//   This macro is used to cast a value to unsigned long long int type.
// Usage example:
//   unsigned long long int ulli = C_ULLI(42);
#define C_ULLI(x) static_cast<unsigned long long int>(x)
#define NC_ULLI(x) gsl::narrow_cast<unsigned long long int>(x)
// Macro to cast to std::string
// Description:
//   This macro is used to cast a value to std::string type.
// Usage example:
//   std::string str = C_STR("Hello");
#define C_STR(x) static_cast<std::string>(x)
#define NC_STR(x) gsl::narrow_cast<std::string>(x)
// Macro to cast to std::wstring
// Description:
//   This macro is used to cast a value to std::wstring type.
// Usage example:
//   std::wstring wstr = C_WSTR(L"Hello");
#define C_WSTR(x) static_cast<std::wstring>(x)
#define NC_WSTR(x) gsl::narrow_cast<std::wstring>(x)
// Macro to cast to std::u8string
// Description:
//   This macro is used to cast a value to std::u8string type.
// Usage example:
//   std::u8string u8str = C_U8STR(u8"Hello");
#define C_U8STR(x) static_cast<std::u8string>(x)
#define NC_U8STR(x) gsl::narrow_cast<std::u8string>(x)
// Macro to cast to std::u16string
// Description:
//   This macro is used to cast a value to std::u16string type.
// Usage example:
//   std::u16string u16str = C_U16STR(u"Hello");
#define C_U16STR(x) static_cast<std::u16string>(x)
#define NC_U16STR(x) gsl::narrow_cast<std::u16string>(x)
// Macro to cast to std::u32string
// Description:
//   This macro is used to cast a value to std::u32string type.
// Usage example:
//   std::u32string u32str = C_U32STR(U"Hello");
#define C_U32STR(x) static_cast<std::u32string>(x)
#define NC_U32STR(x) gsl::narrow_cast<std::u32string>(x)
// Macro to cast to std::string_view
// Description: This macro is used to cast a value to std::string_view type.
// Usage example:
//    std::string_view strView = C_STRV("Hello, World!");
#define C_STRV(x) static_cast<std::string_view>(x)
#define NC_STRV(x) gsl::narrow_cast<std::string_view>(x)
// Macro to cast to std::wstring_view
// Description: This macro is used to cast a value to std::wstring_view type.
// Usage example:
//    std::wstring_view wstrView = C_WSTRV(L"Hello, World!");
#define C_WSTRV(x) static_cast<std::wstring_view>(x)
#define NC_WSTRV(x) gsl::narrow_cast<std::wstring_view>(x)
// Macro to cast to std::u8string_view
// Description: This macro is used to cast a value to std::u8string_view type.
/// Usage example:
//    std::u8string_view u8strView = C_U8STRV(u8"Hello, World!");
#define C_U8STRV(x) static_cast<std::u8string_view>(x)
#define NC_U8STRV(x) gsl::narrow_cast<std::u8string_view>(x)
// Macro to cast to std::u16string_view
// Description: This macro is used to cast a value to std::u16string_view type.
// Usage example:
//    std::u16string_view u16strView = C_U16STRV(u"Hello, World!");
#define C_U16STRV(x) static_cast<std::u16string_view>(x)
#define NC_U16STRV(x) gsl::narrow_cast<std::u16string_view>(x)
// Macro to cast to std::u32string_view
// Description: This macro is used to cast a value to std::u32string_view type.
// Usage example:
//    std::u32string_view u32strView = C_U32STRV(U"Hello, World!");
#define C_U32STRV(x) static_cast<std::u32string_view>(x)
#define NC_U32STRV(x) gsl::narrow_cast<std::u32string_view>(x)

#define C_ST(x) static_cast<std::size_t>(x)
#define NC_ST(x) gsl::narrow_cast<std::size_t>(x)
#define C_CPCU32T(x) static_cast<const uint32_t *>(static_cast<const void *>(x)
#define NC_CPCU32T(x) gsl::narrow_cast<const uint32_t *>(static_cast<const void *>(x))