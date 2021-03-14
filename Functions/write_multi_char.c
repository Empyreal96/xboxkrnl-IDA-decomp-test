void __usercall write_multi_char(int *pnumwritten@<edi>, int a2@<eax>, char ch, int num, _iobuf *f)
{
  _DWORD *v5; // esi

  v5 = (_DWORD *)a2;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(a2) = ch;
    --num;
    a2 = write_char(f, a2, v5);
  }
  while ( *v5 != -1 );
}