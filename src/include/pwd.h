#ifndef __PWD_H__
#define __PWD_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct passwd {
    char *pw_name;
    uid_t pw_uid;
    gid_t pw_gid;
    char *pw_dir;
    char *pw_shell;
};

struct passwd *getpwnam(const char *);
struct passwd *getpwuid(uid_t);

#ifdef __cplusplus
}
#endif

#endif
