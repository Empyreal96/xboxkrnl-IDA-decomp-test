char __userpurge KdpSendWaitContinue@<al>(int a1@<esi>, unsigned int OutPacketType, _STRING *OutMessageHeader, _STRING *OutMessageData, _X86_NT5_CONTEXT *ContextRecord)
{
  unsigned int v5; // eax
  int v6; // edx
  int v7; // ecx
  char result; // al
  _DBGKD_MANIPULATE_STATE64 ManipulateState; // [esp+8h] [ebp-4Ch]
  _STRING MessageHeader; // [esp+40h] [ebp-14h]
  _STRING MessageData; // [esp+48h] [ebp-Ch]
  unsigned int Length; // [esp+50h] [ebp-4h]

  MessageHeader.Buffer = (char *)&ManipulateState;
  MessageHeader.MaximumLength = 56;
  MessageData.MaximumLength = 4096;
  MessageData.Buffer = KdpMessageBuffer;
  KdPhysicalPort->SendPacket(OutPacketType, OutMessageHeader, OutMessageData);
  while ( !KdDebuggerNotPresent )
  {
    while ( 1 )
    {
      v5 = KdPhysicalPort->ReceivePacket(2u, &MessageHeader, &MessageData, &Length);
      if ( v5 == 2 )
        break;
      if ( v5 != 1 )
      {
        switch ( ManipulateState.ApiNumber )
        {
          case 0x3130u:
            KdpReadVirtualMemory(&ManipulateState, &MessageData);
            continue;
          case 0x3131u:
            KdpWriteVirtualMemory(&ManipulateState, &MessageData);
            continue;
          case 0x3132u:
            KdpGetContext(v7, v6, &ManipulateState, &MessageData, ContextRecord);
            continue;
          case 0x3133u:
            KdpSetContext(v7, v6, &ManipulateState, &MessageData, ContextRecord);
            continue;
          case 0x3134u:
            KdpWriteBreakpoint(v6, v7, (int *)ContextRecord, &ManipulateState, &MessageData);
            continue;
          case 0x3135u:
            KdpRestoreBreakpoint(v6, v7, (int *)ContextRecord, &ManipulateState, &MessageData);
            continue;
          case 0x3136u:
            return (ManipulateState.u.GetContext.Unused & 0x80000000) == 0;
          case 0x3137u:
            KdpReadControlSpace(v6, v7, a1, &ManipulateState, &MessageData);
            continue;
          case 0x3138u:
            KdpWriteControlSpace(&ManipulateState, &MessageData);
            continue;
          case 0x3139u:
            KdpReadIoSpace(v6, v7, (int *)ContextRecord, &ManipulateState, &MessageData);
            continue;
          case 0x313Au:
            KdpWriteIoSpace(v6, v7, (int *)ContextRecord, &ManipulateState, &MessageData);
            continue;
          case 0x313Bu:
            HalReturnToFirmware(v6, v7, (int *)ContextRecord, a1, HalKdRebootRoutine);
            return result;
          case 0x313Cu:
            if ( (ManipulateState.u.GetContext.Unused & 0x80000000) != 0 )
              return 0;
            KdpGetStateChange(&ManipulateState, ContextRecord);
            return 1;
          case 0x313Du:
            KdpReadPhysicalMemory(v6, v7, (int *)ContextRecord, &ManipulateState, &MessageData);
            continue;
          case 0x313Eu:
            KdpWritePhysicalMemory(&ManipulateState, &MessageData);
            continue;
          case 0x3140u:
            KdSetSpecialCall(&ManipulateState, ContextRecord);
            continue;
          case 0x3141u:
            KdNumberOfSpecialCalls = 0;
            continue;
          case 0x3142u:
            KdSetInternalBreakpoint((int *)ContextRecord, &ManipulateState);
            continue;
          case 0x3143u:
            KdGetInternalBreakpoint(&ManipulateState);
            continue;
          case 0x3146u:
            KdpGetVersion(&ManipulateState);
            continue;
          case 0x3147u:
            if ( !KdpWriteBreakPointEx(&ManipulateState, &MessageData) )
              continue;
            return 0;
          case 0x3148u:
            KdpRestoreBreakPointEx(&ManipulateState, &MessageData);
            continue;
          case 0x3149u:
            KdpCauseBugCheck(&ManipulateState);
            return result;
          case 0x3150u:
            return 2;
          case 0x3151u:
            KdpNotSupported(&ManipulateState);
            break;
          case 0x3152u:
            KdpReadMachineSpecificRegister(v7, v6, &ManipulateState, &MessageData);
            break;
          case 0x3153u:
            KdpWriteMachineSpecificRegister(v7, v6, &ManipulateState, &MessageData);
            break;
          case 0x3156u:
            KdpSearchMemory(&ManipulateState, &MessageData);
            break;
          case 0x3159u:
            KdpCheckLowMemory(&ManipulateState);
            break;
          default:
            MessageData.Length = 0;
            ManipulateState.ReturnStatus = -1073741823;
            KdPhysicalPort->SendPacket(2u, &MessageHeader, &MessageData);
            break;
        }
      }
    }
    KdPhysicalPort->SendPacket(OutPacketType, OutMessageHeader, OutMessageData);
  }
  return 1;
}