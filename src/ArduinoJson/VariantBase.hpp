// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "VariantCasts.hpp"
#include "VariantComparisons.hpp"
#include "VariantOr.hpp"
#include "VariantSubscripts.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename TImpl>
class VariantBase : public VariantCasts<TImpl>,
                    public VariantComparisons<TImpl>,
                    public VariantOr<TImpl>,
                    public VariantSubscripts<TImpl> {};
}  // namespace ARDUINOJSON_NAMESPACE
