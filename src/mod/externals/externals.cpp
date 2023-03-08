#include "exlaunch.hpp"
#include "externals/System/_Object.h"

void (*system_load_typeinfo)(long param) = reinterpret_cast<typeof(system_load_typeinfo)>(exl::util::modules::GetTargetOffset(0x00264fe0));
void* (*system_array_new)(long type, long length) = reinterpret_cast<typeof(system_array_new)>(exl::util::modules::GetTargetOffset(0x002afb00));
void* (*il2cpp_object_new)(void* klass) = reinterpret_cast<typeof(il2cpp_object_new)>(exl::util::modules::GetTargetOffset(0x00266700));
void (*il2cpp_runtime_class_init)(void* klass) = reinterpret_cast<typeof(il2cpp_runtime_class_init)>(exl::util::modules::GetTargetOffset(0x002afbe0));

