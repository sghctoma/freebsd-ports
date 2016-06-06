--- lib/Framework/BufferAccumulator.cpp.orig	2016-06-05 12:23:24 UTC
+++ lib/Framework/BufferAccumulator.cpp
@@ -172,7 +172,7 @@ void Pothos::BufferAccumulator::pop(cons
         if (fOverBounds and f.getEnd() == b.address)
         {
             b.address -= f.length;
-            b.length =+ f.length;
+            b.length += f.length;
             queue.pop_front();
         }
     }
