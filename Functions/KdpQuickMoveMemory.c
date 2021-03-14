void __stdcall KdpQuickMoveMemory(void *Destination, void *Source, unsigned int Length)
{
  unsigned int v3; // esi
  _BYTE *v4; // ecx
  _BYTE *v5; // eax

  v3 = Length;
  if ( Length )
  {
    v4 = Source;
    v5 = Destination;
    do
    {
      *v5++ = *v4++;
      --v3;
    }
    while ( v3 );
  }
}