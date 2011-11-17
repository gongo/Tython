// -*- C++ -*-

#ifndef _TYTHON_UTIL_H_
#define _TYTHON_UTIL_H_

#include <initializer_list>
#include <stdexcept>
#include <tuple>
#include <type_traits>

namespace ty {

/**
 * XnStatus が正常値かどうかをチェックする
 *
 * @param   rc  XnStatus
 * @return      rc が正常値であれば true
 */
inline static XnBool isXnOK(XnStatus rc)
{
    return (rc == XN_STATUS_OK);
}

template <typename T>
inline void throwRuntimeErrorIf(
                std::initializer_list<T> list,
                    typename std::enable_if<
                    std::is_same<T, std::tuple<bool, const char*> >::value
                    || std::is_same<T, std::tuple<XnBool, const char*> >::value
                >::type * = 0
            )
{
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (! (bool)(std::get<0>(*it))) {
            throw std::runtime_error(std::get<1>(*it));
        }
    }
}

template <typename T>
inline void throwRuntimeErrorIf(T status,
                                typename std::enable_if<
                                  std::is_same<T, XnStatus>::value
                                >::type * = 0
                                )
{
    if (!ty::isXnOK(status)) {
        throw std::runtime_error(xnGetStatusString(status));
    }
}

template <typename T>
inline void throwRuntimeErrorIf(
                       std::initializer_list<T> list,
                       typename std::enable_if<
                         std::is_same<T, XnStatus>::value
                       >::type * = 0
                   )
{
    for (auto it = list.begin(); it != list.end(); ++it) {
        // if (!ty::isXnOK(*it)) {
        //     throw std::runtime_error(xnGetStatusString(*it));
        // }
        throwRuntimeErrorIf(*it);
    }
}

#define DIE_IF(rc, message) do {                \
        if (rc) {                               \
            fprintf(stderr, "%s\n", message);   \
            exit(EXIT_FAILURE);                 \
        }                                       \
    } while (0)

} // namespace ty

#endif // _TYTHON_UTIL_H_
