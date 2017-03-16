--- lib/Object/Convert.cpp.orig	2017-03-16 07:15:35 UTC
+++ lib/Object/Convert.cpp
@@ -134,7 +134,8 @@ static Pothos::Object convertObject(const Pothos::Obje
 
 Pothos::Object Pothos::Object::convert(const std::type_info &type) const
 {
-    if (this->type() == type) return *this; //type is the same, just copy the Object (efficient)
+	if (this->type() == type || //type is the same, just copy the Object (efficient)
+		strcmp(this->type().name(), type.name()) == 0) return *this;
     if (type == typeid(Pothos::Object)) return Pothos::Object::make(*this);
     return convertObject(*this, type);
 }
