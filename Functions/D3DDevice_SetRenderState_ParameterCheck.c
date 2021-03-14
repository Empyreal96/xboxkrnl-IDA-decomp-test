// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_SetRenderState_ParameterCheck@<eax>(int *a1@<edi>, _D3DRENDERSTATETYPE State, unsigned int Value)
{
  int result; // eax
  bool v4; // zf
  bool v5; // cf
  bool v6; // zf
  int v7; // eax
  char *v8; // [esp-4h] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[142];
  if ( (signed int)State < 144 )
  {
    switch ( State )
    {
      case 0:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs0");
        goto LABEL_100;
      case 1:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs1");
        goto LABEL_100;
      case 2:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs2");
        goto LABEL_100;
      case 3:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs3");
        goto LABEL_100;
      case 4:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs4");
        goto LABEL_100;
      case 5:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs5");
        goto LABEL_100;
      case 6:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs6");
        goto LABEL_100;
      case 7:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSAlphaInputs7");
        goto LABEL_100;
      case 8:
        if ( D3DK::ValidFinalCombinerABCD(a1, Value, "PSFinalCombinerInputsABCD") )
          goto LABEL_115;
        return -2005530516;
      case 9:
        if ( D3DK::ValidFinalCombinerEFG(a1, Value, "PSFinalCombinerInputsEFG") )
          goto LABEL_115;
        return -2005530516;
      case 26:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs0");
        goto LABEL_100;
      case 27:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs1");
        goto LABEL_100;
      case 28:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs2");
        goto LABEL_100;
      case 29:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs3");
        goto LABEL_100;
      case 30:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs4");
        goto LABEL_100;
      case 31:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs5");
        goto LABEL_100;
      case 32:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs6");
        goto LABEL_100;
      case 33:
        v7 = D3DK::ValidAlphaOutputs(a1, Value, "PSAlphaOutputs7");
        goto LABEL_100;
      case 34:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs0");
        goto LABEL_100;
      case 35:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs1");
        goto LABEL_100;
      case 36:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs2");
        goto LABEL_100;
      case 37:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs3");
        goto LABEL_100;
      case 38:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs4");
        goto LABEL_100;
      case 39:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs5");
        goto LABEL_100;
      case 40:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs6");
        goto LABEL_100;
      case 41:
        v7 = D3DK::ValidCombinerInputs(a1, Value, "PSRGBInputs7");
        goto LABEL_100;
      case 42:
        if ( D3DK::ValidCompareMode(a1, Value, "PSCompareMode") )
          goto LABEL_115;
        return -2005530516;
      case 45:
        v7 = D3DK::ValidRGBOutputs(a1, Value, "PSRGBOutputs0");
        goto LABEL_100;
      case 46:
        v8 = "PSRGBOutputs1";
        goto LABEL_99;
      case 47:
        v7 = D3DK::ValidRGBOutputs(a1, Value, "PSRGBOutputs2");
        goto LABEL_100;
      case 48:
        v7 = D3DK::ValidRGBOutputs(a1, Value, "PSRGBOutputs3");
        goto LABEL_100;
      case 49:
        v8 = "PSRGBOutputs4";
        goto LABEL_99;
      case 50:
        v7 = D3DK::ValidRGBOutputs(a1, Value, "PSRGBOutputs5");
        goto LABEL_100;
      case 51:
        v7 = D3DK::ValidRGBOutputs(a1, Value, "PSRGBOutputs6");
        goto LABEL_100;
      case 52:
        v8 = "PSRGBOutputs7";
LABEL_99:
        v7 = D3DK::ValidRGBOutputs(a1, Value, v8);
LABEL_100:
        if ( !v7 )
          return -2005530516;
        goto LABEL_115;
      case 53:
        if ( D3DK::ValidCombinerCount(a1, Value, "PSCombinerCount") )
          goto LABEL_115;
        return -2005530516;
      case 55:
        if ( D3DK::ValidDotMapping(a1, Value, "PSDotMapping") )
          goto LABEL_115;
        return -2005530516;
      case 56:
        if ( D3DK::ValidInputTexture(a1, Value, "PSInputTexture") )
          goto LABEL_115;
        return -2005530516;
      case 57:
      case 58:
      case 70:
      case 135:
        if ( Value < 0x200 || Value > 0x207 )
          goto LABEL_7;
        goto LABEL_115;
      case 59:
      case 60:
      case 64:
      case 65:
      case 79:
      case 80:
      case 81:
      case 92:
      case 93:
      case 94:
      case 108:
      case 109:
      case 121:
      case 122:
      case 124:
      case 131:
      case 132:
      case 137:
      case 138:
      case 139:
      case 140:
      case 141:
      case 142:
      case 143:
        if ( *(float *)&Value == 0.0 )
          goto LABEL_115;
        v4 = Value == 1;
        goto LABEL_6;
      case 61:
        v4 = (Value & 0xFFFFFF00) == 0;
        goto LABEL_6;
      case 62:
      case 63:
        if ( Value > 1 && Value < 0x300 || Value > 0x308 && Value < 0x8001 )
          goto LABEL_7;
        v5 = Value < 0x8004;
        v6 = Value == 32772;
        goto LABEL_32;
      case 66:
        if ( Value < 0x1D00 )
          goto LABEL_7;
        v5 = Value < 0x1D01;
        v6 = Value == 7425;
        goto LABEL_32;
      case 67:
        v4 = (Value & 0xFEFEFEFE) == 0;
        goto LABEL_6;
      case 68:
      case 69:
      case 125:
        if ( *(float *)&Value == 0.0 || Value >= 0x1E00 && Value <= 0x1E03 || Value == 5386 )
          goto LABEL_115;
        if ( Value < 0x8507 )
          goto LABEL_7;
        v5 = Value < 0x8508;
        v6 = Value == 34056;
        goto LABEL_32;
      case 71:
        if ( Value > 0xFF )
          goto LABEL_7;
        goto LABEL_115;
      case 74:
        if ( Value < 0x8006 || Value > 0x8008 && Value < 0x800A || Value > 0x800B && Value < 0xF005 || Value > 0xF006 )
          goto LABEL_7;
        goto LABEL_115;
      case 76:
        if ( Value > 4 && Value < 0xF )
          goto LABEL_7;
        v5 = Value < 0xF;
        v6 = Value == 15;
        goto LABEL_32;
      case 88:
      case 89:
      case 90:
      case 91:
        if ( !(Value & 0xFEEFEFEF) )
          goto LABEL_115;
        D3DK::DXGRIP(a1, "Invalid WRAP value");
        return -2005530516;
      case 96:
      case 97:
      case 98:
      case 99:
      case 100:
      case 101:
      case 102:
      case 103:
        if ( Value == 1 || Value == 2 || *(float *)&Value == 0.0 )
          goto LABEL_115;
        D3DK::DXGRIP(a1, "Invalid D3DMCS value");
        return -2005530516;
      case 106:
      case 107:
      case 113:
        if ( *(float *)&Value < 0.0 )
          goto LABEL_7;
        goto LABEL_115;
      case 116:
        if ( D3DK::ValidTextureModes(a1, Value, "PSTextureModes") )
          goto LABEL_115;
        return -2005530516;
      case 117:
        if ( Value >= 7 )
          goto LABEL_7;
        goto LABEL_115;
      case 119:
      case 120:
        if ( Value < 0x1B00 )
          goto LABEL_7;
        v5 = Value < 0x1B02;
        v6 = Value == 6914;
        goto LABEL_32;
      case 123:
        v5 = Value < 2;
        v6 = Value == 2;
LABEL_32:
        if ( !v5 && !v6 )
          goto LABEL_7;
        goto LABEL_115;
      case 127:
        if ( *(float *)&Value == 0.0 || Value == 2304 )
          goto LABEL_115;
        v4 = Value == 2305;
        goto LABEL_6;
      case 129:
        if ( Value > 0x10 )
          goto LABEL_7;
        goto LABEL_115;
      case 130:
        if ( Value < 0x1500 || Value > 0x150F )
        {
          v4 = Value == 0;
LABEL_6:
          if ( !v4 )
            goto LABEL_7;
        }
        goto LABEL_115;
      case 134:
        if ( (_BYTE)Value )
        {
          D3DK::DXGRIP(a1, "D3DRS_MULTISAMPLETYPE can't change antialiasing scale factors");
          result = -2005530516;
        }
        else if ( Value & 0xFFFF0000 )
        {
          D3DK::DXGRIP(a1, "D3DRS_MULTISAMPLETYPE can't accept D3DMULTISAMPLE_PREFILTER flags");
          result = -2005530516;
        }
        else
        {
LABEL_115:
          result = 0;
        }
        break;
      case 136:
        if ( *(float *)&Value >= 0.0 )
          goto LABEL_115;
LABEL_7:
        D3DK::DXGRIP(a1, "Invalid value");
        return -2005530516;
      default:
        goto LABEL_115;
    }
  }
  else
  {
    D3DK::DXGRIP(a1, "Invalid render state type");
    result = -2005530516;
  }
  return result;
}