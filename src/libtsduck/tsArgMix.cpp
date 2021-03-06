//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2017, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#include "tsArgMix.h"
#include "tsUString.h"
TSDUCK_SOURCE;

const std::string ts::ArgMix::empty;
const ts::UString ts::ArgMix::uempty;


//----------------------------------------------------------------------------
// Return ArgMix value as a string.
//----------------------------------------------------------------------------

const char* ts::ArgMix::toCharPtr() const
{
    switch (_type) {
        case STRING | BIT8 | CLASS:  return _value.string == 0 ? "" : _value.string->c_str();
        case STRING | BIT8: return _value.charptr == 0 ? "" : _value.charptr;
        default: return "";
    }
}

const ts::UChar* ts::ArgMix::toUCharPtr() const
{
    switch (_type) {
        case STRING | BIT16 | CLASS:  return _value.ustring == 0 ? u"" : _value.ustring->c_str();
        case STRING | BIT16: return _value.ucharptr == 0 ? u"" : _value.ucharptr;
        default: return u"";
    }
}

const std::string& ts::ArgMix::toString() const
{
    return _type == (STRING | BIT8 | CLASS) && _value.string != 0 ? *_value.string : empty;
}

const ts::UString& ts::ArgMix::toUString() const
{
    return _type == (STRING | BIT16 | CLASS) && _value.ustring != 0 ? *_value.ustring : uempty;
}
