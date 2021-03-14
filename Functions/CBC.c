void __stdcall CBC(void (__stdcall *Cipher)(char *, char *, void *, int), unsigned int dwBlockLen, char *output, char *input, void *keyTable, int op, char *feedback)
{
  unsigned int v7; // ebp
  char *v8; // eax
  char *v9; // ebx
  int v10; // ecx
  _DWORD *v11; // ecx
  signed int v12; // ebp
  int v13; // esi
  int v14; // eax
  char *v15; // eax
  int v16; // ecx
  char *v17; // ecx
  int v18; // esi
  int v19; // edi
  int v20; // edx
  char *v21; // eax
  unsigned int v22; // edx
  char *v23; // eax
  char *v24; // eax
  int v25; // ecx
  char *v26; // eax
  int v27; // ecx
  char v28; // dl
  char *outputOld; // [esp+10h] [ebp-44h]
  char *inputOld; // [esp+14h] [ebp-40h]
  char *feedbackOld; // [esp+18h] [ebp-3Ch]
  unsigned __int64 OutputAlignedBuffer; // [esp+1Ch] [ebp-38h]
  unsigned __int64 InputAlignedBuffer; // [esp+24h] [ebp-30h]
  unsigned __int64 FeedbackAlignedBuffer; // [esp+2Ch] [ebp-28h]
  char temp[32]; // [esp+34h] [ebp-20h]
  unsigned int dwBlockLena; // [esp+5Ch] [ebp+8h]
  int fInputAligned; // [esp+60h] [ebp+Ch]

  v7 = dwBlockLen;
  if ( dwBlockLen == 8 )
  {
    v8 = input;
    v9 = output;
    if ( (unsigned __int8)input & 7 && input != output )
    {
      v10 = *(_DWORD *)input;
      inputOld = input;
      v8 = (char *)&InputAlignedBuffer;
      HIDWORD(InputAlignedBuffer) = *((_DWORD *)input + 1);
      LODWORD(InputAlignedBuffer) = v10;
      input = (char *)&InputAlignedBuffer;
      dwBlockLena = 0;
    }
    else
    {
      dwBlockLena = 1;
    }
    if ( (unsigned __int8)output & 7 )
    {
      OutputAlignedBuffer = *(_QWORD *)output;
      if ( output == v8 )
      {
        v8 = (char *)&OutputAlignedBuffer;
        input = (char *)&OutputAlignedBuffer;
      }
      outputOld = output;
      v9 = (char *)&OutputAlignedBuffer;
      fInputAligned = 0;
    }
    else
    {
      fInputAligned = 1;
    }
    v11 = feedback;
    if ( (unsigned __int8)feedback & 7 )
    {
      LODWORD(FeedbackAlignedBuffer) = *(_DWORD *)feedback;
      feedbackOld = feedback;
      v11 = &FeedbackAlignedBuffer;
      HIDWORD(FeedbackAlignedBuffer) = *((_DWORD *)feedback + 1);
      feedback = (char *)&FeedbackAlignedBuffer;
      v12 = 0;
    }
    else
    {
      v12 = 1;
    }
    if ( op == 1 )
    {
      v13 = *v11 ^ *(_DWORD *)v8;
      v14 = v11[1] ^ *((_DWORD *)v8 + 1);
      *(_DWORD *)v9 = v13;
      *((_DWORD *)v9 + 1) = v14;
      Cipher(v9, v9, keyTable, 1);
      v15 = feedback;
      *(_DWORD *)feedback = *(_DWORD *)v9;
      *((_DWORD *)feedback + 1) = *((_DWORD *)v9 + 1);
    }
    else
    {
      if ( v9 != v8 )
      {
        Cipher(v9, v8, keyTable, 0);
        v15 = feedback;
        v16 = *((_DWORD *)v9 + 1);
        *(_DWORD *)v9 ^= *(_DWORD *)feedback;
        *((_DWORD *)v9 + 1) = *((_DWORD *)feedback + 1) ^ v16;
        v17 = input;
        *(_DWORD *)feedback = *(_DWORD *)input;
        *((_DWORD *)feedback + 1) = *((_DWORD *)input + 1);
LABEL_20:
        if ( !fInputAligned )
        {
          *(_DWORD *)outputOld = *(_DWORD *)v9;
          *((_DWORD *)outputOld + 1) = *((_DWORD *)v9 + 1);
        }
        if ( !dwBlockLena )
        {
          *(_DWORD *)inputOld = *(_DWORD *)v17;
          *((_DWORD *)inputOld + 1) = *((_DWORD *)v17 + 1);
        }
        if ( !v12 )
        {
          *(_DWORD *)feedbackOld = *(_DWORD *)v15;
          *((_DWORD *)feedbackOld + 1) = *((_DWORD *)v15 + 1);
        }
        return;
      }
      v18 = *(_DWORD *)v8;
      v19 = *((_DWORD *)v8 + 1);
      ((void (__fastcall *)(void *, signed int, char *, char *, void *, _DWORD))Cipher)(
        keyTable,
        1,
        v9,
        v8,
        keyTable,
        0);
      v15 = feedback;
      v20 = *((_DWORD *)v9 + 1);
      *(_DWORD *)v9 ^= *(_DWORD *)feedback;
      *((_DWORD *)v9 + 1) = *((_DWORD *)feedback + 1) ^ v20;
      *(_DWORD *)feedback = v18;
      *((_DWORD *)feedback + 1) = v19;
    }
    v17 = input;
    goto LABEL_20;
  }
  if ( op == 1 )
  {
    if ( dwBlockLen )
    {
      v21 = input;
      v22 = dwBlockLen;
      do
      {
        *v21 ^= v21[feedback - input];
        ++v21;
        --v22;
      }
      while ( v22 );
    }
    Cipher(output, input, keyTable, 1);
    if ( dwBlockLen )
    {
      v23 = feedback;
      do
      {
        *v23 = v23[output - feedback];
        ++v23;
        --v7;
      }
      while ( v7 );
    }
  }
  else if ( input == output )
  {
    if ( dwBlockLen <= 0x20 )
    {
      qmemcpy(temp, input, dwBlockLen);
      Cipher(output, input, keyTable, 0);
      if ( dwBlockLen )
      {
        v26 = output;
        v27 = feedback - output;
        do
        {
          v28 = v26[temp - output];
          *v26 ^= v26[v27];
          (v26++)[v27] = v28;
          --v7;
        }
        while ( v7 );
      }
    }
  }
  else
  {
    Cipher(output, input, keyTable, 0);
    if ( dwBlockLen )
    {
      v24 = output;
      v25 = feedback - output;
      do
      {
        *v24 ^= v24[v25];
        v24[v25] = v24[input - output];
        ++v24;
        --v7;
      }
      while ( v7 );
    }
  }
}