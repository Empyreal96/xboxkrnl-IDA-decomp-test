void __fastcall PrimitiveSet::create(PrimitiveSet *this, int a2, const void *version_data, int num_versions, const void *instance_data, int num_insts, int ndet_bias, ShaderTypes shader, PrimitiveTypes primitive, D3DTexture *pnormal_map, D3DCubeTexture *pcube_map)
{
  int v11; // eax
  PrimitiveSet *v12; // esi
  PrimitiveTypes v13; // ecx
  D3DCubeTexture *v14; // ecx
  int *v15; // edi
  unsigned int v16; // edx
  int v17; // ecx
  bool v18; // zf
  bool v19; // sf
  int v20; // eax
  int v21; // edi
  PrimitiveTypes v22; // ecx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  int v27; // edi
  ShaderTypes v28; // eax
  unsigned int v29; // edi
  int v30; // edx
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  unsigned __int16 *v34; // ebx
  int v35; // edi
  PrimitiveTypes v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int *v42; // eax
  unsigned int v43; // edx
  int v44; // eax
  int v45; // ebx
  SurfOfRevInst *v46; // edi
  PrimitiveTypes v47; // ecx
  int v48; // ecx
  int v49; // ecx
  int v50; // ecx
  int v51; // ecx
  signed int v52; // eax

  v11 = num_versions;
  v12 = this;
  this->nInstances = num_insts;
  this->shaderType = shader;
  v13 = primitive;
  v12->nVersions = v11;
  v12->primitiveType = v13;
  v12->pNormalMap = pnormal_map;
  v14 = pcube_map;
  v12->pCubeMap = pcube_map;
  v15 = MemAlloc(a2, (int)v14, (int)v12, 24 * v11);
  v16 = 24 * v12->nVersions;
  v12->aVersRecs = (PrimitiveVersionRecord *)v15;
  memset(v15, 0, v16);
  v17 = 0;
  v18 = v12->nVersions == 0;
  v19 = v12->nVersions < 0;
  primitive = 0;
  pnormal_map = 0;
  shader = 0;
  if ( !v19 && !v18 )
  {
    v20 = 0;
    do
    {
      v21 = v20;
      v12->aVersRecs[v21].dwVertexStart = v17;
      v12->aVersRecs[v21].dwIndexStart = (unsigned int)pnormal_map;
      v22 = v12->primitiveType;
      if ( v22 )
      {
        v23 = v22 - 1;
        if ( v23 )
        {
          v24 = v23 - 1;
          if ( v24 )
          {
            v25 = v24 - 1;
            if ( v25 )
            {
              v26 = v25 - 1;
              if ( v26 )
              {
                if ( v26 == 1 )
                  PrimitiveSet::initSurfOfRevVersion(v12, (SurfOfRevVers *)version_data + v20, v20, ndet_bias);
              }
              else
              {
                PrimitiveSet::initConeVersion(v12, (ConeVers *)version_data + v20, v20, ndet_bias);
              }
            }
            else
            {
              PrimitiveSet::initTorusVersion(v12, (TorusVers *)version_data + v20, v20, ndet_bias);
            }
          }
          else
          {
            PrimitiveSet::initBoxVersion(v12, v20);
          }
        }
        else
        {
          PrimitiveSet::initCylinderVersion(v12, (CylinderVers *)version_data + v20, v20, ndet_bias);
        }
      }
      else
      {
        PrimitiveSet::initSphereVersion(v12, (SphereVers *)version_data + v20, v20, ndet_bias);
      }
      v27 = (int)&v12->aVersRecs[v21];
      primitive += *(_DWORD *)(v27 + 4);
      pnormal_map = (D3DTexture *)((char *)pnormal_map + *(_DWORD *)(v27 + 16));
      v20 = (unsigned __int16)++shader;
      v17 = primitive;
    }
    while ( (unsigned __int16)shader < v12->nVersions );
  }
  v28 = v12->shaderType;
  pcube_map = 0;
  if ( v28 )
  {
    if ( v28 == 1 )
      pcube_map = (D3DCubeTexture *)44;
  }
  else
  {
    pcube_map = (D3DCubeTexture *)36;
  }
  v29 = 12 * v17;
  D3DDevice_CreateVertexBuffer((int *)(12 * v17), v17, (int)v12, 12 * v17, 0, 0, 0, &v12->pBaseStream);
  shader = primitive * (_DWORD)pcube_map;
  D3DDevice_CreateVertexBuffer(
    (int *)v29,
    (int)&v12->pExtraStream,
    (int)v12,
    primitive * (_DWORD)pcube_map,
    0,
    0,
    0,
    &v12->pExtraStream);
  D3DDevice_CreateIndexBuffer(v30, v31, (int)v12, 2 * (_DWORD)pnormal_map, 0, D3DFMT_INDEX16, 0, &v12->pIB);
  D3DVertexBuffer_Lock((int *)v29, v12->pBaseStream, 0, v29, (char **)&num_versions, 0);
  D3DVertexBuffer_Lock((int *)v29, v12->pExtraStream, 0, shader, (char **)&num_insts, 0);
  v34 = (unsigned __int16 *)v12->pIB->Data;
  v35 = 0;
  v18 = v12->nVersions == 0;
  v19 = v12->nVersions < 0;
  shader = 0;
  if ( !v19 && !v18 )
  {
    do
    {
      v36 = v12->primitiveType;
      if ( v36 )
      {
        v37 = v36 - 1;
        if ( v37 )
        {
          v38 = v37 - 1;
          if ( v38 )
          {
            v39 = v38 - 1;
            if ( v39 )
            {
              v40 = v39 - 1;
              if ( v40 )
              {
                if ( v40 == 1 )
                  PrimitiveSet::createSurfOfRevVersion(
                    v12,
                    (SurfOfRevVers *)version_data + v35,
                    (char *)num_versions,
                    (char *)num_insts,
                    v34,
                    v35,
                    ndet_bias);
              }
              else
              {
                PrimitiveSet::createConeVersion(
                  v12,
                  v32,
                  (ConeVers *)version_data + v35,
                  (char *)num_versions,
                  (char *)num_insts,
                  v34,
                  v35,
                  ndet_bias);
              }
            }
            else
            {
              PrimitiveSet::createTorusVersion(
                v12,
                (TorusVers *)version_data + v35,
                (char *)num_versions,
                (char *)num_insts,
                v34,
                v35,
                ndet_bias);
            }
          }
          else
          {
            PrimitiveSet::createBoxVersion(v12, (char *)num_versions, (char *)num_insts, v34, v35);
          }
        }
        else
        {
          PrimitiveSet::createCylinderVersion(
            v12,
            v32,
            (CylinderVers *)version_data + v35,
            (char *)num_versions,
            (char *)num_insts,
            v34,
            v35,
            ndet_bias);
        }
      }
      else
      {
        PrimitiveSet::createSphereVersion(
          v12,
          (SphereVers *)version_data + v35,
          (char *)num_versions,
          (char *)num_insts,
          v34,
          v35,
          ndet_bias);
      }
      v32 = num_versions;
      v41 = (int)&v12->aVersRecs[v35];
      num_versions += 12 * *(_DWORD *)(v41 + 4);
      v33 = (_DWORD)pcube_map * *(_DWORD *)(v41 + 4);
      num_insts += v33;
      v35 = (unsigned __int16)++shader;
      v34 += *(_DWORD *)(v41 + 16);
    }
    while ( (unsigned __int16)shader < v12->nVersions );
  }
  v42 = MemAlloc(v32, v33, (int)v12, 284 * v12->nInstances);
  v43 = 284 * v12->nInstances;
  v12->aInstRecs = (PrimitiveInstanceRecord *)v42;
  memset(v42, 0, v43);
  v44 = 0;
  v45 = 0;
  if ( v12->nInstances > 0 )
  {
    v46 = (SurfOfRevInst *)instance_data;
    do
    {
      v47 = v12->primitiveType;
      if ( v47 )
      {
        v48 = v47 - 1;
        if ( v48 )
        {
          v49 = v48 - 1;
          if ( v49 )
          {
            v50 = v49 - 1;
            if ( v50 )
            {
              v51 = v50 - 1;
              if ( v51 )
              {
                if ( v51 == 1 )
                  PrimitiveSet::initConeInstance(v12, &v46[v44], v44);
              }
              else
              {
                PrimitiveSet::initConeInstance(v12, &v46[v44], v44);
              }
            }
            else
            {
              PrimitiveSet::initTorusInstance(v12, (TorusInst *)v46 + v44, v44);
            }
          }
          else
          {
            PrimitiveSet::initBoxInstance(v12, (BoxInst *)&v46[2 * v44], v44);
          }
        }
        else
        {
          PrimitiveSet::initCylinderInstance(v12, (CylinderInst *)v46 + v44, v44);
        }
      }
      else
      {
        PrimitiveSet::initSphereInstance(v12, (SphereInst *)v46 + v44, v44);
      }
      v44 = (unsigned __int16)++v45;
    }
    while ( (unsigned __int16)v45 < v12->nInstances );
  }
  v52 = v12->primitiveType;
  if ( v52 >= 0 )
  {
    if ( v52 <= 1 )
      goto LABEL_59;
    if ( v52 == 2 )
    {
      v12->d3dType = 5;
      goto LABEL_55;
    }
    if ( v52 > 2 && v52 <= 5 )
LABEL_59:
      v12->d3dType = 6;
  }
LABEL_55:
  v12->vAmbient.x = 0.2079;
  v12->vAmbient.y = 1.0;
  v12->vAmbient.z = 0.1;
  v12->vAmbient.w = 1.0;
  v12->vDiffuse.x = 0.2079;
  v12->vDiffuse.y = 1.0;
  v12->vDiffuse.z = 0.1;
  v12->vDiffuse.w = 1.0;
  v12->vSpecular.x = 0.2079;
  v12->vSpecular.y = 1.0;
  v12->vSpecular.z = 0.1;
  v12->vSpecular.w = 1.0;
}