void __fastcall SceneRenderer::createSceneGeometry(int a1, int a2, PrimitiveSet **pp_sets, int ndet_bias)
{
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx

  PrimitiveSet::create(*pp_sets, a2, theSphereVers, 2, theSphereInsts, 28, ndet_bias, st_Bump, 0, 0, 0);
  PrimitiveSet::create(
    pp_sets[5],
    v4,
    theSurfOfRevVers,
    5,
    theSurfOfRevInsts,
    6,
    ndet_bias,
    st_Bump,
    pt_SurfOfRev,
    0,
    0);
  PrimitiveSet::create(pp_sets[4], v5, theConeVers, 3, theConeInsts, 34, ndet_bias, 0, pt_Cone, 0, 0);
  PrimitiveSet::create(pp_sets[2], v6, 0, 1, theBoxInsts, 72, ndet_bias, 0, pt_Box, 0, 0);
  PrimitiveSet::create(pp_sets[1], v7, theCylinderVers, 6, theCylinderInsts, 47, ndet_bias, 0, pt_Cylinder, 0, 0);
  PrimitiveSet::create(pp_sets[3], v8, theTorusVers, 7, theTorusInsts, 84, ndet_bias, 0, pt_Torus, 0, 0);
}