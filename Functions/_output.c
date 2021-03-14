int __usercall _output@<eax>(int *a1@<edi>, _iobuf *stream, const char *format, char *argptr)
{
  int v4; // eax
  STATE v5; // edx
  bool v6; // zf
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // cl
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  char *v18; // eax
  int v19; // eax
  int v20; // eax
  __int64 v21; // rax
  signed __int16 *v22; // eax
  char *v23; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *i; // eax
  _WORD *v32; // eax
  unsigned int v33; // ebx
  char *j; // esi
  int v35; // eax
  unsigned __int64 v36; // ST00_8
  unsigned __int64 v37; // rcx
  signed int v38; // ecx
  char *v39; // eax
  char *v40; // esi
  char v41; // bl
  _iobuf *v42; // esi
  unsigned __int16 *v43; // ebx
  int v44; // eax
  $C8014B43F160BFD769FAE3F15553333C buffer; // [esp+0h] [ebp-240h]
  char s; // [esp+200h] [ebp-40h]
  int count; // [esp+20Ch] [ebp-34h]
  STATE state; // [esp+210h] [ebp-30h]
  int no_output; // [esp+214h] [ebp-2Ch]
  int hexadd; // [esp+218h] [ebp-28h]
  int bufferiswide; // [esp+21Ch] [ebp-24h]
  int fldwidth; // [esp+220h] [ebp-20h]
  int prefixlen; // [esp+224h] [ebp-1Ch]
  char prefix[2]; // [esp+228h] [ebp-18h]
  int charsout; // [esp+22Ch] [ebp-14h]
  int precision; // [esp+230h] [ebp-10h]
  $519E2A0ABDBAFFC353FD5D86715BA24D text; // [esp+234h] [ebp-Ch]
  int radix; // [esp+238h] [ebp-8h]
  int flags; // [esp+23Ch] [ebp-4h]

  v4 = (int)format;
  LOBYTE(v4) = *format;
  v5 = 0;
  v6 = *format == 0;
  radix = 0;
  charsout = 0;
  if ( !v6 )
  {
    while ( 1 )
    {
      ++format;
      v7 = 0;
      if ( charsout < 0 )
        return charsout;
      if ( (char)v4 >= 32 && (char)v4 <= 120 )
        v7 = *(_BYTE *)((char)v4 - 2147381824) & 0xF;
      state = __lookuptable[8 * v7 + v5] >> 4;
      switch ( state )
      {
        case 0:
          goto NORMAL_STATE;
        case 1:
          precision = -1;
          no_output = 0;
          fldwidth = 0;
          prefixlen = 0;
          flags = 0;
          bufferiswide = 0;
          goto LABEL_167;
        case 2:
          v8 = (char)v4 - 32;
          if ( v8 )
          {
            v9 = v8 - 3;
            if ( v9 )
            {
              v10 = v9 - 8;
              if ( v10 )
              {
                v11 = v10 - 2;
                if ( v11 )
                {
                  if ( v11 == 3 )
                    flags |= 8u;
                }
                else
                {
                  flags |= 4u;
                }
              }
              else
              {
                flags |= 1u;
              }
            }
            else
            {
              LOBYTE(flags) = flags | 0x80;
            }
          }
          else
          {
            flags |= 2u;
          }
          goto LABEL_167;
        case 3:
          if ( (_BYTE)v4 == 42 )
          {
            argptr += 4;
            fldwidth = *((_DWORD *)argptr - 1);
            if ( fldwidth < 0 )
            {
              flags |= 4u;
              fldwidth = -fldwidth;
            }
          }
          else
          {
            fldwidth = (char)v4 + 10 * fldwidth - 48;
          }
          goto LABEL_167;
        case 4:
          precision = 0;
          goto LABEL_167;
        case 5:
          if ( (_BYTE)v4 == 42 )
          {
            argptr += 4;
            precision = *((_DWORD *)argptr - 1);
            if ( precision < 0 )
              precision = -1;
          }
          else
          {
            precision = (char)v4 + 10 * precision - 48;
          }
          goto LABEL_167;
        case 6:
          switch ( (_BYTE)v4 )
          {
            case 0x49:
              v12 = *format;
              if ( *format != 54 || format[1] != 52 )
              {
                if ( v12 != 51 || format[1] != 50 )
                {
                  if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
                  {
                    state = 0;
NORMAL_STATE:
                    bufferiswide = 0;
                    write_char(stream, v4, &charsout);
                  }
                }
                else
                {
                  BYTE1(flags) &= 0x7Fu;
                  format += 2;
                }
              }
              else
              {
                BYTE1(flags) |= 0x80u;
                format += 2;
              }
              break;
            case 0x68:
              flags |= 0x20u;
              break;
            case 0x6C:
              flags |= 0x10u;
              break;
            case 0x77:
              BYTE1(flags) |= 8u;
              break;
          }
          goto LABEL_167;
        case 7:
          v4 = (char)v4;
          if ( (char)v4 <= 103 )
          {
            if ( v4 >= 101 )
              goto LABEL_86;
            if ( v4 > 88 )
            {
              v19 = v4 - 90;
              if ( !v19 )
              {
                argptr += 4;
                v22 = (signed __int16 *)*((_DWORD *)argptr - 1);
                if ( v22 && (v23 = (char *)*((_DWORD *)v22 + 1)) != 0 )
                {
                  v24 = *v22;
                  text.sz = v23;
                  if ( flags & 0x800 )
                  {
                    v24 /= 2;
                    bufferiswide = 1;
                  }
                  else
                  {
                    bufferiswide = 0;
                  }
                }
                else
                {
                  text.sz = "(null)";
                  v24 = strlen("(null)");
                }
                goto LABEL_143;
              }
              v20 = v19 - 9;
              if ( !v20 )
                goto LABEL_68;
              if ( v20 != 1 )
                goto LABEL_144;
LABEL_74:
              flags |= 0x40u;
LABEL_75:
              radix = 10;
              goto COMMON_INT;
            }
            if ( v4 != 88 )
            {
              v13 = v4 - 67;
              if ( v13 )
              {
                v14 = v13 - 2;
                if ( !v14 || (v15 = v14 - 2) == 0 )
                {
LABEL_86:
                  argptr += 8;
                  goto LABEL_144;
                }
                if ( v15 != 12 )
                  goto LABEL_144;
                if ( !(flags & 0x830) )
                  BYTE1(flags) |= 8u;
LABEL_60:
                v16 = precision;
                if ( precision == -1 )
                  v16 = 0x7FFFFFFF;
                argptr += 4;
                v17 = *((_DWORD *)argptr - 1);
                text.sz = *(char **)(argptr - 4);
                if ( flags & 0x810 )
                {
                  if ( !v17 )
                    text.sz = (char *)L"(null)";
                  v18 = text.sz;
                  bufferiswide = 1;
                  while ( v16 )
                  {
                    --v16;
                    if ( !*(_WORD *)v18 )
                      break;
                    v18 += 2;
                  }
                  v24 = (v18 - text.sz) >> 1;
                }
                else
                {
                  if ( !v17 )
                    text.sz = "(null)";
                  for ( i = text.sz; v16; ++i )
                  {
                    --v16;
                    if ( !*i )
                      break;
                  }
                  v24 = i - text.sz;
                }
LABEL_143:
                radix = v24;
                goto LABEL_144;
              }
              if ( !(flags & 0x830) )
                BYTE1(flags) |= 8u;
LABEL_68:
              argptr += 4;
              if ( flags & 0x810 )
              {
                radix = wctomb(buffer.sz, *((_WORD *)argptr - 2));
                if ( radix < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(argptr - 4);
                radix = 1;
              }
              text.sz = (char *)&buffer;
              goto LABEL_144;
            }
            goto LABEL_107;
          }
          v25 = v4 - 105;
          if ( !v25 )
            goto LABEL_74;
          v26 = v25 - 5;
          if ( !v26 )
          {
            argptr += 4;
            v32 = (_WORD *)*((_DWORD *)argptr - 1);
            if ( flags & 0x20 )
              *v32 = charsout;
            else
              *(_DWORD *)v32 = charsout;
            no_output = 1;
            goto LABEL_167;
          }
          v27 = v26 - 1;
          if ( v27 )
          {
            v28 = v27 - 1;
            if ( v28 )
            {
              v29 = v28 - 3;
              if ( !v29 )
                goto LABEL_60;
              v30 = v29 - 2;
              if ( !v30 )
                goto LABEL_75;
              if ( v30 != 3 )
                goto LABEL_144;
              hexadd = 39;
              goto COMMON_HEX;
            }
            precision = 8;
LABEL_107:
            hexadd = 7;
COMMON_HEX:
            radix = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
            goto COMMON_INT;
          }
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            BYTE1(flags) |= 2u;
COMMON_INT:
          if ( flags & 0x8000 )
          {
            v21 = *(_QWORD *)argptr;
            argptr += 8;
          }
          else
          {
            argptr += 4;
            if ( flags & 0x20 )
            {
              if ( flags & 0x40 )
                LODWORD(v21) = *((signed __int16 *)argptr - 2);
              else
                LODWORD(v21) = *((unsigned __int16 *)argptr - 2);
            }
            else
            {
              LODWORD(v21) = *((_DWORD *)argptr - 1);
              if ( !(flags & 0x40) )
              {
                HIDWORD(v21) = 0;
                goto LABEL_123;
              }
            }
            v21 = (signed int)v21;
          }
LABEL_123:
          if ( flags & 0x40 && v21 < 0 )
          {
            v21 = -v21;
            BYTE1(flags) |= 1u;
          }
          a1 = (int *)HIDWORD(v21);
          v33 = v21;
          if ( !(flags & 0x8000) )
            a1 = 0;
          if ( precision >= 0 )
            flags &= 0xFFFFFFF7;
          else
            precision = 1;
          if ( !((unsigned int)a1 | (unsigned int)v21) )
            prefixlen = 0;
          for ( j = &buffer.sz[511]; ; --j )
          {
            v35 = precision--;
            if ( v35 <= 0 && !((unsigned int)a1 | v33) )
              break;
            v36 = __PAIR__((unsigned int)a1, v33);
            v37 = __PAIR__((unsigned int)a1, v33) % radix;
            v38 = v37 + 48;
            count = HIDWORD(v37);
            a1 = (int *)(v36 / radix >> 32);
            v33 = v36 / radix;
            if ( v38 > 57 )
              LOBYTE(v38) = hexadd + v38;
            *j = v38;
          }
          v39 = (char *)(&buffer.sz[511] - j);
          v40 = j + 1;
          radix = (int)v39;
          text.sz = v40;
          if ( flags & 0x200 && (*v40 != 48 || !v39) )
          {
            --text.sz;
            *text.sz = 48;
            v24 = (int)(v39 + 1);
            goto LABEL_143;
          }
LABEL_144:
          if ( no_output )
            goto LABEL_167;
          v41 = flags;
          if ( !(flags & 0x40) )
            goto LABEL_153;
          if ( flags & 0x100 )
          {
            prefix[0] = 45;
LABEL_152:
            prefixlen = 1;
            goto LABEL_153;
          }
          if ( flags & 1 )
          {
            prefix[0] = 43;
            prefixlen = 1;
          }
          else if ( flags & 2 )
          {
            prefix[0] = 32;
            goto LABEL_152;
          }
LABEL_153:
          v42 = (_iobuf *)(fldwidth - prefixlen - radix);
          if ( !(flags & 0xC) )
            write_multi_char(a1, (int)&charsout, 32, fldwidth - prefixlen - radix, stream);
          a1 = (int *)stream;
          write_string((char *)&charsout, v42, (int *)stream, prefix, prefixlen);
          if ( v41 & 8 && !(v41 & 4) )
            write_multi_char((int *)stream, (int)&charsout, 48, (int)v42, stream);
          if ( bufferiswide && radix > 0 )
          {
            v43 = (unsigned __int16 *)text.sz;
            count = radix;
            do
            {
              --count;
              v44 = wctomb(&s, *v43);
              ++v43;
              if ( v44 <= 0 )
                break;
              a1 = (int *)stream;
              write_string((char *)&charsout, v42, (int *)stream, &s, v44);
            }
            while ( count );
          }
          else
          {
            write_string((char *)&charsout, v42, (int *)stream, text.sz, radix);
          }
          if ( flags & 4 )
            write_multi_char(a1, (int)&charsout, 32, (int)v42, stream);
LABEL_167:
          v4 = (int)format;
          LOBYTE(v4) = *format;
          if ( !*format )
            return charsout;
          v5 = state;
          break;
        default:
          goto LABEL_167;
      }
    }
  }
  return charsout;
}