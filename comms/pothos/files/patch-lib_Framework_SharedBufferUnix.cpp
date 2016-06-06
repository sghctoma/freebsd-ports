--- lib/Framework/SharedBufferUnix.cpp.orig	2016-06-02 19:35:04 UTC
+++ lib/Framework/SharedBufferUnix.cpp
@@ -21,6 +21,10 @@
 #include <numa.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 /***********************************************************************
  * aligned allocator for a generic memory slab (uses new/delete)
  **********************************************************************/
