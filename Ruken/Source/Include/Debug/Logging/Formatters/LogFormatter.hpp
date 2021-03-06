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

#pragma once

#include <string>

#include "Debug/Logging/LogRecord.hpp"

BEGIN_RUKEN_NAMESPACE

/**
 * \brief This class configures the final order, structure, and contents of the log message.
 */
class LogFormatter
{
    protected:

        #pragma region Methods

        [[nodiscard]]
        virtual std::string ComputeLabel(LogRecord const& in_record) const noexcept;

        #pragma endregion

    public:

        #pragma region Constructors

        LogFormatter() = default;

        LogFormatter(LogFormatter const& in_copy) = delete;
        LogFormatter(LogFormatter&&      in_move) = delete;

        virtual ~LogFormatter() = default;

        #pragma endregion

        #pragma region Methods

        /**
         * \return The resulting string computed from the record.
         */
        [[nodiscard]]
        virtual std::string Format(LogRecord const& in_record) const noexcept;

        #pragma endregion

        #pragma region Operators

        LogFormatter& operator=(LogFormatter const& in_copy) = delete;
        LogFormatter& operator=(LogFormatter&&      in_move) = delete;

        #pragma endregion
};

END_RUKEN_NAMESPACE