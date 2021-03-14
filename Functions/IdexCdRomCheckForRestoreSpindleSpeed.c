char __userpurge IdexCdRomCheckForRestoreSpindleSpeed@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int StartingSectorNumber, unsigned int NumberOfSectors)
{
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // ecx

  v5 = IdexCdRomCurrentSpindleSpeed;
  v6 = 0;
  if ( IdexCdRomCurrentSpindleSpeed >= IdexCdRomMaximumSpindleSpeed )
  {
    RtlAssert(
      a1,
      a2,
      a3,
      0,
      "IdexCdRomCurrentSpindleSpeed < IdexCdRomMaximumSpindleSpeed",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x354u,
      0);
    v5 = IdexCdRomCurrentSpindleSpeed;
  }
  v7 = NumberOfSectors;
  if ( NumberOfSectors >= IdexCdRomSpindleSlowdownSectorsRemaining )
    IdexCdRomSpindleSlowdownSectorsRemaining = 0;
  else
    IdexCdRomSpindleSlowdownSectorsRemaining -= NumberOfSectors;
  if ( IdexCdRomSpindleSlowdownSectorsRemaining )
  {
    v7 = IdexCdRomSpindleSlowdownSectorNumber;
    if ( StartingSectorNumber >= IdexCdRomSpindleSlowdownSectorNumber )
    {
      v6 = IdexCdRomSpindleSlowdownSectorNumber + *(_DWORD *)(4 * v5 - 2147392740);
      if ( StartingSectorNumber < v6 )
        return 0;
    }
  }
  IdexCdRomSpindleSlowdownSectorNumber = StartingSectorNumber;
  IdexCdRomSetSpindleSpeed(StartingSectorNumber, v7, a3, v6, v5 + 1, IdexChannelRestartCurrentPacket);
  return 1;
}