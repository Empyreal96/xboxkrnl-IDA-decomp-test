void __stdcall ObDissectName(_STRING Path, _STRING *FirstName, _STRING *RemainingName)
{
  _STRING *v3; // eax
  unsigned int v4; // esi
  unsigned int FirstNameStart; // [esp+14h] [ebp+10h]

  v3 = FirstName;
  v4 = 0;
  FirstName->Length = 0;
  FirstName->MaximumLength = 0;
  FirstName->Buffer = 0;
  RemainingName->Length = 0;
  RemainingName->MaximumLength = 0;
  RemainingName->Buffer = 0;
  if ( Path.Length )
  {
    if ( *Path.Buffer == 92 )
      v4 = 1;
    FirstNameStart = v4;
    while ( v4 < Path.Length && Path.Buffer[v4] != 92 )
      ++v4;
    v3->Length = v4 - FirstNameStart;
    v3->MaximumLength = v4 - FirstNameStart;
    v3->Buffer = &Path.Buffer[FirstNameStart];
    if ( v4 < Path.Length )
    {
      RemainingName->Length = Path.Length - v4 - 1;
      RemainingName->MaximumLength = Path.Length - v4 - 1;
      RemainingName->Buffer = &Path.Buffer[v4 + 1];
    }
  }
}