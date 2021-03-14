void __stdcall CMcpxCore::SetFrontEndState(MCPX_FE_STATE nState)
{
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  R_FE_CONTROL rFeControl; // [esp+10h] [ebp-4h]

  CAutoIrql::CAutoIrql(&__AutoIrql);
  rFeControl.uValue = MEMORY[0xFE801100];
  switch ( nState )
  {
    case 0:
      rFeControl.uValue = rFeControl.uValue & 0xFFFFFF1F | 0x80;
      break;
    case 1:
      rFeControl.uValue &= 0xFFFFFF1F;
      break;
    case 2:
      rFeControl.uValue |= 4u;
      rFeControl.uValue |= 2u;
      rFeControl.uValue |= 1u;
      rFeControl.uValue |= 0x1000u;
      break;
    case 3:
      rFeControl.uValue &= 0xFFFFFFFB;
      rFeControl.uValue &= 0xFFFFFFFD;
      rFeControl.uValue &= 0xFFFFFFFE;
      rFeControl.uValue &= 0xFFFFEFFF;
      break;
    default:
      break;
  }
  MEMORY[0xFE801100] = rFeControl.uValue;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}