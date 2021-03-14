int __stdcall SHATransform(int *a1, unsigned int *a2)
{
  unsigned int *v2; // edx
  signed int v3; // esi
  char *v4; // ecx
  unsigned int v5; // eax
  int *v6; // ecx
  signed int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // ecx
  int v13; // edx
  int v14; // ebp
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  int v18; // edx
  int v19; // ebp
  int v20; // edi
  int v21; // ecx
  int v22; // esi
  int v23; // edx
  int v24; // ebx
  int v25; // ebp
  int v26; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // ebx
  int v30; // edi
  int v31; // ebp
  int v32; // eax
  int v33; // edx
  int v34; // esi
  int v35; // edi
  int v36; // ecx
  int v37; // ebp
  int v38; // edx
  int v39; // ebx
  int v40; // esi
  int v41; // ecx
  int v42; // eax
  int v43; // ebp
  int v44; // ebx
  int v45; // edi
  int v46; // esi
  int v47; // eax
  int v48; // edx
  int v49; // ebp
  int v50; // edi
  int v51; // ecx
  int v52; // esi
  int v53; // edx
  int v54; // ebx
  int v55; // ebp
  int v56; // ecx
  int v57; // eax
  int v58; // esi
  int v59; // ebx
  int v60; // edi
  int v61; // ebp
  int v62; // eax
  int v63; // edx
  int v64; // esi
  int v65; // edi
  int v66; // ecx
  int v67; // ebp
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // ecx
  int v72; // eax
  int v73; // ebp
  int v74; // ebx
  int v75; // edi
  int v76; // ebp
  int v77; // eax
  int v78; // edx
  int v79; // ebp
  int v80; // edi
  int v81; // ecx
  int v82; // ebp
  int v83; // edx
  int v84; // ebx
  int v85; // ebp
  int v86; // ecx
  int v87; // eax
  int v88; // ebp
  int v89; // ebx
  int v90; // edi
  int v91; // ebp
  int v92; // eax
  int v93; // edx
  int v94; // ebp
  int v95; // edi
  int v96; // ecx
  int v97; // ebp
  int v98; // edx
  int v99; // ebx
  int v100; // ebp
  int v101; // ecx
  int v102; // eax
  int v103; // ebp
  int v104; // ebx
  int v105; // edi
  int v106; // ebp
  int v107; // eax
  int v108; // edx
  int v109; // ebp
  int v110; // edi
  int v111; // ecx
  int v112; // ebp
  int v113; // edx
  int v114; // ebx
  int v115; // ebp
  int v116; // ecx
  int v117; // eax
  int v118; // ebp
  int v119; // ebx
  int v120; // edi
  int v121; // ebp
  int v122; // eax
  int v123; // edx
  int v124; // ebp
  int v125; // edi
  int v126; // ecx
  int v127; // ebp
  int v128; // edx
  int v129; // ebx
  int v130; // ebp
  int v131; // ecx
  int v132; // eax
  int v133; // ebp
  int v134; // esi
  int v135; // ebx
  int v136; // edi
  int v137; // ebp
  int v138; // esi
  int v139; // eax
  int v140; // edx
  int v141; // ebp
  int v142; // esi
  int v143; // edi
  int v144; // ecx
  int v145; // ebp
  int v146; // esi
  int v147; // edx
  int v148; // ebx
  int v149; // ebp
  int v150; // esi
  int v151; // ecx
  int v152; // eax
  int v153; // ebp
  int v154; // esi
  int v155; // ebx
  int v156; // edi
  int v157; // ebp
  int v158; // esi
  int v159; // eax
  int v160; // edx
  int v161; // ebp
  int v162; // esi
  int v163; // edi
  int v164; // ecx
  int v165; // ebp
  int v166; // esi
  int v167; // edx
  int v168; // ebx
  int v169; // ebp
  int v170; // esi
  int v171; // ecx
  int v172; // eax
  int v173; // ebp
  int v174; // esi
  int v175; // ebx
  int v176; // edi
  int v177; // ebp
  int v178; // esi
  int v179; // eax
  int v180; // edx
  int v181; // ebp
  int v182; // esi
  int v183; // edi
  int v184; // ecx
  int v185; // ebp
  int v186; // esi
  int v187; // edx
  int v188; // ebx
  int v189; // ebp
  int v190; // esi
  int v191; // ecx
  int v192; // eax
  int v193; // ebp
  int v194; // esi
  int v195; // ebx
  int v196; // edi
  int v197; // ebp
  int v198; // esi
  int v199; // eax
  int v200; // edx
  int v201; // ebp
  int v202; // esi
  int v203; // edi
  int v204; // ecx
  int v205; // ebp
  int v206; // esi
  int v207; // edx
  int v208; // ebx
  int v209; // ebp
  int v210; // esi
  int v211; // ecx
  int v212; // eax
  int v213; // ebp
  int v214; // ebx
  int v215; // edi
  int v216; // ebp
  int v217; // eax
  int v218; // edx
  int v219; // ebp
  int v220; // edi
  int v221; // ecx
  int v222; // ebp
  int v223; // edx
  int v224; // ebx
  int v225; // ebp
  int v226; // ecx
  int v227; // eax
  int v228; // ebp
  int v229; // ebx
  int v230; // edi
  int v231; // ebp
  int v232; // eax
  int v233; // edx
  int v234; // ebp
  int v235; // edi
  int v236; // ecx
  int v237; // ebp
  int v238; // edx
  int v239; // ebx
  int v240; // ebp
  int v241; // ecx
  int v242; // eax
  int v243; // ebp
  int v244; // ebx
  int v245; // edi
  int v246; // ebp
  int v247; // eax
  int v248; // edx
  int v249; // ebp
  int v250; // edi
  int v251; // ecx
  int v252; // ebp
  int v253; // edx
  int v254; // ebx
  int v255; // ebp
  int v256; // ecx
  int v257; // eax
  int v258; // ebp
  int v259; // ebx
  int v260; // edi
  int v261; // ebp
  int v262; // eax
  int v263; // edx
  int v264; // ebp
  int v265; // edi
  int v266; // ecx
  int v267; // ebp
  int v268; // edx
  int v269; // ebx
  int result; // eax
  int v271; // ebx
  int v272; // ecx
  int v273; // edx
  int v274; // ebp
  char v275; // [esp+0h] [ebp-154h]
  int v276; // [esp+4h] [ebp-150h]
  int v277; // [esp+8h] [ebp-14Ch]
  int v278; // [esp+Ch] [ebp-148h]
  int v279; // [esp+10h] [ebp-144h]
  int v280; // [esp+14h] [ebp-140h]
  int v281; // [esp+18h] [ebp-13Ch]
  int v282; // [esp+1Ch] [ebp-138h]
  int v283; // [esp+20h] [ebp-134h]
  int v284; // [esp+24h] [ebp-130h]
  int v285; // [esp+28h] [ebp-12Ch]
  int v286; // [esp+2Ch] [ebp-128h]
  int v287; // [esp+30h] [ebp-124h]
  int v288; // [esp+34h] [ebp-120h]
  int v289; // [esp+38h] [ebp-11Ch]
  int v290; // [esp+3Ch] [ebp-118h]
  int v291; // [esp+40h] [ebp-114h]
  int v292; // [esp+44h] [ebp-110h]
  int v293; // [esp+48h] [ebp-10Ch]
  int v294; // [esp+4Ch] [ebp-108h]
  int v295; // [esp+50h] [ebp-104h]
  int v296; // [esp+54h] [ebp-100h]
  int v297; // [esp+58h] [ebp-FCh]
  int v298; // [esp+5Ch] [ebp-F8h]
  int v299; // [esp+60h] [ebp-F4h]
  int v300; // [esp+64h] [ebp-F0h]
  int v301; // [esp+68h] [ebp-ECh]
  int v302; // [esp+6Ch] [ebp-E8h]
  int v303; // [esp+70h] [ebp-E4h]
  int v304; // [esp+74h] [ebp-E0h]
  int v305; // [esp+78h] [ebp-DCh]
  int v306; // [esp+7Ch] [ebp-D8h]
  int v307; // [esp+80h] [ebp-D4h]
  int v308; // [esp+84h] [ebp-D0h]
  int v309; // [esp+88h] [ebp-CCh]
  int v310; // [esp+8Ch] [ebp-C8h]
  int v311; // [esp+90h] [ebp-C4h]
  int v312; // [esp+94h] [ebp-C0h]
  int v313; // [esp+98h] [ebp-BCh]
  int v314; // [esp+9Ch] [ebp-B8h]
  int v315; // [esp+A0h] [ebp-B4h]
  int v316; // [esp+A4h] [ebp-B0h]
  int v317; // [esp+A8h] [ebp-ACh]
  int v318; // [esp+ACh] [ebp-A8h]
  int v319; // [esp+B0h] [ebp-A4h]
  int v320; // [esp+B4h] [ebp-A0h]
  int v321; // [esp+B8h] [ebp-9Ch]
  int v322; // [esp+BCh] [ebp-98h]
  int v323; // [esp+C0h] [ebp-94h]
  int v324; // [esp+C4h] [ebp-90h]
  int v325; // [esp+C8h] [ebp-8Ch]
  int v326; // [esp+CCh] [ebp-88h]
  int v327; // [esp+D0h] [ebp-84h]
  int v328; // [esp+D4h] [ebp-80h]
  int v329; // [esp+D8h] [ebp-7Ch]
  int v330; // [esp+DCh] [ebp-78h]
  int v331; // [esp+E0h] [ebp-74h]
  int v332; // [esp+E4h] [ebp-70h]
  int v333; // [esp+E8h] [ebp-6Ch]
  int v334; // [esp+ECh] [ebp-68h]
  int v335; // [esp+F0h] [ebp-64h]
  int v336; // [esp+F4h] [ebp-60h]
  int v337; // [esp+F8h] [ebp-5Ch]
  int v338; // [esp+FCh] [ebp-58h]
  int v339; // [esp+100h] [ebp-54h]
  int v340; // [esp+104h] [ebp-50h]
  int v341; // [esp+108h] [ebp-4Ch]
  int v342; // [esp+10Ch] [ebp-48h]
  int v343; // [esp+110h] [ebp-44h]
  int v344; // [esp+114h] [ebp-40h]
  int v345; // [esp+118h] [ebp-3Ch]
  int v346; // [esp+11Ch] [ebp-38h]
  int v347; // [esp+120h] [ebp-34h]
  int v348; // [esp+124h] [ebp-30h]
  int v349; // [esp+128h] [ebp-2Ch]
  int v350; // [esp+12Ch] [ebp-28h]
  int v351; // [esp+130h] [ebp-24h]
  int v352; // [esp+134h] [ebp-20h]
  int v353; // [esp+138h] [ebp-1Ch]
  int v354; // [esp+13Ch] [ebp-18h]
  int v355; // [esp+140h] [ebp-14h]

  v2 = a2;
  v3 = 16;
  v4 = &v275;
  do
  {
    v5 = *v2;
    v4 += 4;
    ++v2;
    *(_DWORD *)v4 = _byteswap_ulong(v5);
    --v3;
  }
  while ( v3 );
  v6 = &v278;
  v7 = 32;
  do
  {
    v8 = v6[7] ^ v6[1] ^ *(v6 - 1);
    v9 = v6[12];
    v10 = v6[11] ^ v6[6] ^ *v6 ^ *(v6 - 2);
    v6 += 2;
    v6[12] = __ROL4__(v10, 1);
    --v7;
    v6[13] = __ROL4__(v9 ^ v8, 1);
  }
  while ( v7 );
  v11 = a1[1];
  v12 = a1[2];
  v13 = a1[3];
  v14 = v11 & (v13 ^ a1[2]);
  v15 = __ROR4__(__ROR4__(v11, 1), 1);
  v16 = (v13 ^ v14) + v276 + __ROL4__(*a1, 5) + a1[4] + 1518500249;
  v17 = __ROR4__(__ROR4__(*a1, 1), 1);
  v18 = (v12 ^ *a1 & (v12 ^ v15)) + v277 + __ROL4__(v16, 5) + v13 + 1518500249;
  v19 = v16 & (v15 ^ v17);
  v20 = __ROR4__(__ROR4__(v16, 1), 1);
  v21 = (v15 ^ v19) + v278 + __ROL4__(v18, 5) + v12 + 1518500249;
  v22 = v18 & (v17 ^ v20);
  v23 = __ROR4__(__ROR4__(v18, 1), 1);
  v24 = (v17 ^ v22) + v279 + __ROL4__(v21, 5) + v15 + 1518500249;
  v25 = v21 & (v20 ^ v23);
  v26 = __ROR4__(__ROR4__(v21, 1), 1);
  v27 = (v20 ^ v25) + v280 + __ROL4__(v24, 5) + v17 + 1518500249;
  v28 = v24 & (v23 ^ v26);
  v29 = __ROR4__(__ROR4__(v24, 1), 1);
  v30 = (v23 ^ v28) + v281 + __ROL4__(v27, 5) + v20 + 1518500249;
  v31 = v27 & (v26 ^ v29);
  v32 = __ROR4__(__ROR4__(v27, 1), 1);
  v33 = (v26 ^ v31) + v282 + __ROL4__(v30, 5) + v23 + 1518500249;
  v34 = v30 & (v29 ^ v32);
  v35 = __ROR4__(__ROR4__(v30, 1), 1);
  v36 = (v29 ^ v34) + v283 + __ROL4__(v33, 5) + v26 + 1518500249;
  v37 = v33 & (v32 ^ v35);
  v38 = __ROR4__(__ROR4__(v33, 1), 1);
  v39 = (v32 ^ v37) + v284 + __ROL4__(v36, 5) + v29 + 1518500249;
  v40 = v36 & (v35 ^ v38);
  v41 = __ROR4__(__ROR4__(v36, 1), 1);
  v42 = (v35 ^ v40) + v285 + __ROL4__(v39, 5) + v32 + 1518500249;
  v43 = v39 & (v38 ^ v41);
  v44 = __ROR4__(__ROR4__(v39, 1), 1);
  v45 = (v38 ^ v43) + v286 + __ROL4__(v42, 5) + v35 + 1518500249;
  v46 = v42 & (v41 ^ v44);
  v47 = __ROR4__(__ROR4__(v42, 1), 1);
  v48 = (v41 ^ v46) + v287 + __ROL4__(v45, 5) + v38 + 1518500249;
  v49 = v45 & (v44 ^ v47);
  v50 = __ROR4__(__ROR4__(v45, 1), 1);
  v51 = (v44 ^ v49) + v288 + __ROL4__(v48, 5) + v41 + 1518500249;
  v52 = v48 & (v47 ^ v50);
  v53 = __ROR4__(__ROR4__(v48, 1), 1);
  v54 = (v47 ^ v52) + v289 + __ROL4__(v51, 5) + v44 + 1518500249;
  v55 = v51 & (v50 ^ v53);
  v56 = __ROR4__(__ROR4__(v51, 1), 1);
  v57 = (v50 ^ v55) + v290 + __ROL4__(v54, 5) + v47 + 1518500249;
  v58 = v54 & (v53 ^ v56);
  v59 = __ROR4__(__ROR4__(v54, 1), 1);
  v60 = (v53 ^ v58) + v291 + __ROL4__(v57, 5) + v50 + 1518500249;
  v61 = v57 & (v56 ^ v59);
  v62 = __ROR4__(__ROR4__(v57, 1), 1);
  v63 = (v56 ^ v61) + v292 + __ROL4__(v60, 5) + v53 + 1518500249;
  v64 = v60 & (v59 ^ v62);
  v65 = __ROR4__(__ROR4__(v60, 1), 1);
  v66 = (v59 ^ v64) + v293 + __ROL4__(v63, 5) + v56 + 1518500249;
  v67 = v63 & (v62 ^ v65);
  v68 = __ROR4__(__ROR4__(v63, 1), 1);
  v69 = (v62 ^ v67) + v294 + __ROL4__(v66, 5) + v59 + 1518500249;
  v70 = v66 & (v65 ^ v68);
  v71 = __ROR4__(__ROR4__(v66, 1), 1);
  v72 = (v65 ^ v70) + v295 + __ROL4__(v69, 5) + v62 + 1518500249;
  v73 = v68 ^ v69 ^ v71;
  v74 = __ROR4__(__ROR4__(v69, 1), 1);
  v75 = v296 + v73 + __ROL4__(v72, 5) + v65 + 1859775393;
  v76 = v71 ^ v72 ^ v74;
  v77 = __ROR4__(__ROR4__(v72, 1), 1);
  v78 = v297 + v76 + __ROL4__(v75, 5) + v68 + 1859775393;
  v79 = v74 ^ v75 ^ v77;
  v80 = __ROR4__(__ROR4__(v75, 1), 1);
  v81 = v298 + v79 + __ROL4__(v78, 5) + v71 + 1859775393;
  v82 = v77 ^ v78 ^ v80;
  v83 = __ROR4__(__ROR4__(v78, 1), 1);
  v84 = v299 + v82 + __ROL4__(v81, 5) + v74 + 1859775393;
  v85 = v80 ^ v81 ^ v83;
  v86 = __ROR4__(__ROR4__(v81, 1), 1);
  v87 = v300 + v85 + __ROL4__(v84, 5) + v77 + 1859775393;
  v88 = v83 ^ v84 ^ v86;
  v89 = __ROR4__(__ROR4__(v84, 1), 1);
  v90 = v301 + v88 + __ROL4__(v87, 5) + v80 + 1859775393;
  v91 = v86 ^ v87 ^ v89;
  v92 = __ROR4__(__ROR4__(v87, 1), 1);
  v93 = v302 + v91 + __ROL4__(v90, 5) + v83 + 1859775393;
  v94 = v89 ^ v90 ^ v92;
  v95 = __ROR4__(__ROR4__(v90, 1), 1);
  v96 = v303 + v94 + __ROL4__(v93, 5) + v86 + 1859775393;
  v97 = v92 ^ v93 ^ v95;
  v98 = __ROR4__(__ROR4__(v93, 1), 1);
  v99 = v304 + v97 + __ROL4__(v96, 5) + v89 + 1859775393;
  v100 = v95 ^ v96 ^ v98;
  v101 = __ROR4__(__ROR4__(v96, 1), 1);
  v102 = v305 + v100 + __ROL4__(v99, 5) + v92 + 1859775393;
  v103 = v98 ^ v99 ^ v101;
  v104 = __ROR4__(__ROR4__(v99, 1), 1);
  v105 = v306 + v103 + __ROL4__(v102, 5) + v95 + 1859775393;
  v106 = v101 ^ v102 ^ v104;
  v107 = __ROR4__(__ROR4__(v102, 1), 1);
  v108 = v307 + v106 + __ROL4__(v105, 5) + v98 + 1859775393;
  v109 = v104 ^ v105 ^ v107;
  v110 = __ROR4__(__ROR4__(v105, 1), 1);
  v111 = v308 + v109 + __ROL4__(v108, 5) + v101 + 1859775393;
  v112 = v107 ^ v108 ^ v110;
  v113 = __ROR4__(__ROR4__(v108, 1), 1);
  v114 = v309 + v112 + __ROL4__(v111, 5) + v104 + 1859775393;
  v115 = v110 ^ v111 ^ v113;
  v116 = __ROR4__(__ROR4__(v111, 1), 1);
  v117 = v310 + v115 + __ROL4__(v114, 5) + v107 + 1859775393;
  v118 = v113 ^ v114 ^ v116;
  v119 = __ROR4__(__ROR4__(v114, 1), 1);
  v120 = v311 + v118 + __ROL4__(v117, 5) + v110 + 1859775393;
  v121 = v116 ^ v117 ^ v119;
  v122 = __ROR4__(__ROR4__(v117, 1), 1);
  v123 = v312 + v121 + __ROL4__(v120, 5) + v113 + 1859775393;
  v124 = v119 ^ v120 ^ v122;
  v125 = __ROR4__(__ROR4__(v120, 1), 1);
  v126 = v313 + v124 + __ROL4__(v123, 5) + v116 + 1859775393;
  v127 = v122 ^ v123 ^ v125;
  v128 = __ROR4__(__ROR4__(v123, 1), 1);
  v129 = v314 + v127 + __ROL4__(v126, 5) + v119 + 1859775393;
  v130 = v125 ^ v126 ^ v128;
  v131 = __ROR4__(__ROR4__(v126, 1), 1);
  v132 = v315 + v130 + __ROL4__(v129, 5) + v122 + 1859775393;
  v133 = v128 & (v131 | v129);
  v134 = v131 & v129;
  v135 = __ROR4__(__ROR4__(v129, 1), 1);
  v136 = (v133 | v134) + v316 + __ROL4__(v132, 5) + v125 - 1894007588;
  v137 = v131 & (v135 | v132);
  v138 = v135 & v132;
  v139 = __ROR4__(__ROR4__(v132, 1), 1);
  v140 = (v137 | v138) + v317 + __ROL4__(v136, 5) + v128 - 1894007588;
  v141 = v135 & (v139 | v136);
  v142 = v139 & v136;
  v143 = __ROR4__(__ROR4__(v136, 1), 1);
  v144 = (v141 | v142) + v318 + __ROL4__(v140, 5) + v131 - 1894007588;
  v145 = v139 & (v143 | v140);
  v146 = v143 & v140;
  v147 = __ROR4__(__ROR4__(v140, 1), 1);
  v148 = (v145 | v146) + v319 + __ROL4__(v144, 5) + v135 - 1894007588;
  v149 = v143 & (v147 | v144);
  v150 = v147 & v144;
  v151 = __ROR4__(__ROR4__(v144, 1), 1);
  v152 = (v149 | v150) + v320 + __ROL4__(v148, 5) + v139 - 1894007588;
  v153 = v147 & (v151 | v148);
  v154 = v151 & v148;
  v155 = __ROR4__(__ROR4__(v148, 1), 1);
  v156 = (v153 | v154) + v321 + __ROL4__(v152, 5) + v143 - 1894007588;
  v157 = v151 & (v155 | v152);
  v158 = v155 & v152;
  v159 = __ROR4__(__ROR4__(v152, 1), 1);
  v160 = (v157 | v158) + v322 + __ROL4__(v156, 5) + v147 - 1894007588;
  v161 = v155 & (v159 | v156);
  v162 = v159 & v156;
  v163 = __ROR4__(__ROR4__(v156, 1), 1);
  v164 = (v161 | v162) + v323 + __ROL4__(v160, 5) + v151 - 1894007588;
  v165 = v159 & (v163 | v160);
  v166 = v163 & v160;
  v167 = __ROR4__(__ROR4__(v160, 1), 1);
  v168 = (v165 | v166) + v324 + __ROL4__(v164, 5) + v155 - 1894007588;
  v169 = v163 & (v167 | v164);
  v170 = v167 & v164;
  v171 = __ROR4__(__ROR4__(v164, 1), 1);
  v172 = (v169 | v170) + v325 + __ROL4__(v168, 5) + v159 - 1894007588;
  v173 = v167 & (v171 | v168);
  v174 = v171 & v168;
  v175 = __ROR4__(__ROR4__(v168, 1), 1);
  v176 = (v173 | v174) + v326 + __ROL4__(v172, 5) + v163 - 1894007588;
  v177 = v171 & (v175 | v172);
  v178 = v175 & v172;
  v179 = __ROR4__(__ROR4__(v172, 1), 1);
  v180 = (v177 | v178) + v327 + __ROL4__(v176, 5) + v167 - 1894007588;
  v181 = v175 & (v179 | v176);
  v182 = v179 & v176;
  v183 = __ROR4__(__ROR4__(v176, 1), 1);
  v184 = (v181 | v182) + v328 + __ROL4__(v180, 5) + v171 - 1894007588;
  v185 = v179 & (v183 | v180);
  v186 = v183 & v180;
  v187 = __ROR4__(__ROR4__(v180, 1), 1);
  v188 = (v185 | v186) + v329 + __ROL4__(v184, 5) + v175 - 1894007588;
  v189 = v183 & (v187 | v184);
  v190 = v187 & v184;
  v191 = __ROR4__(__ROR4__(v184, 1), 1);
  v192 = (v189 | v190) + v330 + __ROL4__(v188, 5) + v179 - 1894007588;
  v193 = v187 & (v191 | v188);
  v194 = v191 & v188;
  v195 = __ROR4__(__ROR4__(v188, 1), 1);
  v196 = (v193 | v194) + v331 + __ROL4__(v192, 5) + v183 - 1894007588;
  v197 = v191 & (v195 | v192);
  v198 = v195 & v192;
  v199 = __ROR4__(__ROR4__(v192, 1), 1);
  v200 = (v197 | v198) + v332 + __ROL4__(v196, 5) + v187 - 1894007588;
  v201 = v195 & (v199 | v196);
  v202 = v199 & v196;
  v203 = __ROR4__(__ROR4__(v196, 1), 1);
  v204 = (v201 | v202) + v333 + __ROL4__(v200, 5) + v191 - 1894007588;
  v205 = v199 & (v203 | v200);
  v206 = v203 & v200;
  v207 = __ROR4__(__ROR4__(v200, 1), 1);
  v208 = (v205 | v206) + v334 + __ROL4__(v204, 5) + v195 - 1894007588;
  v209 = v203 & (v207 | v204);
  v210 = v207 & v204;
  v211 = __ROR4__(__ROR4__(v204, 1), 1);
  v212 = (v209 | v210) + v335 + __ROL4__(v208, 5) + v199 - 1894007588;
  v213 = v207 ^ v208 ^ v211;
  v214 = __ROR4__(__ROR4__(v208, 1), 1);
  v215 = v336 + v213 + __ROL4__(v212, 5) + v203 - 899497514;
  v216 = v211 ^ v212 ^ v214;
  v217 = __ROR4__(__ROR4__(v212, 1), 1);
  v218 = v337 + v216 + __ROL4__(v215, 5) + v207 - 899497514;
  v219 = v214 ^ v215 ^ v217;
  v220 = __ROR4__(__ROR4__(v215, 1), 1);
  v221 = v338 + v219 + __ROL4__(v218, 5) + v211 - 899497514;
  v222 = v217 ^ v218 ^ v220;
  v223 = __ROR4__(__ROR4__(v218, 1), 1);
  v224 = v339 + v222 + __ROL4__(v221, 5) + v214 - 899497514;
  v225 = v220 ^ v221 ^ v223;
  v226 = __ROR4__(__ROR4__(v221, 1), 1);
  v227 = v340 + v225 + __ROL4__(v224, 5) + v217 - 899497514;
  v228 = v223 ^ v224 ^ v226;
  v229 = __ROR4__(__ROR4__(v224, 1), 1);
  v230 = v341 + v228 + __ROL4__(v227, 5) + v220 - 899497514;
  v231 = v226 ^ v227 ^ v229;
  v232 = __ROR4__(__ROR4__(v227, 1), 1);
  v233 = v342 + v231 + __ROL4__(v230, 5) + v223 - 899497514;
  v234 = v229 ^ v230 ^ v232;
  v235 = __ROR4__(__ROR4__(v230, 1), 1);
  v236 = v343 + v234 + __ROL4__(v233, 5) + v226 - 899497514;
  v237 = v232 ^ v233 ^ v235;
  v238 = __ROR4__(__ROR4__(v233, 1), 1);
  v239 = v344 + v237 + __ROL4__(v236, 5) + v229 - 899497514;
  v240 = v235 ^ v236 ^ v238;
  v241 = __ROR4__(__ROR4__(v236, 1), 1);
  v242 = v345 + v240 + __ROL4__(v239, 5) + v232 - 899497514;
  v243 = v238 ^ v239 ^ v241;
  v244 = __ROR4__(__ROR4__(v239, 1), 1);
  v245 = v346 + v243 + __ROL4__(v242, 5) + v235 - 899497514;
  v246 = v241 ^ v242 ^ v244;
  v247 = __ROR4__(__ROR4__(v242, 1), 1);
  v248 = v347 + v246 + __ROL4__(v245, 5) + v238 - 899497514;
  v249 = v244 ^ v245 ^ v247;
  v250 = __ROR4__(__ROR4__(v245, 1), 1);
  v251 = v348 + v249 + __ROL4__(v248, 5) + v241 - 899497514;
  v252 = v247 ^ v248 ^ v250;
  v253 = __ROR4__(__ROR4__(v248, 1), 1);
  v254 = v349 + v252 + __ROL4__(v251, 5) + v244 - 899497514;
  v255 = v250 ^ v251 ^ v253;
  v256 = __ROR4__(__ROR4__(v251, 1), 1);
  v257 = v350 + v255 + __ROL4__(v254, 5) + v247 - 899497514;
  v258 = v253 ^ v254 ^ v256;
  v259 = __ROR4__(__ROR4__(v254, 1), 1);
  v260 = v351 + v258 + __ROL4__(v257, 5) + v250 - 899497514;
  v261 = v256 ^ v257 ^ v259;
  v262 = __ROR4__(__ROR4__(v257, 1), 1);
  v263 = v352 + v261 + __ROL4__(v260, 5) + v253 - 899497514;
  v264 = v259 ^ v260 ^ v262;
  v265 = __ROR4__(__ROR4__(v260, 1), 1);
  v266 = v353 + v264 + __ROL4__(v263, 5) + v256 - 899497514;
  v267 = v262 ^ v263 ^ v265;
  v268 = __ROR4__(__ROR4__(v263, 1), 1);
  v269 = v354 + v267 + __ROL4__(v266, 5) + v259 - 899497514;
  result = *a1 + (v265 ^ v266 ^ v268) + v355 + __ROL4__(v269, 5) + v262 - 899497514;
  v271 = a1[1] + v269;
  v272 = a1[2] + __ROR4__(__ROR4__(v266, 1), 1);
  v273 = a1[3] + v268;
  v274 = a1[4];
  *a1 = result;
  a1[1] = v271;
  a1[2] = v272;
  a1[3] = v273;
  a1[4] = v274 + v265;
  return result;
}