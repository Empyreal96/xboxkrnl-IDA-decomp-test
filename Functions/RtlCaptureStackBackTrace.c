unsigned __int16 __userpurge RtlCaptureStackBackTrace@<ax>(int a1@<edi>, unsigned int FramesToSkip, unsigned int FramesToCapture, void **BackTrace, unsigned int *BackTraceHash)
{
  unsigned int v5; // esi
  unsigned int v6; // eax
  int v7; // ST0C_4
  unsigned int v8; // edi
  void **v9; // edx
  int v11; // [esp+0h] [ebp-108h]
  int v12; // [esp+4h] [ebp-104h]
  void *Trace[64]; // [esp+8h] [ebp-100h]
  unsigned int FramesFound; // [esp+110h] [ebp+8h]

  v5 = FramesToSkip + 1;
  if ( FramesToSkip + 1 + FramesToCapture < 0x40 )
  {
    v7 = a1;
    v8 = 0;
    FramesFound = RtlWalkFrameChain(
                    Trace,
                    FramesToSkip + 1 + FramesToCapture,
                    0,
                    v7,
                    v11,
                    v12,
                    (int)Trace[0],
                    (int)Trace[1],
                    (int)Trace[2],
                    (int)Trace[3],
                    (int)Trace[4],
                    (int)Trace[5],
                    (int)Trace[6],
                    (int)Trace[7],
                    (int)Trace[8],
                    (int)Trace[9],
                    (int)Trace[10],
                    (int)Trace[11],
                    (int)Trace[12],
                    (int)Trace[13],
                    (int)Trace[14],
                    (int)Trace[15],
                    (int)Trace[16],
                    (int)Trace[17],
                    (int)Trace[18],
                    (int)Trace[19],
                    (int)Trace[20],
                    (int)Trace[21],
                    (int)Trace[22],
                    (int)Trace[23],
                    (int)Trace[24],
                    (int)Trace[25],
                    (int)Trace[26],
                    (int)Trace[27],
                    (int)Trace[28],
                    (int)Trace[29],
                    (int)Trace[30],
                    (int)Trace[31],
                    (int)Trace[32],
                    (int)Trace[33],
                    (int)Trace[34],
                    (int)Trace[35],
                    (int)Trace[36],
                    (int)Trace[37],
                    (int)Trace[38],
                    (int)Trace[39],
                    (int)Trace[40],
                    (int)Trace[41],
                    (int)Trace[42],
                    (int)Trace[43],
                    (int)Trace[44],
                    (int)Trace[45],
                    (int)Trace[46],
                    (int)Trace[47],
                    (int)Trace[48],
                    (int)Trace[49],
                    (int)Trace[50],
                    (int)Trace[51],
                    (int)Trace[52],
                    (int)Trace[53],
                    (int)Trace[54],
                    (int)Trace[55],
                    (int)Trace[56]);
    if ( FramesFound > v5 )
    {
      v6 = 0;
      if ( FramesToCapture > 0 )
      {
        v9 = &Trace[v5];
        do
        {
          if ( v6 + v5 >= FramesFound )
            break;
          v8 += (unsigned int)*v9;
          BackTrace[v6++] = *v9;
          ++v9;
        }
        while ( v6 < FramesToCapture );
      }
      *BackTraceHash = v8;
    }
    else
    {
      LOWORD(v6) = 0;
    }
  }
  else
  {
    LOWORD(v6) = 0;
  }
  return v6;
}