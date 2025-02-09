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

#include <vector>

#include "MapTree.h"
#include "VMapManager2.h"
#include "WorldModel.h"
#include "ModelInstance.h"

using namespace std;

namespace VMAP
{
    // Need direct access to encapsulated VMAP data, so we add functions for MMAP generator
    // maybe add MapBuilder as friend to all of the below classes would be better?

    // declared in src/shared/vmap/MapTree.h
    void StaticMapTree::getModelInstances(ModelInstance*& models, uint32& count)
    {
        models = iTreeValues;
        count = iNTreeValues;
    }

    // declared in src/shared/vmap/VMapManager2.h
    void VMapManager2::getInstanceMapTree(InstanceTreeMap& instanceMapTree)
    {
        instanceMapTree = iInstanceMapTrees;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WorldModel::getGroupModels(vector<GroupModel>& outGroupModels)
    {
        outGroupModels = groupModels;
    }

    // declared in src/shared/vmap/WorldModel.h
    void GroupModel::getMeshData(vector<Vector3>& outVertices, vector<MeshTriangle>& outTriangles, WmoLiquid*& liquid)
    {
        outVertices = vertices;
        outTriangles = triangles;
        liquid = iLiquid;
    }

    // declared in src/shared/vmap/ModelInstance.h
    WorldModel* const ModelInstance::getWorldModel()
    {
        return iModel;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WmoLiquid::getPosInfo(uint32& tilesX, uint32& tilesY, Vector3& corner) const
    {
        tilesX = iTilesX;
        tilesY = iTilesY;
        corner = iCorner;
    }
}