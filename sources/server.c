#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <shadow.h>
#include <crypt.h>
#include <stdlib.h>

#define BUFF_SIZE 2000
#define CHK_SSL(err)        \
if ((err) < 1) {            \
ERR_print_errors_fp(stderr);\
exit(2);                    \
}

#define CHK_ERR(err,s)      \
if ((err)==-1) {            \
perror(s);                  \
exit(1);                    \
}

