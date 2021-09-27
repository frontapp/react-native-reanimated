#pragma once

#include <jsi/jsi.h>
#include <string>
#include "HostFunctionHandler.h"
#include "JSIStoreValueUser.h"
#include "SharedParent.h"
#include "WorkletsCache.h"

#include <react/renderer/uimanager/primitives.h> // ShadowNodeWrapper

using namespace facebook::react;

namespace reanimated {

class HostFunctionWrapper;

class ValueWrapper {
 public:
  ValueWrapper(){};
  ValueWrapper(ValueType _type) : type(_type){};
  ValueType getType() const {
    return type;
  }

  virtual ~ValueWrapper() {}

  static inline bool asBoolean(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline double asNumber(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::string &asString(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::shared_ptr<HostFunctionHandler> &asHostFunction(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::shared_ptr<FrozenObject> &asFrozenObject(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::shared_ptr<RemoteObject> &asRemoteObject(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline std::vector<std::shared_ptr<ShareableValue>> &asFrozenArray(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::shared_ptr<MutableValue> &asMutableValue(
      const std::unique_ptr<ValueWrapper> &valueContainer);
  static inline const std::shared_ptr<ShadowNodeWrapper> &asShadowNodeWrapper(
      const std::unique_ptr<ValueWrapper> &valueContainer);

  static const HostFunctionWrapper *asHostFunctionWrapper(
      const std::unique_ptr<ValueWrapper> &valueContainer);

 protected:
  ValueType type;
};

class BooleanValueWrapper : public ValueWrapper {
 public:
  BooleanValueWrapper(const bool _value)
      : ValueWrapper(ValueType::BoolType), value(_value){};
  bool value;
};

class NumberValueWrapper : public ValueWrapper {
 public:
  NumberValueWrapper(const double _value)
      : ValueWrapper(ValueType::NumberType), value(_value){};
  double value;
};

class StringValueWrapper : public ValueWrapper {
 public:
  StringValueWrapper(const std::string &_value)
      : ValueWrapper(ValueType::StringType), value(_value){};
  std::string value;
};

class HostFunctionWrapper : public ValueWrapper {
 public:
  HostFunctionWrapper(const std::shared_ptr<HostFunctionHandler> &_value)
      : ValueWrapper(ValueType::HostFunctionType), value(_value){};
  std::shared_ptr<HostFunctionHandler> value;
};

class FrozenObjectWrapper : public ValueWrapper {
 public:
  FrozenObjectWrapper(const std::shared_ptr<FrozenObject> &_value)
      : ValueWrapper(ValueType::FrozenObjectType), value(_value){};
  std::shared_ptr<FrozenObject> value;
};

class RemoteObjectWrapper : public ValueWrapper {
 public:
  RemoteObjectWrapper(const std::shared_ptr<RemoteObject> &_value)
      : ValueWrapper(ValueType::RemoteObjectType), value(_value){};
  std::shared_ptr<RemoteObject> value;
};

class FrozenArrayWrapper : public ValueWrapper {
 public:
  FrozenArrayWrapper() : ValueWrapper(ValueType::FrozenArrayType){};
  FrozenArrayWrapper(const std::vector<std::shared_ptr<ShareableValue>> &_value)
      : ValueWrapper(ValueType::FrozenArrayType), value(_value){};
  std::vector<std::shared_ptr<ShareableValue>> value;
};

class MutableValueWrapper : public ValueWrapper {
 public:
  MutableValueWrapper(const std::shared_ptr<MutableValue> &_value)
      : ValueWrapper(ValueType::MutableValueType), value(_value){};
  std::shared_ptr<MutableValue> value;
};

class ShadowNodeWrapperWrapper : public ValueWrapper {
 public:
    ShadowNodeWrapperWrapper(const std::shared_ptr<ShadowNodeWrapper> &_value)
      : ValueWrapper(ValueType::ShadowNodeWrapperType), value(_value){};
  std::shared_ptr<ShadowNodeWrapper> value;
};

inline bool ValueWrapper::asBoolean(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<BooleanValueWrapper *>(valueContainer.get())->value;
};

inline double ValueWrapper::asNumber(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<NumberValueWrapper *>(valueContainer.get())->value;
};

inline const std::string &ValueWrapper::asString(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<StringValueWrapper *>(valueContainer.get())->value;
};

inline const std::shared_ptr<HostFunctionHandler> &ValueWrapper::asHostFunction(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<HostFunctionWrapper *>(valueContainer.get())->value;
};

inline const std::shared_ptr<FrozenObject> &ValueWrapper::asFrozenObject(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<FrozenObjectWrapper *>(valueContainer.get())->value;
};

inline const std::shared_ptr<RemoteObject> &ValueWrapper::asRemoteObject(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<RemoteObjectWrapper *>(valueContainer.get())->value;
};

inline std::vector<std::shared_ptr<ShareableValue>>
    &ValueWrapper::asFrozenArray(
        const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<FrozenArrayWrapper *>(valueContainer.get())->value;
};

inline const std::shared_ptr<MutableValue> &ValueWrapper::asMutableValue(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<MutableValueWrapper *>(valueContainer.get())->value;
};

inline const std::shared_ptr<ShadowNodeWrapper> &ValueWrapper::asShadowNodeWrapper(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<ShadowNodeWrapperWrapper *>(valueContainer.get())->value;
};

inline const HostFunctionWrapper *ValueWrapper::asHostFunctionWrapper(
    const std::unique_ptr<ValueWrapper> &valueContainer) {
  return static_cast<HostFunctionWrapper *>(valueContainer.get());
};

} // namespace reanimated