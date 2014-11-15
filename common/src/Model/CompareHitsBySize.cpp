/*
 Copyright (C) 2010-2014 Kristian Duske
 
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

#include "CompareHitsBySize.h"

#include "Model/BrushFace.h"
#include "Model/Entity.h"
#include "Model/HitAdapter.h"

namespace TrenchBroom {
    namespace Model {
        CompareHitsBySize::CompareHitsBySize(const Math::Axis::Type axis) : m_axis(axis) {}

        int CompareHitsBySize::doCompare(const Hit& lhs, const Hit& rhs) const {
            const FloatType lhsSize = getSize(lhs);
            const FloatType rhsSize = getSize(rhs);
            if (lhsSize < rhsSize)
                return -1;
            if (lhsSize > rhsSize)
                return 1;
            return m_compareByDistance.compare(lhs, rhs);
        }

        FloatType CompareHitsBySize::getSize(const Hit& hit) const {
            const BrushFace* face = hitToFace(hit);
            if (face != NULL)
                return face->area(m_axis);
            const Entity* entity = hitToEntity(hit);
            if (entity != NULL)
                return entity->area(m_axis);
            return 0.0;
        }

        Hits hitsBySize(const Math::Axis::Type axis) {
            return Hits(CompareHitsBySize(axis));
        }
    }
}
