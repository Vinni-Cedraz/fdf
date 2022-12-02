/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:38:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/02 18:55:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***********************************************************
Copyright 1987, 1994, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.


Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

/*
 * The "X11 Window System Protocol" standard defines in Appendix A the
 * keysym codes. These 29-bit integer values identify characters or
 * functions associated with each key (e.g., via the visible
 * engraving) of a keyboard layout. This file assigns mnemonic macro
 * names for these keysyms.
 *
 * This file is also compiled (by src/util/makekeys.c in libX11) into
 * hash tables that can be accessed with X11 library functions such as
 * XStringToKeysym() and XKeysymToString().
 *
 * Where a keysym corresponds one-to-one to an ISO 10646 / Unicode
 * character, this is noted in a comment that provides both the U+xxxx
 * Unicode position, as well as the official Unicode name of the
 * character.
 *
 * Where the correspondence is either not one-to-one or semantically
 * unclear, the Unicode position and name are enclosed in
 * parentheses. Such legacy keysyms should be considered deprecated
 * and are not recommended for use in future keyboard mappings.
 *
 * For any future extension of the keysyms with characters already
 * found in ISO 10646 / Unicode, the following algorithm shall be
 * used. The new keysym code position will simply be the character's
 * Unicode number plus 0x01000000. The keysym values in the range
 * 0x01000100 to 0x0110ffff are reserved to represent Unicode
 * characters in the range U+0100 to U+10FFFF.
 *
 * While most newer Unicode-based X11 clients do already accept
 * Unicode-mapped keysyms in the range 0x01000100 to 0x0110ffff, it
 * will remain necessary for clients -- in the interest of
 * compatibility with existing servers -- to also understand the
 * existing legacy keysym values in the range 0x0100 to 0x20ff.
 *
 * Where several mnemonic names are defined for the same keysym in this
 * file, all but the first one listed should be considered deprecated.
 *
 * Mnemonic names for keysyms are defined in this file with lines
 * that match one of these Perl regular expressions:
 *
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\* U+([0-9A-F]{4,6}) (.*) \*\/\s*$/
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\*\(U+([0-9A-F]{4,6}) (.*)\)\*\/\s*$/
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*(\/\*\s*(.*)\s*\*\/)?\s*$/
 *
 * Before adding new keysyms, please do consider the following: In
 * addition to the keysym names defined in this file, the
 * XStringToKeysym() and XKeysymToString() functions will also handle
 * any keysym string of the form "U0020" to "U007E" and "U00A0" to
 * "U10FFFF" for all possible Unicode characters. In other words,
 * every possible Unicode character has already a keysym string
 * defined algorithmically, even if it is not listed here. Therefore,
 * defining an additional keysym macro is only necessary where a
 * non-hexadecimal mnemonic name is needed, or where the new keysym
 * does not represent any existing Unicode character.
 *
 * When adding new keysyms to this file, do not forget to also update the
 * following:
 *
 *   - the mappings in src/KeyBind.c in the repo
 *     git://anongit.freedesktop.org/xorg/lib/libX11
 *
 *   - the protocol specification in specs/XProtocol/X11.keysyms
 *     in the repo git://anongit.freedesktop.org/xorg/doc/xorg-docs
 *
 */

#ifndef _X11_KEYSYMDEF_H_
# define _X11_KEYSYMDEF_H_

# define XK_VoidSymbol                  0xffffff  /* Void symbol */
/*
 * TTY function keys, cleverly chosen to map to ASCII, for convenience of
 * programming, but could have been arbitrary (at the cost of lookup
 * tables in client code).
 */

# define XK_BackSpace                     0xff08  /* Back space, back char */
# define XK_Tab                           0xff09
# define XK_Linefeed                      0xff0a  /* Linefeed, LF */
# define XK_Clear                         0xff0b
# define XK_Return                        0xff0d  /* Return, enter */
# define XK_Pause                         0xff13  /* Pause, hold */
# define XK_Scroll_Lock                   0xff14
# define XK_Sys_Req                       0xff15
# define XK_Escape                        0xff1b
# define XK_Delete                        0xffff  /* Delete, rubout */



/* International & multi-key character composition */

# define XK_Multi_key                     0xff20  /* Multi-key character compose */
# define XK_Codeinput                     0xff37
# define XK_SingleCandidate               0xff3c
# define XK_MultipleCandidate             0xff3d
# define XK_PreviousCandidate             0xff3e

/* Cursor control & motion */

