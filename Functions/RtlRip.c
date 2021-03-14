void __stdcall RtlRip(void *ApiName, void *Expression, void *Message)
{
  char *v3; // esi
  char *v4; // edi
  char v5; // bl
  char v6; // dl
  char *v7; // ecx
  char Buffer[512]; // [esp+Ch] [ebp-200h]

  v3 = (char *)Expression;
  v4 = (char *)Message;
  if ( !Message )
  {
    v4 = "failed";
    if ( !Expression )
      v4 = "unexpected failure";
  }
  v5 = 32;
  if ( Expression )
  {
    v5 = 40;
    v6 = 41;
  }
  else
  {
    v6 = 32;
  }
  v7 = byte_80014442;
  if ( !Expression )
    v3 = byte_80014442;
  if ( ApiName )
    v7 = (char *)ApiName;
  _snprintf((int *)v4, Buffer, 0x200u, "%s%c %c%s%c %s", v7, ApiName == 0 ? 32 : 58, v5, v3, v6, v4);
  Buffer[511] = 0;
  DebugService(6u, Buffer, 0);
}