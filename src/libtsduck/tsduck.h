//----------------------------------------------------------------------------
//
//  TSDuck - The MPEG Transport Stream Toolkit
//  Copyright (c) 2005-2017, Thierry Lelegard
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
//  THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#pragma once
#include "tsAC3Attributes.h"
#include "tsAC3Descriptor.h"
#include "tsAES.h"
#include "tsAVCAttributes.h"
#include "tsAVCHRDParameters.h"
#include "tsAVCParser.h"
#include "tsAVCSequenceParameterSet.h"
#include "tsAVCVUIParameters.h"
#include "tsAbortInterface.h"
#include "tsAbstractAVCAccessUnit.h"
#include "tsAbstractAVCData.h"
#include "tsAbstractAVCStructure.h"
#include "tsAbstractAudioVideoAttributes.h"
#include "tsAbstractDescrambler.h"
#include "tsAbstractDescriptor.h"
#include "tsAbstractDescriptorsTable.h"
#include "tsAbstractLongTable.h"
#include "tsAbstractTable.h"
#include "tsAbstractTransportListTable.h"
#include "tsAlgorithm.h"
#include "tsApplicationSharedLibrary.h"
#include "tsArgs.h"
#include "tsAsyncReport.h"
#include "tsAudioAttributes.h"
#include "tsAudioLanguageOptions.h"
#include "tsBAT.h"
#include "tsBCD.h"
#include "tsBinaryTable.h"
#include "tsBitStream.h"
#include "tsBlockCipher.h"
#include "tsBouquetNameDescriptor.h"
#include "tsByteBlock.h"
#include "tsCADescriptor.h"
#include "tsCAIdentifierDescriptor.h"
#include "tsCASFamily.h"
#include "tsCAT.h"
#include "tsCBC.h"
#include "tsCOM.h"
#include "tsCRC32.h"
#include "tsCTS1.h"
#include "tsCTS2.h"
#include "tsCTS3.h"
#include "tsCTS4.h"
#include "tsCerrReport.h"
#include "tsCipherChaining.h"
#include "tsCondition.h"
#include "tsConfigFile.h"
#include "tsConfigSection.h"
#include "tsContentDescriptor.h"
#include "tsCountryAvailabilityDescriptor.h"
#include "tsCyclingPacketizer.h"
#include "tsDES.h"
#include "tsDMT.h"
#include "tsDVS042.h"
#include "tsDataBroadcastIdDescriptor.h"
#include "tsDecimal.h"
#include "tsDektecControl.h"
#include "tsDektecInputPlugin.h"
#include "tsDektecOutputPlugin.h"
#include "tsDektecUtils.h"
#include "tsDescriptor.h"
#include "tsDescriptorList.h"
#include "tsDoubleCheckLock.h"
#include "tsECB.h"
#include "tsECMGClient.h"
#include "tsECMGClientHandlerInterface.h"
#include "tsECMGSCS.h"
#include "tsEMMGMUX.h"
#include "tsETID.h"
#include "tsEnhancedAC3Descriptor.h"
#include "tsEnumeration.h"
#include "tsEvent.h"
#include "tsEventHandler.h"
#include "tsException.h"
#include "tsExtendedEventDescriptor.h"
#include "tsFatal.h"
#include "tsFileNameRate.h"
#include "tsForkPipe.h"
#include "tsFormat.h"
#include "tsGenTabPlugin.h"
#include "tsGuard.h"
#include "tsGuardCondition.h"
#include "tsHDSimulcastLogicalChannelDescriptor.h"
#include "tsHash.h"
#include "tsHexa.h"
#include "tsIPAddress.h"
#include "tsIPUtils.h"
#include "tsISO639LanguageDescriptor.h"
#include "tsInputRedirector.h"
#include "tsInterruptHandler.h"
#include "tsLNB.h"
#include "tsLinkageDescriptor.h"
#include "tsLogicalChannelNumberDescriptor.h"
#include "tsMD5.h"
#include "tsMJD.h"
#include "tsMPEG.h"
#include "tsMemoryUtils.h"
#include "tsMessageQueue.h"
#include "tsModulation.h"
#include "tsMonotonic.h"
#include "tsMutex.h"
#include "tsMutexInterface.h"
#include "tsNIT.h"
#include "tsNames.h"
#include "tsNetworkNameDescriptor.h"
#include "tsNullMutex.h"
#include "tsNullReport.h"
#include "tsObject.h"
#include "tsOneShotPacketizer.h"
#include "tsOutputRedirector.h"
#include "tsPAT.h"
#include "tsPCR.h"
#include "tsPCRAnalyzer.h"
#include "tsPCSC.h"
#include "tsPESDemux.h"
#include "tsPESHandlerInterface.h"
#include "tsPESPacket.h"
#include "tsPIDOperator.h"
#include "tsPMT.h"
#include "tsPSILogger.h"
#include "tsPSILoggerOptions.h"
#include "tsPacketizer.h"
#include "tsParentalRatingDescriptor.h"
#include "tsPlatform.h"
#include "tsPlugin.h"
#include "tsPluginSharedLibrary.h"
#include "tsPollFiles.h"
#include "tsPrivateDataSpecifierDescriptor.h"
#include "tsRandomGenerator.h"
#include "tsReportBuffer.h"
#include "tsReportFile.h"
#include "tsReportHandler.h"
#include "tsReportInterface.h"
#include "tsResidentBuffer.h"
#include "tsRingNode.h"
#include "tsRound.h"
#include "tsSDT.h"
#include "tsSHA1.h"
#include "tsSHA256.h"
#include "tsSHA512.h"
#include "tsSSUDataBroadcastIdDescriptor.h"
#include "tsSSULinkageDescriptor.h"
#include "tsSTDDescriptor.h"
#include "tsSafePtr.h"
#include "tsScrambling.h"
#include "tsSection.h"
#include "tsSectionDemux.h"
#include "tsSectionHandlerInterface.h"
#include "tsSectionProviderInterface.h"
#include "tsService.h"
#include "tsServiceDescriptor.h"
#include "tsServiceListDescriptor.h"
#include "tsSharedLibrary.h"
#include "tsShortEventDescriptor.h"
#include "tsSimulCryptDate.h"
#include "tsSingletonManager.h"
#include "tsSocketAddress.h"
#include "tsStandaloneTableDemux.h"
#include "tsStaticInstance.h"
#include "tsStreamIdentifierDescriptor.h"
#include "tsStringUtils.h"
#include "tsSysUtils.h"
#include "tsSystemMonitor.h"
#include "tsSystemRandomGenerator.h"
#include "tsTCPConnection.h"
#include "tsTCPServer.h"
#include "tsTCPSocket.h"
#include "tsTDES.h"
#include "tsTDT.h"
#include "tsTLV.h"
#include "tsTLVAnalyzer.h"
#include "tsTLVChannelMessage.h"
#include "tsTLVConnection.h"
#include "tsTLVMessage.h"
#include "tsTLVMessageFactory.h"
#include "tsTLVProtocol.h"
#include "tsTLVSerializer.h"
#include "tsTLVStreamMessage.h"
#include "tsTOT.h"
#include "tsTSAnalyzer.h"
#include "tsTSAnalyzerOptions.h"
#include "tsTSAnalyzerReport.h"
#include "tsTSDT.h"
#include "tsTSFileInput.h"
#include "tsTSFileInputBuffered.h"
#include "tsTSFileOutput.h"
#include "tsTSFileOutputResync.h"
#include "tsTSPacket.h"
#include "tsTableHandlerInterface.h"
#include "tsTables.h"
#include "tsTablesLogger.h"
#include "tsTablesLoggerOptions.h"
#include "tsTelnetConnection.h"
#include "tsTerrestrialDeliverySystemDescriptor.h"
#include "tsThread.h"
#include "tsThreadAttributes.h"
#include "tsTime.h"
#include "tsToInteger.h"
#include "tsTransportStreamId.h"
#include "tsTuner.h"
#include "tsTunerArgs.h"
#include "tsTunerParameters.h"
#include "tsTunerParametersATSC.h"
#include "tsTunerParametersBitrateDiffDVBT.h"
#include "tsTunerParametersDVBC.h"
#include "tsTunerParametersDVBS.h"
#include "tsTunerParametersDVBT.h"
#include "tsTunerUtils.h"
#include "tsUDPSocket.h"
#include "tsUID.h"
#include "tsUserInterrupt.h"
#include "tsVariable.h"
#include "tsVersion.h"
#include "tsVideoAttributes.h"

#if defined(__linux)
#include "linux/tsDTVProperties.h"
#include "linux/tsSignalAllocator.h"
#endif

#if defined(__windows)
#include "windows/tsComIds.h"
#include "windows/tsComPtr.h"
#include "windows/tsComUtils.h"
#include "windows/tsDirectShowUtils.h"
#include "windows/tsMediaTypeUtils.h"
#include "windows/tsRegistryUtils.h"
#include "windows/tsSinkFilter.h"
#endif
