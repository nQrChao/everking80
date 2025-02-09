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

#ifndef MANGOSSERVER_GAMEOBJECTMODEL_VMAPS_H
#define MANGOSSERVER_GAMEOBJECTMODEL_VMAPS_H

#include <stdio.h>
#include "Platform/Define.h"
#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <string>
#include <unordered_map>
#include <map>

struct TileBuilding;
struct GameobjectModelData;

typedef std::unordered_map<uint32, GameobjectModelData> ModelList;

struct GameobjectModelData
{
    GameobjectModelData(const std::string& name_, const G3D::AABox& box) :
        name(name_), bound(box) {}

    std::string name;
    G3D::AABox bound;

    static ModelList LoadGameObjectModelList(std::string fileName);
    static std::tuple<std::vector<TileBuilding const*>, std::map<uint32, std::vector<TileBuilding const*>>, std::map<uint32, std::vector<TileBuilding const*>>, std::map<uint32, uint32>> GetTileBuildingData(uint32 mapId, uint32 tileX, uint32 tileY, ModelList& modelList);
    static std::tuple<uint32, uint32, uint32, uint32> CalculateBuildingTiles(TileBuilding const& building, G3D::AABox mdl_box);
};

#endif