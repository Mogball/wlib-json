#ifndef __WLIB_JSON_JSONTYPE_H__
#define __WLIB_JSON_JSONTYPE_H__

#include <wlib/string>
#include <wlib/utility>

#define TYPE_DECL(type_v, type_t)               \
template<>                                      \
struct type_of<type_v> {                        \
    typedef type_t type;                        \
};                                              \
template<>                                      \
struct type_info<type_t> {                      \
    static constexpr json_type value = type_v;  \
};

namespace wlp {

    enum json_type {
        TYPE_NULL,
        TYPE_BOOL,
        TYPE_CHAR,
        TYPE_SIGNED_CHAR,
        TYPE_SIGNED_SHORT,
        TYPE_SIGNED_INT,
        TYPE_SIGNED_LONG,
        TYPE_SIGNED_LONG_LONG,
        TYPE_UNSIGNED_CHAR,
        TYPE_UNSIGNED_SHORT,
        TYPE_UNSIGNED_INT,
        TYPE_UNSIGNED_LONG,
        TYPE_UNSIGNED_LONG_LONG,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_LONG_DOUBLE,
        TYPE_JSON_STRING,
        TYPE_JSON_ARRAY,
        TYPE_JSON_OBJECT
    };

    template<json_type type>
    struct type_of;

    template<typename type>
    struct type_info;
    
    TYPE_DECL(TYPE_NULL, nullptr_t)
    TYPE_DECL(TYPE_BOOL, bool)
    TYPE_DECL(TYPE_CHAR, char)
    TYPE_DECL(TYPE_SIGNED_CHAR, signed char)
    TYPE_DECL(TYPE_SIGNED_SHORT, signed short)
    TYPE_DECL(TYPE_SIGNED_INT, signed int)
    TYPE_DECL(TYPE_SIGNED_LONG, signed long)
    TYPE_DECL(TYPE_SIGNED_LONG_LONG, signed long long)
    TYPE_DECL(TYPE_UNSIGNED_CHAR, unsigned char)
    TYPE_DECL(TYPE_UNSIGNED_SHORT, unsigned short)
    TYPE_DECL(TYPE_UNSIGNED_INT, unsigned int)
    TYPE_DECL(TYPE_UNSIGNED_LONG, unsigned long)
    TYPE_DECL(TYPE_UNSIGNED_LONG_LONG, unsigned long long)
    TYPE_DECL(TYPE_FLOAT, float)
    TYPE_DECL(TYPE_DOUBLE, double)
    TYPE_DECL(TYPE_LONG_DOUBLE, long double)
    TYPE_DECL(TYPE_JSON_STRING, char *)
    TYPE_DECL(TYPE_JSON_ARRAY, short *)
    TYPE_DECL(TYPE_JSON_OBJECT, int *)

    template<bool cond, typename target_t = void>
    struct enable_type_if {};

    template<typename target_t>
    struct enable_type_if<true, target_t> {
        typedef target_t type;
    };

    template<typename target_t>
    constexpr bool is_string_type() {
        return 
            is_same<char *, target_t>::value ||
            is_same<const char *, target_t>::value ||
            is_same<dynamic_string, target_t>::value;
    }

}

#endif
