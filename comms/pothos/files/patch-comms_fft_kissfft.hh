--- comms/fft/kissfft.hh.orig	2016-03-06 19:56:20 UTC
+++ comms/fft/kissfft.hh
@@ -3,7 +3,7 @@
 #include <complex>
 #include <vector>
 
-#ifdef HAS_ALLOCA_H
+#if defined (HAS_ALLOCA_H) && ! defined (__FreeBSD__)
 #include <alloca.h>
 #endif //HAS_ALLOCA_H
 
