/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include "fboss/agent/test/utils/AsicUtils.h"
#include <memory>

#include "fboss/agent/SwSwitch.h"
#include "fboss/agent/hw/switch_asics/HwAsic.h"

namespace facebook::fboss::utility {

SwitchID getFirstSwitchId(SwSwitch* sw) {
  auto switchIds = sw->getHwAsicTable()->getSwitchIDs();
  CHECK_GE(switchIds.size(), 1);
  return *switchIds.cbegin();
}

const HwAsic* getFirstAsic(SwSwitch* sw) {
  return sw->getHwAsicTable()->getHwAsic(getFirstSwitchId(sw));
}

const HwAsic* getAsic(const SwSwitch& sw, PortID port) {
  auto switchId = sw.getScopeResolver()->scope(port).switchId();
  return sw.getHwAsicTable()->getHwAsic(switchId);
}
} // namespace facebook::fboss::utility