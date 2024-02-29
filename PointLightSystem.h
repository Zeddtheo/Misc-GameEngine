#pragma once

#include "GameCamera.h"
#include "GameDevice.h"
#include "FrameInfo.h"
#include "GameObject.h"
#include "GamePipeline.h"

// std
#include <memory>
#include <vector>

namespace misc {
    class PointLightSystem {
    public:
        PointLightSystem(
            GameDevice& device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
        ~PointLightSystem();

        PointLightSystem(const PointLightSystem&) = delete;
        PointLightSystem& operator=(const PointLightSystem&) = delete;

        void update(FrameInfo& frameInfo, GlobalUbo& ubo);
        void render(FrameInfo& frameInfo);

    private:
        void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
        void createPipeline(VkRenderPass renderPass);

        GameDevice& myDevice;

        std::unique_ptr<GamePipeline> myPipeline;
        VkPipelineLayout pipelineLayout;
    };
}  // namespace misc

