	.cpu cortex-m4
	.eabi_attribute 27, 1
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"min_max.c"
	.text
.Ltext0:
	.section	.text.check_lower_upper_range,"ax",%progbits
	.align	1
	.global	check_lower_upper_range
	.syntax unified
	.thumb
	.thumb_func
	.fpu fpv4-sp-d16
	.type	check_lower_upper_range, %function
check_lower_upper_range:
.LFB0:
	.file 1 "C:\\Repositories\\nRFSwarm\\drivers\\source\\min_max.c"
	.loc 1 8 0
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #16
.LCFI0:
	vstr.32	s0, [sp, #12]
	vstr.32	s1, [sp, #8]
	vstr.32	s2, [sp, #4]
	.loc 1 9 0
	vldr.32	s14, [sp, #12]
	vldr.32	s15, [sp, #4]
	vcmpe.f32	s14, s15
	vmrs	APSR_nzcv, FPSCR
	blt	.L9
	.loc 1 10 0
	ldr	r3, [sp, #4]	@ float
	str	r3, [sp, #12]	@ float
	b	.L4
.L9:
	.loc 1 11 0
	vldr.32	s14, [sp, #12]
	vldr.32	s15, [sp, #8]
	vcmpe.f32	s14, s15
	vmrs	APSR_nzcv, FPSCR
	bhi	.L4
	.loc 1 12 0
	ldr	r3, [sp, #8]	@ float
	str	r3, [sp, #12]	@ float
.L4:
	.loc 1 14 0
	ldr	r3, [sp, #12]	@ float
	vmov	s15, r3
	.loc 1 15 0
	vmov.f32	s0, s15
	add	sp, sp, #16
.LCFI1:
	@ sp needed
	bx	lr
.LFE0:
	.size	check_lower_upper_range, .-check_lower_upper_range
	.section	.text.min,"ax",%progbits
	.align	1
	.global	min
	.syntax unified
	.thumb
	.thumb_func
	.fpu fpv4-sp-d16
	.type	min, %function
min:
.LFB1:
	.loc 1 18 0
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #8
.LCFI2:
	str	r0, [sp, #4]
	str	r1, [sp]
	.loc 1 19 0
	ldr	r2, [sp, #4]
	ldr	r3, [sp]
	cmp	r2, r3
	bhi	.L11
	.loc 1 20 0
	ldr	r3, [sp, #4]
	b	.L12
.L11:
	.loc 1 22 0
	ldr	r3, [sp]
.L12:
	.loc 1 23 0
	mov	r0, r3
	add	sp, sp, #8
.LCFI3:
	@ sp needed
	bx	lr
.LFE1:
	.size	min, .-min
	.section	.text.max,"ax",%progbits
	.align	1
	.global	max
	.syntax unified
	.thumb
	.thumb_func
	.fpu fpv4-sp-d16
	.type	max, %function
max:
.LFB2:
	.loc 1 26 0
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	sp, sp, #8
.LCFI4:
	str	r0, [sp, #4]
	str	r1, [sp]
	.loc 1 27 0
	ldr	r2, [sp, #4]
	ldr	r3, [sp]
	cmp	r2, r3
	bcc	.L14
	.loc 1 28 0
	ldr	r3, [sp, #4]
	b	.L15
.L14:
	.loc 1 30 0
	ldr	r3, [sp]
.L15:
	.loc 1 31 0
	mov	r0, r3
	add	sp, sp, #8
.LCFI5:
	@ sp needed
	bx	lr
.LFE2:
	.size	max, .-max
	.section	.debug_frame,"",%progbits
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x3
	.ascii	"\000"
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0xe
	.byte	0xc
	.uleb128 0xd
	.uleb128 0
	.align	2
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x4
	.4byte	.LCFI0-.LFB0
	.byte	0xe
	.uleb128 0x10
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0xe
	.uleb128 0
	.align	2
.LEFDE0:
.LSFDE2:
	.4byte	.LEFDE2-.LASFDE2
.LASFDE2:
	.4byte	.Lframe0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.byte	0x4
	.4byte	.LCFI2-.LFB1
	.byte	0xe
	.uleb128 0x8
	.byte	0x4
	.4byte	.LCFI3-.LCFI2
	.byte	0xe
	.uleb128 0
	.align	2
.LEFDE2:
.LSFDE4:
	.4byte	.LEFDE4-.LASFDE4
.LASFDE4:
	.4byte	.Lframe0
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.byte	0x4
	.4byte	.LCFI4-.LFB2
	.byte	0xe
	.uleb128 0x8
	.byte	0x4
	.4byte	.LCFI5-.LCFI4
	.byte	0xe
	.uleb128 0
	.align	2
.LEFDE4:
	.text
.Letext0:
	.file 2 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 3.34/include/__crossworks.h"
	.file 3 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 3.34/include/stdint.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x62e
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF559
	.byte	0xc
	.4byte	.LASF560
	.4byte	.LASF561
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.4byte	.Ldebug_macro0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF469
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF470
	.uleb128 0x3
	.4byte	0x30
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF471
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF472
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x5
	.4byte	.LASF512
	.byte	0x3
	.byte	0x18
	.4byte	0x5c
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF473
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF474
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF475
	.uleb128 0x6
	.4byte	.LASF527
	.byte	0x8
	.byte	0x2
	.byte	0x5e
	.4byte	0x96
	.uleb128 0x7
	.4byte	.LASF476
	.byte	0x2
	.byte	0x5f
	.4byte	0x4a
	.byte	0
	.uleb128 0x7
	.4byte	.LASF477
	.byte	0x2
	.byte	0x60
	.4byte	0x96
	.byte	0x4
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF478
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0xb6
	.uleb128 0x9
	.4byte	0xb6
	.uleb128 0x9
	.4byte	0x5c
	.uleb128 0x9
	.4byte	0xc8
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0xbc
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF479
	.uleb128 0x3
	.4byte	0xbc
	.uleb128 0xa
	.byte	0x4
	.4byte	0x71
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0xec
	.uleb128 0x9
	.4byte	0xec
	.uleb128 0x9
	.4byte	0xf2
	.uleb128 0x9
	.4byte	0x5c
	.uleb128 0x9
	.4byte	0xc8
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x5c
	.uleb128 0xa
	.byte	0x4
	.4byte	0xc3
	.uleb128 0xb
	.byte	0x58
	.byte	0x2
	.byte	0x66
	.4byte	0x281
	.uleb128 0x7
	.4byte	.LASF480
	.byte	0x2
	.byte	0x68
	.4byte	0xf2
	.byte	0
	.uleb128 0x7
	.4byte	.LASF481
	.byte	0x2
	.byte	0x69
	.4byte	0xf2
	.byte	0x4
	.uleb128 0x7
	.4byte	.LASF482
	.byte	0x2
	.byte	0x6a
	.4byte	0xf2
	.byte	0x8
	.uleb128 0x7
	.4byte	.LASF483
	.byte	0x2
	.byte	0x6c
	.4byte	0xf2
	.byte	0xc
	.uleb128 0x7
	.4byte	.LASF484
	.byte	0x2
	.byte	0x6d
	.4byte	0xf2
	.byte	0x10
	.uleb128 0x7
	.4byte	.LASF485
	.byte	0x2
	.byte	0x6e
	.4byte	0xf2
	.byte	0x14
	.uleb128 0x7
	.4byte	.LASF486
	.byte	0x2
	.byte	0x6f
	.4byte	0xf2
	.byte	0x18
	.uleb128 0x7
	.4byte	.LASF487
	.byte	0x2
	.byte	0x70
	.4byte	0xf2
	.byte	0x1c
	.uleb128 0x7
	.4byte	.LASF488
	.byte	0x2
	.byte	0x71
	.4byte	0xf2
	.byte	0x20
	.uleb128 0x7
	.4byte	.LASF489
	.byte	0x2
	.byte	0x72
	.4byte	0xf2
	.byte	0x24
	.uleb128 0x7
	.4byte	.LASF490
	.byte	0x2
	.byte	0x74
	.4byte	0xbc
	.byte	0x28
	.uleb128 0x7
	.4byte	.LASF491
	.byte	0x2
	.byte	0x75
	.4byte	0xbc
	.byte	0x29
	.uleb128 0x7
	.4byte	.LASF492
	.byte	0x2
	.byte	0x76
	.4byte	0xbc
	.byte	0x2a
	.uleb128 0x7
	.4byte	.LASF493
	.byte	0x2
	.byte	0x77
	.4byte	0xbc
	.byte	0x2b
	.uleb128 0x7
	.4byte	.LASF494
	.byte	0x2
	.byte	0x78
	.4byte	0xbc
	.byte	0x2c
	.uleb128 0x7
	.4byte	.LASF495
	.byte	0x2
	.byte	0x79
	.4byte	0xbc
	.byte	0x2d
	.uleb128 0x7
	.4byte	.LASF496
	.byte	0x2
	.byte	0x7a
	.4byte	0xbc
	.byte	0x2e
	.uleb128 0x7
	.4byte	.LASF497
	.byte	0x2
	.byte	0x7b
	.4byte	0xbc
	.byte	0x2f
	.uleb128 0x7
	.4byte	.LASF498
	.byte	0x2
	.byte	0x7c
	.4byte	0xbc
	.byte	0x30
	.uleb128 0x7
	.4byte	.LASF499
	.byte	0x2
	.byte	0x7d
	.4byte	0xbc
	.byte	0x31
	.uleb128 0x7
	.4byte	.LASF500
	.byte	0x2
	.byte	0x7e
	.4byte	0xbc
	.byte	0x32
	.uleb128 0x7
	.4byte	.LASF501
	.byte	0x2
	.byte	0x7f
	.4byte	0xbc
	.byte	0x33
	.uleb128 0x7
	.4byte	.LASF502
	.byte	0x2
	.byte	0x80
	.4byte	0xbc
	.byte	0x34
	.uleb128 0x7
	.4byte	.LASF503
	.byte	0x2
	.byte	0x81
	.4byte	0xbc
	.byte	0x35
	.uleb128 0x7
	.4byte	.LASF504
	.byte	0x2
	.byte	0x86
	.4byte	0xf2
	.byte	0x38
	.uleb128 0x7
	.4byte	.LASF505
	.byte	0x2
	.byte	0x87
	.4byte	0xf2
	.byte	0x3c
	.uleb128 0x7
	.4byte	.LASF506
	.byte	0x2
	.byte	0x88
	.4byte	0xf2
	.byte	0x40
	.uleb128 0x7
	.4byte	.LASF507
	.byte	0x2
	.byte	0x89
	.4byte	0xf2
	.byte	0x44
	.uleb128 0x7
	.4byte	.LASF508
	.byte	0x2
	.byte	0x8a
	.4byte	0xf2
	.byte	0x48
	.uleb128 0x7
	.4byte	.LASF509
	.byte	0x2
	.byte	0x8b
	.4byte	0xf2
	.byte	0x4c
	.uleb128 0x7
	.4byte	.LASF510
	.byte	0x2
	.byte	0x8c
	.4byte	0xf2
	.byte	0x50
	.uleb128 0x7
	.4byte	.LASF511
	.byte	0x2
	.byte	0x8d
	.4byte	0xf2
	.byte	0x54
	.byte	0
	.uleb128 0x5
	.4byte	.LASF513
	.byte	0x2
	.byte	0x8e
	.4byte	0xf8
	.uleb128 0x3
	.4byte	0x281
	.uleb128 0xb
	.byte	0x20
	.byte	0x2
	.byte	0xa4
	.4byte	0x2fa
	.uleb128 0x7
	.4byte	.LASF514
	.byte	0x2
	.byte	0xa6
	.4byte	0x30e
	.byte	0
	.uleb128 0x7
	.4byte	.LASF515
	.byte	0x2
	.byte	0xa7
	.4byte	0x323
	.byte	0x4
	.uleb128 0x7
	.4byte	.LASF516
	.byte	0x2
	.byte	0xa8
	.4byte	0x323
	.byte	0x8
	.uleb128 0x7
	.4byte	.LASF517
	.byte	0x2
	.byte	0xab
	.4byte	0x33d
	.byte	0xc
	.uleb128 0x7
	.4byte	.LASF518
	.byte	0x2
	.byte	0xac
	.4byte	0x352
	.byte	0x10
	.uleb128 0x7
	.4byte	.LASF519
	.byte	0x2
	.byte	0xad
	.4byte	0x352
	.byte	0x14
	.uleb128 0x7
	.4byte	.LASF520
	.byte	0x2
	.byte	0xb0
	.4byte	0x358
	.byte	0x18
	.uleb128 0x7
	.4byte	.LASF521
	.byte	0x2
	.byte	0xb1
	.4byte	0x35e
	.byte	0x1c
	.byte	0
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0x30e
	.uleb128 0x9
	.4byte	0x4a
	.uleb128 0x9
	.4byte	0x4a
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x2fa
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0x323
	.uleb128 0x9
	.4byte	0x4a
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x314
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0x33d
	.uleb128 0x9
	.4byte	0x96
	.uleb128 0x9
	.4byte	0x4a
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x329
	.uleb128 0x8
	.4byte	0x96
	.4byte	0x352
	.uleb128 0x9
	.4byte	0x96
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x343
	.uleb128 0xa
	.byte	0x4
	.4byte	0x9d
	.uleb128 0xa
	.byte	0x4
	.4byte	0xce
	.uleb128 0x5
	.4byte	.LASF522
	.byte	0x2
	.byte	0xb2
	.4byte	0x291
	.uleb128 0x3
	.4byte	0x364
	.uleb128 0xb
	.byte	0xc
	.byte	0x2
	.byte	0xb4
	.4byte	0x3a1
	.uleb128 0x7
	.4byte	.LASF523
	.byte	0x2
	.byte	0xb5
	.4byte	0xf2
	.byte	0
	.uleb128 0x7
	.4byte	.LASF524
	.byte	0x2
	.byte	0xb6
	.4byte	0x3a1
	.byte	0x4
	.uleb128 0x7
	.4byte	.LASF525
	.byte	0x2
	.byte	0xb7
	.4byte	0x3a7
	.byte	0x8
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x28c
	.uleb128 0xa
	.byte	0x4
	.4byte	0x36f
	.uleb128 0x5
	.4byte	.LASF526
	.byte	0x2
	.byte	0xb8
	.4byte	0x374
	.uleb128 0x3
	.4byte	0x3ad
	.uleb128 0x6
	.4byte	.LASF528
	.byte	0x14
	.byte	0x2
	.byte	0xbc
	.4byte	0x3d6
	.uleb128 0x7
	.4byte	.LASF529
	.byte	0x2
	.byte	0xbd
	.4byte	0x3d6
	.byte	0
	.byte	0
	.uleb128 0xc
	.4byte	0x3ed
	.4byte	0x3e6
	.uleb128 0xd
	.4byte	0x3e6
	.byte	0x4
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF530
	.uleb128 0xa
	.byte	0x4
	.4byte	0x3b8
	.uleb128 0xe
	.4byte	.LASF531
	.byte	0x2
	.byte	0xe6
	.4byte	0x3bd
	.uleb128 0xe
	.4byte	.LASF532
	.byte	0x2
	.byte	0xed
	.4byte	0x3b8
	.uleb128 0xe
	.4byte	.LASF533
	.byte	0x2
	.byte	0xf0
	.4byte	0x36f
	.uleb128 0xe
	.4byte	.LASF534
	.byte	0x2
	.byte	0xf1
	.4byte	0x36f
	.uleb128 0xc
	.4byte	0x37
	.4byte	0x42f
	.uleb128 0xd
	.4byte	0x3e6
	.byte	0x7f
	.byte	0
	.uleb128 0x3
	.4byte	0x41f
	.uleb128 0xe
	.4byte	.LASF535
	.byte	0x2
	.byte	0xf3
	.4byte	0x42f
	.uleb128 0xc
	.4byte	0xc3
	.4byte	0x44a
	.uleb128 0xf
	.byte	0
	.uleb128 0x3
	.4byte	0x43f
	.uleb128 0xe
	.4byte	.LASF536
	.byte	0x2
	.byte	0xf5
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF537
	.byte	0x2
	.byte	0xf6
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF538
	.byte	0x2
	.byte	0xf7
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF539
	.byte	0x2
	.byte	0xf8
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF540
	.byte	0x2
	.byte	0xfa
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF541
	.byte	0x2
	.byte	0xfb
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF542
	.byte	0x2
	.byte	0xfc
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF543
	.byte	0x2
	.byte	0xfd
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF544
	.byte	0x2
	.byte	0xfe
	.4byte	0x44a
	.uleb128 0xe
	.4byte	.LASF545
	.byte	0x2
	.byte	0xff
	.4byte	0x44a
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0x4cc
	.uleb128 0x9
	.4byte	0x4cc
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x4d7
	.uleb128 0x10
	.4byte	.LASF562
	.uleb128 0x3
	.4byte	0x4d2
	.uleb128 0x11
	.4byte	.LASF546
	.byte	0x2
	.2byte	0x115
	.4byte	0x4e8
	.uleb128 0xa
	.byte	0x4
	.4byte	0x4bd
	.uleb128 0x8
	.4byte	0x4a
	.4byte	0x4fd
	.uleb128 0x9
	.4byte	0x4fd
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x4d2
	.uleb128 0x11
	.4byte	.LASF547
	.byte	0x2
	.2byte	0x116
	.4byte	0x50f
	.uleb128 0xa
	.byte	0x4
	.4byte	0x4ee
	.uleb128 0x12
	.4byte	.LASF548
	.byte	0x2
	.2byte	0x12d
	.4byte	0x521
	.uleb128 0xa
	.byte	0x4
	.4byte	0x527
	.uleb128 0x8
	.4byte	0xf2
	.4byte	0x536
	.uleb128 0x9
	.4byte	0x4a
	.byte	0
	.uleb128 0x13
	.4byte	.LASF549
	.byte	0x8
	.byte	0x2
	.2byte	0x12f
	.4byte	0x55e
	.uleb128 0x14
	.4byte	.LASF550
	.byte	0x2
	.2byte	0x131
	.4byte	0x515
	.byte	0
	.uleb128 0x14
	.4byte	.LASF551
	.byte	0x2
	.2byte	0x132
	.4byte	0x55e
	.byte	0x4
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.4byte	0x536
	.uleb128 0x12
	.4byte	.LASF552
	.byte	0x2
	.2byte	0x133
	.4byte	0x536
	.uleb128 0x11
	.4byte	.LASF553
	.byte	0x2
	.2byte	0x137
	.4byte	0x57c
	.uleb128 0xa
	.byte	0x4
	.4byte	0x564
	.uleb128 0x15
	.ascii	"max\000"
	.byte	0x1
	.byte	0x19
	.4byte	0x51
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x5b4
	.uleb128 0x16
	.ascii	"a\000"
	.byte	0x1
	.byte	0x19
	.4byte	0x51
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x16
	.ascii	"b\000"
	.byte	0x1
	.byte	0x19
	.4byte	0x51
	.uleb128 0x2
	.byte	0x91
	.sleb128 -8
	.byte	0
	.uleb128 0x15
	.ascii	"min\000"
	.byte	0x1
	.byte	0x11
	.4byte	0x51
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x5e6
	.uleb128 0x16
	.ascii	"a\000"
	.byte	0x1
	.byte	0x11
	.4byte	0x51
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x16
	.ascii	"b\000"
	.byte	0x1
	.byte	0x11
	.4byte	0x51
	.uleb128 0x2
	.byte	0x91
	.sleb128 -8
	.byte	0
	.uleb128 0x17
	.4byte	.LASF554
	.byte	0x1
	.byte	0x7
	.4byte	0x62a
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x62a
	.uleb128 0x18
	.4byte	.LASF555
	.byte	0x1
	.byte	0x7
	.4byte	0x62a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x18
	.4byte	.LASF556
	.byte	0x1
	.byte	0x7
	.4byte	0x62a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -8
	.uleb128 0x18
	.4byte	.LASF557
	.byte	0x1
	.byte	0x7
	.4byte	0x62a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.4byte	.LASF558
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.uleb128 0x2119
	.uleb128 0x17
	.uleb128 0x2134
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_pubnames,"",%progbits
	.4byte	0x3a
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x632
	.4byte	0x582
	.ascii	"max\000"
	.4byte	0x5b4
	.ascii	"min\000"
	.4byte	0x5e6
	.ascii	"check_lower_upper_range\000"
	.4byte	0
	.section	.debug_pubtypes,"",%progbits
	.4byte	0x18b
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x632
	.4byte	0x29
	.ascii	"signed char\000"
	.4byte	0x30
	.ascii	"unsigned char\000"
	.4byte	0x3c
	.ascii	"short int\000"
	.4byte	0x43
	.ascii	"short unsigned int\000"
	.4byte	0x4a
	.ascii	"int\000"
	.4byte	0x5c
	.ascii	"unsigned int\000"
	.4byte	0x51
	.ascii	"uint32_t\000"
	.4byte	0x63
	.ascii	"long long int\000"
	.4byte	0x6a
	.ascii	"long long unsigned int\000"
	.4byte	0x96
	.ascii	"long int\000"
	.4byte	0x71
	.ascii	"__mbstate_s\000"
	.4byte	0xbc
	.ascii	"char\000"
	.4byte	0x281
	.ascii	"__RAL_locale_data_t\000"
	.4byte	0x364
	.ascii	"__RAL_locale_codeset_t\000"
	.4byte	0x3ad
	.ascii	"__RAL_locale_t\000"
	.4byte	0x3e6
	.ascii	"sizetype\000"
	.4byte	0x3bd
	.ascii	"__locale_s\000"
	.4byte	0x515
	.ascii	"__RAL_error_decoder_fn_t\000"
	.4byte	0x536
	.ascii	"__RAL_error_decoder_s\000"
	.4byte	0x564
	.ascii	"__RAL_error_decoder_t\000"
	.4byte	0x62a
	.ascii	"float\000"
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LFB2
	.4byte	.LFE2
	.4byte	0
	.4byte	0
	.section	.debug_macro,"",%progbits
.Ldebug_macro0:
	.2byte	0x4
	.byte	0x2
	.4byte	.Ldebug_line0
	.byte	0x7
	.4byte	.Ldebug_macro1
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.file 4 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 3.34/include/stdbool.h"
	.byte	0x3
	.uleb128 0x1
	.uleb128 0x4
	.byte	0x7
	.4byte	.Ldebug_macro2
	.byte	0x4
	.byte	0x3
	.uleb128 0x2
	.uleb128 0x3
	.byte	0x7
	.4byte	.Ldebug_macro3
	.byte	0x4
	.file 5 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 3.34/include/string.h"
	.byte	0x3
	.uleb128 0x3
	.uleb128 0x5
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF445
	.byte	0x3
	.uleb128 0xf
	.uleb128 0x2
	.byte	0x7
	.4byte	.Ldebug_macro4
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro5
	.byte	0x4
	.file 6 "../../../drivers/include/min_max.h"
	.byte	0x3
	.uleb128 0x5
	.uleb128 0x6
	.byte	0x4
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.0.33c65a410bce284fc7a60ea790d88bbd,comdat
.Ldebug_macro1:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0
	.4byte	.LASF0
	.byte	0x5
	.uleb128 0
	.4byte	.LASF1
	.byte	0x5
	.uleb128 0
	.4byte	.LASF2
	.byte	0x5
	.uleb128 0
	.4byte	.LASF3
	.byte	0x5
	.uleb128 0
	.4byte	.LASF4
	.byte	0x5
	.uleb128 0
	.4byte	.LASF5
	.byte	0x5
	.uleb128 0
	.4byte	.LASF6
	.byte	0x5
	.uleb128 0
	.4byte	.LASF7
	.byte	0x5
	.uleb128 0
	.4byte	.LASF8
	.byte	0x5
	.uleb128 0
	.4byte	.LASF9
	.byte	0x5
	.uleb128 0
	.4byte	.LASF10
	.byte	0x5
	.uleb128 0
	.4byte	.LASF11
	.byte	0x5
	.uleb128 0
	.4byte	.LASF12
	.byte	0x5
	.uleb128 0
	.4byte	.LASF13
	.byte	0x5
	.uleb128 0
	.4byte	.LASF14
	.byte	0x5
	.uleb128 0
	.4byte	.LASF15
	.byte	0x5
	.uleb128 0
	.4byte	.LASF16
	.byte	0x5
	.uleb128 0
	.4byte	.LASF17
	.byte	0x5
	.uleb128 0
	.4byte	.LASF18
	.byte	0x5
	.uleb128 0
	.4byte	.LASF19
	.byte	0x5
	.uleb128 0
	.4byte	.LASF20
	.byte	0x5
	.uleb128 0
	.4byte	.LASF21
	.byte	0x5
	.uleb128 0
	.4byte	.LASF22
	.byte	0x5
	.uleb128 0
	.4byte	.LASF23
	.byte	0x5
	.uleb128 0
	.4byte	.LASF24
	.byte	0x5
	.uleb128 0
	.4byte	.LASF25
	.byte	0x5
	.uleb128 0
	.4byte	.LASF26
	.byte	0x5
	.uleb128 0
	.4byte	.LASF27
	.byte	0x5
	.uleb128 0
	.4byte	.LASF28
	.byte	0x5
	.uleb128 0
	.4byte	.LASF29
	.byte	0x5
	.uleb128 0
	.4byte	.LASF30
	.byte	0x5
	.uleb128 0
	.4byte	.LASF31
	.byte	0x5
	.uleb128 0
	.4byte	.LASF32
	.byte	0x5
	.uleb128 0
	.4byte	.LASF33
	.byte	0x5
	.uleb128 0
	.4byte	.LASF34
	.byte	0x5
	.uleb128 0
	.4byte	.LASF35
	.byte	0x5
	.uleb128 0
	.4byte	.LASF36
	.byte	0x5
	.uleb128 0
	.4byte	.LASF37
	.byte	0x5
	.uleb128 0
	.4byte	.LASF38
	.byte	0x5
	.uleb128 0
	.4byte	.LASF39
	.byte	0x5
	.uleb128 0
	.4byte	.LASF40
	.byte	0x5
	.uleb128 0
	.4byte	.LASF41
	.byte	0x5
	.uleb128 0
	.4byte	.LASF42
	.byte	0x5
	.uleb128 0
	.4byte	.LASF43
	.byte	0x5
	.uleb128 0
	.4byte	.LASF44
	.byte	0x5
	.uleb128 0
	.4byte	.LASF45
	.byte	0x5
	.uleb128 0
	.4byte	.LASF46
	.byte	0x5
	.uleb128 0
	.4byte	.LASF47
	.byte	0x5
	.uleb128 0
	.4byte	.LASF48
	.byte	0x5
	.uleb128 0
	.4byte	.LASF49
	.byte	0x5
	.uleb128 0
	.4byte	.LASF50
	.byte	0x5
	.uleb128 0
	.4byte	.LASF51
	.byte	0x5
	.uleb128 0
	.4byte	.LASF52
	.byte	0x5
	.uleb128 0
	.4byte	.LASF53
	.byte	0x5
	.uleb128 0
	.4byte	.LASF54
	.byte	0x5
	.uleb128 0
	.4byte	.LASF55
	.byte	0x5
	.uleb128 0
	.4byte	.LASF56
	.byte	0x5
	.uleb128 0
	.4byte	.LASF57
	.byte	0x5
	.uleb128 0
	.4byte	.LASF58
	.byte	0x5
	.uleb128 0
	.4byte	.LASF59
	.byte	0x5
	.uleb128 0
	.4byte	.LASF60
	.byte	0x5
	.uleb128 0
	.4byte	.LASF61
	.byte	0x5
	.uleb128 0
	.4byte	.LASF62
	.byte	0x5
	.uleb128 0
	.4byte	.LASF63
	.byte	0x5
	.uleb128 0
	.4byte	.LASF64
	.byte	0x5
	.uleb128 0
	.4byte	.LASF65
	.byte	0x5
	.uleb128 0
	.4byte	.LASF66
	.byte	0x5
	.uleb128 0
	.4byte	.LASF67
	.byte	0x5
	.uleb128 0
	.4byte	.LASF68
	.byte	0x5
	.uleb128 0
	.4byte	.LASF69
	.byte	0x5
	.uleb128 0
	.4byte	.LASF70
	.byte	0x5
	.uleb128 0
	.4byte	.LASF71
	.byte	0x5
	.uleb128 0
	.4byte	.LASF72
	.byte	0x5
	.uleb128 0
	.4byte	.LASF73
	.byte	0x5
	.uleb128 0
	.4byte	.LASF74
	.byte	0x5
	.uleb128 0
	.4byte	.LASF75
	.byte	0x5
	.uleb128 0
	.4byte	.LASF76
	.byte	0x5
	.uleb128 0
	.4byte	.LASF77
	.byte	0x5
	.uleb128 0
	.4byte	.LASF78
	.byte	0x5
	.uleb128 0
	.4byte	.LASF79
	.byte	0x5
	.uleb128 0
	.4byte	.LASF80
	.byte	0x5
	.uleb128 0
	.4byte	.LASF81
	.byte	0x5
	.uleb128 0
	.4byte	.LASF82
	.byte	0x5
	.uleb128 0
	.4byte	.LASF83
	.byte	0x5
	.uleb128 0
	.4byte	.LASF84
	.byte	0x5
	.uleb128 0
	.4byte	.LASF85
	.byte	0x5
	.uleb128 0
	.4byte	.LASF86
	.byte	0x5
	.uleb128 0
	.4byte	.LASF87
	.byte	0x5
	.uleb128 0
	.4byte	.LASF88
	.byte	0x5
	.uleb128 0
	.4byte	.LASF89
	.byte	0x5
	.uleb128 0
	.4byte	.LASF90
	.byte	0x5
	.uleb128 0
	.4byte	.LASF91
	.byte	0x5
	.uleb128 0
	.4byte	.LASF92
	.byte	0x5
	.uleb128 0
	.4byte	.LASF93
	.byte	0x5
	.uleb128 0
	.4byte	.LASF94
	.byte	0x5
	.uleb128 0
	.4byte	.LASF95
	.byte	0x5
	.uleb128 0
	.4byte	.LASF96
	.byte	0x5
	.uleb128 0
	.4byte	.LASF97
	.byte	0x5
	.uleb128 0
	.4byte	.LASF98
	.byte	0x5
	.uleb128 0
	.4byte	.LASF99
	.byte	0x5
	.uleb128 0
	.4byte	.LASF100
	.byte	0x5
	.uleb128 0
	.4byte	.LASF101
	.byte	0x5
	.uleb128 0
	.4byte	.LASF102
	.byte	0x5
	.uleb128 0
	.4byte	.LASF103
	.byte	0x5
	.uleb128 0
	.4byte	.LASF104
	.byte	0x5
	.uleb128 0
	.4byte	.LASF105
	.byte	0x5
	.uleb128 0
	.4byte	.LASF106
	.byte	0x5
	.uleb128 0
	.4byte	.LASF107
	.byte	0x5
	.uleb128 0
	.4byte	.LASF108
	.byte	0x5
	.uleb128 0
	.4byte	.LASF109
	.byte	0x5
	.uleb128 0
	.4byte	.LASF110
	.byte	0x5
	.uleb128 0
	.4byte	.LASF111
	.byte	0x5
	.uleb128 0
	.4byte	.LASF112
	.byte	0x5
	.uleb128 0
	.4byte	.LASF113
	.byte	0x5
	.uleb128 0
	.4byte	.LASF114
	.byte	0x5
	.uleb128 0
	.4byte	.LASF115
	.byte	0x5
	.uleb128 0
	.4byte	.LASF116
	.byte	0x5
	.uleb128 0
	.4byte	.LASF117
	.byte	0x5
	.uleb128 0
	.4byte	.LASF118
	.byte	0x5
	.uleb128 0
	.4byte	.LASF119
	.byte	0x5
	.uleb128 0
	.4byte	.LASF120
	.byte	0x5
	.uleb128 0
	.4byte	.LASF121
	.byte	0x5
	.uleb128 0
	.4byte	.LASF122
	.byte	0x5
	.uleb128 0
	.4byte	.LASF123
	.byte	0x5
	.uleb128 0
	.4byte	.LASF124
	.byte	0x5
	.uleb128 0
	.4byte	.LASF125
	.byte	0x5
	.uleb128 0
	.4byte	.LASF126
	.byte	0x5
	.uleb128 0
	.4byte	.LASF127
	.byte	0x5
	.uleb128 0
	.4byte	.LASF128
	.byte	0x5
	.uleb128 0
	.4byte	.LASF129
	.byte	0x5
	.uleb128 0
	.4byte	.LASF130
	.byte	0x5
	.uleb128 0
	.4byte	.LASF131
	.byte	0x5
	.uleb128 0
	.4byte	.LASF132
	.byte	0x5
	.uleb128 0
	.4byte	.LASF133
	.byte	0x5
	.uleb128 0
	.4byte	.LASF134
	.byte	0x5
	.uleb128 0
	.4byte	.LASF135
	.byte	0x5
	.uleb128 0
	.4byte	.LASF136
	.byte	0x5
	.uleb128 0
	.4byte	.LASF137
	.byte	0x5
	.uleb128 0
	.4byte	.LASF138
	.byte	0x5
	.uleb128 0
	.4byte	.LASF139
	.byte	0x5
	.uleb128 0
	.4byte	.LASF140
	.byte	0x5
	.uleb128 0
	.4byte	.LASF141
	.byte	0x5
	.uleb128 0
	.4byte	.LASF142
	.byte	0x5
	.uleb128 0
	.4byte	.LASF143
	.byte	0x5
	.uleb128 0
	.4byte	.LASF144
	.byte	0x5
	.uleb128 0
	.4byte	.LASF145
	.byte	0x5
	.uleb128 0
	.4byte	.LASF146
	.byte	0x5
	.uleb128 0
	.4byte	.LASF147
	.byte	0x5
	.uleb128 0
	.4byte	.LASF148
	.byte	0x5
	.uleb128 0
	.4byte	.LASF149
	.byte	0x5
	.uleb128 0
	.4byte	.LASF150
	.byte	0x5
	.uleb128 0
	.4byte	.LASF151
	.byte	0x5
	.uleb128 0
	.4byte	.LASF152
	.byte	0x5
	.uleb128 0
	.4byte	.LASF153
	.byte	0x5
	.uleb128 0
	.4byte	.LASF154
	.byte	0x5
	.uleb128 0
	.4byte	.LASF155
	.byte	0x5
	.uleb128 0
	.4byte	.LASF156
	.byte	0x5
	.uleb128 0
	.4byte	.LASF157
	.byte	0x5
	.uleb128 0
	.4byte	.LASF158
	.byte	0x5
	.uleb128 0
	.4byte	.LASF159
	.byte	0x5
	.uleb128 0
	.4byte	.LASF160
	.byte	0x5
	.uleb128 0
	.4byte	.LASF161
	.byte	0x5
	.uleb128 0
	.4byte	.LASF162
	.byte	0x5
	.uleb128 0
	.4byte	.LASF163
	.byte	0x5
	.uleb128 0
	.4byte	.LASF164
	.byte	0x5
	.uleb128 0
	.4byte	.LASF165
	.byte	0x5
	.uleb128 0
	.4byte	.LASF166
	.byte	0x5
	.uleb128 0
	.4byte	.LASF167
	.byte	0x5
	.uleb128 0
	.4byte	.LASF168
	.byte	0x5
	.uleb128 0
	.4byte	.LASF169
	.byte	0x5
	.uleb128 0
	.4byte	.LASF170
	.byte	0x5
	.uleb128 0
	.4byte	.LASF171
	.byte	0x5
	.uleb128 0
	.4byte	.LASF172
	.byte	0x5
	.uleb128 0
	.4byte	.LASF173
	.byte	0x5
	.uleb128 0
	.4byte	.LASF174
	.byte	0x5
	.uleb128 0
	.4byte	.LASF175
	.byte	0x5
	.uleb128 0
	.4byte	.LASF176
	.byte	0x5
	.uleb128 0
	.4byte	.LASF177
	.byte	0x5
	.uleb128 0
	.4byte	.LASF178
	.byte	0x5
	.uleb128 0
	.4byte	.LASF179
	.byte	0x5
	.uleb128 0
	.4byte	.LASF180
	.byte	0x5
	.uleb128 0
	.4byte	.LASF181
	.byte	0x5
	.uleb128 0
	.4byte	.LASF182
	.byte	0x5
	.uleb128 0
	.4byte	.LASF183
	.byte	0x5
	.uleb128 0
	.4byte	.LASF184
	.byte	0x5
	.uleb128 0
	.4byte	.LASF185
	.byte	0x5
	.uleb128 0
	.4byte	.LASF186
	.byte	0x5
	.uleb128 0
	.4byte	.LASF187
	.byte	0x5
	.uleb128 0
	.4byte	.LASF188
	.byte	0x5
	.uleb128 0
	.4byte	.LASF189
	.byte	0x5
	.uleb128 0
	.4byte	.LASF190
	.byte	0x5
	.uleb128 0
	.4byte	.LASF191
	.byte	0x5
	.uleb128 0
	.4byte	.LASF192
	.byte	0x5
	.uleb128 0
	.4byte	.LASF193
	.byte	0x5
	.uleb128 0
	.4byte	.LASF194
	.byte	0x5
	.uleb128 0
	.4byte	.LASF195
	.byte	0x5
	.uleb128 0
	.4byte	.LASF196
	.byte	0x5
	.uleb128 0
	.4byte	.LASF197
	.byte	0x5
	.uleb128 0
	.4byte	.LASF198
	.byte	0x5
	.uleb128 0
	.4byte	.LASF199
	.byte	0x5
	.uleb128 0
	.4byte	.LASF200
	.byte	0x5
	.uleb128 0
	.4byte	.LASF201
	.byte	0x5
	.uleb128 0
	.4byte	.LASF202
	.byte	0x5
	.uleb128 0
	.4byte	.LASF203
	.byte	0x5
	.uleb128 0
	.4byte	.LASF204
	.byte	0x5
	.uleb128 0
	.4byte	.LASF205
	.byte	0x5
	.uleb128 0
	.4byte	.LASF206
	.byte	0x5
	.uleb128 0
	.4byte	.LASF207
	.byte	0x5
	.uleb128 0
	.4byte	.LASF208
	.byte	0x5
	.uleb128 0
	.4byte	.LASF209
	.byte	0x5
	.uleb128 0
	.4byte	.LASF210
	.byte	0x5
	.uleb128 0
	.4byte	.LASF211
	.byte	0x5
	.uleb128 0
	.4byte	.LASF212
	.byte	0x5
	.uleb128 0
	.4byte	.LASF213
	.byte	0x5
	.uleb128 0
	.4byte	.LASF214
	.byte	0x5
	.uleb128 0
	.4byte	.LASF215
	.byte	0x5
	.uleb128 0
	.4byte	.LASF216
	.byte	0x5
	.uleb128 0
	.4byte	.LASF217
	.byte	0x5
	.uleb128 0
	.4byte	.LASF218
	.byte	0x5
	.uleb128 0
	.4byte	.LASF219
	.byte	0x5
	.uleb128 0
	.4byte	.LASF220
	.byte	0x5
	.uleb128 0
	.4byte	.LASF221
	.byte	0x5
	.uleb128 0
	.4byte	.LASF222
	.byte	0x5
	.uleb128 0
	.4byte	.LASF223
	.byte	0x5
	.uleb128 0
	.4byte	.LASF224
	.byte	0x5
	.uleb128 0
	.4byte	.LASF225
	.byte	0x5
	.uleb128 0
	.4byte	.LASF226
	.byte	0x5
	.uleb128 0
	.4byte	.LASF227
	.byte	0x5
	.uleb128 0
	.4byte	.LASF228
	.byte	0x5
	.uleb128 0
	.4byte	.LASF229
	.byte	0x5
	.uleb128 0
	.4byte	.LASF230
	.byte	0x5
	.uleb128 0
	.4byte	.LASF231
	.byte	0x5
	.uleb128 0
	.4byte	.LASF232
	.byte	0x5
	.uleb128 0
	.4byte	.LASF233
	.byte	0x5
	.uleb128 0
	.4byte	.LASF234
	.byte	0x5
	.uleb128 0
	.4byte	.LASF235
	.byte	0x5
	.uleb128 0
	.4byte	.LASF236
	.byte	0x5
	.uleb128 0
	.4byte	.LASF237
	.byte	0x5
	.uleb128 0
	.4byte	.LASF238
	.byte	0x5
	.uleb128 0
	.4byte	.LASF239
	.byte	0x5
	.uleb128 0
	.4byte	.LASF240
	.byte	0x5
	.uleb128 0
	.4byte	.LASF241
	.byte	0x5
	.uleb128 0
	.4byte	.LASF242
	.byte	0x5
	.uleb128 0
	.4byte	.LASF243
	.byte	0x5
	.uleb128 0
	.4byte	.LASF244
	.byte	0x5
	.uleb128 0
	.4byte	.LASF245
	.byte	0x5
	.uleb128 0
	.4byte	.LASF246
	.byte	0x5
	.uleb128 0
	.4byte	.LASF247
	.byte	0x5
	.uleb128 0
	.4byte	.LASF248
	.byte	0x5
	.uleb128 0
	.4byte	.LASF249
	.byte	0x5
	.uleb128 0
	.4byte	.LASF250
	.byte	0x5
	.uleb128 0
	.4byte	.LASF251
	.byte	0x5
	.uleb128 0
	.4byte	.LASF252
	.byte	0x5
	.uleb128 0
	.4byte	.LASF253
	.byte	0x5
	.uleb128 0
	.4byte	.LASF254
	.byte	0x5
	.uleb128 0
	.4byte	.LASF255
	.byte	0x5
	.uleb128 0
	.4byte	.LASF256
	.byte	0x5
	.uleb128 0
	.4byte	.LASF257
	.byte	0x5
	.uleb128 0
	.4byte	.LASF258
	.byte	0x5
	.uleb128 0
	.4byte	.LASF259
	.byte	0x5
	.uleb128 0
	.4byte	.LASF260
	.byte	0x5
	.uleb128 0
	.4byte	.LASF261
	.byte	0x5
	.uleb128 0
	.4byte	.LASF262
	.byte	0x5
	.uleb128 0
	.4byte	.LASF263
	.byte	0x5
	.uleb128 0
	.4byte	.LASF264
	.byte	0x5
	.uleb128 0
	.4byte	.LASF265
	.byte	0x5
	.uleb128 0
	.4byte	.LASF266
	.byte	0x5
	.uleb128 0
	.4byte	.LASF267
	.byte	0x5
	.uleb128 0
	.4byte	.LASF268
	.byte	0x5
	.uleb128 0
	.4byte	.LASF269
	.byte	0x5
	.uleb128 0
	.4byte	.LASF270
	.byte	0x5
	.uleb128 0
	.4byte	.LASF271
	.byte	0x5
	.uleb128 0
	.4byte	.LASF272
	.byte	0x5
	.uleb128 0
	.4byte	.LASF273
	.byte	0x5
	.uleb128 0
	.4byte	.LASF274
	.byte	0x5
	.uleb128 0
	.4byte	.LASF275
	.byte	0x5
	.uleb128 0
	.4byte	.LASF276
	.byte	0x5
	.uleb128 0
	.4byte	.LASF277
	.byte	0x5
	.uleb128 0
	.4byte	.LASF278
	.byte	0x5
	.uleb128 0
	.4byte	.LASF279
	.byte	0x5
	.uleb128 0
	.4byte	.LASF280
	.byte	0x5
	.uleb128 0
	.4byte	.LASF281
	.byte	0x5
	.uleb128 0
	.4byte	.LASF282
	.byte	0x5
	.uleb128 0
	.4byte	.LASF283
	.byte	0x5
	.uleb128 0
	.4byte	.LASF284
	.byte	0x5
	.uleb128 0
	.4byte	.LASF285
	.byte	0x5
	.uleb128 0
	.4byte	.LASF286
	.byte	0x5
	.uleb128 0
	.4byte	.LASF287
	.byte	0x5
	.uleb128 0
	.4byte	.LASF288
	.byte	0x5
	.uleb128 0
	.4byte	.LASF289
	.byte	0x5
	.uleb128 0
	.4byte	.LASF290
	.byte	0x5
	.uleb128 0
	.4byte	.LASF291
	.byte	0x5
	.uleb128 0
	.4byte	.LASF292
	.byte	0x5
	.uleb128 0
	.4byte	.LASF293
	.byte	0x5
	.uleb128 0
	.4byte	.LASF294
	.byte	0x5
	.uleb128 0
	.4byte	.LASF295
	.byte	0x5
	.uleb128 0
	.4byte	.LASF296
	.byte	0x5
	.uleb128 0
	.4byte	.LASF297
	.byte	0x5
	.uleb128 0
	.4byte	.LASF298
	.byte	0x5
	.uleb128 0
	.4byte	.LASF299
	.byte	0x5
	.uleb128 0
	.4byte	.LASF300
	.byte	0x5
	.uleb128 0
	.4byte	.LASF301
	.byte	0x5
	.uleb128 0
	.4byte	.LASF302
	.byte	0x5
	.uleb128 0
	.4byte	.LASF303
	.byte	0x5
	.uleb128 0
	.4byte	.LASF304
	.byte	0x5
	.uleb128 0
	.4byte	.LASF305
	.byte	0x5
	.uleb128 0
	.4byte	.LASF306
	.byte	0x5
	.uleb128 0
	.4byte	.LASF307
	.byte	0x5
	.uleb128 0
	.4byte	.LASF308
	.byte	0x5
	.uleb128 0
	.4byte	.LASF309
	.byte	0x5
	.uleb128 0
	.4byte	.LASF310
	.byte	0x5
	.uleb128 0
	.4byte	.LASF311
	.byte	0x5
	.uleb128 0
	.4byte	.LASF312
	.byte	0x5
	.uleb128 0
	.4byte	.LASF313
	.byte	0x5
	.uleb128 0
	.4byte	.LASF314
	.byte	0x5
	.uleb128 0
	.4byte	.LASF315
	.byte	0x5
	.uleb128 0
	.4byte	.LASF316
	.byte	0x5
	.uleb128 0
	.4byte	.LASF317
	.byte	0x5
	.uleb128 0
	.4byte	.LASF318
	.byte	0x5
	.uleb128 0
	.4byte	.LASF319
	.byte	0x5
	.uleb128 0
	.4byte	.LASF320
	.byte	0x5
	.uleb128 0
	.4byte	.LASF321
	.byte	0x5
	.uleb128 0
	.4byte	.LASF322
	.byte	0x5
	.uleb128 0
	.4byte	.LASF323
	.byte	0x5
	.uleb128 0
	.4byte	.LASF324
	.byte	0x5
	.uleb128 0
	.4byte	.LASF325
	.byte	0x5
	.uleb128 0
	.4byte	.LASF326
	.byte	0x5
	.uleb128 0
	.4byte	.LASF327
	.byte	0x5
	.uleb128 0
	.4byte	.LASF328
	.byte	0x5
	.uleb128 0
	.4byte	.LASF329
	.byte	0x5
	.uleb128 0
	.4byte	.LASF330
	.byte	0x5
	.uleb128 0
	.4byte	.LASF331
	.byte	0x6
	.uleb128 0
	.4byte	.LASF332
	.byte	0x5
	.uleb128 0
	.4byte	.LASF333
	.byte	0x6
	.uleb128 0
	.4byte	.LASF334
	.byte	0x5
	.uleb128 0
	.4byte	.LASF335
	.byte	0x5
	.uleb128 0
	.4byte	.LASF336
	.byte	0x5
	.uleb128 0
	.4byte	.LASF337
	.byte	0x5
	.uleb128 0
	.4byte	.LASF338
	.byte	0x5
	.uleb128 0
	.4byte	.LASF339
	.byte	0x5
	.uleb128 0
	.4byte	.LASF340
	.byte	0x5
	.uleb128 0
	.4byte	.LASF341
	.byte	0x5
	.uleb128 0
	.4byte	.LASF342
	.byte	0x5
	.uleb128 0
	.4byte	.LASF343
	.byte	0x5
	.uleb128 0
	.4byte	.LASF344
	.byte	0x5
	.uleb128 0
	.4byte	.LASF345
	.byte	0x5
	.uleb128 0
	.4byte	.LASF346
	.byte	0x5
	.uleb128 0
	.4byte	.LASF347
	.byte	0x5
	.uleb128 0
	.4byte	.LASF348
	.byte	0x5
	.uleb128 0
	.4byte	.LASF349
	.byte	0x5
	.uleb128 0
	.4byte	.LASF350
	.byte	0x5
	.uleb128 0
	.4byte	.LASF351
	.byte	0x5
	.uleb128 0
	.4byte	.LASF352
	.byte	0x6
	.uleb128 0
	.4byte	.LASF353
	.byte	0x6
	.uleb128 0
	.4byte	.LASF354
	.byte	0x6
	.uleb128 0
	.4byte	.LASF355
	.byte	0x5
	.uleb128 0
	.4byte	.LASF356
	.byte	0x5
	.uleb128 0
	.4byte	.LASF357
	.byte	0x5
	.uleb128 0
	.4byte	.LASF358
	.byte	0x5
	.uleb128 0
	.4byte	.LASF359
	.byte	0x5
	.uleb128 0
	.4byte	.LASF360
	.byte	0x5
	.uleb128 0
	.4byte	.LASF361
	.byte	0x5
	.uleb128 0
	.4byte	.LASF362
	.byte	0x5
	.uleb128 0
	.4byte	.LASF363
	.byte	0x5
	.uleb128 0
	.4byte	.LASF364
	.byte	0x5
	.uleb128 0
	.4byte	.LASF365
	.byte	0x5
	.uleb128 0
	.4byte	.LASF366
	.byte	0x5
	.uleb128 0
	.4byte	.LASF357
	.byte	0x5
	.uleb128 0
	.4byte	.LASF367
	.byte	0x5
	.uleb128 0
	.4byte	.LASF368
	.byte	0x5
	.uleb128 0
	.4byte	.LASF369
	.byte	0x5
	.uleb128 0
	.4byte	.LASF370
	.byte	0x5
	.uleb128 0
	.4byte	.LASF371
	.byte	0x5
	.uleb128 0
	.4byte	.LASF372
	.byte	0x5
	.uleb128 0
	.4byte	.LASF373
	.byte	0x5
	.uleb128 0
	.4byte	.LASF374
	.byte	0x5
	.uleb128 0
	.4byte	.LASF375
	.byte	0x5
	.uleb128 0
	.4byte	.LASF376
	.byte	0x5
	.uleb128 0
	.4byte	.LASF377
	.byte	0x5
	.uleb128 0
	.4byte	.LASF378
	.byte	0x5
	.uleb128 0
	.4byte	.LASF379
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stdbool.h.13.50a67290410591540d9a89d27de1d2f2,comdat
.Ldebug_macro2:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF380
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF381
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF382
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF383
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF384
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.stdint.h.13.e7ff37f6f039a2e2d3a3b754131cfc10,comdat
.Ldebug_macro3:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF385
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF386
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF387
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF388
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF389
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF390
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF391
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF392
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF393
	.byte	0x5
	.uleb128 0x65
	.4byte	.LASF394
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF395
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF396
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF397
	.byte	0x5
	.uleb128 0x6b
	.4byte	.LASF398
	.byte	0x5
	.uleb128 0x6c
	.4byte	.LASF399
	.byte	0x5
	.uleb128 0x6d
	.4byte	.LASF400
	.byte	0x5
	.uleb128 0x70
	.4byte	.LASF401
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF402
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF403
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF404
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF405
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF406
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF407
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF408
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF409
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF410
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF411
	.byte	0x5
	.uleb128 0x7b
	.4byte	.LASF412
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF413
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF414
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF415
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF416
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF417
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF418
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF419
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF420
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF421
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF422
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF423
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF424
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF425
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF426
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF427
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF428
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF429
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF430
	.byte	0x5
	.uleb128 0xa3
	.4byte	.LASF431
	.byte	0x5
	.uleb128 0xa4
	.4byte	.LASF432
	.byte	0x5
	.uleb128 0xa5
	.4byte	.LASF433
	.byte	0x5
	.uleb128 0xa6
	.4byte	.LASF434
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF435
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF436
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF437
	.byte	0x5
	.uleb128 0xaa
	.4byte	.LASF438
	.byte	0x5
	.uleb128 0xac
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0xad
	.4byte	.LASF440
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF441
	.byte	0x5
	.uleb128 0xb8
	.4byte	.LASF442
	.byte	0x5
	.uleb128 0xbc
	.4byte	.LASF443
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF444
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.__crossworks.h.13.c3cdfeca0c65bfeeeafcbc919abafa26,comdat
.Ldebug_macro4:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF446
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF447
	.byte	0x6
	.uleb128 0x23
	.4byte	.LASF448
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF449
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF450
	.byte	0x5
	.uleb128 0x2b
	.4byte	.LASF451
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF452
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF447
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF453
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF454
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF455
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF456
	.byte	0x5
	.uleb128 0x4d
	.4byte	.LASF457
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF458
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF459
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF460
	.byte	0x5
	.uleb128 0x53
	.4byte	.LASF461
	.byte	0x5
	.uleb128 0x54
	.4byte	.LASF462
	.byte	0x5
	.uleb128 0x55
	.4byte	.LASF463
	.byte	0x5
	.uleb128 0x56
	.4byte	.LASF464
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF465
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF466
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.string.h.22.cda10d8e370d892a37152512dd464b42,comdat
.Ldebug_macro5:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF467
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF468
	.byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF85:
	.ascii	"__SIG_ATOMIC_MAX__ 0x7fffffff\000"
.LASF64:
	.ascii	"__UINT_FAST64_TYPE__ long long unsigned int\000"
.LASF182:
	.ascii	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD\000"
.LASF147:
	.ascii	"__DBL_DECIMAL_DIG__ 17\000"
.LASF398:
	.ascii	"INTMAX_MIN (-9223372036854775807LL-1)\000"
.LASF61:
	.ascii	"__UINT_FAST8_TYPE__ unsigned int\000"
.LASF301:
	.ascii	"__USA_IBIT__ 16\000"
.LASF379:
	.ascii	"MPU9250 1\000"
.LASF323:
	.ascii	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1\000"
.LASF433:
	.ascii	"INT16_C(x) (x)\000"
.LASF181:
	.ascii	"__DEC64_EPSILON__ 1E-15DD\000"
.LASF259:
	.ascii	"__ULACCUM_EPSILON__ 0x1P-32ULK\000"
.LASF376:
	.ascii	"SWI_DISABLE0 1\000"
.LASF479:
	.ascii	"char\000"
.LASF104:
	.ascii	"__UINT8_C(c) c\000"
.LASF353:
	.ascii	"__ARM_NEON__\000"
.LASF466:
	.ascii	"__MAX_CATEGORY 5\000"
.LASF271:
	.ascii	"__QQ_IBIT__ 0\000"
.LASF287:
	.ascii	"__UDQ_IBIT__ 0\000"
.LASF327:
	.ascii	"__SIZEOF_WINT_T__ 4\000"
.LASF143:
	.ascii	"__DBL_MIN_EXP__ (-1021)\000"
.LASF421:
	.ascii	"UINT_FAST8_MAX UINT8_MAX\000"
.LASF68:
	.ascii	"__has_include_next(STR) __has_include_next__(STR)\000"
.LASF340:
	.ascii	"__ARM_SIZEOF_WCHAR_T 4\000"
.LASF221:
	.ascii	"__LLFRACT_IBIT__ 0\000"
.LASF197:
	.ascii	"__USFRACT_MIN__ 0.0UHR\000"
.LASF6:
	.ascii	"__GNUC_MINOR__ 3\000"
.LASF362:
	.ascii	"__ARM_ASM_SYNTAX_UNIFIED__ 1\000"
.LASF411:
	.ascii	"UINT_LEAST32_MAX UINT32_MAX\000"
.LASF473:
	.ascii	"unsigned int\000"
.LASF551:
	.ascii	"next\000"
.LASF332:
	.ascii	"__ARM_FEATURE_CRYPTO\000"
.LASF106:
	.ascii	"__UINT16_C(c) c\000"
.LASF23:
	.ascii	"__SIZEOF_SIZE_T__ 4\000"
.LASF38:
	.ascii	"__CHAR16_TYPE__ short unsigned int\000"
.LASF22:
	.ascii	"__SIZEOF_LONG_DOUBLE__ 8\000"
.LASF133:
	.ascii	"__FLT_MAX__ 1.1\000"
.LASF111:
	.ascii	"__INT_FAST8_MAX__ 0x7fffffff\000"
.LASF507:
	.ascii	"abbrev_month_names\000"
.LASF228:
	.ascii	"__ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR\000"
.LASF186:
	.ascii	"__DEC128_MIN__ 1E-6143DL\000"
.LASF329:
	.ascii	"__ARM_FEATURE_DSP 1\000"
.LASF304:
	.ascii	"__UTA_FBIT__ 64\000"
.LASF141:
	.ascii	"__DBL_MANT_DIG__ 53\000"
.LASF56:
	.ascii	"__UINT_LEAST64_TYPE__ long long unsigned int\000"
.LASF72:
	.ascii	"__INT_MAX__ 0x7fffffff\000"
.LASF12:
	.ascii	"__ATOMIC_RELEASE 3\000"
.LASF33:
	.ascii	"__PTRDIFF_TYPE__ int\000"
.LASF310:
	.ascii	"__CHAR_UNSIGNED__ 1\000"
.LASF42:
	.ascii	"__INT16_TYPE__ short int\000"
.LASF334:
	.ascii	"__ARM_FEATURE_QRDMX\000"
.LASF174:
	.ascii	"__DEC32_EPSILON__ 1E-6DF\000"
.LASF156:
	.ascii	"__LDBL_DIG__ 15\000"
.LASF17:
	.ascii	"__SIZEOF_LONG__ 4\000"
.LASF409:
	.ascii	"UINT_LEAST8_MAX UINT8_MAX\000"
.LASF261:
	.ascii	"__LLACCUM_IBIT__ 32\000"
.LASF10:
	.ascii	"__ATOMIC_SEQ_CST 5\000"
.LASF501:
	.ascii	"int_n_sep_by_space\000"
.LASF19:
	.ascii	"__SIZEOF_SHORT__ 2\000"
.LASF471:
	.ascii	"short int\000"
.LASF459:
	.ascii	"__CTYPE_BLANK 0x40\000"
.LASF164:
	.ascii	"__LDBL_EPSILON__ 1.1\000"
.LASF49:
	.ascii	"__INT_LEAST8_TYPE__ signed char\000"
.LASF335:
	.ascii	"__ARM_32BIT_STATE 1\000"
.LASF485:
	.ascii	"mon_decimal_point\000"
.LASF84:
	.ascii	"__UINTMAX_C(c) c ## ULL\000"
.LASF29:
	.ascii	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF175:
	.ascii	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF\000"
.LASF211:
	.ascii	"__LFRACT_IBIT__ 0\000"
.LASF539:
	.ascii	"__RAL_c_locale_abbrev_month_names\000"
.LASF343:
	.ascii	"__ARM_ARCH 7\000"
.LASF3:
	.ascii	"__STDC_UTF_32__ 1\000"
.LASF97:
	.ascii	"__INT_LEAST16_MAX__ 0x7fff\000"
.LASF375:
	.ascii	"NRF52840_XXAA 1\000"
.LASF70:
	.ascii	"__SCHAR_MAX__ 0x7f\000"
.LASF266:
	.ascii	"__ULLACCUM_IBIT__ 32\000"
.LASF189:
	.ascii	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000"
	.ascii	"000000001E-6143DL\000"
.LASF226:
	.ascii	"__ULLFRACT_IBIT__ 0\000"
.LASF9:
	.ascii	"__ATOMIC_RELAXED 0\000"
.LASF51:
	.ascii	"__INT_LEAST32_TYPE__ long int\000"
.LASF480:
	.ascii	"decimal_point\000"
.LASF80:
	.ascii	"__SIZE_MAX__ 0xffffffffU\000"
.LASF252:
	.ascii	"__LACCUM_MIN__ (-0X1P31LK-0X1P31LK)\000"
.LASF268:
	.ascii	"__ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK\000"
.LASF257:
	.ascii	"__ULACCUM_MIN__ 0.0ULK\000"
.LASF351:
	.ascii	"__ARM_FP 4\000"
.LASF495:
	.ascii	"n_sep_by_space\000"
.LASF138:
	.ascii	"__FLT_HAS_INFINITY__ 1\000"
.LASF349:
	.ascii	"__ARMEL__ 1\000"
.LASF303:
	.ascii	"__UDA_IBIT__ 32\000"
.LASF419:
	.ascii	"INT_FAST32_MAX INT32_MAX\000"
.LASF60:
	.ascii	"__INT_FAST64_TYPE__ long long int\000"
.LASF96:
	.ascii	"__INT8_C(c) c\000"
.LASF346:
	.ascii	"__thumb2__ 1\000"
.LASF469:
	.ascii	"signed char\000"
.LASF267:
	.ascii	"__ULLACCUM_MIN__ 0.0ULLK\000"
.LASF512:
	.ascii	"uint32_t\000"
.LASF371:
	.ascii	"BOARD_PCA10056 1\000"
.LASF517:
	.ascii	"__iswctype\000"
.LASF493:
	.ascii	"p_sep_by_space\000"
.LASF66:
	.ascii	"__UINTPTR_TYPE__ unsigned int\000"
.LASF135:
	.ascii	"__FLT_EPSILON__ 1.1\000"
.LASF354:
	.ascii	"__ARM_NEON\000"
.LASF311:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1\000"
.LASF435:
	.ascii	"INT32_C(x) (x ##L)\000"
.LASF513:
	.ascii	"__RAL_locale_data_t\000"
.LASF293:
	.ascii	"__SA_IBIT__ 16\000"
.LASF223:
	.ascii	"__LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR\000"
.LASF114:
	.ascii	"__INT_FAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF140:
	.ascii	"__FP_FAST_FMAF 1\000"
.LASF558:
	.ascii	"float\000"
.LASF127:
	.ascii	"__FLT_DIG__ 6\000"
.LASF112:
	.ascii	"__INT_FAST16_MAX__ 0x7fffffff\000"
.LASF314:
	.ascii	"__GCC_ATOMIC_BOOL_LOCK_FREE 2\000"
.LASF312:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1\000"
.LASF394:
	.ascii	"INT32_MIN (-2147483647L-1)\000"
.LASF294:
	.ascii	"__DA_FBIT__ 31\000"
.LASF166:
	.ascii	"__LDBL_HAS_DENORM__ 1\000"
.LASF172:
	.ascii	"__DEC32_MIN__ 1E-95DF\000"
.LASF121:
	.ascii	"__GCC_IEC_559 0\000"
.LASF475:
	.ascii	"long long unsigned int\000"
.LASF352:
	.ascii	"__ARM_FEATURE_FMA 1\000"
.LASF239:
	.ascii	"__USACCUM_EPSILON__ 0x1P-8UHK\000"
.LASF544:
	.ascii	"__RAL_data_utf8_minus\000"
.LASF79:
	.ascii	"__PTRDIFF_MAX__ 0x7fffffff\000"
.LASF444:
	.ascii	"WINT_MAX 2147483647L\000"
.LASF258:
	.ascii	"__ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK\000"
.LASF208:
	.ascii	"__UFRACT_MAX__ 0XFFFFP-16UR\000"
.LASF193:
	.ascii	"__SFRACT_MAX__ 0X7FP-7HR\000"
.LASF541:
	.ascii	"__RAL_data_utf8_comma\000"
.LASF103:
	.ascii	"__UINT_LEAST8_MAX__ 0xff\000"
.LASF184:
	.ascii	"__DEC128_MIN_EXP__ (-6142)\000"
.LASF87:
	.ascii	"__INT8_MAX__ 0x7f\000"
.LASF219:
	.ascii	"__ULFRACT_EPSILON__ 0x1P-32ULR\000"
.LASF518:
	.ascii	"__towupper\000"
.LASF440:
	.ascii	"UINTMAX_C(x) (x ##ULL)\000"
.LASF216:
	.ascii	"__ULFRACT_IBIT__ 0\000"
.LASF260:
	.ascii	"__LLACCUM_FBIT__ 31\000"
.LASF109:
	.ascii	"__UINT_LEAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF125:
	.ascii	"__FLT_RADIX__ 2\000"
.LASF546:
	.ascii	"__user_set_time_of_day\000"
.LASF503:
	.ascii	"int_n_sign_posn\000"
.LASF227:
	.ascii	"__ULLFRACT_MIN__ 0.0ULLR\000"
.LASF154:
	.ascii	"__DBL_HAS_QUIET_NAN__ 1\000"
.LASF247:
	.ascii	"__UACCUM_MIN__ 0.0UK\000"
.LASF553:
	.ascii	"__RAL_error_decoder_head\000"
.LASF214:
	.ascii	"__LFRACT_EPSILON__ 0x1P-31LR\000"
.LASF490:
	.ascii	"int_frac_digits\000"
.LASF234:
	.ascii	"__SACCUM_EPSILON__ 0x1P-7HK\000"
.LASF62:
	.ascii	"__UINT_FAST16_TYPE__ unsigned int\000"
.LASF368:
	.ascii	"__ARM_ARCH_FPV4_SP_D16__ 1\000"
.LASF384:
	.ascii	"__bool_true_false_are_defined 1\000"
.LASF230:
	.ascii	"__SACCUM_FBIT__ 7\000"
.LASF468:
	.ascii	"NULL 0\000"
.LASF341:
	.ascii	"__ARM_ARCH_PROFILE 77\000"
.LASF347:
	.ascii	"__THUMBEL__ 1\000"
.LASF180:
	.ascii	"__DEC64_MAX__ 9.999999999999999E384DD\000"
.LASF202:
	.ascii	"__FRACT_MIN__ (-0.5R-0.5R)\000"
.LASF450:
	.ascii	"__RAL_SIZE_MAX 4294967295UL\000"
.LASF320:
	.ascii	"__GCC_ATOMIC_INT_LOCK_FREE 2\000"
.LASF556:
	.ascii	"lower\000"
.LASF207:
	.ascii	"__UFRACT_MIN__ 0.0UR\000"
.LASF249:
	.ascii	"__UACCUM_EPSILON__ 0x1P-16UK\000"
.LASF393:
	.ascii	"INT32_MAX 2147483647L\000"
.LASF241:
	.ascii	"__ACCUM_IBIT__ 16\000"
.LASF277:
	.ascii	"__DQ_IBIT__ 0\000"
.LASF448:
	.ascii	"__RAL_SIZE_T\000"
.LASF235:
	.ascii	"__USACCUM_FBIT__ 8\000"
.LASF231:
	.ascii	"__SACCUM_IBIT__ 8\000"
.LASF328:
	.ascii	"__SIZEOF_PTRDIFF_T__ 4\000"
.LASF562:
	.ascii	"timeval\000"
.LASF285:
	.ascii	"__USQ_IBIT__ 0\000"
.LASF477:
	.ascii	"__wchar\000"
.LASF150:
	.ascii	"__DBL_EPSILON__ ((double)1.1)\000"
.LASF441:
	.ascii	"WCHAR_MIN (-2147483647L-1)\000"
.LASF183:
	.ascii	"__DEC128_MANT_DIG__ 34\000"
.LASF360:
	.ascii	"__ARM_ARCH_EXT_IDIV__ 1\000"
.LASF333:
	.ascii	"__ARM_FEATURE_UNALIGNED 1\000"
.LASF429:
	.ascii	"INTPTR_MAX INT32_MAX\000"
.LASF496:
	.ascii	"p_sign_posn\000"
.LASF20:
	.ascii	"__SIZEOF_FLOAT__ 4\000"
.LASF559:
	.ascii	"GNU C99 6.3.1 20170620 (release) [ARM/embedded-6-br"
	.ascii	"anch revision 249437] -fmessage-length=0 -mcpu=cort"
	.ascii	"ex-m4 -mlittle-endian -mfloat-abi=hard -mfpu=fpv4-s"
	.ascii	"p-d16 -mthumb -mtp=soft -g3 -gpubnames -std=gnu99 -"
	.ascii	"fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builti"
	.ascii	"n -ffunction-sections -fdata-sections -fshort-enums"
	.ascii	" -fno-common\000"
.LASF238:
	.ascii	"__USACCUM_MAX__ 0XFFFFP-8UHK\000"
.LASF108:
	.ascii	"__UINT32_C(c) c ## UL\000"
.LASF171:
	.ascii	"__DEC32_MAX_EXP__ 97\000"
.LASF498:
	.ascii	"int_p_cs_precedes\000"
.LASF561:
	.ascii	"C:\\Repositories\\nRFSwarm\\pca10056\\blank\\ses\000"
.LASF5:
	.ascii	"__GNUC__ 6\000"
.LASF163:
	.ascii	"__LDBL_MIN__ 1.1\000"
.LASF295:
	.ascii	"__DA_IBIT__ 32\000"
.LASF25:
	.ascii	"__BIGGEST_ALIGNMENT__ 8\000"
.LASF251:
	.ascii	"__LACCUM_IBIT__ 32\000"
.LASF463:
	.ascii	"__CTYPE_GRAPH (__CTYPE_PUNCT | __CTYPE_UPPER | __CT"
	.ascii	"YPE_LOWER | __CTYPE_DIGIT)\000"
.LASF198:
	.ascii	"__USFRACT_MAX__ 0XFFP-8UHR\000"
.LASF115:
	.ascii	"__UINT_FAST8_MAX__ 0xffffffffU\000"
.LASF26:
	.ascii	"__ORDER_LITTLE_ENDIAN__ 1234\000"
.LASF262:
	.ascii	"__LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)\000"
.LASF418:
	.ascii	"INT_FAST16_MAX INT32_MAX\000"
.LASF292:
	.ascii	"__SA_FBIT__ 15\000"
.LASF510:
	.ascii	"time_format\000"
.LASF399:
	.ascii	"INTMAX_MAX 9223372036854775807LL\000"
.LASF529:
	.ascii	"__category\000"
.LASF58:
	.ascii	"__INT_FAST16_TYPE__ int\000"
.LASF401:
	.ascii	"INT_LEAST8_MIN INT8_MIN\000"
.LASF46:
	.ascii	"__UINT16_TYPE__ short unsigned int\000"
.LASF372:
	.ascii	"CONFIG_GPIO_AS_PINRESET 1\000"
.LASF499:
	.ascii	"int_n_cs_precedes\000"
.LASF308:
	.ascii	"__GNUC_STDC_INLINE__ 1\000"
.LASF283:
	.ascii	"__UHQ_IBIT__ 0\000"
.LASF205:
	.ascii	"__UFRACT_FBIT__ 16\000"
.LASF434:
	.ascii	"UINT16_C(x) (x ##U)\000"
.LASF337:
	.ascii	"__ARM_FEATURE_CLZ 1\000"
.LASF74:
	.ascii	"__LONG_LONG_MAX__ 0x7fffffffffffffffLL\000"
.LASF406:
	.ascii	"INT_LEAST16_MAX INT16_MAX\000"
.LASF44:
	.ascii	"__INT64_TYPE__ long long int\000"
.LASF131:
	.ascii	"__FLT_MAX_10_EXP__ 38\000"
.LASF502:
	.ascii	"int_p_sign_posn\000"
.LASF489:
	.ascii	"negative_sign\000"
.LASF370:
	.ascii	"DEBUG_NRF 1\000"
.LASF264:
	.ascii	"__LLACCUM_EPSILON__ 0x1P-31LLK\000"
.LASF447:
	.ascii	"__THREAD __thread\000"
.LASF309:
	.ascii	"__NO_INLINE__ 1\000"
.LASF404:
	.ascii	"INT_LEAST64_MIN INT64_MIN\000"
.LASF217:
	.ascii	"__ULFRACT_MIN__ 0.0ULR\000"
.LASF126:
	.ascii	"__FLT_MANT_DIG__ 24\000"
.LASF81:
	.ascii	"__INTMAX_MAX__ 0x7fffffffffffffffLL\000"
.LASF306:
	.ascii	"__REGISTER_PREFIX__ \000"
.LASF420:
	.ascii	"INT_FAST64_MAX INT64_MAX\000"
.LASF381:
	.ascii	"bool _Bool\000"
.LASF246:
	.ascii	"__UACCUM_IBIT__ 16\000"
.LASF116:
	.ascii	"__UINT_FAST16_MAX__ 0xffffffffU\000"
.LASF456:
	.ascii	"__CTYPE_SPACE 0x08\000"
.LASF69:
	.ascii	"__GXX_ABI_VERSION 1010\000"
.LASF236:
	.ascii	"__USACCUM_IBIT__ 8\000"
.LASF356:
	.ascii	"__THUMB_INTERWORK__ 1\000"
.LASF200:
	.ascii	"__FRACT_FBIT__ 15\000"
.LASF412:
	.ascii	"UINT_LEAST64_MAX UINT64_MAX\000"
.LASF385:
	.ascii	"__stdint_H \000"
.LASF18:
	.ascii	"__SIZEOF_LONG_LONG__ 8\000"
.LASF526:
	.ascii	"__RAL_locale_t\000"
.LASF123:
	.ascii	"__FLT_EVAL_METHOD__ 0\000"
.LASF545:
	.ascii	"__RAL_data_empty_string\000"
.LASF377:
	.ascii	"UART_ENABLED 0\000"
.LASF408:
	.ascii	"INT_LEAST64_MAX INT64_MAX\000"
.LASF101:
	.ascii	"__INT_LEAST64_MAX__ 0x7fffffffffffffffLL\000"
.LASF240:
	.ascii	"__ACCUM_FBIT__ 15\000"
.LASF414:
	.ascii	"INT_FAST16_MIN INT32_MIN\000"
.LASF177:
	.ascii	"__DEC64_MIN_EXP__ (-382)\000"
.LASF256:
	.ascii	"__ULACCUM_IBIT__ 32\000"
.LASF220:
	.ascii	"__LLFRACT_FBIT__ 63\000"
.LASF519:
	.ascii	"__towlower\000"
.LASF524:
	.ascii	"data\000"
.LASF300:
	.ascii	"__USA_FBIT__ 16\000"
.LASF91:
	.ascii	"__UINT8_MAX__ 0xff\000"
.LASF92:
	.ascii	"__UINT16_MAX__ 0xffff\000"
.LASF369:
	.ascii	"DEBUG 1\000"
.LASF134:
	.ascii	"__FLT_MIN__ 1.1\000"
.LASF462:
	.ascii	"__CTYPE_ALNUM (__CTYPE_UPPER | __CTYPE_LOWER | __CT"
	.ascii	"YPE_DIGIT)\000"
.LASF386:
	.ascii	"UINT8_MAX 255\000"
.LASF426:
	.ascii	"PTRDIFF_MAX INT32_MAX\000"
.LASF173:
	.ascii	"__DEC32_MAX__ 9.999999E96DF\000"
.LASF210:
	.ascii	"__LFRACT_FBIT__ 31\000"
.LASF367:
	.ascii	"__SES_ARM 1\000"
.LASF443:
	.ascii	"WINT_MIN (-2147483647L-1)\000"
.LASF50:
	.ascii	"__INT_LEAST16_TYPE__ short int\000"
.LASF315:
	.ascii	"__GCC_ATOMIC_CHAR_LOCK_FREE 2\000"
.LASF142:
	.ascii	"__DBL_DIG__ 15\000"
.LASF316:
	.ascii	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2\000"
.LASF95:
	.ascii	"__INT_LEAST8_MAX__ 0x7f\000"
.LASF250:
	.ascii	"__LACCUM_FBIT__ 31\000"
.LASF209:
	.ascii	"__UFRACT_EPSILON__ 0x1P-16UR\000"
.LASF151:
	.ascii	"__DBL_DENORM_MIN__ ((double)1.1)\000"
.LASF321:
	.ascii	"__GCC_ATOMIC_LONG_LOCK_FREE 2\000"
.LASF244:
	.ascii	"__ACCUM_EPSILON__ 0x1P-15K\000"
.LASF400:
	.ascii	"UINTMAX_MAX 18446744073709551615ULL\000"
.LASF286:
	.ascii	"__UDQ_FBIT__ 64\000"
.LASF378:
	.ascii	"__HEAP_SIZE 0\000"
.LASF348:
	.ascii	"__ARM_ARCH_ISA_THUMB 2\000"
.LASF288:
	.ascii	"__UTQ_FBIT__ 128\000"
.LASF474:
	.ascii	"long long int\000"
.LASF100:
	.ascii	"__INT32_C(c) c ## L\000"
.LASF455:
	.ascii	"__CTYPE_DIGIT 0x04\000"
.LASF508:
	.ascii	"am_pm_indicator\000"
.LASF53:
	.ascii	"__UINT_LEAST8_TYPE__ unsigned char\000"
.LASF465:
	.ascii	"__RAL_WCHAR_T unsigned\000"
.LASF15:
	.ascii	"__FINITE_MATH_ONLY__ 0\000"
.LASF233:
	.ascii	"__SACCUM_MAX__ 0X7FFFP-7HK\000"
.LASF342:
	.ascii	"__arm__ 1\000"
.LASF155:
	.ascii	"__LDBL_MANT_DIG__ 53\000"
.LASF279:
	.ascii	"__TQ_IBIT__ 0\000"
.LASF298:
	.ascii	"__UHA_FBIT__ 8\000"
.LASF487:
	.ascii	"mon_grouping\000"
.LASF365:
	.ascii	"__ELF__ 1\000"
.LASF437:
	.ascii	"INT64_C(x) (x ##LL)\000"
.LASF98:
	.ascii	"__INT16_C(c) c\000"
.LASF330:
	.ascii	"__ARM_FEATURE_QBIT 1\000"
.LASF94:
	.ascii	"__UINT64_MAX__ 0xffffffffffffffffULL\000"
.LASF253:
	.ascii	"__LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK\000"
.LASF113:
	.ascii	"__INT_FAST32_MAX__ 0x7fffffff\000"
.LASF199:
	.ascii	"__USFRACT_EPSILON__ 0x1P-8UHR\000"
.LASF11:
	.ascii	"__ATOMIC_ACQUIRE 2\000"
.LASF47:
	.ascii	"__UINT32_TYPE__ long unsigned int\000"
.LASF458:
	.ascii	"__CTYPE_CNTRL 0x20\000"
.LASF90:
	.ascii	"__INT64_MAX__ 0x7fffffffffffffffLL\000"
.LASF363:
	.ascii	"__ARM_FEATURE_COPROC 15\000"
.LASF0:
	.ascii	"__STDC__ 1\000"
.LASF461:
	.ascii	"__CTYPE_ALPHA (__CTYPE_UPPER | __CTYPE_LOWER)\000"
.LASF245:
	.ascii	"__UACCUM_FBIT__ 16\000"
.LASF505:
	.ascii	"abbrev_day_names\000"
.LASF132:
	.ascii	"__FLT_DECIMAL_DIG__ 9\000"
.LASF14:
	.ascii	"__ATOMIC_CONSUME 1\000"
.LASF436:
	.ascii	"UINT32_C(x) (x ##UL)\000"
.LASF35:
	.ascii	"__WINT_TYPE__ unsigned int\000"
.LASF73:
	.ascii	"__LONG_MAX__ 0x7fffffffL\000"
.LASF88:
	.ascii	"__INT16_MAX__ 0x7fff\000"
.LASF215:
	.ascii	"__ULFRACT_FBIT__ 32\000"
.LASF34:
	.ascii	"__WCHAR_TYPE__ unsigned int\000"
.LASF242:
	.ascii	"__ACCUM_MIN__ (-0X1P15K-0X1P15K)\000"
.LASF424:
	.ascii	"UINT_FAST64_MAX UINT64_MAX\000"
.LASF21:
	.ascii	"__SIZEOF_DOUBLE__ 8\000"
.LASF7:
	.ascii	"__GNUC_PATCHLEVEL__ 1\000"
.LASF548:
	.ascii	"__RAL_error_decoder_fn_t\000"
.LASF364:
	.ascii	"__GXX_TYPEINFO_EQUALITY_INLINE 0\000"
.LASF442:
	.ascii	"WCHAR_MAX 2147483647L\000"
.LASF203:
	.ascii	"__FRACT_MAX__ 0X7FFFP-15R\000"
.LASF78:
	.ascii	"__WINT_MIN__ 0U\000"
.LASF255:
	.ascii	"__ULACCUM_FBIT__ 32\000"
.LASF504:
	.ascii	"day_names\000"
.LASF366:
	.ascii	"__SIZEOF_WCHAR_T 4\000"
.LASF185:
	.ascii	"__DEC128_MAX_EXP__ 6145\000"
.LASF355:
	.ascii	"__ARM_NEON_FP\000"
.LASF2:
	.ascii	"__STDC_UTF_16__ 1\000"
.LASF201:
	.ascii	"__FRACT_IBIT__ 0\000"
.LASF520:
	.ascii	"__wctomb\000"
.LASF296:
	.ascii	"__TA_FBIT__ 63\000"
.LASF167:
	.ascii	"__LDBL_HAS_INFINITY__ 1\000"
.LASF122:
	.ascii	"__GCC_IEC_559_COMPLEX 0\000"
.LASF93:
	.ascii	"__UINT32_MAX__ 0xffffffffUL\000"
.LASF157:
	.ascii	"__LDBL_MIN_EXP__ (-1021)\000"
.LASF225:
	.ascii	"__ULLFRACT_FBIT__ 64\000"
.LASF326:
	.ascii	"__SIZEOF_WCHAR_T__ 4\000"
.LASF535:
	.ascii	"__RAL_ascii_ctype_map\000"
.LASF30:
	.ascii	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF243:
	.ascii	"__ACCUM_MAX__ 0X7FFFFFFFP-15K\000"
.LASF206:
	.ascii	"__UFRACT_IBIT__ 0\000"
.LASF169:
	.ascii	"__DEC32_MANT_DIG__ 7\000"
.LASF464:
	.ascii	"__CTYPE_PRINT (__CTYPE_BLANK | __CTYPE_PUNCT | __CT"
	.ascii	"YPE_UPPER | __CTYPE_LOWER | __CTYPE_DIGIT)\000"
.LASF511:
	.ascii	"date_time_format\000"
.LASF86:
	.ascii	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)\000"
.LASF224:
	.ascii	"__LLFRACT_EPSILON__ 0x1P-63LLR\000"
.LASF438:
	.ascii	"UINT64_C(x) (x ##ULL)\000"
.LASF521:
	.ascii	"__mbtowc\000"
.LASF527:
	.ascii	"__mbstate_s\000"
.LASF190:
	.ascii	"__SFRACT_FBIT__ 7\000"
.LASF39:
	.ascii	"__CHAR32_TYPE__ long unsigned int\000"
.LASF191:
	.ascii	"__SFRACT_IBIT__ 0\000"
.LASF397:
	.ascii	"UINT64_MAX 18446744073709551615ULL\000"
.LASF273:
	.ascii	"__HQ_IBIT__ 0\000"
.LASF533:
	.ascii	"__RAL_codeset_ascii\000"
.LASF307:
	.ascii	"__USER_LABEL_PREFIX__ \000"
.LASF451:
	.ascii	"__RAL_PTRDIFF_T int\000"
.LASF55:
	.ascii	"__UINT_LEAST32_TYPE__ long unsigned int\000"
.LASF276:
	.ascii	"__DQ_FBIT__ 63\000"
.LASF192:
	.ascii	"__SFRACT_MIN__ (-0.5HR-0.5HR)\000"
.LASF336:
	.ascii	"__ARM_FEATURE_LDREX 7\000"
.LASF325:
	.ascii	"__PRAGMA_REDEFINE_EXTNAME 1\000"
.LASF392:
	.ascii	"UINT32_MAX 4294967295UL\000"
.LASF27:
	.ascii	"__ORDER_BIG_ENDIAN__ 4321\000"
.LASF71:
	.ascii	"__SHRT_MAX__ 0x7fff\000"
.LASF318:
	.ascii	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2\000"
.LASF28:
	.ascii	"__ORDER_PDP_ENDIAN__ 3412\000"
.LASF275:
	.ascii	"__SQ_IBIT__ 0\000"
.LASF522:
	.ascii	"__RAL_locale_codeset_t\000"
.LASF525:
	.ascii	"codeset\000"
.LASF89:
	.ascii	"__INT32_MAX__ 0x7fffffffL\000"
.LASF515:
	.ascii	"__toupper\000"
.LASF388:
	.ascii	"INT8_MIN (-128)\000"
.LASF188:
	.ascii	"__DEC128_EPSILON__ 1E-33DL\000"
.LASF431:
	.ascii	"INT8_C(x) (x)\000"
.LASF280:
	.ascii	"__UQQ_FBIT__ 8\000"
.LASF555:
	.ascii	"value\000"
.LASF339:
	.ascii	"__ARM_SIZEOF_MINIMAL_ENUM 1\000"
.LASF531:
	.ascii	"__RAL_global_locale\000"
.LASF263:
	.ascii	"__LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK\000"
.LASF550:
	.ascii	"decode\000"
.LASF178:
	.ascii	"__DEC64_MAX_EXP__ 385\000"
.LASF407:
	.ascii	"INT_LEAST32_MAX INT32_MAX\000"
.LASF43:
	.ascii	"__INT32_TYPE__ long int\000"
.LASF483:
	.ascii	"int_curr_symbol\000"
.LASF478:
	.ascii	"long int\000"
.LASF361:
	.ascii	"__ARM_FEATURE_IDIV 1\000"
.LASF491:
	.ascii	"frac_digits\000"
.LASF159:
	.ascii	"__LDBL_MAX_EXP__ 1024\000"
.LASF274:
	.ascii	"__SQ_FBIT__ 31\000"
.LASF212:
	.ascii	"__LFRACT_MIN__ (-0.5LR-0.5LR)\000"
.LASF428:
	.ascii	"INTPTR_MIN INT32_MIN\000"
.LASF549:
	.ascii	"__RAL_error_decoder_s\000"
.LASF453:
	.ascii	"__CTYPE_UPPER 0x01\000"
.LASF552:
	.ascii	"__RAL_error_decoder_t\000"
.LASF387:
	.ascii	"INT8_MAX 127\000"
.LASF452:
	.ascii	"__CODE \000"
.LASF107:
	.ascii	"__UINT_LEAST32_MAX__ 0xffffffffUL\000"
.LASF413:
	.ascii	"INT_FAST8_MIN INT8_MIN\000"
.LASF345:
	.ascii	"__thumb__ 1\000"
.LASF168:
	.ascii	"__LDBL_HAS_QUIET_NAN__ 1\000"
.LASF41:
	.ascii	"__INT8_TYPE__ signed char\000"
.LASF77:
	.ascii	"__WINT_MAX__ 0xffffffffU\000"
.LASF445:
	.ascii	"__string_H \000"
.LASF423:
	.ascii	"UINT_FAST32_MAX UINT32_MAX\000"
.LASF278:
	.ascii	"__TQ_FBIT__ 127\000"
.LASF282:
	.ascii	"__UHQ_FBIT__ 16\000"
.LASF396:
	.ascii	"INT64_MAX 9223372036854775807LL\000"
.LASF118:
	.ascii	"__UINT_FAST64_MAX__ 0xffffffffffffffffULL\000"
.LASF117:
	.ascii	"__UINT_FAST32_MAX__ 0xffffffffU\000"
.LASF195:
	.ascii	"__USFRACT_FBIT__ 8\000"
.LASF102:
	.ascii	"__INT64_C(c) c ## LL\000"
.LASF272:
	.ascii	"__HQ_FBIT__ 15\000"
.LASF299:
	.ascii	"__UHA_IBIT__ 8\000"
.LASF534:
	.ascii	"__RAL_codeset_utf8\000"
.LASF75:
	.ascii	"__WCHAR_MAX__ 0xffffffffU\000"
.LASF281:
	.ascii	"__UQQ_IBIT__ 0\000"
.LASF45:
	.ascii	"__UINT8_TYPE__ unsigned char\000"
.LASF67:
	.ascii	"__has_include(STR) __has_include__(STR)\000"
.LASF395:
	.ascii	"INT64_MIN (-9223372036854775807LL-1)\000"
.LASF52:
	.ascii	"__INT_LEAST64_TYPE__ long long int\000"
.LASF488:
	.ascii	"positive_sign\000"
.LASF467:
	.ascii	"__RAL_SIZE_T_DEFINED \000"
.LASF500:
	.ascii	"int_p_sep_by_space\000"
.LASF158:
	.ascii	"__LDBL_MIN_10_EXP__ (-307)\000"
.LASF523:
	.ascii	"name\000"
.LASF31:
	.ascii	"__SIZEOF_POINTER__ 4\000"
.LASF540:
	.ascii	"__RAL_data_utf8_period\000"
.LASF338:
	.ascii	"__ARM_FEATURE_SIMD32 1\000"
.LASF350:
	.ascii	"__VFP_FP__ 1\000"
.LASF218:
	.ascii	"__ULFRACT_MAX__ 0XFFFFFFFFP-32ULR\000"
.LASF290:
	.ascii	"__HA_FBIT__ 7\000"
.LASF403:
	.ascii	"INT_LEAST32_MIN INT32_MIN\000"
.LASF454:
	.ascii	"__CTYPE_LOWER 0x02\000"
.LASF232:
	.ascii	"__SACCUM_MIN__ (-0X1P7HK-0X1P7HK)\000"
.LASF324:
	.ascii	"__GCC_ATOMIC_POINTER_LOCK_FREE 2\000"
.LASF110:
	.ascii	"__UINT64_C(c) c ## ULL\000"
.LASF554:
	.ascii	"check_lower_upper_range\000"
.LASF254:
	.ascii	"__LACCUM_EPSILON__ 0x1P-31LK\000"
.LASF430:
	.ascii	"UINTPTR_MAX UINT32_MAX\000"
.LASF194:
	.ascii	"__SFRACT_EPSILON__ 0x1P-7HR\000"
.LASF530:
	.ascii	"sizetype\000"
.LASF284:
	.ascii	"__USQ_FBIT__ 32\000"
.LASF291:
	.ascii	"__HA_IBIT__ 8\000"
.LASF359:
	.ascii	"__ARM_EABI__ 1\000"
.LASF537:
	.ascii	"__RAL_c_locale_abbrev_day_names\000"
.LASF317:
	.ascii	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2\000"
.LASF1:
	.ascii	"__STDC_VERSION__ 199901L\000"
.LASF136:
	.ascii	"__FLT_DENORM_MIN__ 1.1\000"
.LASF24:
	.ascii	"__CHAR_BIT__ 8\000"
.LASF204:
	.ascii	"__FRACT_EPSILON__ 0x1P-15R\000"
.LASF4:
	.ascii	"__STDC_HOSTED__ 1\000"
.LASF119:
	.ascii	"__INTPTR_MAX__ 0x7fffffff\000"
.LASF149:
	.ascii	"__DBL_MIN__ ((double)1.1)\000"
.LASF560:
	.ascii	"C:\\Repositories\\nRFSwarm\\drivers\\source\\min_ma"
	.ascii	"x.c\000"
.LASF416:
	.ascii	"INT_FAST64_MIN INT64_MIN\000"
.LASF373:
	.ascii	"INITIALIZE_USER_SECTIONS 1\000"
.LASF486:
	.ascii	"mon_thousands_sep\000"
.LASF391:
	.ascii	"INT16_MAX 32767\000"
.LASF322:
	.ascii	"__GCC_ATOMIC_LLONG_LOCK_FREE 1\000"
.LASF313:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1\000"
.LASF130:
	.ascii	"__FLT_MAX_EXP__ 128\000"
.LASF542:
	.ascii	"__RAL_data_utf8_space\000"
.LASF470:
	.ascii	"unsigned char\000"
.LASF170:
	.ascii	"__DEC32_MIN_EXP__ (-94)\000"
.LASF37:
	.ascii	"__UINTMAX_TYPE__ long long unsigned int\000"
.LASF449:
	.ascii	"__RAL_SIZE_T unsigned\000"
.LASF460:
	.ascii	"__CTYPE_XDIGIT 0x80\000"
.LASF536:
	.ascii	"__RAL_c_locale_day_names\000"
.LASF532:
	.ascii	"__RAL_c_locale\000"
.LASF65:
	.ascii	"__INTPTR_TYPE__ int\000"
.LASF358:
	.ascii	"__ARM_PCS_VFP 1\000"
.LASF124:
	.ascii	"__DEC_EVAL_METHOD__ 2\000"
.LASF248:
	.ascii	"__UACCUM_MAX__ 0XFFFFFFFFP-16UK\000"
.LASF237:
	.ascii	"__USACCUM_MIN__ 0.0UHK\000"
.LASF557:
	.ascii	"upper\000"
.LASF196:
	.ascii	"__USFRACT_IBIT__ 0\000"
.LASF481:
	.ascii	"thousands_sep\000"
.LASF63:
	.ascii	"__UINT_FAST32_TYPE__ unsigned int\000"
.LASF446:
	.ascii	"__crossworks_H \000"
.LASF415:
	.ascii	"INT_FAST32_MIN INT32_MIN\000"
.LASF165:
	.ascii	"__LDBL_DENORM_MIN__ 1.1\000"
.LASF32:
	.ascii	"__SIZE_TYPE__ unsigned int\000"
.LASF265:
	.ascii	"__ULLACCUM_FBIT__ 32\000"
.LASF432:
	.ascii	"UINT8_C(x) (x ##U)\000"
.LASF145:
	.ascii	"__DBL_MAX_EXP__ 1024\000"
.LASF514:
	.ascii	"__isctype\000"
.LASF319:
	.ascii	"__GCC_ATOMIC_SHORT_LOCK_FREE 2\000"
.LASF8:
	.ascii	"__VERSION__ \"6.3.1 20170620 (release) [ARM/embedde"
	.ascii	"d-6-branch revision 249437]\"\000"
.LASF484:
	.ascii	"currency_symbol\000"
.LASF439:
	.ascii	"INTMAX_C(x) (x ##LL)\000"
.LASF129:
	.ascii	"__FLT_MIN_10_EXP__ (-37)\000"
.LASF457:
	.ascii	"__CTYPE_PUNCT 0x10\000"
.LASF76:
	.ascii	"__WCHAR_MIN__ 0U\000"
.LASF153:
	.ascii	"__DBL_HAS_INFINITY__ 1\000"
.LASF482:
	.ascii	"grouping\000"
.LASF148:
	.ascii	"__DBL_MAX__ ((double)1.1)\000"
.LASF59:
	.ascii	"__INT_FAST32_TYPE__ int\000"
.LASF331:
	.ascii	"__ARM_FEATURE_SAT 1\000"
.LASF139:
	.ascii	"__FLT_HAS_QUIET_NAN__ 1\000"
.LASF16:
	.ascii	"__SIZEOF_INT__ 4\000"
.LASF36:
	.ascii	"__INTMAX_TYPE__ long long int\000"
.LASF380:
	.ascii	"__stdbool_h \000"
.LASF82:
	.ascii	"__INTMAX_C(c) c ## LL\000"
.LASF374:
	.ascii	"NO_VTOR_CONFIG 1\000"
.LASF422:
	.ascii	"UINT_FAST16_MAX UINT32_MAX\000"
.LASF344:
	.ascii	"__APCS_32__ 1\000"
.LASF417:
	.ascii	"INT_FAST8_MAX INT8_MAX\000"
.LASF389:
	.ascii	"UINT16_MAX 65535\000"
.LASF48:
	.ascii	"__UINT64_TYPE__ long long unsigned int\000"
.LASF425:
	.ascii	"PTRDIFF_MIN INT32_MIN\000"
.LASF146:
	.ascii	"__DBL_MAX_10_EXP__ 308\000"
.LASF543:
	.ascii	"__RAL_data_utf8_plus\000"
.LASF472:
	.ascii	"short unsigned int\000"
.LASF289:
	.ascii	"__UTQ_IBIT__ 0\000"
.LASF297:
	.ascii	"__TA_IBIT__ 64\000"
.LASF270:
	.ascii	"__QQ_FBIT__ 7\000"
.LASF405:
	.ascii	"INT_LEAST8_MAX INT8_MAX\000"
.LASF54:
	.ascii	"__UINT_LEAST16_TYPE__ short unsigned int\000"
.LASF494:
	.ascii	"n_cs_precedes\000"
.LASF390:
	.ascii	"INT16_MIN (-32767-1)\000"
.LASF538:
	.ascii	"__RAL_c_locale_month_names\000"
.LASF128:
	.ascii	"__FLT_MIN_EXP__ (-125)\000"
.LASF402:
	.ascii	"INT_LEAST16_MIN INT16_MIN\000"
.LASF187:
	.ascii	"__DEC128_MAX__ 9.999999999999999999999999999999999E"
	.ascii	"6144DL\000"
.LASF161:
	.ascii	"__DECIMAL_DIG__ 17\000"
.LASF547:
	.ascii	"__user_get_time_of_day\000"
.LASF382:
	.ascii	"true 1\000"
.LASF497:
	.ascii	"n_sign_posn\000"
.LASF160:
	.ascii	"__LDBL_MAX_10_EXP__ 308\000"
.LASF410:
	.ascii	"UINT_LEAST16_MAX UINT16_MAX\000"
.LASF120:
	.ascii	"__UINTPTR_MAX__ 0xffffffffU\000"
.LASF152:
	.ascii	"__DBL_HAS_DENORM__ 1\000"
.LASF305:
	.ascii	"__UTA_IBIT__ 64\000"
.LASF476:
	.ascii	"__state\000"
.LASF213:
	.ascii	"__LFRACT_MAX__ 0X7FFFFFFFP-31LR\000"
.LASF13:
	.ascii	"__ATOMIC_ACQ_REL 4\000"
.LASF302:
	.ascii	"__UDA_FBIT__ 32\000"
.LASF357:
	.ascii	"__ARM_ARCH_7EM__ 1\000"
.LASF383:
	.ascii	"false 0\000"
.LASF509:
	.ascii	"date_format\000"
.LASF99:
	.ascii	"__INT_LEAST32_MAX__ 0x7fffffffL\000"
.LASF162:
	.ascii	"__LDBL_MAX__ 1.1\000"
.LASF179:
	.ascii	"__DEC64_MIN__ 1E-383DD\000"
.LASF528:
	.ascii	"__locale_s\000"
.LASF83:
	.ascii	"__UINTMAX_MAX__ 0xffffffffffffffffULL\000"
.LASF40:
	.ascii	"__SIG_ATOMIC_TYPE__ int\000"
.LASF427:
	.ascii	"SIZE_MAX INT32_MAX\000"
.LASF222:
	.ascii	"__LLFRACT_MIN__ (-0.5LLR-0.5LLR)\000"
.LASF144:
	.ascii	"__DBL_MIN_10_EXP__ (-307)\000"
.LASF506:
	.ascii	"month_names\000"
.LASF492:
	.ascii	"p_cs_precedes\000"
.LASF229:
	.ascii	"__ULLFRACT_EPSILON__ 0x1P-64ULLR\000"
.LASF57:
	.ascii	"__INT_FAST8_TYPE__ int\000"
.LASF105:
	.ascii	"__UINT_LEAST16_MAX__ 0xffff\000"
.LASF269:
	.ascii	"__ULLACCUM_EPSILON__ 0x1P-32ULLK\000"
.LASF176:
	.ascii	"__DEC64_MANT_DIG__ 16\000"
.LASF137:
	.ascii	"__FLT_HAS_DENORM__ 1\000"
.LASF516:
	.ascii	"__tolower\000"
	.ident	"GCC: (GNU) 6.3.1 20170620 (release) [ARM/embedded-6-branch revision 249437]"
