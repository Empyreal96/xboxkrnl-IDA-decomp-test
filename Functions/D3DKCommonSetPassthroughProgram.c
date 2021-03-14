void __usercall D3DK::CommonSetPassthroughProgram(D3DK::CDevice *pDevice@<eax>, int *a2@<ecx>)
{
  int *v2; // edi
  unsigned int *v3; // esi
  int v4; // edx
  unsigned int *v5; // esi

  v2 = a2;
  if ( *(_BYTE *)(a2[285] + 8) & 2 )
  {
    v3 = XMETAL_StartPushCount(a2, (_XMETAL_PushBuffer *)a2, 0x4Eu);
    XMETAL_Push1f(v2, v3, 0x1EA4u, 0.0);
    XMETAL_PushCount(v2, v3 + 2, 0xB80u, 8u);
    v3[3] = v2[321];
    v3[4] = v2[322];
    v4 = v2[319];
    *((float *)v3 + 6) = 1.0;
    v3[5] = v4;
    v3[7] = LODWORD(KELVIN_BORDER_1);
    v3[8] = LODWORD(KELVIN_BORDER_1);
    v3[9] = 0;
    v3[10] = 0;
    XMETAL_Push1f(v2, v3 + 11, 0x1E9Cu, 0.0);
    v5 = D3DK::ParseProgram(v3 + 13, D3DK::g_PassthruProgramSpecularFog, 0x30u);
    D3DK::PushedRaw(v2, v5);
    XMETAL_EndPush(v2, (_XMETAL_PushBuffer *)v2, v5);
  }
}