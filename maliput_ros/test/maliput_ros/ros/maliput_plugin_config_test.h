// BSD 3-Clause License
//
// Copyright (c) 2022, Woven Planet. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#pragma once

#include <memory>

#include <maliput/api/road_network.h>

#include "maliput_ros/ros/maliput_mock.h"

namespace maliput_ros {
namespace ros {
namespace test {

/// Holds the pointers to all the mocked entities in a maliput::api::RoadGeometry class.
struct RoadNetworkMockPointers {
  RoadGeometryMock* road_geometry{};
  RoadRulebookMock* road_rulebook{};
  TrafficLightBookMock* traffic_light_book{};
  IntersectionBookMock* intersection_book{};
  PhaseRingBookMock* phase_ring_book{};
  RightOfWayRuleStateProviderMock* right_of_way_state_provider{};
  PhaseProviderMock* phase_provider{};
  DiscreteValueRuleStateProviderMock* discrete_value_rule_state_provider{};
  RangeValueRuleStateProviderMock* range_value_rule_state_provider{};
};

/// Register a maliput::api::RoadNetwork.
///
/// @pre All the entities in the maliput::api::RoadNetwork are mocks.
void RegisterRoadNetworkForPlugin(std::unique_ptr<maliput::api::RoadNetwork> road_network);

/// @return A copy of the registered pointers via RegisterRoadNetworkForPlugin().
RoadNetworkMockPointers GetRoadNetworkMockPointers();

/// @return The maliput::api::RoadNetwork registered via RegisterRoadNetworkForPlugin().
std::unique_ptr<maliput::api::RoadNetwork> GetRoadNetworkForPlugin();

}  // namespace test
}  // namespace ros
}  // namespace maliput_ros
