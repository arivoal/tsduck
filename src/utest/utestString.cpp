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
//
//  CppUnit test suite for the String class.
//
//----------------------------------------------------------------------------

#include "tsString.h"
#include "tsHexa.h"
#include "tsDecimal.h"
#include "tsFormat.h"
#include "tsToInteger.h"
#include "tsByteBlock.h"
#include "utestCppUnitTest.h"
TSDUCK_SOURCE;

//----------------------------------------------------------------------------
// The test fixture
//----------------------------------------------------------------------------

class StringTest: public CppUnit::TestFixture
{
public:
    StringTest();
    void setUp();
    void tearDown();
    void testIsSpace();
    void testUTF();
    void testTrim();

    CPPUNIT_TEST_SUITE(StringTest);
    CPPUNIT_TEST(testIsSpace);
    CPPUNIT_TEST(testUTF);
    CPPUNIT_TEST(testTrim);
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(StringTest);


//----------------------------------------------------------------------------
// Initialization.
//----------------------------------------------------------------------------

// Constructor.
StringTest::StringTest()
{
}

// Test suite initialization method.
void StringTest::setUp()
{
}

// Test suite cleanup method.
void StringTest::tearDown()
{
}


//----------------------------------------------------------------------------
// Test cases
//----------------------------------------------------------------------------

void StringTest::testIsSpace()
{
    CPPUNIT_ASSERT(ts::IsSpace(ts::SPACE));
    CPPUNIT_ASSERT(ts::IsSpace(ts::LINE_FEED));
    CPPUNIT_ASSERT(ts::IsSpace(ts::CARRIAGE_RETURN));
    CPPUNIT_ASSERT(ts::IsSpace(ts::HORIZONTAL_TABULATION));
    CPPUNIT_ASSERT(ts::IsSpace(ts::VERTICAL_TABULATION));
    CPPUNIT_ASSERT(ts::IsSpace(ts::FORM_FEED));
    CPPUNIT_ASSERT(!ts::IsSpace(ts::LATIN_CAPITAL_LETTER_A));
    CPPUNIT_ASSERT(!ts::IsSpace(ts::COLON));
    CPPUNIT_ASSERT(!ts::IsSpace(ts::CHAR_NULL));
}

void StringTest::testUTF()
{
    // Reference UTF-8 text.
    // Was entered manually in Notepad++ and separately saved in UTF-8 and UTF-16.
    static const uint8_t utf8_bytes[] = {
        0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x66, 0x6b, 0x6c,
        0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
        0x79, 0x7a, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x46,
        0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56,
        0x57, 0x58, 0x59, 0x5a, 0x0a, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x37, 0x38, 0x39, 0x2f, 0x5c, 0x2d, 0x5f, 0x3d, 0x2b, 0x28, 0x29, 0x5b,
        0x5d, 0x7b, 0x7d, 0x7e, 0x26, 0xc2, 0xb2, 0xc2, 0xb0, 0x27, 0x22, 0x23,
        0xc3, 0xa9, 0xc3, 0xa8, 0xc3, 0xaa, 0xc3, 0xa0, 0xc3, 0xa2, 0xc3, 0xb9,
        0xc3, 0xbb, 0xc3, 0xa7, 0xe2, 0x82, 0xac, 0xc3, 0xa4, 0x5e, 0xc2, 0xa8,
        0xc2, 0xa3, 0xc2, 0xa4, 0xc3, 0x89, 0xc3, 0x88, 0xc3, 0x8a, 0xc3, 0x80,
        0xc3, 0x82, 0xc3, 0x99, 0xc3, 0x9b, 0xc3, 0x87, 0xe2, 0x82, 0xac, 0xc3,
        0x84, 0x5e, 0xc2, 0xa8, 0xc2, 0xa3, 0xc2, 0xa4, 0x0a, 0xc3, 0x80, 0xc3,
        0x81, 0xc3, 0x82, 0xc3, 0x83, 0xc3, 0x84, 0xc3, 0x85, 0xc3, 0x86, 0xc3,
        0x87, 0xc3, 0x88, 0xc3, 0x89, 0xc3, 0x8a, 0xc3, 0x8b, 0xc3, 0x8c, 0xc3,
        0x8d, 0xc3, 0x8e, 0xc3, 0x8f, 0xc3, 0x90, 0xc3, 0x93, 0xc3, 0x94, 0xc3,
        0x96, 0xc3, 0x97, 0xc3, 0x98, 0xc3, 0x9c, 0xc3, 0x9d, 0xc3, 0x9e, 0xc3,
        0x9f, 0xc3, 0xa0, 0xc3, 0xa1, 0xc3, 0xa2, 0xc3, 0xa3, 0xc3, 0xa5, 0xc3,
        0xa5, 0xc3, 0xa6, 0xc3, 0xa7, 0xc3, 0xa8, 0xc3, 0xa9, 0xc3, 0xaa, 0xc3,
        0xab, 0xc3, 0xb0, 0xc3, 0xb1, 0xc3, 0xb5, 0x0a,
        // Null terminated for tests.
        0x00
    };

    // Corresponding UTF-16 values.
    static const uint16_t utf16_values[] = {
        0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069,
        0x0066, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f, 0x0070, 0x0071, 0x0072,
        0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007a, 0x0041,
        0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x0046,
        0x004b, 0x004c, 0x004d, 0x004e, 0x004f, 0x0050, 0x0051, 0x0052, 0x0053,
        0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005a, 0x000a, 0x0030,
        0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
        0x002f, 0x005c, 0x002d, 0x005f, 0x003d, 0x002b, 0x0028, 0x0029, 0x005b,
        0x005d, 0x007b, 0x007d, 0x007e, 0x0026, 0x00b2, 0x00b0, 0x0027, 0x0022,
        0x0023, 0x00e9, 0x00e8, 0x00ea, 0x00e0, 0x00e2, 0x00f9, 0x00fb, 0x00e7,
        0x20ac, 0x00e4, 0x005e, 0x00a8, 0x00a3, 0x00a4, 0x00c9, 0x00c8, 0x00ca,
        0x00c0, 0x00c2, 0x00d9, 0x00db, 0x00c7, 0x20ac, 0x00c4, 0x005e, 0x00a8,
        0x00a3, 0x00a4, 0x000a, 0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5,
        0x00c6, 0x00c7, 0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce,
        0x00cf, 0x00d0, 0x00d3, 0x00d4, 0x00d6, 0x00d7, 0x00d8, 0x00dc, 0x00dd,
        0x00de, 0x00df, 0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e5, 0x00e5, 0x00e6,
        0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00f0, 0x00f1, 0x00f5, 0x000a,
        // Null terminated for tests.
        0x0000
    };

    const size_t utf16_count = sizeof(utf16_values) / sizeof(utf16_values[0]) - 1;
    const size_t utf8_count = sizeof(utf8_bytes) / sizeof(utf8_bytes[0]) - 1;

    ts::String s1(reinterpret_cast<const ts::Char*>(utf16_values));
    ts::String s2(reinterpret_cast<const ts::Char*>(utf16_values), utf16_count);
    ts::String s3(reinterpret_cast<const char*>(utf8_bytes));
    ts::String s4(reinterpret_cast<const char*>(utf8_bytes), utf8_count);

    utest::Out() << "StringTest::testUTF: utf16_count = " << utf16_count << ", s1.length() = " << s1.length() << std::endl;

    CPPUNIT_ASSERT_EQUAL(s1.length(), s1.size());
    CPPUNIT_ASSERT_EQUAL(s2.length(), s2.size());
    CPPUNIT_ASSERT_EQUAL(s3.length(), s3.size());
    CPPUNIT_ASSERT_EQUAL(s4.length(), s4.size());

    CPPUNIT_ASSERT_EQUAL(s1.length(), utf16_count);
    CPPUNIT_ASSERT_EQUAL(s2.length(), utf16_count);
    CPPUNIT_ASSERT_EQUAL(s3.length(), utf16_count);
    CPPUNIT_ASSERT_EQUAL(s4.length(), utf16_count);

    CPPUNIT_ASSERT(s1 == s2);
    CPPUNIT_ASSERT(s1 == s3);
    CPPUNIT_ASSERT(s1 == s4);
}

void StringTest::testTrim()
{
    ts::String s;

    s = "  abc  ";
    s.trim();
    CPPUNIT_ASSERT(s == "abc");

    s = "  abc  ";
    s.trim(true, false);
    CPPUNIT_ASSERT(s == "abc  ");

    s = "  abc  ";
    s.trim(false, true);
    CPPUNIT_ASSERT(s == "  abc");

    s = "  abc  ";
    s.trim(false, false);
    CPPUNIT_ASSERT(s == "  abc  ");

    s = "abc";
    s.trim();
    CPPUNIT_ASSERT(s == "abc");

    s = "abc";
    s.trim(true, false);
    CPPUNIT_ASSERT(s == "abc");

    s = "abc";
    s.trim(false, true);
    CPPUNIT_ASSERT(s == "abc");

    s = "abc";
    s.trim(false, false);
    CPPUNIT_ASSERT(s == "abc");

    s = "  abc  ";
    CPPUNIT_ASSERT(s.trimmed() == "abc");
    CPPUNIT_ASSERT(s.trimmed(true, false) == "abc  ");
    CPPUNIT_ASSERT(s.trimmed(false, true) == "  abc");
    CPPUNIT_ASSERT(s.trimmed(false, false) == "  abc  ");

    s = "abc";
    CPPUNIT_ASSERT(s.trimmed() == "abc");
    CPPUNIT_ASSERT(s.trimmed(true, false) == "abc");
    CPPUNIT_ASSERT(s.trimmed(false, true) == "abc");
    CPPUNIT_ASSERT(s.trimmed(false, false) == "abc");
}