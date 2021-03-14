void __stdcall KdpSerialSendString(char *Source, unsigned int Length)
{
  unsigned int v2; // edi
  char *v3; // esi
  char Output; // [esp+10h] [ebp+Ch]

  v2 = Length;
  if ( Length )
  {
    v3 = Source;
    do
    {
      Output = *v3++;
      KdPortPutByte(Output);
      --v2;
    }
    while ( v2 );
  }
}