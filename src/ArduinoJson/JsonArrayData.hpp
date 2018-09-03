// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "Data/JsonVariantData.hpp"
#include "Data/List.hpp"
#include "Memory/AllocableInMemoryPool.hpp"
#include "Polyfills/type_traits.hpp"

// Returns the size (in bytes) of an array with n elements.
// Can be very handy to determine the size of a StaticMemoryPool.
#define JSON_ARRAY_SIZE(NUMBER_OF_ELEMENTS)        \
  (sizeof(ArduinoJson::Internals::JsonArrayData) + \
   (NUMBER_OF_ELEMENTS) *                          \
       sizeof(ArduinoJson::Internals::JsonArrayData::node_type))

namespace ArduinoJson {
namespace Internals {
struct JsonArrayData : List<JsonVariantData>, AllocableInMemoryPool {
  JsonVariantData* addSlot(MemoryPool* memoryPool) {
    iterator it = add(memoryPool);
    return it != end() ? &*it : 0;
  }
};
}  // namespace Internals
}  // namespace ArduinoJson
