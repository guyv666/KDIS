/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    KDefines
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Defines some of the core data types that KDIS uses.                
*********************************************************************/

#pragma once

#include "./KSymbolicNames.h"
#include <cstring> // memset
#include <string>
#include <sstream>
#include <exception>

#define KDIS_VERSION "v2-6-0"

#define MAX_PDU_SIZE MAX_PDU_SIZE_OCTETS 

// Comment out the following line to enable Enum descriptors or declare KDIS_USE_ENUM_DESCRIPTORS
// in your project pre-processor definitions (-D KDIS_USE_ENUM_DESCRIPTORS).
//#define KDIS_USE_ENUM_DESCRIPTORS

#if defined( WIN32 ) | defined( WIN64 )
// Disable this warning, it simply warns us about any functions that have a throw qualifier.
#pragma warning( disable : 4290 )

// Warning about conversion from size_t
#pragma warning( disable : 4267 )

// Safe to ignore this error as we are only exporting STL objects
#pragma warning( disable : 4251 )
#endif

/************************************************************************/
/*  Export Options                                                      */
/************************************************************************/

#ifdef EXPORT_KDIS
	#ifdef IMPORT_KDIS
		#pragma error( "IMPORT_KDIS & EXPORT_KDIS Can Not Be Both Defined" )
	#endif
#endif

#if defined( WIN32 ) | defined( WIN64 )
	#if defined EXPORT_KDIS
		#define KDIS_EXPORT __declspec( dllexport )
	#elif defined IMPORT_KDIS
		#define KDIS_EXPORT __declspec( dllimport  )
	#else
		#define KDIS_EXPORT
	#endif
#else
	#define KDIS_EXPORT
#endif

// Used when we include both DIS 5, 6, or 7 PDUs in a component, such as the PDU_Factory.
// We can use this to know what PDUs we should allow use off and what features.
// E.G DIS version 7 uses some of the headers padding to add an extra field.
#ifndef DIS_VERSION
	#pragma message("No DIS version specified, defaulting to 6. If you wish to use 5 define 'DIS_VERSION 5' in your project. You may also define DIS version 7 for the draft 15 standard.")
	#define DIS_VERSION 6
#endif

/************************************************************************/
/* Type Definitions                                                     */
/************************************************************************/

namespace KDIS {

typedef unsigned char KUINT8;
typedef char KINT8;
typedef unsigned short int KUINT16;
typedef short int KINT16;
typedef unsigned int KUINT32;
typedef int KINT32;
typedef unsigned long long KUINT64;
typedef long long KINT64;

typedef char KOCTET;
typedef unsigned char KUOCTET;
typedef char KCHAR8;
typedef unsigned char KUCHAR8;

typedef float KFLOAT32;
typedef double KFLOAT64;

typedef std::string KString;
typedef std::stringstream KStringStream;

typedef bool KBOOL;

/************************************************************************/
/* Error Code Definitions                                               */
/************************************************************************/

enum ErrorCodes
{
    NO_ERRORS                                           = 0,
    BUFFER_TOO_SMALL                                    = 1,
    NOT_ENOUGH_DATA_IN_BUFFER                           = 2,
    STRING_PDU_SIZE_TOO_BIG                             = 3,
    DATA_TYPE_TOO_LARGE                                 = 4,
    WRONG_PDU_TYPE_IN_HEADER                            = 5,
    FILE_NOT_OPEN                                       = 6,
    OUT_OF_BOUNDS                                       = 7,
    INVALID_DATA                                        = 8,
    UNSUPPORTED_DATATYPE                                = 9,
    INVALID_OPERATION                                   = 10,
	PDU_TOO_LARGE                                       = 11
};

/************************************************************************/
/* Error Code As String                                                 */
/************************************************************************/

static KString GetErrorText( KUINT16 ErrorCode )
{
    switch( ErrorCode )
    {
		case NO_ERRORS:
			return "No Errors. ";
		case BUFFER_TOO_SMALL:
			return "Buffer Is To Small. ";
		case NOT_ENOUGH_DATA_IN_BUFFER:
			return "Buffer Does Not Contain Enough Information To Decode. ";
		case STRING_PDU_SIZE_TOO_BIG:
			return "String Size Too Big. ";
		case DATA_TYPE_TOO_LARGE:
			return "Data Type Is Too Large. ";
		case WRONG_PDU_TYPE_IN_HEADER:
			return "Incorrect PDU Type Specified In Header. ";
		case FILE_NOT_OPEN:
			return "Could Not Open File For Reading/Writing. ";
		case OUT_OF_BOUNDS:
			return "Parameter Is Out Of Bounds/Range Of Acceptable Values. ";
		case INVALID_DATA:
			return "Invalid Data. ";
		case UNSUPPORTED_DATATYPE:
			return "Unsupported Data Type, Can Not Decode. ";
		case INVALID_OPERATION:
			return "Invalid Operation. ";
		case PDU_TOO_LARGE:
			return "PDU Is Too Large. PDU Must Not Exceed 8192 Bytes.";			
		default:
			return "Unknown KDIS Error. ";
    }
};

/************************************************************************/
/* Exception                                                            */
/************************************************************************/

class KException : public std::exception
{
public:

    KUINT16 m_ui16ErrorCode;
    KString m_sErrorText;

    KException( KUINT16 EC ) :
        m_ui16ErrorCode( EC ),
        m_sErrorText( GetErrorText( EC ) )
    {
    };

    KException( KString Text, KUINT16 EC ) :
        m_ui16ErrorCode( EC ),
        m_sErrorText( Text + ": " + GetErrorText( EC ) )
    {
    };

    template<class T>
    KException( KString Text, KUINT16 EC, T AdditonalInfo ) :
        m_ui16ErrorCode( EC ),
        m_sErrorText( Text + ": " + GetErrorText( EC ) )
    {
        KStringStream ss;
        ss << m_sErrorText << AdditonalInfo;
        m_sErrorText = ss.str();
    };

    virtual ~KException( void ) throw()
    {
    };

    virtual const KCHAR8 *  what() const throw()
    {
        return m_sErrorText.c_str();
    };
};

/************************************************************************/
/* Endian                                                               */
/************************************************************************/

enum Endian
{
    Little_Endian  = 0,
    Big_Endian     = 1
};

}; // END namespace KDIS










