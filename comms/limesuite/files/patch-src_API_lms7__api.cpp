--- src/API/lms7_api.cpp.orig	2017-03-16 14:17:49 UTC
+++ src/API/lms7_api.cpp
@@ -1118,12 +1118,12 @@ API_EXPORT int CALL_CONV LMS_GetNormalizedGain(lms_dev
     }
 
     *gain = lms->GetNormalizedGain(dir_tx,chan);
-    if (gain < 0)
+    if (*gain < 0)
         return -1;
     return LMS_SUCCESS;
 }
 
-API_EXPORT int CALL_CONV LMS_GetGaindB(lms_device_t *device, bool dir_tx, size_t chan, unsigned *gain)
+API_EXPORT int CALL_CONV LMS_GetGaindB(lms_device_t *device, bool dir_tx, size_t chan, int *gain)
 {
     if (device == nullptr)
     {
@@ -1140,7 +1140,7 @@ API_EXPORT int CALL_CONV LMS_GetGaindB(lms_device_t *d
     }
 
     *gain = lms->GetGain(dir_tx,chan);
-    if (gain < 0)
+    if (*gain < 0)
         return -1;
     return LMS_SUCCESS;
 }
