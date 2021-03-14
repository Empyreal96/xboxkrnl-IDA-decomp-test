int __stdcall D3DK::Inverse4x4(_D3DMATRIX *inverse, _D3DMATRIX *src, int bNormalize)
{
  double v3; // st7
  double v4; // st6
  float v5; // ST50_4
  float x10; // ST30_4
  float v7; // ST4C_4
  float x20; // ST34_4
  float v9; // ecx
  float v10; // ST54_4
  float y12; // ST2C_4
  float v12; // edx
  float v13; // ST38_4
  float v14; // ST48_4
  float v15; // ST44_4
  float v16; // ST40_4
  float y02; // ST28_4
  double v18; // st7
  double v19; // st6
  double v20; // st4
  float v21; // ST50_4
  double v22; // st5
  double v23; // st4
  double v24; // st3
  float v25; // ST4C_4
  float v26; // ST54_4
  double v27; // st4
  double v28; // st7
  double v29; // st6
  double v30; // st5
  float v31; // ST2C_4
  float v32; // ST28_4
  float v33; // ST30_4
  float v34; // edx
  float v35; // ST34_4
  float v36; // ST3C_4
  double v37; // st4
  double v38; // st3
  double v39; // st2
  float v40; // eax
  double v41; // st7
  float x; // ST00_4
  float x00; // ST24_4
  int v45; // ecx
  float z33; // [esp+4h] [ebp-54h]
  float z32; // [esp+8h] [ebp-50h]
  float z23; // [esp+Ch] [ebp-4Ch]
  float z22; // [esp+10h] [ebp-48h]
  float z13; // [esp+14h] [ebp-44h]
  float z12; // [esp+18h] [ebp-40h]
  float z03; // [esp+1Ch] [ebp-3Ch]
  float z02; // [esp+20h] [ebp-38h]
  float x02; // [esp+38h] [ebp-20h]
  float y23; // [esp+3Ch] [ebp-1Ch]
  float x32; // [esp+40h] [ebp-18h]
  float x22; // [esp+44h] [ebp-14h]
  float x12; // [esp+48h] [ebp-10h]
  float x21; // [esp+4Ch] [ebp-Ch]
  float x11; // [esp+50h] [ebp-8h]
  float x31; // [esp+54h] [ebp-4h]
  float rcp; // [esp+64h] [ebp+Ch]
  float rcpa; // [esp+64h] [ebp+Ch]

  v3 = src->_11;
  v4 = src->_12;
  v5 = src->_22;
  x10 = src->_21;
  v7 = src->_32;
  x20 = src->_31;
  v9 = src->_41;
  v10 = src->_42;
  y12 = v5 * v3 - x10 * v4;
  v12 = src->_14;
  v13 = src->_13;
  v14 = src->_23;
  v15 = src->_33;
  v16 = src->_43;
  y02 = v7 * v3 - x20 * v4;
  v18 = v3 * v10 - v9 * v4;
  v19 = v7 * x10 - x20 * v5;
  v20 = v9 * v5;
  v21 = src->_24;
  v22 = v10 * x10 - v20;
  v23 = v10 * x20;
  v24 = v9 * v7;
  v25 = src->_34;
  v26 = src->_44;
  v27 = v23 - v24;
  z33 = v13 * v19 - v14 * y02 + v15 * y12;
  z23 = v14 * v18 - v16 * y12 - v13 * v22;
  z13 = v13 * v27 - v15 * v18 + v16 * y02;
  z03 = v15 * v22 - v16 * v19 - v14 * v27;
  z32 = y02 * v21 - y12 * v25 - v19 * v12;
  z22 = v22 * v12 - v18 * v21 + y12 * v26;
  z12 = v18 * v25 - y02 * v26 - v27 * v12;
  z02 = v27 * v21 - v22 * v25 + v19 * v26;
  v28 = v13 * v21 - v14 * v12;
  v29 = v13 * v25 - v15 * v12;
  v30 = v13 * v26 - v16 * v12;
  v31 = v14 * v25 - v15 * v21;
  v32 = v14 * v26 - v16 * v21;
  v33 = src->_21;
  v34 = src->_41;
  v35 = src->_31;
  v36 = v15 * v26 - v16 * v25;
  v37 = src->_12;
  v38 = src->_22;
  v39 = src->_32;
  v40 = src->_42;
  x32 = v29 * v38 - v28 * v39 - v31 * v37;
  x22 = v32 * v37 - v30 * v38 + v28 * v40;
  x12 = v30 * v39 - v29 * v40 - v36 * v37;
  x02 = v36 * v38 - v32 * v39 + v31 * v40;
  x31 = v31 * src->_11 - v29 * v33 + v28 * v35;
  x21 = v33 * v30 - v28 * v34 - v32 * src->_11;
  x11 = v36 * src->_11 - v30 * v35 + v29 * v34;
  y23 = v32 * v35 - v31 * v34 - v36 * v33;
  v41 = x32 * v34 + x22 * v35 + x12 * v33 + x02 * src->_11;
  rcp = v41;
  if ( v41 == 0.0 )
    return -1;
  if ( bNormalize )
  {
    x = rcp * rcp;
    x00 = D3DK::JBInvSqrt(x);
    LODWORD(rcpa) = LODWORD(x00) | v45 & 0x80000000;
    inverse->_11 = rcpa * x02;
    inverse->_21 = rcpa * y23;
    inverse->_12 = rcpa * x12;
    inverse->_31 = rcpa * z02;
    inverse->_13 = rcpa * x22;
    inverse->_41 = rcpa * z03;
    inverse->_14 = rcpa * x32;
    inverse->_22 = rcpa * x11;
    inverse->_32 = rcpa * z12;
    inverse->_23 = rcpa * x21;
    inverse->_42 = rcpa * z13;
    inverse->_24 = rcpa * x31;
    inverse->_33 = rcpa * z22;
    inverse->_43 = rcpa * z23;
    inverse->_34 = rcpa * z32;
    inverse->_44 = rcpa * z33;
  }
  else
  {
    LODWORD(inverse->_11) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x02);
    LODWORD(inverse->_21) = LODWORD(rcp) & 0x80000000 ^ LODWORD(y23);
    LODWORD(inverse->_12) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x12);
    LODWORD(inverse->_31) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z02);
    LODWORD(inverse->_13) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x22);
    LODWORD(inverse->_41) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z03);
    LODWORD(inverse->_14) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x32);
    LODWORD(inverse->_22) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x11);
    LODWORD(inverse->_32) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z12);
    LODWORD(inverse->_23) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x21);
    LODWORD(inverse->_42) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z13);
    LODWORD(inverse->_24) = LODWORD(rcp) & 0x80000000 ^ LODWORD(x31);
    LODWORD(inverse->_33) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z22);
    LODWORD(inverse->_43) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z23);
    LODWORD(inverse->_34) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z32);
    LODWORD(inverse->_44) = LODWORD(rcp) & 0x80000000 ^ LODWORD(z33);
  }
  return 0;
}