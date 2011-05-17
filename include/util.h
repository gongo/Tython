// -*- C++ -*-

#ifndef _TYTHON_UTIL_H_
#define _TYTHON_UTIL_H_

#define XN_OK(rc) (rc == XN_STATUS_OK)

#define CHECK_XN(rc) do {                                               \
        if (!XN_OK(rc)) {                                                \
            fprintf(stderr, "%s failed: %s\n", #rc, xnGetStatusString(rc)); \
            exit(rc);                                                   \
        }                                                               \
    } while (0)

#define DIE_IF(rc, message) do {                \
        if (rc) {                               \
            fprintf(stderr, "%s\n", message);   \
            exit(EXIT_FAILURE);                 \
        }                                       \
    } while (0)

#endif // _TYTHON_UTIL_H_
