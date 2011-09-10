// -*- C++ -*-

#ifndef _TYTHON_UTIL_H_
#define _TYTHON_UTIL_H_

#include <stdexcept>

namespace ty {

/**
 * XnStatus が正常値かどうかをチェックする
 *
 * @param   rc  XnStatus
 * @return      rc が正常値であれば true
 */
inline static bool xnCheck(XnStatus rc)
{
    return (rc == XN_STATUS_OK);
}

/**
 * XnStatus が異常値の場合、runtime_error を throw する

 * @param  rc                  XnStatus
 * @throw  std::runtime_error  rc is failure status code
 */
inline static void xnRuntimeCheck(XnStatus rc)
{
    if (!ty::xnCheck(rc)) {
        throw std::runtime_error(xnGetStatusString(rc));
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
