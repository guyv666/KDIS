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

#include "./Bundle.h"

using namespace KDIS;
using namespace PDU;

//////////////////////////////////////////////////////////////////////////
// Protected:
//////////////////////////////////////////////////////////////////////////

void Bundle::calculateLength()
{
	m_ui16Length = 0;

	vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		m_ui16Length += citrObj->GetBufferSize();
	}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		m_ui16Length += ( *citrRef )->GetPDULength();
	}
}

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Bundle::Bundle( void ) : 
	m_ui16Length( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Bundle::~Bundle( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( const KDataStream & K ) throw( KException )
{
	m_vStreams.push_back( K );
	m_ui16Length += K.GetBufferSize();	
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::AddPDU( PduPtr H ) throw( KException )
{
	m_vRefHeaders.push_back( H );
	m_ui16Length += H->GetPDULength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<KDataStream> & P ) throw( KException )
{
	m_vStreams = P;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<PduPtr> & P ) throw( KException )
{
	m_vRefHeaders = P;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

void Bundle::SetPDUs( const vector<KDataStream> & Streams, const vector<PduPtr> & References ) throw( KException )
{
	m_vStreams = Streams;
	m_vRefHeaders = References;
	calculateLength();
	if( m_ui16Length > MAX_PDU_SIZE )throw KException( __FUNCTION__, PDU_TOO_LARGE );
}

//////////////////////////////////////////////////////////////////////////

const vector<KDataStream> & Bundle::GetPDUStreams() const
{
	return m_vStreams;
}

//////////////////////////////////////////////////////////////////////////

const vector<PduPtr> & Bundle::GetRefPDUs() const
{
	return m_vRefHeaders;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::ClearPDUs()
{
	m_vStreams.clear();
	m_vRefHeaders.clear();
	m_ui16Length = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Bundle::GetLength() 
{
	return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KString Bundle::GetAsString() 
{
    KStringStream ss;	
	
	ss << "***************************************************************";	
	ss << "PDU Bundle.\nTotal Length: " << m_ui16Length;
	ss << "***************************************************************";	

	// We only print the PDU, no point in printing the streams.

	//vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	//vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	//for( ; citrObj != citrObjEnd; ++citrObj )
	//{
	//	ss << citrObj->GetAsString();
	//}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		ss << ( *citrRef )->GetAsString();
	}

	ss << "***************************************************************";	

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KDataStream Bundle::Encode() const
{
    KDataStream stream;

	Bundle::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Bundle::Encode( KDataStream & stream ) const
{
	// TODO: Check for 64 bit alignment and pad

	vector<KDataStream>::const_iterator citrObj = m_vStreams.begin();
	vector<KDataStream>::const_iterator citrObjEnd = m_vStreams.end();
	for( ; citrObj != citrObjEnd; ++citrObj )
	{
		stream.CopyFromBuffer( citrObj->GetBufferPtr(), citrObj->GetBufferSize() );
	}

	vector<PduPtr>::const_iterator citrRef = m_vRefHeaders.begin();
	vector<PduPtr>::const_iterator citrRefEnd = m_vRefHeaders.end();
	for( ; citrRef != citrRefEnd; ++citrRef )
	{
		( *citrRef )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL Bundle::operator == ( const Bundle & Value ) const
{    
	if( m_vStreams    != Value.m_vStreams )    return false;
	if( m_vRefHeaders != Value.m_vRefHeaders ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Bundle::operator != ( const Bundle & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

