/*
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

#include "Resource/ResourceIdentifier.hpp"

USING_RUKEN_NAMESPACE

ResourceIdentifier::ResourceIdentifier(std::string const& in_name) noexcept:
    name {in_name}
{}

ResourceIdentifier::ResourceIdentifier(ResourceIdentifier const& in_copy) noexcept
{
    name = in_copy.name;
}

ResourceIdentifier::ResourceIdentifier(ResourceIdentifier&& in_move) noexcept
{
    name = std::forward<std::string>(in_move.name);
}

ResourceIdentifier::operator std::string() const noexcept
{
    return name;
}

ResourceIdentifier& ResourceIdentifier::operator=(ResourceIdentifier const& in_copy) noexcept
{
    name = in_copy.name;

    return *this;
}

ResourceIdentifier& ResourceIdentifier::operator=(ResourceIdentifier&& in_move) noexcept
{
    name = std::forward<std::string>(in_move.name);

    return *this;
}

RkBool ResourceIdentifier::operator==(ResourceIdentifier const& in_other) const noexcept
{
    return name == in_other.name;
}
