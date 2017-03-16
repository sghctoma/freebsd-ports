--- src/ErrorReporting.cpp.orig	2017-03-16 14:17:49 UTC
+++ src/ErrorReporting.cpp
@@ -29,7 +29,7 @@ static const char *errToStr(const int errnum)
     return buff;
     #else
     //http://linux.die.net/man/3/strerror_r
-    #if ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE) || __APPLE__
+    #if ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE) || __APPLE__ || __FreeBSD__
     strerror_r(errnum, buff, sizeof(buff));
     #else
     //this version may decide to use its own internal string