# define XK_Home                          0xff50
# define XK_Left                          0xff51  /* Move left, left arrow */
# define XK_Up                            0xff52  /* Move up, up arrow */
# define XK_Right                         0xff53  /* Move right, right arrow */
# define XK_Down                          0xff54  /* Move down, down arrow */
# define XK_Prior                         0xff55  /* Prior, previous */
# define XK_Page_Up                       0xff55
# define XK_Next                          0xff56  /* Next */
# define XK_Page_Down                     0xff56
# define XK_End                           0xff57  /* EOL */
# define XK_Begin                         0xff58  /* BOL */


/* Misc functions */

# define XK_Select                        0xff60  /* Select, mark */
# define XK_Print                         0xff61
# define XK_Execute                       0xff62  /* Execute, run, do */
# define XK_Insert                        0xff63  /* Insert, insert here */
# define XK_Undo                          0xff65
# define XK_Redo                          0xff66  /* Redo, again */
# define XK_Menu                          0xff67
# define XK_Find                          0xff68  /* Find, search */
# define XK_Cancel                        0xff69  /* Cancel, stop, abort, exit */
# define XK_Help                          0xff6a  /* Help */
# define XK_Break                         0xff6b
# define XK_Mode_switch                   0xff7e  /* Character set switch */
# define XK_script_switch                 0xff7e  /* Alias for mode_switch */
# define XK_Num_Lock                      0xff7f

/* Keypad functions, keypad numbers cleverly chosen to map to ASCII */

# define XK_KP_Space                      0xff80  /* Space */
# define XK_KP_Tab                        0xff89
# define XK_KP_Enter                      0xff8d  /* Enter */
# define XK_KP_F1                         0xff91  /* PF1, KP_A, ... */
# define XK_KP_F2                         0xff92
# define XK_KP_F3                         0xff93
# define XK_KP_F4                         0xff94
# define XK_KP_Home                       0xff95
# define XK_KP_Left                       0xff96
# define XK_KP_Up                         0xff97
# define XK_KP_Right                      0xff98
# define XK_KP_Down                       0xff99
# define XK_KP_Prior                      0xff9a
# define XK_KP_Page_Up                    0xff9a
# define XK_KP_Next                       0xff9b
# define XK_KP_Page_Down                  0xff9b
# define XK_KP_End                        0xff9c
# define XK_KP_Begin                      0xff9d
# define XK_KP_Insert                     0xff9e
# define XK_KP_Delete                     0xff9f
# define XK_KP_Equal                      0xffbd  /* Equals */
# define XK_KP_Multiply                   0xffaa
# define XK_KP_Add                        0xffab
# define XK_KP_Separator                  0xffac  /* Separator, often comma */
# define XK_KP_Subtract                   0xffad
# define XK_KP_Decimal                    0xffae
# define XK_KP_Divide                     0xffaf

# define XK_KP_0                          0xffb0
# define XK_KP_1                          0xffb1
# define XK_KP_2                          0xffb2
# define XK_KP_3                          0xffb3
# define XK_KP_4                          0xffb4
# define XK_KP_5                          0xffb5
# define XK_KP_6                          0xffb6
# define XK_KP_7                          0xffb7
# define XK_KP_8                          0xffb8
# define XK_KP_9                          0xffb9

/*
 * Auxiliary functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufacturers have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

# define XK_F1                            0xffbe
# define XK_F2                            0xffbf
# define XK_F3                            0xffc0
# define XK_F4                            0xffc1
# define XK_F5                            0xffc2
# define XK_F6                            0xffc3
# define XK_F7                            0xffc4
# define XK_F8                            0xffc5
# define XK_F9                            0xffc6
# define XK_F10                           0xffc7
# define XK_F11                           0xffc8
# define XK_L1                            0xffc8
# define XK_F12                           0xffc9

/* Modifiers */

# define XK_Shift_L                       0xffe1  /* Left shift */
# define XK_Shift_R                       0xffe2  /* Right shift */
# define XK_Control_L                     0xffe3  /* Left control */
# define XK_Control_R                     0xffe4  /* Right control */
# define XK_Caps_Lock                     0xffe5  /* Caps lock */
# define XK_Shift_Lock                    0xffe6  /* Shift lock */

# define XK_Meta_L                        0xffe7  /* Left meta */
# define XK_Meta_R                        0xffe8  /* Right meta */
# define XK_Alt_L                         0xffe9  /* Left alt */
# define XK_Alt_R                         0xffea  /* Right alt */
# define XK_Super_L                       0xffeb  /* Left super */
# define XK_Super_R                       0xffec  /* Right super */
# define XK_Hyper_L                       0xffed  /* Left hyper */
# define XK_Hyper_R                       0xffee  /* Right hyper */

# endif
