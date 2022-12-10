/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keycodes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:38:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/10 19:55:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copyright 1987, 1994, 1998  The Open Group
//
// Permission to use, copy, modify, distribute, and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appear in all copies and that both that
// copyright notice and this permission notice appear in supporting
// documentation.
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// Except as contained in this notice, the name of The Open Group shall
// not be used in advertising or otherwise to promote the sale, use or
// other dealings in this Software without prior written authorization
// from The Open Group.
//
//
// Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts
//
//                         All Rights Reserved
//
// Permission to use, copy, modify, and distribute this software and its
// documentation for any purpose and without fee is hereby granted,
// provided that the above copyright notice appear in all copies and that
// both that copyright notice and this permission notice appear in
// supporting documentation, and that the name of Digital not be
// used in advertising or publicity pertaining to distribution of the
// software without specific, written prior permission.
//
// DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
// ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
// DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
// ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
// ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
// SOFTWARE.
//
// ******************************************************************
//
//  *
//  * The "X11 Window System Protocol" standard defines in Appendix A the
//  * keysym codes. These 29-bit integer values identify characters or
//  * functions associated with each key (e.g., via the visible
//  * engraving) of a keyboard layout. This file assigns mnemonic macro
//  * names for these keysyms.
//  *
//  * This file is also compiled (by src/util/makekeys.c in libX11) into
//  * hash tables that can be accessed with X11 library functions such as
//  * XStringToKeysym() and XKeysymToString().
//  *
//  * Where a keysym corresponds one-to-one to an ISO 10646 / Unicode
//  * character, this is noted in a comment that provides both the U+xxxx
//  * Unicode position, as well as the official Unicode name of the
//  * character.
//  *
//  * Where the correspondence is either not one-to-one or semantically
//  * unclear, the Unicode position and name are enclosed in
//  * parentheses. Such legacy keysyms should be considered deprecated
//  * and are not recommended for use in future keyboard mappings.
//  *
//  * For any future extension of the keysyms with characters already
//  * found in ISO 10646 / Unicode, the following algorithm shall be
//  * used. The new keysym code position will simply be the character's
//  * Unicode number plus 0x01000000. The keysym values in the range
//  * 0x01000100 to 0x0110ffff are reserved to represent Unicode
//  * characters in the range U+0100 to U+10FFFF.
//  *
//  * While most newer Unicode-based X11 clients do already accept
//  * Unicode-mapped keysyms in the range 0x01000100 to 0x0110ffff, it
//  * will remain necessary for clients -- in the interest of
//  * compatibility with existing servers -- to also understand the
//  * existing legacy keysym values in the range 0x0100 to 0x20ff.
//  *
//  * Where several mnemonic names are defined for the same keysym in this
//  * file, all but the first one listed should be considered deprecated.
//  *
//  * Mnemonic names for keysyms are defined in this file with lines
//  * that match one of these Perl regular expressions:
//  *
//  *
// 	/^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\* U+([0-9A-F]{4,6})
// (.*) \*\/\s*$/
//  *
// 	/^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\*\(U+([0-9A-F]{4,6})
// (.*)\)\*\/\s*$/
//  *    /^\#define
//  XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*(\/\*\s*(.*)\s*\*\/)?\s*$/
//  *
//  * Before adding new keysyms, please do consider the following: In
//  * addition to the keysym names defined in this file, the
//  * XStringToKeysym() and XKeysymToString() functions will also handle
//  * any keysym string of the form "U0020" to "U007E" and "U00A0" to
//  * "U10FFFF" for all possible Unicode characters. In other words,
//  * every possible Unicode character has already a keysym string
//  * defined algorithmically, even if it is not listed here. Therefore,
//  * defining an additional keysym macro is only necessary where a
//  * non-hexadecimal mnemonic name is needed, or where the new keysym
//  * does not represent any existing Unicode character.
//  *
//  * When adding new keysyms to this file, do not forget to also update the
//  * following:
//  *
//  *   - the mappings in src/KeyBind.c in the repo
//  *     git://anongit.freedesktop.org/xorg/lib/libX11
//  *
//  *   - the protocol specification in specs/XProtocol/X11.keysyms
//  *     in the repo git://anongit.freedesktop.org/xorg/doc/xorg-docs
//  *

#ifndef FDF_KEYCODES_H
# define FDF_KEYCODES_H

# define XK_VOIDSYMBOL 0xffffff /* Void symbol */

# define XK_BACKSPACE 0xff08 /* Back space, back char */
# define XK_TAB 0xff09
# define XK_LINEFEED 0xff0a /* Linefeed, LF */
# define XK_CLEAR 0xff0b
# define XK_RETURN 0xff0d /* Return, enter */
# define XK_PAUSE 0xff13  /* Pause, hold */
# define XK_SCROLL_LOCK 0xff14
# define XK_SYS_REQ 0xff15
# define XK_ESCAPE 0xff1b
# define XK_DELETE 0xffff /* Delete, rubout */

/* International & multi-key character composition */

