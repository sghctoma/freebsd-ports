--- deviceManager.cpp	2013-11-18 18:26:17.052474333 +0100
+++ deviceManager.cpp	2013-11-18 18:31:54.591446798 +0100
@@ -20,7 +20,7 @@

 #include "deviceManager.h"
 #include "log.h"
-#include <mntent.h>
+#include <fstab.h>
 #include <dirent.h>
 #include "garminFilebasedDevice.h"

@@ -160,15 +160,13 @@
     }

     if (scanMounted) {
-        FILE *mounts = NULL;
-        struct mntent *ent = NULL;
-        mounts = setmntent("/etc/mtab", "r");
-
-        Log::dbg("Searching for Edge705/Oregon300/...");
-        while ( (ent = getmntent(mounts)) != NULL ) {
-            string filesystype = ent->mnt_type;
-            string mountPath = ent->mnt_dir;
-            if (filesystype.compare("vfat") == 0) {
+	struct fstab *pfstab = NULL;
+	setfsent();
+
+	while (((pfstab = getfsent()) != NULL)) {
+	    string filesystype = pfstab->fs_vfstype;
+	    string mountPath = pfstab->fs_file;
+	    if (filesystype.compare("msdosfs") == 0) {
                 Log::dbg("Searching on ["+mountPath+"] ["+filesystype+"]");
                 GpsDevice *dev = createGarminDeviceFromPath(mountPath, NULL);
                 if (dev != NULL) {
@@ -179,6 +177,9 @@
                 Log::dbg("Not searching on ["+mountPath+"] ["+filesystype+"] - wrong fstype.");
             }
         }
+
+	endfsent();
+
     } else {
         Log::dbg("Scanning for mounted devices is disabled!");
     }
