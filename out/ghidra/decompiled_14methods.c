===== Life_IncrementAge @ 0x2575df4 =====

/* WARNING: Removing unreachable block (ram,0x0257b1b0) */
/* WARNING: Removing unreachable block (ram,0x0257b1f4) */
/* WARNING: Removing unreachable block (ram,0x0257746c) */
/* WARNING: Removing unreachable block (ram,0x02577478) */
/* WARNING: Removing unreachable block (ram,0x0257b248) */
/* WARNING: Removing unreachable block (ram,0x0257b190) */

void Life_IncrementAge(int param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  int *piVar15;
  undefined4 *puVar16;
  int unaff_r6;
  int iVar17;
  int *unaff_r7;
  int *unaff_r8;
  int unaff_r9;
  int *unaff_r11;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  uint in_fpscr;
  uint uVar21;
  double unaff_d8;
  double dVar22;
  double unaff_d9;
  float fVar23;
  double dVar24;
  undefined8 uVar25;
  double dVar26;
  double dVar27;
  int *in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int *in_stack_00000048;
  undefined4 uStack00000058;
  undefined8 *in_stack_0000005c;
  undefined4 *in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined8 uStack00000070;
  undefined8 in_stack_00000078;
  undefined4 uStack000000a8;
  undefined8 uStack000000ac;
  
  if (param_1 != 0) {
    piVar4 = (int *)FUN_02565a6c();
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (iVar5 < 1) goto LAB_02575e3c;
LAB_02576160:
    iVar5 = FUN_02565a6c(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565a6c(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565a6c(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565a6c(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_0257715c + 0x2576220));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01b8c918(iVar5,0,0,0);
          if (*(int *)(**(int **)(DAT_02577160 + 0x2576260) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(uVar6,**(undefined4 **)(DAT_02577164 + 0x2576280),0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_025772b0 + 0x25762d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          thunk_FUN_0464f828(**(undefined4 **)(DAT_025772b4 + 0x2576308),uVar6,0);
        }
        if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r8 + 0x1a8))();
      }
    }
    iVar5 = FUN_02565af4(in_stack_00000040);
    bVar3 = false;
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565af4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565af4(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565af4(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02577444 + 0x2576504));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b7aa54(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = *(undefined4 *)(iVar7 + 8);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b7aa54(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar16 = *(undefined4 **)(DAT_0257754c + 0x2576574);
          uVar6 = thunk_FUN_04662ba0(*puVar16,uVar6,*(undefined4 *)(iVar7 + 0xc),0);
          if (*(int *)(**(int **)(DAT_02577550 + 0x257658c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(uVar6,**(undefined4 **)(DAT_02577554 + 0x25765ac),0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b7aa54(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = *(undefined4 *)(iVar7 + 8);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          bVar3 = false;
          iVar5 = FUN_01b7aa54(iVar5,0);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = thunk_FUN_04662ba0(*puVar16,uVar6,*(undefined4 *)(iVar5 + 0xc),0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_025773a4 + 0x2576404) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          puVar16 = *(undefined4 **)(DAT_02577418 + 0x2576434);
          thunk_FUN_0464f828(*puVar16,uVar6,0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          piVar4 = (int *)FUN_02565af4(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          uVar6 = FUN_01f8250c(uVar6,0);
          uVar6 = thunk_FUN_0464f828(*puVar16,uVar6,0);
          bVar3 = true;
        }
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r7 + 0x1a8))(unaff_r7,uVar6,*(undefined4 *)(*unaff_r7 + 0x1ac));
      }
    }
    iVar5 = FUN_02565da4(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565da4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565da4(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565da4(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02577668 + 0x2576740));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b780c8(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = *(undefined4 *)(iVar7 + 0xc);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b780c8(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar16 = *(undefined4 **)(DAT_02577754 + 0x25767b4);
          uVar6 = thunk_FUN_04662ba0(*puVar16,uVar6,*(undefined4 *)(iVar7 + 0x10),0);
          if (*(int *)(**(int **)(DAT_02577758 + 0x25767cc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(uVar6,**(undefined4 **)(DAT_0257775c + 0x25767ec),0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b780c8(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = *(undefined4 *)(iVar7 + 0xc);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_01b780c8(iVar5,0);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = thunk_FUN_04662ba0(*puVar16,uVar6,*(undefined4 *)(iVar5 + 0x10),0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_0257786c + 0x25768d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          puVar16 = *(undefined4 **)(DAT_02577870 + 0x2576908);
          thunk_FUN_0464f828(*puVar16,uVar6,0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          piVar4 = (int *)FUN_02565da4(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          uVar6 = FUN_01f8250c(uVar6,0);
          uVar6 = thunk_FUN_0464f828(*puVar16,uVar6,0);
          bVar3 = true;
        }
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r7 + 0x1a8))(unaff_r7,uVar6,*(undefined4 *)(*unaff_r7 + 0x1ac));
      }
    }
    iVar5 = FUN_02565e2c(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565e2c(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565e2c(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565e2c(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02577960 + 0x2576a68));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01bc6598(iVar5,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_02577a70 + 0x2576aa4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(*(undefined4 *)(iVar7 + 0xc),**(undefined4 **)(DAT_02577a74 + 0x2576ac8),0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_01bc6598(iVar5,0);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = *(undefined4 *)(iVar5 + 0xc);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_02577a78 + 0x2576b64) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          puVar16 = *(undefined4 **)(DAT_02577b6c + 0x2576b94);
          thunk_FUN_0464f828(*puVar16,uVar6,0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          piVar4 = (int *)FUN_02565e2c(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          uVar6 = FUN_01f8250c(uVar6,0);
          uVar6 = thunk_FUN_0464f828(*puVar16,uVar6,0);
          bVar3 = true;
        }
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r7 + 0x1a8))(unaff_r7,uVar6,*(undefined4 *)(*unaff_r7 + 0x1ac));
      }
    }
    iVar5 = FUN_02565f6c(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565f6c(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565f6c(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565f6c(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02577c8c + 0x2576cf4));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01b51e94(iVar5,0);
          if (*(int *)(**(int **)(DAT_02577c90 + 0x2576d24) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(uVar6,**(undefined4 **)(DAT_02577c94 + 0x2576d44),0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01b51e94(iVar5,0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_02577d84 + 0x2576dcc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          puVar16 = *(undefined4 **)(DAT_02577d88 + 0x2576dfc);
          thunk_FUN_0464f828(*puVar16,uVar6,0);
          if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*unaff_r8 + 0x1a8))();
          piVar4 = (int *)FUN_02565f6c(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          uVar6 = FUN_01f8250c(uVar6,0);
          uVar6 = thunk_FUN_0464f828(*puVar16,uVar6,0);
          bVar3 = true;
        }
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r7 + 0x1a8))(unaff_r7,uVar6,*(undefined4 *)(*unaff_r7 + 0x1ac));
      }
    }
    iVar5 = FUN_02565eb4(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02565eb4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02565eb4(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02565eb4(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          piVar4 = (int *)FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02577ec4 + 0x2576f5c));
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0xe8))(piVar4,*(undefined4 *)(*piVar4 + 0xec));
          if (*(int *)(**(int **)(DAT_02577ec8 + 0x2576f94) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(uVar6,**(undefined4 **)(DAT_02577ecc + 0x2576fb4),0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_02577fbc + 0x2576ff0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          thunk_FUN_0464f828(**(undefined4 **)(DAT_02577fc0 + 0x2577020),uVar6,0);
        }
        if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r8 + 0x1a8))();
      }
    }
    iVar5 = FUN_02566f9c(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02566f9c(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (0 < iVar5) {
        piVar4 = (int *)FUN_02566f9c(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        piVar4 = (int *)FUN_02566f9c(in_stack_00000040);
        if (iVar5 == 1) {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
          iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_025780a4 + 0x257710c));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_025780a8 + 0x257712c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          FUN_01f83354(*(undefined4 *)(iVar5 + 8),**(undefined4 **)(DAT_025780ac + 0x2577150),0);
        }
        else {
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
          if (*(int *)(**(int **)(DAT_025780b0 + 0x2577198) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_01f8250c(uVar6,0);
          thunk_FUN_0464f828(**(undefined4 **)(DAT_025780b4 + 0x25771c8),uVar6,0);
        }
        if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r8 + 0x1a8))();
      }
    }
    iVar5 = FUN_02566890(in_stack_00000040);
    if (iVar5 != 0) {
      piVar4 = (int *)FUN_02566890(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uStack000000ac._0_4_ =
           (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
      in_stack_00000060 = &uStack000000a8;
      in_stack_0000005c = &uStack000000ac;
      uStack00000058 = 0;
      piVar4 = *(int **)(DAT_02578200 + 0x2577264);
      fVar23 = DAT_02577558;
      do {
        piVar8 = (int *)uStack000000ac;
        if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)uStack000000ac;
        uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
        if (uVar14 != 0) {
          piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
          do {
            if (piVar15[-1] == *unaff_r11) {
              puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
              goto LAB_025772c4;
            }
            uVar14 = uVar14 - 1;
            piVar15 = piVar15 + 2;
          } while (uVar14 != 0);
        }
        puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025772c4:
        iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
        piVar8 = (int *)uStack000000ac;
        if (iVar5 == 0) {
          piVar15 = *(int **)(DAT_02578204 + 0x25773bc);
          piVar8 = (int *)thunk_FUN_0105da7c((int *)uStack000000ac,*piVar15);
          uStack000000a8 = piVar8;
          if (piVar8 == (int *)0x0) goto LAB_02577464;
          iVar5 = *piVar8;
          iVar7 = *piVar15;
          uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar14 == 0) goto LAB_02577408;
          piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
          goto LAB_025773f0;
        }
        if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)uStack000000ac;
        uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
        if (uVar14 != 0) {
          piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
          do {
            if (piVar15[-1] == *unaff_r11) {
              puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
              goto LAB_0257733c;
            }
            uVar14 = uVar14 - 1;
            piVar15 = piVar15 + 2;
          } while (uVar14 != 0);
        }
        puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257733c:
        piVar8 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *piVar4;
        uVar14 = (uint)*(byte *)(iVar5 + 0xb8);
        if ((*(byte *)(*piVar8 + 0xb8) < uVar14) ||
           (*(int *)(*(int *)(*piVar8 + 100) + uVar14 * 4 + -4) != iVar5)) {
                    /* WARNING: Subroutine does not return */
          FUN_0101fa24(piVar8);
        }
        fVar23 = fVar23 + (float)piVar8[6];
      } while( true );
    }
    iVar5 = FUN_02567354(in_stack_00000040);
    fVar23 = DAT_02577558;
    if (iVar5 != 0) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      goto LAB_02577684;
    }
    goto LAB_0257784c;
  }
LAB_02575e3c:
  iVar5 = FUN_02565af4(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02565af4(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02566890(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02566890(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02565da4(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02565da4(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02565e2c(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02565e2c(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02565f6c(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02565f6c(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02565eb4(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02565eb4(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02566f9c(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02566f9c(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_02567354(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_02567354(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_025673dc(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025673dc(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_025674b4(unaff_r6);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025674b4(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    unaff_r6 = in_stack_00000040;
    if (0 < iVar5) goto LAB_02576160;
  }
  iVar5 = FUN_025693f0(unaff_r6);
  fVar23 = DAT_025764d0;
  bVar3 = false;
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025693f0(unaff_r6);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (0 < iVar5) goto LAB_02576160;
  }
LAB_02577e78:
  if (in_stack_00000034 != 0) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    goto LAB_02578164;
  }
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
LAB_02577ed4:
  if ((*(int *)(in_stack_00000040 + 0x70) == 0) ||
     (*(int *)(*(int *)(in_stack_00000040 + 0x70) + 0x1c4) != 3)) {
    iVar5 = *(int *)(in_stack_00000040 + 0xb0);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 8) == 6)) {
      iVar5 = FUN_00d98e30(iVar5,**(undefined4 **)(DAT_02578fcc + 0x2577fec));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar5 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(*(int *)(iVar5 + 0x18) + 8) == 7) {
        iVar5 = FUN_00d98e30(*(undefined4 *)(iVar5 + 0x18),
                             **(undefined4 **)(DAT_02578fd0 + 0x2578028));
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = *(int *)(iVar5 + 0x18);
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar7 + 0x88) == '\0') {
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(char *)(iVar7 + 0x89) == '\0') goto LAB_02578164;
          iVar7 = *(int *)(iVar5 + 0x18);
        }
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = *(undefined4 *)(iVar7 + 8);
        uVar25 = FUN_01c93dcc(iVar7,0,0);
        if (*(int *)(**(int **)(DAT_02578fd4 + 0x25780fc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar10 = FUN_01f7f518((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0);
        thunk_FUN_04662ba0(**(undefined4 **)(DAT_02578fd8 + 0x2578134),uVar6,uVar10,0);
        if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*unaff_r8 + 0x1a8))();
      }
    }
    goto LAB_02578164;
  }
  iVar5 = *(int *)(in_stack_00000040 + 0xb0);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 8) == 6)) {
    iVar5 = FUN_00d98e30(iVar5,**(undefined4 **)(DAT_02578ca0 + 0x2577f18));
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(iVar5 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(*(int *)(iVar5 + 0x18) + 8) == 7) {
      iVar5 = FUN_00d98e30(*(undefined4 *)(iVar5 + 0x18),**(undefined4 **)(DAT_02578ca4 + 0x2577f54)
                          );
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar7 = *(int *)(iVar5 + 0x18);
      if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar7 + 0x88) == '\0') {
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar7 + 0x89) == '\0') goto LAB_025789e0;
        iVar7 = *(int *)(iVar5 + 0x18);
      }
      if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = *(undefined4 *)(iVar7 + 8);
      uVar25 = FUN_01c93dcc(iVar7,0,0);
      if (*(int *)(**(int **)(DAT_02579830 + 0x2578948) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar10 = FUN_01f7f518((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0);
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar13 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
      thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257999c + 0x25789ac),uVar6,uVar10,uVar13);
      if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*unaff_r8 + 0x1a8))();
    }
  }
LAB_025789e0:
  if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  dVar27 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
  uVar14 = in_fpscr & 0xfffffff | (uint)(dVar27 == -10.0) << 0x1e;
  uVar21 = uVar14 | (uint)(-10.0 <= dVar27) << 0x1d;
  if (!(bool)((byte)(uVar21 >> 0x1d) & 1) || SUB41(uVar14 >> 0x1e,0)) {
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
    puVar16 = *(undefined4 **)(DAT_02579a38 + 0x2578aa0);
LAB_02578a9c:
    thunk_FUN_0464f828(*puVar16,uVar6,0);
    if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*unaff_r8 + 0x1a8))();
  }
  else {
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    dVar27 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
    uVar14 = in_fpscr & 0xfffffff | (uint)(dVar27 < 10.0) << 0x1f;
    uVar21 = uVar14 | (uint)NAN(dVar27) << 0x1c;
    if ((byte)(uVar14 >> 0x1f) == ((byte)(uVar21 >> 0x1c) & 1)) {
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
      puVar16 = *(undefined4 **)((int)&DAT_02578a64 + DAT_02579a34);
      goto LAB_02578a9c;
    }
  }
  uVar14 = uVar21 & 0xfffffff | (uint)(unaff_d9 < 0.0) << 0x1f | (uint)(unaff_d9 == 0.0) << 0x1e;
  uVar21 = uVar14 | (uint)NAN(unaff_d9) << 0x1c;
  bVar2 = (byte)(uVar14 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar21 >> 0x1c) & 1)) goto LAB_02578284;
  if (*(int *)(**(int **)(DAT_02579a3c + 0x2578ae8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  uVar6 = FUN_01f80d88();
  if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar10 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
  thunk_FUN_04662ba0(**(undefined4 **)(DAT_02579a40 + 0x2578b48),uVar6,uVar10,0);
LAB_0257825c:
  if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*unaff_r8 + 0x1a8))();
  goto LAB_02578284;
  while( true ) {
    uVar14 = uVar14 - 1;
    piVar15 = piVar15 + 2;
    if (uVar14 == 0) break;
LAB_025773f0:
    if (piVar15[-1] == iVar7) {
      puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
      goto LAB_02577454;
    }
  }
LAB_02577408:
  puVar16 = (undefined4 *)FUN_0105aa50(piVar8,iVar7,0);
LAB_02577454:
  (*(code *)*puVar16)(piVar8,puVar16[1]);
LAB_02577464:
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar8 = (int *)FUN_02566890(in_stack_00000040);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
  if (iVar5 == 1) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar8 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar6 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
    iVar5 = FUN_00d98e30(uVar6,*piVar4);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_01b8ab7c(iVar5,0);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    FUN_013bcec8(iVar5,0);
LAB_02577620:
    if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*unaff_r8 + 0x1a8))();
  }
  else {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (1 < iVar5) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_02566890(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (*(int *)(**(int **)(DAT_025785cc + 0x25775ec) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar6 = FUN_01f8250c(uVar6,0);
      thunk_FUN_0464f828(**(undefined4 **)(DAT_025785d0 + 0x257761c),uVar6,0);
      goto LAB_02577620;
    }
  }
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = FUN_02567354(in_stack_00000040);
  if (iVar5 != 0) {
LAB_02577684:
    piVar4 = (int *)FUN_02567354(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (iVar5 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
      iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_025786f4 + 0x2577704));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_025786f8 + 0x2577724) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_01f83354(*(undefined4 *)(iVar5 + 0xc),**(undefined4 **)(DAT_025786fc + 0x2577748),0);
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (iVar5 < 2) goto LAB_0257784c;
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (*(int *)(**(int **)(DAT_025787a4 + 0x25777f0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar6 = FUN_01f8250c(uVar6,0);
      thunk_FUN_0464f828(**(undefined4 **)(DAT_025787a8 + 0x2577820),uVar6,0);
    }
    if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*unaff_r8 + 0x1a8))();
LAB_0257784c:
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar5 = FUN_025673dc(in_stack_00000040);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (iVar5 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025673dc(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
      iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_025788f0 + 0x2577910));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_025788f4 + 0x2577930) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_01f83354(*(undefined4 *)(iVar5 + 0xc),**(undefined4 **)(DAT_025788f8 + 0x2577954),0);
LAB_02577a28:
      if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*unaff_r8 + 0x1a8))();
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025673dc(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (1 < iVar5) {
        if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar4 = (int *)FUN_025673dc(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        if (*(int *)(**(int **)(DAT_025788fc + 0x25779f4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar6 = FUN_01f8250c(uVar6,0);
        thunk_FUN_0464f828(**(undefined4 **)(DAT_02578900 + 0x2577a24),uVar6,0);
        goto LAB_02577a28;
      }
    }
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar5 = FUN_025674b4(in_stack_00000040);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025674b4(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (iVar5 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025674b4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
      iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02578a64 + 0x2577b1c));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_02578a68 + 0x2577b3c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_01f83354(*(undefined4 *)(iVar5 + 8),**(undefined4 **)(DAT_02578b50 + 0x2577b60),0);
LAB_02577c34:
      if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*unaff_r8 + 0x1a8))();
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025674b4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (1 < iVar5) {
        if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar4 = (int *)FUN_025674b4(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
        if (*(int *)(**(int **)(DAT_02578bf0 + 0x2577c00) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar6 = FUN_01f8250c(uVar6,0);
        thunk_FUN_0464f828(**(undefined4 **)(DAT_02578bf4 + 0x2577c30),uVar6,0);
        goto LAB_02577c34;
      }
    }
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar5 = FUN_025693f0(in_stack_00000040);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_025693f0(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
    if (iVar5 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x198))(piVar4,0,*(undefined4 *)(*piVar4 + 0x19c));
      iVar5 = FUN_00d98e30(uVar6,**(undefined4 **)(DAT_02578c8c + 0x2577d34));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_02578c90 + 0x2577d54) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_01f83354(*(undefined4 *)(iVar5 + 8),**(undefined4 **)(DAT_02578c94 + 0x2577d78),0);
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (iVar5 < 2) goto LAB_02577e78;
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = (**(code **)(*piVar4 + 0x170))(piVar4,*(undefined4 *)(*piVar4 + 0x174));
      if (*(int *)(**(int **)(DAT_02578c98 + 0x2577e1c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar6 = FUN_01f8250c(uVar6,0);
      thunk_FUN_0464f828(**(undefined4 **)(DAT_02578c9c + 0x2577e4c),uVar6,0);
    }
    if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*unaff_r8 + 0x1a8))();
    goto LAB_02577e78;
  }
  if (in_stack_00000034 == 0) goto LAB_02577ed4;
LAB_02578164:
  if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)(in_stack_00000040 + 0x78);
  dVar27 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
  uVar14 = in_fpscr & 0xfffffff | (uint)(dVar27 == -10.0) << 0x1e;
  uVar21 = uVar14 | (uint)(-10.0 <= dVar27) << 0x1d;
  if (!(bool)((byte)(uVar21 >> 0x1d) & 1) || SUB41(uVar14 >> 0x1e,0)) {
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(**(int **)(DAT_02578fe4 + 0x2578220) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar6 = FUN_01f7f518(SUB84(-*(double *)(iVar5 + 8),0),
                         (int)((ulonglong)-*(double *)(iVar5 + 8) >> 0x20),0);
    puVar16 = *(undefined4 **)(DAT_02579238 + 0x2578254);
LAB_02578250:
    thunk_FUN_0464f828(*puVar16,uVar6,0);
    goto LAB_0257825c;
  }
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar14 = in_fpscr & 0xfffffff | (uint)(*(double *)(iVar5 + 8) < 10.0) << 0x1f;
  uVar21 = uVar14 | (uint)NAN(*(double *)(iVar5 + 8)) << 0x1c;
  if ((byte)(uVar14 >> 0x1f) == ((byte)(uVar21 >> 0x1c) & 1)) {
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar25 = *(undefined8 *)(*(int *)(in_stack_00000040 + 0x78) + 8);
    if (*(int *)(**(int **)(DAT_02578fdc + 0x25781d0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar6 = FUN_01f7f518((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0);
    puVar16 = *(undefined4 **)((int)&DAT_02578200 + DAT_02578fe0);
    goto LAB_02578250;
  }
LAB_02578284:
  uVar21 = uVar21 & 0xfffffff | (uint)(unaff_d9 < 0.0) << 0x1f | (uint)(unaff_d9 == 0.0) << 0x1e;
  uVar14 = uVar21 | (uint)NAN(unaff_d9) << 0x1c;
  bVar2 = (byte)(uVar21 >> 0x18);
  if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar14 >> 0x1c) & 1)) {
    if (*(int *)(**(int **)(DAT_0257923c + 0x257829c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar6 = FUN_01f80d88();
    thunk_FUN_0464f828(**(undefined4 **)(DAT_02579240 + 0x25782d0),uVar6,0);
    if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*unaff_r8 + 0x1a8))();
  }
  if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = **(int **)(DAT_02579248 + 0x2578324);
  if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
    iVar5 = **(int **)(DAT_02579244 + 0x2578308);
  }
  if (unaff_r8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar7 = (**(code **)(*unaff_r8 + 0x170))();
  if (iVar7 < 1) {
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
    uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_02579524 + 0x25785b8),in_stack_00000028,uVar6,
                               iVar5);
  }
  else {
    bVar19 = true;
    if ((((*(int *)(in_stack_00000040 + 0xd4) != 0) &&
         (*(int *)(*(int *)(in_stack_00000040 + 0xd4) + 8) == 1)) &&
        (uVar14 = uVar14 & 0xfffffff, 0.0 <= unaff_d8)) &&
       (bVar19 = false, *(char *)(in_stack_00000038 + 0xc) != '\0')) {
      bVar19 = true;
    }
    piVar4 = (int *)thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257924c + 0x25783a4),5);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if ((in_stack_00000028 != 0) &&
       (iVar7 = thunk_FUN_0105da7c(in_stack_00000028,*(undefined4 *)(*piVar4 + 0x20)), iVar7 == 0))
    {
      uVar6 = thunk_FUN_01065924();
      FUN_0101f51c(uVar6,0);
    }
    if (piVar4[3] == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar4[4] = in_stack_00000028;
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
    if ((iVar7 != 0) &&
       (iVar9 = thunk_FUN_0105da7c(iVar7,*(undefined4 *)(*piVar4 + 0x20)), iVar9 == 0)) {
      uVar6 = thunk_FUN_01065924();
      FUN_0101f51c(uVar6,0);
    }
    if ((uint)piVar4[3] < 2) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar4[5] = iVar7;
    if ((iVar5 != 0) &&
       (iVar7 = thunk_FUN_0105da7c(iVar5,*(undefined4 *)(*piVar4 + 0x20)), iVar7 == 0)) {
      uVar6 = thunk_FUN_01065924();
      FUN_0101f51c(uVar6,0);
    }
    if ((uint)piVar4[3] < 3) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar4[6] = iVar5;
    uVar6 = thunk_FUN_0105db90(**(undefined4 **)(DAT_02579458 + 0x25784ac));
    thunk_FUN_04776538();
    if (*(int *)(**(int **)(DAT_0257945c + 0x25784cc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    iVar5 = FUN_01f84a64(uVar6,0);
    if ((iVar5 != 0) &&
       (iVar7 = thunk_FUN_0105da7c(iVar5,*(undefined4 *)(*piVar4 + 0x20)), iVar7 == 0)) {
      uVar6 = thunk_FUN_01065924();
      FUN_0101f51c(uVar6,0);
    }
    if ((uint)piVar4[3] < 4) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar4[7] = iVar5;
    piVar8 = *(int **)(DAT_02579518 + 0x2578538);
    iVar5 = *piVar8;
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
      iVar7 = iVar5;
    }
    else {
      uVar21 = uVar14 & 0xfffffff | (uint)(unaff_d8 < 0.0) << 0x1f | (uint)(unaff_d8 == 0.0) << 0x1e
      ;
      uVar14 = uVar21 | (uint)NAN(unaff_d8) << 0x1c;
      bVar2 = (byte)(uVar21 >> 0x18);
      iVar7 = **(int **)(DAT_02579520 + 0x2578560);
      if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar14 >> 0x1c) & 1)) {
        iVar7 = iVar5;
      }
      if (*(int *)(*(int *)(in_stack_00000040 + 0xd4) + 8) != 1) {
        iVar7 = iVar5;
      }
    }
    uVar6 = **(undefined4 **)(DAT_0257951c + 0x2578544);
    FUN_00d99150(piVar4,iVar7);
    if ((uint)piVar4[3] < 5) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar4[8] = iVar7;
    uVar6 = thunk_FUN_04662c44(uVar6,piVar4,0);
    if (bVar19) {
      iVar5 = *(int *)(in_stack_00000040 + 0x70);
      if (iVar5 != 0) {
        if (*(int *)(iVar5 + 0x1c4) == 3) {
          unaff_d8 = unaff_d8 * 0.5;
        }
      }
      iVar7 = *(int *)(in_stack_00000040 + 0xd4);
      if ((iVar7 == 0) || (*(int *)(iVar7 + 8) != 2)) {
        bVar18 = false;
        bVar19 = false;
        if (iVar5 == 0) goto LAB_02578708;
      }
      else {
        if (iVar5 == 0) {
          bVar19 = true;
          goto LAB_02578708;
        }
        bVar19 = iVar5 == in_stack_0000001c;
        iVar9 = 2;
        if (bVar19) {
          iVar9 = *(int *)(in_stack_0000001c + 0x1c4);
        }
        bVar18 = bVar19 && iVar9 == 3;
        bVar19 = !bVar19 || iVar9 != 3;
      }
      bVar20 = iVar5 == in_stack_0000001c;
      if (bVar20) {
        iVar5 = *(int *)(in_stack_0000001c + 0x1c4);
      }
      if ((!(bVar20 && iVar5 == 3)) || (iVar7 == 0)) {
        if (!bVar18) {
LAB_02578708:
          piVar4 = (int *)FUN_02565674(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
          iVar5 = 0;
          in_stack_00000060 = &uStack000000a8;
          in_stack_0000005c = &uStack000000ac;
          uStack00000058 = 0;
          do {
            piVar4 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = *(int *)uStack000000ac;
            uVar21 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar21 != 0) {
              piVar15 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar16 = (undefined4 *)(iVar7 + *piVar15 * 8 + 0xc0);
                  goto LAB_025787b8;
                }
                uVar21 = uVar21 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar21 != 0);
            }
            puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025787b8:
            iVar7 = (*(code *)*puVar16)(piVar4,puVar16[1]);
            piVar4 = (int *)uStack000000ac;
            if (iVar7 == 0) {
              FUN_00d98384(&uStack00000058);
              if (iVar5 == 1) {
                bVar18 = false;
                if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                goto LAB_02579094;
              }
              bVar18 = false;
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              goto LAB_02578ffc;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = *(int *)uStack000000ac;
            uVar21 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar21 != 0) {
              piVar15 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar16 = (undefined4 *)(iVar7 + *piVar15 * 8 + 200);
                  goto LAB_02578830;
                }
                uVar21 = uVar21 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar21 != 0);
            }
            puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_02578830:
            piVar4 = (int *)(*(code *)*puVar16)(piVar4,puVar16[1]);
            if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar9 = **(int **)(DAT_02579828 + 0x2578858);
            iVar7 = *piVar4;
            uVar21 = (uint)*(byte *)(iVar9 + 0xb8);
            if ((*(byte *)(iVar7 + 0xb8) < uVar21) ||
               (*(int *)(*(int *)(iVar7 + 100) + uVar21 * 4 + -4) != iVar9)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar4);
            }
            if ((*(byte *)(iVar7 + 0xb8) < uVar21) ||
               (*(int *)(*(int *)(iVar7 + 100) + uVar21 * 4 + -4) != iVar9)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar4);
            }
            iVar5 = iVar5 + (uint)*(byte *)(piVar4 + 3);
          } while( true );
        }
      }
      else if (!bVar18 && *(int *)(iVar7 + 8) != 2) goto LAB_02578708;
      iVar5 = 0;
      bVar18 = true;
