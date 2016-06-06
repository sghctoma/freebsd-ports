--- lib/Util/FileLockUnix.cpp.orig	2016-06-02 19:35:04 UTC
+++ lib/Util/FileLockUnix.cpp
@@ -10,6 +10,10 @@
 #include <cstring> //strerror
 #include <cerrno> //errno
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 struct Pothos::Util::FileLock::Impl
 {
     Impl(void):
