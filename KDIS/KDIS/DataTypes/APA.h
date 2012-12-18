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
    class:      APA
    created:    2009/01/05
    author:     Karl Jones

    purpose:    Additional Passive Activity ( APA )
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::AdditionalPassiveParameterIndex;

class KDIS_EXPORT APA : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16APPI    : 14;
            KUINT16 m_ui16Status2 : 1;
            KUINT16 m_ui16Status1 : 1;
        };
        KUINT16 m_ui16ParamIndex;
    }m_ApaUnion;

    KINT16 m_i16Value;

public:

    static const KUINT16 APA_SIZE = 4;

    APA( void );

    APA( KDataStream & stream ) throw( KException );

    APA( AdditionalPassiveParameterIndex APPI, KBOOL Val1, KBOOL Val2, KINT16 Value );

    virtual ~APA( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetAPPI
    //              KDIS::DATA_TYPE::APA::GetAPPI
    // Description: Indicates which database record ( or file ) shall be used to describe
    //              an additional acoustic source such as transient effects, pre-launch
    //              data( i.e torpedo tube floodings ), additional sources, and the
    //              states available for each source type. This index shall be used to
    //              identify data from databases such as the Special Event Database
    //              ( SEDB )and an Additional Narrow band Database ( ANDB ).
    // Parameter:   AdditionalPassiveParameterIndex RPM, void
    //************************************
    void SetAPPI( AdditionalPassiveParameterIndex APPI );
    AdditionalPassiveParameterIndex GetAPPI() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetStatus
    //              KDIS::DATA_TYPE::APA::GetStatus
    // Description: The left most 2 bits are used to indicate
    //              on/off/change status of the record.
    //              A value of ( 1, 1 ) shall be used to indicate
    //              the record shall be activated commensurate
    //              with the conditions in the database and the following APA value
    //              field. A value of ( 0, 0 ) shall be used to indicate
    //              that the record has been deselected or turned off.
    //              A value of ( 1, 0 ) shall indicate a state change has occurred.
    //              A value of ( 0, 1 ) shall indicate the state has not
    //              changed, but the corresponding APA value field has changed.
    // Parameter:   KBOOL Val1, void
    // Parameter:   KBOOL Val2
    //************************************
    void SetStatus( KBOOL Val1, KBOOL Val2 );
    KBOOL GetStatusVal1() const;
    KBOOL GetStatusVal2() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetValue
    //              KDIS::DATA_TYPE::APA::GetValue
    // Description: Represents the value of a state change
    //              defined in the APA param index field.
    // Parameter:   KINT16 V, void
    //************************************
    void SetValue( KINT16 V );
    KINT16 GetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const APA & Value ) const;
    KBOOL operator != ( const APA & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
