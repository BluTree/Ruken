/*
 *  MIT License
 *
 *  Copyright (c) 2019 Basile Combet, Philippe Yi
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

#include "StreamHandler.hpp"

BEGIN_DAEMON_NAMESPACE

/**
 * \brief This class, located in the core logging package, sends logging output to a disk file.
 *
 * \note It inherits the output functionality from StreamHandler.
 */
class FileHandler final : public StreamHandler
{
    protected:

        #pragma region Members

        String m_path;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Outputs the record to the file.
         *
         * \param in_record The record to emit.
         */
        DAEvoid Emit(LogRecord const& in_record) override;

        #pragma endregion

    public:

        #pragma region Contructors and Destructor

        explicit FileHandler(String const& in_path, std::ios::openmode in_mode, ELogLevel in_level = ELogLevel::NotSet) noexcept;

        FileHandler(FileHandler const&  in_copy) = delete;
        FileHandler(FileHandler&&       in_move) = delete;

        ~FileHandler() noexcept;

        #pragma endregion

        #pragma region Operators

        FileHandler& operator=(FileHandler const& in_other) = delete;
        FileHandler& operator=(FileHandler&&      in_other) = delete;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Closes the file.
         */
        DAEvoid Close() override;

        #pragma endregion
};

END_DAEMON_NAMESPACE