# define XK_MULTI_KEY 0xff20 /* Multi-key character compose */
# define XK_CODEINPUT 0xff37
# define XK_SINGLECANDIDATE 0xff3c
# define XK_MULTIPLECANDIDATE 0xff3d
# define XK_PREVIOUSCANDIDATE 0xff3e

/* Cursor control & motion */

# define XK_HOME 0xff50
# define XK_LEFT 0xff51  /* Move left, left arrow */
# define XK_UP 0xff52    /* Move up, up arrow */
# define XK_RIGHT 0xff53 /* Move right, right arrow */
# define XK_DOWN 0xff54  /* Move down, down arrow */
# define XK_PRIOR 0xff55 /* Prior, previous */
# define XK_PAGE_UP 0xff55
# define XK_NEXT 0xff56 /* Next */
# define XK_PAGE_DOWN 0xff56
# define XK_END 0xff57   /* EOL */
# define XK_BEGIN 0xff58 /* BOL */

/* Misc functions */

# define XK_SELECT 0xff60 /* Select, mark */
# define XK_PRINT 0xff61
# define XK_EXECUTE 0xff62 /* Execute, run, do */
# define XK_INSERT 0xff63  /* Insert, insert here */
# define XK_UNDO 0xff65
# define XK_REDO 0xff66 /* Redo, again */
# define XK_MENU 0xff67
# define XK_FIND 0xff68   /* Find, search */
# define XK_CANCEL 0xff69 /* Cancel, stop, abort, exit */
# define XK_HELP 0xff6a   /* Help */
# define XK_BREAK 0xff6b
# define XK_MODE_SWITCH 0xff7e   /* Character set switch */
# define XK_SCRIPT_SWITCH 0xff7e /* Alias for mode_switch */
# define XK_NUM_LOCK 0xff7f

/* Keypad functions, keypad numbers cleverly chosen to map to ASCII */

# define XK_KP_SPACE 0xff80 /* Space */
# define XK_KP_TAB 0xff89
# define XK_KP_ENTER 0xff8d /* Enter */
# define XK_KP_F1 0xff91    /* PF1, KP_A, ... */
# define XK_KP_F2 0xff92
# define XK_KP_F3 0xff93
# define XK_KP_F4 0xff94
# define XK_KP_HOME 0xff95
# define XK_KP_LEFT 0xff96
# define XK_KP_UP 0xff97
# define XK_KP_RIGHT 0xff98
# define XK_KP_DOWN 0xff99
# define XK_KP_PRIOR 0xff9a
# define XK_KP_PAGE_UP 0xff9a
# define XK_KP_NEXT 0xff9b
# define XK_KP_PAGE_DOWN 0xff9b
# define XK_KP_END 0xff9c
# define XK_KP_BEGIN 0xff9d
# define XK_KP_INSERT 0xff9e
# define XK_KP_DELETE 0xff9f
# define XK_KP_EQUAL 0xffbd /* Equals */
# define XK_KP_MULTIPLY 0xffaa
# define XK_KP_ADD 0xffab
# define XK_KP_SEPARATOR 0xffac /* Separator, often comma */
# define XK_KP_SUBTRACT 0xffad
# define XK_KP_DECIMAL 0xffae
# define XK_KP_DIVIDE 0xffaf

# define XK_KP_0 0xffb0
# define XK_KP_1 0xffb1
# define XK_KP_2 0xffb2
# define XK_KP_3 0xffb3
# define XK_KP_4 0xffb4
# define XK_KP_5 0xffb5
# define XK_KP_6 0xffb6
# define XK_KP_7 0xffb7
# define XK_KP_8 0xffb8
# define XK_KP_9 0xffb9

/*
 * Auxiliary functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufacturers have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

# define XK_F1 0xffbe
# define XK_F2 0xffbf
# define XK_F3 0xffc0
# define XK_F4 0xffc1
# define XK_F5 0xffc2
# define XK_F6 0xffc3
# define XK_F7 0xffc4
# define XK_F8 0xffc5
# define XK_F9 0xffc6
# define XK_F10 0xffc7
# define XK_F11 0xffc8
# define XK_L1 0xffc8
# define XK_F12 0xffc9

/* Modifiers */

# define XK_SHIFT_L 0xffe1    /* Left shift */
# define XK_SHIFT_R 0xffe2    /* Right shift */
# define XK_CONTROL_L 0xffe3  /* Left control */
# define XK_CONTROL_R 0xffe4  /* Right control */
# define XK_CAPS_LOCK 0xffe5  /* Caps lock */
# define XK_SHIFT_LOCK 0xffe6 /* Shift lock */

# define XK_META_L 0xffe7  /* Left meta */
# define XK_META_R 0xffe8  /* Right meta */
# define XK_ALT_L 0xffe9   /* Left alt */
# define XK_ALT_R 0xffea   /* Right alt */
# define XK_SUPER_L 0xffeb /* Left super */
# define XK_SUPER_R 0xffec /* Right super */
# define XK_HYPER_L 0xffed /* Left hyper */
# define XK_HYPER_R 0xffee /* Right hyper */

#endif