LAB_02578ffc:
      iVar7 = *(int *)(in_stack_00000040 + 0xd4);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 8) == 3)) {
        iVar7 = *(int *)(iVar7 + 0xc);
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar9 = *(int *)(*(int *)(in_stack_00000044 + 0x48) + 200);
        if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar10 = FUN_01b9e854(iVar9,0);
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = thunk_FUN_0465f908(iVar7,uVar10,0);
        if (iVar7 != 0) goto LAB_02579094;
      }
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) != '\0') {
LAB_02579094:
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        dVar27 = 0.0;
        if ((*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) == '\0') &&
           (*(int *)(in_stack_00000040 + 0xd0) == 0)) {
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar10 = FUN_01a4e1f8(iVar5,0);
          if (*(int *)(**(int **)(DAT_0257a108 + 0x2579110) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          dVar27 = (double)FUN_01786018(SUB84(unaff_d8 - (double)fVar23,0),
                                        (int)((ulonglong)(unaff_d8 - (double)fVar23) >> 0x20),uVar10
                                        ,0);
        }
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        dVar22 = unaff_d8 - dVar27;
        if (0x11 < *(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14)) {
          uVar10 = FUN_02565af4(in_stack_00000040);
          iVar5 = FUN_01f76fd4(uVar10,0);
          uVar10 = FUN_02565da4(in_stack_00000040);
          iVar7 = FUN_01f76fd4(uVar10,0);
          uVar10 = FUN_02565e2c(in_stack_00000040);
          iVar9 = FUN_01f76fd4(uVar10,0);
          uVar10 = FUN_02565f6c(in_stack_00000040);
          iVar11 = FUN_01f76fd4(uVar10,0);
          if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar17 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
          if (iVar17 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar16 = *(undefined4 **)(DAT_0257a1cc + 0x25792dc);
          iVar17 = FUN_03c38838(iVar17,2,*puVar16);
          dVar24 = 0.0;
          if (iVar17 != 0) {
            if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar17 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
            if (iVar17 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            dVar24 = (double)FUN_03c384e8(iVar17,2,**(undefined4 **)(DAT_0257a1d0 + 0x2579320));
            dVar24 = dVar24 + 0.0;
          }
          piVar4 = (int *)FUN_02565af4(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = iVar7 + iVar5 + iVar9 + iVar11;
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
          uStack00000058 = 0;
          piVar4 = *(int **)(DAT_0257a1d4 + 0x2579390);
          in_stack_0000005c = &uStack000000ac;
          in_stack_00000060 = &uStack000000a8;
          do {
            piVar8 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
            if (uVar14 != 0) {
              piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
                  goto LAB_025793ec;
                }
                uVar14 = uVar14 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar14 != 0);
            }
            puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025793ec:
            iVar5 = (*(code *)*puVar12)(piVar8,puVar12[1]);
            piVar8 = (int *)uStack000000ac;
            if (iVar5 == 0) {
              FUN_00d98384(&uStack00000058);
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
              if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar5 = FUN_03c38838(iVar5,3,*puVar16);
              if (iVar5 != 0) {
                if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
                if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                dVar26 = (double)FUN_03c384e8(iVar5,3,**(undefined4 **)(DAT_0257b56c + 0x257a684));
                dVar24 = dVar24 + dVar26;
              }
              piVar4 = (int *)FUN_02565da4(in_stack_00000040);
              if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              uStack000000ac._0_4_ =
                   (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
              uStack00000058 = 0;
              piVar4 = *(int **)(DAT_0257b6c8 + 0x257a6e0);
              in_stack_0000005c = &uStack000000ac;
              in_stack_00000060 = &uStack000000a8;
              goto LAB_0257a6dc;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
            if (uVar14 != 0) {
              piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
                  goto LAB_0257946c;
                }
                uVar14 = uVar14 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar14 != 0);
            }
            puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257946c:
            piVar15 = (int *)(*(code *)*puVar12)(piVar8,puVar12[1]);
            piVar8 = (int *)0x0;
            if (piVar15 != (int *)0x0) {
              uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
              if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
                 (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
                FUN_0101fa24();
              }
              piVar8 = piVar15;
            }
            piVar15 = (int *)FUN_02565af4(in_stack_00000044);
            if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
            if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (piVar8[0xd] != 0) {
              dVar24 = dVar24 - (double)*(float *)(piVar8[0xd] + 0x2c);
            }
          } while( true );
        }
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = (**(code **)(*unaff_r7 + 0x170))(unaff_r7,*(undefined4 *)(*unaff_r7 + 0x174));
        if (0 < iVar5) {
          uVar10 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257a184 + 0x2579194));
          thunk_FUN_04776538(uVar10,unaff_r7,0);
          if (*(int *)(**(int **)(DAT_0257a188 + 0x25791b8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar10 = FUN_01f84a64(uVar10,0);
          iVar5 = (**(code **)(*unaff_r7 + 0x170))(unaff_r7,*(undefined4 *)(*unaff_r7 + 0x174));
          puVar16 = *(undefined4 **)(DAT_0257a1c4 + 0x2579204);
          if (1 < iVar5) {
            puVar16 = *(undefined4 **)(DAT_0257a1c0 + 0x25791fc);
          }
          if (bVar3) {
            puVar16 = *(undefined4 **)(DAT_0257a1c0 + 0x25791fc);
          }
          uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257a1c8 + 0x2579210),uVar6,uVar10,
                                     *puVar16);
        }
LAB_0257af28:
        if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_03c38838(iVar5,1,**(undefined4 **)(DAT_0257bf3c + 0x257af5c));
        dVar24 = 0.0;
        if (iVar5 != 0) {
          if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          dVar24 = (double)FUN_03c384e8(iVar5,1,**(undefined4 **)(DAT_0257bf40 + 0x257afa4));
          dVar24 = dVar24 + 0.0;
        }
        piVar4 = (int *)FUN_02565a6c(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        uStack00000058 = 0;
        piVar4 = *(int **)(DAT_0257bf44 + 0x257b010);
        in_stack_0000005c = &uStack000000ac;
        do {
          piVar8 = (int *)uStack000000ac;
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *(int *)uStack000000ac;
          uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar14 != 0) {
            piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar15[-1] == *unaff_r11) {
                puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
                goto LAB_0257b070;
              }
              uVar14 = uVar14 - 1;
              piVar15 = piVar15 + 2;
            } while (uVar14 != 0);
          }
          puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b070:
          iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
          piVar8 = (int *)uStack000000ac;
          if (iVar5 == 0) {
            FUN_00d98384(&uStack00000058);
            if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            puVar16 = *(undefined4 **)(DAT_0257c194 + 0x257b320);
            if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
            if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = FUN_03c38838(iVar5,5,*puVar16);
            if (iVar5 != 0) {
              if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
              if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              dVar26 = (double)FUN_03c384e8(iVar5,5,**(undefined4 **)(DAT_0257c198 + 0x257b380));
              dVar24 = dVar24 + dVar26;
            }
            piVar4 = (int *)FUN_02565eb4(in_stack_00000040);
            if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uStack000000ac._0_4_ =
                 (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
            uStack00000058 = 0;
            piVar4 = *(int **)(DAT_0257c19c + 0x257b3dc);
            in_stack_0000005c = &uStack000000ac;
            in_stack_00000060 = &uStack000000a8;
            goto LAB_0257b3d8;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *(int *)uStack000000ac;
          uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar14 != 0) {
            piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar15[-1] == *unaff_r11) {
                puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
                goto LAB_0257b108;
              }
              uVar14 = uVar14 - 1;
              piVar15 = piVar15 + 2;
            } while (uVar14 != 0);
          }
          puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b108:
          piVar8 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
          if ((*(byte *)(*piVar8 + 0xb8) < uVar14) ||
             (*(int *)(*(int *)(*piVar8 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar8);
          }
          if (piVar8[0x14] == 0) {
            if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (*(int *)(in_stack_00000038 + 0x14) < 0x12) goto LAB_0257b194;
            iVar5 = piVar8[0x14] + *(int *)(in_stack_00000038 + 0x14) + -0x12;
          }
          else {
LAB_0257b194:
            if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = *(int *)(in_stack_00000038 + 0x14) + piVar8[0x14];
          }
          piVar8[0x14] = iVar5;
          piVar15 = (int *)FUN_02565a6c(in_stack_00000044);
          if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
          if (piVar8[0xf] != 0) {
            dVar24 = dVar24 - (double)*(float *)(piVar8[0xf] + 0x2c);
          }
        } while( true );
      }
      iVar9 = *(int *)(in_stack_00000040 + 0xd4);
      iVar7 = 0;
      if (iVar9 != 0) {
        iVar7 = *(int *)(iVar9 + 8);
      }
      if ((iVar9 == 0 || iVar7 == 0) || ((1 < iVar5 && (iVar7 == 1)))) {
LAB_02579540:
        if (unaff_r7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = (**(code **)(*unaff_r7 + 0x170))(unaff_r7,*(undefined4 *)(*unaff_r7 + 0x174));
        if (0 < iVar7) {
          uVar10 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257a3f0 + 0x2579574));
          thunk_FUN_04776538(uVar10,unaff_r7,0);
          if (*(int *)(**(int **)(DAT_0257a3f4 + 0x2579598) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar10 = FUN_01f84a64(uVar10,0);
          iVar7 = (**(code **)(*unaff_r7 + 0x170))(unaff_r7,*(undefined4 *)(*unaff_r7 + 0x174));
          puVar16 = *(undefined4 **)(DAT_0257a5dc + 0x25795e4);
          if (1 < iVar7) {
            puVar16 = *(undefined4 **)(DAT_0257a5d0 + 0x25795dc);
          }
          if (bVar3) {
            puVar16 = *(undefined4 **)(DAT_0257a5d0 + 0x25795dc);
          }
          uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257a5e0 + 0x25795f0),uVar6,uVar10,
                                     *puVar16);
        }
        if (1 < iVar5) {
          piVar4 = (int *)FUN_02565674(in_stack_00000040);
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
          in_stack_00000060 = &uStack000000a8;
          in_stack_0000005c = &uStack000000ac;
          uStack00000058 = 0;
          bVar3 = true;
          bVar19 = true;
          do {
            piVar4 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = *(int *)uStack000000ac;
            uVar21 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar21 != 0) {
              piVar15 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar16 = (undefined4 *)(iVar7 + *piVar15 * 8 + 0xc0);
                  goto LAB_025796ec;
                }
                uVar21 = uVar21 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar21 != 0);
            }
            puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025796ec:
            iVar7 = (*(code *)*puVar16)(piVar4,puVar16[1]);
            piVar4 = (int *)uStack000000ac;
            if (iVar7 == 0) {
              FUN_00d98384(&uStack00000058);
              if (bVar19) {
                piVar4 = *(int **)(DAT_0257b0e4 + 0x257a170);
                if (iVar5 == 2) {
                  piVar4 = *(int **)(DAT_0257b0e0 + 0x257a168);
                }
                iVar7 = *piVar4;
                puVar16 = *(undefined4 **)((int)&DAT_0257a184 + DAT_0257b0e8);
              }
              else {
                puVar16 = *(undefined4 **)(DAT_0257b0ec + 0x257a1a0);
                if (bVar3) {
                  piVar4 = *(int **)(DAT_0257b0f4 + 0x257a1b8);
                  if (iVar5 == 2) {
                    piVar4 = *(int **)(DAT_0257b0f0 + 0x257a1b0);
                  }
                  iVar7 = *piVar4;
                }
                else {
                  iVar7 = **(int **)(&LAB_0257a1e4 + DAT_0257b0f8);
                }
              }
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              goto LAB_0257a1fc;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = *(int *)uStack000000ac;
            uVar21 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar21 != 0) {
              piVar15 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar15[-1] == *unaff_r11) {
                  puVar16 = (undefined4 *)(iVar7 + *piVar15 * 8 + 200);
                  goto LAB_02579764;
                }
                uVar21 = uVar21 - 1;
                piVar15 = piVar15 + 2;
              } while (uVar21 != 0);
            }
            puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_02579764:
            piVar4 = (int *)(*(code *)*puVar16)(piVar4,puVar16[1]);
            if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar21 = (uint)*(byte *)(**(int **)(DAT_0257a730 + 0x2579788) + 0xb8);
            if ((*(byte *)(*piVar4 + 0xb8) < uVar21) ||
               (*(int *)(*(int *)(*piVar4 + 100) + uVar21 * 4 + -4) !=
                **(int **)(DAT_0257a730 + 0x2579788))) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24();
            }
            piVar15 = in_stack_00000048;
            if (piVar4 != in_stack_00000048) {
              piVar15 = (int *)(uint)*(byte *)(piVar4 + 3);
            }
            if (piVar4 != in_stack_00000048 && piVar15 != (int *)0x0) {
              if (piVar4[4] == 0) {
                bVar3 = false;
              }
              else {
                bVar19 = (bool)(piVar4[4] != 1 & bVar19);
              }
            }
          } while( true );
        }
        iVar7 = *piVar8;
        puVar16 = *(undefined4 **)(&LAB_02579630 + DAT_0257a5e4);
