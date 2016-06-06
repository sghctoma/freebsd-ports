--- include/Pothos/Object/ObjectImpl.hpp.orig	2016-06-02 19:35:04 UTC
+++ include/Pothos/Object/ObjectImpl.hpp
@@ -165,7 +165,7 @@ ValueType &ObjectContainer::extract(cons
     }
 
     //Otherwise, check the type for a match and then extract the internal value
-    if (obj._impl != nullptr and obj.type() == typeid(ValueType))
+    if (obj._impl != nullptr and strcmp(obj.type().name(), typeid(ValueType).name()) == 0)
     {
         return *(reinterpret_cast<typename ObjectContainerType<DecayValueType>::type *>(obj._impl->get()));
     }
