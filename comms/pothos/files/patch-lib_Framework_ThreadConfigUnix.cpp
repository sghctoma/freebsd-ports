--- lib/Framework/ThreadConfigUnix.cpp.orig	2016-06-02 19:35:04 UTC
+++ lib/Framework/ThreadConfigUnix.cpp
@@ -15,6 +15,11 @@
 #include <thread>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#endif
+
 std::string ThreadEnvironment::setPriority(const double prio)
 {
     //no negative priorities supported on this OS
@@ -44,8 +49,22 @@ std::string ThreadEnvironment::setCPUAff
 {
     #ifdef __APPLE__
     return "sched_setaffinity() not available";
-    #else
+    #elif __FreeBSD__
+    cpuset_t cpuset;
+    CPU_ZERO(&cpuset);
+    for (const auto &cpu : affinity)
+    {
+        CPU_SET(cpu, &cpuset);
+    }
+
+    std::string errorMsg;
+    if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1, sizeof(cpuset), &cpuset) == -1)
+    {
+        errorMsg = strerror(errno);
+    }
 
+	return errorMsg;
+    #else
     //create cpu bit set
     cpu_set_t *cpusetp = CPU_ALLOC(Poco::Environment::processorCount());
     if (cpusetp == nullptr) return "CPU_ALLOC";
