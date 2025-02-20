/*
 Copyright (C) 2021 Amara M. Kilic
 Copyright (C) 2021 Kristian Duske

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

#include "IO/Path.h"

#include <kdl/reflection_decl.h>

#include <variant>

namespace TrenchBroom {
namespace IO {
struct MapExportOptions {
  Path exportPath;

  kdl_reflect_decl(MapExportOptions, exportPath);
};

enum class ObjMtlPathMode {
  RelativeToGamePath,
  RelativeToExportPath
};

std::ostream& operator<<(std::ostream& lhs, ObjMtlPathMode rhs);

struct ObjExportOptions {
  Path exportPath;
  ObjMtlPathMode mtlPathMode;

  kdl_reflect_decl(ObjExportOptions, exportPath, mtlPathMode);
};

using ExportOptions = std::variant<MapExportOptions, ObjExportOptions>;

std::ostream& operator<<(std::ostream& lhs, const ExportOptions& rhs);
} // namespace IO
} // namespace TrenchBroom
