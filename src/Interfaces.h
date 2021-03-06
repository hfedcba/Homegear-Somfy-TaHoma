/* Copyright 2013-2019 Homegear GmbH
 *
 * Homegear is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Homegear is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Homegear.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */

#ifndef INTERFACES_H_
#define INTERFACES_H_

#include <homegear-base/BaseLib.h>
#include "PhysicalInterfaces/Tahoma.h"

namespace MyFamily
{

using namespace BaseLib;

class Interfaces : public BaseLib::Systems::PhysicalInterfaces
{
public:
	Interfaces(BaseLib::SharedObjects* bl, std::map<std::string, Systems::PPhysicalInterfaceSettings> physicalInterfaceSettings);
	virtual ~Interfaces();

    void startListening() override;
    void stopListening() override;

    void addEventHandlers(BaseLib::Systems::IPhysicalInterface::IPhysicalInterfaceEventSink* central);
    void removeEventHandlers();
    std::shared_ptr<Tahoma> addInterface(Systems::PPhysicalInterfaceSettings settings, bool storeInDatabase);
    void removeUnknownInterfaces(std::set<std::string>& knownInterfaces);
    std::shared_ptr<Tahoma> getDefaultInterface();
    std::shared_ptr<Tahoma> getInterface(std::string& name);
	std::shared_ptr<Tahoma> getInterfaceByUuid(std::string& uuid);
    std::vector<std::shared_ptr<Tahoma>> getInterfaces();
protected:
	std::shared_ptr<Api> _api;
    std::shared_ptr<Tahoma> _defaultPhysicalInterface;
    std::map<std::string, PEventHandler> _physicalInterfaceEventhandlers;

	virtual void create();
};

}

#endif
