/*
 * This file is part of Everking. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _INTERMEDIATE_VALUES_H
#define _INTERMEDIATE_VALUES_H

#include "MMapCommon.h"
#include "TerrainBuilder.h"

#include "Recast.h"
#include "DetourNavMesh.h"

namespace MMAP
{
    // this class gathers all debug info holding and output
    struct IntermediateValues
    {
        rcHeightfield* heightfield;
        rcCompactHeightfield* compactHeightfield;
        rcContourSet* contours;
        rcPolyMesh* polyMesh;
        rcPolyMeshDetail* polyMeshDetail;
        const char* m_workdir;

        IntermediateValues();
        IntermediateValues(const char* workdir);
        ~IntermediateValues();

        void writeIV(uint32 mapID, uint32 tileX, uint32 tileY);

        void debugWrite(FILE* file, const rcHeightfield* mesh);
        void debugWrite(FILE* file, const rcCompactHeightfield* chf);
        void debugWrite(FILE* file, const rcContourSet* cs);
        void debugWrite(FILE* file, const rcPolyMesh* mesh);
        void debugWrite(FILE* file, const rcPolyMeshDetail* mesh);

        void generateObjFile(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData);
        void generateObjFile(std::string filename, MeshData& meshData);
    };
}
#endif
