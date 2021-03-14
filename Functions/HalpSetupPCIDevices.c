void __fastcall HalpSetupPCIDevices(int a1, int a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  int v26; // edx
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // edx
  int v43; // ecx
  int v44; // edx
  int v45; // ecx
  int v46; // edx
  int v47; // ecx
  int v48; // edx
  int v49; // ecx
  int v50; // edx
  int v51; // ecx
  int v52; // edx
  int v53; // ecx
  int v54; // edx
  int v55; // ecx
  int v56; // edx
  int v57; // ecx
  _PCI_COMMON_CONFIG Configuration; // [esp+Ch] [ebp-118h]
  unsigned int epgpclock; // [esp+10Ch] [ebp-18h]
  unsigned int agpcmd; // [esp+110h] [ebp-14h]
  unsigned int interrupt; // [esp+114h] [ebp-10h]
  unsigned int acicfg; // [esp+118h] [ebp-Ch]
  unsigned int mcpUsbCfg20Value; // [esp+11Ch] [ebp-8h]
  char pciint; // [esp+122h] [ebp-2h]
  char acpitimer; // [esp+123h] [ebp-1h]

  pciint = 3;
  HalReadWritePCISpace(a1, a2, 0, 1u, 0x6Au, &pciint, 1u, 1);
  interrupt = 235295889;
  HalReadWritePCISpace(v3, v2, 0, 1u, 0x6Cu, &interrupt, 4u, 1);
  interrupt = 2828;
  HalReadWritePCISpace(v5, v4, 0, 1u, 0x64u, &interrupt, 4u, 1);
  HalReadWritePCISpace(v7, v6, 0, 1u, 0x81u, &acpitimer, 1u, 0);
  acpitimer |= 8u;
  HalReadWritePCISpace(v9, v8, 0, 1u, 0x81u, &acpitimer, 1u, 1);
  HalReadWritePCISpace(v11, v10, 0, 9u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 5u;
  Configuration.ProgIf &= 0xFAu;
  Configuration.u.type0.BaseAddresses[4] = 65377;
  *(_DWORD *)&Configuration.DeviceSpecific[16] = 2;
  *(_DWORD *)&Configuration.DeviceSpecific[24] = 538976288;
  *(_DWORD *)&Configuration.DeviceSpecific[32] = -1061109568;
  HalReadWritePCISpace(v13, v12, 0, 9u, 0, &Configuration, 0x100u, 1);
  HalReadWritePCISpace(v15, v14, 0, 4u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  *(_QWORD *)Configuration.u.type0.BaseAddresses = 246299176730624i64;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 4;
  HalReadWritePCISpace(v17, v16, 0, 4u, 0, &Configuration, 0x100u, 1);
  HalReadWritePCISpace(v19, v18, 0, 2u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  Configuration.u.type0.BaseAddresses[0] = -19922944;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 1;
  HalReadWritePCISpace(v21, v20, 0, 2u, 0, &Configuration, 0x100u, 1);
  mcpUsbCfg20Value = 15;
  HalReadWritePCISpace(v23, v22, 0, 2u, 0x50u, &mcpUsbCfg20Value, 4u, 1);
  HalReadWritePCISpace(v25, v24, 0, 3u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  Configuration.u.type0.BaseAddresses[0] = -19890176;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 9;
  HalReadWritePCISpace(v27, v26, 0, 3u, 0, &Configuration, 0x100u, 1);
  mcpUsbCfg20Value = 48;
  HalReadWritePCISpace(v29, v28, 0, 3u, 0x50u, &mcpUsbCfg20Value, 4u, 1);
  HalReadWritePCISpace(v31, v30, 0, 6u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 6;
  *(_QWORD *)Configuration.u.type0.BaseAddresses = 230901736853505i64;
  Configuration.u.type0.BaseAddresses[2] = -20971520;
  HalReadWritePCISpace(v33, v32, 0, 6u, 0, &Configuration, 0x100u, 1);
  HalReadWritePCISpace(v35, v34, 0, 5u, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 5;
  Configuration.u.type0.BaseAddresses[0] = -25165824;
  HalReadWritePCISpace(v37, v36, 0, 5u, 0, &Configuration, 0x100u, 1);
  HalReadWritePCISpace(v39, v38, 0, 1u, 0x8Cu, &epgpclock, 4u, 0);
  epgpclock = epgpclock & 0xFBFFFFFF | 0x8000000;
  HalReadWritePCISpace(v41, v40, 0, 1u, 0x8Cu, &epgpclock, 4u, 1);
  LOWORD(v42) = -32563;
  __outbyte(0x80CDu, 8u);
  HalReadWritePCISpace(v43, v42, 0, 6u, 0x4Cu, &acicfg, 4u, 0);
  HIWORD(acicfg) |= 0x101u;
  HalReadWritePCISpace(v45, v44, 0, 6u, 0x4Cu, &acicfg, 4u, 1);
  HalReadWritePCISpace(v47, v46, 0, 0x1Eu, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  Configuration.u.type1.PrefetchLimit = ((XboxHardwareInfo.Flags & 8) << 7) | 0xF3F0;
  Configuration.u.type1.PrimaryBus = 0;
  *(_WORD *)&Configuration.u.type2.SecondaryBus = 257;
  Configuration.u.type0.BaseAddresses[4] = -26149632;
  Configuration.u.type1.PrefetchBase = -4096;
  HalReadWritePCISpace(v49, v48, 0, 0x1Eu, 0, &Configuration, 0x100u, 1);
  agpcmd = 276;
  HalReadWritePCISpace(v51, v50, 0, 0, 0x48u, &agpcmd, 4u, 1);
  HalReadWritePCISpace(v53, v52, 1u, 0, 0, &Configuration, 0x100u, 0);
  LOBYTE(Configuration.Command) |= 7u;
  *(_WORD *)&Configuration.u.type2.InterruptLine = 259;
  HalReadWritePCISpace(v55, v54, 1u, 0, 0, &Configuration, 0x100u, 1);
  agpcmd = 276;
  HalReadWritePCISpace(v57, v56, 1u, 0, 0x4Cu, &agpcmd, 4u, 1);
}