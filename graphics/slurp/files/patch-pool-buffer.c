--- pool-buffer.c.orig	2018-10-22 08:17:14 UTC
+++ pool-buffer.c
@@ -1,4 +1,4 @@
-#define _XOPEN_SOURCE 500
+#define _POSIX_C_SOURCE 200809L
 #include <cairo/cairo.h>
 #include <fcntl.h>
 #include <stdio.h>
