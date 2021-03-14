void __stdcall CMcpxCore::SetSetupEngineState(MCPX_SE_STATE nState)
{
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  R_SE_CONTROL rSeControl; // [esp+10h] [ebp-4h]

  CAutoIrql::CAutoIrql(&__AutoIrql);
  rSeControl.uValue = MEMORY[0xFE802000];
  switch ( nState )
  {
    case 0:
      rSeControl.uValue &= 0xFFFFFFE7;
      break;
    case 1:
      rSeControl.uValue = rSeControl.uValue & 0xFFFFFFE7 | 8;
      break;
    case 2:
      rSeControl.uValue = rSeControl.uValue & 0xFFFFFFE7 | 0x10;
      break;
    case 3:
      rSeControl.uValue |= 0x18u;
      break;
    case 4:
      rSeControl.uValue |= 4u;
      rSeControl.uValue |= 2u;
      rSeControl.uValue |= 1u;
      break;
    case 5:
      rSeControl.uValue &= 0xFFFFFFFB;
      rSeControl.uValue &= 0xFFFFFFFD;
      rSeControl.uValue &= 0xFFFFFFFE;
      break;
    default:
      break;
  }
  MEMORY[0xFE802000] = rSeControl.uValue;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}