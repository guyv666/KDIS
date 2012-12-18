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
    EnumRadio
    created:    21/08/2008
    author:     Karl Jones

    purpose:    Enums for radio parameters
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* Transmit State                                                       */
/* Radio Tranmit State                                                  */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum TransmitState
{
    Off                                                               = 0,
    OnButNotTransmitting                                              = 1,
    OnAndTransmitting                                                 = 2
};

KString GetEnumAsStringTransmitState( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTransmitState( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Radio Input Source                                                   */
/* Radio in put source, represents the part of the entity that is       */
/* transmitting.                                                        */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum RadioInputSource
{
    OtherRadioInputSource                                             = 0,
    Pilot                                                             = 1,
    Copilot                                                           = 2,
    FirstOfficer                                                      = 3,
    Driver                                                            = 4,
    Loader                                                            = 5,
    Gunner                                                            = 6,
    Commander                                                         = 7,
    DigitalDataDevice                                                 = 8,
    Intercom                                                          = 9
};

KString GetEnumAsStringRadioInputSource( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRadioInputSource( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Antenna Pattern Type                                                 */
/* Type of representation used for radiation pattern from antenna       */
/* transmitting.                                                        */
/* Used In:                                                             */
/*  Tranmitter PDU                                                      */
/************************************************************************/

enum AntennaPatternType
{
    Omni_Directional                                                  = 0,
    Beam                                                              = 1,
    SphericalHarmonic                                                 = 2
};

KString GetEnumAsStringAntennaPatternType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAntennaPatternType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Radio Major Modulation                                               */
/* Major Modulation Field                                               */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum RadioMajorModulation
{
    OtherRadioMajorModulation                                         = 0,
    Amplitude                                                         = 1,
    AmplitudeAndAngle                                                 = 2,
    Angle                                                             = 3,
    Combination                                                       = 4,
    Pulse                                                             = 5,
    Unmodulated                                                       = 6,
    CarrierPhaseShiftModulation_CPSM                                  = 7
};

KString GetEnumAsStringRadioMajorModulation( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRadioMajorModulation( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Modulation Detail                                                    */
/* Various Enums dependent on Radio Major Modulation                    */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum DetailAmplitude
{
    OtherDetailAmplitude                                              = 0,
    AFSK_AudioFrequencyShiftKeying                                    = 1,
    AM_AmplitudeModulation                                            = 2,
    CW_ContinuousWaveModulation                                       = 3,
    DSB_DoubleSideband                                                = 4,
    ISB_IndependentSideband                                           = 5,
    LSB_SingleBandSuppressedCarrier_LowerSidebandMode                 = 6,
    SSB_Full_SingleSidebandFullCarrier                                = 7,
    SSB_Reduc_SingleBandReducedCarrier                                = 8,
    USB_SingleBandSuppressedCarrier_UpperSidebandMode                 = 9,
    VSB_VestigialSideband                                             = 10
};

KString GetEnumAsStringDetailAmplitude( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailAmplitude( const KString & Value, KINT32 & ValueOut );

enum DetailAmplitudeAndAngle
{
    OtherDetailAmplitudeAndAngleDetail                                = 0,
    AmplitudeAndAngleDetail                                           = 1
};

KString GetEnumAsStringDetailAmplitudeAndAngle( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailAmplitudeAndAngle( const KString & Value, KINT32 & ValueOut );

enum DetailAngle
{
    OtherDetailAngle                                                  = 0,
    FM_FrequencyModulation                                            = 1,
    FSK_FrequencyShiftKeying                                          = 2,
    PM_PhaseModulation                                                = 3
};

KString GetEnumAsStringDetailAngle( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailAngle( const KString & Value, KINT32 & ValueOut );

enum DetailCombination
{
    OtherDetailCombination                                            = 0,
    AmplitudeAnglePulse                                               = 1
};

KString GetEnumAsStringDetailCombination( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailCombination( const KString & Value, KINT32 & ValueOut );

enum DetailPulse
{
    OtherPulseDetail                                                  = 0,
    PulseDetail                                                       = 1,
    X_Band_TACAN_PulseDetail                                          = 2,
    Y_Band_TACAN_PulseDetail                                          = 3
};

KString GetEnumAsStringDetailPulse( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailPulse( const KString & Value, KINT32 & ValueOut );

enum DetailUnmodulated
{
    OtherDetailUnmodulted                                             = 0,
    ContinuousWaveEmissionOfAnUnmodulatedCarrier                      = 1
};

KString GetEnumAsStringDetailUnmodulated( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailUnmodulated( const KString & Value, KINT32 & ValueOut );

enum DetailCarrierPhaseShift
{
    OtherDetailCarrierPhaseShift                                      = 0
};

KString GetEnumAsStringDetailCarrierPhaseShift( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringDetailCarrierPhaseShift( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Modulation System                                                    */
/* Specifies the interpretation of the modulation parameter field(s)    */
/* Used In:                                                             */
/*  Modulation Type                                                     */
/************************************************************************/

enum ModulationSystem
{
    OtherModulationSystem                                             = 0,
    GenericModulationSystem                                           = 1,
    HQ                                                                = 2,
    HQII                                                              = 3,
    HQIIA                                                             = 4,
    SINCGARS                                                          = 5,
    CCTT_SINCGARS                                                     = 6,
    EPLRS_EnhancedPositionLocationReportingSystem                     = 7,
    JTIDS_MIDS                                                        = 8
};

KString GetEnumAsStringModulationSystem( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringModulationSystem( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Crypto System Type                                                   */
/* Identifies the crypto equipment used in a tranmission                */
/* Used In:                                                             */
/*  Transmitter PDU                                                     */
/************************************************************************/

enum CryptoSystemType
{
    OtherCryptoSystem                                                 = 0,
    KY_28                                                             = 1,
    VINSON_KY_57_KY_58_SINCGARS_ICOM                                  = 2,
    NarrowSpectrumSecureVoice_NSVE                                    = 3,
    WideSpectrumSecureVoice_WSVE                                      = 4
};

KString GetEnumAsStringCryptoSystemType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringCryptoSystemType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encryption Mode                                                      */
/* Identifies the mode of encryption                                    */
/* Used In:                                                             */
/*  CryptoSystem                                                        */
/************************************************************************/

enum EncryptionMode
{
    BaseBand                                                          = 0,
    Diphase                                                           = 1
};

KString GetEnumAsStringEncryptionMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEncryptionMode( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encoding Class                                                       */
/* Encoding class for a signal PDU                                      */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum EncodingClass
{
    EncodedAudio                                                      = 0,
    RawBinaryData                                                     = 1,
    ApplicationSpecificData                                           = 2,
    DatabaseIndex                                                     = 3
};

KString GetEnumAsStringEncodingClass( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEncodingClass( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Encoding Type                                                        */
/* Encoding type when EncodingClass is audio                            */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum EncodingType
{
    _8_bit_mu_law                                                     = 1,
    CVSD_per_MIL_STD_188_113                                          = 2,
    ADPCM_per_CCITT_G_721                                             = 3,
    _16_bit_linear_PCM                                                = 4,
    _8_bit_linear_PCM                                                 = 5,
    VQ_VectorQuantization                                             = 6
};

KString GetEnumAsStringEncodingType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEncodingType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* TDL Type                                                             */
/* Tactical Data Link Type                                              */
/* Used In:                                                             */
/*  EncodingScheme                                                      */
/************************************************************************/

enum TDLType
{
    OtherTDLType                                                      = 0,
    PADIL                                                             = 1,
    NATOLink_1                                                        = 2,
    ATDL_1                                                            = 3,
    Link11B_TADILB_                                                   = 4,
    SituationalAwarenessDataLink_SADL_                                = 5,
    Link16LegacyFormat_JTIDS_TADIL_J_                                 = 6,
    Link16LegacyFormat_JTIDS_FDL_TADIL_J_                             = 7,
    Link11A_TADILA_                                                   = 8,
    IJMS                                                              = 9,
    Link4A_TADILC_                                                    = 10,
    Link4C                                                            = 11,
    TIBS                                                              = 12,
    ATL                                                               = 13,
    ConstantSource                                                    = 14,
    AbbreviatedCommandandControl                                      = 15,
    MILSTAR                                                           = 16,
    ATHS                                                              = 17,
    OTHGOLD                                                           = 18,
    TACELINT                                                          = 19,
    WeaponsDataLink_AWW_13_                                           = 20,
    AbbreviatedCommandandControl1                                     = 21,
    EnhancedPositionLocationReportingSystem_EPLRS_                    = 22,
    PositionLocationReportingSystem_PLRS_                             = 23,
    SINCGARS_TDLType                                                  = 24,
    HaveQuickI                                                        = 25,
    HaveQuickII                                                       = 26,
    HaveQuickIIA_Saturn_                                              = 27,
    Intra_FlightDataLink1                                             = 28,
    Intra_FlightDataLink2                                             = 29,
    ImprovedDataModem_IDM_                                            = 30,
    AirForceApplicationProgramDevelopment_AFAPD_                      = 31,
    CooperativeEngagementCapability_CEC_                              = 32,
    ForwardAreaAirDefense_FAAD_DataLink_FDL_                          = 33,
    GroundBasedDataLink_GBDL_                                         = 34,
    IntraVehicularInfoSystem_IVIS_                                    = 35,
    MarineTacticalSystem_MTS_                                         = 36,
    TacticalFireDirectionSystem_TACFIRE_                              = 37,
    IntegratedBroadcastService_IBS_                                   = 38,
    AirborneInformationTransfer_ABIT_                                 = 39,
    AdvancedTacticalAirborneReconnaissanceSystem_ATARS_DataLink       = 40,
    BattleGroupPassiveHorizonExtensionSystem_BGPHES_DataLink          = 41,
    CommonHighBandwidthDataLink_CHBDL_                                = 42,
    GuardrailInteroperableDataLink_IDL_                               = 43,
    GuardrailCommonSensorSystemOne_CSS1_DataLink                      = 44,
    GuardrailCommonSensorSystemTwo_CSS2_DataLink                      = 45,
    GuardrailCSS2Multi_RoleDataLink_MRDL_                             = 46,
    GuardrailCSS2DirectAirtoSatelliteRelay_DASR_DataLink              = 47,
    LineofSight_LOS_DataLinkImplementation_LOStether_                 = 48,
    LightweightCDL_LWCDL_                                             = 49,
    L_52M_SR_71_                                                      = 50,
    RivetReach_RivetOwlDataLink                                       = 51,
    SeniorSpan                                                        = 52,
    SeniorSpur                                                        = 53,
    SeniorStretch_                                                    = 54,
    SeniorYearInteroperableDataLink_IDL_                              = 55,
    SpaceCDL                                                          = 56,
    TR_1modeMISTAirborneDataLink                                      = 57,
    Ku_bandSATCOMDataLinkImplementation_UAV_                          = 58,
    MissionEquipmentControlDatalink_MECDL_                            = 59,
    RadarDataTransmittingSetDataLink                                  = 60,
    SurveillanceandControlDataLink_SCDL_                              = 61,
    TacticalUAVVideo                                                  = 62,
    UHFSATCOMDataLinkImplementation_UAV_                              = 63,
    TacticalCommonDataLink_TCDL_                                      = 64,
    LowLevelAirPictureInterface_LLAPI_                                = 65,
    WeaponsDataLink_AGM_130_                                          = 66,
    GC3                                                               = 99,
    Link16StandardizedFormat_JTIDS_MIDS_TADILJ_                       = 100,
    Link16EnhancedDataRate_EDRJTIDS_MIDS_TADIL_J_                     = 101,
    JTIDS_MIDSNetDataLoad_TIMS_TOMS_                                  = 102,
    Link22                                                            = 103,
    AFIWCIADSCommunicationsLinks                                      = 104
};

KString GetEnumAsStringTDLType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTDLType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Control Type                                                         */
/* Type of control requested                                            */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum ControlType
{
    ControlTypeReserved                                               = 0,
    ControlTypeStatus                                                 = 1,
    Request_Acknowledge_Required                                      = 2,
    Request_No_Acknowledge                                            = 3,
    Ack_Request_Granted                                               = 4,
    Nack_Request_Denied                                               = 5
    // 6-255 Reserved
};

KString GetEnumAsStringControlType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringControlType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Communications Channel Type                                          */
/* Communications Channel Type enumerations                             */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum ChannelType
{
    ChannelTypeReserved                                               = 0,
    Connection_FDX                                                    = 1,
    Connection_HDX_Destination_Receive_Only                           = 2,
    Connection_HDX_Destination_Transmit_Only                          = 3,
    Connection_HDX                                                    = 4
    // 5-255 Reserved
};

KString GetEnumAsStringChannelType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringChannelType( const KString & Value, KINT32 & ValueOut );

enum ChannelClass
{
    Simulated_Comm_Channel                                            = 0,
    Simulation_Support_Comm_Channel                                   = 1
};

KString GetEnumAsStringChannelClass( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringChannelClass( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Transmit Line State                                                  */
/* Identifies the current transmit state of the line at the intercon    */
/* source.                                                              */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum TransmitLineState
{
    TransmitLineStateNotApplicable                                    = 0,
    NotTransmitting                                                   = 1,
    Transmitting                                                      = 2
    // 3-255 Reserved
};

KString GetEnumAsStringTransmitLineState( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTransmitLineState( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Line State Command                                                   */
/* specifies the detailed type requested when the control type is       */
/* request or acknowledge                                               */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum LineStateCommand
{
    NoLineStateCommand                                                = 0,
    SetLineState_Transmitting                                         = 1,
    SetLineState_NotTransmitting                                      = 2,
    ReturnToLocalLineStateControl                                     = 3
    // 4-255        Reserved
};

KString GetEnumAsStringLineStateCommand( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringLineStateCommand( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* AdditionalIntrCommParamType                                          */
/* specifies the type of additonal intercom parameter data included.    */
/* Used In:                                                             */
/*  Intercom_Control_PDU                                                */
/************************************************************************/

enum AdditionalIntrCommParamType
{
    EntityDestinationRecord_Type                                      = 1,
    GroupDestinationRecord_Type                                       = 2,
    GroupAssignmentRecord_Type                                        = 3
};

KString GetEnumAsStringAdditionalIntrCommParamType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAdditionalIntrCommParamType( const KString & Value, KINT32 & ValueOut );

#if DIS_VERSION > 6
/************************************************************************/
/* AttachedIndicator                                                    */
/* Used to indicate whether the object is attached to an entity or      */
/* object.                                                              */
/* Used In:                                                             */
/*  PDU Header 7                                                        */
/************************************************************************/

enum AttachedIndicator
{
    NoStatementAttachedIndicator                                      = 0,
    UnattachedAttachedIndicator                                       = 1,
    AttachedAttachedIndicator                                         = 2
};

KString GetEnumAsStringAttachedIndicator( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAttachedIndicator( const KString & Value, KINT32 & ValueOut );

#endif

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS