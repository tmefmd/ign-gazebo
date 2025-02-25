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

#ifndef IGNITION_GAZEBO_GUI_MODELEDITOR_HH_
#define IGNITION_GAZEBO_GUI_MODELEDITOR_HH_

#include <memory>

#include <QtCore>

#include <ignition/gazebo/Types.hh>

namespace ignition
{
namespace gazebo
{
  class ModelEditorPrivate;

  /// \brief Model Editor
  class ModelEditor : public QObject
  {
    Q_OBJECT

    /// \brief Constructor
    public: ModelEditor();

    /// \brief Destructor
    public: ~ModelEditor();

    /// \brief Load the model editor
    public: void Load();

    /// \brief Update the model editor with data from ECM
    /// \param[in] _info Simulator update info
    /// \param[in] _ecm Reference to Entity Component Manager
    public: void Update(const UpdateInfo &_info, EntityComponentManager &_ecm);

    // Documentation inherited
    protected: bool eventFilter(QObject *_obj, QEvent *_event) override;

    /// \internal
    /// \brief Pointer to private data.
    private: std::unique_ptr<ModelEditorPrivate> dataPtr;
  };
}
}

#endif
