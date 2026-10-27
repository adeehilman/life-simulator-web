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


