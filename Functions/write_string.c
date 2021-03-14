void __usercall write_string(char *string@<eax>, _iobuf *f@<esi>, int *pnumwritten@<edi>, _BYTE *a4@<ecx>, int len)
{
  char *v5; // esi
  _BYTE *v6; // ebx

  v5 = string;
  v6 = a4;
  if ( !(pnumwritten[3] & 0x40) || pnumwritten[2] )
  {
    do
    {
      if ( len <= 0 )
        break;
      LOBYTE(string) = *v6;
      --len;
      string = (char *)write_char((_iobuf *)pnumwritten, (int)string, v5);
      ++v6;
    }
    while ( *(_DWORD *)v5 != -1 );
  }
  else
  {
    *(_DWORD *)string += len;
  }
}