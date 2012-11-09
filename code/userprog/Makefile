# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

# if file sys done first!
#DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS
#INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
#HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H)
#CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C)
#C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
 ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
 ../threads/thread.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/list.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../userprog/processmanager.h \
 ../userprog/processcb.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/sysopenfile.h ../machine/console.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
 ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/switch.h ../threads/synch.h \
 ../threads/list.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../userprog/processmanager.h \
 ../userprog/processcb.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/sysopenfile.h ../machine/console.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/signal.h /usr/include/bits/sigset.h \
 /usr/include/bits/signum.h /usr/include/time.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/asm/sigcontext.h \
 /usr/include/linux/types.h /usr/include/asm/types.h \
 /usr/include/asm-generic/types.h /usr/include/asm-generic/int-ll64.h \
 /usr/include/asm/bitsperlong.h /usr/include/asm-generic/bitsperlong.h \
 /usr/include/linux/posix_types.h /usr/include/linux/stddef.h \
 /usr/include/asm/posix_types.h /usr/include/asm/posix_types_32.h \
 /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h /usr/include/sys/uio.h \
 /usr/include/bits/uio.h /usr/include/bits/socket.h \
 /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/asm/sockios.h \
 /usr/include/asm-generic/sockios.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h /usr/include/bits/stat.h \
 /usr/include/sys/un.h /usr/include/sys/mman.h /usr/include/bits/mman.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/getopt.h /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h ../userprog/syscall.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/limits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
 ../userprog/bitmap.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc ../threads/copyright.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h ../threads/synch.h ../userprog/processmanager.h
memorymanager.o: ../userprog/memorymanager.cc ../userprog/memorymanager.h \
 ../machine/machine.h ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../userprog/addrspace.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h
processmanager.o: ../userprog/processmanager.cc \
 ../userprog/processmanager.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../userprog/processcb.h ../threads/thread.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../userprog/addrspace.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/limits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h
processcb.o: ../userprog/processcb.cc ../userprog/processcb.h \
 ../threads/thread.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../userprog/addrspace.h
nachossyscalls.o: ../userprog/nachossyscalls.cc /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h ../userprog/nachossyscalls.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h ../userprog/processmanager.h
sysopenfile.o: ../filesys/sysopenfile.cc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/cstdlib \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/include/stdlib.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/sys/types.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h ../filesys/sysopenfile.h ../filesys/openfile.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h
openuserfile.o: ../filesys/openuserfile.cc /usr/include/string.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/xlocale.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/cstdlib \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/types.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../filesys/openfile.h ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h
console.o: ../machine/console.cc ../threads/copyright.h \
 ../machine/console.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../bin/noff.h ../filesys/openuserfile.h ../filesys/sysopenfile.h \
 ../userprog/nachossyscalls.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/processmanager.h ../userprog/processcb.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/sysopenfile.h \
 ../threads/synch.h ../machine/console.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorymanager.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../userprog/processmanager.h ../userprog/processcb.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/sysopenfile.h ../threads/synch.h \
 ../machine/console.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/vector \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_algobase.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++config.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/os_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/cpu_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/functexcept.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/exception_defines.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/cpp_type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/type_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/numeric_traits.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_pair.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/move.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/concept_check.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_types.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator_base_funcs.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_iterator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/debug/debug.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/i686-redhat-linux/bits/c++allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/ext/new_allocator.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/new \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/exception \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_construct.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_uninitialized.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_vector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/initializer_list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_bvector.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/range_access.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/vector.tcc \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorymanager.h \
 ../machine/machine.h ../bin/noff.h ../filesys/openuserfile.h \
 ../filesys/sysopenfile.h ../userprog/nachossyscalls.h \
 ../threads/system.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/list \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/stl_list.h \
 /usr/lib/gcc/i686-redhat-linux/4.6.1/../../../../include/c++/4.6.1/bits/list.tcc \
 ../threads/utility.h ../threads/thread.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../userprog/processmanager.h \
 ../userprog/processcb.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/sysopenfile.h ../threads/synch.h ../machine/console.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
