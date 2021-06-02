/**
 2  * @file compiler_port.h
 3  * @brief Compiler specific definitions
 4  *
 5  * @section License
 6  *
 7  * SPDX-License-Identifier: GPL-2.0-or-later
 8  *
 9  * Copyright (C) 2010-2021 Oryx Embedded SARL. All rights reserved.
10  *
11  * This program is free software; you can redistribute it and/or
12  * modify it under the terms of the GNU General Public License
13  * as published by the Free Software Foundation; either version 2
14  * of the License, or (at your option) any later version.
15  *
16  * This program is distributed in the hope that it will be useful,
17  * but WITHOUT ANY WARRANTY; without even the implied warranty of
18  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
19  * GNU General Public License for more details.
20  *
21  * You should have received a copy of the GNU General Public License
22  * along with this program; if not, write to the Free Software Foundation,
23  * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
24  *
25  * @author Oryx Embedded SARL (www.oryx-embedded.com)
26  * @version 2.0.4
27  **/
28  
29 #ifndef _COMPILER_PORT_H
30 #define _COMPILER_PORT_H
31  
32 //Dependencies
33 #include <stddef.h>
34 #include <stdint.h>
35 #include <inttypes.h>
36  
37 //C++ guard
38 #ifdef __cplusplus
39 extern "C" {
40 #endif
41  
42 //Types
43 typedef char char_t;
44 typedef signed int int_t;
45 typedef unsigned int uint_t;
46 typedef uint32_t systime_t;
47  
48 #if !defined(R_TYPEDEFS_H) && !defined(USE_CHIBIOS_2)
49    typedef int bool_t;
50 #endif
51  
52 #if defined(__linux__)
53    #define PRIuSIZE "zu"
54    #define PRIXSIZE "zX"
55    #define PRIuTIME "lu"
56 #elif defined(_WIN32)
57    #define PRIuSIZE "Iu"
58    #define PRIXSIZE "IX"
59    #define PRIuTIME "lu"
60 #elif defined(__XC32)
61    #define PRIuSIZE "u"
62    #define PRIXSIZE "X"
63    #define PRIuTIME "u"
64 #elif defined(__CWCC__)
65    #define PRIu8 "u"
66    #define PRIu16 "u"
67    #define PRIu32 "u"
68    #define PRIx8 "x"
69    #define PRIx16 "x"
70    #define PRIx32 "x"
71    #define PRIX8 "X"
72    #define PRIX16 "X"
73    #define PRIX32 "X"
74    #define PRIuSIZE "u"
75    #define PRIXSIZE "X"
76    #define PRIuTIME "u"
77 #else
78    #define PRIuSIZE "u"
79    #define PRIXSIZE "X"
80    #define PRIuTIME "lu"
81 #endif
82  
83 #if defined(__CC_ARM)
84    #undef PRIu8
85    #define PRIu8 "u"
86    #undef PRIu16
87    #define PRIu16 "u"
88 #endif
89  
90 //ARM compiler V6?
91 #if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
92    char *strtok_r(char *s, const char *delim, char **last);
93 //GCC compiler?
94 #elif defined(__GNUC__)
95    int strcasecmp(const char *s1, const char *s2);
96    int strncasecmp(const char *s1, const char *s2, size_t n);
97    char *strtok_r(char *s, const char *delim, char **last);
98 //CodeWarrior compiler?
99 #elif defined(__CWCC__)
   typedef uint32_t time_t;
   int strcasecmp(const char *s1, const char *s2);
   int strncasecmp(const char *s1, const char *s2, size_t n);
   char *strtok_r(char *s, const char *delim, char **last);
//TI ARM compiler?
#elif defined(__TI_ARM__)
   int strcasecmp(const char *s1, const char *s2);
   int strncasecmp(const char *s1, const char *s2, size_t n);
   char *strtok_r(char *s, const char *delim, char **last);
//Microchip XC32 compiler?
#elif defined(__XC32)
   #define sprintf _sprintf
   int sprintf(char * str, const char * format, ...);
   int strcasecmp(const char *s1, const char *s2);
   int strncasecmp(const char *s1, const char *s2, size_t n);
   char *strtok_r(char *s, const char *delim, char **last);
#endif
 
//ARM compiler V6?
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
   #undef __start_packed
   #define __start_packed
   #undef __end_packed
   #define __end_packed __attribute__((packed))
   #define __weak __attribute__((weak))
//GCC compiler?
#elif defined(__GNUC__)
   #undef __start_packed
   #define __start_packed
   #undef __end_packed
   #define __end_packed __attribute__((__packed__))
   #define __weak __attribute__((weak))
//ARM compiler?
#elif defined(__CC_ARM)
   #pragma anon_unions
   #undef __start_packed
   #define __start_packed __packed
   #undef __end_packed
   #define __end_packed
//IAR compiler?
#elif defined(__IAR_SYSTEMS_ICC__)
   #undef __start_packed
   #define __start_packed __packed
   #undef __end_packed
   #define __end_packed
//CodeWarrior compiler?
#elif defined(__CWCC__)
   #undef __start_packed
   #define __start_packed
   #undef __end_packed
   #define __end_packed
   #define __weak
//TI ARM compiler?
#elif defined(__TI_ARM__)
   #undef __start_packed
   #define __start_packed
   #undef __end_packed
   #define __end_packed __attribute__((__packed__))
   #define __weak
//Win32 compiler?
#elif defined(_WIN32)
   #undef interface
   #undef __start_packed
   #define __start_packed
   #undef __end_packed
   #define __end_packed
   #define __weak
#endif
 
//C++ guard
#ifdef __cplusplus
}
#endif
 
#endif