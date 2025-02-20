/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "FloatType.h"
#include "Model/PickResult.h"
#include "View/PickRequest.h"

namespace TrenchBroom {
namespace Renderer {
class Camera;
}

namespace View {
using ModifierKeyState = unsigned int;
namespace ModifierKeys {
static const ModifierKeyState MKNone = 0;
static const ModifierKeyState MKShift = 1 << 0;
static const ModifierKeyState MKCtrlCmd = 1 << 1; // Cmd on Mac, Ctrl on other systems
static const ModifierKeyState MKAlt = 1 << 2;
static const ModifierKeyState MKDontCare = 1 << 3;
} // namespace ModifierKeys

typedef enum {
  MK_Yes,
  MK_No,
  MK_DontCare
} ModifierKeyPressed;

using MouseButtonState = unsigned int;
namespace MouseButtons {
static const MouseButtonState MBNone = 0;
static const MouseButtonState MBLeft = 1 << 0;
static const MouseButtonState MBRight = 1 << 1;
static const MouseButtonState MBMiddle = 1 << 2;
} // namespace MouseButtons

class InputState {
private:
  ModifierKeyState m_modifierKeys;
  MouseButtonState m_mouseButtons;
  /** Mouse position in units of points, relative to top left of widget */
  float m_mouseX;
  float m_mouseY;
  float m_mouseDX;
  float m_mouseDY;
  float m_scrollX;
  float m_scrollY;

  bool m_anyToolDragging;
  PickRequest m_pickRequest;
  Model::PickResult m_pickResult;

public:
  InputState();
  InputState(const float mouseX, const float mouseY);
  virtual ~InputState();

  virtual ModifierKeyState modifierKeys() const;
  bool modifierKeysDown(ModifierKeyState keys) const;
  bool modifierKeysPressed(ModifierKeyState keys) const;
  bool checkModifierKeys(
    ModifierKeyState key1, ModifierKeyState key2 = ModifierKeys::MKDontCare,
    ModifierKeyState key3 = ModifierKeys::MKDontCare,
    ModifierKeyState key4 = ModifierKeys::MKDontCare) const;
  bool checkModifierKeys(
    ModifierKeyPressed ctrl, ModifierKeyPressed alt, ModifierKeyPressed shift) const;
  bool checkModifierKey(ModifierKeyPressed state, ModifierKeyState key) const;

  MouseButtonState mouseButtons() const;
  bool mouseButtonsDown(MouseButtonState buttons) const;
  /**
   * Checks whether only the given buttons are down (and no others).
   */
  bool mouseButtonsPressed(const MouseButtonState buttons) const;
  float mouseX() const;
  float mouseY() const;
  float mouseDX() const;
  float mouseDY() const;

  /**
   * Number of "lines" to scroll horizontally.
   */
  float scrollX() const;
  /**
   * Number of "lines" to scroll vertically.
   */
  float scrollY() const;

  void setModifierKeys(const ModifierKeyState keys);
  void clearModifierKeys();
  void mouseDown(const MouseButtonState button);
  void mouseUp(const MouseButtonState button);
  void clearMouseButtons();
  void mouseMove(const float mouseX, const float mouseY, const float mouseDX, const float mouseDY);
  void scroll(const float scrollX, const float scrollY);

  bool anyToolDragging() const;
  void setAnyToolDragging(bool anyToolDragging);

  const vm::ray3& pickRay() const;
  const vm::vec3 defaultPoint() const;
  const vm::vec3 defaultPointUnderMouse() const;
  const Renderer::Camera& camera() const;
  void setPickRequest(const PickRequest& pickRequest);

  const Model::PickResult& pickResult() const;
  void setPickResult(Model::PickResult&& pickResult);
};
} // namespace View
} // namespace TrenchBroom
