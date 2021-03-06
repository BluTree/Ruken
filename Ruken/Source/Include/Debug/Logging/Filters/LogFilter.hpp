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

#include "Debug/Logging/LogRecord.hpp"

BEGIN_RUKEN_NAMESPACE

/**
 * \brief This class provides a finer grained facility for determining which log records to output.
 * \note  Filters objects can be used by Loggers for more sophisticated filtering than is provided by levels.
 */
class __declspec(novtable) LogFilter
{
    public:

        #pragma region Constructors

        LogFilter() = default;

        LogFilter(LogFilter const& in_copy) = delete;
        LogFilter(LogFilter&&      in_move) = delete;

        virtual ~LogFilter() = default;

        #pragma endregion

        #pragma region Methods

        /**
         * \return True if the specified record is to be logged, else False.
         */
        [[nodiscard]]
        virtual RkBool Filter(LogRecord const& in_record) const = 0;

        #pragma endregion

        #pragma region Operators

        LogFilter& operator=(LogFilter const& in_copy) = delete;
        LogFilter& operator=(LogFilter&&      in_move) = delete;

        #pragma endregion
};

END_RUKEN_NAMESPACE