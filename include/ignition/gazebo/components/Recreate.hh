/*
 * Copyright (C) 2021 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_COMPONENTS_RECREATE_HH_
#define IGNITION_GAZEBO_COMPONENTS_RECREATE_HH_

#include <ignition/gazebo/components/Factory.hh>
#include <ignition/gazebo/components/Component.hh>
#include <ignition/gazebo/config.hh>

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace components
{
  /// \brief A component that identifies an entity needs to be recreated.
  /// Currently, only Models will be processed for recreation by the
  /// SimulationRunner in the ProcessRecreateEntitiesRemove and
  /// ProcessRecreateEntitiesCreate functions.
  ///
  /// The GUI ModelEditor contains example code on how to use this
  /// component. For example, the ModelEditor allows a user to add a link to an
  /// existing model. The existing model is tagged with this component so
  /// that it can be recreated by the server.
  using Recreate = Component<NoData, class RecreateTag>;
  IGN_GAZEBO_REGISTER_COMPONENT("ign_gazebo_components.Recreate", Recreate)
}
}
}
}

#endif
