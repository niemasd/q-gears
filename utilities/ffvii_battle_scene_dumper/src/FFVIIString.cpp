#include "FFVIIString.h"


unsigned char NA = 0xD0;

unsigned char ascii[256] = {      // ASCII to FF7 conversion ( NA  = none)
    0xFF, NA , NA , NA , NA , NA , NA , NA , NA ,0xE1,0xE7, NA , NA ,0xE8, NA , NA ,
     NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA , NA ,
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
    0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,

    0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
    0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
    0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
    0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E, NA ,

     NA , NA ,0xC2,0xA4,0xC3,0xA9, NA ,0xD6, NA ,0xC4, NA ,0xBC,0xAE, NA , NA , NA ,
     NA ,0xB4,0xB5,0xB2,0xB3,0xC0,0xB0,0xB1,0x8C,0x8A, NA ,0xBD,0xAF, NA , NA ,0xB9,
    0xAA,0xA1,0x82,0x83,0xBB,0x94, NA , NA , NA ,0x89,0x9B,0xA7,0xA2, NA ,0x88, NA ,
    0x81,0x91, NA , NA ,0x8B,0x95,0x86,0xC1, NA , NA ,0x9C,0xA8, NA , NA , NA ,0xA0,

    0xAB,0x61,0xC5,0xAC,0x60, NA ,0x8E,0x62,0xC9,0x63,0xC6,0xC8,0xCD,0xCA,0xCB,0xCC,
     NA ,0x64,0xD1,0xCE,0xCF,0xAD,0x65, NA ,0x8F, NA ,0x84,0x85,0x66, NA , NA ,0x87,
    0x68,0x67,0x69,0x6B,0x6A,0x6C,0x9E,0x6D,0x6F,0x6E,0x70,0x71,0x73,0x72,0x74,0x75,
     NA ,0x76,0x78,0x77,0x79,0x7B,0x7A,0xB6,0x9F,0x7D,0x7C,0x7E,0x7F, NA , NA ,0xB8,
};



FFVIIString
StringToFFVIIString( const Ogre::String& string )
{
    FFVIIString ret;

    for( int i = 0; i < string.size(); ++i )
    {
        ret.push_back( ascii[ string[ i ] ] );
    }

    return ret;
}



Ogre::String
FFVIIStringToString( const FFVIIString& string )
{
    Ogre::String ret;

    for( int i = 0; i < string.size(); ++i )
    {
        Ogre::String l = "";

        for( int j = 0; j < 256; ++j )
        {
            if( ascii[ j ] == string[ i ] )
            {
                l = j;
            }
        }

        ret += l;
    }

    return ret;
}
