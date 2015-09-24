--- garminFilebasedDevice.cpp	2013-11-18 18:26:17.048473504 +0100
+++ garminFilebasedDevice.cpp	2013-11-18 18:29:05.099459806 +0100
@@ -20,7 +20,9 @@
 #include <sys/stat.h>
 #include <iostream>
 #include <fstream>
-#include "sys/statfs.h"
+#include <libgen.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <limits.h>
 #include <dirent.h>
 #include <vector>
