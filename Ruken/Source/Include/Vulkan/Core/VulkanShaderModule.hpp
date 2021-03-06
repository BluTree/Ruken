﻿/*
 *  MIT License
 *
 *  Copyright (c) 2019-2020 Basile Combet, Philippe Yi
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#pragma once

#include <vector>

#include "Vulkan/Utilities/VulkanConfig.hpp"

BEGIN_RUKEN_NAMESPACE

/**
 * \brief RAII-class wrapping a 'VkShaderModule' object.
 *        Shader modules contain shader code and one or more entry points.
 *        Shaders are selected from a shader module by specifying an entry point as part of pipeline creation.
 *        The stages of a pipeline can use shaders that come from different modules.
 *        The shader code defining a shader module must be in the SPIR-V format.
 */
class VulkanShaderModule
{
    private:

        #pragma region Members

        VkShaderModule m_handle {nullptr};

        #pragma endregion

    public:

        #pragma region Constructors

        explicit VulkanShaderModule(std::vector<RkUint32> const& in_code) noexcept;

        VulkanShaderModule(VulkanShaderModule const& in_copy) = delete;
        VulkanShaderModule(VulkanShaderModule&&      in_move) noexcept;

        ~VulkanShaderModule() noexcept;

        #pragma endregion

        #pragma region Methods

        [[nodiscard]] RkBool               IsValid  () const noexcept;
        [[nodiscard]] VkShaderModule const& GetHandle() const noexcept;

        #pragma endregion

        #pragma region Operators

        VulkanShaderModule& operator=(VulkanShaderModule const& in_copy) = delete;
        VulkanShaderModule& operator=(VulkanShaderModule&&      in_move) noexcept;

        #pragma endregion
};

END_RUKEN_NAMESPACE