LAB_0257a1fc:
        dVar27 = 0.0;
        if (*(int *)(in_stack_00000040 + 0xd0) == 0) {
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar9 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar10 = FUN_01a4e1f8(iVar9,0);
          if (*(int *)(**(int **)(DAT_0257b23c + 0x257a258) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          dVar27 = (double)FUN_01786018(SUB84(unaff_d8 - (double)fVar23,0),
                                        (int)((ulonglong)(unaff_d8 - (double)fVar23) >> 0x20),uVar10
                                        ,0);
        }
        iVar9 = *in_stack_00000018;
        fVar23 = (float)VectorSignedToFloat(iVar5,(byte)(uVar14 >> 0x16) & 3);
        dVar22 = (unaff_d8 - dVar27) / (double)fVar23;
        if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        *(double *)(iVar9 + 8) = dVar22 + *(double *)(iVar9 + 8);
        if (in_stack_0000003c == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar10 = *puVar16;
        *(double *)(in_stack_0000003c + 0x28) = dVar22;
        if (dVar27 == 0.0) {
          iVar5 = thunk_FUN_0105cca8(uVar10,4);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_00d99150(iVar5,uVar6);
          if (*(int *)(iVar5 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x10) = uVar6;
          FUN_00d99150(iVar5,iVar7);
          if (*(uint *)(iVar5 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar5 + 0x14) = iVar7;
          uVar6 = **(undefined4 **)(DAT_0257b2c8 + 0x257a350);
          if (dVar22 < 0.0) {
            piVar8 = *(int **)(DAT_0257b2cc + 0x257a358);
          }
          iVar7 = *piVar8;
          FUN_00d99150(iVar5,iVar7);
          if (*(uint *)(iVar5 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar5 + 0x18) = iVar7;
          if (*(int *)(**(int **)(DAT_0257b2d0 + 0x257a38c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          if (*(int *)(**(int **)(DAT_0257b2d4 + 0x257a3ac) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar10 = FUN_01f7f518(SUB84(ABS(dVar22),0),(int)((ulonglong)ABS(dVar22) >> 0x20),0);
          FUN_00d99150(iVar5,uVar10);
          if (*(uint *)(iVar5 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x1c) = uVar10;
        }
        else {
          iVar5 = thunk_FUN_0105cca8(uVar10,6);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_00d99150(iVar5,uVar6);
          if (*(int *)(iVar5 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x10) = uVar6;
          FUN_00d99150(iVar5,iVar7);
          if (*(uint *)(iVar5 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar5 + 0x14) = iVar7;
          uVar6 = **(undefined4 **)(DAT_0257b42c + 0x257a464);
          if (dVar22 < 0.0) {
            piVar8 = *(int **)(DAT_0257b430 + 0x257a46c);
          }
          iVar7 = *piVar8;
          FUN_00d99150(iVar5,iVar7);
          if (*(uint *)(iVar5 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar5 + 0x18) = iVar7;
          if (*(int *)(**(int **)(DAT_0257b434 + 0x257a4a0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          if (*(int *)(**(int **)(DAT_0257b4b0 + 0x257a4c4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar10 = FUN_01f7f518(SUB84(ABS(dVar22),0),(int)((ulonglong)ABS(dVar22) >> 0x20),0);
          FUN_00d99150(iVar5,uVar10);
          if (*(uint *)(iVar5 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x1c) = uVar10;
          uVar10 = FUN_01f7f518(SUB84(dVar27,0),(int)((ulonglong)dVar27 >> 0x20),0);
          FUN_00d99150(iVar5,uVar10);
          if (*(uint *)(iVar5 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x20) = uVar10;
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01a4e1f8(iVar7,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar10 = *(undefined4 *)(iVar7 + 0x1c);
          FUN_00d99150(iVar5,uVar10);
          if (*(uint *)(iVar5 + 0xc) < 6) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x24) = uVar10;
        }
        uVar6 = thunk_FUN_04662c44(uVar6,iVar5,0);
        bVar3 = true;
        bVar19 = true;
LAB_0257b958:
        piVar4 = (int *)FUN_02566890(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
        uStack00000058 = 0;
        piVar4 = *(int **)(DAT_0257c9a4 + 0x257b9ac);
        in_stack_0000005c = &uStack000000ac;
        in_stack_00000060 = &uStack000000a8;
        do {
          piVar8 = (int *)uStack000000ac;
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *(int *)uStack000000ac;
          uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar14 != 0) {
            piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar15[-1] == *unaff_r11) {
                puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
                goto LAB_0257ba08;
              }
              uVar14 = uVar14 - 1;
              piVar15 = piVar15 + 2;
            } while (uVar14 != 0);
          }
          puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257ba08:
          iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
          piVar8 = (int *)uStack000000ac;
          if (iVar5 == 0) {
            FUN_00d98384(&uStack00000058);
            if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            piVar4 = (int *)FUN_02567354(in_stack_00000040);
            if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uStack000000ac._0_4_ =
                 (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
            uStack00000058 = 0;
            piVar4 = *(int **)(DAT_0257cac4 + 0x257bbac);
            in_stack_0000005c = &uStack000000ac;
            in_stack_00000060 = &uStack000000a8;
            goto LAB_0257bba8;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *(int *)uStack000000ac;
          uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar14 != 0) {
            piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar15[-1] == *unaff_r11) {
                puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
                goto LAB_0257ba80;
              }
              uVar14 = uVar14 - 1;
              piVar15 = piVar15 + 2;
            } while (uVar14 != 0);
          }
          puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257ba80:
          piVar15 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
          piVar8 = (int *)0x0;
          if (piVar15 != (int *)0x0) {
            uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
            if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
               (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24();
            }
            piVar8 = piVar15;
          }
          piVar15 = (int *)FUN_02566890(in_stack_00000044);
          if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
        } while( true );
      }
      if (iVar7 == 3) {
        piVar4 = (int *)FUN_02565674(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        in_stack_0000005c = &uStack000000ac;
        uStack00000058 = 0;
        do {
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
          if (iVar7 == 0) {
            FUN_00d98384(&uStack00000058);
            goto LAB_025799dc;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar10 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
          iVar7 = FUN_00d98e30(uVar10,**(undefined4 **)(DAT_0257a88c + 0x25798e8));
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(iVar7 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar9 = FUN_01b9e854(*(int *)(iVar7 + 200),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar9 = thunk_FUN_0465f908(iVar9,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc)
                                     ,0);
        } while ((iVar9 == 0) || (*(char *)(iVar7 + 0xc) != '\0'));
        FUN_00d98384(&uStack00000058);
        goto LAB_02579540;
      }
LAB_025799dc:
      if (bVar19) goto LAB_02579540;
      if (bVar18) {
        if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_01d20174(*(int *)(in_stack_00000040 + 0x70),
                             *(undefined4 *)(in_stack_00000044 + 0x60),0);
        if (iVar5 == 0) {
          if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_01d20174(*(int *)(in_stack_00000040 + 0x70),
                               *(undefined4 *)(in_stack_00000044 + 0x58),0);
          if (iVar5 == 0) {
            if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = FUN_01d14e7c(*(int *)(in_stack_00000040 + 0x70),0);
            puVar16 = *(undefined4 **)(&LAB_02579c30 + DAT_0257ab40);
            if (iVar5 == 0) {
              puVar16 = *(undefined4 **)(DAT_0257ab3c + 0x2579c28);
            }
          }
          else {
            puVar16 = *(undefined4 **)(&LAB_02579bf8 + DAT_0257ab38);
          }
        }
        else {
          puVar16 = *(undefined4 **)((int)&DAT_02579a34 + DAT_0257a9d8);
        }
        uVar10 = *puVar16;
        iVar5 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257ab44 + 0x2579c3c),4);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_00d99150(iVar5,uVar6);
        if (*(int *)(iVar5 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x10) = uVar6;
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
        FUN_00d99150(iVar5,uVar6);
        if (*(uint *)(iVar5 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x14) = uVar6;
        uVar6 = **(undefined4 **)(DAT_0257ac94 + 0x2579cd8);
        puVar16 = *(undefined4 **)(DAT_0257ac9c + 0x2579ce8);
        if (unaff_d8 < 0.0) {
          puVar16 = *(undefined4 **)(DAT_0257ac98 + 0x2579ce0);
        }
        uVar13 = *puVar16;
        FUN_00d99150(iVar5,uVar13);
        if (*(uint *)(iVar5 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x18) = uVar13;
        FUN_00d99150(iVar5,uVar10);
        if (*(uint *)(iVar5 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x1c) = uVar10;
        uVar6 = thunk_FUN_04662c44(uVar6,iVar5,0);
      }
      else {
        piVar4 = (int *)FUN_02565674(in_stack_00000040);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        in_stack_0000005c = &uStack000000ac;
        uStack00000058 = 0;
        do {
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
          if (iVar5 == 0) {
            FUN_00d98384(&uStack00000058);
            iVar5 = FUN_02565bbc(in_stack_00000044);
            if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            FUN_0419a9e4(&uStack00000058,iVar5,**(undefined4 **)(DAT_0257adc8 + 0x2579dd4));
            uStack00000070 = CONCAT44(in_stack_0000005c,uStack00000058);
            in_stack_00000078 = CONCAT44(in_stack_00000064,in_stack_00000060);
            in_stack_0000005c = &uStack00000070;
            uStack00000058 = 0;
            puVar16 = *(undefined4 **)(DAT_0257adf8 + 0x2579e00);
            goto LAB_02579dfc;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar10 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
          iVar5 = FUN_00d98e30(uVar10,**(undefined4 **)(DAT_0257aa54 + 0x2579ae0));
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(iVar5 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b9e854(*(int *)(iVar5 + 8),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = thunk_FUN_0465f908(iVar7,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc)
                                     ,0);
          if (iVar7 != 0) break;
          if (*(int *)(iVar5 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = FUN_01b9e854(*(int *)(iVar5 + 200),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = thunk_FUN_0465f908(iVar7,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc)
                                     ,0);
        } while (iVar7 == 0);
        FUN_00d98384(&uStack00000058);
LAB_02579ee0:
        iVar7 = FUN_01d14e7c(iVar5,0);
        puVar16 = *(undefined4 **)(DAT_0257ae04 + 0x2579f04);
        if (iVar7 == 0) {
          puVar16 = *(undefined4 **)(DAT_0257ae00 + 0x2579efc);
        }
        if (*(int *)(iVar5 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar10 = thunk_FUN_04661ec4(*puVar16,**(undefined4 **)(DAT_0257ae08 + 0x2579f28),
                                    *(undefined4 *)(*(int *)(iVar5 + 8) + 0xc),0);
LAB_02579f38:
        iVar5 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257ae0c + 0x2579f48),8);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar5 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x10) = uVar6;
        if (*(uint *)(iVar5 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x14) = **(undefined4 **)(DAT_0257ae10 + 0x2579f88);
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
        if (*(uint *)(iVar5 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x18) = uVar6;
        if (*(uint *)(iVar5 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x1c) = **(undefined4 **)(DAT_0257ae14 + 0x2579fe4);
        uVar14 = *(uint *)(iVar5 + 0xc);
        puVar16 = *(undefined4 **)(DAT_0257ae1c + 0x257a00c);
        if (unaff_d8 < 0.0) {
          puVar16 = *(undefined4 **)(DAT_0257ae18 + 0x257a004);
        }
        if (uVar14 < 5) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x20) = *puVar16;
        if (uVar14 < 6) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x24) = **(undefined4 **)(DAT_0257ae20 + 0x257a038);
        if (uVar14 < 7) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x28) = uVar10;
        if (uVar14 < 8) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar5 + 0x2c) = **(undefined4 **)(DAT_0257b060 + 0x257a06c);
        uVar6 = thunk_FUN_04662824(iVar5,0);
      }
LAB_0257c1dc:
      iVar5 = FUN_02565794(in_stack_00000044);
      uVar10 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257d068 + 0x257c1f4));
      FUN_04199548(uVar10,**(undefined4 **)(DAT_0257d06c + 0x257c208));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar5 + 8) = uVar10;
    }
  }
LAB_0257c220:
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14) < 0x12) {
    if (in_stack_00000048 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_01d08764(in_stack_00000048,0);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(iVar5 + 0x6c) == '\0') {
      iVar5 = *(int *)(in_stack_00000044 + 0x58);
      if (iVar5 != 0) {
        if (*(char *)(iVar5 + 0xc) != '\0') goto LAB_0257c278;
        iVar5 = *(int *)(iVar5 + 0x1a4);
        cVar1 = '\0';
        if (iVar5 != 0) {
          cVar1 = *(char *)(iVar5 + 0xc);
        }
        if (iVar5 != 0 && cVar1 != '\0') goto LAB_0257c278;
      }
      iVar5 = *(int *)(in_stack_00000044 + 0x60);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar5 + 0x199) == '\0') {
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar5 + 0xc) != '\0') goto LAB_0257c278;
        iVar5 = *(int *)(in_stack_00000044 + 0x60);
      }
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar5 + 0x1a4) != 0) {
        if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)(*(int *)(in_stack_00000044 + 0x60) + 0x1a4);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar5 + 0xc) != '\0') goto LAB_0257c278;
      }
      if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar10 = FUN_01ac8cc8(*(int *)(in_stack_00000044 + 0x48),0);
      iVar5 = FUN_0257d0bc(uVar10,0);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar7 = *(int *)(iVar5 + 8);
      if (0 < iVar7) {
        iVar5 = thunk_FUN_0464f828(**(undefined4 **)(DAT_0257d070 + 0x257c784),iVar5,0);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = *(int *)(iVar5 + 8);
      }
      puVar16 = *(undefined4 **)(DAT_0257d07c + 0x257c7c0);
      if (0 < iVar7) {
        puVar16 = *(undefined4 **)(DAT_0257d078 + 0x257c7b8);
      }
      uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d074 + 0x257c7ac),uVar6,iVar5,*puVar16);
    }
  }
LAB_0257c278:
  if (in_stack_00000034 != 0) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(in_stack_00000040 + 0xb0);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 8) == 6)) {
      iVar5 = FUN_00d98e30(iVar5,**(undefined4 **)(DAT_0257d080 + 0x257c2b8));
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar5 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(*(int *)(iVar5 + 0x18) + 8) == 7) {
        iVar5 = FUN_00d98e30(*(undefined4 *)(iVar5 + 0x18),
                             **(undefined4 **)(DAT_0257d084 + 0x257c2f4));
        iVar7 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d088 + 0x257c310),6);
        if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar7 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x10) = uVar6;
        if (*(uint *)(iVar7 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x14) = **(undefined4 **)(DAT_0257d08c + 0x257c34c);
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        puVar16 = *(undefined4 **)(DAT_0257d094 + 0x257c380);
        if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
          puVar16 = *(undefined4 **)(DAT_0257d090 + 0x257c378);
        }
        if (*(uint *)(iVar7 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x18) = *puVar16;
        if (*(uint *)(iVar7 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x1c) = **(undefined4 **)(DAT_0257d098 + 0x257c3ac);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(iVar5 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar7 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(*(int *)(iVar5 + 0x18) + 8);
        if (*(uint *)(iVar7 + 0xc) < 6) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar7 + 0x24) = **(undefined4 **)(DAT_0257d09c + 0x257c400);
        uVar6 = thunk_FUN_04662824(iVar7,0);
      }
    }
  }
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = FUN_01d15f1c(*(int *)(in_stack_00000044 + 0x48),0);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_01a4e348(iVar5,0,0);
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = FUN_01d0dab4(*(int *)(in_stack_00000044 + 0x48),0);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_01a4e348(iVar5,0,0);
  piVar4 = (int *)FUN_02565ff4(in_stack_00000044);
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
  in_stack_00000060 = &uStack000000a8;
  in_stack_0000005c = &uStack000000ac;
  uStack00000058 = 0;
  piVar4 = *(int **)(DAT_0257d0a0 + 0x257c4f0);
  do {
    piVar8 = (int *)uStack000000ac;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)uStack000000ac;
    uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
    if (uVar14 != 0) {
      piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
      do {
        if (piVar15[-1] == *unaff_r11) {
          puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
          goto LAB_0257c550;
        }
        uVar14 = uVar14 - 1;
        piVar15 = piVar15 + 2;
      } while (uVar14 != 0);
    }
    puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257c550:
    iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
    piVar8 = (int *)uStack000000ac;
    if (iVar5 == 0) {
      FUN_00d98384(&uStack00000058);
      iVar5 = **(int **)(**(int **)(DAT_0257d0a4 + 0x257ca30) + 0x5c);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(in_stack_00000044 + 0x48);
      if (in_stack_00000024 == 0) {
        if (unaff_r9 != 0) {
          iVar5 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d0ac + 0x257cae0),5);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_00d99150(iVar5,uVar6);
          if (*(int *)(iVar5 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x10) = uVar6;
          uVar6 = FUN_01d42534(unaff_r9,1,0);
          FUN_00d99150(iVar5,uVar6);
          if (*(uint *)(iVar5 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x14) = uVar6;
          if (*(int *)(unaff_r9 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01ba8890(*(int *)(unaff_r9 + 8),0);
          FUN_00d99150(iVar5,uVar6);
          if (*(uint *)(iVar5 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x18) = uVar6;
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01d18c0c(in_stack_00000038,0);
          FUN_00d99150(iVar5,uVar6);
          if (*(uint *)(iVar5 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x1c) = uVar6;
          iVar7 = FUN_01d0dab4(unaff_r9,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01a4e1f8(iVar7,0);
          uVar10 = FUN_01d14e7c(unaff_r9,0);
          iVar7 = FUN_01d08764(unaff_r9,0);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar6 = FUN_01ad9d5c(uVar6,1,uVar10,*(undefined4 *)(iVar7 + 0x74));
          FUN_00d99150(iVar5,uVar6);
          if (*(uint *)(iVar5 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar5 + 0x20) = uVar6;
          uVar6 = thunk_FUN_04662c44(**(undefined4 **)(DAT_0257d0b0 + 0x257cc78),iVar5,0);
        }
      }
      else {
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar10 = FUN_01d18c0c(in_stack_00000038,0);
        if (*(int *)(in_stack_00000044 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar13 = FUN_01ad9c14(*(int *)(in_stack_00000044 + 0xd0),0,0);
        uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d0a8 + 0x257cab8),uVar6,uVar10,uVar13);
      }
      if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_0268300c(*(int *)(in_stack_00000044 + 0x28),uVar6,0);
      if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_02683508(*(int *)(in_stack_00000044 + 0x28),0);
      if (*(int *)(in_stack_00000044 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_02358098(*(int *)(in_stack_00000044 + 8),0);
      if (*(int *)(**(int **)(DAT_0257d0b4 + 0x257cce8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_02018748(1,0,0);
      return;
    }
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)uStack000000ac;
    uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
    if (uVar14 != 0) {
      piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
      do {
        if (piVar15[-1] == *unaff_r11) {
          puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
          goto LAB_0257c5cc;
        }
        uVar14 = uVar14 - 1;
        piVar15 = piVar15 + 2;
      } while (uVar14 != 0);
    }
    puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257c5cc:
    piVar8 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = *piVar4;
    iVar5 = *piVar8;
    uVar14 = (uint)*(byte *)(iVar7 + 0xb8);
    if ((*(byte *)(iVar5 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(iVar5 + 100) + uVar14 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar8);
    }
    if ((*(byte *)(iVar5 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(iVar5 + 100) + uVar14 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar8);
    }
    FUN_01a4e348(piVar8,0,0);
  } while( true );
LAB_0257a6dc:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257a740;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257a740:
  iVar5 = (*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_03c38838(iVar5,4,*puVar16);
    if (iVar5 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar26 = (double)FUN_03c384e8(iVar5,4,**(undefined4 **)(DAT_0257b8b4 + 0x257a92c));
      dVar24 = dVar24 + dVar26;
    }
    piVar4 = (int *)FUN_02565e2c(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar4 = *(int **)(DAT_0257b8b8 + 0x257a988);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257a984;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257a7b8;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257a7b8:
  piVar15 = (int *)(*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02565da4(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar8[7] != 0) {
    dVar24 = dVar24 - (double)*(float *)(piVar8[7] + 0x2c);
  }
  goto LAB_0257a6dc;
LAB_0257a984:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257a9e8;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257a9e8:
  iVar5 = (*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_03c38838(iVar5,7,*puVar16);
    if (iVar5 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar26 = (double)FUN_03c384e8(iVar5,7,**(undefined4 **)(DAT_0257bb2c + 0x257abe4));
      dVar24 = dVar24 + dVar26;
    }
    piVar4 = (int *)FUN_02565f6c(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar4 = *(int **)(&LAB_0257ac40 + DAT_0257bbfc);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257ac40;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257aa64;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257aa64:
  piVar15 = (int *)(*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02565e2c(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar8[8] != 0) {
    dVar24 = dVar24 - (double)*(float *)(piVar8[8] + 0x2c);
  }
  goto LAB_0257a984;
LAB_0257ac40:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257acac;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257acac:
  iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    iVar5 = **(int **)(**(int **)(DAT_0257bdfc + 0x257ae54) + 0x5c);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(iVar5 + 0x2c);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_024c3528(iVar5,0);
    if (iVar5 != 0) {
      iVar5 = **(int **)(**(int **)(DAT_0257be78 + 0x257ae98) + 0x5c);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = *(int *)(iVar5 + 0x24);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if ((*(char *)(iVar5 + 0x131) != '\0') && (0 < iVar11)) {
        puVar16 = *(undefined4 **)(DAT_0257be80 + 0x257aee8);
        if (iVar11 == 1) {
          puVar16 = *(undefined4 **)(DAT_0257be7c + 0x257aee0);
        }
        if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0268300c(*(int *)(in_stack_00000044 + 0x28),*puVar16,0);
      }
    }
    dVar22 = dVar22 - dVar24;
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    goto LAB_0257af28;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257ad24;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257ad24:
  piVar15 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02565f6c(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar8[0x10] != 0) {
    dVar24 = dVar24 - (double)*(float *)(piVar8[0x10] + 0x2c);
  }
  goto LAB_0257ac40;
LAB_0257b3d8:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257b444;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b444:
  iVar5 = (*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_03c38838(iVar5,6,*puVar16);
    if (iVar5 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar26 = (double)FUN_03c384e8(iVar5,6,**(undefined4 **)(DAT_0257c5bc + 0x257b618));
      dVar24 = dVar24 + dVar26;
    }
    piVar4 = (int *)FUN_02566f9c(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar4 = *(int **)(&LAB_0257b674 + DAT_0257c66c);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257b674;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar12 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257b4c0;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar12 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b4c0:
  piVar15 = (int *)(*(code *)*puVar12)(piVar8,puVar12[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02565eb4(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  goto LAB_0257b3d8;
LAB_0257b674:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257b6d8;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b6d8:
  iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    iVar5 = *in_stack_00000018;
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(iVar5 + 8) = (dVar22 - dVar24) + *(double *)(iVar5 + 8);
    if (in_stack_0000003c == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(in_stack_0000003c + 0x28) = dVar22 - dVar24;
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    bVar3 = false;
    if (*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) == '\0') {
      if (dVar27 == 0.0) {
        uVar6 = thunk_FUN_0464f828(**(undefined4 **)(DAT_0257c878 + 0x257b8ac),uVar6,0);
      }
      else {
        if (*(int *)(**(int **)(DAT_0257c8b0 + 0x257b8c8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar10 = FUN_01f7f518(SUB84(dVar27,0),(int)((ulonglong)dVar27 >> 0x20),0);
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_01d0dab4(in_stack_00000038,0);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_01a4e1f8(iVar5,0);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257c938 + 0x257b948),uVar6,uVar10,
                                   *(undefined4 *)(iVar5 + 0x1c));
      }
      bVar3 = false;
    }
    goto LAB_0257b958;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257b750;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b750:
  piVar15 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02566f9c(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  goto LAB_0257b674;
LAB_0257bba8:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257bc0c;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257bc0c:
  iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar4 = *(int **)(DAT_0257cda4 + 0x257bdac);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257bda8;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257bc84;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257bc84:
  piVar15 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_02567354(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  goto LAB_0257bba8;
LAB_0257bda8:
  piVar8 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 0xc0);
        goto LAB_0257be0c;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257be0c:
  iVar5 = (*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)uStack000000ac;
  if (iVar5 != 0) goto code_r0x0257be24;
  FUN_00d98384(&uStack00000058);
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar4 = (int *)FUN_025674b4(in_stack_00000040);
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
  uStack00000058 = 0;
  puVar16 = *(undefined4 **)(DAT_0257cf38 + 0x257bfc4);
  in_stack_0000005c = &uStack000000ac;
  in_stack_00000060 = &uStack000000a8;
  while( true ) {
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
    if (iVar5 == 0) break;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
    uVar10 = FUN_00d98e30(uVar10,*puVar16);
    piVar4 = (int *)FUN_025674b4(in_stack_00000044);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar4 + 0x1a8))(piVar4,uVar10,*(undefined4 *)(*piVar4 + 0x1ac));
  }
  FUN_00d98384(&uStack00000058);
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar4 = (int *)FUN_025693f0(in_stack_00000040);
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
  uStack00000058 = 0;
  puVar16 = *(undefined4 **)(&LAB_0257c0e8 + DAT_0257d064);
  in_stack_0000005c = &uStack000000ac;
  in_stack_00000060 = &uStack000000a8;
  while( true ) {
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
    if (iVar5 == 0) break;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
    uVar10 = FUN_00d98e30(uVar10,*puVar16);
    piVar4 = (int *)FUN_025693f0(in_stack_00000044);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar4 + 0x1a8))(piVar4,uVar10,*(undefined4 *)(*piVar4 + 0x1ac));
  }
  FUN_00d98384(&uStack00000058);
  if (bVar19 || (bVar18 || bVar3)) goto LAB_0257c1dc;
  goto LAB_0257c220;
code_r0x0257be24:
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)uStack000000ac;
  uVar14 = (uint)*(ushort *)(iVar5 + 0xb6);
  if (uVar14 != 0) {
    piVar15 = (int *)(*(int *)(iVar5 + 0x58) + 4);
    do {
      if (piVar15[-1] == *unaff_r11) {
        puVar16 = (undefined4 *)(iVar5 + *piVar15 * 8 + 200);
        goto LAB_0257be90;
      }
      uVar14 = uVar14 - 1;
      piVar15 = piVar15 + 2;
    } while (uVar14 != 0);
  }
  puVar16 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257be90:
  piVar15 = (int *)(*(code *)*puVar16)(piVar8,puVar16[1]);
  piVar8 = (int *)0x0;
  if (piVar15 != (int *)0x0) {
    uVar14 = (uint)*(byte *)(*piVar4 + 0xb8);
    if ((*(byte *)(*piVar15 + 0xb8) < uVar14) ||
       (*(int *)(*(int *)(*piVar15 + 100) + uVar14 * 4 + -4) != *piVar4)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar8 = piVar15;
  }
  piVar15 = (int *)FUN_025673dc(in_stack_00000044);
  if (piVar15 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar15 + 0x1a8))(piVar15,piVar8,*(undefined4 *)(*piVar15 + 0x1ac));
  goto LAB_0257bda8;
  while( true ) {
    if (*(int *)(iVar5 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = FUN_01b9e854(*(int *)(iVar5 + 200),0);
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = thunk_FUN_0465f908(iVar7,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
    if (iVar7 != 0) break;
LAB_02579dfc:
    iVar5 = FUN_03da6844(&uStack00000070,*puVar16);
    if (iVar5 == 0) {
      FUN_00d98eec(&uStack00000058);
      uVar10 = **(undefined4 **)(DAT_0257b0dc + 0x257a0f8);
      goto LAB_02579f38;
    }
    iVar5 = in_stack_00000078._4_4_;
    if (in_stack_00000078._4_4_ == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000078._4_4_ + 8) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = FUN_01b9e854(*(int *)(in_stack_00000078._4_4_ + 8),0);
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar7 = thunk_FUN_0465f908(iVar7,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
    if (iVar7 != 0) break;
  }
  FUN_00d98eec(&uStack00000058);
  goto LAB_02579ee0;
}


===== Life_IncrementAgeSimulation @ 0x2575e18 =====

void Life_IncrementAgeSimulation(void)

{
                    /* WARNING: Subroutine does not return */
  thunk_FUN_01064660();
}


===== Life_IncrementAgeUI @ 0x257b1ac =====

/* WARNING: Removing unreachable block (ram,0x0257b190) */
/* WARNING: Removing unreachable block (ram,0x0257b248) */

void Life_IncrementAgeUI(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  int *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int *piVar12;
  int unaff_r8;
  int *unaff_r9;
  int *unaff_r11;
  undefined1 in_ZR;
  double unaff_d8;
  double unaff_d9;
  double unaff_d10;
  double dVar13;
  int in_stack_00000014;
  int *in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  undefined4 uStack00000058;
  int *in_stack_000000ac;
  
code_r0x0257b1ac:
  if (!(bool)in_ZR) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = unaff_r7 + unaff_r5;
  do {
    unaff_r4[0x14] = iVar3;
    piVar4 = (int *)FUN_02565a6c(in_stack_00000044);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar4 + 0x1a8))(piVar4,unaff_r4,*(undefined4 *)(*piVar4 + 0x1ac));
    if (unaff_r6 != 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (unaff_r4[0xf] != 0) {
      unaff_d10 = unaff_d10 - (double)*(float *)(unaff_r4[0xf] + 0x2c);
    }
    if (in_stack_000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = *in_stack_000000ac;
    uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
    if (uVar10 != 0) {
      piVar4 = (int *)(*(int *)(iVar3 + 0x58) + 4);
      do {
        if (piVar4[-1] == *unaff_r11) {
          puVar2 = (undefined4 *)(iVar3 + *piVar4 * 8 + 0xc0);
          goto LAB_0257b070;
        }
        uVar10 = uVar10 - 1;
        piVar4 = piVar4 + 2;
      } while (uVar10 != 0);
    }
    puVar2 = (undefined4 *)FUN_0105aa50(in_stack_000000ac,*unaff_r11,0);
LAB_0257b070:
    iVar3 = (*(code *)*puVar2)(in_stack_000000ac,puVar2[1]);
    if (iVar3 == 0) {
      FUN_00d98384(&uStack00000058);
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      puVar2 = *(undefined4 **)(DAT_0257c194 + 0x257b320);
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = FUN_03c38838(iVar3,5,*puVar2);
      if (iVar3 != 0) {
        if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar3 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        dVar13 = (double)FUN_03c384e8(iVar3,5,**(undefined4 **)(DAT_0257c198 + 0x257b380));
        unaff_d10 = unaff_d10 + dVar13;
      }
      piVar4 = (int *)FUN_02565eb4(in_stack_00000040);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
      uStack00000058 = 0;
      piVar12 = *(int **)(DAT_0257c19c + 0x257b3dc);
      break;
    }
    if (in_stack_000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = *in_stack_000000ac;
    uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
    if (uVar10 != 0) {
      piVar4 = (int *)(*(int *)(iVar3 + 0x58) + 4);
      do {
        if (piVar4[-1] == *unaff_r11) {
          puVar2 = (undefined4 *)(iVar3 + *piVar4 * 8 + 200);
          goto LAB_0257b108;
        }
        uVar10 = uVar10 - 1;
        piVar4 = piVar4 + 2;
      } while (uVar10 != 0);
    }
    puVar2 = (undefined4 *)FUN_0105aa50(in_stack_000000ac,*unaff_r11,1);
LAB_0257b108:
    unaff_r4 = (int *)(*(code *)*puVar2)(in_stack_000000ac,puVar2[1]);
    if (unaff_r4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = (uint)*(byte *)(*unaff_r9 + 0xb8);
    if ((*(byte *)(*unaff_r4 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*unaff_r4 + 100) + uVar10 * 4 + -4) != *unaff_r9)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(unaff_r4);
    }
    unaff_r6 = 0;
    if (unaff_r4[0x14] != 0) goto LAB_0257b194;
    if (unaff_r8 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(unaff_r8 + 0x14) < 0x12) goto LAB_0257b194;
    iVar3 = unaff_r4[0x14] + *(int *)(unaff_r8 + 0x14) + -0x12;
    unaff_r8 = in_stack_00000038;
  } while( true );
LAB_0257b3d8:
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar5 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
        goto LAB_0257b444;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar5 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257b444:
  iVar3 = (*(code *)*puVar5)(piVar4,puVar5[1]);
  if (iVar3 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = FUN_03c38838(iVar3,6,*puVar2);
    if (iVar3 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar13 = (double)FUN_03c384e8(iVar3,6,**(undefined4 **)(DAT_0257c5bc + 0x257b618));
      unaff_d10 = unaff_d10 + dVar13;
    }
    piVar4 = (int *)FUN_02566f9c(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar12 = *(int **)(&LAB_0257b674 + DAT_0257c66c);
    goto LAB_0257b674;
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar5 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
        goto LAB_0257b4c0;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar5 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257b4c0:
  piVar6 = (int *)(*(code *)*puVar5)(piVar4,puVar5[1]);
  piVar11 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    uVar10 = (uint)*(byte *)(*piVar12 + 0xb8);
    if ((*(byte *)(*piVar6 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*piVar6 + 100) + uVar10 * 4 + -4) != *piVar12)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar11 = piVar6;
  }
  piVar6 = (int *)FUN_02565eb4(in_stack_00000044);
  if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar6 + 0x1a8))(piVar6,piVar11,*(undefined4 *)(*piVar6 + 0x1ac));
  goto LAB_0257b3d8;
LAB_0257b674:
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
        goto LAB_0257b6d8;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257b6d8:
  iVar3 = (*(code *)*puVar2)(piVar4,puVar2[1]);
  if (iVar3 == 0) {
    FUN_00d98384(&uStack00000058);
    iVar3 = *in_stack_00000018;
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(iVar3 + 8) = (unaff_d8 - unaff_d10) + *(double *)(iVar3 + 8);
    if (in_stack_0000003c == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(in_stack_0000003c + 0x28) = unaff_d8 - unaff_d10;
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) == '\0') {
      if (unaff_d9 == 0.0) {
        in_stack_00000028 =
             thunk_FUN_0464f828(**(undefined4 **)(DAT_0257c878 + 0x257b8ac),in_stack_00000028,0);
      }
      else {
        if (*(int *)(**(int **)(DAT_0257c8b0 + 0x257b8c8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar8 = FUN_01f7f518();
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar3 = FUN_01d0dab4(in_stack_00000038,0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar3 = FUN_01a4e1f8(iVar3,0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        in_stack_00000028 =
             thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257c938 + 0x257b948),in_stack_00000028,uVar8,
                                *(undefined4 *)(iVar3 + 0x1c));
      }
    }
    piVar4 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar12 = *(int **)(DAT_0257c9a4 + 0x257b9ac);
    goto LAB_0257b9a8;
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
        goto LAB_0257b750;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257b750:
  piVar6 = (int *)(*(code *)*puVar2)(piVar4,puVar2[1]);
  piVar11 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    uVar10 = (uint)*(byte *)(*piVar12 + 0xb8);
    if ((*(byte *)(*piVar6 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*piVar6 + 100) + uVar10 * 4 + -4) != *piVar12)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar11 = piVar6;
  }
  piVar6 = (int *)FUN_02566f9c(in_stack_00000044);
  if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar6 + 0x1a8))(piVar6,piVar11,*(undefined4 *)(*piVar6 + 0x1ac));
  goto LAB_0257b674;
LAB_0257b9a8:
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
        goto LAB_0257ba08;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257ba08:
  iVar3 = (*(code *)*puVar2)(piVar4,puVar2[1]);
  if (iVar3 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_02567354(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar12 = *(int **)(DAT_0257cac4 + 0x257bbac);
    goto LAB_0257bba8;
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
        goto LAB_0257ba80;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257ba80:
  piVar6 = (int *)(*(code *)*puVar2)(piVar4,puVar2[1]);
  piVar11 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    uVar10 = (uint)*(byte *)(*piVar12 + 0xb8);
    if ((*(byte *)(*piVar6 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*piVar6 + 100) + uVar10 * 4 + -4) != *piVar12)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar11 = piVar6;
  }
  piVar6 = (int *)FUN_02566890(in_stack_00000044);
  if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar6 + 0x1a8))(piVar6,piVar11,*(undefined4 *)(*piVar6 + 0x1ac));
  goto LAB_0257b9a8;
LAB_0257bba8:
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
        goto LAB_0257bc0c;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257bc0c:
  iVar3 = (*(code *)*puVar2)(piVar4,puVar2[1]);
  if (iVar3 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar12 = *(int **)(DAT_0257cda4 + 0x257bdac);
    goto LAB_0257bda8;
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
        goto LAB_0257bc84;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257bc84:
  piVar6 = (int *)(*(code *)*puVar2)(piVar4,puVar2[1]);
  piVar11 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    uVar10 = (uint)*(byte *)(*piVar12 + 0xb8);
    if ((*(byte *)(*piVar6 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*piVar6 + 100) + uVar10 * 4 + -4) != *piVar12)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar11 = piVar6;
  }
  piVar6 = (int *)FUN_02567354(in_stack_00000044);
  if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar6 + 0x1a8))(piVar6,piVar11,*(undefined4 *)(*piVar6 + 0x1ac));
  goto LAB_0257bba8;
LAB_0257bda8:
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
        goto LAB_0257be0c;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257be0c:
  iVar3 = (*(code *)*puVar2)(piVar4,puVar2[1]);
  if (iVar3 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_025674b4(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = (**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    puVar2 = *(undefined4 **)(DAT_0257cf38 + 0x257bfc4);
    while( true ) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar7 = FUN_00d98a08(0,*unaff_r11,iVar3);
      if (iVar7 == 0) break;
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar8 = FUN_00d98a08(1,*unaff_r11,iVar3);
      uVar8 = FUN_00d98e30(uVar8,*puVar2);
      piVar4 = (int *)FUN_025674b4(in_stack_00000044);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*piVar4 + 0x1a8))(piVar4,uVar8,*(undefined4 *)(*piVar4 + 0x1ac));
    }
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)FUN_025693f0(in_stack_00000040);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = (**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    puVar2 = *(undefined4 **)(&LAB_0257c0e8 + DAT_0257d064);
    while( true ) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar7 = FUN_00d98a08(0,*unaff_r11,iVar3);
      if (iVar7 == 0) break;
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar8 = FUN_00d98a08(1,*unaff_r11,iVar3);
      uVar8 = FUN_00d98e30(uVar8,*puVar2);
      piVar4 = (int *)FUN_025693f0(in_stack_00000044);
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*piVar4 + 0x1a8))(piVar4,uVar8,*(undefined4 *)(*piVar4 + 0x1ac));
    }
    FUN_00d98384(&uStack00000058);
    if (in_stack_0000001c != 0 || in_stack_00000014 != 0) {
      iVar3 = FUN_02565794(in_stack_00000044);
      uVar8 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257d068 + 0x257c1f4));
      FUN_04199548(uVar8,**(undefined4 **)(DAT_0257d06c + 0x257c208));
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar3 + 8) = uVar8;
    }
    if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14) < 0x12) {
      if (in_stack_00000048 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = FUN_01d08764(in_stack_00000048,0);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar3 + 0x6c) == '\0') {
        iVar3 = *(int *)(in_stack_00000044 + 0x58);
        if (iVar3 != 0) {
          if (*(char *)(iVar3 + 0xc) != '\0') goto LAB_0257c278;
          iVar3 = *(int *)(iVar3 + 0x1a4);
          cVar1 = '\0';
          if (iVar3 != 0) {
            cVar1 = *(char *)(iVar3 + 0xc);
          }
          if (!(iVar3 == 0 || cVar1 == '\0')) goto LAB_0257c278;
        }
        iVar3 = *(int *)(in_stack_00000044 + 0x60);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar3 + 0x199) == '\0') {
          if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(char *)(iVar3 + 0xc) != '\0') goto LAB_0257c278;
          iVar3 = *(int *)(in_stack_00000044 + 0x60);
        }
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(iVar3 + 0x1a4) != 0) {
          if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar3 = *(int *)(*(int *)(in_stack_00000044 + 0x60) + 0x1a4);
          if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(char *)(iVar3 + 0xc) != '\0') goto LAB_0257c278;
        }
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar8 = FUN_01ac8cc8(*(int *)(in_stack_00000044 + 0x48),0);
        iVar3 = FUN_0257d0bc(uVar8,0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = *(int *)(iVar3 + 8);
        if (0 < iVar7) {
          iVar3 = thunk_FUN_0464f828(**(undefined4 **)(DAT_0257d070 + 0x257c784),iVar3,0);
          if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = *(int *)(iVar3 + 8);
        }
        puVar2 = *(undefined4 **)(DAT_0257d07c + 0x257c7c0);
        if (0 < iVar7) {
          puVar2 = *(undefined4 **)(DAT_0257d078 + 0x257c7b8);
        }
        in_stack_00000028 =
             thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d074 + 0x257c7ac),in_stack_00000028,iVar3,
                                *puVar2);
      }
    }
LAB_0257c278:
    if (in_stack_00000034 != 0) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = *(int *)(in_stack_00000040 + 0xb0);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 8) == 6)) {
        iVar3 = FUN_00d98e30(iVar3,**(undefined4 **)(DAT_0257d080 + 0x257c2b8));
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(iVar3 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(*(int *)(iVar3 + 0x18) + 8) == 7) {
          iVar3 = FUN_00d98e30(*(undefined4 *)(iVar3 + 0x18),
                               **(undefined4 **)(DAT_0257d084 + 0x257c2f4));
          iVar7 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d088 + 0x257c310),6);
          if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(uint *)(iVar7 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x10) = in_stack_00000028;
          if (*(uint *)(iVar7 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x14) = **(undefined4 **)(DAT_0257d08c + 0x257c34c);
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar2 = *(undefined4 **)(DAT_0257d094 + 0x257c380);
          if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
            puVar2 = *(undefined4 **)(DAT_0257d090 + 0x257c378);
          }
          if (*(uint *)(iVar7 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x18) = *puVar2;
          if (*(uint *)(iVar7 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x1c) = **(undefined4 **)(DAT_0257d098 + 0x257c3ac);
          if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(iVar3 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(uint *)(iVar7 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(*(int *)(iVar3 + 0x18) + 8);
          if (*(uint *)(iVar7 + 0xc) < 6) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar7 + 0x24) = **(undefined4 **)(DAT_0257d09c + 0x257c400);
          in_stack_00000028 = thunk_FUN_04662824(iVar7,0);
        }
      }
    }
    if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = FUN_01d15f1c(*(int *)(in_stack_00000044 + 0x48),0);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    FUN_01a4e348(iVar3,0,0);
    if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = FUN_01d0dab4(*(int *)(in_stack_00000044 + 0x48),0);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    FUN_01a4e348(iVar3,0,0);
    piVar4 = (int *)FUN_02565ff4(in_stack_00000044);
    if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1e8))(piVar4,*(undefined4 *)(*piVar4 + 0x1ec));
    uStack00000058 = 0;
    piVar12 = *(int **)(DAT_0257d0a0 + 0x257c4f0);
    do {
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = *piVar4;
      uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
      if (uVar10 != 0) {
        piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
        do {
          if (piVar11[-1] == *unaff_r11) {
            puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 0xc0);
            goto LAB_0257c550;
          }
          uVar10 = uVar10 - 1;
          piVar11 = piVar11 + 2;
        } while (uVar10 != 0);
      }
      puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,0);
LAB_0257c550:
      iVar3 = (*(code *)*puVar2)(piVar4,puVar2[1]);
      if (iVar3 == 0) {
        FUN_00d98384(&uStack00000058);
        iVar3 = **(int **)(**(int **)(DAT_0257d0a4 + 0x257ca30) + 0x5c);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(in_stack_00000044 + 0x48);
        if (in_stack_00000024 == 0) {
          if (in_stack_00000030 != 0) {
            iVar3 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d0ac + 0x257cae0),5);
            if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            FUN_00d99150(iVar3,in_stack_00000028);
            if (*(int *)(iVar3 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_010646b0();
            }
            *(undefined4 *)(iVar3 + 0x10) = in_stack_00000028;
            uVar8 = FUN_01d42534(in_stack_00000030,1,0);
            FUN_00d99150(iVar3,uVar8);
            if (*(uint *)(iVar3 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_010646b0();
            }
            *(undefined4 *)(iVar3 + 0x14) = uVar8;
            if (*(int *)(in_stack_00000030 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar8 = FUN_01ba8890(*(int *)(in_stack_00000030 + 8),0);
            FUN_00d99150(iVar3,uVar8);
            if (*(uint *)(iVar3 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_010646b0();
            }
            *(undefined4 *)(iVar3 + 0x18) = uVar8;
            if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar8 = FUN_01d18c0c(in_stack_00000038,0);
            FUN_00d99150(iVar3,uVar8);
            if (*(uint *)(iVar3 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_010646b0();
            }
            *(undefined4 *)(iVar3 + 0x1c) = uVar8;
            iVar7 = FUN_01d0dab4(in_stack_00000030,0);
            if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar8 = FUN_01a4e1f8(iVar7,0);
            uVar9 = FUN_01d14e7c(in_stack_00000030,0);
            iVar7 = FUN_01d08764(in_stack_00000030,0);
            if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar8 = FUN_01ad9d5c(uVar8,1,uVar9,*(undefined4 *)(iVar7 + 0x74));
            FUN_00d99150(iVar3,uVar8);
            if (*(uint *)(iVar3 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_010646b0();
            }
            *(undefined4 *)(iVar3 + 0x20) = uVar8;
            in_stack_00000028 =
                 thunk_FUN_04662c44(**(undefined4 **)(DAT_0257d0b0 + 0x257cc78),iVar3,0);
          }
        }
        else {
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar8 = FUN_01d18c0c(in_stack_00000038,0);
          if (*(int *)(in_stack_00000044 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar9 = FUN_01ad9c14(*(int *)(in_stack_00000044 + 0xd0),0,0);
          in_stack_00000028 =
               thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d0a8 + 0x257cab8),in_stack_00000028,
                                  uVar8,uVar9);
        }
        if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0268300c(*(int *)(in_stack_00000044 + 0x28),in_stack_00000028,0);
        if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_02683508(*(int *)(in_stack_00000044 + 0x28),0);
        if (*(int *)(in_stack_00000044 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_02358098(*(int *)(in_stack_00000044 + 8),0);
        if (*(int *)(**(int **)(DAT_0257d0b4 + 0x257cce8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        FUN_02018748(1,0,0);
        return;
      }
      if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar3 = *piVar4;
      uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
      if (uVar10 != 0) {
        piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
        do {
          if (piVar11[-1] == *unaff_r11) {
            puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
            goto LAB_0257c5cc;
          }
          uVar10 = uVar10 - 1;
          piVar11 = piVar11 + 2;
        } while (uVar10 != 0);
      }
      puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257c5cc:
      piVar11 = (int *)(*(code *)*puVar2)(piVar4,puVar2[1]);
      if (piVar11 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar7 = *piVar12;
      iVar3 = *piVar11;
      uVar10 = (uint)*(byte *)(iVar7 + 0xb8);
      if ((*(byte *)(iVar3 + 0xb8) < uVar10) ||
         (*(int *)(*(int *)(iVar3 + 100) + uVar10 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
        FUN_0101fa24(piVar11);
      }
      if ((*(byte *)(iVar3 + 0xb8) < uVar10) ||
         (*(int *)(*(int *)(iVar3 + 100) + uVar10 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
        FUN_0101fa24(piVar11);
      }
      FUN_01a4e348(piVar11,0,0);
    } while( true );
  }
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *piVar4;
  uVar10 = (uint)*(ushort *)(iVar3 + 0xb6);
  if (uVar10 != 0) {
    piVar11 = (int *)(*(int *)(iVar3 + 0x58) + 4);
    do {
      if (piVar11[-1] == *unaff_r11) {
        puVar2 = (undefined4 *)(iVar3 + *piVar11 * 8 + 200);
        goto LAB_0257be90;
      }
      uVar10 = uVar10 - 1;
      piVar11 = piVar11 + 2;
    } while (uVar10 != 0);
  }
  puVar2 = (undefined4 *)FUN_0105aa50(piVar4,*unaff_r11,1);
LAB_0257be90:
  piVar6 = (int *)(*(code *)*puVar2)(piVar4,puVar2[1]);
  piVar11 = (int *)0x0;
  if (piVar6 != (int *)0x0) {
    uVar10 = (uint)*(byte *)(*piVar12 + 0xb8);
    if ((*(byte *)(*piVar6 + 0xb8) < uVar10) ||
       (*(int *)(*(int *)(*piVar6 + 100) + uVar10 * 4 + -4) != *piVar12)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar11 = piVar6;
  }
  piVar6 = (int *)FUN_025673dc(in_stack_00000044);
  if (piVar6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar6 + 0x1a8))(piVar6,piVar11,*(undefined4 *)(*piVar6 + 0x1ac));
  goto LAB_0257bda8;
LAB_0257b194:
  unaff_r5 = unaff_r4[0x14];
  if (unaff_r8 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  unaff_r7 = *(int *)(unaff_r8 + 0x14);
  in_ZR = true;
  goto code_r0x0257b1ac;
}


===== Sim_UpdateStatesForAge @ 0x1d18318 =====

float Sim_UpdateStatesForAge(void)

{
  float fVar1;
  undefined4 uVar2;
  int unaff_r4;
  int unaff_r5;
  int iVar3;
  int *unaff_r6;
  uint in_fpscr;
  float fVar4;
  
  if (**(int **)(*unaff_r6 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar3 = *(int *)(**(int **)(*unaff_r6 + 0x5c) + 0x10);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(iVar3 + 0x58) != 0) {
    if (**(int **)(*unaff_r6 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = *(int *)(**(int **)(*unaff_r6 + 0x5c) + 0x10);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar3 = *(int *)(iVar3 + 0x58);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    unaff_r4 = unaff_r4 + (uint)*(byte *)(iVar3 + 0xc);
  }
  if (unaff_r5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(unaff_r5 + 0x14) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  fVar1 = (float)FUN_01bb45b0(*(int *)(unaff_r5 + 0x14),0);
  if (*(int *)(**(int **)(DAT_01d18420 + 0x1d183cc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  uVar2 = thunk_FUN_047de608(unaff_r4,1,0);
  fVar4 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  return fVar1 / fVar4;
}


===== UnityEngine_Random_RangeFloat @ 0x5047db8 =====

void UnityEngine_Random_RangeFloat(void)

{
  code *unaff_r6;
  
  (*unaff_r6)();
  return;
}


===== UnityEngine_Random_RangeInt @ 0x5047e0c =====

void UnityEngine_Random_RangeInt(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int unaff_r4;
  int *piVar7;
  int unaff_r6;
  char *unaff_r7;
  bool bVar8;
  
  if (*unaff_r7 == '\0') {
    thunk_FUN_0101f410(*(undefined4 *)(DAT_05047fb0 + 0x5047e24));
    thunk_FUN_0101f410(*(undefined4 *)(DAT_05047fb4 + 0x5047e30));
    thunk_FUN_0101f410(*(undefined4 *)(DAT_05047fb8 + 0x5047e3c));
    *unaff_r7 = '\x01';
  }
  bVar8 = *(char *)(unaff_r4 + 0xc) != '\0';
  iVar1 = 0;
  if (bVar8) {
    iVar1 = *(int *)(unaff_r4 + 0x10);
  }
  if ((bVar8 && iVar1 != 4) && (1 < iVar1)) {
    piVar7 = *(int **)(unaff_r4 + 8);
    piVar2 = (int *)thunk_FUN_0105cca8(**(undefined4 **)(DAT_05047fbc + 0x5047e78),2);
    if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if ((unaff_r6 != 0) && (iVar1 = thunk_FUN_0105da7c(), iVar1 == 0)) {
      uVar3 = thunk_FUN_01065924();
      thunk_FUN_0101f51c(uVar3,0);
    }
    if (piVar2[3] == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar2[4] = unaff_r6;
    iVar1 = FUN_050473f8();
    if ((iVar1 != 0) &&
       (iVar4 = thunk_FUN_0105da7c(iVar1,*(undefined4 *)(*piVar2 + 0x20)), iVar4 == 0)) {
      uVar3 = thunk_FUN_01065924();
      thunk_FUN_0101f51c(uVar3,0);
    }
    if ((uint)piVar2[3] < 2) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar2[5] = iVar1;
    if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar1 = *piVar7;
    uVar3 = **(undefined4 **)(DAT_05047fc0 + 0x5047f38);
    uVar6 = (uint)*(ushort *)(iVar1 + 0xb6);
    if (uVar6 != 0) {
      piVar2 = (int *)(*(int *)(iVar1 + 0x58) + 4);
      do {
        if (piVar2[-1] == **(int **)(DAT_05047fc4 + 0x5047f44)) {
          puVar5 = (undefined4 *)(iVar1 + *piVar2 * 8 + 0xc0);
          goto LAB_05047f8c;
        }
        uVar6 = uVar6 - 1;
        piVar2 = piVar2 + 2;
      } while (uVar6 != 0);
    }
    puVar5 = (undefined4 *)thunk_FUN_0105aa50(piVar7,**(int **)(DAT_05047fc4 + 0x5047f44),0);
LAB_05047f8c:
    (*(code *)*puVar5)(piVar7,2,0,uVar3);
  }
  return;
}


===== ZooAnimal_GetHappiness @ 0x1bdb3cc =====

/* WARNING: Removing unreachable block (ram,0x01bdb570) */
/* WARNING: Removing unreachable block (ram,0x01bdb5cc) */

int ZooAnimal_GetHappiness(void)

{
  int iVar1;
  int iVar2;
  undefined1 *unaff_r4;
  int unaff_r5;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uStack00000008;
  undefined1 *in_stack_0000000c;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  undefined1 uStack00000018;
  undefined1 *puStack0000001c;
  undefined4 uStack00000020;
  int iStack00000024;
  undefined1 uStack00000028;
  undefined1 *puStack0000002c;
  undefined4 uStack00000030;
  int iStack00000034;
  
  *unaff_r4 = 1;
  puStack0000001c = *(undefined1 **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack00000020 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  iStack00000024 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  _uStack00000028 = 0;
  _uStack00000018 = 0;
  puStack0000002c = puStack0000001c;
  uStack00000030 = uStack00000020;
  iStack00000034 = iStack00000024;
  iVar1 = thunk_FUN_0105db90(**(undefined4 **)(DAT_01bdb66c + 0x1bdb3ec));
  thunk_FUN_04199548(iVar1,**(undefined4 **)(DAT_01bdb670 + 0x1bdb408));
  if (*(int *)(unaff_r5 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  thunk_FUN_0419a9e4(&uStack00000008,*(int *)(unaff_r5 + 0x40),
                     **(undefined4 **)(DAT_01bdb674 + 0x1bdb434));
  _uStack00000028 = uStack00000008;
  puStack0000002c = in_stack_0000000c;
  uStack00000030 = in_stack_00000010;
  iStack00000034 = in_stack_00000014;
  puVar5 = *(undefined4 **)(DAT_01bdb678 + 0x1bdb45c);
  piVar3 = *(int **)(DAT_01bdb67c + 0x1bdb464);
  do {
    iVar2 = thunk_FUN_03da6844(&uStack00000028,**(undefined4 **)(DAT_01bdb688 + 0x1bdb46c));
    if (iVar2 == 0) {
      thunk_FUN_03da6840(&uStack00000028,**(undefined4 **)(DAT_01bdb68c + 0x1bdb5bc));
      return iVar1;
    }
    if (iStack00000034 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(iStack00000034 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    thunk_FUN_0419a9e4(&uStack00000008,*(int *)(iStack00000034 + 0x28),
                       **(undefined4 **)(DAT_01bdb680 + 0x1bdb4a8));
    _uStack00000018 = uStack00000008;
    puStack0000001c = in_stack_0000000c;
    uStack00000020 = in_stack_00000010;
    iStack00000024 = in_stack_00000014;
    uStack00000008 = 0;
    in_stack_0000000c = &uStack00000018;
    while (iVar2 = thunk_FUN_03da6844(&uStack00000018,*puVar5), iVar2 != 0) {
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar6 = *(int *)(iVar1 + 8);
      uVar4 = *(uint *)(iVar1 + 0xc);
      iVar2 = *piVar3;
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
      if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (uVar4 < *(uint *)(iVar6 + 0xc)) {
        *(uint *)(iVar1 + 0xc) = uVar4 + 1;
        *(int *)(iVar6 + uVar4 * 4 + 0x10) = iStack00000024;
      }
      else {
        thunk_FUN_04199d54(iVar1,iStack00000024,
                           *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x10) + 0x60) + 0x38));
      }
    }
    thunk_FUN_03da6840(&uStack00000018,**(undefined4 **)(DAT_01bdb684 + 0x1bdb564));
  } while( true );
}


===== SimPerson_GetSmarts @ 0x1bdb8e8 =====

undefined4 SimPerson_GetSmarts(void)

{
  undefined4 *puVar1;
  uint unaff_r4;
  int unaff_r5;
  undefined1 *unaff_r6;
  
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9c8 + 0x1bdb8f4));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9cc + 0x1bdb900));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9d0 + 0x1bdb90c));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9d4 + 0x1bdb918));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9d8 + 0x1bdb924));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9dc + 0x1bdb930));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9e0 + 0x1bdb93c));
  FUN_0101f410(*(undefined4 *)(DAT_01bdb9e4 + 0x1bdb948));
  *unaff_r6 = 1;
  if (unaff_r4 < 0xb) {
    puVar1 = (undefined4 *)(DAT_01bdb9ec + 0x1bdb96c + unaff_r4 * 4);
    if (*(int *)(unaff_r5 + 0x1c) == 0) {
      puVar1 = (undefined4 *)(DAT_01bdb9f0 + 0x1bdb970 + unaff_r4 * 4);
    }
    puVar1 = (undefined4 *)*puVar1;
  }
  else {
    puVar1 = *(undefined4 **)(DAT_01bdb9e8 + 0x1bdb98c);
  }
  return *puVar1;
}


===== Life_ValidateAndSetScenario @ 0x2575954 =====

/* WARNING: Removing unreachable block (ram,0x02575d38) */
/* WARNING: Removing unreachable block (ram,0x02575c78) */
/* WARNING: Removing unreachable block (ram,0x02575d04) */
/* WARNING: Removing unreachable block (ram,0x0257b190) */
/* WARNING: Removing unreachable block (ram,0x0257b1f4) */
/* WARNING: Removing unreachable block (ram,0x0257746c) */
/* WARNING: Removing unreachable block (ram,0x02577478) */
/* WARNING: Removing unreachable block (ram,0x0257b1b0) */
/* WARNING: Removing unreachable block (ram,0x02575c28) */
/* WARNING: Removing unreachable block (ram,0x0257b248) */

void Life_ValidateAndSetScenario(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  char cVar17;
  int unaff_r5;
  undefined4 *puVar18;
  int *unaff_r6;
  int iVar19;
  int *piVar20;
  int iVar21;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  int *unaff_r11;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  uint in_fpscr;
  double unaff_d8;
  double dVar25;
  double unaff_d9;
  float fVar26;
  double dVar27;
  undefined8 uVar28;
  double dVar29;
  double dVar30;
  int *in_stack_00000018;
  int in_stack_0000001c;
  int *piStack00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  int *in_stack_00000048;
  undefined4 uStack00000058;
  undefined8 *in_stack_0000005c;
  undefined4 *in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined8 uStack00000070;
  undefined8 in_stack_00000078;
  undefined1 uStack00000080;
  int in_stack_0000008c;
  undefined4 uStack000000a8;
  undefined8 uStack000000ac;
  
  while( true ) {
    iVar11 = in_stack_00000048[5];
    iVar13 = *(int *)(unaff_r5 + 0x1c);
    iVar15 = *(int *)(unaff_r5 + 0x20);
    iVar21 = *(int *)(unaff_r5 + 0x24);
    unaff_r6[0xf] = (unaff_r8 - unaff_r9) + unaff_r7;
    iVar11 = iVar11 - unaff_r9;
    *(int *)(unaff_r5 + 0x1c) = iVar11 + iVar13;
    *(int *)(unaff_r5 + 0x20) = iVar11 + iVar15;
    *(int *)(unaff_r5 + 0x24) = iVar11 + iVar21;
    puVar18 = *(undefined4 **)(DAT_025764bc + 0x25756d4);
    do {
      iVar11 = FUN_03da6844(&uStack00000080,*puVar18);
      if (iVar11 == 0) {
        FUN_00d9c908(&uStack00000058);
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        bVar3 = false;
        piStack00000030 = (int *)0x0;
        if (*(char *)(in_stack_00000038 + 0xc) != '\0') goto LAB_025759e4;
        if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        bVar3 = false;
        if (*(int *)(in_stack_00000040 + 0xd0) == 0) {
          piStack00000030 = (int *)0x0;
          goto LAB_025759e4;
        }
        iVar11 = FUN_01ad9f1c(*(int *)(in_stack_00000040 + 0xd0),0);
        piStack00000030 = (int *)0x0;
        if (iVar11 == 0) goto LAB_025759e4;
        iVar11 = **(int **)(**(int **)(DAT_025768a4 + 0x2575b20) + 0x5c);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = *(int *)(iVar11 + 0x10);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_02565bbc(iVar11);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0419a9e4(&uStack00000058,iVar11,**(undefined4 **)(DAT_02576b28 + 0x2575b70));
        uStack00000070 = CONCAT44(in_stack_0000005c,uStack00000058);
        in_stack_00000078 = CONCAT44(in_stack_00000064,in_stack_00000060);
        in_stack_0000005c = &uStack00000070;
        uStack00000058 = 0;
        puVar18 = *(undefined4 **)(DAT_02576b2c + 0x2575ba0);
        piVar20 = *(int **)(&LAB_02575ba8 + DAT_02576b30);
        piStack00000030 = (int *)0x0;
        iVar11 = 0;
        goto LAB_02575ba8;
      }
      if (in_stack_0000008c == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(int *)(in_stack_0000008c + 0x1c) =
           (in_stack_00000048[5] - unaff_r9) + *(int *)(in_stack_0000008c + 0x1c);
    } while ((*(int *)(in_stack_0000008c + 0x14) != 0x12) &&
            (9 < *(int *)(in_stack_0000008c + 0x14) - 1U));
    piVar20 = *(int **)(in_stack_0000008c + 0x10);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = **(int **)(DAT_025764c0 + 0x2575744);
    iVar11 = *piVar20;
    uVar12 = (uint)*(byte *)(iVar13 + 0xb8);
    uVar14 = (uint)*(byte *)(iVar11 + 0xb8);
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar20);
    }
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) break;
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar20);
    }
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) break;
    unaff_r6 = *(int **)(in_stack_0000008c + 0x10);
    unaff_r8 = in_stack_00000048[5];
    piVar20[0x10] = (in_stack_00000048[5] - unaff_r9) + piVar20[0x10];
    if (unaff_r6 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *unaff_r6;
    uVar12 = (uint)*(byte *)(iVar13 + 0xb8);
    uVar14 = (uint)*(byte *)(iVar11 + 0xb8);
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(unaff_r6);
    }
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(unaff_r6);
    }
    unaff_r7 = unaff_r6[0xf];
    if ((uVar14 < uVar12) || (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(unaff_r6);
    }
    if ((uVar14 < uVar12) ||
       (unaff_r5 = in_stack_0000008c, *(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13))
    {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(unaff_r6);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0101fa24(piVar20);
LAB_02575ba8:
  do {
    iVar13 = FUN_03da6844(&uStack00000070,*puVar18);
    if (iVar13 == 0) {
      FUN_00d98eec(&uStack00000058);
      goto LAB_02578bac;
    }
    piVar7 = in_stack_00000078._4_4_;
    if (in_stack_00000078._4_4_ == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*in_stack_00000078._4_4_ + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*in_stack_00000078._4_4_ + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(in_stack_00000078._4_4_);
    }
    cVar17 = '\0';
    if ((char)in_stack_00000078._4_4_[3] == '\0') {
      cVar17 = -0x30;
    }
    if (cVar17 == '\0') {
      iVar13 = FUN_01d08764(in_stack_00000078._4_4_,0);
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      cVar17 = '\0';
      if (*(char *)(iVar13 + 0x6c) == '\0') {
        cVar17 = -0x30;
      }
      if (cVar17 == '\0') {
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        cVar17 = '\0';
        if (*(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14) < piVar7[5]) {
          cVar17 = -0x2e;
        }
        if (cVar17 == '\0') {
          if (in_stack_00000048 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01d08764(in_stack_00000048,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          cVar17 = '\0';
          if (*(char *)(iVar13 + 0x6c) != '\0') {
            cVar17 = -0x30;
          }
          if (cVar17 != '\0') goto LAB_02575c60;
        }
        else if (cVar17 != -0x2e) break;
        cVar17 = -0x30;
        if (iVar11 < piVar7[5]) {
          cVar17 = '\0';
        }
        if (cVar17 != -0x30) {
          if (cVar17 != '\0') break;
          piStack00000030 = piVar7;
          iVar11 = piVar7[5];
        }
        goto LAB_02575ba8;
      }
    }
LAB_02575c60:
  } while (cVar17 == -0x30);
  FUN_00d98eec(&uStack00000058);
  if (cVar17 != '\0') {
    return;
  }
LAB_02578bac:
  if (piStack00000030 == (int *)0x0) {
    if (in_stack_00000048 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_01d08764(in_stack_00000048,0);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    bVar3 = false;
    if (*(char *)(iVar11 + 0x6c) != '\0') {
      bVar3 = true;
      iVar11 = *(int *)(in_stack_00000044 + 0xd0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar11 + 0xc) = 1;
      iVar13 = *(int *)(in_stack_00000044 + 0x48);
      *(undefined4 *)(iVar11 + 0x1c) = 0;
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar15 = *(int *)(iVar13 + 8);
      iVar11 = FUN_01d0dab4(iVar13,0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = FUN_01a4e1f8(iVar11,0);
      if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar5 = FUN_01d14e7c(*(int *)(in_stack_00000044 + 0x48),0);
      uVar4 = FUN_01ad9680(uVar4,1,uVar5,1);
      if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = *(int *)(in_stack_00000044 + 0x48);
      iVar11 = *(int *)(in_stack_00000044 + 0xd0);
      *(undefined4 *)(iVar15 + 0x18) = uVar4;
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = *(undefined4 *)(iVar11 + 0xc);
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar5 = *(undefined4 *)(iVar13 + 0x10);
      if (*(int *)(in_stack_00000044 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      cVar17 = *(char *)(*(int *)(in_stack_00000044 + 0xd0) + 0x14);
      if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = FUN_01d0dab4(*(int *)(in_stack_00000044 + 0x48),0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = FUN_01a4e1f8(iVar11,0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = FUN_012a93a0(uVar4,uVar5,cVar17 != '\0',*(undefined4 *)(iVar11 + 0x10));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = *(int *)(in_stack_00000044 + 0xd0);
      iVar15 = *(int *)(in_stack_00000044 + 0x48);
      *(undefined4 *)(iVar13 + 0x38) = uVar4;
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = FUN_01ada1c0(iVar11,0);
      if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
      *(undefined4 *)(iVar15 + 0x8c) = uVar4;
    }
    if (in_stack_00000048 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_01d08764(in_stack_00000048,0);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(iVar11 + 0x6c) != '\0') goto LAB_02578ea0;
  }
  else {
    bVar3 = false;
    iVar11 = FUN_01d08764(piStack00000030,0);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    FUN_01d3d610(iVar11,1,0);
LAB_02578ea0:
    if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(*(int *)(in_stack_00000044 + 0x60) + 0xc) != '\0') {
      if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = FUN_01d08764(*(int *)(in_stack_00000044 + 0x60),0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar11 + 0x6c) != '\0') {
        if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_01d08764(*(int *)(in_stack_00000044 + 0x60),0);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        *(undefined1 *)(iVar11 + 0x79) = 1;
      }
    }
  }
  if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
LAB_025759e4:
  uVar4 = FUN_01d18c0c(in_stack_00000038,0);
  if (*(int *)(in_stack_00000038 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar5 = FUN_01b9e854(*(int *)(in_stack_00000038 + 8),0);
  uVar4 = thunk_FUN_04662ba0(**(undefined4 **)(DAT_0257689c + 0x2575a2c),uVar4,uVar5,0);
  if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x54) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x54) + 0xc);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = thunk_FUN_04664390(iVar11,**(undefined4 **)(DAT_02576d94 + 0x2575dac),uVar4,0);
  }
  else {
    uVar4 = FUN_01d18c0c(in_stack_00000038,0);
    if (*(int *)(in_stack_00000038 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar5 = FUN_01b9e854(*(int *)(in_stack_00000038 + 8),0);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
    iVar11 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_025768a0 + 0x2575abc),uVar4,uVar5,uVar6);
  }
  puVar18 = *(undefined4 **)(DAT_02576d98 + 0x2575dc4);
  piVar20 = (int *)thunk_FUN_0105db90(*puVar18);
  thunk_FUN_0476f85c(piVar20,0);
  piVar7 = (int *)thunk_FUN_0105db90(*puVar18);
  thunk_FUN_0476f85c(piVar7,0);
  iVar13 = FUN_02565a6c(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565a6c(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (iVar13 < 1) goto LAB_02575e3c;
LAB_02576160:
    iVar13 = FUN_02565a6c(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565a6c(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565a6c(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565a6c(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_0257715c + 0x2576220));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = FUN_01b8c918(iVar13,0,0,0);
          if (*(int *)(**(int **)(DAT_02577160 + 0x2576260) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(uVar4,**(undefined4 **)(DAT_02577164 + 0x2576280),0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_025772b0 + 0x25762d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_025772b4 + 0x2576308),uVar4,0);
        }
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
      }
    }
    iVar13 = FUN_02565af4(in_stack_00000040);
    bVar2 = false;
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565af4(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565af4(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565af4(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02577444 + 0x2576504));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b7aa54(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = *(undefined4 *)(iVar15 + 8);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b7aa54(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar18 = *(undefined4 **)(DAT_0257754c + 0x2576574);
          uVar4 = thunk_FUN_04662ba0(*puVar18,uVar4,*(undefined4 *)(iVar15 + 0xc),0);
          if (*(int *)(**(int **)(DAT_02577550 + 0x257658c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(uVar4,**(undefined4 **)(DAT_02577554 + 0x25765ac),0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b7aa54(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = *(undefined4 *)(iVar15 + 8);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          bVar2 = false;
          iVar13 = FUN_01b7aa54(iVar13,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = thunk_FUN_04662ba0(*puVar18,uVar4,*(undefined4 *)(iVar13 + 0xc),0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_025773a4 + 0x2576404) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          puVar18 = *(undefined4 **)(DAT_02577418 + 0x2576434);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          piVar8 = (int *)FUN_02565af4(in_stack_00000040);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          bVar2 = true;
        }
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar7 + 0x1a8))(piVar7,uVar4,*(undefined4 *)(*piVar7 + 0x1ac));
      }
    }
    iVar13 = FUN_02565da4(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565da4(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565da4(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565da4(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02577668 + 0x2576740));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b780c8(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = *(undefined4 *)(iVar15 + 0xc);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b780c8(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar18 = *(undefined4 **)(DAT_02577754 + 0x25767b4);
          uVar4 = thunk_FUN_04662ba0(*puVar18,uVar4,*(undefined4 *)(iVar15 + 0x10),0);
          if (*(int *)(**(int **)(DAT_02577758 + 0x25767cc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(uVar4,**(undefined4 **)(DAT_0257775c + 0x25767ec),0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b780c8(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = *(undefined4 *)(iVar15 + 0xc);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01b780c8(iVar13,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = thunk_FUN_04662ba0(*puVar18,uVar4,*(undefined4 *)(iVar13 + 0x10),0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_0257786c + 0x25768d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          puVar18 = *(undefined4 **)(DAT_02577870 + 0x2576908);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          piVar8 = (int *)FUN_02565da4(in_stack_00000040);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          bVar2 = true;
        }
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar7 + 0x1a8))(piVar7,uVar4,*(undefined4 *)(*piVar7 + 0x1ac));
      }
    }
    iVar13 = FUN_02565e2c(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565e2c(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565e2c(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565e2c(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02577960 + 0x2576a68));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01bc6598(iVar13,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_02577a70 + 0x2576aa4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(*(undefined4 *)(iVar15 + 0xc),
                               **(undefined4 **)(DAT_02577a74 + 0x2576ac8),0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01bc6598(iVar13,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = *(undefined4 *)(iVar13 + 0xc);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_02577a78 + 0x2576b64) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          puVar18 = *(undefined4 **)(DAT_02577b6c + 0x2576b94);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          piVar8 = (int *)FUN_02565e2c(in_stack_00000040);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          bVar2 = true;
        }
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar7 + 0x1a8))(piVar7,uVar4,*(undefined4 *)(*piVar7 + 0x1ac));
      }
    }
    iVar13 = FUN_02565f6c(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565f6c(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565f6c(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565f6c(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02577c8c + 0x2576cf4));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = FUN_01b51e94(iVar13,0);
          if (*(int *)(**(int **)(DAT_02577c90 + 0x2576d24) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(uVar4,**(undefined4 **)(DAT_02577c94 + 0x2576d44),0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = FUN_01b51e94(iVar13,0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_02577d84 + 0x2576dcc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          puVar18 = *(undefined4 **)(DAT_02577d88 + 0x2576dfc);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
          piVar8 = (int *)FUN_02565f6c(in_stack_00000040);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
          bVar2 = true;
        }
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar7 + 0x1a8))(piVar7,uVar4,*(undefined4 *)(*piVar7 + 0x1ac));
      }
    }
    iVar13 = FUN_02565eb4(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02565eb4(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02565eb4(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02565eb4(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          piVar8 = (int *)FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02577ec4 + 0x2576f5c));
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0xe8))(piVar8,*(undefined4 *)(*piVar8 + 0xec));
          if (*(int *)(**(int **)(DAT_02577ec8 + 0x2576f94) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(uVar4,**(undefined4 **)(DAT_02577ecc + 0x2576fb4),0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_02577fbc + 0x2576ff0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_02577fc0 + 0x2577020),uVar4,0);
        }
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
      }
    }
    iVar13 = FUN_02566f9c(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02566f9c(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (0 < iVar13) {
        piVar8 = (int *)FUN_02566f9c(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        piVar8 = (int *)FUN_02566f9c(in_stack_00000040);
        if (iVar13 == 1) {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
          iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_025780a4 + 0x257710c));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_025780a8 + 0x257712c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f83354(*(undefined4 *)(iVar13 + 8),
                               **(undefined4 **)(DAT_025780ac + 0x2577150),0);
        }
        else {
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
          if (*(int *)(**(int **)(DAT_025780b0 + 0x2577198) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar4 = FUN_01f8250c(uVar4,0);
          uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_025780b4 + 0x25771c8),uVar4,0);
        }
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
      }
    }
    iVar13 = FUN_02566890(in_stack_00000040);
    if (iVar13 != 0) {
      piVar8 = (int *)FUN_02566890(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uStack000000ac._0_4_ =
           (int *)(**(code **)(*piVar8 + 0x1e8))(piVar8,*(undefined4 *)(*piVar8 + 0x1ec));
      in_stack_00000060 = &uStack000000a8;
      in_stack_0000005c = &uStack000000ac;
      uStack00000058 = 0;
      piVar8 = *(int **)(DAT_02578200 + 0x2577264);
      fVar26 = DAT_02577558;
      do {
        piVar9 = (int *)uStack000000ac;
        if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = *(int *)uStack000000ac;
        uVar12 = (uint)*(ushort *)(iVar13 + 0xb6);
        if (uVar12 != 0) {
          piVar16 = (int *)(*(int *)(iVar13 + 0x58) + 4);
          do {
            if (piVar16[-1] == *unaff_r11) {
              puVar18 = (undefined4 *)(iVar13 + *piVar16 * 8 + 0xc0);
              goto LAB_025772c4;
            }
            uVar12 = uVar12 - 1;
            piVar16 = piVar16 + 2;
          } while (uVar12 != 0);
        }
        puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025772c4:
        iVar13 = (*(code *)*puVar18)(piVar9,puVar18[1]);
        piVar9 = (int *)uStack000000ac;
        if (iVar13 == 0) {
          piVar16 = *(int **)(DAT_02578204 + 0x25773bc);
          piVar9 = (int *)thunk_FUN_0105da7c((int *)uStack000000ac,*piVar16);
          uStack000000a8 = piVar9;
          if (piVar9 == (int *)0x0) goto LAB_02577464;
          iVar13 = *piVar9;
          iVar15 = *piVar16;
          uVar12 = (uint)*(ushort *)(iVar13 + 0xb6);
          if (uVar12 == 0) goto LAB_02577408;
          piVar16 = (int *)(*(int *)(iVar13 + 0x58) + 4);
          goto LAB_025773f0;
        }
        if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = *(int *)uStack000000ac;
        uVar12 = (uint)*(ushort *)(iVar13 + 0xb6);
        if (uVar12 != 0) {
          piVar16 = (int *)(*(int *)(iVar13 + 0x58) + 4);
          do {
            if (piVar16[-1] == *unaff_r11) {
              puVar18 = (undefined4 *)(iVar13 + *piVar16 * 8 + 200);
              goto LAB_0257733c;
            }
            uVar12 = uVar12 - 1;
            piVar16 = piVar16 + 2;
          } while (uVar12 != 0);
        }
        puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257733c:
        piVar9 = (int *)(*(code *)*puVar18)(piVar9,puVar18[1]);
        if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = *piVar8;
        uVar12 = (uint)*(byte *)(iVar13 + 0xb8);
        if ((*(byte *)(*piVar9 + 0xb8) < uVar12) ||
           (*(int *)(*(int *)(*piVar9 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
          FUN_0101fa24(piVar9);
        }
        fVar26 = fVar26 + (float)piVar9[6];
      } while( true );
    }
    iVar13 = FUN_02567354(in_stack_00000040);
    fVar26 = DAT_02577558;
    if (iVar13 != 0) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      goto LAB_02577684;
    }
    goto LAB_0257784c;
  }
LAB_02575e3c:
  iVar13 = FUN_02565af4(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565af4(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02566890(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02565da4(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565da4(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02565e2c(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565e2c(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02565f6c(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565f6c(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02565eb4(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02565eb4(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02566f9c(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02566f9c(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_02567354(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_02567354(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_025673dc(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_025674b4(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025674b4(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
  iVar13 = FUN_025693f0(in_stack_00000040);
  fVar26 = DAT_025764d0;
  bVar2 = false;
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025693f0(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (0 < iVar13) goto LAB_02576160;
  }
LAB_02577e78:
  if (in_stack_00000034 != 0) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    goto LAB_02578164;
  }
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
LAB_02577ed4:
  if ((*(int *)(in_stack_00000040 + 0x70) == 0) ||
     (*(int *)(*(int *)(in_stack_00000040 + 0x70) + 0x1c4) != 3)) {
    iVar13 = *(int *)(in_stack_00000040 + 0xb0);
    if ((iVar13 != 0) && (*(int *)(iVar13 + 8) == 6)) {
      iVar13 = FUN_00d98e30(iVar13,**(undefined4 **)(DAT_02578fcc + 0x2577fec));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar13 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(*(int *)(iVar13 + 0x18) + 8) == 7) {
        iVar13 = FUN_00d98e30(*(undefined4 *)(iVar13 + 0x18),
                              **(undefined4 **)(DAT_02578fd0 + 0x2578028));
        if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar15 = *(int *)(iVar13 + 0x18);
        if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar15 + 0x88) == '\0') {
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(char *)(iVar15 + 0x89) == '\0') goto LAB_02578164;
          iVar15 = *(int *)(iVar13 + 0x18);
        }
        if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = *(undefined4 *)(iVar15 + 8);
        uVar28 = FUN_01c93dcc(iVar15,0,0);
        if (*(int *)(**(int **)(DAT_02578fd4 + 0x25780fc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar5 = FUN_01f7f518((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
        uVar4 = thunk_FUN_04662ba0(**(undefined4 **)(DAT_02578fd8 + 0x2578134),uVar4,uVar5,0);
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
      }
    }
    goto LAB_02578164;
  }
  iVar13 = *(int *)(in_stack_00000040 + 0xb0);
  if ((iVar13 != 0) && (*(int *)(iVar13 + 8) == 6)) {
    iVar13 = FUN_00d98e30(iVar13,**(undefined4 **)(DAT_02578ca0 + 0x2577f18));
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(iVar13 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(*(int *)(iVar13 + 0x18) + 8) == 7) {
      iVar13 = FUN_00d98e30(*(undefined4 *)(iVar13 + 0x18),
                            **(undefined4 **)(DAT_02578ca4 + 0x2577f54));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar15 = *(int *)(iVar13 + 0x18);
      if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar15 + 0x88) == '\0') {
        if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar15 + 0x89) == '\0') goto LAB_025789e0;
        iVar15 = *(int *)(iVar13 + 0x18);
      }
      if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = *(undefined4 *)(iVar15 + 8);
      uVar28 = FUN_01c93dcc(iVar15,0,0);
      if (*(int *)(**(int **)(DAT_02579830 + 0x2578948) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar5 = FUN_01f7f518((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
      uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257999c + 0x25789ac),uVar4,uVar5,uVar6);
      if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
    }
  }
LAB_025789e0:
  if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  dVar30 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
  uVar12 = in_fpscr & 0xfffffff | (uint)(dVar30 == -10.0) << 0x1e;
  uVar14 = uVar12 | (uint)(-10.0 <= dVar30) << 0x1d;
  if (!(bool)((byte)(uVar14 >> 0x1d) & 1) || SUB41(uVar12 >> 0x1e,0)) {
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar4 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
    puVar18 = *(undefined4 **)(DAT_02579a38 + 0x2578aa0);
LAB_02578a9c:
    uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
  }
  else {
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    dVar30 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
    uVar12 = in_fpscr & 0xfffffff | (uint)(dVar30 < 10.0) << 0x1f;
    uVar14 = uVar12 | (uint)NAN(dVar30) << 0x1c;
    if ((byte)(uVar12 >> 0x1f) == ((byte)(uVar14 >> 0x1c) & 1)) {
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
      puVar18 = *(undefined4 **)((int)&DAT_02578a64 + DAT_02579a34);
      goto LAB_02578a9c;
    }
  }
  uVar12 = uVar14 & 0xfffffff | (uint)(unaff_d9 < 0.0) << 0x1f | (uint)(unaff_d9 == 0.0) << 0x1e;
  uVar14 = uVar12 | (uint)NAN(unaff_d9) << 0x1c;
  bVar1 = (byte)(uVar12 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar14 >> 0x1c) & 1)) goto LAB_02578284;
  if (*(int *)(**(int **)(DAT_02579a3c + 0x2578ae8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  uVar4 = FUN_01f80d88();
  if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar5 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),1,0);
  uVar4 = thunk_FUN_04662ba0(**(undefined4 **)(DAT_02579a40 + 0x2578b48),uVar4,uVar5,0);
LAB_0257825c:
  if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
  goto LAB_02578284;
  while( true ) {
    uVar12 = uVar12 - 1;
    piVar16 = piVar16 + 2;
    if (uVar12 == 0) break;
LAB_025773f0:
    if (piVar16[-1] == iVar15) {
      puVar18 = (undefined4 *)(iVar13 + *piVar16 * 8 + 0xc0);
      goto LAB_02577454;
    }
  }
LAB_02577408:
  puVar18 = (undefined4 *)FUN_0105aa50(piVar9,iVar15,0);
LAB_02577454:
  (*(code *)*puVar18)(piVar9,puVar18[1]);
LAB_02577464:
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar9 = (int *)FUN_02566890(in_stack_00000040);
  if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar13 = (**(code **)(*piVar9 + 0x170))(piVar9,*(undefined4 *)(*piVar9 + 0x174));
  if (iVar13 == 1) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar9 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar9 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar4 = (**(code **)(*piVar9 + 0x198))(piVar9,0,*(undefined4 *)(*piVar9 + 0x19c));
    iVar13 = FUN_00d98e30(uVar4,*piVar8);
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = FUN_01b8ab7c(iVar13,0);
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar4 = FUN_013bcec8(iVar13,0);
LAB_02577620:
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
  }
  else {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar8 = (int *)FUN_02566890(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (1 < iVar13) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_02566890(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (*(int *)(**(int **)(DAT_025785cc + 0x25775ec) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f8250c(uVar4,0);
      uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_025785d0 + 0x257761c),uVar4,0);
      goto LAB_02577620;
    }
  }
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar13 = FUN_02567354(in_stack_00000040);
  if (iVar13 != 0) {
LAB_02577684:
    piVar8 = (int *)FUN_02567354(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (iVar13 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
      iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_025786f4 + 0x2577704));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_025786f8 + 0x2577724) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f83354(*(undefined4 *)(iVar13 + 0xc),**(undefined4 **)(DAT_025786fc + 0x2577748)
                           ,0);
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (iVar13 < 2) goto LAB_0257784c;
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_02567354(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (*(int *)(**(int **)(DAT_025787a4 + 0x25777f0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f8250c(uVar4,0);
      uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_025787a8 + 0x2577820),uVar4,0);
    }
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
LAB_0257784c:
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar13 = FUN_025673dc(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (iVar13 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025673dc(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
      iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_025788f0 + 0x2577910));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_025788f4 + 0x2577930) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f83354(*(undefined4 *)(iVar13 + 0xc),**(undefined4 **)(DAT_025788f8 + 0x2577954)
                           ,0);
LAB_02577a28:
      if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025673dc(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (1 < iVar13) {
        if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar8 = (int *)FUN_025673dc(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        if (*(int *)(**(int **)(DAT_025788fc + 0x25779f4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar4 = FUN_01f8250c(uVar4,0);
        uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_02578900 + 0x2577a24),uVar4,0);
        goto LAB_02577a28;
      }
    }
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar13 = FUN_025674b4(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025674b4(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (iVar13 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025674b4(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
      iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02578a64 + 0x2577b1c));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_02578a68 + 0x2577b3c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f83354(*(undefined4 *)(iVar13 + 8),**(undefined4 **)(DAT_02578b50 + 0x2577b60),0
                          );
LAB_02577c34:
      if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025674b4(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (1 < iVar13) {
        if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar8 = (int *)FUN_025674b4(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
        if (*(int *)(**(int **)(DAT_02578bf0 + 0x2577c00) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar4 = FUN_01f8250c(uVar4,0);
        uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_02578bf4 + 0x2577c30),uVar4,0);
        goto LAB_02577c34;
      }
    }
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  iVar13 = FUN_025693f0(in_stack_00000040);
  if (iVar13 != 0) {
    piVar8 = (int *)FUN_025693f0(in_stack_00000040);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
    if (iVar13 == 1) {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x198))(piVar8,0,*(undefined4 *)(*piVar8 + 0x19c));
      iVar13 = FUN_00d98e30(uVar4,**(undefined4 **)(DAT_02578c8c + 0x2577d34));
      if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(**(int **)(DAT_02578c90 + 0x2577d54) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f83354(*(undefined4 *)(iVar13 + 8),**(undefined4 **)(DAT_02578c94 + 0x2577d78),0
                          );
    }
    else {
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (iVar13 < 2) goto LAB_02577e78;
      if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar8 = (int *)FUN_025693f0(in_stack_00000040);
      if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar4 = (**(code **)(*piVar8 + 0x170))(piVar8,*(undefined4 *)(*piVar8 + 0x174));
      if (*(int *)(**(int **)(DAT_02578c98 + 0x2577e1c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar4 = FUN_01f8250c(uVar4,0);
      uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_02578c9c + 0x2577e4c),uVar4,0);
    }
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
    goto LAB_02577e78;
  }
  if (in_stack_00000034 == 0) goto LAB_02577ed4;
LAB_02578164:
  if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar13 = *(int *)(in_stack_00000040 + 0x78);
  dVar30 = *(double *)(*(int *)(in_stack_00000040 + 0x78) + 8);
  uVar12 = in_fpscr & 0xfffffff | (uint)(dVar30 == -10.0) << 0x1e;
  uVar14 = uVar12 | (uint)(-10.0 <= dVar30) << 0x1d;
  if (!(bool)((byte)(uVar14 >> 0x1d) & 1) || SUB41(uVar12 >> 0x1e,0)) {
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(**(int **)(DAT_02578fe4 + 0x2578220) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar4 = FUN_01f7f518(SUB84(-*(double *)(iVar13 + 8),0),
                         (int)((ulonglong)-*(double *)(iVar13 + 8) >> 0x20),0);
    puVar18 = *(undefined4 **)(DAT_02579238 + 0x2578254);
LAB_02578250:
    uVar4 = thunk_FUN_0464f828(*puVar18,uVar4,0);
    goto LAB_0257825c;
  }
  if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar12 = in_fpscr & 0xfffffff | (uint)(*(double *)(iVar13 + 8) < 10.0) << 0x1f;
  uVar14 = uVar12 | (uint)NAN(*(double *)(iVar13 + 8)) << 0x1c;
  if ((byte)(uVar12 >> 0x1f) == ((byte)(uVar14 >> 0x1c) & 1)) {
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar28 = *(undefined8 *)(*(int *)(in_stack_00000040 + 0x78) + 8);
    if (*(int *)(**(int **)(DAT_02578fdc + 0x25781d0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar4 = FUN_01f7f518((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),0);
    puVar18 = *(undefined4 **)((int)&DAT_02578200 + DAT_02578fe0);
    goto LAB_02578250;
  }
LAB_02578284:
  uVar14 = uVar14 & 0xfffffff | (uint)(unaff_d9 < 0.0) << 0x1f | (uint)(unaff_d9 == 0.0) << 0x1e;
  uVar12 = uVar14 | (uint)NAN(unaff_d9) << 0x1c;
  bVar1 = (byte)(uVar14 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar12 >> 0x1c) & 1)) {
    if (*(int *)(**(int **)(DAT_0257923c + 0x257829c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar4 = FUN_01f80d88();
    uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_02579240 + 0x25782d0),uVar4,0);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar4,*(undefined4 *)(*piVar20 + 0x1ac));
  }
  if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar13 = **(int **)(DAT_02579248 + 0x2578324);
  if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
    iVar13 = **(int **)(DAT_02579244 + 0x2578308);
  }
  if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar15 = (**(code **)(*piVar20 + 0x170))(piVar20,*(undefined4 *)(*piVar20 + 0x174));
  if (iVar15 < 1) {
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar4 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
    uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_02579524 + 0x25785b8),iVar11,uVar4,iVar13);
  }
  else {
    bVar23 = true;
    if ((((*(int *)(in_stack_00000040 + 0xd4) != 0) &&
         (*(int *)(*(int *)(in_stack_00000040 + 0xd4) + 8) == 1)) &&
        (uVar12 = uVar12 & 0xfffffff, 0.0 <= unaff_d8)) &&
       (bVar23 = false, *(char *)(in_stack_00000038 + 0xc) != '\0')) {
      bVar23 = true;
    }
    piVar8 = (int *)thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257924c + 0x25783a4),5);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if ((iVar11 != 0) &&
       (iVar15 = thunk_FUN_0105da7c(iVar11,*(undefined4 *)(*piVar8 + 0x20)), iVar15 == 0)) {
      uVar4 = thunk_FUN_01065924();
      FUN_0101f51c(uVar4,0);
    }
    if (piVar8[3] == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar8[4] = iVar11;
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
    if ((iVar11 != 0) &&
       (iVar15 = thunk_FUN_0105da7c(iVar11,*(undefined4 *)(*piVar8 + 0x20)), iVar15 == 0)) {
      uVar4 = thunk_FUN_01065924();
      FUN_0101f51c(uVar4,0);
    }
    if ((uint)piVar8[3] < 2) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar8[5] = iVar11;
    if ((iVar13 != 0) &&
       (iVar11 = thunk_FUN_0105da7c(iVar13,*(undefined4 *)(*piVar8 + 0x20)), iVar11 == 0)) {
      uVar4 = thunk_FUN_01065924();
      FUN_0101f51c(uVar4,0);
    }
    if ((uint)piVar8[3] < 3) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar8[6] = iVar13;
    uVar4 = thunk_FUN_0105db90(**(undefined4 **)(DAT_02579458 + 0x25784ac));
    thunk_FUN_04776538(uVar4,piVar20,0);
    if (*(int *)(**(int **)(DAT_0257945c + 0x25784cc) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    iVar11 = FUN_01f84a64(uVar4,0);
    if ((iVar11 != 0) &&
       (iVar13 = thunk_FUN_0105da7c(iVar11,*(undefined4 *)(*piVar8 + 0x20)), iVar13 == 0)) {
      uVar4 = thunk_FUN_01065924();
      FUN_0101f51c(uVar4,0);
    }
    if ((uint)piVar8[3] < 4) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar8[7] = iVar11;
    piVar20 = *(int **)(DAT_02579518 + 0x2578538);
    iVar11 = *piVar20;
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
      iVar13 = iVar11;
    }
    else {
      uVar14 = uVar12 & 0xfffffff | (uint)(unaff_d8 < 0.0) << 0x1f | (uint)(unaff_d8 == 0.0) << 0x1e
      ;
      uVar12 = uVar14 | (uint)NAN(unaff_d8) << 0x1c;
      bVar1 = (byte)(uVar14 >> 0x18);
      iVar13 = **(int **)(DAT_02579520 + 0x2578560);
      if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar12 >> 0x1c) & 1)) {
        iVar13 = iVar11;
      }
      if (*(int *)(*(int *)(in_stack_00000040 + 0xd4) + 8) != 1) {
        iVar13 = iVar11;
      }
    }
    uVar4 = **(undefined4 **)(DAT_0257951c + 0x2578544);
    FUN_00d99150(piVar8,iVar13);
    if ((uint)piVar8[3] < 5) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_010646b0();
    }
    piVar8[8] = iVar13;
    uVar4 = thunk_FUN_04662c44(uVar4,piVar8,0);
    if (bVar23) {
      iVar11 = *(int *)(in_stack_00000040 + 0x70);
      if (iVar11 != 0) {
        if (*(int *)(iVar11 + 0x1c4) == 3) {
          unaff_d8 = unaff_d8 * 0.5;
        }
      }
      iVar13 = *(int *)(in_stack_00000040 + 0xd4);
      if ((iVar13 == 0) || (*(int *)(iVar13 + 8) != 2)) {
        bVar22 = false;
        bVar23 = false;
        if (iVar11 == 0) goto LAB_02578708;
      }
      else {
        if (iVar11 == 0) {
          bVar23 = true;
          goto LAB_02578708;
        }
        bVar23 = iVar11 == in_stack_0000001c;
        iVar15 = 2;
        if (bVar23) {
          iVar15 = *(int *)(in_stack_0000001c + 0x1c4);
        }
        bVar22 = bVar23 && iVar15 == 3;
        bVar23 = !bVar23 || iVar15 != 3;
      }
      bVar24 = iVar11 == in_stack_0000001c;
      if (bVar24) {
        iVar11 = *(int *)(in_stack_0000001c + 0x1c4);
      }
      if ((!(bVar24 && iVar11 == 3)) || (iVar13 == 0)) {
        if (!bVar22) {
LAB_02578708:
          piVar8 = (int *)FUN_02565674(in_stack_00000040);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar8 + 0x1e8))(piVar8,*(undefined4 *)(*piVar8 + 0x1ec));
          iVar11 = 0;
          in_stack_00000060 = &uStack000000a8;
          in_stack_0000005c = &uStack000000ac;
          uStack00000058 = 0;
          do {
            piVar8 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar13 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar13 + 0xb6);
            if (uVar14 != 0) {
              piVar9 = (int *)(*(int *)(iVar13 + 0x58) + 4);
              do {
                if (piVar9[-1] == *unaff_r11) {
                  puVar18 = (undefined4 *)(iVar13 + *piVar9 * 8 + 0xc0);
                  goto LAB_025787b8;
                }
                uVar14 = uVar14 - 1;
                piVar9 = piVar9 + 2;
              } while (uVar14 != 0);
            }
            puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025787b8:
            iVar13 = (*(code *)*puVar18)(piVar8,puVar18[1]);
            piVar8 = (int *)uStack000000ac;
            if (iVar13 == 0) {
              FUN_00d98384(&uStack00000058);
              if (iVar11 != 1) {
                bVar22 = false;
                if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                goto LAB_02578ffc;
              }
              bVar22 = false;
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              goto LAB_02579094;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar13 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar13 + 0xb6);
            if (uVar14 != 0) {
              piVar9 = (int *)(*(int *)(iVar13 + 0x58) + 4);
              do {
                if (piVar9[-1] == *unaff_r11) {
                  puVar18 = (undefined4 *)(iVar13 + *piVar9 * 8 + 200);
                  goto LAB_02578830;
                }
                uVar14 = uVar14 - 1;
                piVar9 = piVar9 + 2;
              } while (uVar14 != 0);
            }
            puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_02578830:
            piVar8 = (int *)(*(code *)*puVar18)(piVar8,puVar18[1]);
            if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar15 = **(int **)(DAT_02579828 + 0x2578858);
            iVar13 = *piVar8;
            uVar14 = (uint)*(byte *)(iVar15 + 0xb8);
            if ((*(byte *)(iVar13 + 0xb8) < uVar14) ||
               (*(int *)(*(int *)(iVar13 + 100) + uVar14 * 4 + -4) != iVar15)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar8);
            }
            if ((*(byte *)(iVar13 + 0xb8) < uVar14) ||
               (*(int *)(*(int *)(iVar13 + 100) + uVar14 * 4 + -4) != iVar15)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar8);
            }
            iVar11 = iVar11 + (uint)*(byte *)(piVar8 + 3);
          } while( true );
        }
      }
      else if (!bVar22 && *(int *)(iVar13 + 8) != 2) goto LAB_02578708;
      iVar11 = 0;
      bVar22 = true;
LAB_02578ffc:
      iVar13 = *(int *)(in_stack_00000040 + 0xd4);
      if ((iVar13 != 0) && (*(int *)(iVar13 + 8) == 3)) {
        iVar13 = *(int *)(iVar13 + 0xc);
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar15 = *(int *)(*(int *)(in_stack_00000044 + 0x48) + 200);
        if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar5 = FUN_01b9e854(iVar15,0);
        if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = thunk_FUN_0465f908(iVar13,uVar5,0);
        if (iVar13 != 0) goto LAB_02579094;
      }
      if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) != '\0') {
LAB_02579094:
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        dVar30 = 0.0;
        if ((*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) == '\0') &&
           (*(int *)(in_stack_00000040 + 0xd0) == 0)) {
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar5 = FUN_01a4e1f8(iVar11,0);
          if (*(int *)(**(int **)(DAT_0257a108 + 0x2579110) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          dVar30 = (double)FUN_01786018(SUB84(unaff_d8 - (double)fVar26,0),
                                        (int)((ulonglong)(unaff_d8 - (double)fVar26) >> 0x20),uVar5,
                                        0);
        }
        if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        dVar25 = unaff_d8 - dVar30;
        if (0x11 < *(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14)) {
          uVar5 = FUN_02565af4(in_stack_00000040);
          iVar11 = FUN_01f76fd4(uVar5,0);
          uVar5 = FUN_02565da4(in_stack_00000040);
          iVar13 = FUN_01f76fd4(uVar5,0);
          uVar5 = FUN_02565e2c(in_stack_00000040);
          iVar15 = FUN_01f76fd4(uVar5,0);
          uVar5 = FUN_02565f6c(in_stack_00000040);
          iVar21 = FUN_01f76fd4(uVar5,0);
          if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar19 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
          if (iVar19 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          puVar18 = *(undefined4 **)(DAT_0257a1cc + 0x25792dc);
          iVar19 = FUN_03c38838(iVar19,2,*puVar18);
          dVar27 = 0.0;
          if (iVar19 != 0) {
            if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar19 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
            if (iVar19 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            dVar27 = (double)FUN_03c384e8(iVar19,2,**(undefined4 **)(DAT_0257a1d0 + 0x2579320));
            dVar27 = dVar27 + 0.0;
          }
          piVar20 = (int *)FUN_02565af4(in_stack_00000040);
          if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar21 = iVar13 + iVar11 + iVar15 + iVar21;
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
          uStack00000058 = 0;
          piVar20 = *(int **)(DAT_0257a1d4 + 0x2579390);
          in_stack_0000005c = &uStack000000ac;
          in_stack_00000060 = &uStack000000a8;
          do {
            piVar7 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = *(int *)uStack000000ac;
            uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
            if (uVar12 != 0) {
              piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
              do {
                if (piVar8[-1] == *unaff_r11) {
                  puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
                  goto LAB_025793ec;
                }
                uVar12 = uVar12 - 1;
                piVar8 = piVar8 + 2;
              } while (uVar12 != 0);
            }
            puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025793ec:
            iVar11 = (*(code *)*puVar10)(piVar7,puVar10[1]);
            piVar7 = (int *)uStack000000ac;
            if (iVar11 == 0) {
              FUN_00d98384(&uStack00000058);
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
              if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar11 = FUN_03c38838(iVar11,3,*puVar18);
              if (iVar11 != 0) {
                if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
                if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                  thunk_FUN_01064660();
                }
                dVar29 = (double)FUN_03c384e8(iVar11,3,**(undefined4 **)(DAT_0257b56c + 0x257a684));
                dVar27 = dVar27 + dVar29;
              }
              piVar20 = (int *)FUN_02565da4(in_stack_00000040);
              if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              uStack000000ac._0_4_ =
                   (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec))
              ;
              uStack00000058 = 0;
              piVar20 = *(int **)(DAT_0257b6c8 + 0x257a6e0);
              in_stack_0000005c = &uStack000000ac;
              in_stack_00000060 = &uStack000000a8;
              goto LAB_0257a6dc;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = *(int *)uStack000000ac;
            uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
            if (uVar12 != 0) {
              piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
              do {
                if (piVar8[-1] == *unaff_r11) {
                  puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
                  goto LAB_0257946c;
                }
                uVar12 = uVar12 - 1;
                piVar8 = piVar8 + 2;
              } while (uVar12 != 0);
            }
            puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257946c:
            piVar8 = (int *)(*(code *)*puVar10)(piVar7,puVar10[1]);
            piVar7 = (int *)0x0;
            if (piVar8 != (int *)0x0) {
              uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
              if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
                 (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
                FUN_0101fa24();
              }
              piVar7 = piVar8;
            }
            piVar8 = (int *)FUN_02565af4(in_stack_00000044);
            if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
            if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (piVar7[0xd] != 0) {
              dVar27 = dVar27 - (double)*(float *)(piVar7[0xd] + 0x2c);
            }
          } while( true );
        }
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = (**(code **)(*piVar7 + 0x170))(piVar7,*(undefined4 *)(*piVar7 + 0x174));
        if (0 < iVar11) {
          uVar5 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257a184 + 0x2579194));
          thunk_FUN_04776538(uVar5,piVar7,0);
          if (*(int *)(**(int **)(DAT_0257a188 + 0x25791b8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar5 = FUN_01f84a64(uVar5,0);
          iVar11 = (**(code **)(*piVar7 + 0x170))(piVar7,*(undefined4 *)(*piVar7 + 0x174));
          puVar18 = *(undefined4 **)(DAT_0257a1c4 + 0x2579204);
          if (1 < iVar11) {
            puVar18 = *(undefined4 **)(DAT_0257a1c0 + 0x25791fc);
          }
          if (bVar2) {
            puVar18 = *(undefined4 **)(DAT_0257a1c0 + 0x25791fc);
          }
          uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257a1c8 + 0x2579210),uVar4,uVar5,
                                     *puVar18);
        }
LAB_0257af28:
        if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_03c38838(iVar11,1,**(undefined4 **)(DAT_0257bf3c + 0x257af5c));
        dVar27 = 0.0;
        if (iVar11 != 0) {
          if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
          if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          dVar27 = (double)FUN_03c384e8(iVar11,1,**(undefined4 **)(DAT_0257bf40 + 0x257afa4));
          dVar27 = dVar27 + 0.0;
        }
        piVar20 = (int *)FUN_02565a6c(in_stack_00000040);
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        uStack00000058 = 0;
        piVar20 = *(int **)(DAT_0257bf44 + 0x257b010);
        in_stack_0000005c = &uStack000000ac;
        do {
          piVar7 = (int *)uStack000000ac;
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = *(int *)uStack000000ac;
          uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
          if (uVar12 != 0) {
            piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
            do {
              if (piVar8[-1] == *unaff_r11) {
                puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
                goto LAB_0257b070;
              }
              uVar12 = uVar12 - 1;
              piVar8 = piVar8 + 2;
            } while (uVar12 != 0);
          }
          puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b070:
          iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
          piVar7 = (int *)uStack000000ac;
          if (iVar11 == 0) {
            FUN_00d98384(&uStack00000058);
            if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            puVar18 = *(undefined4 **)(DAT_0257c194 + 0x257b320);
            if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
            if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = FUN_03c38838(iVar11,5,*puVar18);
            if (iVar11 != 0) {
              if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
              if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              dVar29 = (double)FUN_03c384e8(iVar11,5,**(undefined4 **)(DAT_0257c198 + 0x257b380));
              dVar27 = dVar27 + dVar29;
            }
            piVar20 = (int *)FUN_02565eb4(in_stack_00000040);
            if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uStack000000ac._0_4_ =
                 (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
            uStack00000058 = 0;
            piVar20 = *(int **)(DAT_0257c19c + 0x257b3dc);
            in_stack_0000005c = &uStack000000ac;
            in_stack_00000060 = &uStack000000a8;
            goto LAB_0257b3d8;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = *(int *)uStack000000ac;
          uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
          if (uVar12 != 0) {
            piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
            do {
              if (piVar8[-1] == *unaff_r11) {
                puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
                goto LAB_0257b108;
              }
              uVar12 = uVar12 - 1;
              piVar8 = piVar8 + 2;
            } while (uVar12 != 0);
          }
          puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b108:
          piVar7 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
          if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
          if ((*(byte *)(*piVar7 + 0xb8) < uVar12) ||
             (*(int *)(*(int *)(*piVar7 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar7);
          }
          if (piVar7[0x14] == 0) {
            if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (*(int *)(in_stack_00000038 + 0x14) < 0x12) goto LAB_0257b194;
            iVar11 = piVar7[0x14] + *(int *)(in_stack_00000038 + 0x14) + -0x12;
          }
          else {
LAB_0257b194:
            if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = *(int *)(in_stack_00000038 + 0x14) + piVar7[0x14];
          }
          piVar7[0x14] = iVar11;
          piVar8 = (int *)FUN_02565a6c(in_stack_00000044);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
          if (piVar7[0xf] != 0) {
            dVar27 = dVar27 - (double)*(float *)(piVar7[0xf] + 0x2c);
          }
        } while( true );
      }
      iVar15 = *(int *)(in_stack_00000040 + 0xd4);
      iVar13 = 0;
      if (iVar15 != 0) {
        iVar13 = *(int *)(iVar15 + 8);
      }
      if ((iVar15 == 0 || iVar13 == 0) || ((1 < iVar11 && (iVar13 == 1)))) {
LAB_02579540:
        if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = (**(code **)(*piVar7 + 0x170))(piVar7,*(undefined4 *)(*piVar7 + 0x174));
        if (0 < iVar13) {
          uVar5 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257a3f0 + 0x2579574));
          thunk_FUN_04776538(uVar5,piVar7,0);
          if (*(int *)(**(int **)(DAT_0257a3f4 + 0x2579598) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar5 = FUN_01f84a64(uVar5,0);
          iVar13 = (**(code **)(*piVar7 + 0x170))(piVar7,*(undefined4 *)(*piVar7 + 0x174));
          puVar18 = *(undefined4 **)(DAT_0257a5dc + 0x25795e4);
          if (1 < iVar13) {
            puVar18 = *(undefined4 **)(DAT_0257a5d0 + 0x25795dc);
          }
          if (bVar2) {
            puVar18 = *(undefined4 **)(DAT_0257a5d0 + 0x25795dc);
          }
          uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257a5e0 + 0x25795f0),uVar4,uVar5,
                                     *puVar18);
        }
        if (1 < iVar11) {
          piVar7 = (int *)FUN_02565674(in_stack_00000040);
          if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uStack000000ac._0_4_ =
               (int *)(**(code **)(*piVar7 + 0x1e8))(piVar7,*(undefined4 *)(*piVar7 + 0x1ec));
          in_stack_00000060 = &uStack000000a8;
          in_stack_0000005c = &uStack000000ac;
          uStack00000058 = 0;
          bVar2 = true;
          bVar23 = true;
          do {
            piVar7 = (int *)uStack000000ac;
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar13 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar13 + 0xb6);
            if (uVar14 != 0) {
              piVar8 = (int *)(*(int *)(iVar13 + 0x58) + 4);
              do {
                if (piVar8[-1] == *unaff_r11) {
                  puVar18 = (undefined4 *)(iVar13 + *piVar8 * 8 + 0xc0);
                  goto LAB_025796ec;
                }
                uVar14 = uVar14 - 1;
                piVar8 = piVar8 + 2;
              } while (uVar14 != 0);
            }
            puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_025796ec:
            iVar13 = (*(code *)*puVar18)(piVar7,puVar18[1]);
            piVar7 = (int *)uStack000000ac;
            if (iVar13 == 0) {
              FUN_00d98384(&uStack00000058);
              if (bVar23) {
                piVar7 = *(int **)(DAT_0257b0e4 + 0x257a170);
                if (iVar11 == 2) {
                  piVar7 = *(int **)(DAT_0257b0e0 + 0x257a168);
                }
                iVar13 = *piVar7;
                puVar18 = *(undefined4 **)((int)&DAT_0257a184 + DAT_0257b0e8);
              }
              else {
                puVar18 = *(undefined4 **)(DAT_0257b0ec + 0x257a1a0);
                if (bVar2) {
                  piVar7 = *(int **)(DAT_0257b0f4 + 0x257a1b8);
                  if (iVar11 == 2) {
                    piVar7 = *(int **)(DAT_0257b0f0 + 0x257a1b0);
                  }
                  iVar13 = *piVar7;
                }
                else {
                  iVar13 = **(int **)(&LAB_0257a1e4 + DAT_0257b0f8);
                }
              }
              if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              goto LAB_0257a1fc;
            }
            if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar13 = *(int *)uStack000000ac;
            uVar14 = (uint)*(ushort *)(iVar13 + 0xb6);
            if (uVar14 != 0) {
              piVar8 = (int *)(*(int *)(iVar13 + 0x58) + 4);
              do {
                if (piVar8[-1] == *unaff_r11) {
                  puVar18 = (undefined4 *)(iVar13 + *piVar8 * 8 + 200);
                  goto LAB_02579764;
                }
                uVar14 = uVar14 - 1;
                piVar8 = piVar8 + 2;
              } while (uVar14 != 0);
            }
            puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_02579764:
            piVar7 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
            if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar14 = (uint)*(byte *)(**(int **)(DAT_0257a730 + 0x2579788) + 0xb8);
            if ((*(byte *)(*piVar7 + 0xb8) < uVar14) ||
               (*(int *)(*(int *)(*piVar7 + 100) + uVar14 * 4 + -4) !=
                **(int **)(DAT_0257a730 + 0x2579788))) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24();
            }
            piVar8 = in_stack_00000048;
            if (piVar7 != in_stack_00000048) {
              piVar8 = (int *)(uint)*(byte *)(piVar7 + 3);
            }
            if (piVar7 != in_stack_00000048 && piVar8 != (int *)0x0) {
              if (piVar7[4] == 0) {
                bVar2 = false;
              }
              else {
                bVar23 = (bool)(piVar7[4] != 1 & bVar23);
              }
            }
          } while( true );
        }
        iVar13 = *piVar20;
        puVar18 = *(undefined4 **)(&LAB_02579630 + DAT_0257a5e4);
LAB_0257a1fc:
        dVar30 = 0.0;
        if (*(int *)(in_stack_00000040 + 0xd0) == 0) {
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar5 = FUN_01a4e1f8(iVar15,0);
          if (*(int *)(**(int **)(DAT_0257b23c + 0x257a258) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          dVar30 = (double)FUN_01786018(SUB84(unaff_d8 - (double)fVar26,0),
                                        (int)((ulonglong)(unaff_d8 - (double)fVar26) >> 0x20),uVar5,
                                        0);
        }
        iVar15 = *in_stack_00000018;
        fVar26 = (float)VectorSignedToFloat(iVar11,(byte)(uVar12 >> 0x16) & 3);
        dVar25 = (unaff_d8 - dVar30) / (double)fVar26;
        if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        *(double *)(iVar15 + 8) = dVar25 + *(double *)(iVar15 + 8);
        if (in_stack_0000003c == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar5 = *puVar18;
        *(double *)(in_stack_0000003c + 0x28) = dVar25;
        if (dVar30 == 0.0) {
          iVar11 = thunk_FUN_0105cca8(uVar5,4);
          if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_00d99150(iVar11,uVar4);
          if (*(int *)(iVar11 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x10) = uVar4;
          FUN_00d99150(iVar11,iVar13);
          if (*(uint *)(iVar11 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar11 + 0x14) = iVar13;
          uVar4 = **(undefined4 **)(DAT_0257b2c8 + 0x257a350);
          if (dVar25 < 0.0) {
            piVar20 = *(int **)(DAT_0257b2cc + 0x257a358);
          }
          iVar13 = *piVar20;
          FUN_00d99150(iVar11,iVar13);
          if (*(uint *)(iVar11 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar11 + 0x18) = iVar13;
          if (*(int *)(**(int **)(DAT_0257b2d0 + 0x257a38c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          if (*(int *)(**(int **)(DAT_0257b2d4 + 0x257a3ac) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar5 = FUN_01f7f518(SUB84(ABS(dVar25),0),(int)((ulonglong)ABS(dVar25) >> 0x20),0);
          FUN_00d99150(iVar11,uVar5);
          if (*(uint *)(iVar11 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x1c) = uVar5;
        }
        else {
          iVar11 = thunk_FUN_0105cca8(uVar5,6);
          if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_00d99150(iVar11,uVar4);
          if (*(int *)(iVar11 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x10) = uVar4;
          FUN_00d99150(iVar11,iVar13);
          if (*(uint *)(iVar11 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar11 + 0x14) = iVar13;
          uVar4 = **(undefined4 **)(DAT_0257b42c + 0x257a464);
          if (dVar25 < 0.0) {
            piVar20 = *(int **)(DAT_0257b430 + 0x257a46c);
          }
          iVar13 = *piVar20;
          FUN_00d99150(iVar11,iVar13);
          if (*(uint *)(iVar11 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(int *)(iVar11 + 0x18) = iVar13;
          if (*(int *)(**(int **)(DAT_0257b434 + 0x257a4a0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          if (*(int *)(**(int **)(DAT_0257b4b0 + 0x257a4c4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar5 = FUN_01f7f518(SUB84(ABS(dVar25),0),(int)((ulonglong)ABS(dVar25) >> 0x20),0);
          FUN_00d99150(iVar11,uVar5);
          if (*(uint *)(iVar11 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x1c) = uVar5;
          uVar5 = FUN_01f7f518(SUB84(dVar30,0),(int)((ulonglong)dVar30 >> 0x20),0);
          FUN_00d99150(iVar11,uVar5);
          if (*(uint *)(iVar11 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x20) = uVar5;
          if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01d0dab4(in_stack_00000038,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01a4e1f8(iVar13,0);
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar5 = *(undefined4 *)(iVar13 + 0x1c);
          FUN_00d99150(iVar11,uVar5);
          if (*(uint *)(iVar11 + 0xc) < 6) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_010646b0();
          }
          *(undefined4 *)(iVar11 + 0x24) = uVar5;
        }
        uVar4 = thunk_FUN_04662c44(uVar4,iVar11,0);
        bVar2 = true;
        bVar23 = true;
LAB_0257b958:
        piVar20 = (int *)FUN_02566890(in_stack_00000040);
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
        uStack00000058 = 0;
        piVar20 = *(int **)(DAT_0257c9a4 + 0x257b9ac);
        in_stack_0000005c = &uStack000000ac;
        in_stack_00000060 = &uStack000000a8;
        do {
          piVar7 = (int *)uStack000000ac;
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = *(int *)uStack000000ac;
          uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
          if (uVar12 != 0) {
            piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
            do {
              if (piVar8[-1] == *unaff_r11) {
                puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
                goto LAB_0257ba08;
              }
              uVar12 = uVar12 - 1;
              piVar8 = piVar8 + 2;
            } while (uVar12 != 0);
          }
          puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257ba08:
          iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
          piVar7 = (int *)uStack000000ac;
          if (iVar11 == 0) {
            FUN_00d98384(&uStack00000058);
            if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            piVar20 = (int *)FUN_02567354(in_stack_00000040);
            if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uStack000000ac._0_4_ =
                 (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
            uStack00000058 = 0;
            piVar20 = *(int **)(DAT_0257cac4 + 0x257bbac);
            in_stack_0000005c = &uStack000000ac;
            in_stack_00000060 = &uStack000000a8;
            goto LAB_0257bba8;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = *(int *)uStack000000ac;
          uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
          if (uVar12 != 0) {
            piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
            do {
              if (piVar8[-1] == *unaff_r11) {
                puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
                goto LAB_0257ba80;
              }
              uVar12 = uVar12 - 1;
              piVar8 = piVar8 + 2;
            } while (uVar12 != 0);
          }
          puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257ba80:
          piVar8 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
          piVar7 = (int *)0x0;
          if (piVar8 != (int *)0x0) {
            uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
            if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
               (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24();
            }
            piVar7 = piVar8;
          }
          piVar8 = (int *)FUN_02566890(in_stack_00000044);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
        } while( true );
      }
      if (iVar13 == 3) {
        piVar8 = (int *)FUN_02565674(in_stack_00000040);
        if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar8 + 0x1e8))(piVar8,*(undefined4 *)(*piVar8 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        in_stack_0000005c = &uStack000000ac;
        uStack00000058 = 0;
        do {
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
          if (iVar13 == 0) {
            FUN_00d98384(&uStack00000058);
            goto LAB_025799dc;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar5 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
          iVar13 = FUN_00d98e30(uVar5,**(undefined4 **)(DAT_0257a88c + 0x25798e8));
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(iVar13 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = FUN_01b9e854(*(int *)(iVar13 + 200),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar15 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar15 = thunk_FUN_0465f908(iVar15,*(undefined4 *)
                                              (*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
        } while ((iVar15 == 0) || (*(char *)(iVar13 + 0xc) != '\0'));
        FUN_00d98384(&uStack00000058);
        goto LAB_02579540;
      }
LAB_025799dc:
      if (bVar23) goto LAB_02579540;
      if (bVar22) {
        if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_01d20174(*(int *)(in_stack_00000040 + 0x70),
                              *(undefined4 *)(in_stack_00000044 + 0x60),0);
        if (iVar11 == 0) {
          if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = FUN_01d20174(*(int *)(in_stack_00000040 + 0x70),
                                *(undefined4 *)(in_stack_00000044 + 0x58),0);
          if (iVar11 == 0) {
            if (*(int *)(in_stack_00000040 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar11 = FUN_01d14e7c(*(int *)(in_stack_00000040 + 0x70),0);
            puVar18 = *(undefined4 **)(&LAB_02579c30 + DAT_0257ab40);
            if (iVar11 == 0) {
              puVar18 = *(undefined4 **)(DAT_0257ab3c + 0x2579c28);
            }
          }
          else {
            puVar18 = *(undefined4 **)(&LAB_02579bf8 + DAT_0257ab38);
          }
        }
        else {
          puVar18 = *(undefined4 **)((int)&DAT_02579a34 + DAT_0257a9d8);
        }
        uVar5 = *puVar18;
        iVar11 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257ab44 + 0x2579c3c),4);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_00d99150(iVar11,uVar4);
        if (*(int *)(iVar11 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x10) = uVar4;
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
        FUN_00d99150(iVar11,uVar4);
        if (*(uint *)(iVar11 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x14) = uVar4;
        uVar4 = **(undefined4 **)(DAT_0257ac94 + 0x2579cd8);
        puVar18 = *(undefined4 **)(DAT_0257ac9c + 0x2579ce8);
        if (unaff_d8 < 0.0) {
          puVar18 = *(undefined4 **)(DAT_0257ac98 + 0x2579ce0);
        }
        uVar6 = *puVar18;
        FUN_00d99150(iVar11,uVar6);
        if (*(uint *)(iVar11 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x18) = uVar6;
        FUN_00d99150(iVar11,uVar5);
        if (*(uint *)(iVar11 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x1c) = uVar5;
        uVar4 = thunk_FUN_04662c44(uVar4,iVar11,0);
      }
      else {
        piVar20 = (int *)FUN_02565674(in_stack_00000040);
        if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uStack000000ac._0_4_ =
             (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
        in_stack_00000060 = &uStack000000a8;
        in_stack_0000005c = &uStack000000ac;
        uStack00000058 = 0;
        do {
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar11 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
          if (iVar11 == 0) {
            FUN_00d98384(&uStack00000058);
            iVar11 = FUN_02565bbc(in_stack_00000044);
            if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            FUN_0419a9e4(&uStack00000058,iVar11,**(undefined4 **)(DAT_0257adc8 + 0x2579dd4));
            uStack00000070 = CONCAT44(in_stack_0000005c,uStack00000058);
            in_stack_00000078 = CONCAT44(in_stack_00000064,in_stack_00000060);
            in_stack_0000005c = &uStack00000070;
            uStack00000058 = 0;
            puVar18 = *(undefined4 **)(DAT_0257adf8 + 0x2579e00);
            goto LAB_02579dfc;
          }
          if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          uVar5 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
          iVar11 = FUN_00d98e30(uVar5,**(undefined4 **)(DAT_0257aa54 + 0x2579ae0));
          if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(iVar11 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01b9e854(*(int *)(iVar11 + 8),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = thunk_FUN_0465f908(iVar13,*(undefined4 *)
                                              (*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
          if (iVar13 != 0) break;
          if (*(int *)(iVar11 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = FUN_01b9e854(*(int *)(iVar11 + 200),0);
          if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar13 = thunk_FUN_0465f908(iVar13,*(undefined4 *)
                                              (*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
        } while (iVar13 == 0);
        FUN_00d98384(&uStack00000058);
LAB_02579ee0:
        iVar13 = FUN_01d14e7c(iVar11,0);
        puVar18 = *(undefined4 **)(DAT_0257ae04 + 0x2579f04);
        if (iVar13 == 0) {
          puVar18 = *(undefined4 **)(DAT_0257ae00 + 0x2579efc);
        }
        if (*(int *)(iVar11 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar5 = thunk_FUN_04661ec4(*puVar18,**(undefined4 **)(DAT_0257ae08 + 0x2579f28),
                                   *(undefined4 *)(*(int *)(iVar11 + 8) + 0xc),0);
LAB_02579f38:
        iVar11 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257ae0c + 0x2579f48),8);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar11 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x10) = uVar4;
        if (*(uint *)(iVar11 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x14) = **(undefined4 **)(DAT_0257ae10 + 0x2579f88);
        if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01d23070(*(int *)(in_stack_00000040 + 0x48),5,0);
        if (*(uint *)(iVar11 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x18) = uVar4;
        if (*(uint *)(iVar11 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x1c) = **(undefined4 **)(DAT_0257ae14 + 0x2579fe4);
        uVar12 = *(uint *)(iVar11 + 0xc);
        puVar18 = *(undefined4 **)(DAT_0257ae1c + 0x257a00c);
        if (unaff_d8 < 0.0) {
          puVar18 = *(undefined4 **)(DAT_0257ae18 + 0x257a004);
        }
        if (uVar12 < 5) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x20) = *puVar18;
        if (uVar12 < 6) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x24) = **(undefined4 **)(DAT_0257ae20 + 0x257a038);
        if (uVar12 < 7) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x28) = uVar5;
        if (uVar12 < 8) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x2c) = **(undefined4 **)(DAT_0257b060 + 0x257a06c);
        uVar4 = thunk_FUN_04662824(iVar11,0);
      }
LAB_0257c1dc:
      iVar11 = FUN_02565794(in_stack_00000044);
      uVar5 = thunk_FUN_0105db90(**(undefined4 **)(DAT_0257d068 + 0x257c1f4));
      FUN_04199548(uVar5,**(undefined4 **)(DAT_0257d06c + 0x257c208));
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar11 + 8) = uVar5;
    }
  }
LAB_0257c220:
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(*(int *)(in_stack_00000044 + 0x48) + 0x14) < 0x12) {
    if (in_stack_00000048 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_01d08764(in_stack_00000048,0);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(iVar11 + 0x6c) == '\0') {
      iVar11 = *(int *)(in_stack_00000044 + 0x58);
      if (iVar11 != 0) {
        if (*(char *)(iVar11 + 0xc) != '\0') goto LAB_0257c278;
        iVar11 = *(int *)(iVar11 + 0x1a4);
        cVar17 = '\0';
        if (iVar11 != 0) {
          cVar17 = *(char *)(iVar11 + 0xc);
        }
        if (iVar11 != 0 && cVar17 != '\0') goto LAB_0257c278;
      }
      iVar11 = *(int *)(in_stack_00000044 + 0x60);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(char *)(iVar11 + 0x199) == '\0') {
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar11 + 0xc) != '\0') goto LAB_0257c278;
        iVar11 = *(int *)(in_stack_00000044 + 0x60);
      }
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar11 + 0x1a4) != 0) {
        if (*(int *)(in_stack_00000044 + 0x60) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = *(int *)(*(int *)(in_stack_00000044 + 0x60) + 0x1a4);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar11 + 0xc) != '\0') goto LAB_0257c278;
      }
      if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar5 = FUN_01ac8cc8(*(int *)(in_stack_00000044 + 0x48),0);
      iVar11 = FUN_0257d0bc(uVar5,0);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar13 = *(int *)(iVar11 + 8);
      if (0 < iVar13) {
        iVar11 = thunk_FUN_0464f828(**(undefined4 **)(DAT_0257d070 + 0x257c784),iVar11,0);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar13 = *(int *)(iVar11 + 8);
      }
      puVar18 = *(undefined4 **)(DAT_0257d07c + 0x257c7c0);
      if (0 < iVar13) {
        puVar18 = *(undefined4 **)(DAT_0257d078 + 0x257c7b8);
      }
      uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d074 + 0x257c7ac),uVar4,iVar11,*puVar18);
    }
  }
LAB_0257c278:
  if (in_stack_00000034 != 0) {
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(in_stack_00000040 + 0xb0);
    if ((iVar11 != 0) && (*(int *)(iVar11 + 8) == 6)) {
      iVar11 = FUN_00d98e30(iVar11,**(undefined4 **)(DAT_0257d080 + 0x257c2b8));
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(iVar11 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if (*(int *)(*(int *)(iVar11 + 0x18) + 8) == 7) {
        iVar11 = FUN_00d98e30(*(undefined4 *)(iVar11 + 0x18),
                              **(undefined4 **)(DAT_0257d084 + 0x257c2f4));
        iVar13 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d088 + 0x257c310),6);
        if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar13 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x10) = uVar4;
        if (*(uint *)(iVar13 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x14) = **(undefined4 **)(DAT_0257d08c + 0x257c34c);
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        puVar18 = *(undefined4 **)(DAT_0257d094 + 0x257c380);
        if (*(char *)(in_stack_00000038 + 0xc) == '\0') {
          puVar18 = *(undefined4 **)(DAT_0257d090 + 0x257c378);
        }
        if (*(uint *)(iVar13 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x18) = *puVar18;
        if (*(uint *)(iVar13 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x1c) = **(undefined4 **)(DAT_0257d098 + 0x257c3ac);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(iVar11 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(uint *)(iVar13 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x20) = *(undefined4 *)(*(int *)(iVar11 + 0x18) + 8);
        if (*(uint *)(iVar13 + 0xc) < 6) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar13 + 0x24) = **(undefined4 **)(DAT_0257d09c + 0x257c400);
        uVar4 = thunk_FUN_04662824(iVar13,0);
      }
    }
  }
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = FUN_01d15f1c(*(int *)(in_stack_00000044 + 0x48),0);
  if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_01a4e348(iVar11,0,0);
  if (*(int *)(in_stack_00000044 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = FUN_01d0dab4(*(int *)(in_stack_00000044 + 0x48),0);
  if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_01a4e348(iVar11,0,0);
  piVar20 = (int *)FUN_02565ff4(in_stack_00000044);
  if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
  in_stack_00000060 = &uStack000000a8;
  in_stack_0000005c = &uStack000000ac;
  uStack00000058 = 0;
  piVar20 = *(int **)(DAT_0257d0a0 + 0x257c4f0);
  do {
    piVar7 = (int *)uStack000000ac;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)uStack000000ac;
    uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
    if (uVar12 != 0) {
      piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
      do {
        if (piVar8[-1] == *unaff_r11) {
          puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
          goto LAB_0257c550;
        }
        uVar12 = uVar12 - 1;
        piVar8 = piVar8 + 2;
      } while (uVar12 != 0);
    }
    puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257c550:
    iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
    piVar7 = (int *)uStack000000ac;
    if (iVar11 == 0) {
      FUN_00d98384(&uStack00000058);
      iVar11 = **(int **)(**(int **)(DAT_0257d0a4 + 0x257ca30) + 0x5c);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(undefined4 *)(iVar11 + 0x14) = *(undefined4 *)(in_stack_00000044 + 0x48);
      if (bVar3) {
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar5 = FUN_01d18c0c(in_stack_00000038,0);
        if (*(int *)(in_stack_00000044 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = FUN_01ad9c14(*(int *)(in_stack_00000044 + 0xd0),0,0);
        uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257d0a8 + 0x257cab8),uVar4,uVar5,uVar6);
      }
      else if (piStack00000030 != (int *)0x0) {
        iVar11 = thunk_FUN_0105cca8(**(undefined4 **)(DAT_0257d0ac + 0x257cae0),5);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_00d99150(iVar11,uVar4);
        if (*(int *)(iVar11 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x10) = uVar4;
        uVar4 = FUN_01d42534(piStack00000030,1,0);
        FUN_00d99150(iVar11,uVar4);
        if (*(uint *)(iVar11 + 0xc) < 2) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x14) = uVar4;
        if (piStack00000030[2] == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01ba8890(piStack00000030[2],0);
        FUN_00d99150(iVar11,uVar4);
        if (*(uint *)(iVar11 + 0xc) < 3) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x18) = uVar4;
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01d18c0c(in_stack_00000038,0);
        FUN_00d99150(iVar11,uVar4);
        if (*(uint *)(iVar11 + 0xc) < 4) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x1c) = uVar4;
        iVar13 = FUN_01d0dab4(piStack00000030,0);
        if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01a4e1f8(iVar13,0);
        uVar5 = FUN_01d14e7c(piStack00000030,0);
        iVar13 = FUN_01d08764(piStack00000030,0);
        if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = FUN_01ad9d5c(uVar4,1,uVar5,*(undefined4 *)(iVar13 + 0x74));
        FUN_00d99150(iVar11,uVar4);
        if (*(uint *)(iVar11 + 0xc) < 5) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_010646b0();
        }
        *(undefined4 *)(iVar11 + 0x20) = uVar4;
        uVar4 = thunk_FUN_04662c44(**(undefined4 **)(DAT_0257d0b0 + 0x257cc78),iVar11,0);
      }
      if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_0268300c(*(int *)(in_stack_00000044 + 0x28),uVar4,0);
      if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_02683508(*(int *)(in_stack_00000044 + 0x28),0);
      if (*(int *)(in_stack_00000044 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_02358098(*(int *)(in_stack_00000044 + 8),0);
      if (*(int *)(**(int **)(DAT_0257d0b4 + 0x257cce8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      FUN_02018748(1,0,0);
      return;
    }
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)uStack000000ac;
    uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
    if (uVar12 != 0) {
      piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
      do {
        if (piVar8[-1] == *unaff_r11) {
          puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
          goto LAB_0257c5cc;
        }
        uVar12 = uVar12 - 1;
        piVar8 = piVar8 + 2;
      } while (uVar12 != 0);
    }
    puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257c5cc:
    piVar7 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
    if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = *piVar20;
    iVar11 = *piVar7;
    uVar12 = (uint)*(byte *)(iVar13 + 0xb8);
    if ((*(byte *)(iVar11 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar7);
    }
    if ((*(byte *)(iVar11 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(iVar11 + 100) + uVar12 * 4 + -4) != iVar13)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24(piVar7);
    }
    FUN_01a4e348(piVar7,0,0);
  } while( true );
LAB_0257a6dc:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257a740;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257a740:
  iVar11 = (*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_03c38838(iVar11,4,*puVar18);
    if (iVar11 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar29 = (double)FUN_03c384e8(iVar11,4,**(undefined4 **)(DAT_0257b8b4 + 0x257a92c));
      dVar27 = dVar27 + dVar29;
    }
    piVar20 = (int *)FUN_02565e2c(in_stack_00000040);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
    uStack00000058 = 0;
    piVar20 = *(int **)(DAT_0257b8b8 + 0x257a988);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257a984;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257a7b8;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257a7b8:
  piVar8 = (int *)(*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02565da4(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar7[7] != 0) {
    dVar27 = dVar27 - (double)*(float *)(piVar7[7] + 0x2c);
  }
  goto LAB_0257a6dc;
LAB_0257a984:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257a9e8;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257a9e8:
  iVar11 = (*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_03c38838(iVar11,7,*puVar18);
    if (iVar11 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar29 = (double)FUN_03c384e8(iVar11,7,**(undefined4 **)(DAT_0257bb2c + 0x257abe4));
      dVar27 = dVar27 + dVar29;
    }
    piVar20 = (int *)FUN_02565f6c(in_stack_00000040);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
    uStack00000058 = 0;
    piVar20 = *(int **)(&LAB_0257ac40 + DAT_0257bbfc);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257ac40;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257aa64;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257aa64:
  piVar8 = (int *)(*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02565e2c(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar7[8] != 0) {
    dVar27 = dVar27 - (double)*(float *)(piVar7[8] + 0x2c);
  }
  goto LAB_0257a984;
LAB_0257ac40:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257acac;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257acac:
  iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    iVar11 = **(int **)(**(int **)(DAT_0257bdfc + 0x257ae54) + 0x5c);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(iVar11 + 0x2c);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_024c3528(iVar11,0);
    if (iVar11 != 0) {
      iVar11 = **(int **)(**(int **)(DAT_0257be78 + 0x257ae98) + 0x5c);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = *(int *)(iVar11 + 0x24);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      if ((*(char *)(iVar11 + 0x131) != '\0') && (0 < iVar21)) {
        puVar18 = *(undefined4 **)(DAT_0257be80 + 0x257aee8);
        if (iVar21 == 1) {
          puVar18 = *(undefined4 **)(DAT_0257be7c + 0x257aee0);
        }
        if (*(int *)(in_stack_00000044 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0268300c(*(int *)(in_stack_00000044 + 0x28),*puVar18,0);
      }
    }
    dVar25 = dVar25 - dVar27;
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    goto LAB_0257af28;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257ad24;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257ad24:
  piVar8 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02565f6c(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (piVar7[0x10] != 0) {
    dVar27 = dVar27 - (double)*(float *)(piVar7[0x10] + 0x2c);
  }
  goto LAB_0257ac40;
LAB_0257b3d8:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257b444;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b444:
  iVar11 = (*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_03c38838(iVar11,6,*puVar18);
    if (iVar11 != 0) {
      if (*(int *)(in_stack_00000040 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar11 = *(int *)(*(int *)(in_stack_00000040 + 0x78) + 0x18);
      if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      dVar29 = (double)FUN_03c384e8(iVar11,6,**(undefined4 **)(DAT_0257c5bc + 0x257b618));
      dVar27 = dVar27 + dVar29;
    }
    piVar20 = (int *)FUN_02566f9c(in_stack_00000040);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
    uStack00000058 = 0;
    piVar20 = *(int **)(&LAB_0257b674 + DAT_0257c66c);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257b674;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar10 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257b4c0;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar10 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b4c0:
  piVar8 = (int *)(*(code *)*puVar10)(piVar7,puVar10[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02565eb4(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  goto LAB_0257b3d8;
LAB_0257b674:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257b6d8;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257b6d8:
  iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    iVar11 = *in_stack_00000018;
    if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(iVar11 + 8) = (dVar25 - dVar27) + *(double *)(iVar11 + 8);
    if (in_stack_0000003c == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(double *)(in_stack_0000003c + 0x28) = dVar25 - dVar27;
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)(in_stack_00000040 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    bVar2 = false;
    if (*(char *)(*(int *)(in_stack_00000040 + 0x48) + 0xc) == '\0') {
      if (dVar30 == 0.0) {
        uVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_0257c878 + 0x257b8ac),uVar4,0);
      }
      else {
        if (*(int *)(**(int **)(DAT_0257c8b0 + 0x257b8c8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        uVar5 = FUN_01f7f518(SUB84(dVar30,0),(int)((ulonglong)dVar30 >> 0x20),0);
        if (in_stack_00000038 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_01d0dab4(in_stack_00000038,0);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar11 = FUN_01a4e1f8(iVar11,0);
        if (iVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar4 = thunk_FUN_04662bf0(**(undefined4 **)(DAT_0257c938 + 0x257b948),uVar4,uVar5,
                                   *(undefined4 *)(iVar11 + 0x1c));
      }
      bVar2 = false;
    }
    goto LAB_0257b958;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257b750;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257b750:
  piVar8 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02566f9c(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  goto LAB_0257b674;
LAB_0257bba8:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257bc0c;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257bc0c:
  iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 == 0) {
    FUN_00d98384(&uStack00000058);
    if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar20 = (int *)FUN_025673dc(in_stack_00000040);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uStack000000ac._0_4_ =
         (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
    uStack00000058 = 0;
    piVar20 = *(int **)(DAT_0257cda4 + 0x257bdac);
    in_stack_0000005c = &uStack000000ac;
    in_stack_00000060 = &uStack000000a8;
    goto LAB_0257bda8;
  }
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257bc84;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257bc84:
  piVar8 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_02567354(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  goto LAB_0257bba8;
LAB_0257bda8:
  piVar7 = (int *)uStack000000ac;
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 0xc0);
        goto LAB_0257be0c;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,0);
LAB_0257be0c:
  iVar11 = (*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)uStack000000ac;
  if (iVar11 != 0) goto code_r0x0257be24;
  FUN_00d98384(&uStack00000058);
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar20 = (int *)FUN_025674b4(in_stack_00000040);
  if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
  uStack00000058 = 0;
  puVar18 = *(undefined4 **)(DAT_0257cf38 + 0x257bfc4);
  in_stack_0000005c = &uStack000000ac;
  in_stack_00000060 = &uStack000000a8;
  while( true ) {
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
    if (iVar11 == 0) break;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar5 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
    uVar5 = FUN_00d98e30(uVar5,*puVar18);
    piVar20 = (int *)FUN_025674b4(in_stack_00000044);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar5,*(undefined4 *)(*piVar20 + 0x1ac));
  }
  FUN_00d98384(&uStack00000058);
  if (in_stack_00000040 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar20 = (int *)FUN_025693f0(in_stack_00000040);
  if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uStack000000ac._0_4_ =
       (int *)(**(code **)(*piVar20 + 0x1e8))(piVar20,*(undefined4 *)(*piVar20 + 0x1ec));
  uStack00000058 = 0;
  puVar18 = *(undefined4 **)(&LAB_0257c0e8 + DAT_0257d064);
  in_stack_0000005c = &uStack000000ac;
  in_stack_00000060 = &uStack000000a8;
  while( true ) {
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar11 = FUN_00d98a08(0,*unaff_r11,(int *)uStack000000ac);
    if (iVar11 == 0) break;
    if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar5 = FUN_00d98a08(1,*unaff_r11,(int *)uStack000000ac);
    uVar5 = FUN_00d98e30(uVar5,*puVar18);
    piVar20 = (int *)FUN_025693f0(in_stack_00000044);
    if (piVar20 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    (**(code **)(*piVar20 + 0x1a8))(piVar20,uVar5,*(undefined4 *)(*piVar20 + 0x1ac));
  }
  FUN_00d98384(&uStack00000058);
  if (bVar23 || (bVar22 || bVar2)) goto LAB_0257c1dc;
  goto LAB_0257c220;
code_r0x0257be24:
  if ((int *)uStack000000ac == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar11 = *(int *)uStack000000ac;
  uVar12 = (uint)*(ushort *)(iVar11 + 0xb6);
  if (uVar12 != 0) {
    piVar8 = (int *)(*(int *)(iVar11 + 0x58) + 4);
    do {
      if (piVar8[-1] == *unaff_r11) {
        puVar18 = (undefined4 *)(iVar11 + *piVar8 * 8 + 200);
        goto LAB_0257be90;
      }
      uVar12 = uVar12 - 1;
      piVar8 = piVar8 + 2;
    } while (uVar12 != 0);
  }
  puVar18 = (undefined4 *)FUN_0105aa50((int *)uStack000000ac,*unaff_r11,1);
LAB_0257be90:
  piVar8 = (int *)(*(code *)*puVar18)(piVar7,puVar18[1]);
  piVar7 = (int *)0x0;
  if (piVar8 != (int *)0x0) {
    uVar12 = (uint)*(byte *)(*piVar20 + 0xb8);
    if ((*(byte *)(*piVar8 + 0xb8) < uVar12) ||
       (*(int *)(*(int *)(*piVar8 + 100) + uVar12 * 4 + -4) != *piVar20)) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    piVar7 = piVar8;
  }
  piVar8 = (int *)FUN_025673dc(in_stack_00000044);
  if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  (**(code **)(*piVar8 + 0x1a8))(piVar8,piVar7,*(undefined4 *)(*piVar8 + 0x1ac));
  goto LAB_0257bda8;
  while( true ) {
    if (*(int *)(iVar11 + 200) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = FUN_01b9e854(*(int *)(iVar11 + 200),0);
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = thunk_FUN_0465f908(iVar13,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
    if (iVar13 != 0) break;
LAB_02579dfc:
    iVar11 = FUN_03da6844(&uStack00000070,*puVar18);
    if (iVar11 == 0) {
      FUN_00d98eec(&uStack00000058);
      uVar5 = **(undefined4 **)(DAT_0257b0dc + 0x257a0f8);
      goto LAB_02579f38;
    }
    iVar11 = (int)in_stack_00000078._4_4_;
    if (in_stack_00000078._4_4_ == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(int *)((int)in_stack_00000078._4_4_ + 8) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = FUN_01b9e854(*(int *)((int)in_stack_00000078._4_4_ + 8),0);
    if (*(int *)(in_stack_00000040 + 0xd4) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (iVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar13 = thunk_FUN_0465f908(iVar13,*(undefined4 *)(*(int *)(in_stack_00000040 + 0xd4) + 0xc),0);
    if (iVar13 != 0) break;
  }
  FUN_00d98eec(&uStack00000058);
  goto LAB_02579ee0;
}


===== Scenario_LoadDesignerFormat @ 0x1d8ba6c =====

undefined4 Scenario_LoadDesignerFormat(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float extraout_r0;
  int iVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  float extraout_r0_00;
  undefined4 uVar7;
  float extraout_r0_01;
  float extraout_r0_02;
  float extraout_r0_03;
  undefined4 *unaff_r4;
  char *pcVar8;
  int *unaff_r5;
  int *piVar9;
  undefined4 unaff_r7;
  undefined1 *unaff_r8;
  int *unaff_r9;
  int *unaff_r10;
  uint in_fpscr;
  float __x;
  float __x_00;
  float __x_01;
  int iVar10;
  float unaff_s16;
  float fVar11;
  float unaff_s18;
  float fVar12;
  undefined4 uVar13;
  float unaff_s24;
  undefined4 unaff_s28;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  undefined4 in_stack_00000098;
  
  FUN_0101f410(*(undefined4 *)(param_1 + 0x1d8ba74));
  *unaff_r8 = 1;
  uVar13 = VectorSignedToFloat(unaff_s28,(byte)(in_fpscr >> 0x16) & 3);
  if (*(int *)(*unaff_r9 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  in_fpscr = in_fpscr & 0xfffffff;
  if (unaff_s24 == DAT_01d8b99c) {
    uVar13 = DAT_01d8b9a0;
  }
  uVar1 = (**(code **)(*unaff_r5 + 0xe0))();
  uVar2 = (**(code **)(*unaff_r5 + 0xf0))();
  ceilf(__x);
  in_fpscr = in_fpscr & 0xfffffff;
  VectorSignedToFloat((int)extraout_r0,(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  FUN_01d8eb50(0x3f333333,in_stack_00000028,in_stack_0000002c,in_stack_00000098);
  FUN_01d8ebfc(in_stack_00000034,in_stack_00000030,in_stack_00000020,uVar13);
  in_fpscr = in_fpscr & 0xfffffff;
  if (unaff_s18 < unaff_s16) {
    if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    thunk_FUN_05069d8c();
  }
  uVar13 = thunk_FUN_04661ec4(unaff_r7);
  iVar3 = FUN_03536964(uVar13,*unaff_r4);
  if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  iVar4 = thunk_FUN_050621bc(iVar3,0,0);
  if (iVar4 != 0) {
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar13 = thunk_FUN_0501a190(iVar3,0);
    if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    iVar4 = thunk_FUN_050621bc(uVar13,0,0);
    if (iVar4 != 0) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar5 = (int *)thunk_FUN_0501a190(iVar3,0);
      if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar13 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      fVar11 = (float)VectorSignedToFloat(uVar13,(byte)(in_fpscr >> 0x16) & 3);
      fVar12 = *(float *)(in_stack_00000034 + 0x14);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar12 < fVar11) {
        iVar3 = FUN_02134320(0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar4 = (int)*(float *)(in_stack_00000034 + 0x14);
        iVar10 = (int)*(float *)(in_stack_00000034 + 0x18);
        in_fpscr = in_fpscr & 0xfffffff;
        if (*(float *)(in_stack_00000034 + 0x14) == DAT_01d8b99c) {
          iVar4 = -0x80000000;
        }
        if (*(float *)(in_stack_00000034 + 0x18) == DAT_01d8b99c) {
          iVar10 = -0x80000000;
        }
        piVar5 = (int *)FUN_0214796c(iVar3,piVar5,iVar4,iVar10);
        if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
      }
      uVar13 = thunk_FUN_05040220(piVar5,0);
      uVar1 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      pcVar8 = (char *)(DAT_01d8c328 + 0x1d8bd48);
      VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      if (*pcVar8 == '\0') {
        FUN_0101f410(uVar1,*(undefined4 *)(DAT_01d8c32c + 0x1d8bd64));
        *pcVar8 = '\x01';
      }
      piVar9 = *(int **)(DAT_01d8c330 + 0x1d8bd7c);
      if (*(int *)(*piVar9 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      fVar6 = (float)(**(code **)(*piVar5 + 0xf0))(piVar5,*(undefined4 *)(*piVar5 + 0xf4));
      VectorSignedToFloat(fVar6,(byte)(in_fpscr >> 0x16) & 3);
      ceilf(fVar6);
      if (*pcVar8 == '\0') {
        FUN_0101f410(*(undefined4 *)(DAT_01d8c334 + 0x1d8bddc));
        *pcVar8 = '\x01';
      }
      uVar1 = VectorSignedToFloat((int)extraout_r0_00,(byte)(in_fpscr >> 0x16) & 3);
      if (*(int *)(*piVar9 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      in_fpscr = in_fpscr & 0xfffffff;
      if (extraout_r0_00 == DAT_01d8bd00) {
        uVar1 = DAT_01d8bd04;
      }
      uVar2 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      uVar7 = (**(code **)(*piVar5 + 0xf0))(piVar5,*(undefined4 *)(*piVar5 + 0xf4));
      ceilf(__x_00);
      in_fpscr = in_fpscr & 0xfffffff;
      VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat((int)extraout_r0_01,(byte)(in_fpscr >> 0x16) & 3);
      FUN_01d8ebfc(in_stack_00000034,in_stack_00000030,uVar13,uVar1);
      in_fpscr = in_fpscr & 0xfffffff;
      unaff_r4 = *(undefined4 **)(DAT_01d8c338 + 0x1d8bec8);
      if (fVar12 < fVar11) {
        if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        thunk_FUN_05069d8c(piVar5,0);
      }
    }
  }
  uVar13 = thunk_FUN_046526c8(unaff_r7,**(undefined4 **)(DAT_01d8c33c + 0x1d8bef8),0);
  iVar3 = FUN_03536964(uVar13,*unaff_r4);
  if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  iVar4 = thunk_FUN_050621bc(iVar3,0,0);
  if (iVar4 != 0) {
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar13 = thunk_FUN_0501a190(iVar3,0);
    if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    iVar4 = thunk_FUN_050621bc(uVar13,0,0);
    if (iVar4 != 0) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar5 = (int *)thunk_FUN_0501a190(iVar3,0);
      if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar13 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      fVar11 = (float)VectorSignedToFloat(uVar13,(byte)(in_fpscr >> 0x16) & 3);
      fVar12 = *(float *)(in_stack_00000034 + 0x14);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar12 < fVar11) {
        iVar3 = FUN_02134320(0);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar4 = (int)*(float *)(in_stack_00000034 + 0x14);
        iVar10 = (int)*(float *)(in_stack_00000034 + 0x18);
        in_fpscr = in_fpscr & 0xfffffff;
        if (*(float *)(in_stack_00000034 + 0x14) == DAT_01d8c2bc) {
          iVar4 = -0x80000000;
        }
        if (*(float *)(in_stack_00000034 + 0x18) == DAT_01d8c2bc) {
          iVar10 = -0x80000000;
        }
        piVar5 = (int *)FUN_0214796c(iVar3,piVar5,iVar4,iVar10);
        if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
      }
      uVar13 = thunk_FUN_05040220(piVar5,0);
      uVar1 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      pcVar8 = (char *)(DAT_01d8c340 + 0x1d8c080);
      VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      if (*pcVar8 == '\0') {
        FUN_0101f410(uVar1,*(undefined4 *)(DAT_01d8c344 + 0x1d8c09c));
        *pcVar8 = '\x01';
      }
      piVar9 = *(int **)(DAT_01d8c348 + 0x1d8c0b4);
      if (*(int *)(*piVar9 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      fVar6 = (float)(**(code **)(*piVar5 + 0xf0))(piVar5,*(undefined4 *)(*piVar5 + 0xf4));
      VectorSignedToFloat(fVar6,(byte)(in_fpscr >> 0x16) & 3);
      ceilf(fVar6);
      if (*pcVar8 == '\0') {
        FUN_0101f410(*(undefined4 *)(DAT_01d8c34c + 0x1d8c114));
        *pcVar8 = '\x01';
      }
      uVar1 = VectorSignedToFloat((int)extraout_r0_02,(byte)(in_fpscr >> 0x16) & 3);
      if (*(int *)(*piVar9 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      in_fpscr = in_fpscr & 0xfffffff;
      if (extraout_r0_02 == DAT_01d8c2bc) {
        uVar1 = DAT_01d8c2c0;
      }
      uVar2 = (**(code **)(*piVar5 + 0xe0))(piVar5,*(undefined4 *)(*piVar5 + 0xe4));
      uVar7 = (**(code **)(*piVar5 + 0xf0))(piVar5,*(undefined4 *)(*piVar5 + 0xf4));
      ceilf(__x_01);
      in_fpscr = in_fpscr & 0xfffffff;
      VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat((int)extraout_r0_03,(byte)(in_fpscr >> 0x16) & 3);
      FUN_01d8ebfc(in_stack_00000034,in_stack_00000030,uVar13,uVar1);
      if (fVar12 < fVar11) {
        if (*(int *)(*unaff_r10 + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        thunk_FUN_05069d8c(piVar5,0);
      }
    }
  }
  return in_stack_00000030;
}


===== Scenario_CreateDesignerScenarioCondition @ 0x1d98320 =====

void Scenario_CreateDesignerScenarioCondition(void)

{
                    /* WARNING: Subroutine does not return */
  thunk_FUN_01064660();
}


===== Scenario_ParseDesignerBluePrintPayload @ 0x1d97c08 =====

undefined4 Scenario_ParseDesignerBluePrintPayload(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_r4;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  int unaff_r8;
  int unaff_r10;
  int *piVar11;
  bool in_NG;
  bool bVar12;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if (in_NG) {
    if (*(int *)(unaff_r8 + 400) == 1) {
      unaff_r10 = 3;
    }
    else {
      unaff_r10 = 1;
      if (*(int *)(unaff_r8 + 400) == 0x16) {
        unaff_r10 = 3;
      }
    }
    if (unaff_r8 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
  }
  uVar10 = *(undefined4 *)(unaff_r8 + 0x14);
  iVar5 = FUN_01d1c640();
  if (iVar5 != 0) {
    if (*(int *)(unaff_r8 + 0x184) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = *(undefined4 *)(*(int *)(unaff_r8 + 0x184) + 0x18);
  }
  bVar4 = 0;
  iVar5 = FUN_02134320(0);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = FUN_021374cc(iVar5,uVar10,0);
  if (in_stack_00000020 != iVar5) {
    iVar7 = *(int *)(unaff_r4 + 0x1c);
    iVar5 = FUN_02134320(0);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar6 = FUN_021374cc(iVar5,uVar10,0);
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    bVar4 = FUN_0213750c(iVar7,uVar6,0);
  }
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_02137468(*(int *)(unaff_r4 + 0x1c),uVar10,0);
  iVar5 = *(int *)(unaff_r4 + 0x1c);
  uVar10 = FUN_01d987a4();
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_02143d5c(iVar5,uVar10,0);
  piVar8 = (int *)(unaff_r10 - 1);
  if (piVar8 != (int *)0x2) {
    piVar8 = (int *)(uint)(unaff_r10 == 2);
  }
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  bVar2 = false;
  FUN_02142204(*(int *)(unaff_r4 + 0x1c),piVar8,0);
  if (in_stack_0000001c == 0) {
    iVar5 = FUN_01d931e8();
    if ((iVar5 != 0) && (iVar7 = *(int *)(unaff_r8 + 0x14), iVar5 = FUN_01d931e8(), iVar5 <= iVar7))
    {
      iVar5 = FUN_01d931e8();
      iVar7 = FUN_01d93220();
      if (iVar7 < iVar5) {
        bVar2 = true;
        FUN_01d9359c();
      }
    }
  }
  else {
    iVar5 = FUN_01d93220();
    if (iVar5 == 0) {
      if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      bVar2 = false;
      iVar5 = FUN_0213f708(*(int *)(unaff_r4 + 0x1c),0);
      if ((in_stack_00000020 != iVar5 & bVar4) == 1) {
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0213f724(*(int *)(unaff_r4 + 0x1c),in_stack_00000004,0xe,0);
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_02140d5c(*(int *)(unaff_r4 + 0x1c),in_stack_00000000,0xe,0);
        goto LAB_01d96fa4;
      }
    }
    else {
      iVar7 = *(int *)(unaff_r8 + 0x14);
      iVar5 = FUN_01d93220();
      if (iVar5 <= iVar7) {
        FUN_01d9359c();
LAB_01d96fa4:
        bVar2 = true;
      }
    }
  }
  piVar11 = *(int **)(DAT_01d97fa0 + 0x1d96fb4);
  if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(**(int **)(*piVar11 + 0x5c) + 0x14) == unaff_r8) {
    bVar3 = false;
    if (in_stack_00000010 != *(int *)(unaff_r8 + 0x38)) {
      if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_0213791c(*(int *)(unaff_r4 + 0x1c),0,*(int *)(unaff_r8 + 0x38),0);
      bVar3 = true;
    }
    piVar8 = *(int **)(unaff_r8 + 0x3c);
    if (in_stack_00000014 != piVar8) {
      if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      bVar3 = true;
      FUN_0213791c(*(int *)(unaff_r4 + 0x1c),1,piVar8,0);
    }
    iVar5 = FUN_0220b2ec(0);
    if (iVar5 == 0) goto LAB_01d9727c;
LAB_01d9714c:
    piVar9 = *(int **)(unaff_r8 + 0x40);
    piVar8 = piVar9;
    if (in_stack_00000018 != piVar9) {
      iVar5 = *(int *)(unaff_r4 + 0x1c);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      goto LAB_01d972a4;
    }
  }
  else {
    if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = *(int *)(**(int **)(*piVar11 + 0x5c) + 0x24);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    if (*(char *)(iVar5 + 0x37) == '\0') {
      bVar3 = false;
      if (in_stack_00000010 != 0) {
        bVar3 = true;
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0213791c(*(int *)(unaff_r4 + 0x1c),0,0,0);
      }
      if (in_stack_00000014 != (int *)0x0) {
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        bVar3 = true;
        FUN_0213791c(*(int *)(unaff_r4 + 0x1c),1,0,0);
      }
    }
    else {
      bVar3 = false;
      iVar7 = FUN_0220b2ec(0);
      iVar5 = 0;
      if (iVar7 != 0) {
        iVar5 = *(int *)(unaff_r8 + 0x40);
      }
      if (iVar7 != 0 && iVar5 != 0) {
        if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)(**(int **)(*piVar11 + 0x5c) + 0x24);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar5 + 0x38) == '\0') goto LAB_01d97024;
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        bVar3 = false;
        iVar5 = FUN_021375ec(*(int *)(unaff_r4 + 0x1c),0,0);
        if (iVar5 != 0) {
          if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_0213791c(*(int *)(unaff_r4 + 0x1c),0,0,0);
          bVar3 = true;
        }
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_021375ec(*(int *)(unaff_r4 + 0x1c),1,0);
        if (iVar5 != 0) {
          iVar5 = *(int *)(unaff_r4 + 0x1c);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          piVar9 = (int *)0x0;
          goto LAB_01d9708c;
        }
      }
      else {
LAB_01d97024:
        if (in_stack_00000010 != *(int *)(unaff_r8 + 0x38)) {
          if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          FUN_0213791c(*(int *)(unaff_r4 + 0x1c),0,*(int *)(unaff_r8 + 0x38),0);
          bVar3 = true;
        }
        piVar9 = *(int **)(unaff_r8 + 0x3c);
        piVar8 = piVar9;
        if (in_stack_00000014 != piVar9) {
          iVar5 = *(int *)(unaff_r4 + 0x1c);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
LAB_01d9708c:
          bVar3 = true;
          FUN_0213791c(iVar5,1,piVar9,0);
        }
      }
      iVar5 = FUN_0220b2ec(0);
      if (iVar5 != 0) {
        if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *(int *)(**(int **)(*piVar11 + 0x5c) + 0x24);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(char *)(iVar5 + 0x38) != '\0') {
          piVar8 = (int *)thunk_FUN_0102effc();
          if (*(int *)(*(int *)(*(int *)(DAT_01d97fa4 + 0x1d970f4) + 0x70) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar10 = thunk_FUN_047eecf8(**(undefined4 **)(DAT_01d97fa8 + 0x1d97100),0);
          if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = (**(code **)(*piVar8 + 0x520))(piVar8,uVar10,*(undefined4 *)(*piVar8 + 0x524));
          if (iVar5 == 0) goto LAB_01d9714c;
        }
      }
    }
LAB_01d9727c:
    if (in_stack_00000018 != (int *)0x0) {
      iVar5 = *(int *)(unaff_r4 + 0x1c);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar9 = (int *)0x0;
LAB_01d972a4:
      FUN_0213791c(iVar5,2,piVar9,0);
      bVar3 = true;
    }
  }
  if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  bVar1 = false;
  if ((*(int *)(**(int **)(*piVar11 + 0x5c) + 0x14) == unaff_r8) &&
     (iVar5 = FUN_01d967b4(), iVar5 != 0)) {
    bVar1 = false;
    iVar5 = FUN_01ca86e0(0);
    if (iVar5 == 0) {
      bVar1 = true;
      FUN_01d96174();
    }
  }
  FUN_01d951ac();
  if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(**(int **)(*piVar11 + 0x5c) + 0x14) != unaff_r8) {
    piVar8 = (int *)thunk_FUN_0102effc();
    if (*(int *)(*(int *)(*(int *)(DAT_01d97fac + 0x1d97360) + 0x70) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    bVar12 = false;
    uVar10 = thunk_FUN_047eecf8(**(undefined4 **)(DAT_01d97fb0 + 0x1d9736c),0);
    if (piVar8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = (**(code **)(*piVar8 + 0x520))(piVar8,uVar10,*(undefined4 *)(*piVar8 + 0x524));
    if (iVar5 != 0) goto LAB_01d973bc;
    goto LAB_01d974b4;
  }
LAB_01d973bc:
  if (**(int **)(*piVar11 + 0x5c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)(**(int **)(*piVar11 + 0x5c) + 0x14);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = FUN_01d0dab4(iVar5,0);
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar5 = *(int *)(iVar5 + 0x1c0);
  if (iVar5 != 0) {
    piVar8 = *(int **)(iVar5 + 0x80);
  }
  if (iVar5 != 0 && piVar8 != (int *)0x0) {
    iVar5 = *(int *)(iVar5 + 0x84);
    bVar12 = false;
    if (iVar5 == 3) {
      if (*(int **)(unaff_r8 + 0x4c) == piVar8) goto LAB_01d974b4;
      iVar5 = *(int *)(unaff_r4 + 0x1c);
      *(undefined4 *)(unaff_r8 + 0x48) = 0;
      *(int **)(unaff_r8 + 0x4c) = piVar8;
      *(undefined4 *)(unaff_r8 + 0x44) = 0;
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_0213791c(iVar5,5,piVar8,0);
      if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      FUN_0213791c(*(int *)(unaff_r4 + 0x1c),4,0,0);
      iVar5 = *(int *)(unaff_r4 + 0x1c);
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar10 = 3;
      goto LAB_01d974a4;
    }
    if (iVar5 == 2) {
      if (*(int **)(unaff_r8 + 0x48) != piVar8) {
        iVar5 = *(int *)(unaff_r4 + 0x1c);
        *(undefined4 *)(unaff_r8 + 0x4c) = 0;
        *(undefined4 *)(unaff_r8 + 0x44) = 0;
        *(int **)(unaff_r8 + 0x48) = piVar8;
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        FUN_0213791c(iVar5,4,piVar8,0);
        iVar5 = *(int *)(unaff_r4 + 0x1c);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar10 = 3;
        goto LAB_01d97480;
      }
    }
    else if ((iVar5 == 1) && (*(int **)(unaff_r8 + 0x44) != piVar8)) {
      iVar5 = *(int *)(unaff_r4 + 0x1c);
      *(undefined4 *)(unaff_r8 + 0x4c) = 0;
      *(undefined4 *)(unaff_r8 + 0x48) = 0;
      *(int **)(unaff_r8 + 0x44) = piVar8;
      if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      goto LAB_01d97460;
    }
  }
  else {
    if (*(int *)(unaff_r8 + 0x44) == 0) {
      iVar5 = *(int *)(unaff_r8 + 0x48);
      bVar12 = iVar5 == 0;
      if (bVar12) {
        iVar5 = *(int *)(unaff_r8 + 0x4c);
      }
      if (bVar12 && iVar5 == 0) {
        bVar12 = false;
        goto LAB_01d974b4;
      }
    }
    iVar5 = *(int *)(unaff_r4 + 0x1c);
    *(undefined4 *)(unaff_r8 + 0x44) = 0;
    *(undefined4 *)(unaff_r8 + 0x48) = 0;
    *(undefined4 *)(unaff_r8 + 0x4c) = 0;
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    piVar8 = (int *)0x0;
LAB_01d97460:
    FUN_0213791c(iVar5,3,piVar8,0);
    iVar5 = *(int *)(unaff_r4 + 0x1c);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = 4;
LAB_01d97480:
    FUN_0213791c(iVar5,uVar10,0,0);
    iVar5 = *(int *)(unaff_r4 + 0x1c);
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    uVar10 = 5;
LAB_01d974a4:
    FUN_0213791c(iVar5,uVar10,0,0);
    bVar12 = true;
  }
LAB_01d974b4:
  if (((!bVar2 && !bVar3) && !bVar1) && !bVar12) {
    if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar5 = FUN_0213f708(*(int *)(unaff_r4 + 0x1c),0);
    if (in_stack_00000020 == iVar5) {
      if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      iVar5 = FUN_02142894(*(int *)(unaff_r4 + 0x1c),0);
      if (in_stack_0000000c == iVar5) {
        if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = FUN_02143b50(*(int *)(unaff_r4 + 0x1c),0);
        if (in_stack_00000008 == iVar5) {
          if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = FUN_02143e2c(*(int *)(unaff_r4 + 0x1c),0);
          if (in_stack_0000001c == iVar5) {
            iVar5 = FUN_02134320(0);
            if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = FUN_02147700(iVar5,*(undefined4 *)(*(int *)(unaff_r4 + 0x1c) + 8),0);
            if (iVar5 != 0) goto LAB_01d9760c;
          }
        }
      }
    }
  }
  iVar5 = FUN_02134320(0);
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar10 = FUN_0213706c(*(int *)(unaff_r4 + 0x1c),0);
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  FUN_0215410c(iVar5,uVar10,*(undefined4 *)(*(int *)(unaff_r4 + 0x1c) + 8),0);
LAB_01d9760c:
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar10 = FUN_0213706c(*(int *)(unaff_r4 + 0x1c),0);
  *(undefined4 *)(unaff_r4 + 0x18) = uVar10;
  if (*(int *)(unaff_r4 + 0x1c) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  return *(undefined4 *)(*(int *)(unaff_r4 + 0x1c) + 8);
}


===== Scenario_LoadLegacyFormat @ 0x1d909dc =====

undefined4 Scenario_LoadLegacyFormat(void)

{
  int iVar1;
  undefined4 unaff_r4;
  
  iVar1 = FUN_03c875b4();
  if (iVar1 != 0) {
    unaff_r4 = *(undefined4 *)(iVar1 + 8);
  }
  return unaff_r4;
}


===== RandomDeckCollection_ValidateAndSetScenario @ 0x1a6b61c =====

/* WARNING: Removing unreachable block (ram,0x01a6cb40) */
/* WARNING: Removing unreachable block (ram,0x01a6cb30) */
/* WARNING: Removing unreachable block (ram,0x01a6bdc8) */
/* WARNING: Removing unreachable block (ram,0x01a6c5e0) */
/* WARNING: Removing unreachable block (ram,0x01a6cfec) */
/* WARNING: Removing unreachable block (ram,0x01a6cff8) */
/* WARNING: Removing unreachable block (ram,0x01a6bf74) */
/* WARNING: Removing unreachable block (ram,0x01a6bdc0) */
/* WARNING: Removing unreachable block (ram,0x01a6c5d8) */
/* WARNING: Removing unreachable block (ram,0x01a6c6d8) */
/* WARNING: Removing unreachable block (ram,0x01a6beb4) */
/* WARNING: Removing unreachable block (ram,0x01a6c78c) */
/* WARNING: Removing unreachable block (ram,0x01a6c794) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void RandomDeckCollection_ValidateAndSetScenario
               (int param_1,int param_2,uint param_3,int *param_4,undefined4 param_5,
               undefined4 param_6,int param_7,int param_8,undefined4 param_9,int *param_10,
               int param_11,int param_12)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int unaff_r4;
  undefined4 unaff_r6;
  int unaff_r7;
  int *unaff_r8;
  int *piVar13;
  int unaff_r9;
  int unaff_r10;
  int iVar14;
  int *unaff_r11;
  
  do {
    do {
      if (param_4[-1] == param_2) {
        puVar1 = (undefined4 *)(param_1 + *param_4 * 8 + 0xc0);
        goto LAB_01a6b650;
      }
      param_3 = param_3 - 1;
      param_4 = param_4 + 2;
    } while (param_3 != 0);
    do {
      puVar1 = (undefined4 *)FUN_0105aa50(unaff_r8,param_2,0);
LAB_01a6b650:
      (*(code *)*puVar1)(unaff_r8,puVar1[1]);
      do {
        if (unaff_r4 != 0) {
          FUN_0101f668(unaff_r4);
        }
        piVar13 = *(int **)(DAT_01a6c670 + 0x1a6b684);
        if (unaff_r9 != 0x12 && unaff_r9 != 0) {
          return;
        }
        if (unaff_r7 == 0) {
          unaff_r10 = thunk_FUN_0464f828(**(undefined4 **)(DAT_01a6c674 + 0x1a6b6a0),unaff_r6,0);
        }
        if (unaff_r10 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        if (*(int *)(unaff_r10 + 8) != 0) {
          if (param_12 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          *(int *)(param_12 + 0x10) = unaff_r10;
          (**(code **)(*param_10 + 0x1a8))(param_10,param_12,*(undefined4 *)(*param_10 + 0x1ac));
          param_8 = param_8 + 1;
          if (param_8 == param_7) {
            iVar8 = *(int *)(**(int **)(DAT_01a6c6d4 + 0x1a6b758) + 0x74);
            *(int **)(param_11 + 0x128) = param_10;
            if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01077b58();
            }
            piVar2 = (int *)FUN_017a1bd8(0x32,3,0);
            piVar3 = (int *)thunk_FUN_0105db90(**(undefined4 **)(DAT_01a6c75c + 0x1a6b794));
            thunk_FUN_0476f85c(piVar3,0);
            if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            piVar2 = (int *)(**(code **)(*piVar2 + 0x1e8))(piVar2,*(undefined4 *)(*piVar2 + 0x1ec));
            goto LAB_01a6b7e4;
          }
          if (*(int *)(**(int **)(DAT_01a6c0ec + 0x1a6b1f8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_017a2b80(0);
          if (*(int *)(**(int **)(DAT_01a6c0f0 + 0x1a6b220) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          iVar8 = FUN_01f7e348(0,6,0);
          param_9 = FUN_017a0b4c(uVar6,iVar8 == 0,0,0);
          param_12 = thunk_FUN_0105db90(*piVar13);
          FUN_01ba92d0(param_12,param_9,1,param_11);
          unaff_r10 = **(int **)(DAT_01a6c26c + 0x1a6b294);
        }
        if (*(int *)(**(int **)(DAT_01a6c270 + 0x1a6b2a4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        iVar8 = FUN_01f7e348(0,3,0);
        if (iVar8 < 2) {
          if (param_12 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_01a6c2c0 + 0x1a6b324) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          unaff_r6 = FUN_017a35fc(param_9,*(undefined4 *)(param_12 + 0x18),
                                  *(undefined4 *)(param_12 + 0x20),0);
        }
        else {
          if (*(int *)(**(int **)(DAT_01a6c2bc + 0x1a6b2d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          iVar8 = FUN_01f7e348(0,2,0);
          if (iVar8 == 0) {
            if (*(int *)(**(int **)(DAT_01a6c2c4 + 0x1a6b360) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01077b58();
            }
            iVar8 = FUN_015d49f4(**(undefined4 **)(DAT_01a6c2c8 + 0x1a6b380),0);
          }
          else {
            iVar8 = FUN_01a4e1f8(param_11);
          }
          if (param_12 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          unaff_r6 = FUN_013b51e4(iVar8,*(undefined4 *)(param_12 + 0x18),0);
        }
        if (param_10 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar2 = (int *)(**(code **)(*param_10 + 0x1e8))
                                  (param_10,*(undefined4 *)(*param_10 + 0x1ec));
        do {
          if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar8 = *piVar2;
          uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
          if (uVar11 != 0) {
            piVar3 = (int *)(*(int *)(iVar8 + 0x58) + 4);
            do {
              if (piVar3[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar8 + *piVar3 * 8 + 0xc0);
                goto LAB_01a6b454;
              }
              uVar11 = uVar11 - 1;
              piVar3 = piVar3 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,0);
LAB_01a6b454:
          unaff_r7 = (*(code *)*puVar1)(piVar2,puVar1[1]);
          unaff_r9 = 0x12;
          if (unaff_r7 == 0) {
            unaff_r7 = 0;
            break;
          }
          if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar8 = *piVar2;
          uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
          if (uVar11 != 0) {
            piVar3 = (int *)(*(int *)(iVar8 + 0x58) + 4);
            do {
              if (piVar3[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar8 + *piVar3 * 8 + 200);
                goto LAB_01a6b4d4;
              }
              uVar11 = uVar11 - 1;
              piVar3 = piVar3 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,1);
LAB_01a6b4d4:
          piVar3 = (int *)(*(code *)*puVar1)(piVar2,puVar1[1]);
          if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar9 = *piVar13;
          iVar8 = *piVar3;
          uVar11 = (uint)*(byte *)(iVar9 + 0xb8);
          if ((*(byte *)(iVar8 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar8 + 100) + uVar11 * 4 + -4) != iVar9)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar3);
          }
          if ((*(byte *)(iVar8 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar8 + 100) + uVar11 * 4 + -4) != iVar9)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar3);
          }
          if (piVar3[4] == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar8 = thunk_FUN_04666814(piVar3[4],0);
          if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar8 = thunk_FUN_0465f908(iVar8,unaff_r6,0);
        } while (iVar8 == 0);
        unaff_r4 = 0;
        unaff_r8 = (int *)thunk_FUN_0105da7c(piVar2,**(undefined4 **)(DAT_01a6c5a8 + 0x1a6b5e0));
      } while (unaff_r8 == (int *)0x0);
      param_1 = *unaff_r8;
      param_3 = (uint)*(ushort *)(param_1 + 0xb6);
      param_2 = **(int **)(DAT_01a6c5ac + 0x1a6b608);
    } while (param_3 == 0);
    param_4 = (int *)(*(int *)(param_1 + 0x58) + 4);
  } while( true );
LAB_01a6b7e4:
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar8 = *piVar2;
  uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
  if (uVar11 != 0) {
    piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
    do {
      if (piVar12[-1] == *unaff_r11) {
        puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 0xc0);
        goto LAB_01a6b840;
      }
      uVar11 = uVar11 - 1;
      piVar12 = piVar12 + 2;
    } while (uVar11 != 0);
  }
  puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,0);
LAB_01a6b840:
  iVar8 = (*(code *)*puVar1)(piVar2,puVar1[1]);
  if (iVar8 == 0) {
    piVar2 = (int *)thunk_FUN_0105da7c(piVar2,**(undefined4 **)(DAT_01a6ce34 + 0x1a6bed0));
    if (piVar2 == (int *)0x0) goto LAB_01a6bf68;
    iVar8 = *piVar2;
    uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
    if (uVar11 == 0) goto LAB_01a6bf28;
    piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
    goto LAB_01a6bf10;
  }
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar8 = *piVar2;
  uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
  if (uVar11 != 0) {
    piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
    do {
      if (piVar12[-1] == *unaff_r11) {
        puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 200);
        goto LAB_01a6b8b8;
      }
      uVar11 = uVar11 - 1;
      piVar12 = piVar12 + 2;
    } while (uVar11 != 0);
  }
  puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,1);
LAB_01a6b8b8:
  piVar12 = (int *)(*(code *)*puVar1)(piVar2,puVar1[1]);
  param_10 = (int *)0x0;
  if (piVar12 != (int *)0x0) {
    uVar11 = (uint)*(byte *)(**(int **)(DAT_01a6c760 + 0x1a6b8e4) + 0xb8);
    if ((*(byte *)(*piVar12 + 0xb8) < uVar11) ||
       (*(int *)(*(int *)(*piVar12 + 100) + uVar11 * 4 + -4) != **(int **)(DAT_01a6c760 + 0x1a6b8e4)
       )) {
                    /* WARNING: Subroutine does not return */
      FUN_0101fa24();
    }
    param_10 = piVar12;
  }
  if (*(int *)(**(int **)(DAT_01a6c8e4 + 0x1a6b91c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  iVar8 = FUN_01f7e348(0,5,0);
  if (0 < iVar8 + 3) {
    iVar9 = 0;
    do {
      iVar4 = thunk_FUN_0105db90(*piVar13);
      FUN_01ba92d0(iVar4,param_10,4,param_11);
      iVar14 = **(int **)(&LAB_01a6b980 + DAT_01a6c970);
      do {
        if (*(int *)(**(int **)(DAT_01a6c974 + 0x1a6b98c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01077b58();
        }
        iVar5 = FUN_01f7e348(0,3,0);
        if (iVar5 < 2) {
          if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          if (*(int *)(**(int **)(DAT_01a6c97c + 0x1a6ba3c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          uVar6 = FUN_017a35fc(param_10,*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x20),
                               0);
        }
        else {
          if (*(int *)(**(int **)(DAT_01a6c978 + 0x1a6b9c0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          iVar5 = FUN_01f7e348(0,2,0);
          if (iVar5 == 0) {
            if (*(int *)(**(int **)(DAT_01a6c980 + 0x1a6ba78) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01077b58();
            }
            iVar5 = FUN_015d49f4(**(undefined4 **)(DAT_01a6ca8c + 0x1a6ba94),0);
            if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar6 = FUN_013b51e4(iVar5,*(undefined4 *)(iVar4 + 0x18),0);
          }
          else {
            iVar5 = FUN_01a4e1f8(param_11);
            if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            uVar6 = FUN_013b51e4(iVar5,*(undefined4 *)(iVar4 + 0x18),0);
          }
        }
        if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar13 = (int *)(**(code **)(*piVar3 + 0x1e8))(piVar3,*(undefined4 *)(*piVar3 + 0x1ec));
        do {
          if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *piVar13;
          uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar12[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar5 + *piVar12 * 8 + 0xc0);
                goto LAB_01a6bba8;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,0);
LAB_01a6bba8:
          iVar5 = (*(code *)*puVar1)(piVar13,puVar1[1]);
          if (iVar5 == 0) {
            iVar5 = 0;
            break;
          }
          if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = *piVar13;
          uVar11 = (uint)*(ushort *)(iVar7 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar7 + 0x58) + 4);
            do {
              if (piVar12[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar7 + *piVar12 * 8 + 200);
                goto LAB_01a6bc3c;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,1);
LAB_01a6bc3c:
          piVar12 = (int *)(*(code *)*puVar1)(piVar13,puVar1[1]);
          if (piVar12 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar10 = **(int **)(DAT_01a6cbd0 + 0x1a6bc64);
          iVar7 = *piVar12;
          uVar11 = (uint)*(byte *)(iVar10 + 0xb8);
          if ((*(byte *)(iVar7 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar7 + 100) + uVar11 * 4 + -4) != iVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar12);
          }
          if ((*(byte *)(iVar7 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar7 + 100) + uVar11 * 4 + -4) != iVar10)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar12);
          }
          if (piVar12[4] == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = thunk_FUN_0465f96c(piVar12[4],uVar6,5,0);
        } while (iVar7 == 0);
        piVar13 = (int *)thunk_FUN_0105da7c(piVar13,**(undefined4 **)(DAT_01a6cbd8 + 0x1a6bd2c));
        if (piVar13 != (int *)0x0) {
          iVar7 = *piVar13;
          uVar11 = (uint)*(ushort *)(iVar7 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar7 + 0x58) + 4);
            do {
              if (piVar12[-1] == **(int **)(DAT_01a6cbdc + 0x1a6bd5c)) {
                puVar1 = (undefined4 *)(iVar7 + *piVar12 * 8 + 0xc0);
                goto LAB_01a6bda4;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar13,**(int **)(DAT_01a6cbdc + 0x1a6bd5c),0);
LAB_01a6bda4:
          (*(code *)*puVar1)(piVar13,puVar1[1]);
        }
        if (iVar5 == 0) {
          iVar14 = thunk_FUN_0464f828(**(undefined4 **)(DAT_01a6cda8 + 0x1a6bde4),uVar6,0);
        }
        if (iVar14 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
      } while (*(int *)(iVar14 + 8) == 0);
      if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(int *)(iVar4 + 0x10) = iVar14;
      (**(code **)(*piVar3 + 0x1a8))(piVar3,iVar4,*(undefined4 *)(*piVar3 + 0x1ac));
      iVar9 = iVar9 + 1;
      piVar13 = *(int **)(&LAB_01a6bea4 + DAT_01a6ce2c);
    } while (iVar9 != iVar8 + 3);
  }
  goto LAB_01a6b7e4;
  while( true ) {
    uVar11 = uVar11 - 1;
    piVar12 = piVar12 + 2;
    if (uVar11 == 0) break;
LAB_01a6bf10:
    if (piVar12[-1] == **(int **)(DAT_01a6ce38 + 0x1a6befc)) {
      puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 0xc0);
      goto LAB_01a6bf58;
    }
  }
LAB_01a6bf28:
  puVar1 = (undefined4 *)FUN_0105aa50(piVar2,**(int **)(DAT_01a6ce38 + 0x1a6befc),0);
LAB_01a6bf58:
  (*(code *)*puVar1)(piVar2,puVar1[1]);
LAB_01a6bf68:
  iVar8 = *(int *)(**(int **)(DAT_01a6cf3c + 0x1a6bf90) + 0x74);
  *(int **)(param_11 + 0x134) = piVar3;
  if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  piVar2 = (int *)FUN_017a1788(2,0);
  piVar3 = (int *)thunk_FUN_0105db90(**(undefined4 **)(DAT_01a6cf40 + 0x1a6bfc8));
  thunk_FUN_0476f85c(piVar3,0);
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x1e8))(piVar2,*(undefined4 *)(*piVar2 + 0x1ec));
  do {
    if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar8 = *piVar2;
    uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
    if (uVar11 != 0) {
      piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
      do {
        if (piVar12[-1] == *unaff_r11) {
          puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 0xc0);
          goto LAB_01a6c078;
        }
        uVar11 = uVar11 - 1;
        piVar12 = piVar12 + 2;
      } while (uVar11 != 0);
    }
    puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,0);
LAB_01a6c078:
    iVar8 = (*(code *)*puVar1)(piVar2,puVar1[1]);
    if (iVar8 == 0) {
      piVar2 = (int *)thunk_FUN_0105da7c(piVar2,**(undefined4 **)(DAT_01a6d368 + 0x1a6c6f4));
      if (piVar2 == (int *)0x0) goto LAB_01a6c780;
      iVar8 = *piVar2;
      uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
      if (uVar11 == 0) goto LAB_01a6c74c;
      piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
      break;
    }
    if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    iVar8 = *piVar2;
    uVar11 = (uint)*(ushort *)(iVar8 + 0xb6);
    if (uVar11 != 0) {
      piVar12 = (int *)(*(int *)(iVar8 + 0x58) + 4);
      do {
        if (piVar12[-1] == *unaff_r11) {
          puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 200);
          goto LAB_01a6c100;
        }
        uVar11 = uVar11 - 1;
        piVar12 = piVar12 + 2;
      } while (uVar11 != 0);
    }
    puVar1 = (undefined4 *)FUN_0105aa50(piVar2,*unaff_r11,1);
LAB_01a6c100:
    piVar12 = (int *)(*(code *)*puVar1)(piVar2,puVar1[1]);
    param_10 = (int *)0x0;
    if (piVar12 != (int *)0x0) {
      uVar11 = (uint)*(byte *)(**(int **)(DAT_01a6d090 + 0x1a6c12c) + 0xb8);
      if ((*(byte *)(*piVar12 + 0xb8) < uVar11) ||
         (*(int *)(*(int *)(*piVar12 + 100) + uVar11 * 4 + -4) !=
          **(int **)(DAT_01a6d090 + 0x1a6c12c))) {
                    /* WARNING: Subroutine does not return */
        FUN_0101fa24();
      }
      param_10 = piVar12;
    }
    if (*(int *)(**(int **)(DAT_01a6d14c + 0x1a6c164) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    iVar8 = FUN_01f7e348(0,4,0);
    if (0 < iVar8 + 2) {
      iVar9 = 0;
      do {
        iVar4 = thunk_FUN_0105db90(*piVar13);
        FUN_01ba92d0(iVar4,param_10,3,param_11);
        iVar14 = **(int **)(&LAB_01a6c1c8 + DAT_01a6d1b8);
        do {
          if (*(int *)(**(int **)(DAT_01a6d1c8 + 0x1a6c1d4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01077b58();
          }
          iVar5 = FUN_01f7e348(0,3,0);
          if (iVar5 < 2) {
            if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            if (*(int *)(**(int **)(DAT_01a6d284 + 0x1a6c28c) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01077b58();
            }
            uVar6 = FUN_017a35fc(param_10,*(undefined4 *)(iVar4 + 0x18),
                                 *(undefined4 *)(iVar4 + 0x20),0);
          }
          else {
            if (*(int *)(**(int **)(DAT_01a6d200 + 0x1a6c208) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01077b58();
            }
            iVar5 = FUN_01f7e348(0,2,0);
            if (iVar5 == 0) {
              if (*(int *)(**(int **)(DAT_01a6d2b0 + 0x1a6c2d8) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01077b58();
              }
              iVar5 = FUN_015d49f4(**(undefined4 **)(DAT_01a6d2b4 + 0x1a6c2f4),0);
              if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              uVar6 = FUN_013b51e4(iVar5,*(undefined4 *)(iVar4 + 0x18),0);
            }
            else {
              iVar5 = FUN_01a4e1f8(param_11);
              if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_01064660();
              }
              uVar6 = FUN_013b51e4(iVar5,*(undefined4 *)(iVar4 + 0x18),0);
            }
          }
          if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          piVar13 = (int *)(**(code **)(*piVar3 + 0x1e8))(piVar3,*(undefined4 *)(*piVar3 + 0x1ec));
          do {
            if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar5 = *piVar13;
            uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
            if (uVar11 != 0) {
              piVar12 = (int *)(*(int *)(iVar5 + 0x58) + 4);
              do {
                if (piVar12[-1] == *unaff_r11) {
                  puVar1 = (undefined4 *)(iVar5 + *piVar12 * 8 + 0xc0);
                  goto LAB_01a6c3d0;
                }
                uVar11 = uVar11 - 1;
                piVar12 = piVar12 + 2;
              } while (uVar11 != 0);
            }
            puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,0);
LAB_01a6c3d0:
            iVar5 = (*(code *)*puVar1)(piVar13,puVar1[1]);
            if (iVar5 == 0) {
              iVar5 = 0;
              break;
            }
            if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = *piVar13;
            uVar11 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar11 != 0) {
              piVar12 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar12[-1] == *unaff_r11) {
                  puVar1 = (undefined4 *)(iVar7 + *piVar12 * 8 + 200);
                  goto LAB_01a6c450;
                }
                uVar11 = uVar11 - 1;
                piVar12 = piVar12 + 2;
              } while (uVar11 != 0);
            }
            puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,1);
LAB_01a6c450:
            piVar12 = (int *)(*(code *)*puVar1)(piVar13,puVar1[1]);
            if (piVar12 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar10 = **(int **)(DAT_01a6d348 + 0x1a6c478);
            iVar7 = *piVar12;
            uVar11 = (uint)*(byte *)(iVar10 + 0xb8);
            if ((*(byte *)(iVar7 + 0xb8) < uVar11) ||
               (*(int *)(*(int *)(iVar7 + 100) + uVar11 * 4 + -4) != iVar10)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar12);
            }
            if ((*(byte *)(iVar7 + 0xb8) < uVar11) ||
               (*(int *)(*(int *)(iVar7 + 100) + uVar11 * 4 + -4) != iVar10)) {
                    /* WARNING: Subroutine does not return */
              FUN_0101fa24(piVar12);
            }
            if (piVar12[4] == 0) {
                    /* WARNING: Subroutine does not return */
              thunk_FUN_01064660();
            }
            iVar7 = thunk_FUN_0465f96c(piVar12[4],uVar6,5,0);
          } while (iVar7 == 0);
          piVar13 = (int *)thunk_FUN_0105da7c(piVar13,**(undefined4 **)(DAT_01a6d350 + 0x1a6c53c));
          if (piVar13 != (int *)0x0) {
            iVar7 = *piVar13;
            uVar11 = (uint)*(ushort *)(iVar7 + 0xb6);
            if (uVar11 != 0) {
              piVar12 = (int *)(*(int *)(iVar7 + 0x58) + 4);
              do {
                if (piVar12[-1] == **(int **)(DAT_01a6d354 + 0x1a6c56c)) {
                  puVar1 = (undefined4 *)(iVar7 + *piVar12 * 8 + 0xc0);
                  goto LAB_01a6c5bc;
                }
                uVar11 = uVar11 - 1;
                piVar12 = piVar12 + 2;
              } while (uVar11 != 0);
            }
            puVar1 = (undefined4 *)FUN_0105aa50(piVar13,**(int **)(DAT_01a6d354 + 0x1a6c56c),0);
LAB_01a6c5bc:
            (*(code *)*puVar1)(piVar13,puVar1[1]);
          }
          if (iVar5 == 0) {
            iVar14 = thunk_FUN_0464f828(**(undefined4 **)(DAT_01a6d358 + 0x1a6c5fc),uVar6,0);
          }
          if (iVar14 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
        } while (*(int *)(iVar14 + 8) == 0);
        if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        *(int *)(iVar4 + 0x10) = iVar14;
        (**(code **)(*piVar3 + 0x1a8))(piVar3,iVar4,*(undefined4 *)(*piVar3 + 0x1ac));
        iVar9 = iVar9 + 1;
        piVar13 = *(int **)(&LAB_01a6c6c4 + DAT_01a6d35c);
      } while (iVar9 != iVar8 + 2);
    }
  } while( true );
  while( true ) {
    uVar11 = uVar11 - 1;
    piVar12 = piVar12 + 2;
    if (uVar11 == 0) break;
    if (piVar12[-1] == **(int **)(DAT_01a6d36c + 0x1a6c720)) {
      puVar1 = (undefined4 *)(iVar8 + *piVar12 * 8 + 0xc0);
      goto LAB_01a6c770;
    }
  }
LAB_01a6c74c:
  puVar1 = (undefined4 *)FUN_0105aa50(piVar2,**(int **)(DAT_01a6d36c + 0x1a6c720),0);
LAB_01a6c770:
  (*(code *)*puVar1)(piVar2,puVar1[1]);
LAB_01a6c780:
  uVar6 = **(undefined4 **)(DAT_01a6d370 + 0x1a6c7a8);
  *(int **)(param_11 + 0x130) = piVar3;
  piVar2 = (int *)thunk_FUN_0105db90(uVar6);
  thunk_FUN_0476f85c(piVar2,0);
  iVar8 = 0;
  do {
    if (*(int *)(**(int **)(DAT_01a6d374 + 0x1a6c7d4) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01077b58();
    }
    uVar6 = FUN_017a0b4c(10,0,0,0);
    iVar9 = thunk_FUN_0105db90(*piVar13);
    FUN_01ba92d0(iVar9,uVar6,5,param_11);
    iVar4 = **(int **)(DAT_01a6d378 + 0x1a6c830);
    do {
      if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      uVar6 = FUN_01bafd10(iVar9,0);
      if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      piVar13 = (int *)(**(code **)(*piVar2 + 0x1e8))(piVar2,*(undefined4 *)(*piVar2 + 0x1ec));
      do {
        if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar14 = *piVar13;
        uVar11 = (uint)*(ushort *)(iVar14 + 0xb6);
        if (uVar11 != 0) {
          piVar3 = (int *)(*(int *)(iVar14 + 0x58) + 4);
          do {
            if (piVar3[-1] == *unaff_r11) {
              puVar1 = (undefined4 *)(iVar14 + *piVar3 * 8 + 0xc0);
              goto LAB_01a6c8f4;
            }
            uVar11 = uVar11 - 1;
            piVar3 = piVar3 + 2;
          } while (uVar11 != 0);
        }
        puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,0);
LAB_01a6c8f4:
        iVar14 = (*(code *)*puVar1)(piVar13,puVar1[1]);
        if (iVar14 == 0) {
          iVar14 = 0;
          break;
        }
        if (piVar13 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = *piVar13;
        uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
        if (uVar11 != 0) {
          piVar3 = (int *)(*(int *)(iVar5 + 0x58) + 4);
          do {
            if (piVar3[-1] == *unaff_r11) {
              puVar1 = (undefined4 *)(iVar5 + *piVar3 * 8 + 200);
              goto LAB_01a6c990;
            }
            uVar11 = uVar11 - 1;
            piVar3 = piVar3 + 2;
          } while (uVar11 != 0);
        }
        puVar1 = (undefined4 *)FUN_0105aa50(piVar13,*unaff_r11,1);
LAB_01a6c990:
        piVar3 = (int *)(*(code *)*puVar1)(piVar13,puVar1[1]);
        if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar7 = **(int **)(DAT_01a6d37c + 0x1a6c9b8);
        iVar5 = *piVar3;
        uVar11 = (uint)*(byte *)(iVar7 + 0xb8);
        if ((*(byte *)(iVar5 + 0xb8) < uVar11) ||
           (*(int *)(*(int *)(iVar5 + 100) + uVar11 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_0101fa24(piVar3);
        }
        if ((*(byte *)(iVar5 + 0xb8) < uVar11) ||
           (*(int *)(*(int *)(iVar5 + 100) + uVar11 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
          FUN_0101fa24(piVar3);
        }
        if (piVar3[4] == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = thunk_FUN_04666814(piVar3[4],0);
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        iVar5 = thunk_FUN_0465f908(iVar5,uVar6,0);
      } while (iVar5 == 0);
      piVar3 = (int *)thunk_FUN_0105da7c(piVar13,**(undefined4 **)(DAT_01a6d384 + 0x1a6caa0));
      piVar13 = *(int **)(DAT_01a6d388 + 0x1a6cabc);
      if (piVar3 != (int *)0x0) {
        iVar5 = *piVar3;
        uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
        if (uVar11 != 0) {
          piVar12 = (int *)(*(int *)(iVar5 + 0x58) + 4);
          do {
            if (piVar12[-1] == **(int **)(DAT_01a6d38c + 0x1a6cad0)) {
              puVar1 = (undefined4 *)(iVar5 + *piVar12 * 8 + 0xc0);
              goto LAB_01a6cb18;
            }
            uVar11 = uVar11 - 1;
            piVar12 = piVar12 + 2;
          } while (uVar11 != 0);
        }
        puVar1 = (undefined4 *)FUN_0105aa50(piVar3,**(int **)(DAT_01a6d38c + 0x1a6cad0),0);
LAB_01a6cb18:
        (*(code *)*puVar1)(piVar3,puVar1[1]);
      }
      if (iVar14 == 0) {
        iVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_01a6d390 + 0x1a6cb60),uVar6,0);
      }
      if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
    } while (*(int *)(iVar4 + 8) == 0);
    if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_01064660();
    }
    *(int *)(iVar9 + 0x10) = iVar4;
    (**(code **)(*piVar2 + 0x1a8))(piVar2,iVar9,*(undefined4 *)(*piVar2 + 0x1ac));
    iVar8 = iVar8 + 1;
  } while (iVar8 != 6);
  *(int **)(param_11 + 0x138) = piVar2;
  iVar8 = FUN_01a4e1f8();
  if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  if (*(int *)(iVar8 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  iVar8 = thunk_FUN_0465f908(*(int *)(iVar8 + 0xc),**(undefined4 **)(DAT_01a6d394 + 0x1a6cc54),0);
  if (iVar8 != 0) {
    piVar2 = (int *)thunk_FUN_0105db90(**(undefined4 **)(DAT_01a6d398 + 0x1a6cc70));
    thunk_FUN_0476f85c(piVar2,0);
    iVar8 = 0;
    do {
      if (*(int *)(**(int **)(DAT_01a6d39c + 0x1a6cc98) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01077b58();
      }
      uVar6 = FUN_017a0b4c(0xc,0,0,0);
      iVar9 = thunk_FUN_0105db90(*piVar13);
      FUN_01ba92d0(iVar9,uVar6,7,param_11);
      iVar4 = **(int **)(DAT_01a6d3a0 + 0x1a6ccf4);
      do {
        if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        uVar6 = FUN_01bafd10(iVar9,0);
        if (piVar2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
        piVar3 = (int *)(**(code **)(*piVar2 + 0x1e8))(piVar2,*(undefined4 *)(*piVar2 + 0x1ec));
        do {
          if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar14 = *piVar3;
          uVar11 = (uint)*(ushort *)(iVar14 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar14 + 0x58) + 4);
            do {
              if (piVar12[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar14 + *piVar12 * 8 + 0xc0);
                goto LAB_01a6cdb8;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar3,*unaff_r11,0);
LAB_01a6cdb8:
          iVar14 = (*(code *)*puVar1)(piVar3,puVar1[1]);
          if (iVar14 == 0) {
            iVar14 = 0;
            break;
          }
          if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = *piVar3;
          uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar12[-1] == *unaff_r11) {
                puVar1 = (undefined4 *)(iVar5 + *piVar12 * 8 + 200);
                goto LAB_01a6ce48;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar3,*unaff_r11,1);
LAB_01a6ce48:
          piVar12 = (int *)(*(code *)*puVar1)(piVar3,puVar1[1]);
          if (piVar12 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar7 = *piVar13;
          iVar5 = *piVar12;
          uVar11 = (uint)*(byte *)(iVar7 + 0xb8);
          if ((*(byte *)(iVar5 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar5 + 100) + uVar11 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar12);
          }
          if ((*(byte *)(iVar5 + 0xb8) < uVar11) ||
             (*(int *)(*(int *)(iVar5 + 100) + uVar11 * 4 + -4) != iVar7)) {
                    /* WARNING: Subroutine does not return */
            FUN_0101fa24(piVar12);
          }
          if (piVar12[4] == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = thunk_FUN_04666814(piVar12[4],0);
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_01064660();
          }
          iVar5 = thunk_FUN_0465f908(iVar5,uVar6,0);
        } while (iVar5 == 0);
        piVar3 = (int *)thunk_FUN_0105da7c(piVar3,**(undefined4 **)(DAT_01a6d3a4 + 0x1a6cf5c));
        piVar13 = *(int **)(DAT_01a6d3a8 + 0x1a6cf78);
        if (piVar3 != (int *)0x0) {
          iVar5 = *piVar3;
          uVar11 = (uint)*(ushort *)(iVar5 + 0xb6);
          if (uVar11 != 0) {
            piVar12 = (int *)(*(int *)(iVar5 + 0x58) + 4);
            do {
              if (piVar12[-1] == **(int **)(DAT_01a6d3ac + 0x1a6cf8c)) {
                puVar1 = (undefined4 *)(iVar5 + *piVar12 * 8 + 0xc0);
                goto LAB_01a6cfd4;
              }
              uVar11 = uVar11 - 1;
              piVar12 = piVar12 + 2;
            } while (uVar11 != 0);
          }
          puVar1 = (undefined4 *)FUN_0105aa50(piVar3,**(int **)(DAT_01a6d3ac + 0x1a6cf8c),0);
LAB_01a6cfd4:
          (*(code *)*puVar1)(piVar3,puVar1[1]);
        }
        if (iVar14 == 0) {
          iVar4 = thunk_FUN_0464f828(**(undefined4 **)(DAT_01a6d3b0 + 0x1a6d020),uVar6,0);
        }
        if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_01064660();
        }
      } while (*(int *)(iVar4 + 8) == 0);
      if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_01064660();
      }
      *(int *)(iVar9 + 0x10) = iVar4;
      (**(code **)(*piVar2 + 0x1a8))(piVar2,iVar9,*(undefined4 *)(*piVar2 + 0x1ac));
      iVar8 = iVar8 + 1;
    } while (iVar8 != 6);
    *(int **)(param_11 + 0x13c) = piVar2;
  }
  if (*(int *)(**(int **)(DAT_01a6d3b4 + 0x1a6d0e0) + 0x74) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01077b58();
  }
  uVar6 = FUN_017a1e34(0);
  iVar8 = thunk_FUN_0105db90(*piVar13);
  FUN_01ba92d0(iVar8,uVar6,6,param_11);
  if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_01064660();
  }
  uVar6 = FUN_01bafd10(iVar8,0);
  *(int *)(param_11 + 0x140) = iVar8;
  *(undefined4 *)(iVar8 + 0x10) = uVar6;
  return;
}


