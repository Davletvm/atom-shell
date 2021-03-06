// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/common/native_mate_converters/value_converter.h"

#include "atom/common/native_mate_converters/v8_value_converter.h"
#include "base/values.h"

namespace mate {

bool Converter<base::DictionaryValue>::FromV8(v8::Isolate* isolate,
                                              v8::Handle<v8::Value> val,
                                              base::DictionaryValue* out) {
  scoped_ptr<atom::V8ValueConverter> converter(new atom::V8ValueConverter);
  scoped_ptr<base::Value> value(converter->FromV8Value(
      val, isolate->GetCurrentContext()));
  if (value && value->IsType(base::Value::TYPE_DICTIONARY)) {
    out->Swap(static_cast<base::DictionaryValue*>(value.get()));
    return true;
  } else {
    return false;
  }
}

bool Converter<base::ListValue>::FromV8(v8::Isolate* isolate,
                                        v8::Handle<v8::Value> val,
                                        base::ListValue* out) {
  scoped_ptr<atom::V8ValueConverter> converter(new atom::V8ValueConverter);
  scoped_ptr<base::Value> value(converter->FromV8Value(
      val, isolate->GetCurrentContext()));
  if (value->IsType(base::Value::TYPE_LIST)) {
    out->Swap(static_cast<base::ListValue*>(value.get()));
    return true;
  } else {
    return false;
  }
}

}  // namespace mate
