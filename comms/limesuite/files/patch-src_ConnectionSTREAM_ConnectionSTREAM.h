--- src/ConnectionSTREAM/ConnectionSTREAM.h.orig	2017-03-16 14:17:49 UTC
+++ src/ConnectionSTREAM/ConnectionSTREAM.h
@@ -21,7 +21,11 @@
 #include "windows.h"
 #include "CyAPI.h"
 #else
+#ifdef __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include <mutex>
 #include <condition_variable>
 #include <chrono>
