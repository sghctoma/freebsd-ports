--- comms/fft/_kiss_fft_guts.h.orig	2016-03-06 19:56:20 UTC
+++ comms/fft/_kiss_fft_guts.h
@@ -155,7 +155,9 @@ struct kiss_fft_state{
 // Temporary buffers are used in two case: 
 // 1. FFT sizes that have "bad" factors. i.e. not 2,3 and 5
 // 2. "in-place" FFTs.  Notice the quotes, since kissfft does not really do an in-place transform.
+#ifdef __FreeBSD__
 #include <alloca.h>
+#endif
 #define  KISS_FFT_TMP_ALLOC(nbytes) alloca(nbytes)
 #define  KISS_FFT_TMP_FREE(ptr) 
 #else
