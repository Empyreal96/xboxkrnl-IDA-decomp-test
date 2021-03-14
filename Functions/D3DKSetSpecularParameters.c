unsigned int *__stdcall D3DK::SetSpecularParameters(unsigned int *pPush)
{
  unsigned int *v1; // esi
  float N; // ST18_4
  float n; // ST00_4
  double v4; // st7
  float v5; // ecx
  double v6; // st7
  float v7; // eax
  float v8; // ecx
  float M1; // [esp+1Ch] [ebp-10h]
  float L1; // [esp+20h] [ebp-Ch]
  float M; // [esp+24h] [ebp-8h]
  float power; // [esp+28h] [ebp-4h]

  v1 = pPush;
  power = D3DK::g_pDevice->m_Material.Power;
  XMETAL_PushCount((int *)D3DK::g_pDevice, pPush, 0x9E0u, 6u);
  D3DK::Explut((int *)D3DK::g_pDevice, power, (float *)&pPush, &M);
  N = *(float *)&pPush + 1.0 - M;
  n = power * 0.5;
  D3DK::Explut((int *)D3DK::g_pDevice, n, &L1, &M1);
  v4 = L1 + 1.0;
  v5 = M;
  v1[1] = (unsigned int)pPush;
  v6 = v4 - M1;
  v7 = L1;
  *((float *)v1 + 2) = v5;
  v8 = M1;
  *((float *)v1 + 6) = v6;
  *((float *)v1 + 3) = N;
  *((float *)v1 + 4) = v7;
  *((float *)v1 + 5) = v8;
  return v1 + 7;
}