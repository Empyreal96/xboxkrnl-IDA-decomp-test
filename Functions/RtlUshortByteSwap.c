USHORT __fastcall RtlUshortByteSwap(USHORT Source)
{
  USHORT result; // ax

  LOBYTE(result) = HIBYTE(Source);
  HIBYTE(result) = Source;
  return result;
}