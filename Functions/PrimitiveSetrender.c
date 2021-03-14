// write access to const memory has been detected, the output may be wrong!
void __userpurge PrimitiveSet::render(PrimitiveSet *this@<ecx>, int *a2@<edi>, _D3DLIGHT8 *light, bool b_query_blob)
{
  PrimitiveSet *v4; // ebx
  ShaderTypes v5; // eax
  int v6; // eax
  int v7; // eax
  _D3DLIGHT8 *v8; // edi
  float v9; // eax
  _D3DMATRIX *v10; // eax
  bool v11; // zf
  bool v12; // sf
  int v13; // esi
  __int16 v14; // ax
  float *v15; // eax
  _D3DVECTOR v16; // ST08_12
  double v17; // st7
  ShaderTypes v18; // eax
  ShaderTypes v19; // eax
  _D3DMATRIX *v20; // eax
  PrimitiveVersionRecord *v21; // esi
  PrimitiveTypes v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-254h]
  _D3DMATRIX finalSMat; // [esp+Ch] [ebp-248h]
  _D3DMATRIX matTmp; // [esp+4Ch] [ebp-208h]
  _D3DMATRIX matOTS; // [esp+8Ch] [ebp-1C8h]
  _D3DMATRIX matFinal; // [esp+CCh] [ebp-188h]
  _D3DMATRIX inv_world_mat; // [esp+10Ch] [ebp-148h]
  _D3DMATRIX world_mat; // [esp+14Ch] [ebp-108h]
  _D3DMATRIX tmp; // [esp+18Ch] [ebp-C8h]
  D3DVECTOR4 vObjEyePos; // [esp+1CCh] [ebp-88h]
  _D3DVECTOR p_light_pos; // [esp+1DCh] [ebp-78h]
  float v34; // [esp+1E8h] [ebp-6Ch]
  D3DVECTOR4 vObjLightPos; // [esp+1ECh] [ebp-68h]
  _D3DMATRIX *matWTP; // [esp+1FCh] [ebp-58h]
  D3DVECTOR4 light_val[3]; // [esp+200h] [ebp-54h]
  D3DVECTOR4 vAtten; // [esp+230h] [ebp-24h]
  float fIntensity; // [esp+240h] [ebp-14h]
  int i; // [esp+244h] [ebp-10h]
  unsigned int v41; // [esp+248h] [ebp-Ch]
  int num_indices_in_cap; // [esp+24Ch] [ebp-8h]
  bool b_no_lighting; // [esp+253h] [ebp-1h]

  v4 = this;
  D3DDevice_SetStreamSource(a2, 0, this->pBaseStream, 0xCu);
  D3DDevice_SetIndices(a2, v4->pIB, 0);
  v5 = v4->shaderType;
  b_no_lighting = 0;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          b_no_lighting = 1;
          if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZWRITEENABLE, 1u) )
          {
            D3DDevice_SetRenderState_Simple(0, 0x4035Cu, 1u, (int *)1);
            dword_800C24C8 = 1;
          }
          if ( !D3DDevice_SetRenderState_ParameterCheck((int *)1, D3DRS_ZENABLE, 1u) )
            D3DDevice_SetRenderState_ZEnable((int *)1, 1u);
        }
      }
      else
      {
        b_no_lighting = 1;
      }
    }
    else
    {
      D3DDevice_SetTexture(0, (D3DBaseTexture *)&v4->pNormalMap->Common);
      D3DDevice_SetTexture(1u, (D3DBaseTexture *)&v4->pCubeMap->Common);
      D3DDevice_SetTexture(2u, (D3DBaseTexture *)&v4->pCubeMap->Common);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_MINFILTER, 3u) )
        D3DDevice_SetTextureState_Deferred(0, 0, 14, 3u);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_MAGFILTER, 3u) )
        D3DDevice_SetTextureState_Deferred(0, 0, 13, 3u);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_MIPFILTER, 0) )
        D3DDevice_SetTextureState_Deferred(0, 0, 15, 0);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_ADDRESSU, 1u) )
        D3DDevice_SetTextureState_Deferred(0, 0, 10, 1u);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_ADDRESSV, 1u) )
        D3DDevice_SetTextureState_Deferred(0, 0, 11, 1u);
      if ( !D3DDevice_SetTextureState_ParameterCheck((int *)1, 0, D3DTSS_ADDRESSW, 1u) )
        D3DDevice_SetTextureState_Deferred(0, 0, 12, 1u);
      D3DDevice_SetStreamSource((int *)1, 1u, v4->pExtraStream, 0x2Cu);
      D3DDevice_SetVertexShader((int *)1, 0);
      D3DDevice_SetPixelShader(0);
    }
  }
  else
  {
    D3DDevice_SetTexture(1u, (D3DBaseTexture *)&v4->pCubeMap->Common);
    D3DDevice_SetTexture(2u, (D3DBaseTexture *)&v4->pCubeMap->Common);
    D3DDevice_SetStreamSource(a2, 1u, v4->pExtraStream, 0x24u);
    D3DDevice_SetVertexShader(a2, 0);
    D3DDevice_SetPixelShader(0);
  }
  if ( b_query_blob || b_no_lighting )
  {
    v8 = light;
  }
  else
  {
    v8 = light;
    light_val[0].x = light->Ambient.r * v4->vAmbient.x;
    light_val[0].y = light->Ambient.g * v4->vAmbient.y;
    light_val[0].z = light->Ambient.b * v4->vAmbient.z;
    light_val[0].w = 1.0;
    light_val[1].x = v4->vDiffuse.x * light->Diffuse.r;
    light_val[1].y = v4->vDiffuse.y * light->Diffuse.g;
    light_val[1].z = v4->vDiffuse.z * light->Diffuse.b;
    light_val[1].w = 1.0;
    light_val[2].x = v4->vSpecular.x * light->Specular.r;
    light_val[2].y = v4->vSpecular.y * light->Specular.g;
    light_val[2].z = v4->vSpecular.z * light->Specular.b;
    light_val[2].w = 1.0;
    D3DDevice_SetPixelShaderConstant((int *)light, 0, light_val, 3u);
    v9 = light->Attenuation0;
    vAtten.w = 1.0;
    vAtten.x = v9;
    vAtten.y = light->Attenuation1;
    vAtten.z = light->Attenuation2;
    D3DDevice_SetVertexShaderConstant(7, &vAtten, 1u);
  }
  v10 = Camera::getWTP(&dword_8010BDA8);
  v11 = v4->nInstances == 0;
  v12 = v4->nInstances < 0;
  matWTP = v10;
  i = 0;
  if ( !v12 && !v11 )
  {
    v41 = 0;
    while ( 1 )
    {
      v13 = (int)&v4->aInstRecs[v41 / 0x11C];
      v12 = *(_WORD *)(v13 + 2) < 0;
      num_indices_in_cap = (int)&v4->aInstRecs[v41 / 0x11C];
      if ( v12 && *(_WORD *)(v13 + 4) < 0 )
      {
        qmemcpy(&world_mat, (const void *)(v13 + 216), sizeof(world_mat));
        qmemcpy(&inv_world_mat, (const void *)(num_indices_in_cap + 72), sizeof(inv_world_mat));
        v8 = light;
        v13 = num_indices_in_cap;
      }
      else
      {
        v14 = *(_WORD *)(v13 + 4);
        if ( v14 < 0 )
        {
          qmemcpy(&tmp, (const void *)(v13 + 8), sizeof(tmp));
          v8 = light;
          v13 = num_indices_in_cap;
        }
        else
        {
          MulMats((_D3DMATRIX *)(v13 + 8), (_D3DMATRIX *)(dword_8010C20C[0] + (v14 << 6)), &tmp);
        }
        if ( *(_WORD *)(v13 + 2) >= 0 )
        {
          v15 = (float *)(dword_8010C214[0] + 12 * *(signed __int16 *)(v13 + 2));
          tmp._41 = tmp._41 + *v15;
          tmp._42 = tmp._42 + v15[1];
          tmp._43 = tmp._43 + v15[2];
        }
        SetInverse(&tmp, &inv_world_mat);
        MulMats((_D3DMATRIX *)(v13 + 136), &tmp, &world_mat);
      }
      if ( v4->shaderType != 3 )
      {
        MulMats(&world_mat, matWTP, &matTmp);
        SetTranspose(&matTmp, &matFinal);
        D3DDevice_SetVertexShaderConstant(0, &matFinal, 4u);
        goto LABEL_43;
      }
      if ( *(_BYTE *)(v13 + 280) == v4->bHiZ )
        break;
LABEL_60:
      ++i;
      v41 += 284;
      if ( i >= v4->nInstances )
        return;
    }
    D3DDevice_SetTransform(D3DTS_WORLD, &world_mat);
LABEL_43:
    if ( !b_query_blob || b_no_lighting )
    {
      v18 = v4->shaderType;
      if ( v18 == 3 )
      {
LABEL_54:
        v21 = &v4->aVersRecs[v4->aInstRecs[v41 / 0x11C].idxVersion];
        v22 = v4->primitiveType;
        if ( v22 == 1 || v22 == 4 )
        {
          num_indices_in_cap = v21->dwParameter;
          v23 = num_indices_in_cap;
          if ( num_indices_in_cap )
          {
            D3DDevice_DrawIndexedVertices(D3DPT_TRIANGLEFAN, num_indices_in_cap, &D3D__IndexData[v21->dwIndexStart]);
            D3DDevice_DrawIndexedVertices(
              D3DPT_TRIANGLEFAN,
              num_indices_in_cap,
              &D3D__IndexData[num_indices_in_cap + v21->dwIndexStart]);
            v23 = num_indices_in_cap;
          }
          D3DDevice_DrawIndexedVertices(
            D3DPT_TRIANGLESTRIP,
            v21->dwIndexCount - 2 * v23,
            &D3D__IndexData[v21->dwIndexStart + 2 * v23]);
        }
        else
        {
          D3DDevice_DrawIndexedVertices(
            v4->d3dType,
            *(_DWORD *)(8 * v4->d3dType - 2146428516) + v21->dwPrimCount * *(_DWORD *)(8 * v4->d3dType - 2146428520),
            &D3D__IndexData[v21->dwIndexStart]);
        }
        goto LABEL_60;
      }
      if ( v18 != 2 )
        TransformPoint(&v8->Position, &inv_world_mat, (_D3DVECTOR *)&vObjLightPos.x);
    }
    else
    {
      v34 = 1.0;
      *(_QWORD *)&v16.x = *(_QWORD *)&world_mat.m[3][0];
      v16.z = world_mat._43;
      VBlob::getLightForPosition(&stru_8010C21C, &p_light_pos, &fIntensity, v16);
      fIntensity = 0.0 + 0.0;
      light_val[0].x = light->Ambient.r * v4->vAmbient.x * (0.0 + 0.0);
      light_val[0].y = light->Ambient.g * v4->vAmbient.y * (0.0 + 0.0);
      light_val[0].z = light->Ambient.b * v4->vAmbient.z * (0.0 + 0.0);
      light_val[0].w = 1.0;
      light_val[1].x = v4->vDiffuse.x * light->Diffuse.r * (0.0 + 0.0);
      light_val[1].y = v4->vDiffuse.y * light->Diffuse.g * (0.0 + 0.0);
      light_val[1].z = v4->vDiffuse.z * light->Diffuse.b * (0.0 + 0.0);
      light_val[1].w = 1.0;
      light_val[2].x = v4->vSpecular.x * light->Specular.r * (0.0 + 0.0);
      light_val[2].y = v4->vSpecular.y * light->Specular.g * (0.0 + 0.0);
      light_val[2].z = v4->vSpecular.z * light->Specular.b * (0.0 + 0.0);
      light_val[2].w = 1.0;
      D3DDevice_SetPixelShaderConstant(&v24, 0, light_val, 3u);
      TransformPoint((D3DVECTOR4 *)&p_light_pos, &inv_world_mat, &vObjLightPos);
      v17 = 1.0 / fIntensity;
      vAtten.x = light->Attenuation0;
      vAtten.y = v17 * light->Attenuation1;
      vAtten.z = v17 * light->Attenuation2;
      vAtten.w = 1.0;
      D3DDevice_SetVertexShaderConstant(7, &vAtten, 1u);
      v8 = light;
      v13 = num_indices_in_cap;
    }
    v19 = v4->shaderType;
    if ( v19 != 3 && v19 != 2 )
    {
      vObjLightPos.w = 1.0;
      D3DDevice_SetVertexShaderConstant(4, &vObjLightPos, 1u);
      TransformPoint(&pt, &inv_world_mat, (_D3DVECTOR *)&vObjEyePos.x);
      vObjEyePos.w = 1.0;
      D3DDevice_SetVertexShaderConstant(5, &vObjEyePos, 1u);
      D3DDevice_SetVertexShaderConstant(6, (const void *)(v13 + 200), 1u);
      v20 = &stru_8010C18C;
      if ( !*(_BYTE *)(v13 + 280) )
        v20 = (_D3DMATRIX *)dword_8010C1CC;
      MulMats(&world_mat, v20, &matOTS);
      SetTranspose(&matOTS, &finalSMat);
      D3DDevice_SetVertexShaderConstant(8, &finalSMat, 4u);
      *(_BYTE *)(v13 + 280);
      D3DDevice_SetTexture(3u, 0);
    }
    goto LABEL_54;
  }
}