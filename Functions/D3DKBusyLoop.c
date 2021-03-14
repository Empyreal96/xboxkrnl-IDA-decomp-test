void D3DK::BusyLoop()
{
  volatile unsigned int i; // [esp+0h] [ebp-4h]

  i = 400;
  do
    --i;
  while ( i );
}