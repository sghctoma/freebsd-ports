--- util/shm.c.orig	2018-11-08 12:00:44 UTC
+++ util/shm.c
@@ -42,7 +42,7 @@ int allocate_shm_file(size_t size) {
 		return -1;
 	}
 
-#ifdef WLR_HAS_POSIX_FALLOCATE
+#if defined(WLR_HAS_POSIX_FALLOCATE) && !defined(__FreeBSD__)
 	int ret;
 	do {
 		ret = posix_fallocate(fd, 0, size);
