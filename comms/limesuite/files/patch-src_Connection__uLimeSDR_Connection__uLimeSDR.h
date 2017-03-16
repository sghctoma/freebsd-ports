--- src/Connection_uLimeSDR/Connection_uLimeSDR.h.orig	2017-03-16 14:17:49 UTC
+++ src/Connection_uLimeSDR/Connection_uLimeSDR.h
@@ -19,7 +19,11 @@
 #include "windows.h"
 #include "FTD3XXLibrary/FTD3XX.h"
 #else
+#ifdef __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include <mutex>
 #include <condition_variable>
 #include <chrono>
