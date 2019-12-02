/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVELEDGER_STATE_CURRENT_RECONCILE_STATE_H_
#define BRAVELEDGER_STATE_CURRENT_RECONCILE_STATE_H_

#include <string>

#include "bat/ledger/internal/state/state_reader.h"
#include "bat/ledger/internal/state/state_writer.h"
#include "bat/ledger/internal/properties/current_reconcile_properties.h"
#include "rapidjson/writer.h"

namespace ledger {

using JsonWriter = rapidjson::Writer<rapidjson::StringBuffer>;

class CurrentReconcileState
    : public state::Reader<CurrentReconcileProperties>,
      public state::Writer<JsonWriter*, CurrentReconcileProperties> {
 public:
  CurrentReconcileState();
  ~CurrentReconcileState();

  bool FromJson(
      const std::string& json,
      CurrentReconcileProperties* properties) const override;

  bool FromDict(
      const base::DictionaryValue* dictionary,
      CurrentReconcileProperties* properties) const override;

  bool ToJson(
      JsonWriter* writer,
      const CurrentReconcileProperties& properties) const override;

  std::string ToJson(
      const CurrentReconcileProperties& properties) const override;
};

}  // namespace ledger

#endif  // BRAVELEDGER_STATE_CURRENT_RECONCILE_STATE_H_
