/*
 * Copyright (C) 2019 Open Source Robotics Foundation
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
#ifndef IGNITION_GAZEBO_GUI_GUIRUNNER_HH_
#define IGNITION_GAZEBO_GUI_GUIRUNNER_HH_

#include <ignition/msgs/serialized_map.pb.h>

#include <QtCore>
#include <string>

#include <ignition/utils/ImplPtr.hh>

#include "ignition/gazebo/config.hh"
#include "ignition/gazebo/EventManager.hh"
#include "ignition/gazebo/gui/Export.hh"

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
/// \brief Responsible for running GUI systems as new states are received from
/// the backend.
class IGNITION_GAZEBO_GUI_VISIBLE GuiRunner : public QObject
{
  Q_OBJECT

  /// \brief Constructor
  /// \param[in] _worldName World name.
  public: explicit GuiRunner(const std::string &_worldName);

  /// \brief Destructor
  public: ~GuiRunner() override;

  /// \brief Get the event manager for the gui
  public: EventManager &GuiEventManager() const;

  // Documentation inherited
  protected: bool eventFilter(QObject *_obj, QEvent *_event) override;

  /// \brief Callback when a plugin has been added.
  /// This function has no effect and is left here for ABI compatibility.
  /// \param[in] _objectName Plugin's object name.
  public slots: void OnPluginAdded(const QString &_objectName);

  /// \brief Make a new state request to the server.
  public slots: void RequestState();

  /// \brief Callback for the async state service.
  /// \param[in] _res Response containing new state.
  private: void OnStateAsyncService(const msgs::SerializedStepMap &_res);

  /// \brief Callback when a new state is received from the server. Actual
  /// updating of the ECM is delegated to OnStateQt
  /// \param[in] _msg New state message.
  private: void OnState(const msgs::SerializedStepMap &_msg);

  /// \brief Called by the Qt thread to update the ECM with new state
  /// \param[in] _msg New state message.
  private: Q_INVOKABLE void OnStateQt(const msgs::SerializedStepMap &_msg);

  /// \brief Update the plugins.
  /// \todo(anyone) Move to GuiRunner::Implementation when porting to v5
  private: Q_INVOKABLE void UpdatePlugins();

  /// \brief Load systems
  private: void LoadSystems();

  /// \brief Update systems
  private: void UpdateSystems();

  /// \brief Pointer to private data.
  IGN_UTILS_UNIQUE_IMPL_PTR(dataPtr)
};
}
}
}
#endif
