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

#include "TagVisitor.h"

namespace TrenchBroom {
namespace Model {
TagVisitor::~TagVisitor() = default;
void TagVisitor::visit(WorldNode&) {}
void TagVisitor::visit(LayerNode&) {}
void TagVisitor::visit(GroupNode&) {}
void TagVisitor::visit(EntityNode&) {}
void TagVisitor::visit(BrushNode&) {}
void TagVisitor::visit(BrushFace&) {}
void TagVisitor::visit(PatchNode&) {}

ConstTagVisitor::~ConstTagVisitor() = default;
void ConstTagVisitor::visit(const WorldNode&) {}
void ConstTagVisitor::visit(const LayerNode&) {}
void ConstTagVisitor::visit(const GroupNode&) {}
void ConstTagVisitor::visit(const EntityNode&) {}
void ConstTagVisitor::visit(const BrushNode&) {}
void ConstTagVisitor::visit(const BrushFace&) {}
void ConstTagVisitor::visit(const PatchNode&) {}
} // namespace Model
} // namespace TrenchBroom
